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
    CData/*0:0*/ jade_hw_top__DOT__u_top__DOT__we;
    CData/*3:0*/ jade_hw_top__DOT__u_top__DOT__leds;
    CData/*1:0*/ jade_hw_top__DOT__u_top__DOT__btn_s;
    CData/*7:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data;
    CData/*0:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_valid;
    CData/*7:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_data;
    CData/*0:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send;
    CData/*0:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy;
    CData/*2:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n;
    CData/*0:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending;
    CData/*0:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending;
    CData/*1:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn;
    CData/*3:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__bitn;
    CData/*1:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state;
    CData/*2:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__bitn;
    CData/*1:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    SData/*15:0*/ jade_hw_top__DOT__u_top__DOT__addr;
    SData/*8:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__shift;
    SData/*15:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count;
    SData/*15:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count;
    IData/*31:0*/ jade_hw_top__DOT__u_top__DOT__wdata;
    IData/*31:0*/ jade_hw_top__DOT__u_top__DOT__scratch;
    IData/*31:0*/ jade_hw_top__DOT__u_top__DOT__uptime;
    IData/*31:0*/ jade_hw_top__DOT__u_top__DOT__wrcount;
    IData/*31:0*/ jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b;
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
