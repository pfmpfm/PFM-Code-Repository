// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBus(c+202,"debug_rs1_data", false,-1, 31,0);
    tracep->declBus(c+203,"debug_rs2_data", false,-1, 31,0);
    tracep->declBus(c+204,"debug_imm", false,-1, 31,0);
    tracep->declBus(c+205,"debug_write_idx", false,-1, 31,0);
    tracep->declBus(c+206,"debug_write_data", false,-1, 31,0);
    tracep->declBus(c+207,"debug_rw_addr", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBus(c+202,"debug_rs1_data", false,-1, 31,0);
    tracep->declBus(c+203,"debug_rs2_data", false,-1, 31,0);
    tracep->declBus(c+204,"debug_imm", false,-1, 31,0);
    tracep->declBus(c+205,"debug_write_idx", false,-1, 31,0);
    tracep->declBus(c+206,"debug_write_data", false,-1, 31,0);
    tracep->declBus(c+207,"debug_rw_addr", false,-1, 31,0);
    tracep->declBus(c+1,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"inst", false,-1, 31,0);
    tracep->declBus(c+3,"rs1", false,-1, 4,0);
    tracep->declBus(c+4,"rs2", false,-1, 4,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+6,"imm", false,-1, 31,0);
    tracep->declBus(c+7,"alu_op", false,-1, 4,0);
    tracep->declBus(c+8,"mem_op", false,-1, 3,0);
    tracep->declBus(c+9,"ex_op", false,-1, 3,0);
    tracep->declBus(c+10,"pc_op", false,-1, 3,0);
    tracep->declBus(c+11,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+12,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+13,"write_idx", false,-1, 4,0);
    tracep->declBus(c+14,"write_data", false,-1, 31,0);
    tracep->declBus(c+15,"ex_alu_data", false,-1, 31,0);
    tracep->declBit(c+16,"compare_result", false,-1);
    tracep->declBus(c+17,"mem_data", false,-1, 31,0);
    tracep->declBit(c+18,"load_valid", false,-1);
    tracep->declBus(c+13,"rd_2", false,-1, 4,0);
    tracep->declBus(c+19,"read_data", false,-1, 31,0);
    tracep->declBus(c+14,"wb_data", false,-1, 31,0);
    tracep->declBus(c+20,"rw_addr", false,-1, 31,0);
    tracep->pushNamePrefix("Regfile ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBus(c+3,"raddr1", false,-1, 4,0);
    tracep->declBus(c+11,"rdata1", false,-1, 31,0);
    tracep->declBus(c+4,"raddr2", false,-1, 4,0);
    tracep->declBus(c+12,"rdata2", false,-1, 31,0);
    tracep->declBit(c+208,"wen", false,-1);
    tracep->declBus(c+13,"waddr", false,-1, 4,0);
    tracep->declBus(c+14,"wdata", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+21+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("_pc ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu ");
    tracep->declBus(c+1,"pc", false,-1, 31,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+11,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+12,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+6,"imm", false,-1, 31,0);
    tracep->declBus(c+7,"alu_op", false,-1, 4,0);
    tracep->declBus(c+9,"ex_op", false,-1, 3,0);
    tracep->declBus(c+15,"ex_alu_data", false,-1, 31,0);
    tracep->declBit(c+16,"compare_result", false,-1);
    tracep->declBit(c+53,"op_auipc", false,-1);
    tracep->declBit(c+54,"op_lui", false,-1);
    tracep->declBit(c+55,"op_jal", false,-1);
    tracep->declBit(c+56,"op_jalr", false,-1);
    tracep->declBit(c+57,"op_branch", false,-1);
    tracep->declBit(c+58,"op_imm_type", false,-1);
    tracep->declBit(c+59,"op_op_type", false,-1);
    tracep->declBit(c+60,"op_load_type", false,-1);
    tracep->declBit(c+61,"op_store_type", false,-1);
    tracep->declBit(c+62,"rs1_rs2", false,-1);
    tracep->declBit(c+63,"rs1_imm", false,-1);
    tracep->declBit(c+64,"pc_4", false,-1);
    tracep->declBit(c+53,"pc_imm12", false,-1);
    tracep->declBit(c+54,"none_imm12", false,-1);
    tracep->declBus(c+65,"imm12", false,-1, 31,0);
    tracep->declBus(c+66,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+67,"alu_src2", false,-1, 31,0);
    tracep->declBus(c+68,"alu_result", false,-1, 31,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+7,"alu_op", false,-1, 4,0);
    tracep->declBus(c+9,"ex_op", false,-1, 3,0);
    tracep->declBus(c+66,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+67,"alu_src2", false,-1, 31,0);
    tracep->declBus(c+68,"alu_result", false,-1, 31,0);
    tracep->declBit(c+16,"compare_result", false,-1);
    tracep->declBit(c+69,"op_add", false,-1);
    tracep->declBit(c+70,"op_sub", false,-1);
    tracep->declBit(c+71,"op_xor", false,-1);
    tracep->declBit(c+72,"op_or", false,-1);
    tracep->declBit(c+73,"op_and", false,-1);
    tracep->declBit(c+74,"op_sll", false,-1);
    tracep->declBit(c+75,"op_srl", false,-1);
    tracep->declBit(c+76,"op_sra", false,-1);
    tracep->declBit(c+77,"op_slt", false,-1);
    tracep->declBit(c+78,"op_sltu", false,-1);
    tracep->declBit(c+79,"op_beq", false,-1);
    tracep->declBit(c+80,"op_bne", false,-1);
    tracep->declBit(c+81,"op_blt", false,-1);
    tracep->declBit(c+82,"op_bge", false,-1);
    tracep->declBit(c+83,"op_bltu", false,-1);
    tracep->declBit(c+84,"op_bgeu", false,-1);
    tracep->declBit(c+85,"op_mul", false,-1);
    tracep->declBit(c+86,"op_mulh", false,-1);
    tracep->declBit(c+87,"op_mulhu", false,-1);
    tracep->declBit(c+88,"op_div", false,-1);
    tracep->declBit(c+89,"op_divu", false,-1);
    tracep->declBit(c+90,"op_rem", false,-1);
    tracep->declBit(c+91,"op_remu", false,-1);
    tracep->declBit(c+92,"adder_cout", false,-1);
    tracep->declBus(c+93,"adder_result", false,-1, 31,0);
    tracep->declBus(c+66,"adder_a", false,-1, 31,0);
    tracep->declBus(c+94,"adder_b", false,-1, 31,0);
    tracep->declQuad(c+95,"adder_cin", false,-1, 32,0);
    tracep->declBit(c+97,"isSUB", false,-1);
    tracep->declBit(c+98,"slt_result", false,-1);
    tracep->declBit(c+99,"sltu_result", false,-1);
    tracep->declQuad(c+100,"mulh_64_result", false,-1, 63,0);
    tracep->declQuad(c+102,"mulhu_64_result", false,-1, 63,0);
    tracep->declBus(c+104,"mulh_32_result", false,-1, 31,0);
    tracep->declBus(c+104,"mulhu_32_result", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+2,"inst", false,-1, 31,0);
    tracep->declBus(c+3,"rs1", false,-1, 4,0);
    tracep->declBus(c+4,"rs2", false,-1, 4,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+6,"imm", false,-1, 31,0);
    tracep->declBus(c+7,"alu_op", false,-1, 4,0);
    tracep->declBus(c+8,"mem_op", false,-1, 3,0);
    tracep->declBus(c+9,"ex_op", false,-1, 3,0);
    tracep->declBus(c+10,"pc_op", false,-1, 3,0);
    tracep->declBus(c+105,"opcode", false,-1, 6,0);
    tracep->declBus(c+106,"funct3", false,-1, 2,0);
    tracep->declBus(c+107,"funct7", false,-1, 6,0);
    tracep->declBus(c+108,"funct12", false,-1, 11,0);
    tracep->declBit(c+109,"R_type", false,-1);
    tracep->declBit(c+110,"I_type", false,-1);
    tracep->declBit(c+111,"S_type", false,-1);
    tracep->declBit(c+112,"B_type", false,-1);
    tracep->declBit(c+113,"U_type", false,-1);
    tracep->declBit(c+114,"J_type", false,-1);
    tracep->declBit(c+115,"NONE_type", false,-1);
    tracep->declBit(c+116,"Inst_auipc", false,-1);
    tracep->declBit(c+117,"Inst_add", false,-1);
    tracep->declBit(c+118,"Inst_addi", false,-1);
    tracep->declBit(c+119,"Inst_and", false,-1);
    tracep->declBit(c+120,"Inst_andi", false,-1);
    tracep->declBit(c+121,"Inst_beq", false,-1);
    tracep->declBit(c+122,"Inst_bne", false,-1);
    tracep->declBit(c+123,"Inst_bge", false,-1);
    tracep->declBit(c+124,"Inst_bgeu", false,-1);
    tracep->declBit(c+125,"Inst_blt", false,-1);
    tracep->declBit(c+126,"Inst_bltu", false,-1);
    tracep->declBit(c+127,"Inst_divu", false,-1);
    tracep->declBit(c+128,"Inst_div", false,-1);
    tracep->declBit(c+129,"Inst_lw", false,-1);
    tracep->declBit(c+130,"Inst_lui", false,-1);
    tracep->declBit(c+131,"Inst_lbu", false,-1);
    tracep->declBit(c+132,"Inst_lh", false,-1);
    tracep->declBit(c+133,"Inst_lb", false,-1);
    tracep->declBit(c+134,"Inst_lhu", false,-1);
    tracep->declBit(c+135,"Inst_mul", false,-1);
    tracep->declBit(c+136,"Inst_mulh", false,-1);
    tracep->declBit(c+137,"Inst_mulhu", false,-1);
    tracep->declBit(c+138,"Inst_or", false,-1);
    tracep->declBit(c+139,"Inst_ori", false,-1);
    tracep->declBit(c+140,"Inst_rem", false,-1);
    tracep->declBit(c+141,"Inst_remu", false,-1);
    tracep->declBit(c+142,"Inst_sw", false,-1);
    tracep->declBit(c+143,"Inst_sub", false,-1);
    tracep->declBit(c+144,"Inst_sltiu", false,-1);
    tracep->declBit(c+145,"Inst_slti", false,-1);
    tracep->declBit(c+146,"Inst_sltu", false,-1);
    tracep->declBit(c+147,"Inst_sh", false,-1);
    tracep->declBit(c+148,"Inst_srai", false,-1);
    tracep->declBit(c+149,"Inst_sll", false,-1);
    tracep->declBit(c+150,"Inst_srli", false,-1);
    tracep->declBit(c+151,"Inst_slli", false,-1);
    tracep->declBit(c+152,"Inst_slt", false,-1);
    tracep->declBit(c+153,"Inst_sb", false,-1);
    tracep->declBit(c+154,"Inst_sra", false,-1);
    tracep->declBit(c+155,"Inst_srl", false,-1);
    tracep->declBit(c+156,"Inst_xor", false,-1);
    tracep->declBit(c+157,"Inst_xori", false,-1);
    tracep->declBit(c+114,"Inst_jal", false,-1);
    tracep->declBit(c+158,"Inst_jalr", false,-1);
    tracep->declBit(c+159,"Inst_ebreak", false,-1);
    tracep->declBit(c+160,"load_type", false,-1);
    tracep->declBit(c+111,"store_type", false,-1);
    tracep->declBit(c+112,"branch_type", false,-1);
    tracep->declBit(c+109,"op_type", false,-1);
    tracep->declBit(c+161,"op_imm_type", false,-1);
    tracep->declBus(c+162,"I_imm", false,-1, 31,0);
    tracep->declBus(c+163,"S_imm", false,-1, 31,0);
    tracep->declBus(c+164,"B_imm", false,-1, 31,0);
    tracep->declBus(c+165,"U_imm", false,-1, 31,0);
    tracep->declBus(c+166,"J_imm", false,-1, 31,0);
    tracep->declBit(c+167,"isNeed_imm", false,-1);
    tracep->declBit(c+168,"isNeed_rs1", false,-1);
    tracep->declBit(c+169,"isNeed_rs2", false,-1);
    tracep->declBit(c+170,"isNeed_rd", false,-1);
    tracep->declBit(c+171,"alu_add", false,-1);
    tracep->declBit(c+143,"alu_sub", false,-1);
    tracep->declBit(c+172,"alu_xor", false,-1);
    tracep->declBit(c+173,"alu_and", false,-1);
    tracep->declBit(c+174,"alu_or", false,-1);
    tracep->declBit(c+175,"alu_sll", false,-1);
    tracep->declBit(c+176,"alu_srl", false,-1);
    tracep->declBit(c+177,"alu_sra", false,-1);
    tracep->declBit(c+178,"alu_slt", false,-1);
    tracep->declBit(c+179,"alu_sltu", false,-1);
    tracep->declBit(c+121,"alu_beq", false,-1);
    tracep->declBit(c+122,"alu_bne", false,-1);
    tracep->declBit(c+125,"alu_blt", false,-1);
    tracep->declBit(c+123,"alu_bge", false,-1);
    tracep->declBit(c+126,"alu_bltu", false,-1);
    tracep->declBit(c+124,"alu_bgeu", false,-1);
    tracep->declBit(c+135,"alu_mul", false,-1);
    tracep->declBit(c+136,"alu_mulh", false,-1);
    tracep->declBit(c+137,"alu_mulhu", false,-1);
    tracep->declBit(c+128,"alu_div", false,-1);
    tracep->declBit(c+127,"alu_divu", false,-1);
    tracep->declBit(c+140,"alu_rem", false,-1);
    tracep->declBit(c+141,"alu_remu", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBus(c+1,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+200,"clk", false,-1);
    tracep->declBit(c+201,"rst", false,-1);
    tracep->declBus(c+1,"pc", false,-1, 31,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+12,"rs2_data", false,-1, 31,0);
    tracep->declBus(c+6,"imm", false,-1, 31,0);
    tracep->declBus(c+8,"mem_op", false,-1, 3,0);
    tracep->declBus(c+15,"ex_alu_data", false,-1, 31,0);
    tracep->declBus(c+17,"mem_data", false,-1, 31,0);
    tracep->declBit(c+18,"load_valid", false,-1);
    tracep->declBus(c+13,"rd_2", false,-1, 4,0);
    tracep->declBus(c+20,"rw_addr", false,-1, 31,0);
    tracep->declBus(c+19,"read_data", false,-1, 31,0);
    tracep->declBit(c+180,"op_none", false,-1);
    tracep->declBit(c+181,"op_lb", false,-1);
    tracep->declBit(c+182,"op_lbu", false,-1);
    tracep->declBit(c+183,"op_lh", false,-1);
    tracep->declBit(c+184,"op_lw", false,-1);
    tracep->declBit(c+185,"op_lhu", false,-1);
    tracep->declBit(c+186,"op_sb", false,-1);
    tracep->declBit(c+187,"op_sh", false,-1);
    tracep->declBit(c+188,"op_sw", false,-1);
    tracep->declBit(c+189,"isLoad", false,-1);
    tracep->declBit(c+190,"isStore", false,-1);
    tracep->declBit(c+191,"is1byte", false,-1);
    tracep->declBit(c+192,"is2byte", false,-1);
    tracep->declBit(c+193,"is4byte", false,-1);
    tracep->declBit(c+194,"unsigned_load", false,-1);
    tracep->declBit(c+195,"signed_load", false,-1);
    tracep->declBus(c+196,"signed_mem_data", false,-1, 31,0);
    tracep->declBus(c+197,"unsigned_mem_data", false,-1, 31,0);
    tracep->declBus(c+198,"write_data", false,-1, 31,0);
    tracep->declBus(c+199,"len", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("wbu ");
    tracep->declBus(c+15,"ex_alu_data", false,-1, 31,0);
    tracep->declBus(c+17,"mem_data", false,-1, 31,0);
    tracep->declBit(c+18,"load_valid", false,-1);
    tracep->declBus(c+14,"wb_data", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT___pc__DOT__current_pc),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__inst),32);
    bufp->fullCData(oldp+3,(((IData)(vlSelf->top__DOT__idu__DOT__isNeed_rs1)
                              ? (0x1fU & (vlSelf->top__DOT__inst 
                                          >> 0xfU))
                              : 0U)),5);
    bufp->fullCData(oldp+4,((((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
                              | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0))
                              ? (0x1fU & (vlSelf->top__DOT__inst 
                                          >> 0x14U))
                              : 0U)),5);
    bufp->fullCData(oldp+5,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0) 
                              | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))
                              ? (0x1fU & (vlSelf->top__DOT__inst 
                                          >> 7U)) : 0U)),5);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__imm),32);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__alu_op),5);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__mem_op),4);
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__ex_op),4);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__pc_op),4);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__rs1_data),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__rs2_data),32);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__rd_2),5);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__write_data),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__ex_alu_data),32);
    bufp->fullBit(oldp+16,(vlSelf->top__DOT__compare_result));
    bufp->fullIData(oldp+17,(((IData)(vlSelf->top__DOT__mem__DOT__signed_load)
                               ? ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
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
                                       : vlSelf->top__DOT__read_data))
                               : ((IData)(vlSelf->top__DOT__mem__DOT__unsigned_load)
                                   ? ((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                       ? (0xffU & vlSelf->top__DOT__read_data)
                                       : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                           ? (0xffffU 
                                              & vlSelf->top__DOT__read_data)
                                           : vlSelf->top__DOT__read_data))
                                   : 0U))),32);
    bufp->fullBit(oldp+18,(vlSelf->top__DOT__load_valid));
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__read_data),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__rw_addr),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__Regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__Regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__Regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__Regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__Regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__Regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__Regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__Regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__Regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__Regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__Regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__Regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__Regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__Regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__Regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__Regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__Regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__Regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__Regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__Regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__Regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__Regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__Regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__Regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__Regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__Regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__Regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__Regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__Regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__Regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__Regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__Regfile__DOT__rf[31]),32);
    bufp->fullBit(oldp+53,((1U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+54,((2U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+55,((3U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+56,((4U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+57,((7U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+58,((8U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+59,((9U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+60,((5U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+61,((6U == (IData)(vlSelf->top__DOT__ex_op))));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__exu__DOT__rs1_rs2));
    bufp->fullBit(oldp+63,(vlSelf->top__DOT__exu__DOT__rs1_imm));
    bufp->fullBit(oldp+64,(vlSelf->top__DOT__exu__DOT__pc_4));
    bufp->fullIData(oldp+65,((0xfffff000U & vlSelf->top__DOT__imm)),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__exu__DOT__alu_src1),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__exu__DOT__alu_src2),32);
    bufp->fullIData(oldp+68,((((1U == (IData)(vlSelf->top__DOT__alu_op)) 
                               | (2U == (IData)(vlSelf->top__DOT__alu_op)))
                               ? vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_result
                               : ((3U == (IData)(vlSelf->top__DOT__alu_op))
                                   ? (vlSelf->top__DOT__exu__DOT__alu_src1 
                                      ^ vlSelf->top__DOT__exu__DOT__alu_src2)
                                   : ((4U == (IData)(vlSelf->top__DOT__alu_op))
                                       ? (vlSelf->top__DOT__exu__DOT__alu_src1 
                                          | vlSelf->top__DOT__exu__DOT__alu_src2)
                                       : ((5U == (IData)(vlSelf->top__DOT__alu_op))
                                           ? (vlSelf->top__DOT__exu__DOT__alu_src1 
                                              & vlSelf->top__DOT__exu__DOT__alu_src2)
                                           : ((6U == (IData)(vlSelf->top__DOT__alu_op))
                                               ? (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                  << 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__exu__DOT__alu_src2))
                                               : ((7U 
                                                   == (IData)(vlSelf->top__DOT__alu_op))
                                                   ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_ha85d5376__0
                                                   : 
                                                  ((8U 
                                                    == (IData)(vlSelf->top__DOT__alu_op))
                                                    ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_ha85d5376__0
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
                                                                (vlSelf->top__DOT__exu__DOT__ALU__DOT__mulh_64_result 
                                                                 >> 0x20U))
                                                      : 
                                                     ((0x13U 
                                                       == (IData)(vlSelf->top__DOT__alu_op))
                                                       ? (IData)(
                                                                 (vlSelf->top__DOT__exu__DOT__ALU__DOT__mulh_64_result 
                                                                  >> 0x20U))
                                                       : 
                                                      ((0x14U 
                                                        == (IData)(vlSelf->top__DOT__alu_op))
                                                        ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h50ddfa4f__0
                                                        : 
                                                       ((0x15U 
                                                         == (IData)(vlSelf->top__DOT__alu_op))
                                                         ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h50ddfa4f__0
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlSelf->top__DOT__alu_op))
                                                          ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h51fa2515__0
                                                          : 
                                                         ((0x17U 
                                                           == (IData)(vlSelf->top__DOT__alu_op))
                                                           ? vlSelf->top__DOT__exu__DOT__ALU__DOT____VdfgTmp_h51fa2515__0
                                                           : 
                                                          ((IData)(vlSelf->__VdfgTmp_h498b5a69__0)
                                                            ? 
                                                           (vlSelf->top__DOT__exu__DOT__alu_src1 
                                                            + vlSelf->top__DOT__exu__DOT__alu_src2)
                                                            : 0U)))))))))))))))),32);
    bufp->fullBit(oldp+69,((1U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+70,((2U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+71,((3U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+72,((4U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+73,((5U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+74,((6U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+75,((7U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+76,((8U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+77,((9U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+78,((0xaU == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+79,((0xbU == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+80,((0xcU == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+81,((0xdU == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+82,((0xeU == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+83,((0xfU == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+84,((0x10U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+85,((0x11U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+86,((0x12U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+87,((0x13U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+88,((0x14U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+89,((0x15U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+90,((0x16U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+91,((0x17U == (IData)(vlSelf->top__DOT__alu_op))));
    bufp->fullBit(oldp+92,(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout));
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_result),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_b),32);
    bufp->fullQData(oldp+95,(((IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB)
                               ? 1ULL : 0ULL)),33);
    bufp->fullBit(oldp+97,(vlSelf->top__DOT__exu__DOT__ALU__DOT__isSUB));
    bufp->fullBit(oldp+98,(vlSelf->top__DOT__exu__DOT__ALU__DOT__slt_result));
    bufp->fullBit(oldp+99,((1U & (~ (IData)(vlSelf->top__DOT__exu__DOT__ALU__DOT__adder_cout)))));
    bufp->fullQData(oldp+100,(vlSelf->top__DOT__exu__DOT__ALU__DOT__mulh_64_result),64);
    bufp->fullQData(oldp+102,(((QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src1)) 
                               * (QData)((IData)(vlSelf->top__DOT__exu__DOT__alu_src2)))),64);
    bufp->fullIData(oldp+104,((IData)((vlSelf->top__DOT__exu__DOT__ALU__DOT__mulh_64_result 
                                       >> 0x20U))),32);
    bufp->fullCData(oldp+105,((0x7fU & vlSelf->top__DOT__inst)),7);
    bufp->fullCData(oldp+106,((7U & (vlSelf->top__DOT__inst 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+107,((vlSelf->top__DOT__inst 
                               >> 0x19U)),7);
    bufp->fullSData(oldp+108,((vlSelf->top__DOT__inst 
                               >> 0x14U)),12);
    bufp->fullBit(oldp+109,((0x33U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+110,(vlSelf->top__DOT__idu__DOT__I_type));
    bufp->fullBit(oldp+111,((0x23U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+112,((0x63U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+113,(vlSelf->top__DOT__idu__DOT__U_type));
    bufp->fullBit(oldp+114,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+115,((1U & (~ ((IData)(vlSelf->top__DOT__idu__DOT__isNeed_rs1) 
                                      | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))))));
    bufp->fullBit(oldp+116,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+117,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+118,((IData)((0x13U == (0x707fU 
                                               & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+119,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+120,((IData)((0x7013U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+121,((IData)((0x63U == (0x707fU 
                                               & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+122,((IData)((0x1063U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+123,((IData)((0x5063U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+124,((IData)((0x7063U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+125,((IData)((0x4063U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+126,((IData)((0x6063U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+127,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                             & (1U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+128,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                             & (1U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+129,((IData)((0x2003U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+130,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+131,((IData)((0x4003U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+132,((IData)((0x1003U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+133,((IData)((3U == (0x707fU 
                                            & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+134,((IData)((0x5003U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+135,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                             & (1U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+136,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                             & (1U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+137,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                             & (1U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+138,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+139,((IData)((0x6013U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+140,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                             & (1U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+141,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                             & (1U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+142,((IData)((0x2023U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+143,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                             & (0x20U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
    bufp->fullBit(oldp+144,((IData)((0x3013U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+145,((IData)((0x2013U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+146,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+147,((IData)((0x1023U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+148,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                             & (0x10U == (vlSelf->top__DOT__inst 
                                          >> 0x1aU)))));
    bufp->fullBit(oldp+149,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+150,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x1aU)))));
    bufp->fullBit(oldp+151,((IData)((0x1013U == (0xfc00707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+152,((IData)((0x2033U == (0xfe00707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+153,((IData)((0x23U == (0x707fU 
                                               & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+154,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                             & (0x20U == (vlSelf->top__DOT__inst 
                                          >> 0x19U)))));
    bufp->fullBit(oldp+155,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+156,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                             & (0U == (vlSelf->top__DOT__inst 
                                       >> 0x19U)))));
    bufp->fullBit(oldp+157,((IData)((0x4013U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+158,(vlSelf->top__DOT__idu__DOT__Inst_jalr));
    bufp->fullBit(oldp+159,((0x100073U == vlSelf->top__DOT__inst)));
    bufp->fullBit(oldp+160,((3U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+161,((0x13U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullIData(oldp+162,((((- (IData)((vlSelf->top__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->top__DOT__inst 
                                            >> 0x14U))),32);
    bufp->fullIData(oldp+163,((((- (IData)((vlSelf->top__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->top__DOT__inst 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->top__DOT__inst 
                                                  >> 7U))))),32);
    bufp->fullIData(oldp+164,((((- (IData)((vlSelf->top__DOT__inst 
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
    bufp->fullIData(oldp+165,((0xfffff000U & vlSelf->top__DOT__inst)),32);
    bufp->fullIData(oldp+166,((((- (IData)((vlSelf->top__DOT__inst 
                                            >> 0x1fU))) 
                                << 0x14U) | ((0xff000U 
                                              & vlSelf->top__DOT__inst) 
                                             | ((0x800U 
                                                 & (vlSelf->top__DOT__inst 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlSelf->top__DOT__inst 
                                                      >> 0x14U)))))),32);
    bufp->fullBit(oldp+167,(((IData)(vlSelf->top__DOT__idu__DOT__I_type) 
                             | ((0x23U == (0x7fU & vlSelf->top__DOT__inst)) 
                                | ((0x63U == (0x7fU 
                                              & vlSelf->top__DOT__inst)) 
                                   | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))))));
    bufp->fullBit(oldp+168,(vlSelf->top__DOT__idu__DOT__isNeed_rs1));
    bufp->fullBit(oldp+169,(((0x33U == (0x7fU & vlSelf->top__DOT__inst)) 
                             | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_had26422b__0))));
    bufp->fullBit(oldp+170,(((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hdde88109__0) 
                             | (IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hda0a4f99__0))));
    bufp->fullBit(oldp+171,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69f398c__0) 
                              & (0U == (vlSelf->top__DOT__inst 
                                        >> 0x19U))) 
                             | ((IData)((0x13U == (0x707fU 
                                                   & vlSelf->top__DOT__inst))) 
                                | ((3U == (0x7fU & vlSelf->top__DOT__inst)) 
                                   | ((0x23U == (0x7fU 
                                                 & vlSelf->top__DOT__inst)) 
                                      | ((0x6fU == 
                                          (0x7fU & vlSelf->top__DOT__inst)) 
                                         | ((IData)(vlSelf->top__DOT__idu__DOT__Inst_jalr) 
                                            | (IData)(vlSelf->top__DOT__idu__DOT__U_type)))))))));
    bufp->fullBit(oldp+172,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3e51328__0) 
                              & (0U == (vlSelf->top__DOT__inst 
                                        >> 0x19U))) 
                             | (IData)((0x4013U == 
                                        (0x707fU & vlSelf->top__DOT__inst))))));
    bufp->fullBit(oldp+173,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he7d3bfbe__0) 
                              & (0U == (vlSelf->top__DOT__inst 
                                        >> 0x19U))) 
                             | (IData)((0x7013U == 
                                        (0x707fU & vlSelf->top__DOT__inst))))));
    bufp->fullBit(oldp+174,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he979b2f1__0) 
                              & (0U == (vlSelf->top__DOT__inst 
                                        >> 0x19U))) 
                             | (IData)((0x6013U == 
                                        (0x707fU & vlSelf->top__DOT__inst))))));
    bufp->fullBit(oldp+175,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he69b39c7__0) 
                              & (0U == (vlSelf->top__DOT__inst 
                                        >> 0x19U))) 
                             | (IData)((0x1013U == 
                                        (0xfc00707fU 
                                         & vlSelf->top__DOT__inst))))));
    bufp->fullBit(oldp+176,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                              & (0U == (vlSelf->top__DOT__inst 
                                        >> 0x19U))) 
                             | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                & (0U == (vlSelf->top__DOT__inst 
                                          >> 0x1aU))))));
    bufp->fullBit(oldp+177,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_hd3ddd1c8__0) 
                              & (0x20U == (vlSelf->top__DOT__inst 
                                           >> 0x19U))) 
                             | ((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_h873f971e__0) 
                                & (0x10U == (vlSelf->top__DOT__inst 
                                             >> 0x1aU))))));
    bufp->fullBit(oldp+178,(((IData)((0x2033U == (0xfe00707fU 
                                                  & vlSelf->top__DOT__inst))) 
                             | (IData)((0x2013U == 
                                        (0x707fU & vlSelf->top__DOT__inst))))));
    bufp->fullBit(oldp+179,((((IData)(vlSelf->top__DOT__idu__DOT____VdfgTmp_he48ad066__0) 
                              & (0U == (vlSelf->top__DOT__inst 
                                        >> 0x19U))) 
                             | (IData)((0x3013U == 
                                        (0x707fU & vlSelf->top__DOT__inst))))));
    bufp->fullBit(oldp+180,((0U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+181,((1U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+182,((2U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+183,((3U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+184,((4U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+185,((5U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+186,((6U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+187,((7U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+188,((8U == (IData)(vlSelf->top__DOT__mem_op))));
    bufp->fullBit(oldp+189,(((0U != (IData)(vlSelf->top__DOT__mem_op)) 
                             & ((IData)(vlSelf->top__DOT__mem__DOT____VdfgTmp_h3c6dcd3f__0) 
                                | ((3U == (IData)(vlSelf->top__DOT__mem_op)) 
                                   | ((5U == (IData)(vlSelf->top__DOT__mem_op)) 
                                      | (4U == (IData)(vlSelf->top__DOT__mem_op))))))));
    bufp->fullBit(oldp+190,(((0U != (IData)(vlSelf->top__DOT__mem_op)) 
                             & ((6U == (IData)(vlSelf->top__DOT__mem_op)) 
                                | ((7U == (IData)(vlSelf->top__DOT__mem_op)) 
                                   | (8U == (IData)(vlSelf->top__DOT__mem_op)))))));
    bufp->fullBit(oldp+191,(vlSelf->top__DOT__mem__DOT__is1byte));
    bufp->fullBit(oldp+192,(vlSelf->top__DOT__mem__DOT__is2byte));
    bufp->fullBit(oldp+193,(((4U == (IData)(vlSelf->top__DOT__mem_op)) 
                             | (8U == (IData)(vlSelf->top__DOT__mem_op)))));
    bufp->fullBit(oldp+194,(vlSelf->top__DOT__mem__DOT__unsigned_load));
    bufp->fullBit(oldp+195,(vlSelf->top__DOT__mem__DOT__signed_load));
    bufp->fullIData(oldp+196,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
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
                                        << 0x10U) | 
                                       (0xffffU & vlSelf->top__DOT__read_data))
                                    : vlSelf->top__DOT__read_data))),32);
    bufp->fullIData(oldp+197,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                ? (0xffU & vlSelf->top__DOT__read_data)
                                : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                    ? (0xffffU & vlSelf->top__DOT__read_data)
                                    : vlSelf->top__DOT__read_data))),32);
    bufp->fullIData(oldp+198,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                ? (0xffU & vlSelf->top__DOT__rs2_data)
                                : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                    ? (0xffffU & vlSelf->top__DOT__rs2_data)
                                    : vlSelf->top__DOT__rs2_data))),32);
    bufp->fullIData(oldp+199,(((IData)(vlSelf->top__DOT__mem__DOT__is1byte)
                                ? 1U : ((IData)(vlSelf->top__DOT__mem__DOT__is2byte)
                                         ? 2U : 4U))),32);
    bufp->fullBit(oldp+200,(vlSelf->clk));
    bufp->fullBit(oldp+201,(vlSelf->rst));
    bufp->fullIData(oldp+202,(vlSelf->debug_rs1_data),32);
    bufp->fullIData(oldp+203,(vlSelf->debug_rs2_data),32);
    bufp->fullIData(oldp+204,(vlSelf->debug_imm),32);
    bufp->fullIData(oldp+205,(vlSelf->debug_write_idx),32);
    bufp->fullIData(oldp+206,(vlSelf->debug_write_data),32);
    bufp->fullIData(oldp+207,(vlSelf->debug_rw_addr),32);
    bufp->fullBit(oldp+208,(1U));
}
