// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_DEHAZING__SYMS_H_
#define VERILATED_VTB_DEHAZING__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_dehazing.h"

// INCLUDE MODULE CLASSES
#include "Vtb_dehazing___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_dehazing__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_dehazing* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_dehazing___024root         TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_dehazing;
    VerilatedScope __Vscope_tb_dehazing__fail;

    // CONSTRUCTORS
    Vtb_dehazing__Syms(VerilatedContext* contextp, const char* namep, Vtb_dehazing* modelp);
    ~Vtb_dehazing__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
