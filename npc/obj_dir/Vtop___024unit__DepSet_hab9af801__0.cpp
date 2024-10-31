// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024unit.h"

extern "C" void set_gpr_ptr(const svOpenArrayHandle rf_ptr);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(const VlUnpacked<IData/*31:0*/, 32> &rf_ptr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit\n"); );
    // Body
    static const int rf_ptr__Vopenprops__ulims[2] = {31, 0};
    static const VerilatedVarProps rf_ptr__Vopenprops(VLVT_UINT32, VLVD_IN, VerilatedVarProps::Packed(), 31, 0, VerilatedVarProps::Unpacked(), 1, rf_ptr__Vopenprops__ulims);
    VerilatedDpiOpenVar rf_ptr__Vopenarray (&rf_ptr__Vopenprops, &rf_ptr);
    set_gpr_ptr(&rf_ptr__Vopenarray);
}
