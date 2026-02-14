/*
 * display.c - Display/output functions implementation
 * Exercise 10.1: Multi-file Calculator
 */

#include <stdio.h>
#include "display.h"

void display_welcome(void) {
    printf("================================\n");
    printf("    Multi-File Calculator       \n");
    printf("================================\n\n");
}

void display_result(const char *operation, double a, double b, double result) {
    // TODO: Implement formatted output
    // Example: "5.00 + 3.00 = 8.00"
}

void display_error(const char *message) {
    printf("Error: %s\n", message);
}

void display_menu(void) {
    printf("\nOperations:\n");
    printf("  1. Add\n");
    printf("  2. Subtract\n");
    printf("  3. Multiply\n");
    printf("  4. Divide\n");
    printf("  5. Power\n");
    printf("  0. Exit\n");
    printf("\nChoice: ");
}
