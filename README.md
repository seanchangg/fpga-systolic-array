<img width="387" height="303" alt="Screenshot 2026-09-22 at 10 07 03 PM" src="https://github.com/user-attachments/assets/4d6eded3-c76b-4c3d-afc3-6251d69c7072" />
Hardest part of this mini-project was conceptualizing the clock edges, how data moved between shift registers within each processing unit, and consequently determining the best offset for max utilization. 
Spent a while banging my head against the wall to figure this out, but each "ripple" is 2 clock cycles. This implementation is 50mHZ target with 13 slack. 
