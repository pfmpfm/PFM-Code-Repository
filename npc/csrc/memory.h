#ifndef MY_HEADER_H
#define MY_HEADER_H
#define word_t uint32_t
#define PG_ALIGN __attribute((aligned(4096)))
#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000
#define RESET_VECTOR (uint32_t) CONFIG_MBASE // 客户程序在内存中的初始位置
typedef uint32_t paddr_t;
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {}; // 内存指针

word_t pmem_read(paddr_t addr, int len);
void pmem_write(paddr_t addr, int wdata, int len);
long in_img();
uint8_t *guest_to_host(paddr_t paddr);

#endif 

