/*
 * Exercise 4.3: Fibonacci Sequence
 *
 * Implement Fibonacci both recursively and iteratively.
 * Compare performance for larger values.
 *
 * Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
 *
 * Compile: cc -Wall -o ex03_fibonacci ex03_fibonacci.c
 * Run: ./ex03_fibonacci
 */

#include <stdio.h>
#include <time.h>

// TODO: Implement recursive Fibonacci
// long fib_recursive(int n)

// TODO: Implement iterative Fibonacci
// long fib_iterative(int n)

int main(void) {
    // Print first 20 Fibonacci numbers
    printf("First 20 Fibonacci numbers:\n");
    // TODO: Print using your iterative function

    printf("\n");

    // Performance comparison
    printf("Performance comparison for F(40):\n");

    clock_t start, end;
    double time_taken;

    // Time iterative version
    start = clock();
    // long result_iter = fib_iterative(40);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("Iterative: F(40) = %ld (%.4f seconds)\n", result_iter, time_taken);

    // Time recursive version (WARNING: This is SLOW!)
    printf("(Recursive version may take a while...)\n");
    start = clock();
    // long result_rec = fib_recursive(40);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("Recursive: F(40) = %ld (%.4f seconds)\n", result_rec, time_taken);

    return 0;
}
