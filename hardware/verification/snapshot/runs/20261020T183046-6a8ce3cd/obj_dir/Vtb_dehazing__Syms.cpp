// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_dehazing__pch.h"
#include "Vtb_dehazing.h"
#include "Vtb_dehazing___024root.h"

// FUNCTIONS
Vtb_dehazing__Syms::~Vtb_dehazing__Syms()
{
}

Vtb_dehazing__Syms::Vtb_dehazing__Syms(VerilatedContext* contextp, const char* namep, Vtb_dehazing* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_dehazing.configure(this, name(), "tb_dehazing", "tb_dehazing", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_dehazing__fail.configure(this, name(), "tb_dehazing.fail", "fail", -9, VerilatedScope::SCOPE_OTHER);
}
