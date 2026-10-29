// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dehazing.h for the primary calling header

#include "Vtb_dehazing__pch.h"
#include "Vtb_dehazing__Syms.h"
#include "Vtb_dehazing___024root.h"

void Vtb_dehazing___024root___ctor_var_reset(Vtb_dehazing___024root* vlSelf);

Vtb_dehazing___024root::Vtb_dehazing___024root(Vtb_dehazing__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_dehazing___024root___ctor_var_reset(this);
}

void Vtb_dehazing___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_dehazing___024root::~Vtb_dehazing___024root() {
}
