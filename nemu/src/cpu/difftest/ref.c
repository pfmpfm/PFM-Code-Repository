/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>
#include "../../utils/trace.h"

bool init_pc = true; //pc值有且仅有一次初始化

// __attribute__((visibility("default")))）将这些函数标记为可导出


// 在DUT host memory的`buf`和REF guest memory的`addr`之间拷贝`n`字节,
// `direction`指定拷贝的方向, `DIFFTEST_TO_DUT`表示往DUT拷贝, `DIFFTEST_TO_REF`表示往REF拷贝
void __attribute__((visibility("default"))) difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if(direction == DIFFTEST_TO_DUT){ //向DUT中拷贝
    memcpy(buf,guest_to_host(addr),n);
  }else{
    memcpy(guest_to_host(addr),buf,n);
  }
}

// `direction`为`DIFFTEST_TO_DUT`时, 获取REF的寄存器状态到`dut`;
// `direction`为`DIFFTEST_TO_REF`时, 设置REF的寄存器状态为`dut`;
void __attribute__((visibility("default"))) difftest_regcpy(void *dut, bool direction) {
  if(direction == DIFFTEST_TO_DUT){
    memcpy(dut,&cpu,DIFFTEST_REG_SIZE);
  }else{
    memcpy(&cpu,dut,DIFFTEST_REG_SIZE);
  }
}

// 让REF执行`n`条指令
void __attribute__((visibility("default"))) difftest_exec(uint32_t n, paddr_t dut_pc) {
  if(init_pc){
    cpu.pc=dut_pc;
    init_pc=false;
    return;
   }
   cpu_exec(n);
   //printf("NEMU PC: %8x\n",cpu.pc);
}

void __attribute__((visibility("default"))) difftest_raise_intr(word_t NO) {
  assert(0);
}

void __attribute__((visibility("default"))) difftest_init(int port) {
  /* Perform ISA dependent initialization. */
  init_isa();
}
