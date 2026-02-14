/*
 * Exercise 7.1: Dynamic Array
 *
 * Implement a dynamically resizing array (like Python's list).
 *
 * Python equivalent:
 *   arr = []
 *   arr.append(1)
 *   arr.append(2)
 *   print(arr[0])
 *
 * In C, we must manage memory manually.
 *
 * Compile: cc -Wall -o ex01_dynamic_array ex01_dynamic_array.c
 * Run: ./ex01_dynamic_array
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;      // Pointer to the array data
    int size;       // Number of elements currently stored
    int capacity;   // Total allocated capacity
} DynamicArray;

// Function prototypes
void da_init(DynamicArray *arr);
void da_append(DynamicArray *arr, int value);
int da_get(DynamicArray *arr, int index);
void da_set(DynamicArray *arr, int index, int value);
void da_print(DynamicArray *arr);
void da_free(DynamicArray *arr);

int main(void) {
    DynamicArray arr;
    da_init(&arr);

    printf("Appending elements 0-9...\n");
    for (int i = 0; i < 10; i++) {
        da_append(&arr, i * 10);
        printf("Size: %d, Capacity: %d\n", arr.size, arr.capacity);
    }

    printf("\nArray contents:\n");
    da_print(&arr);

    printf("\nElement at index 5: %d\n", da_get(&arr, 5));

    da_set(&arr, 5, 999);
    printf("After setting index 5 to 999:\n");
    da_print(&arr);

    da_free(&arr);
    printf("\nArray freed.\n");

    return 0;
}

// TODO: Implement these functions

void da_init(DynamicArray *arr) {
    // Initialize with small capacity (e.g., 4)
    // arr->data = malloc(...)
    // arr->size = 0
    // arr->capacity = ...
}

void da_append(DynamicArray *arr, int value) {
    // If size == capacity, need to grow
    // Use realloc to double capacity
    // Add value at arr->data[arr->size]
    // Increment size
}

int da_get(DynamicArray *arr, int index) {
    // Return element at index
    // Optional: bounds checking
    return 0;
}

void da_set(DynamicArray *arr, int index, int value) {
    // Set element at index
    // Optional: bounds checking
}

void da_print(DynamicArray *arr) {
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

void da_free(DynamicArray *arr) {
    // Free the data array
    // Set pointers to NULL, sizes to 0
}
