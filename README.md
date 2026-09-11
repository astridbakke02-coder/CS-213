# CS-213: Machine Organization and Assembly Language

A collection of low-level bit-level manipulation and two's complement arithmetic puzzles implemented in **C**.

## About the Lab
This project explores computer systems, hardware-level data representation, and integer/floating-point encodings. It involves solving constraints using restricted sets of operators to deepen understanding of how computers execute low-level arithmetic and logic.

### Key Puzzles Implemented:
* **Bitwise Logic:** Custom implementations of `OR` and `XOR` using only `~` and `&`.
* **Bit & Byte Manipulation:** Swapping bits, swapping bytes at specific indices, and isolating the least significant bit.
* **Integer Properties:** Checking for `TMax` limits, evaluating positivity, and handling conditional logic.
* **Floating Point:** Generating bit representations for normalized numbers and handling float negation (including `NaN` edge cases).

## Running the Code
To compile and test the functions locally using `gcc`:

```bash
gcc -o puzzle_test your_file.c
./puzzle_test
