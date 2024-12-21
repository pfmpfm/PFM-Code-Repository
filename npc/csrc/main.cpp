#include "verilated.h"
#include "Vtop.h"
#include "Vtop___024root.h" 
#include "verilated_vcd_c.h"
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h> 
#include <dlfcn.h>
#include <svdpi.h> 
#include <verilated_dpi.h>
#include <SDL2/SDL.h>
#include "memory.h"


// #define CONFIG_DIFFTEST  
// #define CONFIG_MTRACE
// #define CONFIG_ITRACE
#define HAS_GUI


#define RESET "\033[0m" //重置
#define RED "\033[31m" //红色
#define GREEN "\033[32m"  //绿色
#define YELLOW "\033[33m"  //黄色
#define BLUE "\033[34m"  //蓝色
#define PURPLE "\033[35m"  //紫色

typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;
typedef uint32_t word_t;


uint8_t * malloc_space(int size);
uint32_t get_time();
void difftest_skip_ref();
static uint32_t screen_size();
#ifdef HAS_GUI
void init_vga();
void vga_update_screen();
#endif


bool difftest_error = false;
Vtop *top; 
uint32_t *cpu_gpr;
static void *vmem = NULL; //显存
uint32_t *p_vmem = NULL;
static uint32_t *vga_regs = NULL; //VGA控制寄存器
int PC;


typedef struct
{
  uint32_t gpr[32];
  vaddr_t pc;
}CPU_state; 
CPU_state *NPC = (CPU_state *)malloc(sizeof(CPU_state)); // 为 CPU_state 分配内存

enum
{
  DIFFTEST_TO_DUT, //代表0
  DIFFTEST_TO_REF  //代表1  ps：如果后续还有其他常量定义则递增，如2，3, ... , n
};

/*******************DPI-C函数*******************/
extern "C" void ebreak(){
    printf(GREEN "HIT GOOD TRAP\n" RESET);
    _exit(0);
}

extern "C" void itrace(int inst){
    #ifdef CONFIG_ITRACE
    printf(GREEN "inst : %08x\n" RESET,inst);
    #endif
}

extern "C" void set_gpr_ptr(const svOpenArrayHandle r) {
    cpu_gpr = (uint32_t *)(((VerilatedDpiOpenVar *)r)->datap());
}

extern "C" int mem_read(int raddr, int len)
{
    if(raddr == RTC_ADDR){
        int clock_time = get_time();
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
          // printf("NPC: raddr:0x%8x \n",raddr);
        #endif
        return clock_time;
    }
    else if(raddr == VGACTL_ADDR){
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
        #endif
        return vga_regs[0];
    }
    else if(raddr>=DEVICE_BASE){
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
        #endif   
        return 0;       
    }
    else if(CONFIG_MBASE <= raddr && raddr < (CONFIG_MBASE + CONFIG_MSIZE)){
        int read_data = pmem_read(raddr, len);
        return read_data;
    }
    
    //else printf("NPC读地址不正确！raddr:%8x\n",raddr);
    return 0;
}

extern "C" void mem_write(int waddr, int wdata, int len)
{
    #ifdef CONFIG_MTRACE
          // if(waddr==0x800b0fa4||waddr==0x800b0fac){
          //   printf("NPC: waddr:0x%8x  data:0x%x  pc:0x%x\n",waddr,wdata,NPC->pc);
          // difftest_error=true;
          // }
          
    #endif
    if(waddr>=DEVICE_BASE){
      // printf("wdata: %x waddr: %x at pc : 0x%08x\n",wdata,waddr,NPC->pc);
    }
    if(waddr == SERIAL_PORT){
        putchar(wdata & 0xff);
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
        #endif
        return;
    }
    else if(waddr == SYNC_ADDR){
        vga_regs[1] = wdata;
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
        #endif    
        #ifdef HAS_GUI
          vga_update_screen();
        #endif
        return;
    }
    else if(FB_ADDR <= waddr && waddr < FB_ADDR+screen_size()){
        p_vmem[(waddr - FB_ADDR)/4] = wdata;
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
        #endif
        return;
    }
    else if(waddr>=DEVICE_BASE){
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
        #endif    
        return;      
    }
    else if(CONFIG_MBASE <= waddr && waddr < (CONFIG_MBASE + CONFIG_MSIZE)){
        pmem_write(waddr, wdata, len);
    }
    
    //else printf("NPC写地址不正确！waddr:%8x\n",waddr);
    return;
}

extern "C" void read_pc(int next_pc)
{
    if(next_pc >= CONFIG_MBASE)NPC->pc=next_pc;
}
/******************************************************/
/*******************时钟*******************/
static uint32_t start_time = 0;
static uint32_t get_time_inside() {
  // struct timeval now_time;
  // gettimeofday(&now_time, NULL);
  // uint32_t us = now_time.tv_sec * 1000000 + now_time.tv_usec; //转换成微秒,返回现在时间  
  struct timespec now_time;
  clock_gettime(CLOCK_MONOTONIC_COARSE, &now_time);
  uint32_t us = now_time.tv_sec * 1000000 + now_time.tv_nsec / 1000;
  return us;
}

uint32_t get_time() {
  if (start_time == 0) start_time = get_time_inside(); //获取初始时间
  uint32_t now_time = get_time_inside();
  return now_time - start_time;
}
/******************************************************/
/*******************VGA*******************/
#ifdef HAS_GUI

static SDL_Renderer *renderer = NULL; 
static SDL_Texture *texture = NULL;

uint8_t * malloc_space(int size){
  uint8_t* p = (uint8_t*)malloc(size); 
  assert(p != NULL); 
  return p; 
}
static uint32_t screen_width() {
  return SCREEN_W; //400
}
static uint32_t screen_height() {
  return SCREEN_H; //300
}
static uint32_t screen_size() {
  return screen_width() * screen_height() * sizeof(uint32_t);
}

static void init_screen() {
  SDL_Window *window = NULL; 
  char window_title[128];
  sprintf(window_title, "riscv32-npc"); 
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(SCREEN_W*2 , SCREEN_H*2 , 0, &window, &renderer); 
  SDL_SetWindowTitle(window, window_title); //设置窗口标题
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, 
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H); 
}

static inline void update_screen() {
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t)); 
  SDL_RenderClear(renderer); 
  SDL_RenderCopy(renderer, texture, NULL, NULL); 
  SDL_RenderPresent(renderer); 
}

void vga_update_screen() {
  uint32_t sync_reg = vga_regs[1]; 
  if(sync_reg){
    update_screen(); 
    vga_regs[1] = 0; 
  }
}

void init_vga() {
  vga_regs = (uint32_t *)malloc_space(8); 
  vga_regs[0] = (screen_width() << 16) | screen_height(); 
  vmem = malloc_space(screen_size()); 
  init_screen(); 
  memset(vmem, 0, screen_size()); 
}
#endif
/******************************************************/

void updateRegfile(){
  for (int i = 0; i < 32; i++) {
    NPC->gpr[i] = cpu_gpr[i];  
  }
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
    word_t memoryValue=pmem_read(addr,4);
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

void difftest_skip_ref()
{
  is_skip_ref = true;
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc)
{
  if((memcmp(ref_r, NPC->gpr, 32 * 4) == 0) && (ref_r->pc == NPC->pc) )// ref_r->pc是下一条pc，而PC是当前pc
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
  ref_difftest_regcpy(NPC, DIFFTEST_TO_REF);                                             // 将DUT的寄存器状态拷贝到REF中

}

static void checkregs(CPU_state *ref, vaddr_t pc)
{	
  if (isa_difftest_checkregs(ref, pc)){
  // printf("\33[1;31mNPC ABORT at next_pc = 0x%8x  NEMU ABORT at next_pc = 0x%8x\n", NPC->pc, ref->pc);
  // printf("NPC = rs1_data: %x rs2_data: %x rd: %x imm: %x wb_data: %x rw_addr: %8x\n",top->debug_rs1_data,top->debug_rs2_data,top->debug_write_idx,top->debug_imm,top->debug_write_data,top->debug_rw_addr);
  // printf("-----------NPC寄存器------------\n");
  // for(int i=0;i<32;i++) printf("Reg%2d value : %8x\n",i,NPC->gpr[i]);
  // printf("-----------NEMU寄存器------------\n");
  // for(int i=0;i<32;i++) printf("Reg%2d value : %8x\n",i,ref->gpr[i]);
  }

  if (!isa_difftest_checkregs(ref, NPC->pc))
  {
    printf("NPC = rs1_data: 0x%x rs2_data: 0x%x rd: 0x%x imm: 0x%x wb_data: 0x%x rw_addr: 0x%8x\n",top->debug_rs1_data,top->debug_rs2_data,top->debug_write_idx,top->debug_imm,top->debug_write_data,top->debug_rw_addr);    
    printf("\33[1;31m-----------------------------------------------------------------\n");
    printf("NPC ABORT at next_pc = 0x%8x  NEMU ABORT at next_pc = 0x%8x\n", NPC->pc, ref->pc);
    //打印出NPC的寄存器
    printf("-----------NPC寄存器------------\n");
    for(int i=0;i<32;i++) printf("Reg%2d value : %8x\n",i,NPC->gpr[i]);
    //打印出NEMU的寄存器
    printf("-----------NEMU寄存器-----------\n");
    for(int i=0;i<32;i++) printf("Reg%2d value : %8x\n",i,ref->gpr[i]);
    //打印出错指令
    printf("------------出错指令------------\n");
    word_t inst = pmem_read(pc,4);
    printf("wrong inst is : %08x\n",inst);
    printf("-----------------------------------------------------------------\n");
    difftest_error = true;
  }
}

void difftest_step(vaddr_t pc)
{
  CPU_state ref_r;

  if (is_skip_ref)
  {
    is_skip_ref = false;
    is_last_skip_ref = true;
    return;
  }

  if(is_last_skip_ref){
    ref_difftest_regcpy(NPC, DIFFTEST_TO_REF);
    is_last_skip_ref = false;
    return;
  }

  ref_difftest_exec(1,  pc);                         // ref执行一次
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT); // 将ref中的寄存器状态备份到ref_r中，比较ref_r和nemu的寄存器状态
  checkregs(&ref_r, pc);

}

#endif


int main(int argc, char *argv[]) {
    
    VerilatedContext* contextp = new VerilatedContext;
    Verilated::mkdir("logs");
    VerilatedVcdC* tfp = new VerilatedVcdC();
    
    top = new Vtop(contextp);
    //Verilated::traceEverOn(true); 
    //top->trace(tfp, 0);
    //tfp->open("./logs/wave.vcd");

    static const char *diff_so_file = argv[1];  //"/home/pfm/ysyx/ysyx-workbench/npc/libnemu.so";
    static const char *img_file = "./am_test/mario.bin";   //// 装载程序镜像的文件指针          argv[2];         "./win_test/alutest-riscv32-nemu.bin";
    long img_size=in_img(img_file); 
    #ifdef HAS_GUI
      init_vga();
      vga_update_screen();
      p_vmem = (uint32_t*)vmem;
    #endif
    //init_difftest(diff_so_file, img_size, 1234);
    //scanMemory(10,0x80000000);//打印内存 nemu当中x 10 0x80000000

    for (int i = 0;; i++) {
        if(difftest_error){
          _exit(1);
          break;
        } 

        if(i==0){
          top->rst=1;
          single_cycle(top,contextp,tfp);
          updateRegfile();
          top->rst=0;
          #ifdef CONFIG_DIFFTEST
            init_difftest(diff_so_file, img_size, 1234);        
          #endif 
        }
        else{
          single_cycle(top,contextp,tfp);
          updateRegfile();
          #ifdef CONFIG_DIFFTEST
            // printf("NPC ABOUT at pc = %8x\n",NPC->pc);
            difftest_step(NPC->pc);     
          #endif 
          
        }
        
        // printf("pc at 0x%08x\n",NPC->pc);
        
    }

    top->final();
    tfp->close();
    
    delete top;
    delete contextp;
    delete tfp;
    
    return 0;
}


