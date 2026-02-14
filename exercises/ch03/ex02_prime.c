/*
 * Exercise 3.2: Prime Number Checker
 *
 * Write a function that checks if a number is prime.
 * Print all prime numbers from 1 to 100.
 *
 * Python version:
 *   def is_prime(n):
 *       if n < 2:
 *           return False
 *       for i in range(2, int(n**0.5) + 1):
 *           if n % i == 0:
 *               return False
 *       return True
 *
 * Compile: cc -Wall -o ex02_prime ex02_prime.c -lm
 * Run: ./ex02_prime
 *
 * Note: -lm links the math library (for sqrt if you use it)
 */

#include <stdio.h>

// TODO: Implement is_prime function
// Return 1 if prime, 0 if not
// int is_prime(int n)

int main(void) {
    printf("Prime numbers from 1 to 100:\n");

    // TODO: Loop through 1-100, print if prime

    printf("\n");
    return 0;
}
