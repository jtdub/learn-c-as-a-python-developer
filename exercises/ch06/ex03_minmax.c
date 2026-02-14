/*
 * Exercise 6.3: Find Min and Max via Pointers
 *
 * Return multiple values using pointer parameters.
 * (C functions can only return one value, so we use pointers for "output" params)
 *
 * Compile: cc -Wall -o ex03_minmax ex03_minmax.c
 * Run: ./ex03_minmax
 */

#include <stdio.h>

// TODO: Implement find_minmax
// The function should set *min and *max to the minimum and maximum values
void find_minmax(int arr[], int size, int *min, int *max);

int main(void) {
    int numbers[] = {23, 45, 12, 67, 34, 89, 21, 5, 78};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int minimum, maximum;

    find_minmax(numbers, size, &minimum, &maximum);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);

    // Test with single element
    int single[] = {42};
    find_minmax(single, 1, &minimum, &maximum);
    printf("\nSingle element array [42]:\n");
    printf("Minimum: %d, Maximum: %d\n", minimum, maximum);

    return 0;
}

void find_minmax(int arr[], int size, int *min, int *max) {
    // TODO: Implement this function
    // Set *min and *max by dereferencing the pointers
    // Example: *min = arr[0];
}
