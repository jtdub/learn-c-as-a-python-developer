/*
 * Exercise 4.1: Calculator Functions
 *
 * Implement basic math operations as functions.
 *
 * Functions to implement:
 *   - add(a, b)       : returns sum
 *   - subtract(a, b)  : returns difference
 *   - multiply(a, b)  : returns product
 *   - divide(a, b)    : returns quotient (handle division by zero!)
 *
 * Compile: cc -Wall -o ex01_calculator ex01_calculator.c
 * Run: ./ex01_calculator
 */

#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

// TODO: Implement the functions below

int main(void) {
    int x = 20, y = 5;

    printf("Calculator Functions Demo\n");
    printf("=========================\n");
    printf("x = %d, y = %d\n\n", x, y);

    printf("%d + %d = %d\n", x, y, add(x, y));
    printf("%d - %d = %d\n", x, y, subtract(x, y));
    printf("%d * %d = %d\n", x, y, multiply(x, y));
    printf("%d / %d = %.2f\n", x, y, divide(x, y));

    // Test division by zero
    printf("\nDivision by zero test:\n");
    printf("10 / 0 = %.2f\n", divide(10, 0));

    return 0;
}

// TODO: Implement functions here

int add(int a, int b) {
    // Your code here
    return 0;
}

int subtract(int a, int b) {
    // Your code here
    return 0;
}

int multiply(int a, int b) {
    // Your code here
    return 0;
}

double divide(int a, int b) {
    // Your code here
    // Handle b == 0!
    return 0;
}
