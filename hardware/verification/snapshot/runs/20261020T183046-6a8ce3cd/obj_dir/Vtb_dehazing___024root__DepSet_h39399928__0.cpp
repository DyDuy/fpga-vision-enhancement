// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dehazing.h for the primary calling header

#include "Vtb_dehazing__pch.h"
#include "Vtb_dehazing___024root.h"

VL_ATTR_COLD void Vtb_dehazing___024root___eval_initial__TOP(Vtb_dehazing___024root* vlSelf);
VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0(Vtb_dehazing___024root* vlSelf);
VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__1(Vtb_dehazing___024root* vlSelf);

void Vtb_dehazing___024root___eval_initial(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_initial\n"); );
    // Body
    Vtb_dehazing___024root___eval_initial__TOP(vlSelf);
    Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_dehazing___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0 
        = vlSelf->tb_dehazing__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__rst_n__0 
        = vlSelf->tb_dehazing__DOT__rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__ar__0 
        = vlSelf->tb_dehazing__DOT__ar;
}

VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__0(Vtb_dehazing___024root* vlSelf);
VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__1(Vtb_dehazing___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    co_await Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__0(vlSelf);
    co_await Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__1(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                           4);
        vlSelf->tb_dehazing__DOT__clk = (1U & (~ (IData)(vlSelf->tb_dehazing__DOT__clk)));
    }
}

VL_INLINE_OPT void Vtb_dehazing___024root___act_comb__TOP__0(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_dehazing__DOT__snk_ready = vlSelf->tb_dehazing__DOT__src_ready;
    vlSelf->tb_dehazing__DOT__probe__DOT__p_m = (0xffU 
                                                 & (((0xffU 
                                                      & (vlSelf->tb_dehazing__DOT__ap 
                                                         >> 0x10U)) 
                                                     > 
                                                     (0xffU 
                                                      & (vlSelf->tb_dehazing__DOT__ap 
                                                         >> 8U)))
                                                     ? 
                                                    (((0xffU 
                                                       & (vlSelf->tb_dehazing__DOT__ap 
                                                          >> 0x10U)) 
                                                      > 
                                                      (0xffU 
                                                       & vlSelf->tb_dehazing__DOT__ap))
                                                      ? 
                                                     (vlSelf->tb_dehazing__DOT__ap 
                                                      >> 0x10U)
                                                      : vlSelf->tb_dehazing__DOT__ap)
                                                     : 
                                                    (((0xffU 
                                                       & (vlSelf->tb_dehazing__DOT__ap 
                                                          >> 8U)) 
                                                      > 
                                                      (0xffU 
                                                       & vlSelf->tb_dehazing__DOT__ap))
                                                      ? 
                                                     (vlSelf->tb_dehazing__DOT__ap 
                                                      >> 8U)
                                                      : vlSelf->tb_dehazing__DOT__ap)));
    vlSelf->tb_dehazing__DOT__dut__DOT____Vcellinp__sof_delay__i_data 
        = ((IData)(vlSelf->tb_dehazing__DOT__snk_sop) 
           & (IData)(vlSelf->tb_dehazing__DOT__snk_valid));
}

void Vtb_dehazing___024root___eval_act(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_act\n"); );
    // Body
    if ((0x1aULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_dehazing___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_dehazing___024root___nba_sequent__TOP__0(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__tb_dehazing__DOT__probe__DOT__max_r;
    __Vdly__tb_dehazing__DOT__probe__DOT__max_r = 0;
    // Body
    __Vdly__tb_dehazing__DOT__probe__DOT__max_r = vlSelf->tb_dehazing__DOT__probe__DOT__max_r;
    if (vlSelf->tb_dehazing__DOT__ar) {
        if (vlSelf->tb_dehazing__DOT__ae) {
            if (((IData)(vlSelf->tb_dehazing__DOT__av) 
                 & (IData)(vlSelf->tb_dehazing__DOT__aso))) {
                if ((0x32U < (IData)(vlSelf->tb_dehazing__DOT__probe__DOT__max_r))) {
                    vlSelf->tb_dehazing__DOT__aa = 
                        (0xffU & ((((IData)(0xfU) * (IData)(vlSelf->tb_dehazing__DOT__aa)) 
                                   + (IData)(vlSelf->tb_dehazing__DOT__probe__DOT__max_r)) 
                                  >> 4U));
                }
                __Vdly__tb_dehazing__DOT__probe__DOT__max_r = 0U;
            } else if (vlSelf->tb_dehazing__DOT__av) {
                if (((IData)(vlSelf->tb_dehazing__DOT__probe__DOT__p_m) 
                     > (IData)(vlSelf->tb_dehazing__DOT__probe__DOT__max_r))) {
                    __Vdly__tb_dehazing__DOT__probe__DOT__max_r 
                        = vlSelf->tb_dehazing__DOT__probe__DOT__p_m;
                }
            }
        }
    } else {
        vlSelf->tb_dehazing__DOT__aa = 0xdcU;
        __Vdly__tb_dehazing__DOT__probe__DOT__max_r = 0U;
    }
    vlSelf->tb_dehazing__DOT__probe__DOT__max_r = __Vdly__tb_dehazing__DOT__probe__DOT__max_r;
}

VL_INLINE_OPT void Vtb_dehazing___024root___nba_sequent__TOP__1(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___nba_sequent__TOP__1\n"); );
    // Init
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9 = 0;
    QData/*33:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v11;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v11 = 0;
    CData/*0:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1 = 0;
    CData/*0:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2 = 0;
    CData/*0:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3 = 0;
    CData/*0:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4;
    __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v5;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v5 = 0;
    CData/*7:0*/ __Vdly__tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r;
    __Vdly__tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r = 0;
    // Body
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v5 = 0U;
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0 = 0U;
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1 = 0U;
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2 = 0U;
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3 = 0U;
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4 = 0U;
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v5 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10 = 0U;
    __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v11 = 0U;
    __Vdly__tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r 
        = vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r;
    vlSelf->__Vdly__tb_dehazing__DOT__dut__DOT__auto_Ag 
        = vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag;
    if (vlSelf->tb_dehazing__DOT__rst_n) {
        if (vlSelf->tb_dehazing__DOT__src_ready) {
            if (vlSelf->tb_dehazing__DOT__snk_valid) {
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT____Vcellinp__sof_delay__i_data;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [0U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [1U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [2U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [3U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4 = 1U;
                vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0 
                    = ((0xff0000U & (vlSelf->tb_dehazing__DOT__snk_data 
                                     >> 6U)) | ((0xff00U 
                                                 & (vlSelf->tb_dehazing__DOT__snk_data 
                                                    >> 4U)) 
                                                | (0xffU 
                                                   & (vlSelf->tb_dehazing__DOT__snk_data 
                                                      >> 2U))));
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0 
                    = (((QData)((IData)(((IData)(vlSelf->tb_dehazing__DOT__dut__DOT____Vcellinp__sof_delay__i_data)
                                          ? (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__mode_sync)
                                          : (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__frame_mode)))) 
                        << 0x21U) | (((QData)((IData)(vlSelf->tb_dehazing__DOT__dut__DOT____Vcellinp__sof_delay__i_data)) 
                                      << 0x20U) | (QData)((IData)(
                                                                  ((((IData)(vlSelf->tb_dehazing__DOT__snk_eop) 
                                                                     & (IData)(vlSelf->tb_dehazing__DOT__snk_valid)) 
                                                                    << 0x1fU) 
                                                                   | (((IData)(vlSelf->tb_dehazing__DOT__snk_valid) 
                                                                       << 0x1eU) 
                                                                      | vlSelf->tb_dehazing__DOT__snk_data))))));
            } else {
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0 = 0U;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [0U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [1U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [2U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                    [3U];
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4 
                    = vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
                __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4 = 1U;
                vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0 = 0U;
                __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0 = 0ULL;
            }
            vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                [0U];
            vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0;
            vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                [1U];
            vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0;
            vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                [2U];
            vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0;
            vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                [3U];
            vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4 
                = vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0;
            vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4 = 1U;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [0U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [1U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [2U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [3U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [4U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [5U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [6U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [7U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [8U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9 = 1U;
            vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                [9U];
            __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10 
                = vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
            __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10 = 1U;
            if (((IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st4__DOT__vd_st4__DOT__d1__DOT__delay_reg) 
                 & vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages
                 [4U])) {
                if ((0x32U < (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r))) {
                    vlSelf->__Vdly__tb_dehazing__DOT__dut__DOT__auto_Ag 
                        = (0xffU & ((((IData)(0xfU) 
                                      * (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag)) 
                                     + (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r)) 
                                    >> 4U));
                }
                __Vdly__tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r = 0U;
            } else if (vlSelf->tb_dehazing__DOT__dut__DOT__st4__DOT__vd_st4__DOT__d1__DOT__delay_reg) {
                if (((0xdcU > (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__t_ref)) 
                     & ((IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__p_m) 
                        > (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r)))) {
                    __Vdly__tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r 
                        = vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__p_m;
                }
            }
            if (vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__v_r1) {
                vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                    = (((IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_r) 
                        << 0x10U) | (((IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_g) 
                                      << 8U) | (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_b)));
            }
            vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__v_r1 
                = vlSelf->tb_dehazing__DOT__dut__DOT__v5;
        }
        if ((((IData)(vlSelf->tb_dehazing__DOT__src_ready) 
              & (IData)(vlSelf->tb_dehazing__DOT__snk_valid)) 
             & (IData)(vlSelf->tb_dehazing__DOT__snk_sop))) {
            vlSelf->tb_dehazing__DOT__dut__DOT__frame_mode 
                = vlSelf->tb_dehazing__DOT__dut__DOT__mode_sync;
        }
    } else {
        __Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v5 = 1U;
        vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v5 = 1U;
        __Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v11 = 1U;
        vlSelf->__Vdly__tb_dehazing__DOT__dut__DOT__auto_Ag = 0xdcU;
        __Vdly__tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__frame_mode = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__v_r1 = 0U;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[0U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v0;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[1U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v1;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[2U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v2;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[3U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v3;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[4U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v4;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[5U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v5;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[6U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v6;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[7U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v7;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[8U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v8;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[9U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v9;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[0xaU] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v10;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages__v11) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[0U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[1U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[2U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[3U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[4U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[5U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[6U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[7U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[8U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[9U] = 0ULL;
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[0xaU] = 0ULL;
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r 
        = __Vdly__tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r;
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[0U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v0;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1) {
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[1U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v1;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2) {
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[2U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v2;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3) {
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[3U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v3;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4) {
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[4U] 
            = __Vdlyvval__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v4;
    }
    if (__Vdlyvset__tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages__v5) {
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[0U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[1U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[2U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[3U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[4U] = 0U;
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__mode_sync = 
        ((IData)(vlSelf->tb_dehazing__DOT__rst_n) && (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__mode_meta));
    vlSelf->tb_dehazing__DOT__dut__DOT__mode_meta = 
        ((IData)(vlSelf->tb_dehazing__DOT__rst_n) && (IData)(vlSelf->tb_dehazing__DOT__sw_bypass));
}

VL_INLINE_OPT void Vtb_dehazing___024root___nba_sequent__TOP__2(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->tb_dehazing__DOT__src_ready) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_r 
            = vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_r__DOT__rom
            [(0xffU & (vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed 
                       >> 0x10U))];
        vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_g 
            = vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_g__DOT__rom
            [(0xffU & (vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed 
                       >> 8U))];
        vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_b 
            = vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_b__DOT__rom
            [(0xffU & vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed)];
    }
    if (vlSelf->tb_dehazing__DOT__rst_n) {
        if (vlSelf->tb_dehazing__DOT__src_ready) {
            if (vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st3) {
                vlSelf->tb_dehazing__DOT__dut__DOT__v5 = 1U;
                vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed 
                    = ((0xffffU & vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed) 
                       | ((VL_LTS_III(32, 0xffU, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_add)
                            ? 0xffU : (VL_GTS_III(32, 0U, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_add)
                                        ? 0U : (0xffU 
                                                & vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_add))) 
                          << 0x10U));
                vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed 
                    = ((0xff00ffU & vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed) 
                       | ((VL_LTS_III(32, 0xffU, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_add)
                            ? 0xffU : (VL_GTS_III(32, 0U, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_add)
                                        ? 0U : (0xffU 
                                                & vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_add))) 
                          << 8U));
                vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed 
                    = ((0xffff00U & vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed) 
                       | (VL_LTS_III(32, 0xffU, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_add)
                           ? 0xffU : (VL_GTS_III(32, 0U, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_add)
                                       ? 0U : (0xffU 
                                               & vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_add))));
            } else {
                vlSelf->tb_dehazing__DOT__dut__DOT__v5 = 0U;
            }
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st3 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st2;
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_add 
                = (VL_SHIFTRS_III(32,32,32, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_mult, 0xaU) 
                   + VL_EXTENDS_II(32,9, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st2)));
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_add 
                = (VL_SHIFTRS_III(32,32,32, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_mult, 0xaU) 
                   + VL_EXTENDS_II(32,9, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st2)));
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_add 
                = (VL_SHIFTRS_III(32,32,32, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_mult, 0xaU) 
                   + VL_EXTENDS_II(32,9, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st2)));
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st2 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st1;
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_mult 
                = VL_MULS_III(32, VL_EXTENDS_II(32,18, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_d), 
                              VL_EXTENDS_II(32,15, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__inv_t)));
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_mult 
                = VL_MULS_III(32, VL_EXTENDS_II(32,18, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_d), 
                              VL_EXTENDS_II(32,15, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__inv_t)));
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st2 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st1;
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_mult 
                = VL_MULS_III(32, VL_EXTENDS_II(32,18, vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_d), 
                              VL_EXTENDS_II(32,15, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__inv_t)));
        }
    } else {
        vlSelf->tb_dehazing__DOT__dut__DOT__v5 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st3 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_add = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_add = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_add = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st2 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_mult = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_mult = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st2 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_mult = 0U;
    }
    if (vlSelf->tb_dehazing__DOT__src_ready) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__inv_t 
            = vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__rom
            [vlSelf->tb_dehazing__DOT__dut__DOT__t_ref];
    }
    if (vlSelf->tb_dehazing__DOT__rst_n) {
        if (vlSelf->tb_dehazing__DOT__src_ready) {
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st1 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st4__DOT__vd_st4__DOT__d1__DOT__delay_reg;
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_d 
                = (0x3ffffU & (VL_EXTENDS_II(18,9, 
                                             (0xffU 
                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                                 [4U] 
                                                 >> 0x10U))) 
                               - VL_EXTENDS_II(18,9, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag))));
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_d 
                = (0x3ffffU & (VL_EXTENDS_II(18,9, 
                                             (0xffU 
                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                                 [4U] 
                                                 >> 8U))) 
                               - VL_EXTENDS_II(18,9, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag))));
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st1 
                = vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag;
            vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_d 
                = (0x3ffffU & (VL_EXTENDS_II(18,9, 
                                             (0xffU 
                                              & vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                              [4U])) 
                               - VL_EXTENDS_II(18,9, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag))));
            vlSelf->tb_dehazing__DOT__dut__DOT__t_ref 
                = ((0x66U > (0x3ffU & (VL_SHIFTL_III(32,32,32, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__t_raw), 8U) 
                                       >> 8U))) ? 0x66U
                    : (0x3ffU & (VL_SHIFTL_III(32,32,32, (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__t_raw), 8U) 
                                 >> 8U)));
        }
    } else {
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st1 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_d = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_d = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st1 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_d = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__t_ref = 0U;
    }
}

VL_INLINE_OPT void Vtb_dehazing___024root___nba_sequent__TOP__3(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag = vlSelf->__Vdly__tb_dehazing__DOT__dut__DOT__auto_Ag;
    if (vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[0U] 
            = vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0;
    }
    if (vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1) {
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[1U] 
            = vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1;
    }
    if (vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2) {
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[2U] 
            = vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2;
    }
    if (vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3) {
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[3U] 
            = vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3;
    }
    if (vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4) {
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[4U] 
            = vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4;
    }
    if (vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v5) {
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[0U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[1U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[2U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[3U] = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[4U] = 0U;
    }
    if (vlSelf->tb_dehazing__DOT__rst_n) {
        if (vlSelf->tb_dehazing__DOT__src_ready) {
            vlSelf->tb_dehazing__DOT__dut__DOT__st4__DOT__vd_st4__DOT__d1__DOT__delay_reg 
                = vlSelf->tb_dehazing__DOT__dut__DOT__v3;
            vlSelf->tb_dehazing__DOT__dut__DOT__t_raw 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__rom_q;
            vlSelf->tb_dehazing__DOT__dut__DOT__v3 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__v_a;
            vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__rom_q 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__transmission_lut
                [(((IData)(vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st2) 
                   << 8U) | (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st2))];
            vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__v_a 
                = vlSelf->tb_dehazing__DOT__dut__DOT__st2__DOT__vd__DOT__d1__DOT__delay_reg;
            vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st2 
                = vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st1;
            vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st2 
                = vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st1;
            vlSelf->tb_dehazing__DOT__dut__DOT__st2__DOT__vd__DOT__d1__DOT__delay_reg 
                = vlSelf->tb_dehazing__DOT__dut__DOT__v1;
            vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st1 
                = (0xffU & (((0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                       >> 0x16U)) > 
                             (0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                       >> 0xcU))) ? 
                            (((0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                        >> 0x16U)) 
                              > (0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                          >> 2U))) ? 
                             (vlSelf->tb_dehazing__DOT__snk_data 
                              >> 0x16U) : (vlSelf->tb_dehazing__DOT__snk_data 
                                           >> 2U)) : 
                            (((0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                        >> 0xcU)) > 
                              (0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                        >> 2U))) ? 
                             (vlSelf->tb_dehazing__DOT__snk_data 
                              >> 0xcU) : (vlSelf->tb_dehazing__DOT__snk_data 
                                          >> 2U))));
            vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st1 
                = (0xffU & (((0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                       >> 0x16U)) < 
                             (0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                       >> 0xcU))) ? 
                            (((0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                        >> 0x16U)) 
                              < (0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                          >> 2U))) ? 
                             (vlSelf->tb_dehazing__DOT__snk_data 
                              >> 0x16U) : (vlSelf->tb_dehazing__DOT__snk_data 
                                           >> 2U)) : 
                            (((0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                        >> 0xcU)) < 
                              (0xffU & (vlSelf->tb_dehazing__DOT__snk_data 
                                        >> 2U))) ? 
                             (vlSelf->tb_dehazing__DOT__snk_data 
                              >> 0xcU) : (vlSelf->tb_dehazing__DOT__snk_data 
                                          >> 2U))));
            vlSelf->tb_dehazing__DOT__dut__DOT__v1 
                = vlSelf->tb_dehazing__DOT__snk_valid;
        }
    } else {
        vlSelf->tb_dehazing__DOT__dut__DOT__st4__DOT__vd_st4__DOT__d1__DOT__delay_reg = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__t_raw = 0x3ffU;
        vlSelf->tb_dehazing__DOT__dut__DOT__v3 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__rom_q = 0x3ffU;
        vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__v_a = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st2 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st2 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__st2__DOT__vd__DOT__d1__DOT__delay_reg = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st1 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st1 = 0U;
        vlSelf->tb_dehazing__DOT__dut__DOT__v1 = 0U;
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__p_m 
        = (0xffU & (((0xffU & (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                               [4U] >> 0x10U)) > (0xffU 
                                                  & (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                                     [4U] 
                                                     >> 8U)))
                     ? (((0xffU & (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                   [4U] >> 0x10U)) 
                         > (0xffU & vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                            [4U])) ? (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                      [4U] >> 0x10U)
                         : vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                        [4U]) : (((0xffU & (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                            [4U] >> 8U)) 
                                  > (0xffU & vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                     [4U])) ? (vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                               [4U] 
                                               >> 8U)
                                  : vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages
                                 [4U])));
}

void Vtb_dehazing___024root___eval_nba(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_nba\n"); );
    // Body
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_dehazing___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_dehazing___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x1aULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_dehazing___024root___act_comb__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_dehazing___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_dehazing___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void Vtb_dehazing___024root___timing_resume(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___timing_resume\n"); );
    // Body
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hff7db3c9__0.resume("@(negedge tb_dehazing.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hff7db318__0.resume("@(posedge tb_dehazing.clk)");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_dehazing___024root___timing_commit(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___timing_commit\n"); );
    // Body
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hff7db3c9__0.commit("@(negedge tb_dehazing.clk)");
    }
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hff7db318__0.commit("@(posedge tb_dehazing.clk)");
    }
}

void Vtb_dehazing___024root___eval_triggers__act(Vtb_dehazing___024root* vlSelf);

bool Vtb_dehazing___024root___eval_phase__act(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<5> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_dehazing___024root___eval_triggers__act(vlSelf);
    Vtb_dehazing___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_dehazing___024root___timing_resume(vlSelf);
        Vtb_dehazing___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_dehazing___024root___eval_phase__nba(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_dehazing___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dehazing___024root___dump_triggers__nba(Vtb_dehazing___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dehazing___024root___dump_triggers__act(Vtb_dehazing___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_dehazing___024root___eval(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_dehazing___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_dehazing___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_dehazing___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_dehazing___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_dehazing___024root___eval_debug_assertions(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
