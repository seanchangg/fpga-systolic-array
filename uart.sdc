create_clock -name clk -period 20.000 [get_ports clk]
derive_clock_uncertainty

# The serial pins and the push button are asynchronous to clk. The
# receiver resynchronises them, so the fitter must not time them.
set_false_path -from [get_ports {rxd button}] -to [all_registers]
set_false_path -from [all_registers] -to [get_ports {txd led[*]}]
