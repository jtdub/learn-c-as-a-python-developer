/*
 * Exercise 2.3: Integer Overflow Demo
 *
 * Demonstrate what happens when you exceed a type's range.
 * In Python, integers can be arbitrarily large.
 * In C, they have fixed sizes and WILL overflow!
 *
 * Compile: cc -Wall -o ex03_overflow ex03_overflow.c
 * Run: ./ex03_overflow
 */

#include <stdio.h>
#include <limits.h>  // For CHAR_MAX, INT_MAX, etc.

int main(void) {
    printf("=== Integer Overflow Demo ===\n\n");

    // --- unsigned char (0 to 255) ---
    printf("--- unsigned char (0 to 255) ---\n");
    unsigned char uc = 255;
    printf("uc = %u\n", uc);
    // TODO: Add 1 and print - what happens?

    printf("\n");

    // --- signed char (-128 to 127) ---
    printf("--- signed char (-128 to 127) ---\n");
    signed char sc = 127;
    printf("sc = %d\n", sc);
    // TODO: Add 1 and print - what happens?

    printf("\n");

    // --- Show the limits ---
    printf("--- Type Limits from <limits.h> ---\n");
    printf("CHAR_MIN:  %d\n", CHAR_MIN);
    printf("CHAR_MAX:  %d\n", CHAR_MAX);
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);
    printf("INT_MIN:   %d\n", INT_MIN);
    printf("INT_MAX:   %d\n", INT_MAX);
    printf("UINT_MAX:  %u\n", UINT_MAX);

    return 0;
}
