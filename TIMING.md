# Timing and resource analysis

MAX 10 FPGA, Quartus Prime Lite in Docker. Commands run from the project
directory, for example `sys_array`.

## 1. Compile

```
cd sys_array
make -f ../Makefile PROJECT=systolic
```

Needs `systolic.qpf`, `systolic.qsf`, `systolic.sdc`, and `systolic.v`.

## 2. Read the resource count

```
cat output_files/systolic.fit.summary
```

"Total logic elements" is the number to track. Check the multiplier line.
A multiply that does not fit the 9-bit blocks becomes logic. For the cost
of each module:

```
grep -A30 "Utilization by Entity" output_files/systolic.fit.rpt
```

## 3. Read Fmax

```
grep -A4 "Slow 1200mV 85C Model Fmax Summary" output_files/systolic.sta.rpt
```

Use the slow 85C model. It is the worst case. Positive setup slack in
`systolic.sta.summary` means the design meets the SDC clock.

Fmax is empty when no register-to-register path exists. Add input
registers to the module, then compile again.

## 4. Find the critical path

Write `sta.tcl` in the project directory:

```
project_open systolic
create_timing_netlist
read_sdc
update_timing_netlist
report_timing -setup -npaths 5 -detail full_path -file paths.txt
```

Run it:

```
~/quartus-build/q quartus_sta -t sta.tcl
```

`paths.txt` lists the slowest paths with the delay of each cell.

To include the pin paths, add these two lines before
`update_timing_netlist`:

```
set_input_delay -clock clk 0 [all_inputs]
set_output_delay -clock clk 0 [all_outputs]
```

## 5. Check the synthesis warnings

```
grep "Warning (1024" output_files/systolic.map.rpt
```

Code 10240 is an inferred latch. Code 10230 is a truncated value. Fix
both before you trust the timing numbers.
