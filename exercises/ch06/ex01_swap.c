/*
 * Exercise 6.1: Swap Function
 *
 * Implement a function that swaps two integers using pointers.
 *
 * Python can't do this directly:
 *   def swap(a, b):
 *       return b, a
 *   x, y = swap(x, y)
 *
 * In C, we use pointers to modify the original variables.
 *
 * Compile: cc -Wall -o ex01_swap ex01_swap.c
 * Run: ./ex01_swap
 */

#include <stdio.h>

// TODO: Implement swap function
// void swap(int *a, int *b)

int main(void) {
    int x = 5, y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    // TODO: Call swap with addresses of x and y
    // swap(&x, &y);

    printf("After swap:  x = %d, y = %d\n", x, y);

    // More tests
    int a = 100, b = 200;
    printf("\nBefore swap: a = %d, b = %d\n", a, b);
    // swap(&a, &b);
    printf("After swap:  a = %d, b = %d\n", a, b);

    return 0;
}

// TODO: Implement swap here
void swap(int *a, int *b) {
    // Hint: Use a temporary variable
    // temp = *a; *a = *b; *b = temp;
}
