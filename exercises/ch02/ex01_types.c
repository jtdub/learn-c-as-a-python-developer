/*
 * Exercise 2.1: Type Exploration
 *
 * Declare variables of different types and print their sizes using sizeof().
 *
 * Expected output:
 *   Type sizes on this system:
 *   char:      1 bytes
 *   short:     2 bytes
 *   int:       4 bytes
 *   long:      8 bytes
 *   float:     4 bytes
 *   double:    8 bytes
 *
 * Compile: cc -Wall -o ex01_types ex01_types.c
 * Run: ./ex01_types
 */

#include <stdio.h>

int main(void) {
    printf("Type sizes on this system:\n");

    // TODO: Print the size of each type using sizeof()
    // Use %zu format specifier for sizeof (returns size_t)

    // Example:
    // printf("char:      %zu bytes\n", sizeof(char));

    return 0;
}
