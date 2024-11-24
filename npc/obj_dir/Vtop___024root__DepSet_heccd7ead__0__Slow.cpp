// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/pfm/ysyx/ysyx-workbench/npc/vsrc/top.v", 3, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->debug_rs1_data = 0;
    vlSelf->debug_rs2_data = 0;
    vlSelf->debug_imm = 0;
    vlSelf->debug_write_idx = 0;
    vlSelf->debug_write_data = 0;
    vlSelf->debug_rw_addr = 0;
    vlSelf->top__DOT__inst = 0;
    vlSelf->top__DOT__imm = 0;
    vlSelf->top__DOT__alu_op = 0;
    vlSelf->top__DOT__mem_op = 0;
    vlSelf->top__DOT__ex_op = 0;
    vlSelf->top__DOT__pc_op = 0;
    vlSelf->top__DOT__rs1_data = 0;
    vlSelf->top__DOT__rs2_data = 0;
    vlSelf->top__DOT__write_data = 0;
    vlSelf->top__DOT__ex_alu_data = 0;
    vlSelf->top__DOT__compare_result = 0;
    vlSelf->top__DOT__load_valid = 0;
    vlSelf->top__DOT__rd_2 = 0;
    vlSelf->top__DOT__read_data = 0;
    vlSelf->top__DOT__rw_addr = 0;
    vlSelf->top__DOT___pc__DOT__is_branch = 0;
    vlSelf->top__DOT___pc__DOT__is_inc4 = 0;
    vlSelf->top__DOT___pc__DOT__current_pc = 0;
    vlSelf->top__DOT___pc__DOT__next_pc = 0;
    vlSelf->top__DOT__idu__DOT__I_type = 0;
    vlSelf->top__DOT__idu__DOT__U_type = 0;
    vlSelf->top__DOT__idu__DOT__Inst_jalr = 0;
    vlSelf->top__DOT__idu__DOT__isNeed_rs1 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0 = 0;
    vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__Regfile__DOT__rf[__Vi0] = 0;
    }
    vlSelf->top__DOT__exu__DOT__rs1_rs2 = 0;
    vlSelf->top__DOT__exu__DOT__rs1_imm = 0;
    vlSelf->top__DOT__exu__DOT__pc_4 = 0;
    vlSelf->top__DOT__exu__DOT__alu_src1 = 0;
    vlSelf->top__DOT__exu__DOT__alu_src2 = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_result = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_b = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT__slt_result = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT__mulh_64_result = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_ha85d5376__0 = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h50ddfa4f__0 = 0;
    vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h51fa2515__0 = 0;
    vlSelf->top__DOT__mem__DOT__is1byte = 0;
    vlSelf->top__DOT__mem__DOT__is2byte = 0;
    vlSelf->top__DOT__mem__DOT__unsigned_load = 0;
    vlSelf->top__DOT__mem__DOT__signed_load = 0;
    vlSelf->top__DOT__mem__DOT____VdfgTmp_h3c6dcd3f__0 = 0;
    vlSelf->__VdfgTmp_h498b5a69__0 = 0;
    vlSelf->__Vfunc_mem_read__5__Vfuncout = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
