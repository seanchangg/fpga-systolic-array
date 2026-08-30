// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vjade_hw_top__pch.h"

//============================================================
// Constructors

Vjade_hw_top::Vjade_hw_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vjade_hw_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , pb{vlSymsp->TOP.pb}
    , dipsw{vlSymsp->TOP.dipsw}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vjade_hw_top::Vjade_hw_top(const char* _vcname__)
    : Vjade_hw_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vjade_hw_top::~Vjade_hw_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vjade_hw_top___024root___eval_debug_assertions(Vjade_hw_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vjade_hw_top___024root___eval_static(Vjade_hw_top___024root* vlSelf);
void Vjade_hw_top___024root___eval_initial(Vjade_hw_top___024root* vlSelf);
void Vjade_hw_top___024root___eval_settle(Vjade_hw_top___024root* vlSelf);
void Vjade_hw_top___024root___eval(Vjade_hw_top___024root* vlSelf);

void Vjade_hw_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vjade_hw_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vjade_hw_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vjade_hw_top___024root___eval_static(&(vlSymsp->TOP));
        Vjade_hw_top___024root___eval_initial(&(vlSymsp->TOP));
        Vjade_hw_top___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vjade_hw_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vjade_hw_top::eventsPending() { return false; }

uint64_t Vjade_hw_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vjade_hw_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vjade_hw_top___024root___eval_final(Vjade_hw_top___024root* vlSelf);

VL_ATTR_COLD void Vjade_hw_top::final() {
    contextp()->executingFinal(true);
    Vjade_hw_top___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vjade_hw_top::hierName() const { return vlSymsp->name(); }
const char* Vjade_hw_top::modelName() const { return "Vjade_hw_top"; }
unsigned Vjade_hw_top::threads() const { return 1; }
void Vjade_hw_top::prepareClone() const { contextp()->prepareClone(); }
void Vjade_hw_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
