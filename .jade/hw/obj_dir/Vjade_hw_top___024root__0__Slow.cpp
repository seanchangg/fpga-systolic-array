// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vjade_hw_top.h for the primary calling header

#include "Vjade_hw_top__pch.h"

VL_ATTR_COLD void Vjade_hw_top___024root___eval_static(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_static\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.jade_hw_top__DOT__u_top__DOT__count = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vjade_hw_top___024root___eval_initial(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_initial\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vjade_hw_top___024root___eval_final(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_final\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vjade_hw_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vjade_hw_top___024root___eval_phase__stl(Vjade_hw_top___024root* vlSelf);

VL_ATTR_COLD void Vjade_hw_top___024root___eval_settle(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_settle\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vjade_hw_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/seanchang/projects/fpga/.jade/hw/jade_hw_top.v", 4, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vjade_hw_top___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vjade_hw_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vjade_hw_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vjade_hw_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vjade_hw_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD bool Vjade_hw_top___024root___eval_phase__stl(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___eval_phase__stl\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vjade_hw_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vjade_hw_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
                    vlSelfRef.led = (0x0000001fU & 
                                     (~ ((0x0000001eU 
                                          & (vlSelfRef.jade_hw_top__DOT__u_top__DOT__count 
                                             >> 0x00000015U)) 
                                         | (1U & (vlSelfRef.jade_hw_top__DOT__u_top__DOT__count 
                                                  >> 0x00000019U)))));
                }
            }
        }
    }
    return (__VstlExecute);
}

bool Vjade_hw_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vjade_hw_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vjade_hw_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vjade_hw_top___024root___ctor_var_reset(Vjade_hw_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vjade_hw_top___024root___ctor_var_reset\n"); );
    Vjade_hw_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = 0;
    vlSelf->pb = 0;
    vlSelf->dipsw = 0;
    vlSelf->led = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
