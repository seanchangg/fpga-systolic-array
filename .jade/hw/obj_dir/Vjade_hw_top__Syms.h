// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VJADE_HW_TOP__SYMS_H_
#define VERILATED_VJADE_HW_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vjade_hw_top.h"

// INCLUDE MODULE CLASSES
#include "Vjade_hw_top___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vjade_hw_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vjade_hw_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vjade_hw_top___024root         TOP;

    // CONSTRUCTORS
    Vjade_hw_top__Syms(VerilatedContext* contextp, const char* namep, Vjade_hw_top* modelp);
    ~Vjade_hw_top__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
