// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vjade_hw_top.h for the primary calling header

#include "Vjade_hw_top__pch.h"

void Vjade_hw_top___024root___ctor_var_reset(Vjade_hw_top___024root* vlSelf);

Vjade_hw_top___024root::Vjade_hw_top___024root(Vjade_hw_top__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vjade_hw_top___024root___ctor_var_reset(this);
}

void Vjade_hw_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vjade_hw_top___024root::~Vjade_hw_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
