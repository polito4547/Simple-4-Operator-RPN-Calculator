# RPN Stack Calculator (C Memory Study)
A stack-based Reverse Polish Notation (RPN) calculator built in C. This project serves as a deep dive into manual memory management, shifting away from high-level abstractions to work directly with the heap and registers.

# The Engineering Challenge
Most entry-level calculators use simple variables or high-level lists to store data. This project was intentionally refactored from a "typical" implementation to a low-level systems approach to explore:

Manual Heap Allocation: Utilizing malloc and free to manage the lifecycle of the calculator's memory.

Buffer Manipulation: Using memmove to shift data within "registers," simulating how a CPU or hardware stack handles incoming data.

Pointer Arithmetic: Managing a register_ptr to ensure precision during calculation and data movement.

# Logic & Architecture
The calculator utilizes a "shift-back" logic. When a new value is entered:

The value at index 1 (the working register) is moved to index 0 (the history/stack).

memmove handles this shift to ensure data integrity.

The new input is placed into the now-vacant index 1.

# How to Build
Any C compiler would work.
