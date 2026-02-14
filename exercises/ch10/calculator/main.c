/*
 * main.c - Calculator main program
 * Exercise 10.1: Multi-file Calculator
 *
 * Build: make
 * Run:   ./calculator
 * Clean: make clean
 */

#include <stdio.h>
#include "operations.h"
#include "display.h"

int main(void) {
    display_welcome();

    int choice;
    double a, b, result;

    while (1) {
        display_menu();

        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            display_error("Invalid input");
            continue;
        }

        if (choice == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            display_error("Invalid choice");
            continue;
        }

        printf("Enter first number: ");
        scanf("%lf", &a);

        printf("Enter second number: ");
        scanf("%lf", &b);

        // TODO: Call appropriate operation and display result
        switch (choice) {
            case 1:
                result = op_add(a, b);
                display_result("+", a, b, result);
                break;
            case 2:
                // Implement
                break;
            case 3:
                // Implement
                break;
            case 4:
                // Implement (check for division by zero)
                break;
            case 5:
                // Implement
                break;
        }
    }

    return 0;
}
