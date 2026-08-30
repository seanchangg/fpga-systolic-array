// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vjade_hw_top.h for the primary calling header

#ifndef VERILATED_VJADE_HW_TOP___024ROOT_H_
#define VERILATED_VJADE_HW_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vjade_hw_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vjade_hw_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(pb,3,0);
    VL_IN8(dipsw,4,0);
    VL_OUT8(led,4,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*25:0*/ jade_hw_top__DOT__u_top__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vjade_hw_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vjade_hw_top___024root(Vjade_hw_top__Syms* symsp, const char* namep);
    ~Vjade_hw_top___024root();
    VL_UNCOPYABLE(Vjade_hw_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
