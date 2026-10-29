// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_dehazing__pch.h"

//============================================================
// Constructors

Vtb_dehazing::Vtb_dehazing(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_dehazing__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_dehazing::Vtb_dehazing(const char* _vcname__)
    : Vtb_dehazing(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_dehazing::~Vtb_dehazing() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_dehazing___024root___eval_debug_assertions(Vtb_dehazing___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_dehazing___024root___eval_static(Vtb_dehazing___024root* vlSelf);
void Vtb_dehazing___024root___eval_initial(Vtb_dehazing___024root* vlSelf);
void Vtb_dehazing___024root___eval_settle(Vtb_dehazing___024root* vlSelf);
void Vtb_dehazing___024root___eval(Vtb_dehazing___024root* vlSelf);

void Vtb_dehazing::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_dehazing::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_dehazing___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_dehazing___024root___eval_static(&(vlSymsp->TOP));
        Vtb_dehazing___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_dehazing___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_dehazing___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_dehazing::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_dehazing::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_dehazing::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_dehazing___024root___eval_final(Vtb_dehazing___024root* vlSelf);

VL_ATTR_COLD void Vtb_dehazing::final() {
    Vtb_dehazing___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_dehazing::hierName() const { return vlSymsp->name(); }
const char* Vtb_dehazing::modelName() const { return "Vtb_dehazing"; }
unsigned Vtb_dehazing::threads() const { return 1; }
void Vtb_dehazing::prepareClone() const { contextp()->prepareClone(); }
void Vtb_dehazing::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_dehazing::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_dehazing::trace()' called on model that was Verilated without --trace option");
}
