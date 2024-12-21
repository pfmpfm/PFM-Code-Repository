// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/pfm/ysyx2/ysyx-workbench/npc/vsrc/IDU.v:2:30
    extern void ebreak();
    // DPI import at /home/pfm/ysyx2/ysyx-workbench/npc/vsrc/IFU.v:2:30
    extern void itrace(int inst);
    // DPI import at /home/pfm/ysyx2/ysyx-workbench/npc/vsrc/MEM.v:2:29
    extern int mem_read(int raddr, int len);
    // DPI import at /home/pfm/ysyx2/ysyx-workbench/npc/vsrc/MEM.v:1:30
    extern void mem_write(int waddr, int wdata, int len);
    // DPI import at /home/pfm/ysyx2/ysyx-workbench/npc/vsrc/PC.v:1:30
    extern void read_pc(int pc);
    // DPI import at /home/pfm/ysyx2/ysyx-workbench/npc/vsrc/regfile.v:2:30
    extern void set_gpr_ptr(const svOpenArrayHandle rf_ptr);

#ifdef __cplusplus
}
#endif

#endif  // guard
