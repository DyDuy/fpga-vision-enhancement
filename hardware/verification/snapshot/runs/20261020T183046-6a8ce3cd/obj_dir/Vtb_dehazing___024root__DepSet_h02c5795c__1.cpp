// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dehazing.h for the primary calling header

#include "Vtb_dehazing__pch.h"
#include "Vtb_dehazing__Syms.h"
#include "Vtb_dehazing___024root.h"

VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__1(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__1\n"); );
    // Init
    IData/*31:0*/ tb_dehazing__DOT__i;
    tb_dehazing__DOT__i = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__71__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__72__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__73__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__74__ready_i;
    __Vtask_tb_dehazing__DOT__tick__74__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__74__valid_i;
    __Vtask_tb_dehazing__DOT__tick__74__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__74__sop_i;
    __Vtask_tb_dehazing__DOT__tick__74__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__74__eop_i;
    __Vtask_tb_dehazing__DOT__tick__74__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__74__mode_i;
    __Vtask_tb_dehazing__DOT__tick__74__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__74__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__74__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__74__reset_i;
    __Vtask_tb_dehazing__DOT__tick__74__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__r;
    __Vtask_tb_dehazing__DOT__tick__74__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__g;
    __Vtask_tb_dehazing__DOT__tick__74__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__b;
    __Vtask_tb_dehazing__DOT__tick__74__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__hi;
    __Vtask_tb_dehazing__DOT__tick__74__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__lo;
    __Vtask_tb_dehazing__DOT__tick__74__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__t;
    __Vtask_tb_dehazing__DOT__tick__74__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__inv;
    __Vtask_tb_dehazing__DOT__tick__74__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__a_used;
    __Vtask_tb_dehazing__DOT__tick__74__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__jr;
    __Vtask_tb_dehazing__DOT__tick__74__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__jg;
    __Vtask_tb_dehazing__DOT__tick__74__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__74__jb;
    __Vtask_tb_dehazing__DOT__tick__74__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__74__gr;
    __Vtask_tb_dehazing__DOT__tick__74__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__74__gg;
    __Vtask_tb_dehazing__DOT__tick__74__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__74__gb;
    __Vtask_tb_dehazing__DOT__tick__74__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__74__processed;
    __Vtask_tb_dehazing__DOT__tick__74__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__74__selected;
    __Vtask_tb_dehazing__DOT__tick__74__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__75__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__75__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__75__value;
    __Vfunc_tb_dehazing__DOT__clamp__75__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__76__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__76__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__76__value;
    __Vfunc_tb_dehazing__DOT__clamp__76__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__77__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__77__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__77__value;
    __Vfunc_tb_dehazing__DOT__clamp__77__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__78__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__79__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__80__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__81__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__82__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__83__ready_i;
    __Vtask_tb_dehazing__DOT__tick__83__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__83__valid_i;
    __Vtask_tb_dehazing__DOT__tick__83__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__83__sop_i;
    __Vtask_tb_dehazing__DOT__tick__83__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__83__eop_i;
    __Vtask_tb_dehazing__DOT__tick__83__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__83__mode_i;
    __Vtask_tb_dehazing__DOT__tick__83__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__83__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__83__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__83__reset_i;
    __Vtask_tb_dehazing__DOT__tick__83__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__r;
    __Vtask_tb_dehazing__DOT__tick__83__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__g;
    __Vtask_tb_dehazing__DOT__tick__83__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__b;
    __Vtask_tb_dehazing__DOT__tick__83__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__hi;
    __Vtask_tb_dehazing__DOT__tick__83__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__lo;
    __Vtask_tb_dehazing__DOT__tick__83__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__t;
    __Vtask_tb_dehazing__DOT__tick__83__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__inv;
    __Vtask_tb_dehazing__DOT__tick__83__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__a_used;
    __Vtask_tb_dehazing__DOT__tick__83__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__jr;
    __Vtask_tb_dehazing__DOT__tick__83__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__jg;
    __Vtask_tb_dehazing__DOT__tick__83__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__83__jb;
    __Vtask_tb_dehazing__DOT__tick__83__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__83__gr;
    __Vtask_tb_dehazing__DOT__tick__83__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__83__gg;
    __Vtask_tb_dehazing__DOT__tick__83__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__83__gb;
    __Vtask_tb_dehazing__DOT__tick__83__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__83__processed;
    __Vtask_tb_dehazing__DOT__tick__83__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__83__selected;
    __Vtask_tb_dehazing__DOT__tick__83__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__84__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__84__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__84__value;
    __Vfunc_tb_dehazing__DOT__clamp__84__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__85__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__85__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__85__value;
    __Vfunc_tb_dehazing__DOT__clamp__85__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__86__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__86__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__86__value;
    __Vfunc_tb_dehazing__DOT__clamp__86__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__87__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__88__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__89__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__90__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__91__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__92__ready_i;
    __Vtask_tb_dehazing__DOT__tick__92__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__92__valid_i;
    __Vtask_tb_dehazing__DOT__tick__92__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__92__sop_i;
    __Vtask_tb_dehazing__DOT__tick__92__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__92__eop_i;
    __Vtask_tb_dehazing__DOT__tick__92__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__92__mode_i;
    __Vtask_tb_dehazing__DOT__tick__92__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__92__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__92__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__92__reset_i;
    __Vtask_tb_dehazing__DOT__tick__92__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__r;
    __Vtask_tb_dehazing__DOT__tick__92__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__g;
    __Vtask_tb_dehazing__DOT__tick__92__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__b;
    __Vtask_tb_dehazing__DOT__tick__92__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__hi;
    __Vtask_tb_dehazing__DOT__tick__92__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__lo;
    __Vtask_tb_dehazing__DOT__tick__92__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__t;
    __Vtask_tb_dehazing__DOT__tick__92__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__inv;
    __Vtask_tb_dehazing__DOT__tick__92__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__a_used;
    __Vtask_tb_dehazing__DOT__tick__92__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__jr;
    __Vtask_tb_dehazing__DOT__tick__92__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__jg;
    __Vtask_tb_dehazing__DOT__tick__92__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__92__jb;
    __Vtask_tb_dehazing__DOT__tick__92__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__92__gr;
    __Vtask_tb_dehazing__DOT__tick__92__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__92__gg;
    __Vtask_tb_dehazing__DOT__tick__92__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__92__gb;
    __Vtask_tb_dehazing__DOT__tick__92__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__92__processed;
    __Vtask_tb_dehazing__DOT__tick__92__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__92__selected;
    __Vtask_tb_dehazing__DOT__tick__92__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__93__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__93__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__93__value;
    __Vfunc_tb_dehazing__DOT__clamp__93__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__94__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__94__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__94__value;
    __Vfunc_tb_dehazing__DOT__clamp__94__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__95__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__95__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__95__value;
    __Vfunc_tb_dehazing__DOT__clamp__95__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__96__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__97__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__98__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__99__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__100__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__101__ready_i;
    __Vtask_tb_dehazing__DOT__tick__101__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__101__valid_i;
    __Vtask_tb_dehazing__DOT__tick__101__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__101__sop_i;
    __Vtask_tb_dehazing__DOT__tick__101__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__101__eop_i;
    __Vtask_tb_dehazing__DOT__tick__101__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__101__mode_i;
    __Vtask_tb_dehazing__DOT__tick__101__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__101__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__101__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__101__reset_i;
    __Vtask_tb_dehazing__DOT__tick__101__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__r;
    __Vtask_tb_dehazing__DOT__tick__101__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__g;
    __Vtask_tb_dehazing__DOT__tick__101__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__b;
    __Vtask_tb_dehazing__DOT__tick__101__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__hi;
    __Vtask_tb_dehazing__DOT__tick__101__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__lo;
    __Vtask_tb_dehazing__DOT__tick__101__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__t;
    __Vtask_tb_dehazing__DOT__tick__101__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__inv;
    __Vtask_tb_dehazing__DOT__tick__101__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__a_used;
    __Vtask_tb_dehazing__DOT__tick__101__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__jr;
    __Vtask_tb_dehazing__DOT__tick__101__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__jg;
    __Vtask_tb_dehazing__DOT__tick__101__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__101__jb;
    __Vtask_tb_dehazing__DOT__tick__101__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__101__gr;
    __Vtask_tb_dehazing__DOT__tick__101__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__101__gg;
    __Vtask_tb_dehazing__DOT__tick__101__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__101__gb;
    __Vtask_tb_dehazing__DOT__tick__101__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__101__processed;
    __Vtask_tb_dehazing__DOT__tick__101__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__101__selected;
    __Vtask_tb_dehazing__DOT__tick__101__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__102__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__102__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__102__value;
    __Vfunc_tb_dehazing__DOT__clamp__102__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__103__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__103__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__103__value;
    __Vfunc_tb_dehazing__DOT__clamp__103__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__104__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__104__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__104__value;
    __Vfunc_tb_dehazing__DOT__clamp__104__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__105__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__106__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__107__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__108__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__109__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__110__ready_i;
    __Vtask_tb_dehazing__DOT__tick__110__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__110__valid_i;
    __Vtask_tb_dehazing__DOT__tick__110__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__110__sop_i;
    __Vtask_tb_dehazing__DOT__tick__110__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__110__eop_i;
    __Vtask_tb_dehazing__DOT__tick__110__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__110__mode_i;
    __Vtask_tb_dehazing__DOT__tick__110__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__110__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__110__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__110__reset_i;
    __Vtask_tb_dehazing__DOT__tick__110__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__r;
    __Vtask_tb_dehazing__DOT__tick__110__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__g;
    __Vtask_tb_dehazing__DOT__tick__110__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__b;
    __Vtask_tb_dehazing__DOT__tick__110__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__hi;
    __Vtask_tb_dehazing__DOT__tick__110__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__lo;
    __Vtask_tb_dehazing__DOT__tick__110__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__t;
    __Vtask_tb_dehazing__DOT__tick__110__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__inv;
    __Vtask_tb_dehazing__DOT__tick__110__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__a_used;
    __Vtask_tb_dehazing__DOT__tick__110__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__jr;
    __Vtask_tb_dehazing__DOT__tick__110__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__jg;
    __Vtask_tb_dehazing__DOT__tick__110__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__110__jb;
    __Vtask_tb_dehazing__DOT__tick__110__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__110__gr;
    __Vtask_tb_dehazing__DOT__tick__110__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__110__gg;
    __Vtask_tb_dehazing__DOT__tick__110__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__110__gb;
    __Vtask_tb_dehazing__DOT__tick__110__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__110__processed;
    __Vtask_tb_dehazing__DOT__tick__110__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__110__selected;
    __Vtask_tb_dehazing__DOT__tick__110__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__111__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__111__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__111__value;
    __Vfunc_tb_dehazing__DOT__clamp__111__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__112__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__112__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__112__value;
    __Vfunc_tb_dehazing__DOT__clamp__112__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__113__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__113__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__113__value;
    __Vfunc_tb_dehazing__DOT__clamp__113__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__114__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__115__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__116__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__117__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__118__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__119__valid_i;
    __Vtask_tb_dehazing__DOT__estimator_case__119__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__119__sof_i;
    __Vtask_tb_dehazing__DOT__estimator_case__119__sof_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__119__en_i;
    __Vtask_tb_dehazing__DOT__estimator_case__119__en_i = 0;
    IData/*23:0*/ __Vtask_tb_dehazing__DOT__estimator_case__119__pixel_i;
    __Vtask_tb_dehazing__DOT__estimator_case__119__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__estimator_case__119__expected;
    __Vtask_tb_dehazing__DOT__estimator_case__119__expected = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__120__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__121__valid_i;
    __Vtask_tb_dehazing__DOT__estimator_case__121__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__121__sof_i;
    __Vtask_tb_dehazing__DOT__estimator_case__121__sof_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__121__en_i;
    __Vtask_tb_dehazing__DOT__estimator_case__121__en_i = 0;
    IData/*23:0*/ __Vtask_tb_dehazing__DOT__estimator_case__121__pixel_i;
    __Vtask_tb_dehazing__DOT__estimator_case__121__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__estimator_case__121__expected;
    __Vtask_tb_dehazing__DOT__estimator_case__121__expected = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__122__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__123__valid_i;
    __Vtask_tb_dehazing__DOT__estimator_case__123__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__123__sof_i;
    __Vtask_tb_dehazing__DOT__estimator_case__123__sof_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__123__en_i;
    __Vtask_tb_dehazing__DOT__estimator_case__123__en_i = 0;
    IData/*23:0*/ __Vtask_tb_dehazing__DOT__estimator_case__123__pixel_i;
    __Vtask_tb_dehazing__DOT__estimator_case__123__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__estimator_case__123__expected;
    __Vtask_tb_dehazing__DOT__estimator_case__123__expected = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__124__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__125__valid_i;
    __Vtask_tb_dehazing__DOT__estimator_case__125__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__125__sof_i;
    __Vtask_tb_dehazing__DOT__estimator_case__125__sof_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__125__en_i;
    __Vtask_tb_dehazing__DOT__estimator_case__125__en_i = 0;
    IData/*23:0*/ __Vtask_tb_dehazing__DOT__estimator_case__125__pixel_i;
    __Vtask_tb_dehazing__DOT__estimator_case__125__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__estimator_case__125__expected;
    __Vtask_tb_dehazing__DOT__estimator_case__125__expected = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__126__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__127__valid_i;
    __Vtask_tb_dehazing__DOT__estimator_case__127__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__127__sof_i;
    __Vtask_tb_dehazing__DOT__estimator_case__127__sof_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__127__en_i;
    __Vtask_tb_dehazing__DOT__estimator_case__127__en_i = 0;
    IData/*23:0*/ __Vtask_tb_dehazing__DOT__estimator_case__127__pixel_i;
    __Vtask_tb_dehazing__DOT__estimator_case__127__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__estimator_case__127__expected;
    __Vtask_tb_dehazing__DOT__estimator_case__127__expected = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__128__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__129__valid_i;
    __Vtask_tb_dehazing__DOT__estimator_case__129__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__129__sof_i;
    __Vtask_tb_dehazing__DOT__estimator_case__129__sof_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__129__en_i;
    __Vtask_tb_dehazing__DOT__estimator_case__129__en_i = 0;
    IData/*23:0*/ __Vtask_tb_dehazing__DOT__estimator_case__129__pixel_i;
    __Vtask_tb_dehazing__DOT__estimator_case__129__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__estimator_case__129__expected;
    __Vtask_tb_dehazing__DOT__estimator_case__129__expected = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__130__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__131__valid_i;
    __Vtask_tb_dehazing__DOT__estimator_case__131__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__131__sof_i;
    __Vtask_tb_dehazing__DOT__estimator_case__131__sof_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__estimator_case__131__en_i;
    __Vtask_tb_dehazing__DOT__estimator_case__131__en_i = 0;
    IData/*23:0*/ __Vtask_tb_dehazing__DOT__estimator_case__131__pixel_i;
    __Vtask_tb_dehazing__DOT__estimator_case__131__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__estimator_case__131__expected;
    __Vtask_tb_dehazing__DOT__estimator_case__131__expected = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__132__reason;
    // Body
    if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                     [0xaU] >> 0x20U))) 
                      != vlSelf->tb_dehazing__DOT__es
                      [0xaU]) | ((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                [0xaU] 
                                                >> 0x1fU))) 
                                 != vlSelf->tb_dehazing__DOT__ee
                                 [0xaU])))) {
        __Vtask_tb_dehazing__DOT__fail__71__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__71__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev[0xaU] 
                     & ((0x3fffffffU & ((1U & (IData)(
                                                      (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                       [0xaU] 
                                                       >> 0x21U)))
                                         ? ((0x3fc00000U 
                                             & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                << 6U)) 
                                            | ((0x300000U 
                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                   >> 2U)) 
                                               | ((0xff000U 
                                                   & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                      << 4U)) 
                                                  | ((0xc00U 
                                                      & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                         >> 4U)) 
                                                     | ((0x3fcU 
                                                         & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                            << 2U)) 
                                                        | (3U 
                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                              >> 6U)))))))
                                         : (IData)(
                                                   vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                   [0xaU]))) 
                        != vlSelf->tb_dehazing__DOT__ed
                        [0xaU])))) {
        VL_WRITEF("expected=%x actual=%x\n",30,vlSelf->tb_dehazing__DOT__ed
                  [0xaU],30,(0x3fffffffU & ((1U & (IData)(
                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                           [0xaU] 
                                                           >> 0x21U)))
                                             ? ((0x3fc00000U 
                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                    << 6U)) 
                                                | ((0x300000U 
                                                    & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                       >> 2U)) 
                                                   | ((0xff000U 
                                                       & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                          << 4U)) 
                                                      | ((0xc00U 
                                                          & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                             >> 4U)) 
                                                         | ((0x3fcU 
                                                             & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                << 2U)) 
                                                            | (3U 
                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                  >> 6U)))))))
                                             : (IData)(
                                                       vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                       [0xaU]))));
        __Vtask_tb_dehazing__DOT__fail__72__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__72__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->__Vtask_tb_dehazing__DOT__tick__65__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(vlSelf->__Vtask_tb_dehazing__DOT__tick__65__ready_i))) 
                     & ((((QData)((IData)((1U & (IData)(
                                                        (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                         [0xaU] 
                                                         >> 0x1eU))))) 
                          << 0x20U) | (QData)((IData)(
                                                      (((IData)(
                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                 [0xaU] 
                                                                 >> 0x20U)) 
                                                        << 0x1fU) 
                                                       | ((0x40000000U 
                                                           & ((IData)(
                                                                      (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                       [0xaU] 
                                                                       >> 0x1fU)) 
                                                              << 0x1eU)) 
                                                          | (0x3fffffffU 
                                                             & ((1U 
                                                                 & (IData)(
                                                                           (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                            [0xaU] 
                                                                            >> 0x21U)))
                                                                 ? 
                                                                ((0x3fc00000U 
                                                                  & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                     << 6U)) 
                                                                 | ((0x300000U 
                                                                     & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                        >> 2U)) 
                                                                    | ((0xff000U 
                                                                        & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                           << 4U)) 
                                                                       | ((0xc00U 
                                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                              >> 4U)) 
                                                                          | ((0x3fcU 
                                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                             | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                 : (IData)(
                                                                           vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                           [0xaU])))))))) 
                        != vlSelf->tb_dehazing__DOT__last_output)))) {
        __Vtask_tb_dehazing__DOT__fail__73__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__73__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    vlSelf->tb_dehazing__DOT__last_output = (((QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                          [0xaU] 
                                                                          >> 0x1eU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               (((IData)(
                                                                         (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                          [0xaU] 
                                                                          >> 0x20U)) 
                                                                 << 0x1fU) 
                                                                | ((0x40000000U 
                                                                    & ((IData)(
                                                                               (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x1fU)) 
                                                                       << 0x1eU)) 
                                                                   | (0x3fffffffU 
                                                                      & ((1U 
                                                                          & (IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                          ? 
                                                                         ((0x3fc00000U 
                                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                              << 6U)) 
                                                                          | ((0x300000U 
                                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 2U)) 
                                                                             | ((0xff000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 4U)) 
                                                                                | ((0xc00U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                                | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                          : (IData)(
                                                                                vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU]))))))));
    vlSelf->tb_dehazing__DOT__last_reset = vlSelf->__Vtask_tb_dehazing__DOT__tick__65__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    __Vtask_tb_dehazing__DOT__tick__74__reset_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__74__pixel_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__74__mode_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__74__eop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__74__sop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__74__valid_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__74__ready_i = 0U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__74__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__74__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__74__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__74__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__74__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__74__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__74__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__74__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__74__ready_i) {
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[9U];
            vlSelf->tb_dehazing__DOT__ev[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[9U];
            vlSelf->tb_dehazing__DOT__es[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[9U];
            vlSelf->tb_dehazing__DOT__ee[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[9U];
            vlSelf->tb_dehazing__DOT__ed[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[8U];
            vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[8U];
            vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[8U];
            vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[8U];
            vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[7U];
            vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[7U];
            vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[7U];
            vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[7U];
            vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[6U];
            vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[6U];
            vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[6U];
            vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[6U];
            vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[5U];
            vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[5U];
            vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[5U];
            vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[5U];
            vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[4U];
            vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[4U];
            vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[4U];
            vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[4U];
            vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[3U];
            vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[3U];
            vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[3U];
            vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[3U];
            vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[2U];
            vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[2U];
            vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[2U];
            vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[2U];
            vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[1U];
            vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[1U];
            vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[1U];
            vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[1U];
            vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[0U];
            vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[0U];
            vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[0U];
            vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[0U];
            vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            if (__Vtask_tb_dehazing__DOT__tick__74__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__74__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__74__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__74__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__74__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__74__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__74__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__74__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__74__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__74__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__74__r, __Vtask_tb_dehazing__DOT__tick__74__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__74__r, __Vtask_tb_dehazing__DOT__tick__74__b)
                            ? __Vtask_tb_dehazing__DOT__tick__74__r
                            : __Vtask_tb_dehazing__DOT__tick__74__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__74__g, __Vtask_tb_dehazing__DOT__tick__74__b)
                            ? __Vtask_tb_dehazing__DOT__tick__74__g
                            : __Vtask_tb_dehazing__DOT__tick__74__b));
                __Vtask_tb_dehazing__DOT__tick__74__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__74__r, __Vtask_tb_dehazing__DOT__tick__74__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__74__r, __Vtask_tb_dehazing__DOT__tick__74__b)
                            ? __Vtask_tb_dehazing__DOT__tick__74__r
                            : __Vtask_tb_dehazing__DOT__tick__74__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__74__g, __Vtask_tb_dehazing__DOT__tick__74__b)
                            ? __Vtask_tb_dehazing__DOT__tick__74__g
                            : __Vtask_tb_dehazing__DOT__tick__74__b));
                __Vtask_tb_dehazing__DOT__tick__74__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__74__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__74__lo))];
                __Vtask_tb_dehazing__DOT__tick__74__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__74__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__74__t)) {
                    __Vtask_tb_dehazing__DOT__tick__74__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__74__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__74__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__74__t));
                __Vtask_tb_dehazing__DOT__tick__74__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__74__inv);
                __Vtask_tb_dehazing__DOT__tick__74__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__74__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__74__selected 
                        = vlSelf->tb_dehazing__DOT__sync_mode;
                    vlSelf->tb_dehazing__DOT__frame_mode 
                        = vlSelf->tb_dehazing__DOT__sync_mode;
                    if (VL_LTS_III(32, 0x32U, vlSelf->tb_dehazing__DOT__maximum)) {
                        vlSelf->tb_dehazing__DOT__atmosphere 
                            = VL_SHIFTR_III(32,32,32, 
                                            (VL_MULS_III(32, (IData)(0xfU), vlSelf->tb_dehazing__DOT__atmosphere) 
                                             + vlSelf->tb_dehazing__DOT__maximum), 4U);
                    }
                    vlSelf->tb_dehazing__DOT__maximum = 0U;
                } else {
                    __Vtask_tb_dehazing__DOT__tick__74__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__74__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__74__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__74__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__75__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__74__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__74__a_used), __Vtask_tb_dehazing__DOT__tick__74__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__74__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__75__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__75__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__75__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__75__value));
                __Vtask_tb_dehazing__DOT__tick__74__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__75__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__76__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__74__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__74__a_used), __Vtask_tb_dehazing__DOT__tick__74__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__74__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__76__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__76__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__76__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__76__value));
                __Vtask_tb_dehazing__DOT__tick__74__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__76__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__77__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__74__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__74__a_used), __Vtask_tb_dehazing__DOT__tick__74__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__74__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__77__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__77__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__77__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__77__value));
                __Vtask_tb_dehazing__DOT__tick__74__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__77__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__74__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__74__jr)];
                __Vtask_tb_dehazing__DOT__tick__74__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__74__jg)];
                __Vtask_tb_dehazing__DOT__tick__74__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__74__jb)];
                __Vtask_tb_dehazing__DOT__tick__74__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__74__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__74__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__74__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__74__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__74__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__74__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__74__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__74__processed
                      : __Vtask_tb_dehazing__DOT__tick__74__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__74__mode_i;
    } else {
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT__meta = 0U;
        vlSelf->tb_dehazing__DOT__sync_mode = 0U;
        vlSelf->tb_dehazing__DOT__frame_mode = 0U;
        vlSelf->tb_dehazing__DOT__atmosphere = 0xdcU;
        vlSelf->tb_dehazing__DOT__maximum = 0U;
    }
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       89);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__snk_ready) 
                     != (IData)(vlSelf->tb_dehazing__DOT__src_ready)))) {
        __Vtask_tb_dehazing__DOT__fail__78__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__78__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__79__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__79__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                     [0xaU] >> 0x20U))) 
                      != vlSelf->tb_dehazing__DOT__es
                      [0xaU]) | ((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                [0xaU] 
                                                >> 0x1fU))) 
                                 != vlSelf->tb_dehazing__DOT__ee
                                 [0xaU])))) {
        __Vtask_tb_dehazing__DOT__fail__80__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__80__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev[0xaU] 
                     & ((0x3fffffffU & ((1U & (IData)(
                                                      (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                       [0xaU] 
                                                       >> 0x21U)))
                                         ? ((0x3fc00000U 
                                             & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                << 6U)) 
                                            | ((0x300000U 
                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                   >> 2U)) 
                                               | ((0xff000U 
                                                   & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                      << 4U)) 
                                                  | ((0xc00U 
                                                      & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                         >> 4U)) 
                                                     | ((0x3fcU 
                                                         & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                            << 2U)) 
                                                        | (3U 
                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                              >> 6U)))))))
                                         : (IData)(
                                                   vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                   [0xaU]))) 
                        != vlSelf->tb_dehazing__DOT__ed
                        [0xaU])))) {
        VL_WRITEF("expected=%x actual=%x\n",30,vlSelf->tb_dehazing__DOT__ed
                  [0xaU],30,(0x3fffffffU & ((1U & (IData)(
                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                           [0xaU] 
                                                           >> 0x21U)))
                                             ? ((0x3fc00000U 
                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                    << 6U)) 
                                                | ((0x300000U 
                                                    & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                       >> 2U)) 
                                                   | ((0xff000U 
                                                       & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                          << 4U)) 
                                                      | ((0xc00U 
                                                          & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                             >> 4U)) 
                                                         | ((0x3fcU 
                                                             & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                << 2U)) 
                                                            | (3U 
                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                  >> 6U)))))))
                                             : (IData)(
                                                       vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                       [0xaU]))));
        __Vtask_tb_dehazing__DOT__fail__81__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__81__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__74__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__74__ready_i))) 
                     & ((((QData)((IData)((1U & (IData)(
                                                        (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                         [0xaU] 
                                                         >> 0x1eU))))) 
                          << 0x20U) | (QData)((IData)(
                                                      (((IData)(
                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                 [0xaU] 
                                                                 >> 0x20U)) 
                                                        << 0x1fU) 
                                                       | ((0x40000000U 
                                                           & ((IData)(
                                                                      (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                       [0xaU] 
                                                                       >> 0x1fU)) 
                                                              << 0x1eU)) 
                                                          | (0x3fffffffU 
                                                             & ((1U 
                                                                 & (IData)(
                                                                           (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                            [0xaU] 
                                                                            >> 0x21U)))
                                                                 ? 
                                                                ((0x3fc00000U 
                                                                  & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                     << 6U)) 
                                                                 | ((0x300000U 
                                                                     & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                        >> 2U)) 
                                                                    | ((0xff000U 
                                                                        & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                           << 4U)) 
                                                                       | ((0xc00U 
                                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                              >> 4U)) 
                                                                          | ((0x3fcU 
                                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                             | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                 : (IData)(
                                                                           vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                           [0xaU])))))))) 
                        != vlSelf->tb_dehazing__DOT__last_output)))) {
        __Vtask_tb_dehazing__DOT__fail__82__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__82__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    vlSelf->tb_dehazing__DOT__last_output = (((QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                          [0xaU] 
                                                                          >> 0x1eU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               (((IData)(
                                                                         (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                          [0xaU] 
                                                                          >> 0x20U)) 
                                                                 << 0x1fU) 
                                                                | ((0x40000000U 
                                                                    & ((IData)(
                                                                               (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x1fU)) 
                                                                       << 0x1eU)) 
                                                                   | (0x3fffffffU 
                                                                      & ((1U 
                                                                          & (IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                          ? 
                                                                         ((0x3fc00000U 
                                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                              << 6U)) 
                                                                          | ((0x300000U 
                                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 2U)) 
                                                                             | ((0xff000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 4U)) 
                                                                                | ((0xc00U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                                | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                          : (IData)(
                                                                                vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU]))))))));
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__74__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    __Vtask_tb_dehazing__DOT__tick__83__reset_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__83__pixel_i = 0x12345678U;
    __Vtask_tb_dehazing__DOT__tick__83__mode_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__83__eop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__83__sop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__83__valid_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__83__ready_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__83__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__83__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__83__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__83__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__83__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__83__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__83__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__83__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__83__ready_i) {
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[9U];
            vlSelf->tb_dehazing__DOT__ev[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[9U];
            vlSelf->tb_dehazing__DOT__es[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[9U];
            vlSelf->tb_dehazing__DOT__ee[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[9U];
            vlSelf->tb_dehazing__DOT__ed[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[8U];
            vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[8U];
            vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[8U];
            vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[8U];
            vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[7U];
            vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[7U];
            vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[7U];
            vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[7U];
            vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[6U];
            vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[6U];
            vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[6U];
            vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[6U];
            vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[5U];
            vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[5U];
            vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[5U];
            vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[5U];
            vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[4U];
            vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[4U];
            vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[4U];
            vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[4U];
            vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[3U];
            vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[3U];
            vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[3U];
            vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[3U];
            vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[2U];
            vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[2U];
            vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[2U];
            vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[2U];
            vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[1U];
            vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[1U];
            vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[1U];
            vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[1U];
            vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                = vlSelf->tb_dehazing__DOT__ev[0U];
            vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                = vlSelf->tb_dehazing__DOT__es[0U];
            vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                = vlSelf->tb_dehazing__DOT__ee[0U];
            vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                = vlSelf->tb_dehazing__DOT__ed[0U];
            vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
            if (__Vtask_tb_dehazing__DOT__tick__83__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__83__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__83__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__83__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__83__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__83__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__83__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__83__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__83__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__83__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__83__r, __Vtask_tb_dehazing__DOT__tick__83__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__83__r, __Vtask_tb_dehazing__DOT__tick__83__b)
                            ? __Vtask_tb_dehazing__DOT__tick__83__r
                            : __Vtask_tb_dehazing__DOT__tick__83__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__83__g, __Vtask_tb_dehazing__DOT__tick__83__b)
                            ? __Vtask_tb_dehazing__DOT__tick__83__g
                            : __Vtask_tb_dehazing__DOT__tick__83__b));
                __Vtask_tb_dehazing__DOT__tick__83__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__83__r, __Vtask_tb_dehazing__DOT__tick__83__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__83__r, __Vtask_tb_dehazing__DOT__tick__83__b)
                            ? __Vtask_tb_dehazing__DOT__tick__83__r
                            : __Vtask_tb_dehazing__DOT__tick__83__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__83__g, __Vtask_tb_dehazing__DOT__tick__83__b)
                            ? __Vtask_tb_dehazing__DOT__tick__83__g
                            : __Vtask_tb_dehazing__DOT__tick__83__b));
                __Vtask_tb_dehazing__DOT__tick__83__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__83__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__83__lo))];
                __Vtask_tb_dehazing__DOT__tick__83__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__83__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__83__t)) {
                    __Vtask_tb_dehazing__DOT__tick__83__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__83__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__83__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__83__t));
                __Vtask_tb_dehazing__DOT__tick__83__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__83__inv);
                __Vtask_tb_dehazing__DOT__tick__83__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__83__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__83__selected 
                        = vlSelf->tb_dehazing__DOT__sync_mode;
                    vlSelf->tb_dehazing__DOT__frame_mode 
                        = vlSelf->tb_dehazing__DOT__sync_mode;
                    if (VL_LTS_III(32, 0x32U, vlSelf->tb_dehazing__DOT__maximum)) {
                        vlSelf->tb_dehazing__DOT__atmosphere 
                            = VL_SHIFTR_III(32,32,32, 
                                            (VL_MULS_III(32, (IData)(0xfU), vlSelf->tb_dehazing__DOT__atmosphere) 
                                             + vlSelf->tb_dehazing__DOT__maximum), 4U);
                    }
                    vlSelf->tb_dehazing__DOT__maximum = 0U;
                } else {
                    __Vtask_tb_dehazing__DOT__tick__83__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__83__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__83__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__83__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__84__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__83__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__83__a_used), __Vtask_tb_dehazing__DOT__tick__83__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__83__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__84__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__84__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__84__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__84__value));
                __Vtask_tb_dehazing__DOT__tick__83__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__84__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__85__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__83__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__83__a_used), __Vtask_tb_dehazing__DOT__tick__83__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__83__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__85__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__85__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__85__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__85__value));
                __Vtask_tb_dehazing__DOT__tick__83__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__85__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__86__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__83__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__83__a_used), __Vtask_tb_dehazing__DOT__tick__83__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__83__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__86__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__86__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__86__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__86__value));
                __Vtask_tb_dehazing__DOT__tick__83__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__86__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__83__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__83__jr)];
                __Vtask_tb_dehazing__DOT__tick__83__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__83__jg)];
                __Vtask_tb_dehazing__DOT__tick__83__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__83__jb)];
                __Vtask_tb_dehazing__DOT__tick__83__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__83__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__83__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__83__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__83__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__83__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__83__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__83__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__83__processed
                      : __Vtask_tb_dehazing__DOT__tick__83__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__83__mode_i;
    } else {
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
        vlSelf->tb_dehazing__DOT__ev[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
        vlSelf->tb_dehazing__DOT__es[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
        vlSelf->tb_dehazing__DOT__ee[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
        vlSelf->tb_dehazing__DOT__ed[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
        vlSelf->tb_dehazing__DOT__meta = 0U;
        vlSelf->tb_dehazing__DOT__sync_mode = 0U;
        vlSelf->tb_dehazing__DOT__frame_mode = 0U;
        vlSelf->tb_dehazing__DOT__atmosphere = 0xdcU;
        vlSelf->tb_dehazing__DOT__maximum = 0U;
    }
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       89);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__snk_ready) 
                     != (IData)(vlSelf->tb_dehazing__DOT__src_ready)))) {
        __Vtask_tb_dehazing__DOT__fail__87__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__87__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__88__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__88__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                     [0xaU] >> 0x20U))) 
                      != vlSelf->tb_dehazing__DOT__es
                      [0xaU]) | ((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                [0xaU] 
                                                >> 0x1fU))) 
                                 != vlSelf->tb_dehazing__DOT__ee
                                 [0xaU])))) {
        __Vtask_tb_dehazing__DOT__fail__89__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__89__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev[0xaU] 
                     & ((0x3fffffffU & ((1U & (IData)(
                                                      (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                       [0xaU] 
                                                       >> 0x21U)))
                                         ? ((0x3fc00000U 
                                             & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                << 6U)) 
                                            | ((0x300000U 
                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                   >> 2U)) 
                                               | ((0xff000U 
                                                   & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                      << 4U)) 
                                                  | ((0xc00U 
                                                      & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                         >> 4U)) 
                                                     | ((0x3fcU 
                                                         & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                            << 2U)) 
                                                        | (3U 
                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                              >> 6U)))))))
                                         : (IData)(
                                                   vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                   [0xaU]))) 
                        != vlSelf->tb_dehazing__DOT__ed
                        [0xaU])))) {
        VL_WRITEF("expected=%x actual=%x\n",30,vlSelf->tb_dehazing__DOT__ed
                  [0xaU],30,(0x3fffffffU & ((1U & (IData)(
                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                           [0xaU] 
                                                           >> 0x21U)))
                                             ? ((0x3fc00000U 
                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                    << 6U)) 
                                                | ((0x300000U 
                                                    & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                       >> 2U)) 
                                                   | ((0xff000U 
                                                       & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                          << 4U)) 
                                                      | ((0xc00U 
                                                          & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                             >> 4U)) 
                                                         | ((0x3fcU 
                                                             & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                << 2U)) 
                                                            | (3U 
                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                  >> 6U)))))))
                                             : (IData)(
                                                       vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                       [0xaU]))));
        __Vtask_tb_dehazing__DOT__fail__90__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__90__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__83__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__83__ready_i))) 
                     & ((((QData)((IData)((1U & (IData)(
                                                        (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                         [0xaU] 
                                                         >> 0x1eU))))) 
                          << 0x20U) | (QData)((IData)(
                                                      (((IData)(
                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                 [0xaU] 
                                                                 >> 0x20U)) 
                                                        << 0x1fU) 
                                                       | ((0x40000000U 
                                                           & ((IData)(
                                                                      (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                       [0xaU] 
                                                                       >> 0x1fU)) 
                                                              << 0x1eU)) 
                                                          | (0x3fffffffU 
                                                             & ((1U 
                                                                 & (IData)(
                                                                           (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                            [0xaU] 
                                                                            >> 0x21U)))
                                                                 ? 
                                                                ((0x3fc00000U 
                                                                  & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                     << 6U)) 
                                                                 | ((0x300000U 
                                                                     & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                        >> 2U)) 
                                                                    | ((0xff000U 
                                                                        & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                           << 4U)) 
                                                                       | ((0xc00U 
                                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                              >> 4U)) 
                                                                          | ((0x3fcU 
                                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                             | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                 : (IData)(
                                                                           vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                           [0xaU])))))))) 
                        != vlSelf->tb_dehazing__DOT__last_output)))) {
        __Vtask_tb_dehazing__DOT__fail__91__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__91__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    vlSelf->tb_dehazing__DOT__last_output = (((QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                          [0xaU] 
                                                                          >> 0x1eU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               (((IData)(
                                                                         (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                          [0xaU] 
                                                                          >> 0x20U)) 
                                                                 << 0x1fU) 
                                                                | ((0x40000000U 
                                                                    & ((IData)(
                                                                               (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x1fU)) 
                                                                       << 0x1eU)) 
                                                                   | (0x3fffffffU 
                                                                      & ((1U 
                                                                          & (IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                          ? 
                                                                         ((0x3fc00000U 
                                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                              << 6U)) 
                                                                          | ((0x300000U 
                                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 2U)) 
                                                                             | ((0xff000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 4U)) 
                                                                                | ((0xc00U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                                | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                          : (IData)(
                                                                                vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU]))))))));
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__83__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    tb_dehazing__DOT__i = 0U;
    while (VL_GTS_III(32, 0xeU, tb_dehazing__DOT__i)) {
        __Vtask_tb_dehazing__DOT__tick__92__reset_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__92__pixel_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__92__mode_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__92__eop_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__92__sop_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__92__valid_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__92__ready_i = 1U;
        co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           45);
        vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__92__ready_i;
        vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__92__valid_i;
        vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__92__sop_i;
        vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__92__eop_i;
        vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__92__pixel_i;
        vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__92__mode_i;
        vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__92__reset_i;
        co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           48);
        if (__Vtask_tb_dehazing__DOT__tick__92__reset_i) {
            if (__Vtask_tb_dehazing__DOT__tick__92__ready_i) {
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[9U];
                vlSelf->tb_dehazing__DOT__ev[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[9U];
                vlSelf->tb_dehazing__DOT__es[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[9U];
                vlSelf->tb_dehazing__DOT__ee[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[9U];
                vlSelf->tb_dehazing__DOT__ed[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[8U];
                vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[8U];
                vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[8U];
                vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[8U];
                vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[7U];
                vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[7U];
                vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[7U];
                vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[7U];
                vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[6U];
                vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[6U];
                vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[6U];
                vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[6U];
                vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[5U];
                vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[5U];
                vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[5U];
                vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[5U];
                vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[4U];
                vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[4U];
                vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[4U];
                vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[4U];
                vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[3U];
                vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[3U];
                vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[3U];
                vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[3U];
                vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[2U];
                vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[2U];
                vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[2U];
                vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[2U];
                vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[1U];
                vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[1U];
                vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[1U];
                vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[1U];
                vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[0U];
                vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[0U];
                vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[0U];
                vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[0U];
                vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                if (__Vtask_tb_dehazing__DOT__tick__92__valid_i) {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__92__sop_i;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__92__eop_i;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__accepted 
                        = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                    __Vtask_tb_dehazing__DOT__tick__92__r 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__92__pixel_i 
                                    >> 0x16U));
                    __Vtask_tb_dehazing__DOT__tick__92__g 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__92__pixel_i 
                                    >> 0xcU));
                    __Vtask_tb_dehazing__DOT__tick__92__b 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__92__pixel_i 
                                    >> 2U));
                    __Vtask_tb_dehazing__DOT__tick__92__hi 
                        = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__92__r, __Vtask_tb_dehazing__DOT__tick__92__g)
                            ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__92__r, __Vtask_tb_dehazing__DOT__tick__92__b)
                                ? __Vtask_tb_dehazing__DOT__tick__92__r
                                : __Vtask_tb_dehazing__DOT__tick__92__b)
                            : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__92__g, __Vtask_tb_dehazing__DOT__tick__92__b)
                                ? __Vtask_tb_dehazing__DOT__tick__92__g
                                : __Vtask_tb_dehazing__DOT__tick__92__b));
                    __Vtask_tb_dehazing__DOT__tick__92__lo 
                        = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__92__r, __Vtask_tb_dehazing__DOT__tick__92__g)
                            ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__92__r, __Vtask_tb_dehazing__DOT__tick__92__b)
                                ? __Vtask_tb_dehazing__DOT__tick__92__r
                                : __Vtask_tb_dehazing__DOT__tick__92__b)
                            : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__92__g, __Vtask_tb_dehazing__DOT__tick__92__b)
                                ? __Vtask_tb_dehazing__DOT__tick__92__g
                                : __Vtask_tb_dehazing__DOT__tick__92__b));
                    __Vtask_tb_dehazing__DOT__tick__92__t 
                        = vlSelf->tb_dehazing__DOT__transmission_rom
                        [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__92__hi, 8U) 
                                     | __Vtask_tb_dehazing__DOT__tick__92__lo))];
                    __Vtask_tb_dehazing__DOT__tick__92__t 
                        = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__92__t);
                    if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__92__t)) {
                        __Vtask_tb_dehazing__DOT__tick__92__t = 0x66U;
                    }
                    __Vtask_tb_dehazing__DOT__tick__92__inv 
                        = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__92__t)
                            ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__92__t));
                    __Vtask_tb_dehazing__DOT__tick__92__inv 
                        = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__92__inv);
                    __Vtask_tb_dehazing__DOT__tick__92__a_used 
                        = vlSelf->tb_dehazing__DOT__atmosphere;
                    if (__Vtask_tb_dehazing__DOT__tick__92__sop_i) {
                        __Vtask_tb_dehazing__DOT__tick__92__selected 
                            = vlSelf->tb_dehazing__DOT__sync_mode;
                        vlSelf->tb_dehazing__DOT__frame_mode 
                            = vlSelf->tb_dehazing__DOT__sync_mode;
                        if (VL_LTS_III(32, 0x32U, vlSelf->tb_dehazing__DOT__maximum)) {
                            vlSelf->tb_dehazing__DOT__atmosphere 
                                = VL_SHIFTR_III(32,32,32, 
                                                (VL_MULS_III(32, (IData)(0xfU), vlSelf->tb_dehazing__DOT__atmosphere) 
                                                 + vlSelf->tb_dehazing__DOT__maximum), 4U);
                        }
                        vlSelf->tb_dehazing__DOT__maximum = 0U;
                    } else {
                        __Vtask_tb_dehazing__DOT__tick__92__selected 
                            = vlSelf->tb_dehazing__DOT__frame_mode;
                        if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__92__t) 
                             & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__92__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                            vlSelf->tb_dehazing__DOT__maximum 
                                = __Vtask_tb_dehazing__DOT__tick__92__hi;
                        }
                    }
                    __Vfunc_tb_dehazing__DOT__clamp__93__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__92__r 
                                                       - __Vtask_tb_dehazing__DOT__tick__92__a_used), __Vtask_tb_dehazing__DOT__tick__92__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__92__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__93__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__93__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__93__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__93__value));
                    __Vtask_tb_dehazing__DOT__tick__92__jr 
                        = __Vfunc_tb_dehazing__DOT__clamp__93__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__94__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__92__g 
                                                       - __Vtask_tb_dehazing__DOT__tick__92__a_used), __Vtask_tb_dehazing__DOT__tick__92__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__92__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__94__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__94__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__94__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__94__value));
                    __Vtask_tb_dehazing__DOT__tick__92__jg 
                        = __Vfunc_tb_dehazing__DOT__clamp__94__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__95__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__92__b 
                                                       - __Vtask_tb_dehazing__DOT__tick__92__a_used), __Vtask_tb_dehazing__DOT__tick__92__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__92__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__95__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__95__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__95__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__95__value));
                    __Vtask_tb_dehazing__DOT__tick__92__jb 
                        = __Vfunc_tb_dehazing__DOT__clamp__95__Vfuncout;
                    __Vtask_tb_dehazing__DOT__tick__92__gr 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__92__jr)];
                    __Vtask_tb_dehazing__DOT__tick__92__gg 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__92__jg)];
                    __Vtask_tb_dehazing__DOT__tick__92__gb 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__92__jb)];
                    __Vtask_tb_dehazing__DOT__tick__92__processed 
                        = (((IData)(__Vtask_tb_dehazing__DOT__tick__92__gr) 
                            << 0x16U) | ((0x300000U 
                                          & ((IData)(__Vtask_tb_dehazing__DOT__tick__92__gr) 
                                             << 0xeU)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__92__gg) 
                                             << 0xcU) 
                                            | ((0xc00U 
                                                & ((IData)(__Vtask_tb_dehazing__DOT__tick__92__gg) 
                                                   << 4U)) 
                                               | (((IData)(__Vtask_tb_dehazing__DOT__tick__92__gb) 
                                                   << 2U) 
                                                  | (3U 
                                                     & ((IData)(__Vtask_tb_dehazing__DOT__tick__92__gb) 
                                                        >> 6U)))))));
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = ((IData)(__Vtask_tb_dehazing__DOT__tick__92__selected)
                            ? __Vtask_tb_dehazing__DOT__tick__92__processed
                            : __Vtask_tb_dehazing__DOT__tick__92__pixel_i);
                } else {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                }
            }
            vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
            vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__92__mode_i;
        } else {
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT__meta = 0U;
            vlSelf->tb_dehazing__DOT__sync_mode = 0U;
            vlSelf->tb_dehazing__DOT__frame_mode = 0U;
            vlSelf->tb_dehazing__DOT__atmosphere = 0xdcU;
            vlSelf->tb_dehazing__DOT__maximum = 0U;
        }
        co_await vlSelf->__VdlySched.delay(0x3e8ULL, 
                                           nullptr, 
                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                           89);
        if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__snk_ready) 
                         != (IData)(vlSelf->tb_dehazing__DOT__src_ready)))) {
            __Vtask_tb_dehazing__DOT__fail__96__reason = 
                std::string{"ready contract"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__96__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                        [0xaU] >> 0x1eU))) 
                         != vlSelf->tb_dehazing__DOT__ev
                         [0xaU]))) {
            __Vtask_tb_dehazing__DOT__fail__97__reason = 
                std::string{"11 enabled-stage valid/reset/bubble timing"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__97__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                         [0xaU] >> 0x20U))) 
                          != vlSelf->tb_dehazing__DOT__es
                          [0xaU]) | ((1U & (IData)(
                                                   (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                    [0xaU] 
                                                    >> 0x1fU))) 
                                     != vlSelf->tb_dehazing__DOT__ee
                                     [0xaU])))) {
            __Vtask_tb_dehazing__DOT__fail__98__reason = 
                std::string{"ordered SOP/EOP"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__98__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev
                         [0xaU] & ((0x3fffffffU & (
                                                   (1U 
                                                    & (IData)(
                                                              (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                               [0xaU] 
                                                               >> 0x21U)))
                                                    ? 
                                                   ((0x3fc00000U 
                                                     & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                        << 6U)) 
                                                    | ((0x300000U 
                                                        & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                           >> 2U)) 
                                                       | ((0xff000U 
                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                              << 4U)) 
                                                          | ((0xc00U 
                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                 >> 4U)) 
                                                             | ((0x3fcU 
                                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                    << 2U)) 
                                                                | (3U 
                                                                   & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                      >> 6U)))))))
                                                    : (IData)(
                                                              vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                              [0xaU]))) 
                                   != vlSelf->tb_dehazing__DOT__ed
                                   [0xaU])))) {
            VL_WRITEF("expected=%x actual=%x\n",30,
                      vlSelf->tb_dehazing__DOT__ed[0xaU],
                      30,(0x3fffffffU & ((1U & (IData)(
                                                       (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                        [0xaU] 
                                                        >> 0x21U)))
                                          ? ((0x3fc00000U 
                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                 << 6U)) 
                                             | ((0x300000U 
                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                    >> 2U)) 
                                                | ((0xff000U 
                                                    & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                       << 4U)) 
                                                   | ((0xc00U 
                                                       & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                          >> 4U)) 
                                                      | ((0x3fcU 
                                                          & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                             << 2U)) 
                                                         | (3U 
                                                            & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                               >> 6U)))))))
                                          : (IData)(
                                                    vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                    [0xaU]))));
            __Vtask_tb_dehazing__DOT__fail__99__reason = 
                std::string{"ordered raw/processed pixel or frame mode"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__99__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__92__reset_i) 
                           & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                          & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__92__ready_i))) 
                         & ((((QData)((IData)((1U & (IData)(
                                                            (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                             [0xaU] 
                                                             >> 0x1eU))))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((IData)(
                                                                    (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                     [0xaU] 
                                                                     >> 0x20U)) 
                                                            << 0x1fU) 
                                                           | ((0x40000000U 
                                                               & ((IData)(
                                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                           [0xaU] 
                                                                           >> 0x1fU)) 
                                                                  << 0x1eU)) 
                                                              | (0x3fffffffU 
                                                                 & ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                     ? 
                                                                    ((0x3fc00000U 
                                                                      & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                         << 6U)) 
                                                                     | ((0x300000U 
                                                                         & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                            >> 2U)) 
                                                                        | ((0xff000U 
                                                                            & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                               << 4U)) 
                                                                           | ((0xc00U 
                                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                              | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                     : (IData)(
                                                                               vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                               [0xaU])))))))) 
                            != vlSelf->tb_dehazing__DOT__last_output)))) {
            __Vtask_tb_dehazing__DOT__fail__100__reason = 
                std::string{"output changed while stalled (including mode changes)"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__100__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        vlSelf->tb_dehazing__DOT__last_output = (((QData)((IData)(
                                                                  (1U 
                                                                   & (IData)(
                                                                             (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                              [0xaU] 
                                                                              >> 0x1eU))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   (((IData)(
                                                                             (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                              [0xaU] 
                                                                              >> 0x20U)) 
                                                                     << 0x1fU) 
                                                                    | ((0x40000000U 
                                                                        & ((IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x1fU)) 
                                                                           << 0x1eU)) 
                                                                       | (0x3fffffffU 
                                                                          & ((1U 
                                                                              & (IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                              ? 
                                                                             ((0x3fc00000U 
                                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 6U)) 
                                                                              | ((0x300000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 2U)) 
                                                                                | ((0xff000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 4U)) 
                                                                                | ((0xc00U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                                | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                              : (IData)(
                                                                                vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU]))))))));
        vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__92__reset_i;
        vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                            + vlSelf->tb_dehazing__DOT__checks);
        tb_dehazing__DOT__i = ((IData)(1U) + tb_dehazing__DOT__i);
    }
    tb_dehazing__DOT__i = 0U;
    while (VL_GTS_III(32, 0xcU, tb_dehazing__DOT__i)) {
        __Vtask_tb_dehazing__DOT__tick__101__reset_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__101__pixel_i 
            = (0x3fffffffU & ((IData)(0x1020304U) * tb_dehazing__DOT__i));
        __Vtask_tb_dehazing__DOT__tick__101__mode_i 
            = (1U & tb_dehazing__DOT__i);
        __Vtask_tb_dehazing__DOT__tick__101__eop_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__101__sop_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__101__valid_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__101__ready_i = 1U;
        co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           45);
        vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__101__ready_i;
        vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__101__valid_i;
        vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__101__sop_i;
        vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__101__eop_i;
        vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__101__pixel_i;
        vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__101__mode_i;
        vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__101__reset_i;
        co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           48);
        if (__Vtask_tb_dehazing__DOT__tick__101__reset_i) {
            if (__Vtask_tb_dehazing__DOT__tick__101__ready_i) {
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[9U];
                vlSelf->tb_dehazing__DOT__ev[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[9U];
                vlSelf->tb_dehazing__DOT__es[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[9U];
                vlSelf->tb_dehazing__DOT__ee[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[9U];
                vlSelf->tb_dehazing__DOT__ed[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[8U];
                vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[8U];
                vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[8U];
                vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[8U];
                vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[7U];
                vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[7U];
                vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[7U];
                vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[7U];
                vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[6U];
                vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[6U];
                vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[6U];
                vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[6U];
                vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[5U];
                vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[5U];
                vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[5U];
                vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[5U];
                vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[4U];
                vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[4U];
                vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[4U];
                vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[4U];
                vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[3U];
                vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[3U];
                vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[3U];
                vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[3U];
                vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[2U];
                vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[2U];
                vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[2U];
                vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[2U];
                vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[1U];
                vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[1U];
                vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[1U];
                vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[1U];
                vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[0U];
                vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[0U];
                vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[0U];
                vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[0U];
                vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                if (__Vtask_tb_dehazing__DOT__tick__101__valid_i) {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__101__sop_i;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__101__eop_i;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__accepted 
                        = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                    __Vtask_tb_dehazing__DOT__tick__101__r 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__101__pixel_i 
                                    >> 0x16U));
                    __Vtask_tb_dehazing__DOT__tick__101__g 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__101__pixel_i 
                                    >> 0xcU));
                    __Vtask_tb_dehazing__DOT__tick__101__b 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__101__pixel_i 
                                    >> 2U));
                    __Vtask_tb_dehazing__DOT__tick__101__hi 
                        = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__101__r, __Vtask_tb_dehazing__DOT__tick__101__g)
                            ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__101__r, __Vtask_tb_dehazing__DOT__tick__101__b)
                                ? __Vtask_tb_dehazing__DOT__tick__101__r
                                : __Vtask_tb_dehazing__DOT__tick__101__b)
                            : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__101__g, __Vtask_tb_dehazing__DOT__tick__101__b)
                                ? __Vtask_tb_dehazing__DOT__tick__101__g
                                : __Vtask_tb_dehazing__DOT__tick__101__b));
                    __Vtask_tb_dehazing__DOT__tick__101__lo 
                        = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__101__r, __Vtask_tb_dehazing__DOT__tick__101__g)
                            ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__101__r, __Vtask_tb_dehazing__DOT__tick__101__b)
                                ? __Vtask_tb_dehazing__DOT__tick__101__r
                                : __Vtask_tb_dehazing__DOT__tick__101__b)
                            : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__101__g, __Vtask_tb_dehazing__DOT__tick__101__b)
                                ? __Vtask_tb_dehazing__DOT__tick__101__g
                                : __Vtask_tb_dehazing__DOT__tick__101__b));
                    __Vtask_tb_dehazing__DOT__tick__101__t 
                        = vlSelf->tb_dehazing__DOT__transmission_rom
                        [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__101__hi, 8U) 
                                     | __Vtask_tb_dehazing__DOT__tick__101__lo))];
                    __Vtask_tb_dehazing__DOT__tick__101__t 
                        = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__101__t);
                    if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__101__t)) {
                        __Vtask_tb_dehazing__DOT__tick__101__t = 0x66U;
                    }
                    __Vtask_tb_dehazing__DOT__tick__101__inv 
                        = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__101__t)
                            ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__101__t));
                    __Vtask_tb_dehazing__DOT__tick__101__inv 
                        = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__101__inv);
                    __Vtask_tb_dehazing__DOT__tick__101__a_used 
                        = vlSelf->tb_dehazing__DOT__atmosphere;
                    if (__Vtask_tb_dehazing__DOT__tick__101__sop_i) {
                        __Vtask_tb_dehazing__DOT__tick__101__selected 
                            = vlSelf->tb_dehazing__DOT__sync_mode;
                        vlSelf->tb_dehazing__DOT__frame_mode 
                            = vlSelf->tb_dehazing__DOT__sync_mode;
                        if (VL_LTS_III(32, 0x32U, vlSelf->tb_dehazing__DOT__maximum)) {
                            vlSelf->tb_dehazing__DOT__atmosphere 
                                = VL_SHIFTR_III(32,32,32, 
                                                (VL_MULS_III(32, (IData)(0xfU), vlSelf->tb_dehazing__DOT__atmosphere) 
                                                 + vlSelf->tb_dehazing__DOT__maximum), 4U);
                        }
                        vlSelf->tb_dehazing__DOT__maximum = 0U;
                    } else {
                        __Vtask_tb_dehazing__DOT__tick__101__selected 
                            = vlSelf->tb_dehazing__DOT__frame_mode;
                        if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__101__t) 
                             & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__101__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                            vlSelf->tb_dehazing__DOT__maximum 
                                = __Vtask_tb_dehazing__DOT__tick__101__hi;
                        }
                    }
                    __Vfunc_tb_dehazing__DOT__clamp__102__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__101__r 
                                                       - __Vtask_tb_dehazing__DOT__tick__101__a_used), __Vtask_tb_dehazing__DOT__tick__101__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__101__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__102__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__102__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__102__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__102__value));
                    __Vtask_tb_dehazing__DOT__tick__101__jr 
                        = __Vfunc_tb_dehazing__DOT__clamp__102__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__103__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__101__g 
                                                       - __Vtask_tb_dehazing__DOT__tick__101__a_used), __Vtask_tb_dehazing__DOT__tick__101__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__101__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__103__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__103__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__103__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__103__value));
                    __Vtask_tb_dehazing__DOT__tick__101__jg 
                        = __Vfunc_tb_dehazing__DOT__clamp__103__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__104__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__101__b 
                                                       - __Vtask_tb_dehazing__DOT__tick__101__a_used), __Vtask_tb_dehazing__DOT__tick__101__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__101__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__104__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__104__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__104__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__104__value));
                    __Vtask_tb_dehazing__DOT__tick__101__jb 
                        = __Vfunc_tb_dehazing__DOT__clamp__104__Vfuncout;
                    __Vtask_tb_dehazing__DOT__tick__101__gr 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__101__jr)];
                    __Vtask_tb_dehazing__DOT__tick__101__gg 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__101__jg)];
                    __Vtask_tb_dehazing__DOT__tick__101__gb 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__101__jb)];
                    __Vtask_tb_dehazing__DOT__tick__101__processed 
                        = (((IData)(__Vtask_tb_dehazing__DOT__tick__101__gr) 
                            << 0x16U) | ((0x300000U 
                                          & ((IData)(__Vtask_tb_dehazing__DOT__tick__101__gr) 
                                             << 0xeU)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__101__gg) 
                                             << 0xcU) 
                                            | ((0xc00U 
                                                & ((IData)(__Vtask_tb_dehazing__DOT__tick__101__gg) 
                                                   << 4U)) 
                                               | (((IData)(__Vtask_tb_dehazing__DOT__tick__101__gb) 
                                                   << 2U) 
                                                  | (3U 
                                                     & ((IData)(__Vtask_tb_dehazing__DOT__tick__101__gb) 
                                                        >> 6U)))))));
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = ((IData)(__Vtask_tb_dehazing__DOT__tick__101__selected)
                            ? __Vtask_tb_dehazing__DOT__tick__101__processed
                            : __Vtask_tb_dehazing__DOT__tick__101__pixel_i);
                } else {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                }
            }
            vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
            vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__101__mode_i;
        } else {
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT__meta = 0U;
            vlSelf->tb_dehazing__DOT__sync_mode = 0U;
            vlSelf->tb_dehazing__DOT__frame_mode = 0U;
            vlSelf->tb_dehazing__DOT__atmosphere = 0xdcU;
            vlSelf->tb_dehazing__DOT__maximum = 0U;
        }
        co_await vlSelf->__VdlySched.delay(0x3e8ULL, 
                                           nullptr, 
                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                           89);
        if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__snk_ready) 
                         != (IData)(vlSelf->tb_dehazing__DOT__src_ready)))) {
            __Vtask_tb_dehazing__DOT__fail__105__reason = 
                std::string{"ready contract"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__105__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                        [0xaU] >> 0x1eU))) 
                         != vlSelf->tb_dehazing__DOT__ev
                         [0xaU]))) {
            __Vtask_tb_dehazing__DOT__fail__106__reason = 
                std::string{"11 enabled-stage valid/reset/bubble timing"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__106__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                         [0xaU] >> 0x20U))) 
                          != vlSelf->tb_dehazing__DOT__es
                          [0xaU]) | ((1U & (IData)(
                                                   (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                    [0xaU] 
                                                    >> 0x1fU))) 
                                     != vlSelf->tb_dehazing__DOT__ee
                                     [0xaU])))) {
            __Vtask_tb_dehazing__DOT__fail__107__reason = 
                std::string{"ordered SOP/EOP"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__107__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev
                         [0xaU] & ((0x3fffffffU & (
                                                   (1U 
                                                    & (IData)(
                                                              (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                               [0xaU] 
                                                               >> 0x21U)))
                                                    ? 
                                                   ((0x3fc00000U 
                                                     & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                        << 6U)) 
                                                    | ((0x300000U 
                                                        & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                           >> 2U)) 
                                                       | ((0xff000U 
                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                              << 4U)) 
                                                          | ((0xc00U 
                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                 >> 4U)) 
                                                             | ((0x3fcU 
                                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                    << 2U)) 
                                                                | (3U 
                                                                   & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                      >> 6U)))))))
                                                    : (IData)(
                                                              vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                              [0xaU]))) 
                                   != vlSelf->tb_dehazing__DOT__ed
                                   [0xaU])))) {
            VL_WRITEF("expected=%x actual=%x\n",30,
                      vlSelf->tb_dehazing__DOT__ed[0xaU],
                      30,(0x3fffffffU & ((1U & (IData)(
                                                       (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                        [0xaU] 
                                                        >> 0x21U)))
                                          ? ((0x3fc00000U 
                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                 << 6U)) 
                                             | ((0x300000U 
                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                    >> 2U)) 
                                                | ((0xff000U 
                                                    & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                       << 4U)) 
                                                   | ((0xc00U 
                                                       & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                          >> 4U)) 
                                                      | ((0x3fcU 
                                                          & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                             << 2U)) 
                                                         | (3U 
                                                            & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                               >> 6U)))))))
                                          : (IData)(
                                                    vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                    [0xaU]))));
            __Vtask_tb_dehazing__DOT__fail__108__reason = 
                std::string{"ordered raw/processed pixel or frame mode"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__108__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__101__reset_i) 
                           & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                          & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__101__ready_i))) 
                         & ((((QData)((IData)((1U & (IData)(
                                                            (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                             [0xaU] 
                                                             >> 0x1eU))))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((IData)(
                                                                    (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                     [0xaU] 
                                                                     >> 0x20U)) 
                                                            << 0x1fU) 
                                                           | ((0x40000000U 
                                                               & ((IData)(
                                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                           [0xaU] 
                                                                           >> 0x1fU)) 
                                                                  << 0x1eU)) 
                                                              | (0x3fffffffU 
                                                                 & ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                     ? 
                                                                    ((0x3fc00000U 
                                                                      & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                         << 6U)) 
                                                                     | ((0x300000U 
                                                                         & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                            >> 2U)) 
                                                                        | ((0xff000U 
                                                                            & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                               << 4U)) 
                                                                           | ((0xc00U 
                                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                              | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                     : (IData)(
                                                                               vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                               [0xaU])))))))) 
                            != vlSelf->tb_dehazing__DOT__last_output)))) {
            __Vtask_tb_dehazing__DOT__fail__109__reason = 
                std::string{"output changed while stalled (including mode changes)"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__109__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        vlSelf->tb_dehazing__DOT__last_output = (((QData)((IData)(
                                                                  (1U 
                                                                   & (IData)(
                                                                             (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                              [0xaU] 
                                                                              >> 0x1eU))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   (((IData)(
                                                                             (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                              [0xaU] 
                                                                              >> 0x20U)) 
                                                                     << 0x1fU) 
                                                                    | ((0x40000000U 
                                                                        & ((IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x1fU)) 
                                                                           << 0x1eU)) 
                                                                       | (0x3fffffffU 
                                                                          & ((1U 
                                                                              & (IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                              ? 
                                                                             ((0x3fc00000U 
                                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 6U)) 
                                                                              | ((0x300000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 2U)) 
                                                                                | ((0xff000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 4U)) 
                                                                                | ((0xc00U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                                | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                              : (IData)(
                                                                                vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU]))))))));
        vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__101__reset_i;
        vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                            + vlSelf->tb_dehazing__DOT__checks);
        tb_dehazing__DOT__i = ((IData)(1U) + tb_dehazing__DOT__i);
    }
    tb_dehazing__DOT__i = 0U;
    while (VL_GTS_III(32, 0xeU, tb_dehazing__DOT__i)) {
        __Vtask_tb_dehazing__DOT__tick__110__reset_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__110__pixel_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__110__mode_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__110__eop_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__110__sop_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__110__valid_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__110__ready_i = 1U;
        co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           45);
        vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__110__ready_i;
        vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__110__valid_i;
        vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__110__sop_i;
        vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__110__eop_i;
        vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__110__pixel_i;
        vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__110__mode_i;
        vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__110__reset_i;
        co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           48);
        if (__Vtask_tb_dehazing__DOT__tick__110__reset_i) {
            if (__Vtask_tb_dehazing__DOT__tick__110__ready_i) {
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[9U];
                vlSelf->tb_dehazing__DOT__ev[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[9U];
                vlSelf->tb_dehazing__DOT__es[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[9U];
                vlSelf->tb_dehazing__DOT__ee[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[9U];
                vlSelf->tb_dehazing__DOT__ed[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[8U];
                vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[8U];
                vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[8U];
                vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[8U];
                vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[7U];
                vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[7U];
                vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[7U];
                vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[7U];
                vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[6U];
                vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[6U];
                vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[6U];
                vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[6U];
                vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[5U];
                vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[5U];
                vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[5U];
                vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[5U];
                vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[4U];
                vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[4U];
                vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[4U];
                vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[4U];
                vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[3U];
                vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[3U];
                vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[3U];
                vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[3U];
                vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[2U];
                vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[2U];
                vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[2U];
                vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[2U];
                vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[1U];
                vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[1U];
                vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[1U];
                vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[1U];
                vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                    = vlSelf->tb_dehazing__DOT__ev[0U];
                vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                    = vlSelf->tb_dehazing__DOT__es[0U];
                vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                    = vlSelf->tb_dehazing__DOT__ee[0U];
                vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                    = vlSelf->tb_dehazing__DOT__ed[0U];
                vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                if (__Vtask_tb_dehazing__DOT__tick__110__valid_i) {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__110__sop_i;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__110__eop_i;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__accepted 
                        = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                    __Vtask_tb_dehazing__DOT__tick__110__r 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__110__pixel_i 
                                    >> 0x16U));
                    __Vtask_tb_dehazing__DOT__tick__110__g 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__110__pixel_i 
                                    >> 0xcU));
                    __Vtask_tb_dehazing__DOT__tick__110__b 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__110__pixel_i 
                                    >> 2U));
                    __Vtask_tb_dehazing__DOT__tick__110__hi 
                        = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__110__r, __Vtask_tb_dehazing__DOT__tick__110__g)
                            ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__110__r, __Vtask_tb_dehazing__DOT__tick__110__b)
                                ? __Vtask_tb_dehazing__DOT__tick__110__r
                                : __Vtask_tb_dehazing__DOT__tick__110__b)
                            : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__110__g, __Vtask_tb_dehazing__DOT__tick__110__b)
                                ? __Vtask_tb_dehazing__DOT__tick__110__g
                                : __Vtask_tb_dehazing__DOT__tick__110__b));
                    __Vtask_tb_dehazing__DOT__tick__110__lo 
                        = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__110__r, __Vtask_tb_dehazing__DOT__tick__110__g)
                            ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__110__r, __Vtask_tb_dehazing__DOT__tick__110__b)
                                ? __Vtask_tb_dehazing__DOT__tick__110__r
                                : __Vtask_tb_dehazing__DOT__tick__110__b)
                            : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__110__g, __Vtask_tb_dehazing__DOT__tick__110__b)
                                ? __Vtask_tb_dehazing__DOT__tick__110__g
                                : __Vtask_tb_dehazing__DOT__tick__110__b));
                    __Vtask_tb_dehazing__DOT__tick__110__t 
                        = vlSelf->tb_dehazing__DOT__transmission_rom
                        [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__110__hi, 8U) 
                                     | __Vtask_tb_dehazing__DOT__tick__110__lo))];
                    __Vtask_tb_dehazing__DOT__tick__110__t 
                        = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__110__t);
                    if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__110__t)) {
                        __Vtask_tb_dehazing__DOT__tick__110__t = 0x66U;
                    }
                    __Vtask_tb_dehazing__DOT__tick__110__inv 
                        = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__110__t)
                            ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__110__t));
                    __Vtask_tb_dehazing__DOT__tick__110__inv 
                        = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__110__inv);
                    __Vtask_tb_dehazing__DOT__tick__110__a_used 
                        = vlSelf->tb_dehazing__DOT__atmosphere;
                    if (__Vtask_tb_dehazing__DOT__tick__110__sop_i) {
                        __Vtask_tb_dehazing__DOT__tick__110__selected 
                            = vlSelf->tb_dehazing__DOT__sync_mode;
                        vlSelf->tb_dehazing__DOT__frame_mode 
                            = vlSelf->tb_dehazing__DOT__sync_mode;
                        if (VL_LTS_III(32, 0x32U, vlSelf->tb_dehazing__DOT__maximum)) {
                            vlSelf->tb_dehazing__DOT__atmosphere 
                                = VL_SHIFTR_III(32,32,32, 
                                                (VL_MULS_III(32, (IData)(0xfU), vlSelf->tb_dehazing__DOT__atmosphere) 
                                                 + vlSelf->tb_dehazing__DOT__maximum), 4U);
                        }
                        vlSelf->tb_dehazing__DOT__maximum = 0U;
                    } else {
                        __Vtask_tb_dehazing__DOT__tick__110__selected 
                            = vlSelf->tb_dehazing__DOT__frame_mode;
                        if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__110__t) 
                             & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__110__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                            vlSelf->tb_dehazing__DOT__maximum 
                                = __Vtask_tb_dehazing__DOT__tick__110__hi;
                        }
                    }
                    __Vfunc_tb_dehazing__DOT__clamp__111__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__110__r 
                                                       - __Vtask_tb_dehazing__DOT__tick__110__a_used), __Vtask_tb_dehazing__DOT__tick__110__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__110__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__111__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__111__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__111__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__111__value));
                    __Vtask_tb_dehazing__DOT__tick__110__jr 
                        = __Vfunc_tb_dehazing__DOT__clamp__111__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__112__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__110__g 
                                                       - __Vtask_tb_dehazing__DOT__tick__110__a_used), __Vtask_tb_dehazing__DOT__tick__110__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__110__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__112__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__112__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__112__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__112__value));
                    __Vtask_tb_dehazing__DOT__tick__110__jg 
                        = __Vfunc_tb_dehazing__DOT__clamp__112__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__113__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__110__b 
                                                       - __Vtask_tb_dehazing__DOT__tick__110__a_used), __Vtask_tb_dehazing__DOT__tick__110__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__110__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__113__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__113__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__113__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__113__value));
                    __Vtask_tb_dehazing__DOT__tick__110__jb 
                        = __Vfunc_tb_dehazing__DOT__clamp__113__Vfuncout;
                    __Vtask_tb_dehazing__DOT__tick__110__gr 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__110__jr)];
                    __Vtask_tb_dehazing__DOT__tick__110__gg 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__110__jg)];
                    __Vtask_tb_dehazing__DOT__tick__110__gb 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__110__jb)];
                    __Vtask_tb_dehazing__DOT__tick__110__processed 
                        = (((IData)(__Vtask_tb_dehazing__DOT__tick__110__gr) 
                            << 0x16U) | ((0x300000U 
                                          & ((IData)(__Vtask_tb_dehazing__DOT__tick__110__gr) 
                                             << 0xeU)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__110__gg) 
                                             << 0xcU) 
                                            | ((0xc00U 
                                                & ((IData)(__Vtask_tb_dehazing__DOT__tick__110__gg) 
                                                   << 4U)) 
                                               | (((IData)(__Vtask_tb_dehazing__DOT__tick__110__gb) 
                                                   << 2U) 
                                                  | (3U 
                                                     & ((IData)(__Vtask_tb_dehazing__DOT__tick__110__gb) 
                                                        >> 6U)))))));
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = ((IData)(__Vtask_tb_dehazing__DOT__tick__110__selected)
                            ? __Vtask_tb_dehazing__DOT__tick__110__processed
                            : __Vtask_tb_dehazing__DOT__tick__110__pixel_i);
                } else {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                }
            }
            vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
            vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__110__mode_i;
        } else {
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[0U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[1U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[2U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[3U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[4U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[5U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[6U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[7U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[8U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[9U] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
            vlSelf->tb_dehazing__DOT__ev[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
            vlSelf->tb_dehazing__DOT__es[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
            vlSelf->tb_dehazing__DOT__ee[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
            vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
            vlSelf->tb_dehazing__DOT__ed[0xaU] = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
            vlSelf->tb_dehazing__DOT__meta = 0U;
            vlSelf->tb_dehazing__DOT__sync_mode = 0U;
            vlSelf->tb_dehazing__DOT__frame_mode = 0U;
            vlSelf->tb_dehazing__DOT__atmosphere = 0xdcU;
            vlSelf->tb_dehazing__DOT__maximum = 0U;
        }
        co_await vlSelf->__VdlySched.delay(0x3e8ULL, 
                                           nullptr, 
                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                           89);
        if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__snk_ready) 
                         != (IData)(vlSelf->tb_dehazing__DOT__src_ready)))) {
            __Vtask_tb_dehazing__DOT__fail__114__reason = 
                std::string{"ready contract"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__114__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                        [0xaU] >> 0x1eU))) 
                         != vlSelf->tb_dehazing__DOT__ev
                         [0xaU]))) {
            __Vtask_tb_dehazing__DOT__fail__115__reason = 
                std::string{"11 enabled-stage valid/reset/bubble timing"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__115__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                         [0xaU] >> 0x20U))) 
                          != vlSelf->tb_dehazing__DOT__es
                          [0xaU]) | ((1U & (IData)(
                                                   (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                    [0xaU] 
                                                    >> 0x1fU))) 
                                     != vlSelf->tb_dehazing__DOT__ee
                                     [0xaU])))) {
            __Vtask_tb_dehazing__DOT__fail__116__reason = 
                std::string{"ordered SOP/EOP"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__116__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev
                         [0xaU] & ((0x3fffffffU & (
                                                   (1U 
                                                    & (IData)(
                                                              (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                               [0xaU] 
                                                               >> 0x21U)))
                                                    ? 
                                                   ((0x3fc00000U 
                                                     & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                        << 6U)) 
                                                    | ((0x300000U 
                                                        & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                           >> 2U)) 
                                                       | ((0xff000U 
                                                           & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                              << 4U)) 
                                                          | ((0xc00U 
                                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                 >> 4U)) 
                                                             | ((0x3fcU 
                                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                    << 2U)) 
                                                                | (3U 
                                                                   & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                      >> 6U)))))))
                                                    : (IData)(
                                                              vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                              [0xaU]))) 
                                   != vlSelf->tb_dehazing__DOT__ed
                                   [0xaU])))) {
            VL_WRITEF("expected=%x actual=%x\n",30,
                      vlSelf->tb_dehazing__DOT__ed[0xaU],
                      30,(0x3fffffffU & ((1U & (IData)(
                                                       (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                        [0xaU] 
                                                        >> 0x21U)))
                                          ? ((0x3fc00000U 
                                              & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                 << 6U)) 
                                             | ((0x300000U 
                                                 & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                    >> 2U)) 
                                                | ((0xff000U 
                                                    & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                       << 4U)) 
                                                   | ((0xc00U 
                                                       & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                          >> 4U)) 
                                                      | ((0x3fcU 
                                                          & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                             << 2U)) 
                                                         | (3U 
                                                            & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                               >> 6U)))))))
                                          : (IData)(
                                                    vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                    [0xaU]))));
            __Vtask_tb_dehazing__DOT__fail__117__reason = 
                std::string{"ordered raw/processed pixel or frame mode"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__117__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__110__reset_i) 
                           & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                          & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__110__ready_i))) 
                         & ((((QData)((IData)((1U & (IData)(
                                                            (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                             [0xaU] 
                                                             >> 0x1eU))))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((IData)(
                                                                    (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                     [0xaU] 
                                                                     >> 0x20U)) 
                                                            << 0x1fU) 
                                                           | ((0x40000000U 
                                                               & ((IData)(
                                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                           [0xaU] 
                                                                           >> 0x1fU)) 
                                                                  << 0x1eU)) 
                                                              | (0x3fffffffU 
                                                                 & ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                     ? 
                                                                    ((0x3fc00000U 
                                                                      & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                         << 6U)) 
                                                                     | ((0x300000U 
                                                                         & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                            >> 2U)) 
                                                                        | ((0xff000U 
                                                                            & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                               << 4U)) 
                                                                           | ((0xc00U 
                                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                              | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                     : (IData)(
                                                                               vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                               [0xaU])))))))) 
                            != vlSelf->tb_dehazing__DOT__last_output)))) {
            __Vtask_tb_dehazing__DOT__fail__118__reason = 
                std::string{"output changed while stalled (including mode changes)"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__118__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        vlSelf->tb_dehazing__DOT__last_output = (((QData)((IData)(
                                                                  (1U 
                                                                   & (IData)(
                                                                             (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                              [0xaU] 
                                                                              >> 0x1eU))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   (((IData)(
                                                                             (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                              [0xaU] 
                                                                              >> 0x20U)) 
                                                                     << 0x1fU) 
                                                                    | ((0x40000000U 
                                                                        & ((IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x1fU)) 
                                                                           << 0x1eU)) 
                                                                       | (0x3fffffffU 
                                                                          & ((1U 
                                                                              & (IData)(
                                                                                (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU] 
                                                                                >> 0x21U)))
                                                                              ? 
                                                                             ((0x3fc00000U 
                                                                               & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 6U)) 
                                                                              | ((0x300000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 2U)) 
                                                                                | ((0xff000U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 4U)) 
                                                                                | ((0xc00U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 4U)) 
                                                                                | ((0x3fcU 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                << 2U)) 
                                                                                | (3U 
                                                                                & (vlSelf->tb_dehazing__DOT__dut__DOT__p_gamma 
                                                                                >> 6U)))))))
                                                                              : (IData)(
                                                                                vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                                                [0xaU]))))))));
        vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__110__reset_i;
        vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                            + vlSelf->tb_dehazing__DOT__checks);
        tb_dehazing__DOT__i = ((IData)(1U) + tb_dehazing__DOT__i);
    }
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       153);
    vlSelf->tb_dehazing__DOT__ar = 0U;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       153);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       153);
    vlSelf->tb_dehazing__DOT__ar = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__119__expected = 0xdcU;
    __Vtask_tb_dehazing__DOT__estimator_case__119__pixel_i = 0xc86432U;
    __Vtask_tb_dehazing__DOT__estimator_case__119__en_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__119__sof_i = 0U;
    __Vtask_tb_dehazing__DOT__estimator_case__119__valid_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       114);
    vlSelf->tb_dehazing__DOT__av = __Vtask_tb_dehazing__DOT__estimator_case__119__valid_i;
    vlSelf->tb_dehazing__DOT__aso = __Vtask_tb_dehazing__DOT__estimator_case__119__sof_i;
    vlSelf->tb_dehazing__DOT__ae = __Vtask_tb_dehazing__DOT__estimator_case__119__en_i;
    vlSelf->tb_dehazing__DOT__ap = __Vtask_tb_dehazing__DOT__estimator_case__119__pixel_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       115);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       115);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__aa) 
                     != (0xffU & __Vtask_tb_dehazing__DOT__estimator_case__119__expected)))) {
        __Vtask_tb_dehazing__DOT__fail__120__reason = 
            std::string{"atmospheric valid SOF / old-A convention"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__120__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    __Vtask_tb_dehazing__DOT__estimator_case__121__expected = 0xdcU;
    __Vtask_tb_dehazing__DOT__estimator_case__121__pixel_i = 0xffffffU;
    __Vtask_tb_dehazing__DOT__estimator_case__121__en_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__121__sof_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__121__valid_i = 0U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       114);
    vlSelf->tb_dehazing__DOT__av = __Vtask_tb_dehazing__DOT__estimator_case__121__valid_i;
    vlSelf->tb_dehazing__DOT__aso = __Vtask_tb_dehazing__DOT__estimator_case__121__sof_i;
    vlSelf->tb_dehazing__DOT__ae = __Vtask_tb_dehazing__DOT__estimator_case__121__en_i;
    vlSelf->tb_dehazing__DOT__ap = __Vtask_tb_dehazing__DOT__estimator_case__121__pixel_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       115);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       115);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__aa) 
                     != (0xffU & __Vtask_tb_dehazing__DOT__estimator_case__121__expected)))) {
        __Vtask_tb_dehazing__DOT__fail__122__reason = 
            std::string{"atmospheric valid SOF / old-A convention"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__122__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    __Vtask_tb_dehazing__DOT__estimator_case__123__expected = 0xdcU;
    __Vtask_tb_dehazing__DOT__estimator_case__123__pixel_i = 0xffffffU;
    __Vtask_tb_dehazing__DOT__estimator_case__123__en_i = 0U;
    __Vtask_tb_dehazing__DOT__estimator_case__123__sof_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__123__valid_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       114);
    vlSelf->tb_dehazing__DOT__av = __Vtask_tb_dehazing__DOT__estimator_case__123__valid_i;
    vlSelf->tb_dehazing__DOT__aso = __Vtask_tb_dehazing__DOT__estimator_case__123__sof_i;
    vlSelf->tb_dehazing__DOT__ae = __Vtask_tb_dehazing__DOT__estimator_case__123__en_i;
    vlSelf->tb_dehazing__DOT__ap = __Vtask_tb_dehazing__DOT__estimator_case__123__pixel_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       115);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       115);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__aa) 
                     != (0xffU & __Vtask_tb_dehazing__DOT__estimator_case__123__expected)))) {
        __Vtask_tb_dehazing__DOT__fail__124__reason = 
            std::string{"atmospheric valid SOF / old-A convention"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__124__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    __Vtask_tb_dehazing__DOT__estimator_case__125__expected = 0xdaU;
    __Vtask_tb_dehazing__DOT__estimator_case__125__pixel_i = 0xffffffU;
    __Vtask_tb_dehazing__DOT__estimator_case__125__en_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__125__sof_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__125__valid_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       114);
    vlSelf->tb_dehazing__DOT__av = __Vtask_tb_dehazing__DOT__estimator_case__125__valid_i;
    vlSelf->tb_dehazing__DOT__aso = __Vtask_tb_dehazing__DOT__estimator_case__125__sof_i;
    vlSelf->tb_dehazing__DOT__ae = __Vtask_tb_dehazing__DOT__estimator_case__125__en_i;
    vlSelf->tb_dehazing__DOT__ap = __Vtask_tb_dehazing__DOT__estimator_case__125__pixel_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       115);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       115);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__aa) 
                     != (0xffU & __Vtask_tb_dehazing__DOT__estimator_case__125__expected)))) {
        __Vtask_tb_dehazing__DOT__fail__126__reason = 
            std::string{"atmospheric valid SOF / old-A convention"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__126__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    __Vtask_tb_dehazing__DOT__estimator_case__127__expected = 0xdaU;
    __Vtask_tb_dehazing__DOT__estimator_case__127__pixel_i = 0xffffffU;
    __Vtask_tb_dehazing__DOT__estimator_case__127__en_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__127__sof_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__127__valid_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       114);
    vlSelf->tb_dehazing__DOT__av = __Vtask_tb_dehazing__DOT__estimator_case__127__valid_i;
    vlSelf->tb_dehazing__DOT__aso = __Vtask_tb_dehazing__DOT__estimator_case__127__sof_i;
    vlSelf->tb_dehazing__DOT__ae = __Vtask_tb_dehazing__DOT__estimator_case__127__en_i;
    vlSelf->tb_dehazing__DOT__ap = __Vtask_tb_dehazing__DOT__estimator_case__127__pixel_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       115);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       115);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__aa) 
                     != (0xffU & __Vtask_tb_dehazing__DOT__estimator_case__127__expected)))) {
        __Vtask_tb_dehazing__DOT__fail__128__reason = 
            std::string{"atmospheric valid SOF / old-A convention"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__128__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    __Vtask_tb_dehazing__DOT__estimator_case__129__expected = 0xdaU;
    __Vtask_tb_dehazing__DOT__estimator_case__129__pixel_i = 0x283214U;
    __Vtask_tb_dehazing__DOT__estimator_case__129__en_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__129__sof_i = 0U;
    __Vtask_tb_dehazing__DOT__estimator_case__129__valid_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       114);
    vlSelf->tb_dehazing__DOT__av = __Vtask_tb_dehazing__DOT__estimator_case__129__valid_i;
    vlSelf->tb_dehazing__DOT__aso = __Vtask_tb_dehazing__DOT__estimator_case__129__sof_i;
    vlSelf->tb_dehazing__DOT__ae = __Vtask_tb_dehazing__DOT__estimator_case__129__en_i;
    vlSelf->tb_dehazing__DOT__ap = __Vtask_tb_dehazing__DOT__estimator_case__129__pixel_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       115);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       115);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__aa) 
                     != (0xffU & __Vtask_tb_dehazing__DOT__estimator_case__129__expected)))) {
        __Vtask_tb_dehazing__DOT__fail__130__reason = 
            std::string{"atmospheric valid SOF / old-A convention"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__130__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    __Vtask_tb_dehazing__DOT__estimator_case__131__expected = 0xdaU;
    __Vtask_tb_dehazing__DOT__estimator_case__131__pixel_i = 0xffffffU;
    __Vtask_tb_dehazing__DOT__estimator_case__131__en_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__131__sof_i = 1U;
    __Vtask_tb_dehazing__DOT__estimator_case__131__valid_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       114);
    vlSelf->tb_dehazing__DOT__av = __Vtask_tb_dehazing__DOT__estimator_case__131__valid_i;
    vlSelf->tb_dehazing__DOT__aso = __Vtask_tb_dehazing__DOT__estimator_case__131__sof_i;
    vlSelf->tb_dehazing__DOT__ae = __Vtask_tb_dehazing__DOT__estimator_case__131__en_i;
    vlSelf->tb_dehazing__DOT__ap = __Vtask_tb_dehazing__DOT__estimator_case__131__pixel_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       115);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                       115);
    if (VL_UNLIKELY(((IData)(vlSelf->tb_dehazing__DOT__aa) 
                     != (0xffU & __Vtask_tb_dehazing__DOT__estimator_case__131__expected)))) {
        __Vtask_tb_dehazing__DOT__fail__132__reason = 
            std::string{"atmospheric valid SOF / old-A convention"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__132__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    VL_WRITEF("CORE_PASS seed=%0d accepted=%0d edge_checks=%0d\n",
              32,vlSelf->tb_dehazing__DOT__seed,32,
              vlSelf->tb_dehazing__DOT__accepted,32,
              vlSelf->tb_dehazing__DOT__checks);
    VL_FINISH_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 162, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dehazing___024root___dump_triggers__act(Vtb_dehazing___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_dehazing___024root___eval_triggers__act(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_dehazing__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_dehazing__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_dehazing__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, (((~ (IData)(vlSelf->tb_dehazing__DOT__ar)) 
                                      & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__ar__0)) 
                                     | ((IData)(vlSelf->tb_dehazing__DOT__clk) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0)))));
    vlSelf->__VactTriggered.set(3U, ((~ (IData)(vlSelf->tb_dehazing__DOT__clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0)));
    vlSelf->__VactTriggered.set(4U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0 
        = vlSelf->tb_dehazing__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__rst_n__0 
        = vlSelf->tb_dehazing__DOT__rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_dehazing__DOT__ar__0 
        = vlSelf->tb_dehazing__DOT__ar;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_dehazing___024root___dump_triggers__act(vlSelf);
    }
#endif
}
