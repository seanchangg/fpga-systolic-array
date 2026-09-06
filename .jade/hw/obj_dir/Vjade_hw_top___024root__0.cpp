// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vjade_hw_top.h for the primary calling header

#include "Vjade_hw_top__pch.h"

void Vjade_hw_top___024root___eval(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
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
