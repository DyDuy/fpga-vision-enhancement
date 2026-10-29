// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_dehazing.h for the primary calling header

#ifndef VERILATED_VTB_DEHAZING___024ROOT_H_
#define VERILATED_VTB_DEHAZING___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_dehazing__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_dehazing___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_dehazing__DOT__clk;
        CData/*0:0*/ tb_dehazing__DOT__rst_n;
        CData/*0:0*/ tb_dehazing__DOT__ar;
        CData/*0:0*/ tb_dehazing__DOT__sw_bypass;
        CData/*0:0*/ tb_dehazing__DOT__snk_valid;
        CData/*0:0*/ tb_dehazing__DOT__snk_sop;
        CData/*0:0*/ tb_dehazing__DOT__snk_eop;
        CData/*0:0*/ tb_dehazing__DOT__src_ready;
        CData/*0:0*/ tb_dehazing__DOT__snk_ready;
        CData/*0:0*/ tb_dehazing__DOT__meta;
        CData/*0:0*/ tb_dehazing__DOT__sync_mode;
        CData/*0:0*/ tb_dehazing__DOT__frame_mode;
        CData/*0:0*/ tb_dehazing__DOT__last_reset;
        CData/*0:0*/ tb_dehazing__DOT__av;
        CData/*0:0*/ tb_dehazing__DOT__aso;
        CData/*0:0*/ tb_dehazing__DOT__ae;
        CData/*7:0*/ tb_dehazing__DOT__aa;
        CData/*0:0*/ tb_dehazing__DOT__mode_value;
        CData/*0:0*/ tb_dehazing__DOT__bubble;
        CData/*0:0*/ tb_dehazing__DOT____Vlvbound_h4ef19631__0;
        CData/*0:0*/ tb_dehazing__DOT____Vlvbound_h783a9f4c__0;
        CData/*0:0*/ tb_dehazing__DOT____Vlvbound_ha6c45c6e__0;
        CData/*0:0*/ tb_dehazing__DOT____Vlvbound_h4ef19631__1;
        CData/*0:0*/ tb_dehazing__DOT____Vlvbound_h783a9f4c__1;
        CData/*0:0*/ tb_dehazing__DOT____Vlvbound_ha6c45c6e__1;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__mode_meta;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__mode_sync;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__frame_mode;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT____Vcellinp__sof_delay__i_data;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__v1;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__v3;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__v5;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__cmax_st1;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__cmin_st1;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__cmax_st2;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__cmin_st2;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__auto_Ag;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__sof_delay__DOT____Vlvbound_h72399335__0;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__st2__DOT__vd__DOT__d1__DOT__delay_reg;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__st3__DOT__v_a;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__st4__DOT__vd_st4__DOT__d1__DOT__delay_reg;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__st_ag__DOT__max_r;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__st_ag__DOT__p_m;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__a_st1;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__v_st1;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__a_st2;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__v_st2;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__v_st3;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__st6__DOT__g_r;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__st6__DOT__g_g;
        CData/*7:0*/ tb_dehazing__DOT__dut__DOT__st6__DOT__g_b;
        CData/*0:0*/ tb_dehazing__DOT__dut__DOT__st6__DOT__v_r1;
        CData/*7:0*/ tb_dehazing__DOT__probe__DOT__max_r;
        CData/*7:0*/ tb_dehazing__DOT__probe__DOT__p_m;
        CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__65__ready_i;
        CData/*0:0*/ __Vtask_tb_dehazing__DOT__tick__65__reset_i;
        CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0;
        CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1;
        CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2;
        CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3;
        CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4;
        CData/*0:0*/ __Vdlyvset__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v5;
        CData/*7:0*/ __Vdly__tb_dehazing__DOT__dut__DOT__auto_Ag;
        CData/*0:0*/ __VstlFirstIteration;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_dehazing__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_dehazing__DOT__rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_dehazing__DOT__ar__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ tb_dehazing__DOT__dut__DOT__t_raw;
        SData/*9:0*/ tb_dehazing__DOT__dut__DOT__t_ref;
        SData/*9:0*/ tb_dehazing__DOT__dut__DOT__st3__DOT__rom_q;
        SData/*13:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__inv_t;
        IData/*29:0*/ tb_dehazing__DOT__snk_data;
        IData/*31:0*/ tb_dehazing__DOT__atmosphere;
        IData/*31:0*/ tb_dehazing__DOT__maximum;
        IData/*31:0*/ tb_dehazing__DOT__checks;
        IData/*31:0*/ tb_dehazing__DOT__accepted;
        IData/*31:0*/ tb_dehazing__DOT__seed;
        IData/*23:0*/ tb_dehazing__DOT__ap;
        IData/*31:0*/ tb_dehazing__DOT__pixel;
        IData/*31:0*/ tb_dehazing__DOT__stall;
        IData/*29:0*/ tb_dehazing__DOT__value;
        IData/*29:0*/ tb_dehazing__DOT____Vlvbound_hd103a873__0;
        IData/*29:0*/ tb_dehazing__DOT____Vlvbound_hd103a873__1;
        IData/*23:0*/ tb_dehazing__DOT__dut__DOT__p_dehazed;
        IData/*23:0*/ tb_dehazing__DOT__dut__DOT__p_gamma;
        IData/*23:0*/ tb_dehazing__DOT__dut__DOT__ud_inst__DOT____Vlvbound_hc6205e02__0;
        IData/*17:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__r_d;
        IData/*17:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__g_d;
        IData/*17:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__b_d;
        IData/*31:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__r_mult;
        IData/*31:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__g_mult;
        IData/*31:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__b_mult;
        IData/*31:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__r_add;
        IData/*31:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__g_add;
        IData/*31:0*/ tb_dehazing__DOT__dut__DOT__st5__DOT__b_add;
        IData/*23:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v0;
        IData/*23:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v1;
        IData/*23:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v2;
        IData/*23:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v3;
        IData/*23:0*/ __Vdlyvval__tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages__v4;
        IData/*31:0*/ __VactIterCount;
        QData/*32:0*/ tb_dehazing__DOT__last_output;
        QData/*33:0*/ tb_dehazing__DOT__dut__DOT__global_sync__DOT____Vlvbound_hd2382cad__0;
        VlUnpacked<CData/*7:0*/, 256> tb_dehazing__DOT__gamma_rom;
        VlUnpacked<SData/*9:0*/, 65536> tb_dehazing__DOT__transmission_rom;
        VlUnpacked<CData/*0:0*/, 11> tb_dehazing__DOT__ev;
        VlUnpacked<CData/*0:0*/, 11> tb_dehazing__DOT__es;
        VlUnpacked<CData/*0:0*/, 11> tb_dehazing__DOT__ee;
        VlUnpacked<IData/*29:0*/, 11> tb_dehazing__DOT__ed;
        VlUnpacked<QData/*33:0*/, 11> tb_dehazing__DOT__dut__DOT__global_sync__DOT__stages;
        VlUnpacked<CData/*0:0*/, 5> tb_dehazing__DOT__dut__DOT__sof_delay__DOT__stages;
        VlUnpacked<SData/*9:0*/, 65536> tb_dehazing__DOT__dut__DOT__st3__DOT__transmission_lut;
        VlUnpacked<IData/*23:0*/, 5> tb_dehazing__DOT__dut__DOT__ud_inst__DOT__stages;
        VlUnpacked<SData/*13:0*/, 1024> tb_dehazing__DOT__dut__DOT__st5__DOT__uinv__DOT__rom;
        VlUnpacked<CData/*7:0*/, 256> tb_dehazing__DOT__dut__DOT__st6__DOT__lut_r__DOT__rom;
        VlUnpacked<CData/*7:0*/, 256> tb_dehazing__DOT__dut__DOT__st6__DOT__lut_g__DOT__rom;
        VlUnpacked<CData/*7:0*/, 256> tb_dehazing__DOT__dut__DOT__st6__DOT__lut_b__DOT__rom;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hff7db3c9__0;
    VlTriggerScheduler __VtrigSched_hff7db318__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<5> __VactTriggered;
    VlTriggerVec<5> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_dehazing__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_dehazing___024root(Vtb_dehazing__Syms* symsp, const char* v__name);
    ~Vtb_dehazing___024root();
    VL_UNCOPYABLE(Vtb_dehazing___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
