// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;
class Vtop___024unit;


class Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*4:0*/ top__DOT__alu_op;
        CData/*3:0*/ top__DOT__mem_op;
        CData/*3:0*/ top__DOT__ex_op;
        CData/*3:0*/ top__DOT__pc_op;
        CData/*0:0*/ top__DOT__compare_result;
        CData/*0:0*/ top__DOT__load_valid;
        CData/*4:0*/ top__DOT__rd_2;
        CData/*0:0*/ top__DOT___pc__DOT__is_branch;
        CData/*0:0*/ top__DOT___pc__DOT__is_inc4;
        CData/*0:0*/ top__DOT__idu__DOT__I_type;
        CData/*0:0*/ top__DOT__idu__DOT__U_type;
        CData/*0:0*/ top__DOT__idu__DOT__Inst_jalr;
        CData/*0:0*/ top__DOT__idu__DOT__isNeed_rs1;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_he69f398c__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_hd3e51328__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_he69b39c7__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_he48ad066__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_he979b2f1__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_h873f971e__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_hdde88109__0;
        CData/*0:0*/ top__DOT__idu__DOT____VdfgTmp_had26422b__0;
        CData/*0:0*/ top__DOT__exu__DOT__rs1_rs2;
        CData/*0:0*/ top__DOT__exu__DOT__rs1_imm;
        CData/*0:0*/ top__DOT__exu__DOT__pc_4;
        CData/*0:0*/ top__DOT__exu__DOT__ALU__DOT__adder_cout;
        CData/*0:0*/ top__DOT__exu__DOT__ALU__DOT__isSUB;
        CData/*0:0*/ top__DOT__exu__DOT__ALU__DOT__slt_result;
        CData/*0:0*/ top__DOT__mem__DOT__is1byte;
        CData/*0:0*/ top__DOT__mem__DOT__is2byte;
        CData/*0:0*/ top__DOT__mem__DOT__unsigned_load;
        CData/*0:0*/ top__DOT__mem__DOT__signed_load;
        CData/*0:0*/ top__DOT__mem__DOT____VdfgTmp_h3c6dcd3f__0;
        CData/*0:0*/ __VdfgTmp_h498b5a69__0;
        CData/*0:0*/ __Vtrigrprev__TOP__clk;
        CData/*0:0*/ __VactContinue;
        VL_OUT(debug_rs1_data,31,0);
        VL_OUT(debug_rs2_data,31,0);
        VL_OUT(debug_imm,31,0);
        VL_OUT(debug_write_idx,31,0);
        VL_OUT(debug_write_data,31,0);
        VL_OUT(debug_rw_addr,31,0);
        IData/*31:0*/ top__DOT__inst;
        IData/*31:0*/ top__DOT__imm;
        IData/*31:0*/ top__DOT__rs1_data;
        IData/*31:0*/ top__DOT__rs2_data;
        IData/*31:0*/ top__DOT__write_data;
        IData/*31:0*/ top__DOT__ex_alu_data;
        IData/*31:0*/ top__DOT__read_data;
        IData/*31:0*/ top__DOT__rw_addr;
        IData/*31:0*/ top__DOT___pc__DOT__current_pc;
        IData/*31:0*/ top__DOT___pc__DOT__next_pc;
        IData/*31:0*/ top__DOT__exu__DOT__alu_src1;
        IData/*31:0*/ top__DOT__exu__DOT__alu_src2;
        IData/*31:0*/ top__DOT__exu__DOT__ALU__DOT__adder_result;
        IData/*31:0*/ top__DOT__exu__DOT__ALU__DOT__adder_b;
        IData/*31:0*/ top__DOT__exu__DOT__ALU__DOT____VdfgTmp_ha85d5376__0;
        IData/*31:0*/ top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h50ddfa4f__0;
        IData/*31:0*/ top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h51fa2515__0;
        IData/*31:0*/ __Vfunc_mem_read__5__Vfuncout;
    };
    struct {
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ top__DOT__exu__DOT__ALU__DOT__mulh_64_result;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__Regfile__DOT__rf;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
