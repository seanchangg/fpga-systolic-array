// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vjade_hw_top.h for the primary calling header

#include "Vjade_hw_top__pch.h"

VL_ATTR_COLD void Vjade_hw_top___024root___eval_static(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_static\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vjade_hw_top___024root___eval_initial(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_initial\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.led = 0x1fU;
    }
}

VL_ATTR_COLD void Vjade_hw_top___024root___eval_final(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_final\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vjade_hw_top___024root___eval_settle(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_settle\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vjade_hw_top___024root___ctor_var_reset(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___ctor_var_reset\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = 0;
    vlSelf->pb = 0;
    vlSelf->dipsw = 0;
    vlSelf->led = 0;
}
