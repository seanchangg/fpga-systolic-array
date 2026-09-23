<img width="387" height="303" alt="Screenshot 2026-09-22 at 10 07 03 PM" src="https://github.com/user-attachments/assets/4d6eded3-c76b-4c3d-afc3-6251d69c7072" />

**Days 1-5:**
Learned about floating-point representation. Figured out how to multiply and add floats using combinatorial circuits. Used intermediate shift registers to store product and final sum to avoid super long and complicated circuits with barrel selectors.
\n**Days 5-7:**
Hardest part of this mini-project was conceptualizing the clock edges, how data moved between shift registers within each processing unit, and consequently determining the best offset for max utilization. Spent a while banging my head against the wall to figure this out, but each "ripple" is 2 clock cycles, with SysVerilog wire arrays for indexing and a manually written 2x2 systolic array. This implementation is 50mHZ target with 13 slack. Currently working on procedurally offsetting inputs and outputs to not have to write it by hand. 
