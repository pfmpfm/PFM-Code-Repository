#define word_t uint32_t
#define PG_ALIGN __attribute((aligned(4096)))
#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000
#define DEVICE_BASE  0xa0000000
#define RTC_ADDR (DEVICE_BASE + 0x00000048)
#define SERIAL_PORT (DEVICE_BASE + 0x000003f8)
#define VGACTL_ADDR (DEVICE_BASE + 0x00000100)
#define SYNC_ADDR (VGACTL_ADDR + 4)
#define FB_ADDR (DEVICE_BASE + 0x1000000)
#define RESET_VECTOR (uint32_t) CONFIG_MBASE // 客户程序在内存中的初始位置
#define SCREEN_W 400
#define SCREEN_H 300
typedef uint32_t paddr_t;
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {}; // 内存指针


word_t pmem_read(paddr_t addr, int len);
void pmem_write(paddr_t addr, int wdata, int len);
long in_img(const char *img_file);
uint8_t *guest_to_host(paddr_t paddr);



