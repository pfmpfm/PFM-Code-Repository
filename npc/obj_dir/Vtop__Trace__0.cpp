// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT___pc__DOT__current_pc),32);
        bufp->chgIData(oldp+1,(vlSelf->top__DOT__inst),32);
        bufp->chgCData(oldp+2,(((IData)(vlSelf->top__DOT__idu__DOT__isNeed_rs1)
                                 ? (0x1fU & (vlSelf->top__DOT__inst 
                                             >> 0xfU))
                                 : 0U)),5);
        bufp->chgCData(oldp+3,((((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
                                 | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0))
                                 ? (0x1fU & (vlSelf->top__DOT__inst 
                                             >> 0x14U))
                                 : 0U)),5);
        bufp->chgCData(oldp+4,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0) 
                                 | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))
                                 ? (0x1fU & (vlSelf->top__DOT__inst 
                                             >> 7U))
                                 : 0U)),5);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__imm),32);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__alu_op),5);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__mem_op),4);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__ex_op),4);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__pc_op),4);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__rs1_data),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__rs2_data),32);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__rd_2),5);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__write_data),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__ex_alu_data),32);
        bufp->chgBit(oldp+15,(vlSelf->top__DOT__compare_result));
        bufp->chgIData(oldp+16,(((IData)(vlSelf->top__DOT__mem__DOT__signed_load)
                                  ? ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                      ? (((- (IData)(
                                                     (1U 
                                                      & (vlSelf->top__DOT__read_data 
                                                         >> 7U)))) 
                                          << 8U) | 
                                         (0xffU & vlSelf->top__DOT__read_data))
                                      : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                          ? (((- (IData)(
                                                         (1U 
                                                          & (vlSelf->top__DOT__read_data 
                                                             >> 0xfU)))) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & vlSelf->top__DOT__read_data))
                                          : vlSelf->top__DOT__read_data))
                                  : ((IData)(vlSelf->top__DOT__mem__DOT__unsigned_load)
                                      ? ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                          ? (0xffU 
                                             & vlSelf->top__DOT__read_data)
                                          : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                              ? (0xffffU 
                                                 & vlSelf->top__DOT__read_data)
                                              : vlSelf->top__DOT__read_data))
                                      : 0U))),32);
        bufp->chgBit(oldp+17,(vlSelf->top__DOT__load_valid));
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__read_data),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__rw_addr),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__Regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__Regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__Regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__Regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__Regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__Regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__Regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__Regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__Regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__Regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__Regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__Regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__Regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__Regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__Regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__Regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__Regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__Regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__Regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__Regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__Regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__Regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__Regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__Regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__Regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__Regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__Regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__Regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__Regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__Regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__Regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__Regfile__DOT__rf[31]),32);
        bufp->chgBit(oldp+52,((1U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+53,((2U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+54,((3U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+55,((4U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+56,((7U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+57,((8U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+58,((9U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+59,((5U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+60,((6U == (IData)(vlSelf->top__DOT__ex_op))));
        bufp->chgBit(oldp+61,(vlSelf->top__DOT__exu__DOT__rs1_rs2));
        bufp->chgBit(oldp+62,(vlSelf->top__DOT__exu__DOT__rs1_imm));
        bufp->chgBit(oldp+63,(vlSelf->top__DOT__exu__DOT__pc_4));
        bufp->chgIData(oldp+64,((0xfffff000U & vlSelf->top__DOT__imm)),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__exu__DOT__alu_src1),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__exu__DOT__alu_src2),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__exu__DOT__alu_result),32);
        bufp->chgBit(oldp+68,((1U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+69,((2U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+70,((3U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+71,((4U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+72,((5U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+73,((6U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+74,((7U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+75,((8U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+76,((9U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+77,((0xaU == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+78,((0xbU == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+79,((0xcU == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+80,((0xdU == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+81,((0xeU == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+82,((0xfU == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+83,((0x10U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+84,((0x11U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+85,((0x12U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+86,((0x13U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+87,((0x14U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+88,((0x15U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+89,((0x16U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+90,((0x17U == (IData)(vlSelf->top__DOT__alu_op))));
        bufp->chgBit(oldp+91,(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout));
        bufp->chgIData(oldp+92,(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_result),32);
        bufp->chgIData(oldp+93,(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_b),32);
        bufp->chgQData(oldp+94,(((IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB)
                                  ? 1ULL : 0ULL)),33);
        bufp->chgBit(oldp+96,(vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB));
        bufp->chgBit(oldp+97,(vlSelf->top__DOT__exu__DOT__ALU__DOT__slt_result));
        bufp->chgBit(oldp+98,((1U & (~ (IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout)))));
        bufp->chgQData(oldp+99,(((((QData)((IData)(
                                                   (- (IData)(
                                                              (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                               >> 0x1fU))))) 
                                   << 0x20U) | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src1))) 
                                 * (((QData)((IData)(
                                                     (- (IData)(
                                                                (vlSelf->top__DOT__exu__DOT__alu_src2 
                                                                 >> 0x1fU))))) 
                                     << 0x20U) | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src2))))),64);
        bufp->chgQData(oldp+101,(((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src1)) 
                                  * (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src2)))),64);
        bufp->chgIData(oldp+103,((IData)((((((QData)((IData)(
                                                             (- (IData)(
                                                                        (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                                         >> 0x1fU))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src1))) 
                                           * (((QData)((IData)(
                                                               (- (IData)(
                                                                          (vlSelf->top__DOT__exu__DOT__alu_src2 
                                                                           >> 0x1fU))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src2)))) 
                                          >> 0x20U))),32);
        bufp->chgCData(oldp+104,((0x7fU & vlSelf->top__DOT__inst)),7);
        bufp->chgCData(oldp+105,((7U & (vlSelf->top__DOT__inst 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+106,((vlSelf->top__DOT__inst 
                                  >> 0x19U)),7);
        bufp->chgSData(oldp+107,((vlSelf->top__DOT__inst 
                                  >> 0x14U)),12);
        bufp->chgBit(oldp+108,((0x33U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+109,(vlSelf->top__DOT__idu__DOT__I_type));
        bufp->chgBit(oldp+110,((0x23U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+111,((0x63U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+112,(vlSelf->top__DOT__idu__DOT__U_type));
        bufp->chgBit(oldp+113,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+114,((1U & (~ ((IData)(vlSelf->top__DOT__idu__DOT__isNeed_rs1) 
                                         | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))))));
        bufp->chgBit(oldp+115,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+116,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+117,((IData)((0x13U == (0x707fU 
                                                  & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+118,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+119,((IData)((0x7013U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+120,((IData)((0x63U == (0x707fU 
                                                  & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+121,((IData)((0x1063U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+122,((IData)((0x5063U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+123,((IData)((0x7063U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+124,((IData)((0x4063U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+125,((IData)((0x6063U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+126,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                & (1U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+127,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                                & (1U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+128,((IData)((0x2003U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+129,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+130,((IData)((0x4003U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+131,((IData)((0x1003U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+132,((IData)((3U == (0x707fU 
                                               & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+133,((IData)((0x5003U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+134,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                                & (1U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+135,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                                & (1U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+136,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                                & (1U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+137,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+138,((IData)((0x6013U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+139,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                                & (1U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+140,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                                & (1U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+141,((IData)((0x2023U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+142,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                                & (0x20U == (vlSelf->top__DOT__inst 
                                             >> 0x19U)))));
        bufp->chgBit(oldp+143,((IData)((0x3013U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+144,((IData)((0x2013U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+145,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+146,((IData)((0x1023U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+147,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                & (0x10U == (vlSelf->top__DOT__inst 
                                             >> 0x1aU)))));
        bufp->chgBit(oldp+148,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+149,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x1aU)))));
        bufp->chgBit(oldp+150,((IData)((0x1013U == 
                                        (0xfc00707fU 
                                         & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+151,((IData)((0x2033U == 
                                        (0xfe00707fU 
                                         & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+152,((IData)((0x23U == (0x707fU 
                                                  & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+153,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                & (0x20U == (vlSelf->top__DOT__inst 
                                             >> 0x19U)))));
        bufp->chgBit(oldp+154,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+155,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+156,((IData)((0x4013U == 
                                        (0x707fU & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+157,(vlSelf->top__DOT__idu__DOT__Inst_jalr));
        bufp->chgBit(oldp+158,((0x100073U == vlSelf->top__DOT__inst)));
        bufp->chgBit(oldp+159,((3U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+160,((0x13U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgIData(oldp+161,((((- (IData)((vlSelf->top__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0xcU) | (vlSelf->top__DOT__inst 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+162,((((- (IData)((vlSelf->top__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0xcU) | ((0xfe0U 
                                                & (vlSelf->top__DOT__inst 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelf->top__DOT__inst 
                                                     >> 7U))))),32);
        bufp->chgIData(oldp+163,((((- (IData)((vlSelf->top__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0xcU) | ((0x800U 
                                                & (vlSelf->top__DOT__inst 
                                                   << 4U)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->top__DOT__inst 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelf->top__DOT__inst 
                                                        >> 7U)))))),32);
        bufp->chgIData(oldp+164,((0xfffff000U & vlSelf->top__DOT__inst)),32);
        bufp->chgIData(oldp+165,((((- (IData)((vlSelf->top__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0x14U) | ((0xff000U 
                                                 & vlSelf->top__DOT__inst) 
                                                | ((0x800U 
                                                    & (vlSelf->top__DOT__inst 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSelf->top__DOT__inst 
                                                         >> 0x14U)))))),32);
        bufp->chgBit(oldp+166,(((IData)(vlSelf->top__DOT__idu__DOT__I_type) 
                                | ((0x23U == (0x7fU 
                                              & vlSelf->top__DOT__inst)) 
                                   | ((0x63U == (0x7fU 
                                                 & vlSelf->top__DOT__inst)) 
                                      | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))))));
        bufp->chgBit(oldp+167,(vlSelf->top__DOT__idu__DOT__isNeed_rs1));
        bufp->chgBit(oldp+168,(((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
                                | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0))));
        bufp->chgBit(oldp+169,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0) 
                                | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))));
        bufp->chgBit(oldp+170,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                                 & (0U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                                | ((IData)((0x13U == 
                                            (0x707fU 
                                             & vlSelf->top__DOT__inst))) 
                                   | ((3U == (0x7fU 
                                              & vlSelf->top__DOT__inst)) 
                                      | ((0x23U == 
                                          (0x7fU & vlSelf->top__DOT__inst)) 
                                         | ((0x6fU 
                                             == (0x7fU 
                                                 & vlSelf->top__DOT__inst)) 
                                            | ((IData)(vlSelf->top__DOT__idu__DOT__Inst_jalr) 
                                               | (IData)(vlSelf->top__DOT__idu__DOT__U_type)))))))));
        bufp->chgBit(oldp+171,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                                 & (0U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                                | (IData)((0x4013U 
                                           == (0x707fU 
                                               & vlSelf->top__DOT__inst))))));
        bufp->chgBit(oldp+172,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                                 & (0U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                                | (IData)((0x7013U 
                                           == (0x707fU 
                                               & vlSelf->top__DOT__inst))))));
        bufp->chgBit(oldp+173,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                                 & (0U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                                | (IData)((0x6013U 
                                           == (0x707fU 
                                               & vlSelf->top__DOT__inst))))));
        bufp->chgBit(oldp+174,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                                 & (0U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                                | (IData)((0x1013U 
                                           == (0xfc00707fU 
                                               & vlSelf->top__DOT__inst))))));
        bufp->chgBit(oldp+175,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                 & (0U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                                | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                   & (0U == (vlSelf->top__DOT__inst 
                                             >> 0x1aU))))));
        bufp->chgBit(oldp+176,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                                 & (0x20U == (vlSelf->top__DOT__inst 
                                              >> 0x19U))) 
                                | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                   & (0x10U == (vlSelf->top__DOT__inst 
                                                >> 0x1aU))))));
        bufp->chgBit(oldp+177,(((IData)((0x2033U == 
                                         (0xfe00707fU 
                                          & vlSelf->top__DOT__inst))) 
                                | (IData)((0x2013U 
                                           == (0x707fU 
                                               & vlSelf->top__DOT__inst))))));
        bufp->chgBit(oldp+178,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                                 & (0U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                                | (IData)((0x3013U 
                                           == (0x707fU 
                                               & vlSelf->top__DOT__inst))))));
        bufp->chgBit(oldp+179,((0U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+180,((1U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+181,((2U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+182,((3U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+183,((4U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+184,((5U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+185,((6U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+186,((7U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+187,((8U == (IData)(vlSelf->top__DOT__mem_op))));
        bufp->chgBit(oldp+188,(((0U != (IData)(vlSelf->top__DOT__mem_op)) 
                                & ((IData)(vlSelf->top__DOT__mem__DOT____VdfgTmp_h3c6dcd3f__0) 
                                   | ((3U == (IData)(vlSelf->top__DOT__mem_op)) 
                                      | ((5U == (IData)(vlSelf->top__DOT__mem_op)) 
                                         | (4U == (IData)(vlSelf->top__DOT__mem_op))))))));
        bufp->chgBit(oldp+189,(((0U != (IData)(vlSelf->top__DOT__mem_op)) 
                                & ((6U == (IData)(vlSelf->top__DOT__mem_op)) 
                                   | ((7U == (IData)(vlSelf->top__DOT__mem_op)) 
                                      | (8U == (IData)(vlSelf->top__DOT__mem_op)))))));
        bufp->chgBit(oldp+190,(vlSelf->top__DOT__mem__DOT__is1byte));
        bufp->chgBit(oldp+191,(vlSelf->top__DOT__mem__DOT__is2byte));
        bufp->chgBit(oldp+192,(((4U == (IData)(vlSelf->top__DOT__mem_op)) 
                                | (8U == (IData)(vlSelf->top__DOT__mem_op)))));
        bufp->chgBit(oldp+193,(vlSelf->top__DOT__mem__DOT__unsigned_load));
        bufp->chgBit(oldp+194,(vlSelf->top__DOT__mem__DOT__signed_load));
        bufp->chgIData(oldp+195,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                   ? (((- (IData)((1U 
                                                   & (vlSelf->top__DOT__read_data 
                                                      >> 7U)))) 
                                       << 8U) | (0xffU 
                                                 & vlSelf->top__DOT__read_data))
                                   : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                       ? (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->top__DOT__read_data 
                                                          >> 0xfU)))) 
                                           << 0x10U) 
                                          | (0xffffU 
                                             & vlSelf->top__DOT__read_data))
                                       : vlSelf->top__DOT__read_data))),32);
        bufp->chgIData(oldp+196,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                   ? (0xffU & vlSelf->top__DOT__read_data)
                                   : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                       ? (0xffffU & vlSelf->top__DOT__read_data)
                                       : vlSelf->top__DOT__read_data))),32);
        bufp->chgIData(oldp+197,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                   ? (0xffU & vlSelf->top__DOT__rs2_data)
                                   : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                       ? (0xffffU & vlSelf->top__DOT__rs2_data)
                                       : vlSelf->top__DOT__rs2_data))),32);
        bufp->chgIData(oldp+198,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                   ? 1U : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                            ? 2U : 4U))),32);
    }
    bufp->chgBit(oldp+199,(vlSelf->clk));
    bufp->chgBit(oldp+200,(vlSelf->rst));
    bufp->chgIData(oldp+201,(vlSelf->debug_rs1_data),32);
    bufp->chgIData(oldp+202,(vlSelf->debug_rs2_data),32);
    bufp->chgIData(oldp+203,(vlSelf->debug_imm),32);
    bufp->chgIData(oldp+204,(vlSelf->debug_write_idx),32);
    bufp->chgIData(oldp+205,(vlSelf->debug_write_data),32);
    bufp->chgIData(oldp+206,(vlSelf->debug_rw_addr),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
