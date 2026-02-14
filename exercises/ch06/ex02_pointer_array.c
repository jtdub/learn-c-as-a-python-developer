/*
 * Exercise 6.2: Array Manipulation with Pointers
 *
 * Traverse and modify an array using pointer arithmetic.
 * Do NOT use array indexing (arr[i]) - only pointers!
 *
 * Tasks:
 * 1. Double every element using pointer arithmetic
 * 2. Print the array using pointer iteration
 *
 * Compile: cc -Wall -o ex02_pointer_array ex02_pointer_array.c
 * Run: ./ex02_pointer_array
 */

#include <stdio.h>

// Print array using pointers only (no arr[i])
void print_array(int *arr, int size);

// Double each element using pointers only
void double_elements(int *arr, int size);

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array:\n");
    print_array(numbers, size);

    double_elements(numbers, size);

    printf("\nAfter doubling:\n");
    print_array(numbers, size);

    return 0;
}

void print_array(int *arr, int size) {
    // TODO: Print using pointer arithmetic
    // Hint: Use a pointer that increments: for (int *p = arr; p < arr + size; p++)
    // Hint: Print *p (the value at pointer p)
}

void double_elements(int *arr, int size) {
    // TODO: Double each element using pointer arithmetic
    // Hint: *p = *p * 2; or *p *= 2;
}
