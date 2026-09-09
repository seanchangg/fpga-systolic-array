// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vjade_hw_top.h for the primary calling header

#include "Vjade_hw_top__pch.h"

bool Vjade_hw_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vjade_hw_top___024root___nba_sequent__TOP__0(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___nba_sequent__TOP__0\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__uptime;
    __Vdly__jade_hw_top__DOT__u_top__DOT__uptime = 0;
    CData/*1:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__btn_s;
    __Vdly__jade_hw_top__DOT__u_top__DOT__btn_s = 0;
    IData/*31:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__scratch;
    __Vdly__jade_hw_top__DOT__u_top__DOT__scratch = 0;
    IData/*31:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__wrcount;
    __Vdly__jade_hw_top__DOT__u_top__DOT__wrcount = 0;
    CData/*3:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__leds;
    __Vdly__jade_hw_top__DOT__u_top__DOT__leds = 0;
    CData/*0:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send = 0;
    CData/*2:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n = 0;
    SData/*15:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__addr;
    __Vdly__jade_hw_top__DOT__u_top__DOT__addr = 0;
    CData/*0:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending = 0;
    IData/*31:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out = 0;
    CData/*0:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending = 0;
    CData/*1:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn = 0;
    SData/*15:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count = 0;
    CData/*0:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy = 0;
    CData/*1:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync = 0;
    CData/*1:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state = 0;
    SData/*15:0*/ __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count = 0;
    CData/*7:0*/ __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0;
    __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0 = 0;
    CData/*0:0*/ __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0;
    __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0 = 0;
    CData/*7:0*/ __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1;
    __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1 = 0;
    CData/*2:0*/ __VdlyDim0__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1;
    __VdlyDim0__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1 = 0;
    CData/*0:0*/ __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1;
    __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1 = 0;
    // Body
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync;
    __Vdly__jade_hw_top__DOT__u_top__DOT__btn_s = vlSelfRef.jade_hw_top__DOT__u_top__DOT__btn_s;
    __Vdly__jade_hw_top__DOT__u_top__DOT__uptime = vlSelfRef.jade_hw_top__DOT__u_top__DOT__uptime;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n;
    __Vdly__jade_hw_top__DOT__u_top__DOT__addr = vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn;
    __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0 = 0U;
    __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1 = 0U;
    __Vdly__jade_hw_top__DOT__u_top__DOT__wrcount = vlSelfRef.jade_hw_top__DOT__u_top__DOT__wrcount;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy 
        = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy;
    __Vdly__jade_hw_top__DOT__u_top__DOT__scratch = vlSelfRef.jade_hw_top__DOT__u_top__DOT__scratch;
    __Vdly__jade_hw_top__DOT__u_top__DOT__leds = vlSelfRef.jade_hw_top__DOT__u_top__DOT__leds;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync 
        = (1U | (2U & ((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync) 
                       << 1U)));
    __Vdly__jade_hw_top__DOT__u_top__DOT__btn_s = (
                                                   (2U 
                                                    & ((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__btn_s) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (IData)(vlSelfRef.pb)));
    __Vdly__jade_hw_top__DOT__u_top__DOT__uptime = 
        ((IData)(1U) + vlSelfRef.jade_hw_top__DOT__u_top__DOT__uptime);
    if (vlSelfRef.jade_hw_top__DOT__u_top__DOT__we) {
        __Vdly__jade_hw_top__DOT__u_top__DOT__wrcount 
            = ((IData)(1U) + vlSelfRef.jade_hw_top__DOT__u_top__DOT__wrcount);
        if ((4U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))) {
            __Vdly__jade_hw_top__DOT__u_top__DOT__scratch 
                = vlSelfRef.jade_hw_top__DOT__u_top__DOT__wdata;
        }
        if ((4U != (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))) {
            if ((8U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))) {
                __Vdly__jade_hw_top__DOT__u_top__DOT__leds 
                    = (0x0000000fU & vlSelfRef.jade_hw_top__DOT__u_top__DOT__wdata);
            }
        }
    }
    if (vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy) {
        if ((0x01b1U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count))) {
            vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__shift 
                = (0x00000100U | (0x000000ffU & ((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__shift) 
                                                 >> 1U)));
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count = 0U;
            if ((9U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__bitn))) {
                __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy = 0U;
            } else {
                vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__bitn 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__bitn)));
            }
        } else {
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count 
                = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count)));
        }
    } else if (vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send) {
        vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__shift 
            = (0x00000100U | (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_data));
        vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__bitn = 0U;
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count = 0U;
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy = 1U;
    }
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_tx__DOT__count;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__we = 0U;
    __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send = 0U;
    if (vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_valid) {
        if ((0U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n))) {
            if (((0x57U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data)) 
                 | (0x52U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data)))) {
                __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0 
                    = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data;
                __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0 = 1U;
                __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n = 1U;
            }
        } else if (((0x52U == vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[0U]) 
                    & (2U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n)))) {
            __Vdly__jade_hw_top__DOT__u_top__DOT__addr 
                = (((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[1U]) 
                    << 8U) | (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data));
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending = 1U;
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n = 0U;
        } else if (((0x57U == vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[0U]) 
                    & (6U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n)))) {
            __Vdly__jade_hw_top__DOT__u_top__DOT__addr 
                = (((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[1U]) 
                    << 8U) | vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[2U]);
            vlSelfRef.jade_hw_top__DOT__u_top__DOT__we = 1U;
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n = 0U;
            vlSelfRef.jade_hw_top__DOT__u_top__DOT__wdata 
                = (((((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[3U]) 
                      << 8U) | vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[4U]) 
                    << 0x00000010U) | (((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[5U]) 
                                        << 8U) | (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data)));
        } else {
            __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1 
                = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data;
            __VdlyDim0__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1 
                = vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n;
            __VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1 = 1U;
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n)));
        }
    }
    if (((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending) 
         & (~ (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending)))) {
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out 
            = ((0U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))
                ? 0x55415254U : ((4U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))
                                  ? vlSelfRef.jade_hw_top__DOT__u_top__DOT__scratch
                                  : ((8U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))
                                      ? (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__leds)
                                      : ((0x000cU == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))
                                          ? (1U & (~ 
                                                   ((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__btn_s) 
                                                    >> 1U)))
                                          : ((0x0010U 
                                              == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))
                                              ? vlSelfRef.jade_hw_top__DOT__u_top__DOT__uptime
                                              : ((0x0014U 
                                                  == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr))
                                                  ? vlSelfRef.jade_hw_top__DOT__u_top__DOT__wrcount
                                                  : 0xdeadbeefU))))));
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending = 0U;
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending = 1U;
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn = 0U;
    } else if ((((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending) 
                 & (~ (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy))) 
                & (~ (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send)))) {
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn)));
        vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_data 
            = (vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out 
               >> 0x18U);
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send = 1U;
        if ((3U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn))) {
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending = 0U;
        }
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out 
            = (vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out 
               << 8U);
    }
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__scratch 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__scratch;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__n;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__pending;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__btn_s = __Vdly__jade_hw_top__DOT__u_top__DOT__btn_s;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__wrcount 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__wrcount;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__out;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__sending;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__txn;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_busy;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__tx_send;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__addr = __Vdly__jade_hw_top__DOT__u_top__DOT__addr;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__leds = __Vdly__jade_hw_top__DOT__u_top__DOT__leds;
    if (__VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0) {
        vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[0U] 
            = __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v0;
    }
    if (__VdlySet__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1) {
        vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b[__VdlyDim0__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1] 
            = __VdlyVal__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__b__v1;
    }
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__uptime 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__uptime;
    vlSelfRef.led = (0x0000001fU & (~ ((0x00000010U 
                                        & (vlSelfRef.jade_hw_top__DOT__u_top__DOT__uptime 
                                           >> 0x00000014U)) 
                                       | (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__leds))));
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_valid = 0U;
    if ((2U & (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state))) {
            if ((0x01b1U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count))) {
                vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_valid = 1U;
                __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state = 0U;
            } else {
                __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count)));
            }
        } else if ((0x01b1U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count))) {
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count = 0U;
            vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data 
                = (((~ ((IData)(1U) << (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__bitn))) 
                    & (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__rx_data)) 
                   | (0x00ffU & ((1U & ((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync) 
                                        >> 1U)) << (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__bitn))));
            if ((7U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__bitn))) {
                __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state = 3U;
            } else {
                vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__bitn 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__bitn)));
            }
        } else {
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count 
                = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count)));
        }
    } else if ((1U & (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state))) {
        if ((0x00d8U == (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count))) {
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count = 0U;
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state 
                = ((2U & (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync))
                    ? 0U : 2U);
        } else {
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count 
                = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count)));
        }
    } else {
        vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__bitn = 0U;
        __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count = 0U;
        if ((1U & (~ ((IData)(vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync) 
                      >> 1U)))) {
            __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state = 1U;
        }
    }
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__state;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__count;
    vlSelfRef.jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync 
        = __Vdly__jade_hw_top__DOT__u_top__DOT__u_bridge__DOT__u_rx__DOT__sync;
}

void Vjade_hw_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vjade_hw_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vjade_hw_top___024root___eval_phase__act(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_phase__act\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vjade_hw_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vjade_hw_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vjade_hw_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vjade_hw_top___024root___eval_phase__nba(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_phase__nba\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vjade_hw_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vjade_hw_top___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vjade_hw_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vjade_hw_top___024root___eval(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vjade_hw_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/seanchang/projects/fpga/.jade/hw/jade_hw_top.v", 4, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vjade_hw_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/seanchang/projects/fpga/.jade/hw/jade_hw_top.v", 4, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vjade_hw_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vjade_hw_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vjade_hw_top___024root___eval_debug_assertions(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_debug_assertions\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.pb & 0xf0U)))) {
        Verilated::overWidthError("pb");
    }
    if (VL_UNLIKELY(((vlSelfRef.dipsw & 0xe0U)))) {
        Verilated::overWidthError("dipsw");
    }
}
#endif  // VL_DEBUG
