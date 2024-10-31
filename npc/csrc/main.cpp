#include "verilated.h"
#include "Vtop.h"
#include "Vtop___024root.h" 
#include "verilated_vcd_c.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h> 
#include <dlfcn.h>
#include <svdpi.h> 
#include <verilated_dpi.h>
#include "memory.h"

#define CONFIG_DIFFTEST  //差分测试
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;
typedef uint32_t word_t;

Vtop *top; 
uint32_t (*cpu_gpr) = NULL;

typedef struct
{
  word_t gpr[32];
  vaddr_t pc;
  word_t csr[4];
}CPU_state; 

enum
{
  DIFFTEST_TO_DUT, //代表0
  DIFFTEST_TO_REF  //代表1  ps：如果后续还有其他常量定义则递增，如2，3, ... , n
};


extern "C" void ebreak(){
    printf("\33[1;32mHIT GOOD TRAP\n");
    _exit(0);
}

extern "C" void itrace(int inst){
    printf("inst : %08x\n",inst);
}

extern "C" void set_gpr_ptr(const svOpenArrayHandle r) {
    cpu_gpr = (uint32_t *)(((VerilatedDpiOpenVar *)r)->datap());
}

void single_cycle(Vtop* top,VerilatedContext* contextp,VerilatedVcdC* tfp) {
    top->clk=1;
    for(int i=0;i<2;i++){
    top->clk = !top->clk;
    top->eval();
    tfp->dump(contextp->time());
    contextp->timeInc(1);
    }
}

static void reset(int n,Vtop* top,VerilatedContext* contextp,VerilatedVcdC* tfp) {
    top->rst = 1;
    while (n-- > 0) single_cycle(top,contextp,tfp);
    top->rst = 0;
}

void scanMemory(int count,word_t addr){
    for(int i=0;i<count;i++){
    word_t memoryValue=pmem_read(addr);
    printf("addr [0x%x] : %08x\n",addr,memoryValue);
    addr = addr+4;
    }
}

#ifdef CONFIG_DIFFTEST

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint32_t n, paddr_t dut_pc) = NULL;
void (*ref_difftest_raise_intr)(uint32_t NO) = NULL;

static bool is_skip_ref = false;
static bool is_last_skip_ref = false;
static int skip_dut_nr_inst = 0;

void difftest_skip_ref()
{
  is_skip_ref = true;
  skip_dut_nr_inst = 0;
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc)
{
  if(memcmp(ref_r, cpu_gpr, 32 * 4) == 0 && ref_r->pc == pc) 
    return true;
  else
    return false;
}

void init_difftest(const char *ref_so_file, long img_size, int port)
{
  assert(ref_so_file != NULL);
  //cpu_gpr[32] = top->inst_sram_addr;

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "============================================Error: %s\n", dlerror());
    return;
  }
  ref_difftest_memcpy = (void (*)(paddr_t, void *, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);
  
  ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint32_t n, paddr_t dut_pc))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint32_t NO))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int port))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF); // 将DUT的guest memory拷贝到REF中
  ref_difftest_regcpy(cpu_gpr, DIFFTEST_TO_REF);                                             // 将DUT的寄存器状态拷贝到REF中
}

static void checkregs(CPU_state *ref, vaddr_t pc)
{
  if (!isa_difftest_checkregs(ref, pc))
  {
    printf("\33[1;31mNPC ABORT at pc = 0x%8x\n", pc);
    //打印出NPC的寄存器
    printf("-----------NPC寄存器------------\n");
    for(int i=0;i<32;i++) printf("Reg%2d value : %8x\n",i,cpu_gpr[i]);
    //打印出NEMU的寄存器
    printf("-----------NEMU寄存器-----------\n");
    for(int i=0;i<32;i++) printf("Reg%2d value : %8x\n",i,ref->gpr[i]);
    //打印出错指令
    printf("------------出错指令------------\n");
    word_t inst = pmem_read(pc);
    printf("wrong inst is : %08x\n",inst);
  }
}

void difftest_step(vaddr_t pc)
{
  CPU_state ref_r;

  if (is_skip_ref)
  {
    // to skip the checking of an instruction, just copy the reg state to reference design
    is_last_skip_ref = true;
    is_skip_ref = false;
    return;
  }

  if(is_last_skip_ref){
    ref_difftest_regcpy(cpu_gpr, DIFFTEST_TO_REF);
    is_last_skip_ref = false;
    return;
  }

  ref_difftest_exec(1,  pc);                         // ref执行一次
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT); // 将ref中的寄存器状态备份到ref_r中，比较ref_r和nemu的寄存器状态

  checkregs(&ref_r, pc);

}

#endif


int main() {
    
    VerilatedContext* contextp = new VerilatedContext;
    Verilated::mkdir("logs");
    VerilatedVcdC* tfp = new VerilatedVcdC();
    
    top = new Vtop(contextp);
    Verilated::traceEverOn(true); 
    top->trace(tfp, 0);
    tfp->open("./logs/wave.vcd");

    long img_size=in_img();
    static const char *diff_so_file = "/home/pfm/ysyx/ysyx-workbench/npc/libnemu.so";
    //init_difftest(diff_so_file, img_size, 1234);
    paddr_t pc = 0x80000000;
    //scanMemory(10,0x80000000);//打印内存 nemu当中x 10 0x80000000
    
    for (int i = 0;; i++) {

        top->inst = pmem_read(pc);
        single_cycle(top,contextp,tfp);
        if(i==0) init_difftest(diff_so_file, img_size, 1234);
        difftest_step(pc);
        pc += 4;
    }

    top->final();
    tfp->close();
    
    delete top;
    delete contextp;
    delete tfp;
    
    return 0;
}


