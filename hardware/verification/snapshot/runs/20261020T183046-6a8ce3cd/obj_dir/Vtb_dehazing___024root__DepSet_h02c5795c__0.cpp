// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dehazing.h for the primary calling header

#include "Vtb_dehazing__pch.h"
#include "Vtb_dehazing__Syms.h"
#include "Vtb_dehazing___024root.h"

VlCoroutine Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__0(Vtb_dehazing___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_dehazing__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dehazing___024root___eval_initial__TOP__Vtiming__0__0\n"); );
    // Init
    IData/*31:0*/ tb_dehazing__DOT__rng;
    tb_dehazing__DOT__rng = 0;
    IData/*31:0*/ tb_dehazing__DOT__frame;
    tb_dehazing__DOT__frame = 0;
    IData/*31:0*/ tb_dehazing__DOT__i;
    tb_dehazing__DOT__i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__0__ready_i;
    __Vtask_tb_dehazing__DOT__tick__0__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__0__valid_i;
    __Vtask_tb_dehazing__DOT__tick__0__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__0__sop_i;
    __Vtask_tb_dehazing__DOT__tick__0__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__0__eop_i;
    __Vtask_tb_dehazing__DOT__tick__0__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__0__mode_i;
    __Vtask_tb_dehazing__DOT__tick__0__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__0__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__0__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__0__reset_i;
    __Vtask_tb_dehazing__DOT__tick__0__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__r;
    __Vtask_tb_dehazing__DOT__tick__0__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__g;
    __Vtask_tb_dehazing__DOT__tick__0__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__b;
    __Vtask_tb_dehazing__DOT__tick__0__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__hi;
    __Vtask_tb_dehazing__DOT__tick__0__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__lo;
    __Vtask_tb_dehazing__DOT__tick__0__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__t;
    __Vtask_tb_dehazing__DOT__tick__0__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__inv;
    __Vtask_tb_dehazing__DOT__tick__0__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__a_used;
    __Vtask_tb_dehazing__DOT__tick__0__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__jr;
    __Vtask_tb_dehazing__DOT__tick__0__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__jg;
    __Vtask_tb_dehazing__DOT__tick__0__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__0__jb;
    __Vtask_tb_dehazing__DOT__tick__0__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__0__gr;
    __Vtask_tb_dehazing__DOT__tick__0__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__0__gg;
    __Vtask_tb_dehazing__DOT__tick__0__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__0__gb;
    __Vtask_tb_dehazing__DOT__tick__0__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__0__processed;
    __Vtask_tb_dehazing__DOT__tick__0__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__0__selected;
    __Vtask_tb_dehazing__DOT__tick__0__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__1__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__1__value;
    __Vfunc_tb_dehazing__DOT__clamp__1__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__2__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__2__value;
    __Vfunc_tb_dehazing__DOT__clamp__2__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__3__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__3__value;
    __Vfunc_tb_dehazing__DOT__clamp__3__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__4__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__5__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__6__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__7__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__8__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__9__ready_i;
    __Vtask_tb_dehazing__DOT__tick__9__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__9__valid_i;
    __Vtask_tb_dehazing__DOT__tick__9__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__9__sop_i;
    __Vtask_tb_dehazing__DOT__tick__9__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__9__eop_i;
    __Vtask_tb_dehazing__DOT__tick__9__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__9__mode_i;
    __Vtask_tb_dehazing__DOT__tick__9__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__9__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__9__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__9__reset_i;
    __Vtask_tb_dehazing__DOT__tick__9__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__r;
    __Vtask_tb_dehazing__DOT__tick__9__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__g;
    __Vtask_tb_dehazing__DOT__tick__9__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__b;
    __Vtask_tb_dehazing__DOT__tick__9__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__hi;
    __Vtask_tb_dehazing__DOT__tick__9__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__lo;
    __Vtask_tb_dehazing__DOT__tick__9__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__t;
    __Vtask_tb_dehazing__DOT__tick__9__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__inv;
    __Vtask_tb_dehazing__DOT__tick__9__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__a_used;
    __Vtask_tb_dehazing__DOT__tick__9__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__jr;
    __Vtask_tb_dehazing__DOT__tick__9__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__jg;
    __Vtask_tb_dehazing__DOT__tick__9__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__9__jb;
    __Vtask_tb_dehazing__DOT__tick__9__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__9__gr;
    __Vtask_tb_dehazing__DOT__tick__9__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__9__gg;
    __Vtask_tb_dehazing__DOT__tick__9__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__9__gb;
    __Vtask_tb_dehazing__DOT__tick__9__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__9__processed;
    __Vtask_tb_dehazing__DOT__tick__9__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__9__selected;
    __Vtask_tb_dehazing__DOT__tick__9__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__10__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__10__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__10__value;
    __Vfunc_tb_dehazing__DOT__clamp__10__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__11__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__11__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__11__value;
    __Vfunc_tb_dehazing__DOT__clamp__11__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__12__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__12__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__12__value;
    __Vfunc_tb_dehazing__DOT__clamp__12__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__13__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__14__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__15__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__16__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__17__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__18__ready_i;
    __Vtask_tb_dehazing__DOT__tick__18__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__18__valid_i;
    __Vtask_tb_dehazing__DOT__tick__18__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__18__sop_i;
    __Vtask_tb_dehazing__DOT__tick__18__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__18__eop_i;
    __Vtask_tb_dehazing__DOT__tick__18__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__18__mode_i;
    __Vtask_tb_dehazing__DOT__tick__18__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__18__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__18__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    __Vtask_tb_dehazing__DOT__tick__18__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__r;
    __Vtask_tb_dehazing__DOT__tick__18__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__g;
    __Vtask_tb_dehazing__DOT__tick__18__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__b;
    __Vtask_tb_dehazing__DOT__tick__18__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__hi;
    __Vtask_tb_dehazing__DOT__tick__18__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__lo;
    __Vtask_tb_dehazing__DOT__tick__18__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__t;
    __Vtask_tb_dehazing__DOT__tick__18__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__inv;
    __Vtask_tb_dehazing__DOT__tick__18__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__a_used;
    __Vtask_tb_dehazing__DOT__tick__18__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__jr;
    __Vtask_tb_dehazing__DOT__tick__18__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__jg;
    __Vtask_tb_dehazing__DOT__tick__18__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__18__jb;
    __Vtask_tb_dehazing__DOT__tick__18__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__18__gr;
    __Vtask_tb_dehazing__DOT__tick__18__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__18__gg;
    __Vtask_tb_dehazing__DOT__tick__18__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__18__gb;
    __Vtask_tb_dehazing__DOT__tick__18__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__18__processed;
    __Vtask_tb_dehazing__DOT__tick__18__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__18__selected;
    __Vtask_tb_dehazing__DOT__tick__18__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__19__value;
    __Vfunc_tb_dehazing__DOT__clamp__19__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__20__value;
    __Vfunc_tb_dehazing__DOT__clamp__20__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__21__value;
    __Vfunc_tb_dehazing__DOT__clamp__21__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__22__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__23__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__24__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__25__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__26__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__27__ready_i;
    __Vtask_tb_dehazing__DOT__tick__27__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__27__valid_i;
    __Vtask_tb_dehazing__DOT__tick__27__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__27__sop_i;
    __Vtask_tb_dehazing__DOT__tick__27__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__27__eop_i;
    __Vtask_tb_dehazing__DOT__tick__27__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__27__mode_i;
    __Vtask_tb_dehazing__DOT__tick__27__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__27__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__27__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__27__reset_i;
    __Vtask_tb_dehazing__DOT__tick__27__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__r;
    __Vtask_tb_dehazing__DOT__tick__27__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__g;
    __Vtask_tb_dehazing__DOT__tick__27__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__b;
    __Vtask_tb_dehazing__DOT__tick__27__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__hi;
    __Vtask_tb_dehazing__DOT__tick__27__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__lo;
    __Vtask_tb_dehazing__DOT__tick__27__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__t;
    __Vtask_tb_dehazing__DOT__tick__27__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__inv;
    __Vtask_tb_dehazing__DOT__tick__27__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__a_used;
    __Vtask_tb_dehazing__DOT__tick__27__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__jr;
    __Vtask_tb_dehazing__DOT__tick__27__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__jg;
    __Vtask_tb_dehazing__DOT__tick__27__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__27__jb;
    __Vtask_tb_dehazing__DOT__tick__27__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__27__gr;
    __Vtask_tb_dehazing__DOT__tick__27__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__27__gg;
    __Vtask_tb_dehazing__DOT__tick__27__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__27__gb;
    __Vtask_tb_dehazing__DOT__tick__27__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__27__processed;
    __Vtask_tb_dehazing__DOT__tick__27__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__27__selected;
    __Vtask_tb_dehazing__DOT__tick__27__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__28__value;
    __Vfunc_tb_dehazing__DOT__clamp__28__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__29__value;
    __Vfunc_tb_dehazing__DOT__clamp__29__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__30__value;
    __Vfunc_tb_dehazing__DOT__clamp__30__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__31__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__32__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__33__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__34__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__35__reason;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__next_random__36__Vfuncout;
    __Vfunc_tb_dehazing__DOT__next_random__36__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__next_random__36__x;
    __Vfunc_tb_dehazing__DOT__next_random__36__x = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__37__ready_i;
    __Vtask_tb_dehazing__DOT__tick__37__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__37__valid_i;
    __Vtask_tb_dehazing__DOT__tick__37__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__37__sop_i;
    __Vtask_tb_dehazing__DOT__tick__37__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__37__eop_i;
    __Vtask_tb_dehazing__DOT__tick__37__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__37__mode_i;
    __Vtask_tb_dehazing__DOT__tick__37__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__37__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__37__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__37__reset_i;
    __Vtask_tb_dehazing__DOT__tick__37__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__r;
    __Vtask_tb_dehazing__DOT__tick__37__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__g;
    __Vtask_tb_dehazing__DOT__tick__37__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__b;
    __Vtask_tb_dehazing__DOT__tick__37__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__hi;
    __Vtask_tb_dehazing__DOT__tick__37__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__lo;
    __Vtask_tb_dehazing__DOT__tick__37__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__t;
    __Vtask_tb_dehazing__DOT__tick__37__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__inv;
    __Vtask_tb_dehazing__DOT__tick__37__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__a_used;
    __Vtask_tb_dehazing__DOT__tick__37__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__jr;
    __Vtask_tb_dehazing__DOT__tick__37__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__jg;
    __Vtask_tb_dehazing__DOT__tick__37__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__37__jb;
    __Vtask_tb_dehazing__DOT__tick__37__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__37__gr;
    __Vtask_tb_dehazing__DOT__tick__37__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__37__gg;
    __Vtask_tb_dehazing__DOT__tick__37__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__37__gb;
    __Vtask_tb_dehazing__DOT__tick__37__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__37__processed;
    __Vtask_tb_dehazing__DOT__tick__37__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__37__selected;
    __Vtask_tb_dehazing__DOT__tick__37__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__38__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__38__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__38__value;
    __Vfunc_tb_dehazing__DOT__clamp__38__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__39__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__39__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__39__value;
    __Vfunc_tb_dehazing__DOT__clamp__39__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__40__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__40__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__40__value;
    __Vfunc_tb_dehazing__DOT__clamp__40__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__41__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__42__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__43__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__44__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__45__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__46__ready_i;
    __Vtask_tb_dehazing__DOT__tick__46__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__46__valid_i;
    __Vtask_tb_dehazing__DOT__tick__46__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__46__sop_i;
    __Vtask_tb_dehazing__DOT__tick__46__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__46__eop_i;
    __Vtask_tb_dehazing__DOT__tick__46__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__46__mode_i;
    __Vtask_tb_dehazing__DOT__tick__46__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__46__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__46__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__46__reset_i;
    __Vtask_tb_dehazing__DOT__tick__46__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__r;
    __Vtask_tb_dehazing__DOT__tick__46__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__g;
    __Vtask_tb_dehazing__DOT__tick__46__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__b;
    __Vtask_tb_dehazing__DOT__tick__46__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__hi;
    __Vtask_tb_dehazing__DOT__tick__46__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__lo;
    __Vtask_tb_dehazing__DOT__tick__46__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__t;
    __Vtask_tb_dehazing__DOT__tick__46__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__inv;
    __Vtask_tb_dehazing__DOT__tick__46__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__a_used;
    __Vtask_tb_dehazing__DOT__tick__46__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__jr;
    __Vtask_tb_dehazing__DOT__tick__46__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__jg;
    __Vtask_tb_dehazing__DOT__tick__46__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__46__jb;
    __Vtask_tb_dehazing__DOT__tick__46__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__46__gr;
    __Vtask_tb_dehazing__DOT__tick__46__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__46__gg;
    __Vtask_tb_dehazing__DOT__tick__46__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__46__gb;
    __Vtask_tb_dehazing__DOT__tick__46__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__46__processed;
    __Vtask_tb_dehazing__DOT__tick__46__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__46__selected;
    __Vtask_tb_dehazing__DOT__tick__46__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__47__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__47__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__47__value;
    __Vfunc_tb_dehazing__DOT__clamp__47__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__48__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__48__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__48__value;
    __Vfunc_tb_dehazing__DOT__clamp__48__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__49__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__49__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__49__value;
    __Vfunc_tb_dehazing__DOT__clamp__49__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__50__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__51__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__52__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__53__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__54__reason;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__next_random__55__Vfuncout;
    __Vfunc_tb_dehazing__DOT__next_random__55__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__next_random__55__x;
    __Vfunc_tb_dehazing__DOT__next_random__55__x = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__56__ready_i;
    __Vtask_tb_dehazing__DOT__tick__56__ready_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__56__valid_i;
    __Vtask_tb_dehazing__DOT__tick__56__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__56__sop_i;
    __Vtask_tb_dehazing__DOT__tick__56__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__56__eop_i;
    __Vtask_tb_dehazing__DOT__tick__56__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__56__mode_i;
    __Vtask_tb_dehazing__DOT__tick__56__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__56__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__56__pixel_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__56__reset_i;
    __Vtask_tb_dehazing__DOT__tick__56__reset_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__r;
    __Vtask_tb_dehazing__DOT__tick__56__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__g;
    __Vtask_tb_dehazing__DOT__tick__56__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__b;
    __Vtask_tb_dehazing__DOT__tick__56__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__hi;
    __Vtask_tb_dehazing__DOT__tick__56__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__lo;
    __Vtask_tb_dehazing__DOT__tick__56__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__t;
    __Vtask_tb_dehazing__DOT__tick__56__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__inv;
    __Vtask_tb_dehazing__DOT__tick__56__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__a_used;
    __Vtask_tb_dehazing__DOT__tick__56__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__jr;
    __Vtask_tb_dehazing__DOT__tick__56__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__jg;
    __Vtask_tb_dehazing__DOT__tick__56__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__56__jb;
    __Vtask_tb_dehazing__DOT__tick__56__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__56__gr;
    __Vtask_tb_dehazing__DOT__tick__56__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__56__gg;
    __Vtask_tb_dehazing__DOT__tick__56__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__56__gb;
    __Vtask_tb_dehazing__DOT__tick__56__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__56__processed;
    __Vtask_tb_dehazing__DOT__tick__56__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__56__selected;
    __Vtask_tb_dehazing__DOT__tick__56__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__57__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__57__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__57__value;
    __Vfunc_tb_dehazing__DOT__clamp__57__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__58__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__58__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__58__value;
    __Vfunc_tb_dehazing__DOT__clamp__58__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__59__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__59__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__59__value;
    __Vfunc_tb_dehazing__DOT__clamp__59__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__60__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__61__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__62__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__63__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__64__reason;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__65__valid_i;
    __Vtask_tb_dehazing__DOT__tick__65__valid_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__65__sop_i;
    __Vtask_tb_dehazing__DOT__tick__65__sop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__65__eop_i;
    __Vtask_tb_dehazing__DOT__tick__65__eop_i = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__65__mode_i;
    __Vtask_tb_dehazing__DOT__tick__65__mode_i = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__65__pixel_i;
    __Vtask_tb_dehazing__DOT__tick__65__pixel_i = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__r;
    __Vtask_tb_dehazing__DOT__tick__65__r = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__g;
    __Vtask_tb_dehazing__DOT__tick__65__g = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__b;
    __Vtask_tb_dehazing__DOT__tick__65__b = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__hi;
    __Vtask_tb_dehazing__DOT__tick__65__hi = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__lo;
    __Vtask_tb_dehazing__DOT__tick__65__lo = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__t;
    __Vtask_tb_dehazing__DOT__tick__65__t = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__inv;
    __Vtask_tb_dehazing__DOT__tick__65__inv = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__a_used;
    __Vtask_tb_dehazing__DOT__tick__65__a_used = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__jr;
    __Vtask_tb_dehazing__DOT__tick__65__jr = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__jg;
    __Vtask_tb_dehazing__DOT__tick__65__jg = 0;
    IData/*31:0*/ __Vtask_tb_dehazing__DOT__tick__65__jb;
    __Vtask_tb_dehazing__DOT__tick__65__jb = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__65__gr;
    __Vtask_tb_dehazing__DOT__tick__65__gr = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__65__gg;
    __Vtask_tb_dehazing__DOT__tick__65__gg = 0;
    CData/*7:0*/ __Vtask_tb_dehazing__DOT__tick__65__gb;
    __Vtask_tb_dehazing__DOT__tick__65__gb = 0;
    IData/*29:0*/ __Vtask_tb_dehazing__DOT__tick__65__processed;
    __Vtask_tb_dehazing__DOT__tick__65__processed = 0;
    CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__65__selected;
    __Vtask_tb_dehazing__DOT__tick__65__selected = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__66__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__66__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__66__value;
    __Vfunc_tb_dehazing__DOT__clamp__66__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__67__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__67__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__67__value;
    __Vfunc_tb_dehazing__DOT__clamp__67__value = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__68__Vfuncout;
    __Vfunc_tb_dehazing__DOT__clamp__68__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_dehazing__DOT__clamp__68__value;
    __Vfunc_tb_dehazing__DOT__clamp__68__value = 0;
    std::string __Vtask_tb_dehazing__DOT__fail__69__reason;
    std::string __Vtask_tb_dehazing__DOT__fail__70__reason;
    VlWide<5>/*159:0*/ __Vtemp_1;
    VlWide<7>/*223:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x64617461U;
    __Vtemp_1[2U] = 0x6c75745fU;
    __Vtemp_1[3U] = 0x6d6d615fU;
    __Vtemp_1[4U] = 0x6761U;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                 ,  &(vlSelf->tb_dehazing__DOT__gamma_rom)
                 , 0, ~0ULL);
    __Vtemp_2[0U] = 0x2e686578U;
    __Vtemp_2[1U] = 0x64617461U;
    __Vtemp_2[2U] = 0x6c75745fU;
    __Vtemp_2[3U] = 0x696f6e5fU;
    __Vtemp_2[4U] = 0x6d697373U;
    __Vtemp_2[5U] = 0x72616e73U;
    __Vtemp_2[6U] = 0x74U;
    VL_READMEM_N(true, 10, 65536, 0, VL_CVT_PACK_STR_NW(7, __Vtemp_2)
                 ,  &(vlSelf->tb_dehazing__DOT__transmission_rom)
                 , 0, ~0ULL);
    if ((! VL_VALUEPLUSARGS_INI(32, std::string{"SEED=%d"}, 
                                vlSelf->tb_dehazing__DOT__seed))) {
        vlSelf->tb_dehazing__DOT__seed = 0U;
    }
    tb_dehazing__DOT__rng = ((IData)(0x12345678U) + vlSelf->tb_dehazing__DOT__seed);
    __Vtask_tb_dehazing__DOT__tick__0__reset_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__0__pixel_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__0__mode_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__0__eop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__0__sop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__0__valid_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__0__ready_i = 0U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__0__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__0__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__0__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__0__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__0__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__0__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__0__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__0__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__0__ready_i) {
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
            if (__Vtask_tb_dehazing__DOT__tick__0__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__0__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__0__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__0__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__0__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__0__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__0__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__0__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__0__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__0__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__0__r, __Vtask_tb_dehazing__DOT__tick__0__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__0__r, __Vtask_tb_dehazing__DOT__tick__0__b)
                            ? __Vtask_tb_dehazing__DOT__tick__0__r
                            : __Vtask_tb_dehazing__DOT__tick__0__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__0__g, __Vtask_tb_dehazing__DOT__tick__0__b)
                            ? __Vtask_tb_dehazing__DOT__tick__0__g
                            : __Vtask_tb_dehazing__DOT__tick__0__b));
                __Vtask_tb_dehazing__DOT__tick__0__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__0__r, __Vtask_tb_dehazing__DOT__tick__0__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__0__r, __Vtask_tb_dehazing__DOT__tick__0__b)
                            ? __Vtask_tb_dehazing__DOT__tick__0__r
                            : __Vtask_tb_dehazing__DOT__tick__0__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__0__g, __Vtask_tb_dehazing__DOT__tick__0__b)
                            ? __Vtask_tb_dehazing__DOT__tick__0__g
                            : __Vtask_tb_dehazing__DOT__tick__0__b));
                __Vtask_tb_dehazing__DOT__tick__0__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__0__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__0__lo))];
                __Vtask_tb_dehazing__DOT__tick__0__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__0__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__0__t)) {
                    __Vtask_tb_dehazing__DOT__tick__0__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__0__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__0__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__0__t));
                __Vtask_tb_dehazing__DOT__tick__0__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__0__inv);
                __Vtask_tb_dehazing__DOT__tick__0__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__0__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__0__selected 
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
                    __Vtask_tb_dehazing__DOT__tick__0__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__0__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__0__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__0__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__1__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__0__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__0__a_used), __Vtask_tb_dehazing__DOT__tick__0__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__0__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__1__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__1__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__1__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__1__value));
                __Vtask_tb_dehazing__DOT__tick__0__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__1__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__2__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__0__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__0__a_used), __Vtask_tb_dehazing__DOT__tick__0__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__0__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__2__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__2__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__2__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__2__value));
                __Vtask_tb_dehazing__DOT__tick__0__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__2__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__3__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__0__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__0__a_used), __Vtask_tb_dehazing__DOT__tick__0__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__0__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__3__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__3__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__3__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__3__value));
                __Vtask_tb_dehazing__DOT__tick__0__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__3__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__0__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__0__jr)];
                __Vtask_tb_dehazing__DOT__tick__0__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__0__jg)];
                __Vtask_tb_dehazing__DOT__tick__0__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__0__jb)];
                __Vtask_tb_dehazing__DOT__tick__0__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__0__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__0__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__0__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__0__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__0__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__0__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__0__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__0__processed
                      : __Vtask_tb_dehazing__DOT__tick__0__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__0__mode_i;
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
        __Vtask_tb_dehazing__DOT__fail__4__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__4__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__5__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__5__reason),
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
        __Vtask_tb_dehazing__DOT__fail__6__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__6__reason),
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
        __Vtask_tb_dehazing__DOT__fail__7__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__7__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__0__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__0__ready_i))) 
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
        __Vtask_tb_dehazing__DOT__fail__8__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__8__reason),
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
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__0__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    __Vtask_tb_dehazing__DOT__tick__9__reset_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__9__pixel_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__9__mode_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__9__eop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__9__sop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__9__valid_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__9__ready_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__9__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__9__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__9__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__9__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__9__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__9__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__9__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__9__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__9__ready_i) {
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
            if (__Vtask_tb_dehazing__DOT__tick__9__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__9__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__9__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__9__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__9__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__9__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__9__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__9__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__9__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__9__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__9__r, __Vtask_tb_dehazing__DOT__tick__9__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__9__r, __Vtask_tb_dehazing__DOT__tick__9__b)
                            ? __Vtask_tb_dehazing__DOT__tick__9__r
                            : __Vtask_tb_dehazing__DOT__tick__9__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__9__g, __Vtask_tb_dehazing__DOT__tick__9__b)
                            ? __Vtask_tb_dehazing__DOT__tick__9__g
                            : __Vtask_tb_dehazing__DOT__tick__9__b));
                __Vtask_tb_dehazing__DOT__tick__9__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__9__r, __Vtask_tb_dehazing__DOT__tick__9__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__9__r, __Vtask_tb_dehazing__DOT__tick__9__b)
                            ? __Vtask_tb_dehazing__DOT__tick__9__r
                            : __Vtask_tb_dehazing__DOT__tick__9__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__9__g, __Vtask_tb_dehazing__DOT__tick__9__b)
                            ? __Vtask_tb_dehazing__DOT__tick__9__g
                            : __Vtask_tb_dehazing__DOT__tick__9__b));
                __Vtask_tb_dehazing__DOT__tick__9__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__9__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__9__lo))];
                __Vtask_tb_dehazing__DOT__tick__9__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__9__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__9__t)) {
                    __Vtask_tb_dehazing__DOT__tick__9__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__9__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__9__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__9__t));
                __Vtask_tb_dehazing__DOT__tick__9__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__9__inv);
                __Vtask_tb_dehazing__DOT__tick__9__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__9__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__9__selected 
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
                    __Vtask_tb_dehazing__DOT__tick__9__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__9__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__9__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__9__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__10__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__9__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__9__a_used), __Vtask_tb_dehazing__DOT__tick__9__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__9__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__10__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__10__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__10__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__10__value));
                __Vtask_tb_dehazing__DOT__tick__9__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__10__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__11__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__9__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__9__a_used), __Vtask_tb_dehazing__DOT__tick__9__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__9__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__11__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__11__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__11__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__11__value));
                __Vtask_tb_dehazing__DOT__tick__9__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__11__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__12__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__9__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__9__a_used), __Vtask_tb_dehazing__DOT__tick__9__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__9__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__12__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__12__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__12__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__12__value));
                __Vtask_tb_dehazing__DOT__tick__9__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__12__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__9__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__9__jr)];
                __Vtask_tb_dehazing__DOT__tick__9__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__9__jg)];
                __Vtask_tb_dehazing__DOT__tick__9__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__9__jb)];
                __Vtask_tb_dehazing__DOT__tick__9__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__9__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__9__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__9__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__9__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__9__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__9__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__9__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__9__processed
                      : __Vtask_tb_dehazing__DOT__tick__9__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__9__mode_i;
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
        __Vtask_tb_dehazing__DOT__fail__13__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__13__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__14__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__14__reason),
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
        __Vtask_tb_dehazing__DOT__fail__15__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__15__reason),
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
        __Vtask_tb_dehazing__DOT__fail__16__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__16__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__9__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__9__ready_i))) 
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
        __Vtask_tb_dehazing__DOT__fail__17__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__17__reason),
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
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__9__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    __Vtask_tb_dehazing__DOT__tick__18__reset_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__pixel_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__mode_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__eop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__sop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__valid_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__ready_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__18__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__18__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__18__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__18__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__18__ready_i) {
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
            if (__Vtask_tb_dehazing__DOT__tick__18__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__18__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__18__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__18__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__18__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__18__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__18__lo))];
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__18__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__18__t)) {
                    __Vtask_tb_dehazing__DOT__tick__18__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__18__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__18__t));
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__18__inv);
                __Vtask_tb_dehazing__DOT__tick__18__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__18__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
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
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__18__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__18__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__19__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__19__value));
                __Vtask_tb_dehazing__DOT__tick__18__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__20__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__20__value));
                __Vtask_tb_dehazing__DOT__tick__18__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__21__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__21__value));
                __Vtask_tb_dehazing__DOT__tick__18__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__18__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jr)];
                __Vtask_tb_dehazing__DOT__tick__18__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jg)];
                __Vtask_tb_dehazing__DOT__tick__18__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jb)];
                __Vtask_tb_dehazing__DOT__tick__18__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__18__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__18__processed
                      : __Vtask_tb_dehazing__DOT__tick__18__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
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
        __Vtask_tb_dehazing__DOT__fail__22__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__22__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__23__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__23__reason),
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
        __Vtask_tb_dehazing__DOT__fail__24__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__24__reason),
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
        __Vtask_tb_dehazing__DOT__fail__25__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__25__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__18__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__18__ready_i))) 
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
        __Vtask_tb_dehazing__DOT__fail__26__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__26__reason),
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
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    tb_dehazing__DOT__i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__reset_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__pixel_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__mode_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__eop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__sop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__valid_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__ready_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__18__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__18__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__18__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__18__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__18__ready_i) {
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
            if (__Vtask_tb_dehazing__DOT__tick__18__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__18__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__18__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__18__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__18__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__18__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__18__lo))];
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__18__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__18__t)) {
                    __Vtask_tb_dehazing__DOT__tick__18__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__18__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__18__t));
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__18__inv);
                __Vtask_tb_dehazing__DOT__tick__18__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__18__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
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
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__18__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__18__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__19__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__19__value));
                __Vtask_tb_dehazing__DOT__tick__18__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__20__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__20__value));
                __Vtask_tb_dehazing__DOT__tick__18__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__21__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__21__value));
                __Vtask_tb_dehazing__DOT__tick__18__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__18__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jr)];
                __Vtask_tb_dehazing__DOT__tick__18__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jg)];
                __Vtask_tb_dehazing__DOT__tick__18__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jb)];
                __Vtask_tb_dehazing__DOT__tick__18__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__18__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__18__processed
                      : __Vtask_tb_dehazing__DOT__tick__18__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
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
        __Vtask_tb_dehazing__DOT__fail__22__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__22__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__23__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__23__reason),
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
        __Vtask_tb_dehazing__DOT__fail__24__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__24__reason),
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
        __Vtask_tb_dehazing__DOT__fail__25__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__25__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__18__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__18__ready_i))) 
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
        __Vtask_tb_dehazing__DOT__fail__26__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__26__reason),
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
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    tb_dehazing__DOT__i = 2U;
    __Vtask_tb_dehazing__DOT__tick__18__reset_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__pixel_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__mode_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__eop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__sop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__valid_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__ready_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__18__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__18__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__18__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__18__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__18__ready_i) {
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
            if (__Vtask_tb_dehazing__DOT__tick__18__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__18__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__18__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__18__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__18__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__18__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__18__lo))];
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__18__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__18__t)) {
                    __Vtask_tb_dehazing__DOT__tick__18__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__18__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__18__t));
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__18__inv);
                __Vtask_tb_dehazing__DOT__tick__18__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__18__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
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
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__18__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__18__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__19__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__19__value));
                __Vtask_tb_dehazing__DOT__tick__18__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__20__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__20__value));
                __Vtask_tb_dehazing__DOT__tick__18__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__21__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__21__value));
                __Vtask_tb_dehazing__DOT__tick__18__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__18__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jr)];
                __Vtask_tb_dehazing__DOT__tick__18__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jg)];
                __Vtask_tb_dehazing__DOT__tick__18__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jb)];
                __Vtask_tb_dehazing__DOT__tick__18__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__18__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__18__processed
                      : __Vtask_tb_dehazing__DOT__tick__18__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
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
        __Vtask_tb_dehazing__DOT__fail__22__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__22__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__23__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__23__reason),
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
        __Vtask_tb_dehazing__DOT__fail__24__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__24__reason),
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
        __Vtask_tb_dehazing__DOT__fail__25__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__25__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__18__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__18__ready_i))) 
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
        __Vtask_tb_dehazing__DOT__fail__26__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__26__reason),
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
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    tb_dehazing__DOT__i = 3U;
    __Vtask_tb_dehazing__DOT__tick__18__reset_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__pixel_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__mode_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__eop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__sop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__18__valid_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__18__ready_i = 1U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__18__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__18__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__18__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (__Vtask_tb_dehazing__DOT__tick__18__reset_i) {
        if (__Vtask_tb_dehazing__DOT__tick__18__ready_i) {
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
            if (__Vtask_tb_dehazing__DOT__tick__18__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__18__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__18__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__18__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__18__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__18__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__18__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__18__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__r, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__r
                            : __Vtask_tb_dehazing__DOT__tick__18__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__g, __Vtask_tb_dehazing__DOT__tick__18__b)
                            ? __Vtask_tb_dehazing__DOT__tick__18__g
                            : __Vtask_tb_dehazing__DOT__tick__18__b));
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__18__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__18__lo))];
                __Vtask_tb_dehazing__DOT__tick__18__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__18__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__18__t)) {
                    __Vtask_tb_dehazing__DOT__tick__18__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__18__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__18__t));
                __Vtask_tb_dehazing__DOT__tick__18__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__18__inv);
                __Vtask_tb_dehazing__DOT__tick__18__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__18__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
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
                    __Vtask_tb_dehazing__DOT__tick__18__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__18__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__18__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__18__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__19__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__19__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__19__value));
                __Vtask_tb_dehazing__DOT__tick__18__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__19__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__20__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__20__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__20__value));
                __Vtask_tb_dehazing__DOT__tick__18__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__20__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__21__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__18__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__18__a_used), __Vtask_tb_dehazing__DOT__tick__18__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__18__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__21__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__21__value));
                __Vtask_tb_dehazing__DOT__tick__18__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__21__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__18__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jr)];
                __Vtask_tb_dehazing__DOT__tick__18__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jg)];
                __Vtask_tb_dehazing__DOT__tick__18__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__18__jb)];
                __Vtask_tb_dehazing__DOT__tick__18__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__18__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__18__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__18__processed
                      : __Vtask_tb_dehazing__DOT__tick__18__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__18__mode_i;
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
        __Vtask_tb_dehazing__DOT__fail__22__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__22__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__23__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__23__reason),
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
        __Vtask_tb_dehazing__DOT__fail__24__reason = 
            std::string{"ordered SOP/EOP"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__24__reason),
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
        __Vtask_tb_dehazing__DOT__fail__25__reason = 
            std::string{"ordered raw/processed pixel or frame mode"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__25__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__18__reset_i) 
                       & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                      & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__18__ready_i))) 
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
        __Vtask_tb_dehazing__DOT__fail__26__reason = 
            std::string{"output changed while stalled (including mode changes)"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__26__reason),
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
    vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__18__reset_i;
    vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                        + vlSelf->tb_dehazing__DOT__checks);
    tb_dehazing__DOT__i = 4U;
    tb_dehazing__DOT__frame = 0U;
    while (VL_GTS_III(32, 0x10U, tb_dehazing__DOT__frame)) {
        vlSelf->tb_dehazing__DOT__mode_value = (1U 
                                                & tb_dehazing__DOT__frame);
        __Vtask_tb_dehazing__DOT__tick__27__reset_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__27__pixel_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__mode_i 
            = vlSelf->tb_dehazing__DOT__mode_value;
        __Vtask_tb_dehazing__DOT__tick__27__eop_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__sop_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__27__valid_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__ready_i = 1U;
        co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           45);
        vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__27__ready_i;
        vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__27__valid_i;
        vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__27__sop_i;
        vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__27__eop_i;
        vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__27__pixel_i;
        vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__27__mode_i;
        vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__27__reset_i;
        co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           48);
        if (__Vtask_tb_dehazing__DOT__tick__27__reset_i) {
            if (__Vtask_tb_dehazing__DOT__tick__27__ready_i) {
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
                if (__Vtask_tb_dehazing__DOT__tick__27__valid_i) {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__27__sop_i;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__27__eop_i;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__accepted 
                        = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                    __Vtask_tb_dehazing__DOT__tick__27__r 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 0x16U));
                    __Vtask_tb_dehazing__DOT__tick__27__g 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 0xcU));
                    __Vtask_tb_dehazing__DOT__tick__27__b 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 2U));
                    __Vtask_tb_dehazing__DOT__tick__27__hi 
                        = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__g)
                            ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__r
                                : __Vtask_tb_dehazing__DOT__tick__27__b)
                            : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__g, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__g
                                : __Vtask_tb_dehazing__DOT__tick__27__b));
                    __Vtask_tb_dehazing__DOT__tick__27__lo 
                        = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__g)
                            ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__r
                                : __Vtask_tb_dehazing__DOT__tick__27__b)
                            : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__g, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__g
                                : __Vtask_tb_dehazing__DOT__tick__27__b));
                    __Vtask_tb_dehazing__DOT__tick__27__t 
                        = vlSelf->tb_dehazing__DOT__transmission_rom
                        [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__27__hi, 8U) 
                                     | __Vtask_tb_dehazing__DOT__tick__27__lo))];
                    __Vtask_tb_dehazing__DOT__tick__27__t 
                        = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__27__t);
                    if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__27__t)) {
                        __Vtask_tb_dehazing__DOT__tick__27__t = 0x66U;
                    }
                    __Vtask_tb_dehazing__DOT__tick__27__inv 
                        = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__27__t)
                            ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__27__t));
                    __Vtask_tb_dehazing__DOT__tick__27__inv 
                        = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__27__inv);
                    __Vtask_tb_dehazing__DOT__tick__27__a_used 
                        = vlSelf->tb_dehazing__DOT__atmosphere;
                    if (__Vtask_tb_dehazing__DOT__tick__27__sop_i) {
                        __Vtask_tb_dehazing__DOT__tick__27__selected 
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
                        __Vtask_tb_dehazing__DOT__tick__27__selected 
                            = vlSelf->tb_dehazing__DOT__frame_mode;
                        if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__27__t) 
                             & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                            vlSelf->tb_dehazing__DOT__maximum 
                                = __Vtask_tb_dehazing__DOT__tick__27__hi;
                        }
                    }
                    __Vfunc_tb_dehazing__DOT__clamp__28__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__r 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__28__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__28__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__28__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jr 
                        = __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__29__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__g 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__29__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__29__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__29__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jg 
                        = __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__30__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__b 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__30__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__30__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__30__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jb 
                        = __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout;
                    __Vtask_tb_dehazing__DOT__tick__27__gr 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jr)];
                    __Vtask_tb_dehazing__DOT__tick__27__gg 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jg)];
                    __Vtask_tb_dehazing__DOT__tick__27__gb 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jb)];
                    __Vtask_tb_dehazing__DOT__tick__27__processed 
                        = (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gr) 
                            << 0x16U) | ((0x300000U 
                                          & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gr) 
                                             << 0xeU)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gg) 
                                             << 0xcU) 
                                            | ((0xc00U 
                                                & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gg) 
                                                   << 4U)) 
                                               | (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gb) 
                                                   << 2U) 
                                                  | (3U 
                                                     & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gb) 
                                                        >> 6U)))))));
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = ((IData)(__Vtask_tb_dehazing__DOT__tick__27__selected)
                            ? __Vtask_tb_dehazing__DOT__tick__27__processed
                            : __Vtask_tb_dehazing__DOT__tick__27__pixel_i);
                } else {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                }
            }
            vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
            vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__27__mode_i;
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
            __Vtask_tb_dehazing__DOT__fail__31__reason = 
                std::string{"ready contract"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__31__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                        [0xaU] >> 0x1eU))) 
                         != vlSelf->tb_dehazing__DOT__ev
                         [0xaU]))) {
            __Vtask_tb_dehazing__DOT__fail__32__reason = 
                std::string{"11 enabled-stage valid/reset/bubble timing"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__32__reason),
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
            __Vtask_tb_dehazing__DOT__fail__33__reason = 
                std::string{"ordered SOP/EOP"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__33__reason),
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
            __Vtask_tb_dehazing__DOT__fail__34__reason = 
                std::string{"ordered raw/processed pixel or frame mode"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__34__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__27__reset_i) 
                           & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                          & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__27__ready_i))) 
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
            __Vtask_tb_dehazing__DOT__fail__35__reason = 
                std::string{"output changed while stalled (including mode changes)"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__35__reason),
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
        vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__27__reset_i;
        vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                            + vlSelf->tb_dehazing__DOT__checks);
        tb_dehazing__DOT__i = 1U;
        __Vtask_tb_dehazing__DOT__tick__27__reset_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__27__pixel_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__mode_i 
            = vlSelf->tb_dehazing__DOT__mode_value;
        __Vtask_tb_dehazing__DOT__tick__27__eop_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__sop_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__27__valid_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__ready_i = 1U;
        co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           45);
        vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__27__ready_i;
        vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__27__valid_i;
        vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__27__sop_i;
        vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__27__eop_i;
        vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__27__pixel_i;
        vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__27__mode_i;
        vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__27__reset_i;
        co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           48);
        if (__Vtask_tb_dehazing__DOT__tick__27__reset_i) {
            if (__Vtask_tb_dehazing__DOT__tick__27__ready_i) {
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
                if (__Vtask_tb_dehazing__DOT__tick__27__valid_i) {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__27__sop_i;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__27__eop_i;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__accepted 
                        = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                    __Vtask_tb_dehazing__DOT__tick__27__r 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 0x16U));
                    __Vtask_tb_dehazing__DOT__tick__27__g 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 0xcU));
                    __Vtask_tb_dehazing__DOT__tick__27__b 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 2U));
                    __Vtask_tb_dehazing__DOT__tick__27__hi 
                        = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__g)
                            ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__r
                                : __Vtask_tb_dehazing__DOT__tick__27__b)
                            : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__g, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__g
                                : __Vtask_tb_dehazing__DOT__tick__27__b));
                    __Vtask_tb_dehazing__DOT__tick__27__lo 
                        = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__g)
                            ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__r
                                : __Vtask_tb_dehazing__DOT__tick__27__b)
                            : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__g, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__g
                                : __Vtask_tb_dehazing__DOT__tick__27__b));
                    __Vtask_tb_dehazing__DOT__tick__27__t 
                        = vlSelf->tb_dehazing__DOT__transmission_rom
                        [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__27__hi, 8U) 
                                     | __Vtask_tb_dehazing__DOT__tick__27__lo))];
                    __Vtask_tb_dehazing__DOT__tick__27__t 
                        = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__27__t);
                    if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__27__t)) {
                        __Vtask_tb_dehazing__DOT__tick__27__t = 0x66U;
                    }
                    __Vtask_tb_dehazing__DOT__tick__27__inv 
                        = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__27__t)
                            ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__27__t));
                    __Vtask_tb_dehazing__DOT__tick__27__inv 
                        = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__27__inv);
                    __Vtask_tb_dehazing__DOT__tick__27__a_used 
                        = vlSelf->tb_dehazing__DOT__atmosphere;
                    if (__Vtask_tb_dehazing__DOT__tick__27__sop_i) {
                        __Vtask_tb_dehazing__DOT__tick__27__selected 
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
                        __Vtask_tb_dehazing__DOT__tick__27__selected 
                            = vlSelf->tb_dehazing__DOT__frame_mode;
                        if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__27__t) 
                             & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                            vlSelf->tb_dehazing__DOT__maximum 
                                = __Vtask_tb_dehazing__DOT__tick__27__hi;
                        }
                    }
                    __Vfunc_tb_dehazing__DOT__clamp__28__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__r 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__28__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__28__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__28__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jr 
                        = __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__29__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__g 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__29__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__29__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__29__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jg 
                        = __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__30__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__b 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__30__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__30__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__30__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jb 
                        = __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout;
                    __Vtask_tb_dehazing__DOT__tick__27__gr 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jr)];
                    __Vtask_tb_dehazing__DOT__tick__27__gg 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jg)];
                    __Vtask_tb_dehazing__DOT__tick__27__gb 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jb)];
                    __Vtask_tb_dehazing__DOT__tick__27__processed 
                        = (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gr) 
                            << 0x16U) | ((0x300000U 
                                          & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gr) 
                                             << 0xeU)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gg) 
                                             << 0xcU) 
                                            | ((0xc00U 
                                                & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gg) 
                                                   << 4U)) 
                                               | (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gb) 
                                                   << 2U) 
                                                  | (3U 
                                                     & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gb) 
                                                        >> 6U)))))));
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = ((IData)(__Vtask_tb_dehazing__DOT__tick__27__selected)
                            ? __Vtask_tb_dehazing__DOT__tick__27__processed
                            : __Vtask_tb_dehazing__DOT__tick__27__pixel_i);
                } else {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                }
            }
            vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
            vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__27__mode_i;
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
            __Vtask_tb_dehazing__DOT__fail__31__reason = 
                std::string{"ready contract"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__31__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                        [0xaU] >> 0x1eU))) 
                         != vlSelf->tb_dehazing__DOT__ev
                         [0xaU]))) {
            __Vtask_tb_dehazing__DOT__fail__32__reason = 
                std::string{"11 enabled-stage valid/reset/bubble timing"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__32__reason),
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
            __Vtask_tb_dehazing__DOT__fail__33__reason = 
                std::string{"ordered SOP/EOP"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__33__reason),
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
            __Vtask_tb_dehazing__DOT__fail__34__reason = 
                std::string{"ordered raw/processed pixel or frame mode"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__34__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__27__reset_i) 
                           & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                          & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__27__ready_i))) 
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
            __Vtask_tb_dehazing__DOT__fail__35__reason = 
                std::string{"output changed while stalled (including mode changes)"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__35__reason),
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
        vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__27__reset_i;
        vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                            + vlSelf->tb_dehazing__DOT__checks);
        tb_dehazing__DOT__i = 2U;
        __Vtask_tb_dehazing__DOT__tick__27__reset_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__27__pixel_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__mode_i 
            = vlSelf->tb_dehazing__DOT__mode_value;
        __Vtask_tb_dehazing__DOT__tick__27__eop_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__sop_i = 1U;
        __Vtask_tb_dehazing__DOT__tick__27__valid_i = 0U;
        __Vtask_tb_dehazing__DOT__tick__27__ready_i = 1U;
        co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           45);
        vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__27__ready_i;
        vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__27__valid_i;
        vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__27__sop_i;
        vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__27__eop_i;
        vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__27__pixel_i;
        vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__27__mode_i;
        vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__27__reset_i;
        co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_dehazing.clk)", 
                                                           "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                           48);
        if (__Vtask_tb_dehazing__DOT__tick__27__reset_i) {
            if (__Vtask_tb_dehazing__DOT__tick__27__ready_i) {
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
                if (__Vtask_tb_dehazing__DOT__tick__27__valid_i) {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__27__sop_i;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = __Vtask_tb_dehazing__DOT__tick__27__eop_i;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__accepted 
                        = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                    __Vtask_tb_dehazing__DOT__tick__27__r 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 0x16U));
                    __Vtask_tb_dehazing__DOT__tick__27__g 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 0xcU));
                    __Vtask_tb_dehazing__DOT__tick__27__b 
                        = (0xffU & (__Vtask_tb_dehazing__DOT__tick__27__pixel_i 
                                    >> 2U));
                    __Vtask_tb_dehazing__DOT__tick__27__hi 
                        = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__g)
                            ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__r
                                : __Vtask_tb_dehazing__DOT__tick__27__b)
                            : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__g, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__g
                                : __Vtask_tb_dehazing__DOT__tick__27__b));
                    __Vtask_tb_dehazing__DOT__tick__27__lo 
                        = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__g)
                            ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__r, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__r
                                : __Vtask_tb_dehazing__DOT__tick__27__b)
                            : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__g, __Vtask_tb_dehazing__DOT__tick__27__b)
                                ? __Vtask_tb_dehazing__DOT__tick__27__g
                                : __Vtask_tb_dehazing__DOT__tick__27__b));
                    __Vtask_tb_dehazing__DOT__tick__27__t 
                        = vlSelf->tb_dehazing__DOT__transmission_rom
                        [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__27__hi, 8U) 
                                     | __Vtask_tb_dehazing__DOT__tick__27__lo))];
                    __Vtask_tb_dehazing__DOT__tick__27__t 
                        = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__27__t);
                    if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__27__t)) {
                        __Vtask_tb_dehazing__DOT__tick__27__t = 0x66U;
                    }
                    __Vtask_tb_dehazing__DOT__tick__27__inv 
                        = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__27__t)
                            ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__27__t));
                    __Vtask_tb_dehazing__DOT__tick__27__inv 
                        = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__27__inv);
                    __Vtask_tb_dehazing__DOT__tick__27__a_used 
                        = vlSelf->tb_dehazing__DOT__atmosphere;
                    if (__Vtask_tb_dehazing__DOT__tick__27__sop_i) {
                        __Vtask_tb_dehazing__DOT__tick__27__selected 
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
                        __Vtask_tb_dehazing__DOT__tick__27__selected 
                            = vlSelf->tb_dehazing__DOT__frame_mode;
                        if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__27__t) 
                             & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__27__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                            vlSelf->tb_dehazing__DOT__maximum 
                                = __Vtask_tb_dehazing__DOT__tick__27__hi;
                        }
                    }
                    __Vfunc_tb_dehazing__DOT__clamp__28__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__r 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__28__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__28__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__28__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jr 
                        = __Vfunc_tb_dehazing__DOT__clamp__28__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__29__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__g 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__29__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__29__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__29__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jg 
                        = __Vfunc_tb_dehazing__DOT__clamp__29__Vfuncout;
                    __Vfunc_tb_dehazing__DOT__clamp__30__value 
                        = (VL_SHIFTRS_III(32,32,32, 
                                          VL_MULS_III(32, 
                                                      (__Vtask_tb_dehazing__DOT__tick__27__b 
                                                       - __Vtask_tb_dehazing__DOT__tick__27__a_used), __Vtask_tb_dehazing__DOT__tick__27__inv), 0xaU) 
                           + __Vtask_tb_dehazing__DOT__tick__27__a_used);
                    __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout 
                        = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__30__value)
                            ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__30__value)
                                     ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__30__value));
                    __Vtask_tb_dehazing__DOT__tick__27__jb 
                        = __Vfunc_tb_dehazing__DOT__clamp__30__Vfuncout;
                    __Vtask_tb_dehazing__DOT__tick__27__gr 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jr)];
                    __Vtask_tb_dehazing__DOT__tick__27__gg 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jg)];
                    __Vtask_tb_dehazing__DOT__tick__27__gb 
                        = vlSelf->tb_dehazing__DOT__gamma_rom
                        [(0xffU & __Vtask_tb_dehazing__DOT__tick__27__jb)];
                    __Vtask_tb_dehazing__DOT__tick__27__processed 
                        = (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gr) 
                            << 0x16U) | ((0x300000U 
                                          & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gr) 
                                             << 0xeU)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gg) 
                                             << 0xcU) 
                                            | ((0xc00U 
                                                & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gg) 
                                                   << 4U)) 
                                               | (((IData)(__Vtask_tb_dehazing__DOT__tick__27__gb) 
                                                   << 2U) 
                                                  | (3U 
                                                     & ((IData)(__Vtask_tb_dehazing__DOT__tick__27__gb) 
                                                        >> 6U)))))));
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = ((IData)(__Vtask_tb_dehazing__DOT__tick__27__selected)
                            ? __Vtask_tb_dehazing__DOT__tick__27__processed
                            : __Vtask_tb_dehazing__DOT__tick__27__pixel_i);
                } else {
                    vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                }
            }
            vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
            vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__27__mode_i;
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
            __Vtask_tb_dehazing__DOT__fail__31__reason = 
                std::string{"ready contract"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__31__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                        [0xaU] >> 0x1eU))) 
                         != vlSelf->tb_dehazing__DOT__ev
                         [0xaU]))) {
            __Vtask_tb_dehazing__DOT__fail__32__reason = 
                std::string{"11 enabled-stage valid/reset/bubble timing"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__32__reason),
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
            __Vtask_tb_dehazing__DOT__fail__33__reason = 
                std::string{"ordered SOP/EOP"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__33__reason),
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
            __Vtask_tb_dehazing__DOT__fail__34__reason = 
                std::string{"ordered raw/processed pixel or frame mode"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__34__reason),
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
        }
        if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__27__reset_i) 
                           & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                          & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__27__ready_i))) 
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
            __Vtask_tb_dehazing__DOT__fail__35__reason = 
                std::string{"output changed while stalled (including mode changes)"};
            VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                      32,vlSelf->tb_dehazing__DOT__seed,
                      32,vlSelf->tb_dehazing__DOT__accepted,
                      32,vlSelf->tb_dehazing__DOT__checks,
                      -1,&(__Vtask_tb_dehazing__DOT__fail__35__reason),
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
        vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__27__reset_i;
        vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                            + vlSelf->tb_dehazing__DOT__checks);
        tb_dehazing__DOT__i = 3U;
        vlSelf->tb_dehazing__DOT__pixel = 0U;
        while (VL_GTS_III(32, 0x17U, vlSelf->tb_dehazing__DOT__pixel)) {
            __Vfunc_tb_dehazing__DOT__next_random__36__x 
                = tb_dehazing__DOT__rng;
            __Vfunc_tb_dehazing__DOT__next_random__36__Vfuncout 
                = ((IData)(0x3c6ef35fU) + ((IData)(0x19660dU) 
                                           * __Vfunc_tb_dehazing__DOT__next_random__36__x));
            tb_dehazing__DOT__rng = __Vfunc_tb_dehazing__DOT__next_random__36__Vfuncout;
            vlSelf->tb_dehazing__DOT__value = (0x3fffffffU 
                                               & tb_dehazing__DOT__rng);
            vlSelf->tb_dehazing__DOT__stall = (7U & 
                                               VL_SHIFTR_III(32,32,32, tb_dehazing__DOT__rng, 0x1cU));
            tb_dehazing__DOT__i = 0U;
            while (VL_LTS_III(32, tb_dehazing__DOT__i, vlSelf->tb_dehazing__DOT__stall)) {
                __Vtask_tb_dehazing__DOT__tick__37__reset_i = 1U;
                __Vtask_tb_dehazing__DOT__tick__37__pixel_i 
                    = vlSelf->tb_dehazing__DOT__value;
                __Vtask_tb_dehazing__DOT__tick__37__mode_i 
                    = (1U & tb_dehazing__DOT__i);
                __Vtask_tb_dehazing__DOT__tick__37__eop_i 
                    = (0x16U == vlSelf->tb_dehazing__DOT__pixel);
                __Vtask_tb_dehazing__DOT__tick__37__sop_i 
                    = (0U == vlSelf->tb_dehazing__DOT__pixel);
                __Vtask_tb_dehazing__DOT__tick__37__valid_i = 1U;
                __Vtask_tb_dehazing__DOT__tick__37__ready_i = 0U;
                co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                                   nullptr, 
                                                                   "@(negedge tb_dehazing.clk)", 
                                                                   "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                                   45);
                vlSelf->tb_dehazing__DOT__src_ready 
                    = __Vtask_tb_dehazing__DOT__tick__37__ready_i;
                vlSelf->tb_dehazing__DOT__snk_valid 
                    = __Vtask_tb_dehazing__DOT__tick__37__valid_i;
                vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__37__sop_i;
                vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__37__eop_i;
                vlSelf->tb_dehazing__DOT__snk_data 
                    = __Vtask_tb_dehazing__DOT__tick__37__pixel_i;
                vlSelf->tb_dehazing__DOT__sw_bypass 
                    = __Vtask_tb_dehazing__DOT__tick__37__mode_i;
                vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__37__reset_i;
                co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                                   nullptr, 
                                                                   "@(posedge tb_dehazing.clk)", 
                                                                   "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                                   48);
                if (__Vtask_tb_dehazing__DOT__tick__37__reset_i) {
                    if (__Vtask_tb_dehazing__DOT__tick__37__ready_i) {
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [9U];
                        vlSelf->tb_dehazing__DOT__ev[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [9U];
                        vlSelf->tb_dehazing__DOT__es[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [9U];
                        vlSelf->tb_dehazing__DOT__ee[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [9U];
                        vlSelf->tb_dehazing__DOT__ed[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [8U];
                        vlSelf->tb_dehazing__DOT__ev[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [8U];
                        vlSelf->tb_dehazing__DOT__es[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [8U];
                        vlSelf->tb_dehazing__DOT__ee[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [8U];
                        vlSelf->tb_dehazing__DOT__ed[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [7U];
                        vlSelf->tb_dehazing__DOT__ev[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [7U];
                        vlSelf->tb_dehazing__DOT__es[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [7U];
                        vlSelf->tb_dehazing__DOT__ee[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [7U];
                        vlSelf->tb_dehazing__DOT__ed[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [6U];
                        vlSelf->tb_dehazing__DOT__ev[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [6U];
                        vlSelf->tb_dehazing__DOT__es[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [6U];
                        vlSelf->tb_dehazing__DOT__ee[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [6U];
                        vlSelf->tb_dehazing__DOT__ed[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [5U];
                        vlSelf->tb_dehazing__DOT__ev[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [5U];
                        vlSelf->tb_dehazing__DOT__es[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [5U];
                        vlSelf->tb_dehazing__DOT__ee[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [5U];
                        vlSelf->tb_dehazing__DOT__ed[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [4U];
                        vlSelf->tb_dehazing__DOT__ev[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [4U];
                        vlSelf->tb_dehazing__DOT__es[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [4U];
                        vlSelf->tb_dehazing__DOT__ee[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [4U];
                        vlSelf->tb_dehazing__DOT__ed[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [3U];
                        vlSelf->tb_dehazing__DOT__ev[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [3U];
                        vlSelf->tb_dehazing__DOT__es[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [3U];
                        vlSelf->tb_dehazing__DOT__ee[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [3U];
                        vlSelf->tb_dehazing__DOT__ed[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [2U];
                        vlSelf->tb_dehazing__DOT__ev[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [2U];
                        vlSelf->tb_dehazing__DOT__es[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [2U];
                        vlSelf->tb_dehazing__DOT__ee[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [2U];
                        vlSelf->tb_dehazing__DOT__ed[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [1U];
                        vlSelf->tb_dehazing__DOT__ev[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [1U];
                        vlSelf->tb_dehazing__DOT__es[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [1U];
                        vlSelf->tb_dehazing__DOT__ee[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [1U];
                        vlSelf->tb_dehazing__DOT__ed[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [0U];
                        vlSelf->tb_dehazing__DOT__ev[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [0U];
                        vlSelf->tb_dehazing__DOT__es[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [0U];
                        vlSelf->tb_dehazing__DOT__ee[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [0U];
                        vlSelf->tb_dehazing__DOT__ed[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        if (__Vtask_tb_dehazing__DOT__tick__37__valid_i) {
                            vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                            vlSelf->tb_dehazing__DOT__es[0U] 
                                = __Vtask_tb_dehazing__DOT__tick__37__sop_i;
                            vlSelf->tb_dehazing__DOT__ee[0U] 
                                = __Vtask_tb_dehazing__DOT__tick__37__eop_i;
                            vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__accepted 
                                = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                            __Vtask_tb_dehazing__DOT__tick__37__r 
                                = (0xffU & (__Vtask_tb_dehazing__DOT__tick__37__pixel_i 
                                            >> 0x16U));
                            __Vtask_tb_dehazing__DOT__tick__37__g 
                                = (0xffU & (__Vtask_tb_dehazing__DOT__tick__37__pixel_i 
                                            >> 0xcU));
                            __Vtask_tb_dehazing__DOT__tick__37__b 
                                = (0xffU & (__Vtask_tb_dehazing__DOT__tick__37__pixel_i 
                                            >> 2U));
                            __Vtask_tb_dehazing__DOT__tick__37__hi 
                                = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__37__r, __Vtask_tb_dehazing__DOT__tick__37__g)
                                    ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__37__r, __Vtask_tb_dehazing__DOT__tick__37__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__37__r
                                        : __Vtask_tb_dehazing__DOT__tick__37__b)
                                    : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__37__g, __Vtask_tb_dehazing__DOT__tick__37__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__37__g
                                        : __Vtask_tb_dehazing__DOT__tick__37__b));
                            __Vtask_tb_dehazing__DOT__tick__37__lo 
                                = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__37__r, __Vtask_tb_dehazing__DOT__tick__37__g)
                                    ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__37__r, __Vtask_tb_dehazing__DOT__tick__37__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__37__r
                                        : __Vtask_tb_dehazing__DOT__tick__37__b)
                                    : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__37__g, __Vtask_tb_dehazing__DOT__tick__37__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__37__g
                                        : __Vtask_tb_dehazing__DOT__tick__37__b));
                            __Vtask_tb_dehazing__DOT__tick__37__t 
                                = vlSelf->tb_dehazing__DOT__transmission_rom
                                [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__37__hi, 8U) 
                                             | __Vtask_tb_dehazing__DOT__tick__37__lo))];
                            __Vtask_tb_dehazing__DOT__tick__37__t 
                                = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__37__t);
                            if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__37__t)) {
                                __Vtask_tb_dehazing__DOT__tick__37__t = 0x66U;
                            }
                            __Vtask_tb_dehazing__DOT__tick__37__inv 
                                = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__37__t)
                                    ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__37__t));
                            __Vtask_tb_dehazing__DOT__tick__37__inv 
                                = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__37__inv);
                            __Vtask_tb_dehazing__DOT__tick__37__a_used 
                                = vlSelf->tb_dehazing__DOT__atmosphere;
                            if (__Vtask_tb_dehazing__DOT__tick__37__sop_i) {
                                __Vtask_tb_dehazing__DOT__tick__37__selected 
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
                                __Vtask_tb_dehazing__DOT__tick__37__selected 
                                    = vlSelf->tb_dehazing__DOT__frame_mode;
                                if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__37__t) 
                                     & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__37__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                                    vlSelf->tb_dehazing__DOT__maximum 
                                        = __Vtask_tb_dehazing__DOT__tick__37__hi;
                                }
                            }
                            __Vfunc_tb_dehazing__DOT__clamp__38__value 
                                = (VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, 
                                                              (__Vtask_tb_dehazing__DOT__tick__37__r 
                                                               - __Vtask_tb_dehazing__DOT__tick__37__a_used), __Vtask_tb_dehazing__DOT__tick__37__inv), 0xaU) 
                                   + __Vtask_tb_dehazing__DOT__tick__37__a_used);
                            __Vfunc_tb_dehazing__DOT__clamp__38__Vfuncout 
                                = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__38__value)
                                    ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__38__value)
                                             ? 0xffU
                                             : __Vfunc_tb_dehazing__DOT__clamp__38__value));
                            __Vtask_tb_dehazing__DOT__tick__37__jr 
                                = __Vfunc_tb_dehazing__DOT__clamp__38__Vfuncout;
                            __Vfunc_tb_dehazing__DOT__clamp__39__value 
                                = (VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, 
                                                              (__Vtask_tb_dehazing__DOT__tick__37__g 
                                                               - __Vtask_tb_dehazing__DOT__tick__37__a_used), __Vtask_tb_dehazing__DOT__tick__37__inv), 0xaU) 
                                   + __Vtask_tb_dehazing__DOT__tick__37__a_used);
                            __Vfunc_tb_dehazing__DOT__clamp__39__Vfuncout 
                                = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__39__value)
                                    ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__39__value)
                                             ? 0xffU
                                             : __Vfunc_tb_dehazing__DOT__clamp__39__value));
                            __Vtask_tb_dehazing__DOT__tick__37__jg 
                                = __Vfunc_tb_dehazing__DOT__clamp__39__Vfuncout;
                            __Vfunc_tb_dehazing__DOT__clamp__40__value 
                                = (VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, 
                                                              (__Vtask_tb_dehazing__DOT__tick__37__b 
                                                               - __Vtask_tb_dehazing__DOT__tick__37__a_used), __Vtask_tb_dehazing__DOT__tick__37__inv), 0xaU) 
                                   + __Vtask_tb_dehazing__DOT__tick__37__a_used);
                            __Vfunc_tb_dehazing__DOT__clamp__40__Vfuncout 
                                = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__40__value)
                                    ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__40__value)
                                             ? 0xffU
                                             : __Vfunc_tb_dehazing__DOT__clamp__40__value));
                            __Vtask_tb_dehazing__DOT__tick__37__jb 
                                = __Vfunc_tb_dehazing__DOT__clamp__40__Vfuncout;
                            __Vtask_tb_dehazing__DOT__tick__37__gr 
                                = vlSelf->tb_dehazing__DOT__gamma_rom
                                [(0xffU & __Vtask_tb_dehazing__DOT__tick__37__jr)];
                            __Vtask_tb_dehazing__DOT__tick__37__gg 
                                = vlSelf->tb_dehazing__DOT__gamma_rom
                                [(0xffU & __Vtask_tb_dehazing__DOT__tick__37__jg)];
                            __Vtask_tb_dehazing__DOT__tick__37__gb 
                                = vlSelf->tb_dehazing__DOT__gamma_rom
                                [(0xffU & __Vtask_tb_dehazing__DOT__tick__37__jb)];
                            __Vtask_tb_dehazing__DOT__tick__37__processed 
                                = (((IData)(__Vtask_tb_dehazing__DOT__tick__37__gr) 
                                    << 0x16U) | ((0x300000U 
                                                  & ((IData)(__Vtask_tb_dehazing__DOT__tick__37__gr) 
                                                     << 0xeU)) 
                                                 | (((IData)(__Vtask_tb_dehazing__DOT__tick__37__gg) 
                                                     << 0xcU) 
                                                    | ((0xc00U 
                                                        & ((IData)(__Vtask_tb_dehazing__DOT__tick__37__gg) 
                                                           << 4U)) 
                                                       | (((IData)(__Vtask_tb_dehazing__DOT__tick__37__gb) 
                                                           << 2U) 
                                                          | (3U 
                                                             & ((IData)(__Vtask_tb_dehazing__DOT__tick__37__gb) 
                                                                >> 6U)))))));
                            vlSelf->tb_dehazing__DOT__ed[0U] 
                                = ((IData)(__Vtask_tb_dehazing__DOT__tick__37__selected)
                                    ? __Vtask_tb_dehazing__DOT__tick__37__processed
                                    : __Vtask_tb_dehazing__DOT__tick__37__pixel_i);
                        } else {
                            vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                        }
                    }
                    vlSelf->tb_dehazing__DOT__sync_mode 
                        = vlSelf->tb_dehazing__DOT__meta;
                    vlSelf->tb_dehazing__DOT__meta 
                        = __Vtask_tb_dehazing__DOT__tick__37__mode_i;
                } else {
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
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
                    __Vtask_tb_dehazing__DOT__fail__41__reason = 
                        std::string{"ready contract"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__41__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                [0xaU] 
                                                >> 0x1eU))) 
                                 != vlSelf->tb_dehazing__DOT__ev
                                 [0xaU]))) {
                    __Vtask_tb_dehazing__DOT__fail__42__reason = 
                        std::string{"11 enabled-stage valid/reset/bubble timing"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__42__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                 [0xaU] 
                                                 >> 0x20U))) 
                                  != vlSelf->tb_dehazing__DOT__es
                                  [0xaU]) | ((1U & (IData)(
                                                           (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                            [0xaU] 
                                                            >> 0x1fU))) 
                                             != vlSelf->tb_dehazing__DOT__ee
                                             [0xaU])))) {
                    __Vtask_tb_dehazing__DOT__fail__43__reason = 
                        std::string{"ordered SOP/EOP"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__43__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev
                                 [0xaU] & ((0x3fffffffU 
                                            & ((1U 
                                                & (IData)(
                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                           [0xaU] 
                                                           >> 0x21U)))
                                                ? (
                                                   (0x3fc00000U 
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
                    VL_WRITEF("expected=%x actual=%x\n",
                              30,vlSelf->tb_dehazing__DOT__ed
                              [0xaU],30,(0x3fffffffU 
                                         & ((1U & (IData)(
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
                    __Vtask_tb_dehazing__DOT__fail__44__reason = 
                        std::string{"ordered raw/processed pixel or frame mode"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__44__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__37__reset_i) 
                                   & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                                  & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__37__ready_i))) 
                                 & ((((QData)((IData)(
                                                      (1U 
                                                       & (IData)(
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
                    __Vtask_tb_dehazing__DOT__fail__45__reason = 
                        std::string{"output changed while stalled (including mode changes)"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__45__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                vlSelf->tb_dehazing__DOT__last_output 
                    = (((QData)((IData)((1U & (IData)(
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
                                                                         [0xaU]))))))));
                vlSelf->tb_dehazing__DOT__last_reset 
                    = __Vtask_tb_dehazing__DOT__tick__37__reset_i;
                vlSelf->tb_dehazing__DOT__checks = 
                    ((IData)(1U) + vlSelf->tb_dehazing__DOT__checks);
                tb_dehazing__DOT__i = ((IData)(1U) 
                                       + tb_dehazing__DOT__i);
            }
            __Vtask_tb_dehazing__DOT__tick__46__reset_i = 1U;
            __Vtask_tb_dehazing__DOT__tick__46__pixel_i 
                = vlSelf->tb_dehazing__DOT__value;
            __Vtask_tb_dehazing__DOT__tick__46__mode_i 
                = vlSelf->tb_dehazing__DOT__mode_value;
            __Vtask_tb_dehazing__DOT__tick__46__eop_i 
                = (0x16U == vlSelf->tb_dehazing__DOT__pixel);
            __Vtask_tb_dehazing__DOT__tick__46__sop_i 
                = (0U == vlSelf->tb_dehazing__DOT__pixel);
            __Vtask_tb_dehazing__DOT__tick__46__valid_i = 1U;
            __Vtask_tb_dehazing__DOT__tick__46__ready_i = 1U;
            co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_dehazing.clk)", 
                                                               "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                               45);
            vlSelf->tb_dehazing__DOT__src_ready = __Vtask_tb_dehazing__DOT__tick__46__ready_i;
            vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__46__valid_i;
            vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__46__sop_i;
            vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__46__eop_i;
            vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__46__pixel_i;
            vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__46__mode_i;
            vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__46__reset_i;
            co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_dehazing.clk)", 
                                                               "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                               48);
            if (__Vtask_tb_dehazing__DOT__tick__46__reset_i) {
                if (__Vtask_tb_dehazing__DOT__tick__46__ready_i) {
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [9U];
                    vlSelf->tb_dehazing__DOT__ev[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [9U];
                    vlSelf->tb_dehazing__DOT__es[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [9U];
                    vlSelf->tb_dehazing__DOT__ee[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [9U];
                    vlSelf->tb_dehazing__DOT__ed[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [8U];
                    vlSelf->tb_dehazing__DOT__ev[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [8U];
                    vlSelf->tb_dehazing__DOT__es[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [8U];
                    vlSelf->tb_dehazing__DOT__ee[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [8U];
                    vlSelf->tb_dehazing__DOT__ed[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [7U];
                    vlSelf->tb_dehazing__DOT__ev[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [7U];
                    vlSelf->tb_dehazing__DOT__es[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [7U];
                    vlSelf->tb_dehazing__DOT__ee[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [7U];
                    vlSelf->tb_dehazing__DOT__ed[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [6U];
                    vlSelf->tb_dehazing__DOT__ev[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [6U];
                    vlSelf->tb_dehazing__DOT__es[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [6U];
                    vlSelf->tb_dehazing__DOT__ee[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [6U];
                    vlSelf->tb_dehazing__DOT__ed[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [5U];
                    vlSelf->tb_dehazing__DOT__ev[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [5U];
                    vlSelf->tb_dehazing__DOT__es[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [5U];
                    vlSelf->tb_dehazing__DOT__ee[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [5U];
                    vlSelf->tb_dehazing__DOT__ed[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [4U];
                    vlSelf->tb_dehazing__DOT__ev[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [4U];
                    vlSelf->tb_dehazing__DOT__es[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [4U];
                    vlSelf->tb_dehazing__DOT__ee[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [4U];
                    vlSelf->tb_dehazing__DOT__ed[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [3U];
                    vlSelf->tb_dehazing__DOT__ev[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [3U];
                    vlSelf->tb_dehazing__DOT__es[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [3U];
                    vlSelf->tb_dehazing__DOT__ee[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [3U];
                    vlSelf->tb_dehazing__DOT__ed[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [2U];
                    vlSelf->tb_dehazing__DOT__ev[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [2U];
                    vlSelf->tb_dehazing__DOT__es[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [2U];
                    vlSelf->tb_dehazing__DOT__ee[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [2U];
                    vlSelf->tb_dehazing__DOT__ed[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [1U];
                    vlSelf->tb_dehazing__DOT__ev[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [1U];
                    vlSelf->tb_dehazing__DOT__es[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [1U];
                    vlSelf->tb_dehazing__DOT__ee[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [1U];
                    vlSelf->tb_dehazing__DOT__ed[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                        = vlSelf->tb_dehazing__DOT__ev
                        [0U];
                    vlSelf->tb_dehazing__DOT__ev[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                        = vlSelf->tb_dehazing__DOT__es
                        [0U];
                    vlSelf->tb_dehazing__DOT__es[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                        = vlSelf->tb_dehazing__DOT__ee
                        [0U];
                    vlSelf->tb_dehazing__DOT__ee[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                        = vlSelf->tb_dehazing__DOT__ed
                        [0U];
                    vlSelf->tb_dehazing__DOT__ed[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                    if (__Vtask_tb_dehazing__DOT__tick__46__valid_i) {
                        vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                        vlSelf->tb_dehazing__DOT__es[0U] 
                            = __Vtask_tb_dehazing__DOT__tick__46__sop_i;
                        vlSelf->tb_dehazing__DOT__ee[0U] 
                            = __Vtask_tb_dehazing__DOT__tick__46__eop_i;
                        vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                        vlSelf->tb_dehazing__DOT__accepted 
                            = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                        __Vtask_tb_dehazing__DOT__tick__46__r 
                            = (0xffU & (__Vtask_tb_dehazing__DOT__tick__46__pixel_i 
                                        >> 0x16U));
                        __Vtask_tb_dehazing__DOT__tick__46__g 
                            = (0xffU & (__Vtask_tb_dehazing__DOT__tick__46__pixel_i 
                                        >> 0xcU));
                        __Vtask_tb_dehazing__DOT__tick__46__b 
                            = (0xffU & (__Vtask_tb_dehazing__DOT__tick__46__pixel_i 
                                        >> 2U));
                        __Vtask_tb_dehazing__DOT__tick__46__hi 
                            = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__46__r, __Vtask_tb_dehazing__DOT__tick__46__g)
                                ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__46__r, __Vtask_tb_dehazing__DOT__tick__46__b)
                                    ? __Vtask_tb_dehazing__DOT__tick__46__r
                                    : __Vtask_tb_dehazing__DOT__tick__46__b)
                                : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__46__g, __Vtask_tb_dehazing__DOT__tick__46__b)
                                    ? __Vtask_tb_dehazing__DOT__tick__46__g
                                    : __Vtask_tb_dehazing__DOT__tick__46__b));
                        __Vtask_tb_dehazing__DOT__tick__46__lo 
                            = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__46__r, __Vtask_tb_dehazing__DOT__tick__46__g)
                                ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__46__r, __Vtask_tb_dehazing__DOT__tick__46__b)
                                    ? __Vtask_tb_dehazing__DOT__tick__46__r
                                    : __Vtask_tb_dehazing__DOT__tick__46__b)
                                : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__46__g, __Vtask_tb_dehazing__DOT__tick__46__b)
                                    ? __Vtask_tb_dehazing__DOT__tick__46__g
                                    : __Vtask_tb_dehazing__DOT__tick__46__b));
                        __Vtask_tb_dehazing__DOT__tick__46__t 
                            = vlSelf->tb_dehazing__DOT__transmission_rom
                            [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__46__hi, 8U) 
                                         | __Vtask_tb_dehazing__DOT__tick__46__lo))];
                        __Vtask_tb_dehazing__DOT__tick__46__t 
                            = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__46__t);
                        if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__46__t)) {
                            __Vtask_tb_dehazing__DOT__tick__46__t = 0x66U;
                        }
                        __Vtask_tb_dehazing__DOT__tick__46__inv 
                            = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__46__t)
                                ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__46__t));
                        __Vtask_tb_dehazing__DOT__tick__46__inv 
                            = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__46__inv);
                        __Vtask_tb_dehazing__DOT__tick__46__a_used 
                            = vlSelf->tb_dehazing__DOT__atmosphere;
                        if (__Vtask_tb_dehazing__DOT__tick__46__sop_i) {
                            __Vtask_tb_dehazing__DOT__tick__46__selected 
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
                            __Vtask_tb_dehazing__DOT__tick__46__selected 
                                = vlSelf->tb_dehazing__DOT__frame_mode;
                            if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__46__t) 
                                 & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__46__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                                vlSelf->tb_dehazing__DOT__maximum 
                                    = __Vtask_tb_dehazing__DOT__tick__46__hi;
                            }
                        }
                        __Vfunc_tb_dehazing__DOT__clamp__47__value 
                            = (VL_SHIFTRS_III(32,32,32, 
                                              VL_MULS_III(32, 
                                                          (__Vtask_tb_dehazing__DOT__tick__46__r 
                                                           - __Vtask_tb_dehazing__DOT__tick__46__a_used), __Vtask_tb_dehazing__DOT__tick__46__inv), 0xaU) 
                               + __Vtask_tb_dehazing__DOT__tick__46__a_used);
                        __Vfunc_tb_dehazing__DOT__clamp__47__Vfuncout 
                            = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__47__value)
                                ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__47__value)
                                         ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__47__value));
                        __Vtask_tb_dehazing__DOT__tick__46__jr 
                            = __Vfunc_tb_dehazing__DOT__clamp__47__Vfuncout;
                        __Vfunc_tb_dehazing__DOT__clamp__48__value 
                            = (VL_SHIFTRS_III(32,32,32, 
                                              VL_MULS_III(32, 
                                                          (__Vtask_tb_dehazing__DOT__tick__46__g 
                                                           - __Vtask_tb_dehazing__DOT__tick__46__a_used), __Vtask_tb_dehazing__DOT__tick__46__inv), 0xaU) 
                               + __Vtask_tb_dehazing__DOT__tick__46__a_used);
                        __Vfunc_tb_dehazing__DOT__clamp__48__Vfuncout 
                            = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__48__value)
                                ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__48__value)
                                         ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__48__value));
                        __Vtask_tb_dehazing__DOT__tick__46__jg 
                            = __Vfunc_tb_dehazing__DOT__clamp__48__Vfuncout;
                        __Vfunc_tb_dehazing__DOT__clamp__49__value 
                            = (VL_SHIFTRS_III(32,32,32, 
                                              VL_MULS_III(32, 
                                                          (__Vtask_tb_dehazing__DOT__tick__46__b 
                                                           - __Vtask_tb_dehazing__DOT__tick__46__a_used), __Vtask_tb_dehazing__DOT__tick__46__inv), 0xaU) 
                               + __Vtask_tb_dehazing__DOT__tick__46__a_used);
                        __Vfunc_tb_dehazing__DOT__clamp__49__Vfuncout 
                            = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__49__value)
                                ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__49__value)
                                         ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__49__value));
                        __Vtask_tb_dehazing__DOT__tick__46__jb 
                            = __Vfunc_tb_dehazing__DOT__clamp__49__Vfuncout;
                        __Vtask_tb_dehazing__DOT__tick__46__gr 
                            = vlSelf->tb_dehazing__DOT__gamma_rom
                            [(0xffU & __Vtask_tb_dehazing__DOT__tick__46__jr)];
                        __Vtask_tb_dehazing__DOT__tick__46__gg 
                            = vlSelf->tb_dehazing__DOT__gamma_rom
                            [(0xffU & __Vtask_tb_dehazing__DOT__tick__46__jg)];
                        __Vtask_tb_dehazing__DOT__tick__46__gb 
                            = vlSelf->tb_dehazing__DOT__gamma_rom
                            [(0xffU & __Vtask_tb_dehazing__DOT__tick__46__jb)];
                        __Vtask_tb_dehazing__DOT__tick__46__processed 
                            = (((IData)(__Vtask_tb_dehazing__DOT__tick__46__gr) 
                                << 0x16U) | ((0x300000U 
                                              & ((IData)(__Vtask_tb_dehazing__DOT__tick__46__gr) 
                                                 << 0xeU)) 
                                             | (((IData)(__Vtask_tb_dehazing__DOT__tick__46__gg) 
                                                 << 0xcU) 
                                                | ((0xc00U 
                                                    & ((IData)(__Vtask_tb_dehazing__DOT__tick__46__gg) 
                                                       << 4U)) 
                                                   | (((IData)(__Vtask_tb_dehazing__DOT__tick__46__gb) 
                                                       << 2U) 
                                                      | (3U 
                                                         & ((IData)(__Vtask_tb_dehazing__DOT__tick__46__gb) 
                                                            >> 6U)))))));
                        vlSelf->tb_dehazing__DOT__ed[0U] 
                            = ((IData)(__Vtask_tb_dehazing__DOT__tick__46__selected)
                                ? __Vtask_tb_dehazing__DOT__tick__46__processed
                                : __Vtask_tb_dehazing__DOT__tick__46__pixel_i);
                    } else {
                        vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                        vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                        vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                        vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                    }
                }
                vlSelf->tb_dehazing__DOT__sync_mode 
                    = vlSelf->tb_dehazing__DOT__meta;
                vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__46__mode_i;
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
                vlSelf->tb_dehazing__DOT__ev[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                vlSelf->tb_dehazing__DOT__es[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                vlSelf->tb_dehazing__DOT__ee[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                vlSelf->tb_dehazing__DOT__ed[0xaU] 
                    = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
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
                __Vtask_tb_dehazing__DOT__fail__50__reason = 
                    std::string{"ready contract"};
                VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                          32,vlSelf->tb_dehazing__DOT__seed,
                          32,vlSelf->tb_dehazing__DOT__accepted,
                          32,vlSelf->tb_dehazing__DOT__checks,
                          -1,&(__Vtask_tb_dehazing__DOT__fail__50__reason),
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
            }
            if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                            [0xaU] 
                                            >> 0x1eU))) 
                             != vlSelf->tb_dehazing__DOT__ev
                             [0xaU]))) {
                __Vtask_tb_dehazing__DOT__fail__51__reason = 
                    std::string{"11 enabled-stage valid/reset/bubble timing"};
                VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                          32,vlSelf->tb_dehazing__DOT__seed,
                          32,vlSelf->tb_dehazing__DOT__accepted,
                          32,vlSelf->tb_dehazing__DOT__checks,
                          -1,&(__Vtask_tb_dehazing__DOT__fail__51__reason),
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
            }
            if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                             [0xaU] 
                                             >> 0x20U))) 
                              != vlSelf->tb_dehazing__DOT__es
                              [0xaU]) | ((1U & (IData)(
                                                       (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                        [0xaU] 
                                                        >> 0x1fU))) 
                                         != vlSelf->tb_dehazing__DOT__ee
                                         [0xaU])))) {
                __Vtask_tb_dehazing__DOT__fail__52__reason = 
                    std::string{"ordered SOP/EOP"};
                VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                          32,vlSelf->tb_dehazing__DOT__seed,
                          32,vlSelf->tb_dehazing__DOT__accepted,
                          32,vlSelf->tb_dehazing__DOT__checks,
                          -1,&(__Vtask_tb_dehazing__DOT__fail__52__reason),
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
            }
            if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev
                             [0xaU] & ((0x3fffffffU 
                                        & ((1U & (IData)(
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
                VL_WRITEF("expected=%x actual=%x\n",
                          30,vlSelf->tb_dehazing__DOT__ed
                          [0xaU],30,(0x3fffffffU & 
                                     ((1U & (IData)(
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
                                       : (IData)(vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                 [0xaU]))));
                __Vtask_tb_dehazing__DOT__fail__53__reason = 
                    std::string{"ordered raw/processed pixel or frame mode"};
                VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                          32,vlSelf->tb_dehazing__DOT__seed,
                          32,vlSelf->tb_dehazing__DOT__accepted,
                          32,vlSelf->tb_dehazing__DOT__checks,
                          -1,&(__Vtask_tb_dehazing__DOT__fail__53__reason),
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
            }
            if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__46__reset_i) 
                               & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                              & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__46__ready_i))) 
                             & ((((QData)((IData)((1U 
                                                   & (IData)(
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
                __Vtask_tb_dehazing__DOT__fail__54__reason = 
                    std::string{"output changed while stalled (including mode changes)"};
                VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                          32,vlSelf->tb_dehazing__DOT__seed,
                          32,vlSelf->tb_dehazing__DOT__accepted,
                          32,vlSelf->tb_dehazing__DOT__checks,
                          -1,&(__Vtask_tb_dehazing__DOT__fail__54__reason),
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
            }
            vlSelf->tb_dehazing__DOT__last_output = 
                (((QData)((IData)((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                 [0xaU] 
                                                 >> 0x1eU))))) 
                  << 0x20U) | (QData)((IData)((((IData)(
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
            vlSelf->tb_dehazing__DOT__last_reset = __Vtask_tb_dehazing__DOT__tick__46__reset_i;
            vlSelf->tb_dehazing__DOT__checks = ((IData)(1U) 
                                                + vlSelf->tb_dehazing__DOT__checks);
            __Vfunc_tb_dehazing__DOT__next_random__55__x 
                = tb_dehazing__DOT__rng;
            __Vfunc_tb_dehazing__DOT__next_random__55__Vfuncout 
                = ((IData)(0x3c6ef35fU) + ((IData)(0x19660dU) 
                                           * __Vfunc_tb_dehazing__DOT__next_random__55__x));
            tb_dehazing__DOT__rng = __Vfunc_tb_dehazing__DOT__next_random__55__Vfuncout;
            vlSelf->tb_dehazing__DOT__bubble = (1U 
                                                & (tb_dehazing__DOT__rng 
                                                   >> 3U));
            if (vlSelf->tb_dehazing__DOT__bubble) {
                __Vtask_tb_dehazing__DOT__tick__56__reset_i = 1U;
                __Vtask_tb_dehazing__DOT__tick__56__pixel_i 
                    = (0x3fffffffU & (~ vlSelf->tb_dehazing__DOT__value));
                __Vtask_tb_dehazing__DOT__tick__56__mode_i 
                    = (1U & (~ (IData)(vlSelf->tb_dehazing__DOT__mode_value)));
                __Vtask_tb_dehazing__DOT__tick__56__eop_i = 1U;
                __Vtask_tb_dehazing__DOT__tick__56__sop_i = 1U;
                __Vtask_tb_dehazing__DOT__tick__56__valid_i = 0U;
                __Vtask_tb_dehazing__DOT__tick__56__ready_i = 1U;
                co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                                   nullptr, 
                                                                   "@(negedge tb_dehazing.clk)", 
                                                                   "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                                   45);
                vlSelf->tb_dehazing__DOT__src_ready 
                    = __Vtask_tb_dehazing__DOT__tick__56__ready_i;
                vlSelf->tb_dehazing__DOT__snk_valid 
                    = __Vtask_tb_dehazing__DOT__tick__56__valid_i;
                vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__56__sop_i;
                vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__56__eop_i;
                vlSelf->tb_dehazing__DOT__snk_data 
                    = __Vtask_tb_dehazing__DOT__tick__56__pixel_i;
                vlSelf->tb_dehazing__DOT__sw_bypass 
                    = __Vtask_tb_dehazing__DOT__tick__56__mode_i;
                vlSelf->tb_dehazing__DOT__rst_n = __Vtask_tb_dehazing__DOT__tick__56__reset_i;
                co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                                   nullptr, 
                                                                   "@(posedge tb_dehazing.clk)", 
                                                                   "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                                   48);
                if (__Vtask_tb_dehazing__DOT__tick__56__reset_i) {
                    if (__Vtask_tb_dehazing__DOT__tick__56__ready_i) {
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [9U];
                        vlSelf->tb_dehazing__DOT__ev[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [9U];
                        vlSelf->tb_dehazing__DOT__es[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [9U];
                        vlSelf->tb_dehazing__DOT__ee[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [9U];
                        vlSelf->tb_dehazing__DOT__ed[0xaU] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [8U];
                        vlSelf->tb_dehazing__DOT__ev[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [8U];
                        vlSelf->tb_dehazing__DOT__es[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [8U];
                        vlSelf->tb_dehazing__DOT__ee[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [8U];
                        vlSelf->tb_dehazing__DOT__ed[9U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [7U];
                        vlSelf->tb_dehazing__DOT__ev[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [7U];
                        vlSelf->tb_dehazing__DOT__es[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [7U];
                        vlSelf->tb_dehazing__DOT__ee[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [7U];
                        vlSelf->tb_dehazing__DOT__ed[8U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [6U];
                        vlSelf->tb_dehazing__DOT__ev[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [6U];
                        vlSelf->tb_dehazing__DOT__es[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [6U];
                        vlSelf->tb_dehazing__DOT__ee[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [6U];
                        vlSelf->tb_dehazing__DOT__ed[7U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [5U];
                        vlSelf->tb_dehazing__DOT__ev[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [5U];
                        vlSelf->tb_dehazing__DOT__es[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [5U];
                        vlSelf->tb_dehazing__DOT__ee[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [5U];
                        vlSelf->tb_dehazing__DOT__ed[6U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [4U];
                        vlSelf->tb_dehazing__DOT__ev[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [4U];
                        vlSelf->tb_dehazing__DOT__es[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [4U];
                        vlSelf->tb_dehazing__DOT__ee[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [4U];
                        vlSelf->tb_dehazing__DOT__ed[5U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [3U];
                        vlSelf->tb_dehazing__DOT__ev[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [3U];
                        vlSelf->tb_dehazing__DOT__es[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [3U];
                        vlSelf->tb_dehazing__DOT__ee[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [3U];
                        vlSelf->tb_dehazing__DOT__ed[4U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [2U];
                        vlSelf->tb_dehazing__DOT__ev[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [2U];
                        vlSelf->tb_dehazing__DOT__es[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [2U];
                        vlSelf->tb_dehazing__DOT__ee[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [2U];
                        vlSelf->tb_dehazing__DOT__ed[3U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [1U];
                        vlSelf->tb_dehazing__DOT__ev[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [1U];
                        vlSelf->tb_dehazing__DOT__es[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [1U];
                        vlSelf->tb_dehazing__DOT__ee[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [1U];
                        vlSelf->tb_dehazing__DOT__ed[2U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0 
                            = vlSelf->tb_dehazing__DOT__ev
                            [0U];
                        vlSelf->tb_dehazing__DOT__ev[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0 
                            = vlSelf->tb_dehazing__DOT__es
                            [0U];
                        vlSelf->tb_dehazing__DOT__es[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0 
                            = vlSelf->tb_dehazing__DOT__ee
                            [0U];
                        vlSelf->tb_dehazing__DOT__ee[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
                        vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0 
                            = vlSelf->tb_dehazing__DOT__ed
                            [0U];
                        vlSelf->tb_dehazing__DOT__ed[1U] 
                            = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__0;
                        if (__Vtask_tb_dehazing__DOT__tick__56__valid_i) {
                            vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                            vlSelf->tb_dehazing__DOT__es[0U] 
                                = __Vtask_tb_dehazing__DOT__tick__56__sop_i;
                            vlSelf->tb_dehazing__DOT__ee[0U] 
                                = __Vtask_tb_dehazing__DOT__tick__56__eop_i;
                            vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__accepted 
                                = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                            __Vtask_tb_dehazing__DOT__tick__56__r 
                                = (0xffU & (__Vtask_tb_dehazing__DOT__tick__56__pixel_i 
                                            >> 0x16U));
                            __Vtask_tb_dehazing__DOT__tick__56__g 
                                = (0xffU & (__Vtask_tb_dehazing__DOT__tick__56__pixel_i 
                                            >> 0xcU));
                            __Vtask_tb_dehazing__DOT__tick__56__b 
                                = (0xffU & (__Vtask_tb_dehazing__DOT__tick__56__pixel_i 
                                            >> 2U));
                            __Vtask_tb_dehazing__DOT__tick__56__hi 
                                = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__56__r, __Vtask_tb_dehazing__DOT__tick__56__g)
                                    ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__56__r, __Vtask_tb_dehazing__DOT__tick__56__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__56__r
                                        : __Vtask_tb_dehazing__DOT__tick__56__b)
                                    : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__56__g, __Vtask_tb_dehazing__DOT__tick__56__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__56__g
                                        : __Vtask_tb_dehazing__DOT__tick__56__b));
                            __Vtask_tb_dehazing__DOT__tick__56__lo 
                                = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__56__r, __Vtask_tb_dehazing__DOT__tick__56__g)
                                    ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__56__r, __Vtask_tb_dehazing__DOT__tick__56__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__56__r
                                        : __Vtask_tb_dehazing__DOT__tick__56__b)
                                    : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__56__g, __Vtask_tb_dehazing__DOT__tick__56__b)
                                        ? __Vtask_tb_dehazing__DOT__tick__56__g
                                        : __Vtask_tb_dehazing__DOT__tick__56__b));
                            __Vtask_tb_dehazing__DOT__tick__56__t 
                                = vlSelf->tb_dehazing__DOT__transmission_rom
                                [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__56__hi, 8U) 
                                             | __Vtask_tb_dehazing__DOT__tick__56__lo))];
                            __Vtask_tb_dehazing__DOT__tick__56__t 
                                = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__56__t);
                            if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__56__t)) {
                                __Vtask_tb_dehazing__DOT__tick__56__t = 0x66U;
                            }
                            __Vtask_tb_dehazing__DOT__tick__56__inv 
                                = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__56__t)
                                    ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__56__t));
                            __Vtask_tb_dehazing__DOT__tick__56__inv 
                                = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__56__inv);
                            __Vtask_tb_dehazing__DOT__tick__56__a_used 
                                = vlSelf->tb_dehazing__DOT__atmosphere;
                            if (__Vtask_tb_dehazing__DOT__tick__56__sop_i) {
                                __Vtask_tb_dehazing__DOT__tick__56__selected 
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
                                __Vtask_tb_dehazing__DOT__tick__56__selected 
                                    = vlSelf->tb_dehazing__DOT__frame_mode;
                                if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__56__t) 
                                     & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__56__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                                    vlSelf->tb_dehazing__DOT__maximum 
                                        = __Vtask_tb_dehazing__DOT__tick__56__hi;
                                }
                            }
                            __Vfunc_tb_dehazing__DOT__clamp__57__value 
                                = (VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, 
                                                              (__Vtask_tb_dehazing__DOT__tick__56__r 
                                                               - __Vtask_tb_dehazing__DOT__tick__56__a_used), __Vtask_tb_dehazing__DOT__tick__56__inv), 0xaU) 
                                   + __Vtask_tb_dehazing__DOT__tick__56__a_used);
                            __Vfunc_tb_dehazing__DOT__clamp__57__Vfuncout 
                                = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__57__value)
                                    ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__57__value)
                                             ? 0xffU
                                             : __Vfunc_tb_dehazing__DOT__clamp__57__value));
                            __Vtask_tb_dehazing__DOT__tick__56__jr 
                                = __Vfunc_tb_dehazing__DOT__clamp__57__Vfuncout;
                            __Vfunc_tb_dehazing__DOT__clamp__58__value 
                                = (VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, 
                                                              (__Vtask_tb_dehazing__DOT__tick__56__g 
                                                               - __Vtask_tb_dehazing__DOT__tick__56__a_used), __Vtask_tb_dehazing__DOT__tick__56__inv), 0xaU) 
                                   + __Vtask_tb_dehazing__DOT__tick__56__a_used);
                            __Vfunc_tb_dehazing__DOT__clamp__58__Vfuncout 
                                = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__58__value)
                                    ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__58__value)
                                             ? 0xffU
                                             : __Vfunc_tb_dehazing__DOT__clamp__58__value));
                            __Vtask_tb_dehazing__DOT__tick__56__jg 
                                = __Vfunc_tb_dehazing__DOT__clamp__58__Vfuncout;
                            __Vfunc_tb_dehazing__DOT__clamp__59__value 
                                = (VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, 
                                                              (__Vtask_tb_dehazing__DOT__tick__56__b 
                                                               - __Vtask_tb_dehazing__DOT__tick__56__a_used), __Vtask_tb_dehazing__DOT__tick__56__inv), 0xaU) 
                                   + __Vtask_tb_dehazing__DOT__tick__56__a_used);
                            __Vfunc_tb_dehazing__DOT__clamp__59__Vfuncout 
                                = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__59__value)
                                    ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__59__value)
                                             ? 0xffU
                                             : __Vfunc_tb_dehazing__DOT__clamp__59__value));
                            __Vtask_tb_dehazing__DOT__tick__56__jb 
                                = __Vfunc_tb_dehazing__DOT__clamp__59__Vfuncout;
                            __Vtask_tb_dehazing__DOT__tick__56__gr 
                                = vlSelf->tb_dehazing__DOT__gamma_rom
                                [(0xffU & __Vtask_tb_dehazing__DOT__tick__56__jr)];
                            __Vtask_tb_dehazing__DOT__tick__56__gg 
                                = vlSelf->tb_dehazing__DOT__gamma_rom
                                [(0xffU & __Vtask_tb_dehazing__DOT__tick__56__jg)];
                            __Vtask_tb_dehazing__DOT__tick__56__gb 
                                = vlSelf->tb_dehazing__DOT__gamma_rom
                                [(0xffU & __Vtask_tb_dehazing__DOT__tick__56__jb)];
                            __Vtask_tb_dehazing__DOT__tick__56__processed 
                                = (((IData)(__Vtask_tb_dehazing__DOT__tick__56__gr) 
                                    << 0x16U) | ((0x300000U 
                                                  & ((IData)(__Vtask_tb_dehazing__DOT__tick__56__gr) 
                                                     << 0xeU)) 
                                                 | (((IData)(__Vtask_tb_dehazing__DOT__tick__56__gg) 
                                                     << 0xcU) 
                                                    | ((0xc00U 
                                                        & ((IData)(__Vtask_tb_dehazing__DOT__tick__56__gg) 
                                                           << 4U)) 
                                                       | (((IData)(__Vtask_tb_dehazing__DOT__tick__56__gb) 
                                                           << 2U) 
                                                          | (3U 
                                                             & ((IData)(__Vtask_tb_dehazing__DOT__tick__56__gb) 
                                                                >> 6U)))))));
                            vlSelf->tb_dehazing__DOT__ed[0U] 
                                = ((IData)(__Vtask_tb_dehazing__DOT__tick__56__selected)
                                    ? __Vtask_tb_dehazing__DOT__tick__56__processed
                                    : __Vtask_tb_dehazing__DOT__tick__56__pixel_i);
                        } else {
                            vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                            vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                        }
                    }
                    vlSelf->tb_dehazing__DOT__sync_mode 
                        = vlSelf->tb_dehazing__DOT__meta;
                    vlSelf->tb_dehazing__DOT__meta 
                        = __Vtask_tb_dehazing__DOT__tick__56__mode_i;
                } else {
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[1U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[2U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[3U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[4U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[5U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[6U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[7U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[8U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[9U] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ev[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h4ef19631__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1 = 0U;
                    vlSelf->tb_dehazing__DOT__es[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ee[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
                    vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1 = 0U;
                    vlSelf->tb_dehazing__DOT__ed[0xaU] 
                        = vlSelf->tb_dehazing__DOT____Vlvbound_hd103a873__1;
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
                    __Vtask_tb_dehazing__DOT__fail__60__reason = 
                        std::string{"ready contract"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__60__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                [0xaU] 
                                                >> 0x1eU))) 
                                 != vlSelf->tb_dehazing__DOT__ev
                                 [0xaU]))) {
                    __Vtask_tb_dehazing__DOT__fail__61__reason = 
                        std::string{"11 enabled-stage valid/reset/bubble timing"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__61__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY((((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                 [0xaU] 
                                                 >> 0x20U))) 
                                  != vlSelf->tb_dehazing__DOT__es
                                  [0xaU]) | ((1U & (IData)(
                                                           (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                            [0xaU] 
                                                            >> 0x1fU))) 
                                             != vlSelf->tb_dehazing__DOT__ee
                                             [0xaU])))) {
                    __Vtask_tb_dehazing__DOT__fail__62__reason = 
                        std::string{"ordered SOP/EOP"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__62__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY((vlSelf->tb_dehazing__DOT__ev
                                 [0xaU] & ((0x3fffffffU 
                                            & ((1U 
                                                & (IData)(
                                                          (vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                                           [0xaU] 
                                                           >> 0x21U)))
                                                ? (
                                                   (0x3fc00000U 
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
                    VL_WRITEF("expected=%x actual=%x\n",
                              30,vlSelf->tb_dehazing__DOT__ed
                              [0xaU],30,(0x3fffffffU 
                                         & ((1U & (IData)(
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
                    __Vtask_tb_dehazing__DOT__fail__63__reason = 
                        std::string{"ordered raw/processed pixel or frame mode"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__63__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                if (VL_UNLIKELY(((((IData)(__Vtask_tb_dehazing__DOT__tick__56__reset_i) 
                                   & (IData)(vlSelf->tb_dehazing__DOT__last_reset)) 
                                  & (~ (IData)(__Vtask_tb_dehazing__DOT__tick__56__ready_i))) 
                                 & ((((QData)((IData)(
                                                      (1U 
                                                       & (IData)(
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
                    __Vtask_tb_dehazing__DOT__fail__64__reason = 
                        std::string{"output changed while stalled (including mode changes)"};
                    VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                              32,vlSelf->tb_dehazing__DOT__seed,
                              32,vlSelf->tb_dehazing__DOT__accepted,
                              32,vlSelf->tb_dehazing__DOT__checks,
                              -1,&(__Vtask_tb_dehazing__DOT__fail__64__reason),
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name());
                    VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
                }
                vlSelf->tb_dehazing__DOT__last_output 
                    = (((QData)((IData)((1U & (IData)(
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
                                                                         [0xaU]))))))));
                vlSelf->tb_dehazing__DOT__last_reset 
                    = __Vtask_tb_dehazing__DOT__tick__56__reset_i;
                vlSelf->tb_dehazing__DOT__checks = 
                    ((IData)(1U) + vlSelf->tb_dehazing__DOT__checks);
            }
            vlSelf->tb_dehazing__DOT__pixel = ((IData)(1U) 
                                               + vlSelf->tb_dehazing__DOT__pixel);
        }
        tb_dehazing__DOT__frame = ((IData)(1U) + tb_dehazing__DOT__frame);
    }
    vlSelf->__Vtask_tb_dehazing__DOT__tick__65__reset_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__65__pixel_i = 0x3fffffffU;
    __Vtask_tb_dehazing__DOT__tick__65__mode_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__65__eop_i = 0U;
    __Vtask_tb_dehazing__DOT__tick__65__sop_i = 1U;
    __Vtask_tb_dehazing__DOT__tick__65__valid_i = 1U;
    vlSelf->__Vtask_tb_dehazing__DOT__tick__65__ready_i = 0U;
    co_await vlSelf->__VtrigSched_hff7db3c9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       45);
    vlSelf->tb_dehazing__DOT__src_ready = vlSelf->__Vtask_tb_dehazing__DOT__tick__65__ready_i;
    vlSelf->tb_dehazing__DOT__snk_valid = __Vtask_tb_dehazing__DOT__tick__65__valid_i;
    vlSelf->tb_dehazing__DOT__snk_sop = __Vtask_tb_dehazing__DOT__tick__65__sop_i;
    vlSelf->tb_dehazing__DOT__snk_eop = __Vtask_tb_dehazing__DOT__tick__65__eop_i;
    vlSelf->tb_dehazing__DOT__snk_data = __Vtask_tb_dehazing__DOT__tick__65__pixel_i;
    vlSelf->tb_dehazing__DOT__sw_bypass = __Vtask_tb_dehazing__DOT__tick__65__mode_i;
    vlSelf->tb_dehazing__DOT__rst_n = vlSelf->__Vtask_tb_dehazing__DOT__tick__65__reset_i;
    co_await vlSelf->__VtrigSched_hff7db318__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_dehazing.clk)", 
                                                       "/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 
                                                       48);
    if (vlSelf->__Vtask_tb_dehazing__DOT__tick__65__reset_i) {
        if (vlSelf->__Vtask_tb_dehazing__DOT__tick__65__ready_i) {
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
            if (__Vtask_tb_dehazing__DOT__tick__65__valid_i) {
                vlSelf->tb_dehazing__DOT__ev[0U] = 1U;
                vlSelf->tb_dehazing__DOT__es[0U] = __Vtask_tb_dehazing__DOT__tick__65__sop_i;
                vlSelf->tb_dehazing__DOT__ee[0U] = __Vtask_tb_dehazing__DOT__tick__65__eop_i;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
                vlSelf->tb_dehazing__DOT__accepted 
                    = ((IData)(1U) + vlSelf->tb_dehazing__DOT__accepted);
                __Vtask_tb_dehazing__DOT__tick__65__r 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__65__pixel_i 
                                >> 0x16U));
                __Vtask_tb_dehazing__DOT__tick__65__g 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__65__pixel_i 
                                >> 0xcU));
                __Vtask_tb_dehazing__DOT__tick__65__b 
                    = (0xffU & (__Vtask_tb_dehazing__DOT__tick__65__pixel_i 
                                >> 2U));
                __Vtask_tb_dehazing__DOT__tick__65__hi 
                    = (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__65__r, __Vtask_tb_dehazing__DOT__tick__65__g)
                        ? (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__65__r, __Vtask_tb_dehazing__DOT__tick__65__b)
                            ? __Vtask_tb_dehazing__DOT__tick__65__r
                            : __Vtask_tb_dehazing__DOT__tick__65__b)
                        : (VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__65__g, __Vtask_tb_dehazing__DOT__tick__65__b)
                            ? __Vtask_tb_dehazing__DOT__tick__65__g
                            : __Vtask_tb_dehazing__DOT__tick__65__b));
                __Vtask_tb_dehazing__DOT__tick__65__lo 
                    = (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__65__r, __Vtask_tb_dehazing__DOT__tick__65__g)
                        ? (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__65__r, __Vtask_tb_dehazing__DOT__tick__65__b)
                            ? __Vtask_tb_dehazing__DOT__tick__65__r
                            : __Vtask_tb_dehazing__DOT__tick__65__b)
                        : (VL_LTS_III(32, __Vtask_tb_dehazing__DOT__tick__65__g, __Vtask_tb_dehazing__DOT__tick__65__b)
                            ? __Vtask_tb_dehazing__DOT__tick__65__g
                            : __Vtask_tb_dehazing__DOT__tick__65__b));
                __Vtask_tb_dehazing__DOT__tick__65__t 
                    = vlSelf->tb_dehazing__DOT__transmission_rom
                    [(0xffffU & (VL_SHIFTL_III(16,32,32, __Vtask_tb_dehazing__DOT__tick__65__hi, 8U) 
                                 | __Vtask_tb_dehazing__DOT__tick__65__lo))];
                __Vtask_tb_dehazing__DOT__tick__65__t 
                    = (0x3ffU & __Vtask_tb_dehazing__DOT__tick__65__t);
                if (VL_GTS_III(32, 0x66U, __Vtask_tb_dehazing__DOT__tick__65__t)) {
                    __Vtask_tb_dehazing__DOT__tick__65__t = 0x66U;
                }
                __Vtask_tb_dehazing__DOT__tick__65__inv 
                    = (VL_GTS_III(32, 0x64U, __Vtask_tb_dehazing__DOT__tick__65__t)
                        ? 0x2800U : VL_DIVS_III(32, (IData)(0x100000U), __Vtask_tb_dehazing__DOT__tick__65__t));
                __Vtask_tb_dehazing__DOT__tick__65__inv 
                    = (0x3fffU & __Vtask_tb_dehazing__DOT__tick__65__inv);
                __Vtask_tb_dehazing__DOT__tick__65__a_used 
                    = vlSelf->tb_dehazing__DOT__atmosphere;
                if (__Vtask_tb_dehazing__DOT__tick__65__sop_i) {
                    __Vtask_tb_dehazing__DOT__tick__65__selected 
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
                    __Vtask_tb_dehazing__DOT__tick__65__selected 
                        = vlSelf->tb_dehazing__DOT__frame_mode;
                    if ((VL_GTS_III(32, 0xdcU, __Vtask_tb_dehazing__DOT__tick__65__t) 
                         & VL_GTS_III(32, __Vtask_tb_dehazing__DOT__tick__65__hi, vlSelf->tb_dehazing__DOT__maximum))) {
                        vlSelf->tb_dehazing__DOT__maximum 
                            = __Vtask_tb_dehazing__DOT__tick__65__hi;
                    }
                }
                __Vfunc_tb_dehazing__DOT__clamp__66__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__65__r 
                                                             - __Vtask_tb_dehazing__DOT__tick__65__a_used), __Vtask_tb_dehazing__DOT__tick__65__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__65__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__66__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__66__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__66__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__66__value));
                __Vtask_tb_dehazing__DOT__tick__65__jr 
                    = __Vfunc_tb_dehazing__DOT__clamp__66__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__67__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__65__g 
                                                             - __Vtask_tb_dehazing__DOT__tick__65__a_used), __Vtask_tb_dehazing__DOT__tick__65__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__65__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__67__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__67__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__67__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__67__value));
                __Vtask_tb_dehazing__DOT__tick__65__jg 
                    = __Vfunc_tb_dehazing__DOT__clamp__67__Vfuncout;
                __Vfunc_tb_dehazing__DOT__clamp__68__value 
                    = (VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, 
                                                            (__Vtask_tb_dehazing__DOT__tick__65__b 
                                                             - __Vtask_tb_dehazing__DOT__tick__65__a_used), __Vtask_tb_dehazing__DOT__tick__65__inv), 0xaU) 
                       + __Vtask_tb_dehazing__DOT__tick__65__a_used);
                __Vfunc_tb_dehazing__DOT__clamp__68__Vfuncout 
                    = (VL_GTS_III(32, 0U, __Vfunc_tb_dehazing__DOT__clamp__68__value)
                        ? 0U : (VL_LTS_III(32, 0xffU, __Vfunc_tb_dehazing__DOT__clamp__68__value)
                                 ? 0xffU : __Vfunc_tb_dehazing__DOT__clamp__68__value));
                __Vtask_tb_dehazing__DOT__tick__65__jb 
                    = __Vfunc_tb_dehazing__DOT__clamp__68__Vfuncout;
                __Vtask_tb_dehazing__DOT__tick__65__gr 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__65__jr)];
                __Vtask_tb_dehazing__DOT__tick__65__gg 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__65__jg)];
                __Vtask_tb_dehazing__DOT__tick__65__gb 
                    = vlSelf->tb_dehazing__DOT__gamma_rom
                    [(0xffU & __Vtask_tb_dehazing__DOT__tick__65__jb)];
                __Vtask_tb_dehazing__DOT__tick__65__processed 
                    = (((IData)(__Vtask_tb_dehazing__DOT__tick__65__gr) 
                        << 0x16U) | ((0x300000U & ((IData)(__Vtask_tb_dehazing__DOT__tick__65__gr) 
                                                   << 0xeU)) 
                                     | (((IData)(__Vtask_tb_dehazing__DOT__tick__65__gg) 
                                         << 0xcU) | 
                                        ((0xc00U & 
                                          ((IData)(__Vtask_tb_dehazing__DOT__tick__65__gg) 
                                           << 4U)) 
                                         | (((IData)(__Vtask_tb_dehazing__DOT__tick__65__gb) 
                                             << 2U) 
                                            | (3U & 
                                               ((IData)(__Vtask_tb_dehazing__DOT__tick__65__gb) 
                                                >> 6U)))))));
                vlSelf->tb_dehazing__DOT__ed[0U] = 
                    ((IData)(__Vtask_tb_dehazing__DOT__tick__65__selected)
                      ? __Vtask_tb_dehazing__DOT__tick__65__processed
                      : __Vtask_tb_dehazing__DOT__tick__65__pixel_i);
            } else {
                vlSelf->tb_dehazing__DOT__ev[0U] = 0U;
                vlSelf->tb_dehazing__DOT__es[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ee[0U] = 0U;
                vlSelf->tb_dehazing__DOT__ed[0U] = 0U;
            }
        }
        vlSelf->tb_dehazing__DOT__sync_mode = vlSelf->tb_dehazing__DOT__meta;
        vlSelf->tb_dehazing__DOT__meta = __Vtask_tb_dehazing__DOT__tick__65__mode_i;
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
        __Vtask_tb_dehazing__DOT__fail__69__reason = 
            std::string{"ready contract"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__69__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
    if (VL_UNLIKELY(((1U & (IData)((vlSelf->tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages
                                    [0xaU] >> 0x1eU))) 
                     != vlSelf->tb_dehazing__DOT__ev
                     [0xaU]))) {
        __Vtask_tb_dehazing__DOT__fail__70__reason = 
            std::string{"11 enabled-stage valid/reset/bubble timing"};
        VL_WRITEF("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %@\n[%0t] %%Fatal: tb_dehazing.sv:35: Assertion failed in %Ntb_dehazing.fail: scoreboard failure\n",
                  32,vlSelf->tb_dehazing__DOT__seed,
                  32,vlSelf->tb_dehazing__DOT__accepted,
                  32,vlSelf->tb_dehazing__DOT__checks,
                  -1,&(__Vtask_tb_dehazing__DOT__fail__70__reason),
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/mnt/c/Users/Duy Khanh/OneDrive/Desktop/Research/fpga-vision-enhancement/hardware v1/verification/tb_dehazing.sv", 35, "");
    }
}
