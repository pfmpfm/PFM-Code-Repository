#include "verilated.h"
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h> 

#define word_t uint32_t
static const word_t img[]={
	0b00000000010100000000000010010011,
	0b00000000000100000000000100010011,
	0b00000000000100000000000001110011,//
        0b00000000001000000000000100010011,
	0b00000000010100001000000100010011
};
word_t *init_mem(word_t size){
	word_t *memory=(word_t*)malloc(size*sizeof(word_t));
	memcpy(memory,img,sizeof(img));
	if(memory==NULL) exit(0);
	return memory;
}
word_t guest_to_host(word_t addr){return addr-0x80000000;}
word_t pmem_read(word_t *memory, word_t vaddr){
	word_t paddr=guest_to_host(vaddr);
	return memory[paddr/4];
}
extern "C" void ebreak(){
    printf("\33[1;31mHIT BAD TRAP\n");
    _exit(0);
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

int main() {
    word_t* memory;
    memory = init_mem(4);

    VerilatedContext* contextp = new VerilatedContext;
    Verilated::mkdir("logs");
    VerilatedVcdC* tfp = new VerilatedVcdC();
    
    Vtop* top = new Vtop(contextp);
    Verilated::traceEverOn(true); 
    top->trace(tfp, 0);
    tfp->open("./logs/wave.vcd");

    //reset(10,top,contextp,tfp);
    word_t pc = 0x80000000;
    for (int i = 0; i <= 4; i++) {
        top->inst = pmem_read(memory, pc);
        pc += 4;
        printf("%u\n",top->inst);
        single_cycle(top,contextp,tfp);
    }
    top->final();
    tfp->close();
    
    delete top;
    delete contextp;
    delete tfp;
    
    return 0;
}


