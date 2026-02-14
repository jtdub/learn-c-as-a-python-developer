/*
 * Exercise 5.1: Array Statistics
 *
 * Calculate sum, average, min, and max of an array.
 *
 * Python version:
 *   numbers = [23, 45, 12, 67, 34, 89, 21]
 *   print(f"Sum: {sum(numbers)}")
 *   print(f"Average: {sum(numbers)/len(numbers)}")
 *   print(f"Min: {min(numbers)}, Max: {max(numbers)}")
 *
 * Compile: cc -Wall -o ex01_array_stats ex01_array_stats.c
 * Run: ./ex01_array_stats
 */

#include <stdio.h>

// Function prototypes
int array_sum(int arr[], int size);
double array_average(int arr[], int size);
int array_min(int arr[], int size);
int array_max(int arr[], int size);

int main(void) {
    int numbers[] = {23, 45, 12, 67, 34, 89, 21};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    printf("Sum:     %d\n", array_sum(numbers, size));
    printf("Average: %.2f\n", array_average(numbers, size));
    printf("Min:     %d\n", array_min(numbers, size));
    printf("Max:     %d\n", array_max(numbers, size));

    return 0;
}

// TODO: Implement these functions

int array_sum(int arr[], int size) {
    // Your code here
    return 0;
}

double array_average(int arr[], int size) {
    // Your code here
    return 0.0;
}

int array_min(int arr[], int size) {
    // Your code here
    return 0;
}

int array_max(int arr[], int size) {
    // Your code here
    return 0;
}
