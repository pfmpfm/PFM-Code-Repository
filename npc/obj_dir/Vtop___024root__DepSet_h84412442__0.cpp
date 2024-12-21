// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(1U) = ((~ (IData)(vlSelf->clk)) 
                                      & (IData)(vlSelf->__Vtrigrprev__TOP__clk));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop___024unit____Vdpiimwrap_itrace_TOP____024unit(IData/*31:0*/ inst);
void Vtop___024unit____Vdpiimwrap_read_pc_TOP____024unit(IData/*31:0*/ pc);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        Vtop___024unit____Vdpiimwrap_itrace_TOP____024unit(vlSelf->top__DOT__inst);
    }
    Vtop___024unit____Vdpiimwrap_read_pc_TOP____024unit(
                                                        ((((- (IData)(
                                                                      ((2U 
                                                                        == (IData)(vlSelf->top__DOT__pc_op)) 
                                                                       | ((0U 
                                                                           == (IData)(vlSelf->top__DOT__pc_op)) 
                                                                          | ((IData)(vlSelf->top__DOT___pc__DOT__is_branch) 
                                                                             | (IData)(vlSelf->top__DOT___pc__DOT__is_inc4)))))) 
                                                           & vlSelf->top__DOT___pc__DOT__current_pc) 
                                                          | ((- (IData)(
                                                                        (3U 
                                                                         == (IData)(vlSelf->top__DOT__pc_op)))) 
                                                             & vlSelf->top__DOT__rs1_data)) 
                                                         + 
                                                         (((- (IData)(
                                                                      ((IData)(vlSelf->top__DOT___pc__DOT__is_branch) 
                                                                       | ((2U 
                                                                           == (IData)(vlSelf->top__DOT__pc_op)) 
                                                                          | (3U 
                                                                             == (IData)(vlSelf->top__DOT__pc_op)))))) 
                                                           & vlSelf->top__DOT__imm) 
                                                          | (4U 
                                                             & (- (IData)((IData)(vlSelf->top__DOT___pc__DOT__is_inc4)))))));
}

void Vtop___024unit____Vdpiimwrap_mem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &mem_read__Vfuncrtn);
void Vtop___024unit____Vdpiimwrap_ebreak_TOP____024unit();
void Vtop___024unit____Vdpiimwrap_mem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, IData/*31:0*/ len);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vfunc_mem_read__1__Vfuncout;
    __Vfunc_mem_read__1__Vfuncout = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__Regfile__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__Regfile__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__Regfile__DOT__rf__v0;
    __Vdlyvval__top__DOT__Regfile__DOT__rf__v0 = 0;
    // Body
    vlSelf->top__DOT___pc__DOT__current_pc = ((IData)(vlSelf->rst)
                                               ? 0x80000000U
                                               : vlSelf->top__DOT___pc__DOT__next_pc);
    vlSelf->top__DOT__rd_2 = (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0) 
                               | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))
                               ? (0x1fU & (vlSelf->top__DOT__inst 
                                           >> 7U)) : 0U);
    if ((0U != vlSelf->top__DOT___pc__DOT__current_pc)) {
        Vtop___024unit____Vdpiimwrap_mem_read_TOP____024unit(vlSelf->top__DOT___pc__DOT__current_pc, 4U, __Vfunc_mem_read__1__Vfuncout);
        vlSelf->top__DOT__inst = __Vfunc_mem_read__1__Vfuncout;
    }
    __Vdlyvval__top__DOT__Regfile__DOT__rf__v0 = ((0U 
                                                   == (IData)(vlSelf->top__DOT__rd_2))
                                                   ? 0U
                                                   : vlSelf->top__DOT__write_data);
    __Vdlyvdim0__top__DOT__Regfile__DOT__rf__v0 = vlSelf->top__DOT__rd_2;
    vlSelf->debug_write_idx = vlSelf->top__DOT__rd_2;
    vlSelf->debug_write_data = vlSelf->top__DOT__write_data;
    vlSelf->debug_rw_addr = vlSelf->top__DOT__rw_addr;
    vlSelf->debug_rs2_data = vlSelf->top__DOT__rs2_data;
    vlSelf->debug_rs1_data = vlSelf->top__DOT__rs1_data;
    vlSelf->debug_imm = vlSelf->top__DOT__imm;
    if ((IData)((0x100073U == (0xfff0007fU & vlSelf->top__DOT__inst)))) {
        Vtop___024unit____Vdpiimwrap_ebreak_TOP____024unit();
    }
    vlSelf->top__DOT__mem_op = ((IData)((3U == (0x707fU 
                                                & vlSelf->top__DOT__inst)))
                                 ? 1U : ((IData)((0x4003U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->top__DOT__inst)))
                                          ? 2U : ((IData)(
                                                          (0x1003U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->top__DOT__inst)))
                                                   ? 3U
                                                   : 
                                                  ((IData)(
                                                           (0x2003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->top__DOT__inst)))
                                                    ? 4U
                                                    : 
                                                   ((IData)(
                                                            (0x5003U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->top__DOT__inst)))
                                                     ? 5U
                                                     : 
                                                    ((IData)(
                                                             (0x23U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->top__DOT__inst)))
                                                      ? 6U
                                                      : 
                                                     ((IData)(
                                                              (0x1023U 
                                                               == 
                                                               (0x707fU 
                                                                & vlSelf->top__DOT__inst)))
                                                       ? 7U
                                                       : 
                                                      ((IData)(
                                                               (0x2023U 
                                                                == 
                                                                (0x707fU 
                                                                 & vlSelf->top__DOT__inst)))
                                                        ? 8U
                                                        : 0U))))))));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0 
        = (IData)((0x33U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0 
        = (IData)((0x7033U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0 
        = (IData)((0x5033U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0 
        = (IData)((0x4033U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0 
        = (IData)((0x1033U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0 
        = (IData)((0x3033U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0 
        = (IData)((0x6033U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0 
        = (IData)((0x5013U == (0x707fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0 
        = ((0x23U == (0x7fU & vlSelf->top__DOT__inst)) 
           | (0x63U == (0x7fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT__U_type = ((0x17U == 
                                           (0x7fU & vlSelf->top__DOT__inst)) 
                                          | (0x37U 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu__DOT__Inst_jalr = (IData)(
                                                    (0x67U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__Regfile__DOT__rf[__Vdlyvdim0__top__DOT__Regfile__DOT__rf__v0] 
        = __Vdlyvval__top__DOT__Regfile__DOT__rf__v0;
    vlSelf->top__DOT__mem__DOT__is2byte = ((3U == (IData)(vlSelf->top__DOT__mem_op)) 
                                           | ((5U == (IData)(vlSelf->top__DOT__mem_op)) 
                                              | (7U 
                                                 == (IData)(vlSelf->top__DOT__mem_op))));
    vlSelf->top__DOT__mem__DOT____VdfgTmp_h3c6dcd3f__0 
        = ((1U == (IData)(vlSelf->top__DOT__mem_op)) 
           | (2U == (IData)(vlSelf->top__DOT__mem_op)));
    vlSelf->top__DOT__mem__DOT__signed_load = ((3U 
                                                == (IData)(vlSelf->top__DOT__mem_op)) 
                                               | ((1U 
                                                   == (IData)(vlSelf->top__DOT__mem_op)) 
                                                  | (4U 
                                                     == (IData)(vlSelf->top__DOT__mem_op))));
    vlSelf->top__DOT__mem__DOT__unsigned_load = ((5U 
                                                  == (IData)(vlSelf->top__DOT__mem_op)) 
                                                 | (2U 
                                                    == (IData)(vlSelf->top__DOT__mem_op)));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0 
        = ((IData)(vlSelf->top__DOT__idu__DOT__U_type) 
           | (0x6fU == (0x7fU & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__pc_op = ((0x63U == (0x7fU & vlSelf->top__DOT__inst))
                                ? 1U : ((0x6fU == (0x7fU 
                                                   & vlSelf->top__DOT__inst))
                                         ? 2U : ((IData)(vlSelf->top__DOT__idu__DOT__Inst_jalr)
                                                  ? 3U
                                                  : 
                                                 ((0U 
                                                   == vlSelf->top__DOT__inst)
                                                   ? 0U
                                                   : 4U))));
    vlSelf->top__DOT__alu_op = ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                                  & (0U == (vlSelf->top__DOT__inst 
                                            >> 0x19U))) 
                                 | ((IData)((0x13U 
                                             == (0x707fU 
                                                 & vlSelf->top__DOT__inst))) 
                                    | ((3U == (0x7fU 
                                               & vlSelf->top__DOT__inst)) 
                                       | ((0x23U == 
                                           (0x7fU & vlSelf->top__DOT__inst)) 
                                          | ((0x6fU 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__inst)) 
                                             | ((IData)(vlSelf->top__DOT__idu__DOT__Inst_jalr) 
                                                | (IData)(vlSelf->top__DOT__idu__DOT__U_type)))))))
                                 ? 1U : (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                                          & (0x20U 
                                             == (vlSelf->top__DOT__inst 
                                                 >> 0x19U)))
                                          ? 2U : ((
                                                   ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                                                    & (0U 
                                                       == 
                                                       (vlSelf->top__DOT__inst 
                                                        >> 0x19U))) 
                                                   | (IData)(
                                                             (0x4013U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->top__DOT__inst))))
                                                   ? 3U
                                                   : 
                                                  ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                                                     & (0U 
                                                        == 
                                                        (vlSelf->top__DOT__inst 
                                                         >> 0x19U))) 
                                                    | (IData)(
                                                              (0x6013U 
                                                               == 
                                                               (0x707fU 
                                                                & vlSelf->top__DOT__inst))))
                                                    ? 4U
                                                    : 
                                                   ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                                                      & (0U 
                                                         == 
                                                         (vlSelf->top__DOT__inst 
                                                          >> 0x19U))) 
                                                     | (IData)(
                                                               (0x7013U 
                                                                == 
                                                                (0x707fU 
                                                                 & vlSelf->top__DOT__inst))))
                                                     ? 5U
                                                     : 
                                                    ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                                                       & (0U 
                                                          == 
                                                          (vlSelf->top__DOT__inst 
                                                           >> 0x19U))) 
                                                      | (IData)(
                                                                (0x1013U 
                                                                 == 
                                                                 (0xfc00707fU 
                                                                  & vlSelf->top__DOT__inst))))
                                                      ? 6U
                                                      : 
                                                     ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                                        & (0U 
                                                           == 
                                                           (vlSelf->top__DOT__inst 
                                                            >> 0x19U))) 
                                                       | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                                          & (0U 
                                                             == 
                                                             (vlSelf->top__DOT__inst 
                                                              >> 0x1aU))))
                                                       ? 7U
                                                       : 
                                                      ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                                         & (0x20U 
                                                            == 
                                                            (vlSelf->top__DOT__inst 
                                                             >> 0x19U))) 
                                                        | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                                           & (0x10U 
                                                              == 
                                                              (vlSelf->top__DOT__inst 
                                                               >> 0x1aU))))
                                                        ? 8U
                                                        : 
                                                       (((IData)(
                                                                 (0x2033U 
                                                                  == 
                                                                  (0xfe00707fU 
                                                                   & vlSelf->top__DOT__inst))) 
                                                         | (IData)(
                                                                   (0x2013U 
                                                                    == 
                                                                    (0x707fU 
                                                                     & vlSelf->top__DOT__inst))))
                                                         ? 9U
                                                         : 
                                                        ((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                                                           & (0U 
                                                              == 
                                                              (vlSelf->top__DOT__inst 
                                                               >> 0x19U))) 
                                                          | (IData)(
                                                                    (0x3013U 
                                                                     == 
                                                                     (0x707fU 
                                                                      & vlSelf->top__DOT__inst))))
                                                          ? 0xaU
                                                          : 
                                                         ((IData)(
                                                                  (0x63U 
                                                                   == 
                                                                   (0x707fU 
                                                                    & vlSelf->top__DOT__inst)))
                                                           ? 0xbU
                                                           : 
                                                          ((IData)(
                                                                   (0x1063U 
                                                                    == 
                                                                    (0x707fU 
                                                                     & vlSelf->top__DOT__inst)))
                                                            ? 0xcU
                                                            : 
                                                           ((IData)(
                                                                    (0x4063U 
                                                                     == 
                                                                     (0x707fU 
                                                                      & vlSelf->top__DOT__inst)))
                                                             ? 0xdU
                                                             : 
                                                            ((IData)(
                                                                     (0x5063U 
                                                                      == 
                                                                      (0x707fU 
                                                                       & vlSelf->top__DOT__inst)))
                                                              ? 0xeU
                                                              : 
                                                             ((IData)(
                                                                      (0x6063U 
                                                                       == 
                                                                       (0x707fU 
                                                                        & vlSelf->top__DOT__inst)))
                                                               ? 0xfU
                                                               : 
                                                              ((IData)(
                                                                       (0x7063U 
                                                                        == 
                                                                        (0x707fU 
                                                                         & vlSelf->top__DOT__inst)))
                                                                ? 0x10U
                                                                : 
                                                               (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                                                                 & (1U 
                                                                    == 
                                                                    (vlSelf->top__DOT__inst 
                                                                     >> 0x19U)))
                                                                 ? 0x11U
                                                                 : 
                                                                (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                                                                  & (1U 
                                                                     == 
                                                                     (vlSelf->top__DOT__inst 
                                                                      >> 0x19U)))
                                                                  ? 0x12U
                                                                  : 
                                                                 (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                                                                   & (1U 
                                                                      == 
                                                                      (vlSelf->top__DOT__inst 
                                                                       >> 0x19U)))
                                                                   ? 0x13U
                                                                   : 
                                                                  (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                                                                    & (1U 
                                                                       == 
                                                                       (vlSelf->top__DOT__inst 
                                                                        >> 0x19U)))
                                                                    ? 0x14U
                                                                    : 
                                                                   (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                                                     & (1U 
                                                                        == 
                                                                        (vlSelf->top__DOT__inst 
                                                                         >> 0x19U)))
                                                                     ? 0x15U
                                                                     : 
                                                                    (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                                                                      & (1U 
                                                                         == 
                                                                         (vlSelf->top__DOT__inst 
                                                                          >> 0x19U)))
                                                                      ? 0x16U
                                                                      : 
                                                                     (((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                                                                       & (1U 
                                                                          == 
                                                                          (vlSelf->top__DOT__inst 
                                                                           >> 0x19U)))
                                                                       ? 0x17U
                                                                       : 0U)))))))))))))))))))))));
    vlSelf->top__DOT__idu__DOT__I_type = ((0x13U == 
                                           (0x7fU & vlSelf->top__DOT__inst)) 
                                          | ((0x1bU 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__inst)) 
                                             | ((3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__inst)) 
                                                | (IData)(vlSelf->top__DOT__idu__DOT__Inst_jalr))));
    vlSelf->top__DOT__ex_op = ((0x17U == (0x7fU & vlSelf->top__DOT__inst))
                                ? 1U : ((0x37U == (0x7fU 
                                                   & vlSelf->top__DOT__inst))
                                         ? 2U : ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__inst))
                                                  ? 3U
                                                  : 
                                                 ((IData)(vlSelf->top__DOT__idu__DOT__Inst_jalr)
                                                   ? 4U
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__inst))
                                                    ? 5U
                                                    : 
                                                   ((0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__inst))
                                                     ? 6U
                                                     : 
                                                    ((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__inst))
                                                      ? 7U
                                                      : 
                                                     ((0x13U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->top__DOT__inst))
                                                       ? 8U
                                                       : 
                                                      ((0x33U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelf->top__DOT__inst))
                                                        ? 9U
                                                        : 0U)))))))));
    vlSelf->top__DOT__rs2_data = vlSelf->top__DOT__Regfile__DOT__rf
        [(((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
           | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0))
           ? (0x1fU & (vlSelf->top__DOT__inst >> 0x14U))
           : 0U)];
    vlSelf->top__DOT__mem__DOT__is1byte = ((IData)(vlSelf->top__DOT__mem__DOT____VdfgTmp_h3c6dcd3f__0) 
                                           | (6U == (IData)(vlSelf->top__DOT__mem_op)));
    vlSelf->top__DOT__load_valid = ((IData)(vlSelf->top__DOT__mem__DOT__unsigned_load) 
                                    | (IData)(vlSelf->top__DOT__mem__DOT__signed_load));
    vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB = (
                                                   (2U 
                                                    == (IData)(vlSelf->top__DOT__alu_op)) 
                                                   | ((9U 
                                                       == (IData)(vlSelf->top__DOT__alu_op)) 
                                                      | ((0xaU 
                                                          == (IData)(vlSelf->top__DOT__alu_op)) 
                                                         | ((0xeU 
                                                             == (IData)(vlSelf->top__DOT__alu_op)) 
                                                            | ((0x10U 
                                                                == (IData)(vlSelf->top__DOT__alu_op)) 
                                                               | ((0xdU 
                                                                   == (IData)(vlSelf->top__DOT__alu_op)) 
                                                                  | (0xfU 
                                                                     == (IData)(vlSelf->top__DOT__alu_op))))))));
    vlSelf->top__DOT__imm = ((IData)(vlSelf->top__DOT__idu__DOT__I_type)
                              ? (((- (IData)((vlSelf->top__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->top__DOT__inst 
                                              >> 0x14U))
                              : ((0x23U == (0x7fU & vlSelf->top__DOT__inst))
                                  ? (((- (IData)((vlSelf->top__DOT__inst 
                                                  >> 0x1fU))) 
                                      << 0xcU) | ((0xfe0U 
                                                   & (vlSelf->top__DOT__inst 
                                                      >> 0x14U)) 
                                                  | (0x1fU 
                                                     & (vlSelf->top__DOT__inst 
                                                        >> 7U))))
                                  : ((0x63U == (0x7fU 
                                                & vlSelf->top__DOT__inst))
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0x800U 
                                             & (vlSelf->top__DOT__inst 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelf->top__DOT__inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->top__DOT__inst 
                                                     >> 7U)))))
                                      : ((IData)(vlSelf->top__DOT__idu__DOT__U_type)
                                          ? (0xfffff000U 
                                             & vlSelf->top__DOT__inst)
                                          : ((0x6fU 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__inst))
                                              ? (((- (IData)(
                                                             (vlSelf->top__DOT__inst 
                                                              >> 0x1fU))) 
                                                  << 0x14U) 
                                                 | ((0xff000U 
                                                     & vlSelf->top__DOT__inst) 
                                                    | ((0x800U 
                                                        & (vlSelf->top__DOT__inst 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlSelf->top__DOT__inst 
                                                             >> 0x14U)))))
                                              : 0U)))));
    vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0 
        = ((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
           | (IData)(vlSelf->top__DOT__idu__DOT__I_type));
    vlSelf->top__DOT__exu__DOT__rs1_rs2 = ((9U == (IData)(vlSelf->top__DOT__ex_op)) 
                                           | (7U == (IData)(vlSelf->top__DOT__ex_op)));
    vlSelf->top__DOT__exu__DOT__rs1_imm = ((8U == (IData)(vlSelf->top__DOT__ex_op)) 
                                           | ((5U == (IData)(vlSelf->top__DOT__ex_op)) 
                                              | (6U 
                                                 == (IData)(vlSelf->top__DOT__ex_op))));
    vlSelf->top__DOT__exu__DOT__pc_4 = ((3U == (IData)(vlSelf->top__DOT__ex_op)) 
                                        | (4U == (IData)(vlSelf->top__DOT__ex_op)));
    vlSelf->top__DOT__idu__DOT__isNeed_rs1 = ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0) 
                                              | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0));
    vlSelf->top__DOT__exu__DOT__alu_src2 = ((IData)(vlSelf->top__DOT__exu__DOT__rs1_rs2)
                                             ? vlSelf->top__DOT__rs2_data
                                             : ((IData)(vlSelf->top__DOT__exu__DOT__rs1_imm)
                                                 ? vlSelf->top__DOT__imm
                                                 : 
                                                ((IData)(vlSelf->top__DOT__exu__DOT__pc_4)
                                                  ? 4U
                                                  : 
                                                 (((1U 
                                                    == (IData)(vlSelf->top__DOT__ex_op)) 
                                                   | (2U 
                                                      == (IData)(vlSelf->top__DOT__ex_op)))
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlSelf->top__DOT__imm)
                                                   : 0U))));
    vlSelf->top__DOT__rs1_data = vlSelf->top__DOT__Regfile__DOT__rf
        [((IData)(vlSelf->top__DOT__idu__DOT__isNeed_rs1)
           ? (0x1fU & (vlSelf->top__DOT__inst >> 0xfU))
           : 0U)];
    vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_b = 
        ((IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB)
          ? (~ vlSelf->top__DOT__exu__DOT__alu_src2)
          : vlSelf->top__DOT__exu__DOT__alu_src2);
    vlSelf->top__DOT__exu__DOT__alu_src1 = (((IData)(vlSelf->top__DOT__exu__DOT__rs1_rs2) 
                                             | (IData)(vlSelf->top__DOT__exu__DOT__rs1_imm))
                                             ? vlSelf->top__DOT__rs1_data
                                             : (((IData)(vlSelf->top__DOT__exu__DOT__pc_4) 
                                                 | (1U 
                                                    == (IData)(vlSelf->top__DOT__ex_op)))
                                                 ? vlSelf->top__DOT___pc__DOT__current_pc
                                                 : 0U));
    vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_ha85d5376__0 
        = (vlSelf->top__DOT__exu__DOT__alu_src1 >> 
           (0x1fU & vlSelf->top__DOT__exu__DOT__alu_src2));
    vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h1aa49d83__0 
        = ((0U != vlSelf->top__DOT__exu__DOT__alu_src2)
            ? VL_DIV_III(32, vlSelf->top__DOT__exu__DOT__alu_src1, vlSelf->top__DOT__exu__DOT__alu_src2)
            : 0U);
    vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout 
        = (1U & (IData)((1ULL & (((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src1)) 
                                  + ((QData)((IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_b)) 
                                     + ((IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB)
                                         ? 1ULL : 0ULL))) 
                                 >> 0x20U))));
    vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_result 
        = (vlSelf->top__DOT__exu__DOT__alu_src1 + (vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_b 
                                                   + 
                                                   ((IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB)
                                                     ? 1U
                                                     : 0U)));
    vlSelf->top__DOT__exu__DOT__alu_result = (((1U 
                                                == (IData)(vlSelf->top__DOT__alu_op)) 
                                               | (2U 
                                                  == (IData)(vlSelf->top__DOT__alu_op)))
                                               ? vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_result
                                               : ((3U 
                                                   == (IData)(vlSelf->top__DOT__alu_op))
                                                   ? 
                                                  (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                   ^ vlSelf->top__DOT__exu__DOT__alu_src2)
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->top__DOT__alu_op))
                                                    ? 
                                                   (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                    | vlSelf->top__DOT__exu__DOT__alu_src2)
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelf->top__DOT__alu_op))
                                                     ? 
                                                    (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                     & vlSelf->top__DOT__exu__DOT__alu_src2)
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->top__DOT__alu_op))
                                                      ? 
                                                     (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelf->top__DOT__exu__DOT__alu_src2))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->top__DOT__alu_op))
                                                       ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_ha85d5376__0
                                                       : 
                                                      ((8U 
                                                        == (IData)(vlSelf->top__DOT__alu_op))
                                                        ? 
                                                       (vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_ha85d5376__0 
                                                        | ((0x1fU 
                                                            >= 
                                                            ((IData)(0x20U) 
                                                             - 
                                                             (0x1fU 
                                                              & vlSelf->top__DOT__exu__DOT__alu_src2)))
                                                            ? 
                                                           ((- (IData)(
                                                                       (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                                        >> 0x1fU))) 
                                                            << 
                                                            ((IData)(0x20U) 
                                                             - 
                                                             (0x1fU 
                                                              & vlSelf->top__DOT__exu__DOT__alu_src2)))
                                                            : 0U))
                                                        : 
                                                       ((0x11U 
                                                         == (IData)(vlSelf->top__DOT__alu_op))
                                                         ? 
                                                        (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                         * vlSelf->top__DOT__exu__DOT__alu_src2)
                                                         : 
                                                        ((0x12U 
                                                          == (IData)(vlSelf->top__DOT__alu_op))
                                                          ? (IData)(
                                                                    (((((QData)((IData)(
                                                                                (- (IData)(
                                                                                (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                                                >> 0x1fU))))) 
                                                                        << 0x20U) 
                                                                       | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src1))) 
                                                                      * 
                                                                      (((QData)((IData)(
                                                                                (- (IData)(
                                                                                (vlSelf->top__DOT__exu__DOT__alu_src2 
                                                                                >> 0x1fU))))) 
                                                                        << 0x20U) 
                                                                       | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src2)))) 
                                                                     >> 0x20U))
                                                          : 
                                                         ((0x13U 
                                                           == (IData)(vlSelf->top__DOT__alu_op))
                                                           ? (IData)(
                                                                     (((((QData)((IData)(
                                                                                (- (IData)(
                                                                                (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                                                >> 0x1fU))))) 
                                                                         << 0x20U) 
                                                                        | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src1))) 
                                                                       * 
                                                                       (((QData)((IData)(
                                                                                (- (IData)(
                                                                                (vlSelf->top__DOT__exu__DOT__alu_src2 
                                                                                >> 0x1fU))))) 
                                                                         << 0x20U) 
                                                                        | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src2)))) 
                                                                      >> 0x20U))
                                                           : 
                                                          ((0x14U 
                                                            == (IData)(vlSelf->top__DOT__alu_op))
                                                            ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h1aa49d83__0
                                                            : 
                                                           ((0x15U 
                                                             == (IData)(vlSelf->top__DOT__alu_op))
                                                             ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h1aa49d83__0
                                                             : 
                                                            ((0x16U 
                                                              == (IData)(vlSelf->top__DOT__alu_op))
                                                              ? 
                                                             ((0U 
                                                               != vlSelf->top__DOT__exu__DOT__alu_src2)
                                                               ? 
                                                              VL_MODDIVS_III(32, vlSelf->top__DOT__exu__DOT__alu_src1, vlSelf->top__DOT__exu__DOT__alu_src2)
                                                               : 0U)
                                                              : 
                                                             ((0x17U 
                                                               == (IData)(vlSelf->top__DOT__alu_op))
                                                               ? 
                                                              ((0U 
                                                                != vlSelf->top__DOT__exu__DOT__alu_src2)
                                                                ? 
                                                               VL_MODDIV_III(32, vlSelf->top__DOT__exu__DOT__alu_src1, vlSelf->top__DOT__exu__DOT__alu_src2)
                                                                : 0U)
                                                               : 0U))))))))))))));
    vlSelf->top__DOT__exu__DOT__ALU__DOT__slt_result 
        = (1U & (((~ (vlSelf->top__DOT__exu__DOT__alu_src2 
                      >> 0x1fU)) & (vlSelf->top__DOT__exu__DOT__alu_src1 
                                    >> 0x1fU)) | ((
                                                   (~ 
                                                    (vlSelf->top__DOT__exu__DOT__alu_src2 
                                                     >> 0x1fU)) 
                                                   ^ 
                                                   (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                    >> 0x1fU)) 
                                                  & (vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_result 
                                                     >> 0x1fU))));
    vlSelf->top__DOT__compare_result = (1U & ((9U == (IData)(vlSelf->top__DOT__alu_op))
                                               ? (IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__slt_result)
                                               : ((0xaU 
                                                   == (IData)(vlSelf->top__DOT__alu_op))
                                                   ? 
                                                  (~ (IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout))
                                                   : 
                                                  ((0xbU 
                                                    == (IData)(vlSelf->top__DOT__alu_op))
                                                    ? 
                                                   (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                    == vlSelf->top__DOT__exu__DOT__alu_src2)
                                                    : 
                                                   ((0xcU 
                                                     == (IData)(vlSelf->top__DOT__alu_op))
                                                     ? 
                                                    (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                     != vlSelf->top__DOT__exu__DOT__alu_src2)
                                                     : 
                                                    ((0xdU 
                                                      == (IData)(vlSelf->top__DOT__alu_op))
                                                      ? (IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__slt_result)
                                                      : 
                                                     ((0xeU 
                                                       == (IData)(vlSelf->top__DOT__alu_op))
                                                       ? 
                                                      (~ (IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__slt_result))
                                                       : 
                                                      ((0xfU 
                                                        == (IData)(vlSelf->top__DOT__alu_op))
                                                        ? 
                                                       (~ (IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout))
                                                        : 
                                                       ((IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout) 
                                                        & (0x10U 
                                                           == (IData)(vlSelf->top__DOT__alu_op)))))))))));
    vlSelf->top__DOT___pc__DOT__is_branch = ((IData)(vlSelf->top__DOT__compare_result) 
                                             & (1U 
                                                == (IData)(vlSelf->top__DOT__pc_op)));
    vlSelf->top__DOT__ex_alu_data = (vlSelf->top__DOT__exu__DOT__alu_result 
                                     | (IData)(vlSelf->top__DOT__compare_result));
    vlSelf->top__DOT___pc__DOT__is_inc4 = ((4U == (IData)(vlSelf->top__DOT__pc_op)) 
                                           | ((~ (IData)(vlSelf->top__DOT___pc__DOT__is_branch)) 
                                              & (1U 
                                                 == (IData)(vlSelf->top__DOT__pc_op))));
    vlSelf->top__DOT__rw_addr = ((0U == (IData)(vlSelf->top__DOT__mem_op))
                                  ? 0U : vlSelf->top__DOT__ex_alu_data);
    vlSelf->top__DOT___pc__DOT__next_pc = ((((- (IData)(
                                                        ((2U 
                                                          == (IData)(vlSelf->top__DOT__pc_op)) 
                                                         | ((0U 
                                                             == (IData)(vlSelf->top__DOT__pc_op)) 
                                                            | ((IData)(vlSelf->top__DOT___pc__DOT__is_branch) 
                                                               | (IData)(vlSelf->top__DOT___pc__DOT__is_inc4)))))) 
                                             & vlSelf->top__DOT___pc__DOT__current_pc) 
                                            | ((- (IData)(
                                                          (3U 
                                                           == (IData)(vlSelf->top__DOT__pc_op)))) 
                                               & vlSelf->top__DOT__rs1_data)) 
                                           + (((- (IData)(
                                                          ((IData)(vlSelf->top__DOT___pc__DOT__is_branch) 
                                                           | ((2U 
                                                               == (IData)(vlSelf->top__DOT__pc_op)) 
                                                              | (3U 
                                                                 == (IData)(vlSelf->top__DOT__pc_op)))))) 
                                               & vlSelf->top__DOT__imm) 
                                              | (4U 
                                                 & (- (IData)((IData)(vlSelf->top__DOT___pc__DOT__is_inc4))))));
    if ((0U != vlSelf->top__DOT__rw_addr)) {
        if (((0U != (IData)(vlSelf->top__DOT__mem_op)) 
             & ((6U == (IData)(vlSelf->top__DOT__mem_op)) 
                | ((7U == (IData)(vlSelf->top__DOT__mem_op)) 
                   | (8U == (IData)(vlSelf->top__DOT__mem_op)))))) {
            Vtop___024unit____Vdpiimwrap_mem_write_TOP____024unit(vlSelf->top__DOT__rw_addr, 
                                                                  ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                                                    ? 
                                                                   (0xffU 
                                                                    & vlSelf->top__DOT__rs2_data)
                                                                    : 
                                                                   ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                                                     ? 
                                                                    (0xffffU 
                                                                     & vlSelf->top__DOT__rs2_data)
                                                                     : vlSelf->top__DOT__rs2_data)), 
                                                                  ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                                                    ? 1U
                                                                    : 
                                                                   ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                                                     ? 2U
                                                                     : 4U)));
        }
    }
    Vtop___024unit____Vdpiimwrap_mem_read_TOP____024unit(vlSelf->top__DOT__rw_addr, 
                                                         ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                                           ? 1U
                                                           : 
                                                          ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                                            ? 2U
                                                            : 4U)), vlSelf->__Vfunc_mem_read__5__Vfuncout);
    vlSelf->top__DOT__read_data = (((0U != vlSelf->top__DOT__rw_addr) 
                                    & (IData)(vlSelf->top__DOT__load_valid))
                                    ? vlSelf->__Vfunc_mem_read__5__Vfuncout
                                    : 0U);
    vlSelf->top__DOT__write_data = ((IData)(vlSelf->top__DOT__load_valid)
                                     ? ((IData)(vlSelf->top__DOT__mem__DOT__signed_load)
                                         ? ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                             ? (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->top__DOT__read_data 
                                                                >> 7U)))) 
                                                 << 8U) 
                                                | (0xffU 
                                                   & vlSelf->top__DOT__read_data))
                                             : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                                 ? 
                                                (((- (IData)(
                                                             (1U 
                                                              & (vlSelf->top__DOT__read_data 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelf->top__DOT__read_data))
                                                 : vlSelf->top__DOT__read_data))
                                         : ((IData)(vlSelf->top__DOT__mem__DOT__unsigned_load)
                                             ? ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                                 ? 
                                                (0xffU 
                                                 & vlSelf->top__DOT__read_data)
                                                 : 
                                                ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                                  ? 
                                                 (0xffffU 
                                                  & vlSelf->top__DOT__read_data)
                                                  : vlSelf->top__DOT__read_data))
                                             : 0U))
                                     : vlSelf->top__DOT__ex_alu_data);
}
