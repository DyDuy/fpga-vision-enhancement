// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dehazing.h for the primary calling header

#include "Vtb_dehazing__pch.h"
#include "Vtb_dehazing___024root.h"

VL_ATTR_COLD void Vtb_dehazing___024root___eval_static__TOP(Vtb_dehazing___024root* vlSelf);

VL_ATTR_COLD void Vtb_dehazing___024root___eval_static(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_static\n"); );
    // Body
    Vtb_dehazing___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_dehazing___024root___eval_static__TOP(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_dehazing__DOT__clk = 0U;
    vlSelf->tb_dehazing__DOT__rst_n = 0U;
    vlSelf->tb_dehazing__DOT__sw_bypass = 0U;
    vlSelf->tb_dehazing__DOT__snk_valid = 0U;
    vlSelf->tb_dehazing__DOT__snk_sop = 0U;
    vlSelf->tb_dehazing__DOT__snk_eop = 0U;
    vlSelf->tb_dehazing__DOT__src_ready = 0U;
    vlSelf->tb_dehazing__DOT__snk_data = 0U;
    vlSelf->tb_dehazing__DOT__meta = 0U;
    vlSelf->tb_dehazing__DOT__sync_mode = 0U;
    vlSelf->tb_dehazing__DOT__frame_mode = 0U;
    vlSelf->tb_dehazing__DOT__atmosphere = 0xdcU;
    vlSelf->tb_dehazing__DOT__maximum = 0U;
    vlSelf->tb_dehazing__DOT__checks = 0U;
    vlSelf->tb_dehazing__DOT__accepted = 0U;
    vlSelf->tb_dehazing__DOT__seed = 0U;
    vlSelf->tb_dehazing__DOT__last_reset = 0U;
    vlSelf->tb_dehazing__DOT__av = 0U;
    vlSelf->tb_dehazing__DOT__aso = 0U;
    vlSelf->tb_dehazing__DOT__ae = 1U;
    vlSelf->tb_dehazing__DOT__ar = 0U;
    vlSelf->tb_dehazing__DOT__ap = 0U;
}

VL_ATTR_COLD void Vtb_dehazing___024root___eval_initial__TOP(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i;
    tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i = 0;
    VlWide<7>/*223:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_3;
    VlWide<5>/*159:0*/ __Vtemp_4;
    VlWide<5>/*159:0*/ __Vtemp_5;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x64617461U;
    __Vtemp_1[2U] = 0x6c75745fU;
    __Vtemp_1[3U] = 0x696f6e5fU;
    __Vtemp_1[4U] = 0x6d697373U;
    __Vtemp_1[5U] = 0x72616e73U;
    __Vtemp_1[6U] = 0x74U;
    VL_READMEM_N(true, 10, 65536, 0, VL_CVT_PACK_STR_NW(7, __Vtemp_1)
                 ,  &(vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__transmission_lut)
                 , 0, ~0ULL);
    tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i)) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__rom[(0x3ffU 
                                                                      & tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i)] 
            = (VL_GTS_III(32, 0x64U, tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i)
                ? 0x2800U : (0x3fffU & VL_DIVS_III(32, (IData)(0x100000U), tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i)));
        tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i 
            = ((IData)(1U) + tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__i);
    }
    __Vtemp_3[0U] = 0x2e686578U;
    __Vtemp_3[1U] = 0x64617461U;
    __Vtemp_3[2U] = 0x6c75745fU;
    __Vtemp_3[3U] = 0x6d6d615fU;
    __Vtemp_3[4U] = 0x6761U;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_3)
                 ,  &(vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_r__DOT__rom)
                 , 0, ~0ULL);
    __Vtemp_4[0U] = 0x2e686578U;
    __Vtemp_4[1U] = 0x64617461U;
    __Vtemp_4[2U] = 0x6c75745fU;
    __Vtemp_4[3U] = 0x6d6d615fU;
    __Vtemp_4[4U] = 0x6761U;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_4)
                 ,  &(vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_g__DOT__rom)
                 , 0, ~0ULL);
    __Vtemp_5[0U] = 0x2e686578U;
    __Vtemp_5[1U] = 0x64617461U;
    __Vtemp_5[2U] = 0x6c75745fU;
    __Vtemp_5[3U] = 0x6d6d615fU;
    __Vtemp_5[4U] = 0x6761U;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_5)
                 ,  &(vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_b__DOT__rom)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_dehazing___024root___eval_final(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dehazing___024root___dump_triggers__stl(Vtb_dehazing___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_dehazing___024root___eval_phase__stl(Vtb_dehazing___024root* vlSelf);

VL_ATTR_COLD void Vtb_dehazing___024root___eval_settle(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_dehazing___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_dehazing___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dehazing___024root___dump_triggers__stl(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_dehazing___024root___stl_sequent__TOP__0(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___stl_sequent__TOP__0\n"); );
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
    vlSelf->tb_dehazing__DOT__dut__DOT____Vcellinp__sof_delay__i_data 
        = ((IData)(vlSelf->tb_dehazing__DOT__snk_sop) 
           & (IData)(vlSelf->tb_dehazing__DOT__snk_valid));
}

VL_ATTR_COLD void Vtb_dehazing___024root___eval_stl(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_dehazing___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_dehazing___024root___eval_triggers__stl(Vtb_dehazing___024root* vlSelf);

VL_ATTR_COLD bool Vtb_dehazing___024root___eval_phase__stl(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_dehazing___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_dehazing___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dehazing___024root___dump_triggers__act(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_dehazing.clk or negedge tb_dehazing.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_dehazing.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_dehazing.ar or posedge tb_dehazing.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge tb_dehazing.clk)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dehazing___024root___dump_triggers__nba(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_dehazing.clk or negedge tb_dehazing.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_dehazing.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_dehazing.ar or posedge tb_dehazing.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge tb_dehazing.clk)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_dehazing___024root___ctor_var_reset(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_dehazing__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__sw_bypass = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__snk_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__snk_sop = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__snk_eop = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__src_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__snk_data = VL_RAND_RESET_I(30);
    vlSelf->tb_dehazing__DOT__snk_ready = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__gamma_rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__transmission_rom[__Vi0] = VL_RAND_RESET_I(10);
    }
    for (int __Vi0 = 0; __Vi0 < 11; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__ev[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 11; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__es[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 11; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__ee[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 11; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__ed[__Vi0] = VL_RAND_RESET_I(30);
    }
    vlSelf->tb_dehazing__DOT__meta = 0;
    vlSelf->tb_dehazing__DOT__sync_mode = 0;
    vlSelf->tb_dehazing__DOT__frame_mode = 0;
    vlSelf->tb_dehazing__DOT__atmosphere = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__maximum = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__checks = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__accepted = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__seed = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__last_output = VL_RAND_RESET_Q(33);
    vlSelf->tb_dehazing__DOT__last_reset = 0;
    vlSelf->tb_dehazing__DOT__av = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__aso = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__ae = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__ar = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__ap = VL_RAND_RESET_I(24);
    vlSelf->tb_dehazing__DOT__aa = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__pixel = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__stall = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__value = VL_RAND_RESET_I(30);
    vlSelf->tb_dehazing__DOT__mode_value = 0;
    vlSelf->tb_dehazing__DOT__bubble = 0;
    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 = 0;
    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 = 0;
    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 = 0;
    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 = VL_RAND_RESET_I(30);
    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0;
    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0;
    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0;
    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = VL_RAND_RESET_I(30);
    vlSelf->tb_dehazing__DOT__dut__DOT__mode_meta = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__mode_sync = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__frame_mode = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT____Vcellinp__sof_delay__i_data = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__v1 = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__v3 = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__v5 = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st1 = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st1 = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__cmax_st2 = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__cmin_st2 = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__t_raw = VL_RAND_RESET_I(10);
    vlSelf->tb_dehazing__DOT__dut__DOT__t_ref = VL_RAND_RESET_I(10);
    vlSelf->tb_dehazing__DOT__dut__DOT__auto_Ag = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__p_dehazed = VL_RAND_RESET_I(24);
    vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma = VL_RAND_RESET_I(24);
    for (int __Vi0 = 0; __Vi0 < 11; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages[__Vi0] = VL_RAND_RESET_Q(34);
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0 = VL_RAND_RESET_Q(34);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0 = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__st2__DOT__vd__DOT__d1__DOT__delay_reg = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__transmission_lut[__Vi0] = VL_RAND_RESET_I(10);
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__rom_q = VL_RAND_RESET_I(10);
    vlSelf->tb_dehazing__DOT__dut__DOT__st3__DOT__v_a = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0 = VL_RAND_RESET_I(24);
    vlSelf->tb_dehazing__DOT__dut__DOT__st4__DOT__vd_st4__DOT__d1__DOT__delay_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__st_ag__DOT__p_m = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__inv_t = VL_RAND_RESET_I(14);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_d = VL_RAND_RESET_I(18);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_d = VL_RAND_RESET_I(18);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_d = VL_RAND_RESET_I(18);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st1 = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st1 = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_mult = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_mult = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_mult = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__a_st2 = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st2 = VL_RAND_RESET_I(1);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__r_add = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__g_add = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__b_add = VL_RAND_RESET_I(32);
    vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__v_st3 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__rom[__Vi0] = VL_RAND_RESET_I(14);
    }
    vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_r = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_g = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__g_b = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__v_r1 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_r__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_g__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_dehazing__DOT__dut__DOT__st6__DOT__lut_b__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_dehazing__DOT__probe__DOT__max_r = VL_RAND_RESET_I(8);
    vlSelf->tb_dehazing__DOT__probe__DOT__p_m = VL_RAND_RESET_I(8);
    vlSelf->__Vtask_tb_dehazing__DOT__tick__65__ready_i = 0;
    vlSelf->__Vtask_tb_dehazing__DOT__tick__65__reset_i = 0;
    vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0 = VL_RAND_RESET_I(24);
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0 = 0;
    vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1 = VL_RAND_RESET_I(24);
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1 = 0;
    vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2 = VL_RAND_RESET_I(24);
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2 = 0;
    vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3 = VL_RAND_RESET_I(24);
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3 = 0;
    vlSelf->__Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4 = VL_RAND_RESET_I(24);
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4 = 0;
    vlSelf->__Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v5 = 0;
    vlSelf->__Vdly__tb_dehazing__DOT__dut__DOT__auto_Ag = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__ar__0 = VL_RAND_RESET_I(1);
}
