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
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    vlSelfRef.jade_hw_top__DOT__u_top__DOT__count 
                        = (0x03ffffffU & ((IData)(1U) 
                                          + vlSelfRef.jade_hw_top__DOT__u_top__DOT__count));
                    vlSelfRef.led = (0x0000001fU & 
                                     (~ ((0x0000001eU 
                                          & (vlSelfRef.jade_hw_top__DOT__u_top__DOT__count 
                                             >> 0x00000015U)) 
                                         | (1U & (vlSelfRef.jade_hw_top__DOT__u_top__DOT__count 
                                                  >> 0x00000019U)))));
                }
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
