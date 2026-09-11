#include <stdio.h>

// Sample puzzle
// Input: none
// Return value: Tmin
int tmin() {
    return 1 << 31;
}

// Puzzle 1 - bitwiseOr
// Input: two integers x and y
// Return value: x | y using only ~ and &
int bitwiseOr(int x, int y) {
    return ~(~x & ~y);
}

// Puzzle 2 - bitXor
// Input: two integers x and y
// Return value: x ^ y using only ~ and &
int bitXor(int x, int y) {
    int onesx = (x & ~y);
    int onesy = (~x & y);
    return ~(~onesx & ~onesy);
}

// Puzzle 3 - copyLeastSigBit
// Input: integer x
// Return value: all 0s if LSB is 0, all 1s if LSB is 1
int copyLeastSigBit(int x) {
    int lastbit = (x & 1);
    return (~lastbit + 1);
}

// Puzzle 4 - equalsTMax
// Input: integer x
// Return value: 1 if x is 0x7FFFFFFF, 0 otherwise
int equalsTMax(int x) {
    int plusOne = (x + 1);
    int checkOne = !(x ^ ~plusOne);
    int checkTwo = !!(plusOne);
    return (checkOne & checkTwo);
}

// Puzzle 5 - swapBits
// Input: unsigned integer x
// Return value: x with even and odd bits swapped
unsigned int swapBits(unsigned int x) {
    unsigned int evenbits = (x & 0xAAAAAAAA);
    unsigned int oddbits = (x & 0x55555555);
    unsigned int swap = (evenbits >> 1) | (oddbits << 1);
    return swap;
}

// Puzzle 6 - swappingBytes
// Input: integer x, byte positions m and n
// Return value: x with bytes at m and n swapped
int swappingBytes(int x, int m, int n) {
    int shiftM = m << 3;
    int shiftN = n << 3;
    int byteM = (x >> shiftM) & 0xFF;
    int byteN = (x >> shiftN) & 0xFF;
    int maskM = (0xFF << shiftM);
    int maskN = (0xFF << shiftN);
    int clearByte = x & ~(maskM | maskN);
    return clearByte | (byteM << shiftN) | (byteN << shiftM);
}

// Puzzle 7 - isPositive
// Input: integer x
// Return value: 1 if x > 0, 0 otherwise
int isPositive(int x) {
    int isNegative = (x >> 31) & 1;
    int isZero = !x;
    return !(isNegative | isZero);
}

// Puzzle 8 - cond
// Input: integers x, y, and z
// Return value: y if x is non-zero, z if x is zero
int cond(int x, int y, int z) {
    // Turn x into 0 or 1
    int checkx = !!x;
    // Mask to all 1s or all 0s
    int maskx = (~checkx + 1);
    return (maskx & y) | (~maskx & z);
}

// Puzzle 9 - create_largest_normalized
// Input: none
// Return value: bit representation of largest normalized float number
unsigned create_largest_normalized() {
    unsigned exp = (0xFE << 23);
    unsigned frac = ((1 << 23) - 1);
    return exp | frac;
}

// Puzzle 10 - float_negate
// Input: unsigned int f (float bit pattern)
// Return value: bit pattern of -f (unless NaN, then return f)
unsigned float_negate(unsigned f) {
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = (f & 0x7FFFFF);
    
    // Check if f is NaN
    if ((exp == 0xFF) && (frac != 0)) {
        return f;
    }
    
    // Flip sign bit
    return f ^ 0x80000000;
}

int main() {
    // Test tmin()
    printf("Test tmin():\n");
    int x = tmin();
    printf("    Tmin Decimal format: %d\n", x);
    printf("    Tmin Hexadecimal format: %x\n\n", x);

    // Test bitwiseOr()
    printf("Test bitwiseOr():\n");
    int p = bitwiseOr(6, 5);
    printf("    bitwiseOr(6, 5) -> Result: %d\n\n", p);

    // Test bitXor()
    printf("Test bitXor():\n");
    int k = bitXor(4, 5);
    printf("    bitXor(4, 5) -> Result: %d\n\n", k);

    // Test copyLeastSigBit()
    printf("Test copyLeastSigBit():\n");
    printf("    copyLeastSigBit(5) -> Result: 0x%08X\n\n", copyLeastSigBit(5));

    // Test equalsTMax()
    printf("Test equalsTMax():\n");
    printf("    equalsTMax(0x7FFFFFFF) -> Result: %d\n\n", equalsTMax(0x7FFFFFFF));

    // Test swapBits()
    printf("Test swapBits():\n");
    printf("    swapBits(0xAAAAAAAA) -> Result: 0x%08X\n\n", swapBits(0xAAAAAAAA));

    // Test swappingBytes()
    printf("Test swappingBytes():\n");
    printf("    swappingBytes(0x12345678, 1, 3) -> Result: 0x%08X\n\n", swappingBytes(0x12345678, 1, 3));

    // Test isPositive()
    printf("Test isPositive():\n");
    printf("    isPositive(5) -> Result: %d\n\n", isPositive(5));

    // Test cond()
    printf("Test cond():\n");
    printf("    cond(2, 4, 5) -> Result: %d\n\n", cond(2, 4, 5));

    // Test create_largest_normalized()
    printf("Test create_largest_normalized():\n");
    unsigned bits = create_largest_normalized();
    printf("    Largest Normalized (Hex): 0x%X\n\n", bits);

    // Test float_negate()
    printf("Test float_negate():\n");
    unsigned p1 = 0x3F800000;
    printf("    Input:  0x%08X\n", p1);
    printf("    Output: 0x%08X\n\n", float_negate(p1));

    printf("  (And with NaN):\n");
    unsigned p4 = 0x7F800001;
    printf("    Input:  0x%08X\n", p4);
    printf("    Output: 0x%08X\n\n", float_negate(p4));

    return 0;
}
