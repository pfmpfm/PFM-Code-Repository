#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include <iostream>
#include <fstream>
#include "memory.h"
#define word_t uint32_t


uint8_t *guest_to_host(paddr_t paddr);
void init_mem();

static const char *img_file = "./win_test/bit-riscv32-nemu.bin";// 装载程序镜像的文件指针
long in_img() {
    init_mem();

    FILE *fp = fopen(img_file, "rb");
    if (fp == NULL) {
        printf("Can't open img_file!\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // 确保读取的大小不超过 pmem 的大小
    if (size > CONFIG_MSIZE - RESET_VECTOR) {
        printf("Image size exceeds memory size!\n");
        fclose(fp);
        return 0;
    }

    int ret = fread(pmem + RESET_VECTOR - CONFIG_MBASE, 1, size, fp);
    if (ret != size) {
        printf("Error reading image file!\n");
    } 
    
    fclose(fp);
    return size;
}

uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; } 
//word_t guest_to_host(paddr_t addr){return addr-0x80000000;}
/*
word_t pmem_read(word_t *memory, word_t vaddr){
	word_t paddr=guest_to_host(vaddr);
	return memory[paddr/4];
}*/
word_t pmem_read(paddr_t addr, int len){
    int start = addr & ~0x3u;
    int diff  = addr - start;
    uint32_t value; 
    if(len == 1){
      value = pmem[start-CONFIG_MBASE + diff];
    }
    else if(len == 2){
      value = (pmem[start-CONFIG_MBASE + diff] << 0) + (pmem[start-CONFIG_MBASE + diff + 1] << 8);
    }
    else{
      value = 
      (pmem[addr-CONFIG_MBASE] << 0) +
      (pmem[addr-CONFIG_MBASE + 1] << 8) +
      (pmem[addr-CONFIG_MBASE + 2] << 16) +
      (pmem[addr-CONFIG_MBASE + 3] << 24);
    }
    printf("addr: %8x start : %8x diff: %d value: %d\n",addr,start,diff,value);
    return value;
}

void pmem_write(paddr_t addr, int wdata, int len) {
    int start = addr & ~0x3u;
    int diff  = addr - start;
    if(len == 1){
      pmem[start-CONFIG_MBASE + diff] = (wdata >> 0) & 0xFF;  
    }
    else if(len == 2){
      pmem[start-CONFIG_MBASE + diff]     = (wdata >> 0) & 0xFF;  
      pmem[start-CONFIG_MBASE + diff + 1] = (wdata >> 8) & 0xFF;  
    }
    else{
      pmem[start-CONFIG_MBASE + diff]     = (wdata >> 0) & 0xFF;     
      pmem[start-CONFIG_MBASE + diff + 1] = (wdata >> 8) & 0xFF; 
      pmem[start-CONFIG_MBASE + diff + 2] = (wdata >> 16) & 0xFF; 
      pmem[start-CONFIG_MBASE + diff + 3] = (wdata >> 24) & 0xFF; 
    }
}

void init_mem(){
  // 为pmem指向的空间填满随机数
  uint32_t *p = (uint32_t *)pmem;
  int i;
  for (i = 0; i < (int)(CONFIG_MSIZE / sizeof(p[0])); i++)
  {
    p[i] = 0;
  }
}
