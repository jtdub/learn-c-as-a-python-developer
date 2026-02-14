/*
 * Exercise 7.2: Memory-Safe String Concatenation
 *
 * Implement a function that concatenates two strings into a NEW
 * heap-allocated string. Caller is responsible for freeing.
 *
 * Python equivalent:
 *   result = s1 + s2  # Creates new string automatically
 *
 * Compile: cc -Wall -o ex02_string_concat ex02_string_concat.c
 * Run: ./ex02_string_concat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns a new heap-allocated string containing s1 + s2
// Caller must free the returned pointer!
char *string_concat(const char *s1, const char *s2);

int main(void) {
    const char *hello = "Hello, ";
    const char *world = "World!";

    char *result = string_concat(hello, world);
    if (result != NULL) {
        printf("Concatenated: \"%s\"\n", result);
        free(result);  // Don't forget!
    }

    // More tests
    char *test1 = string_concat("", "empty first");
    printf("Empty + string: \"%s\"\n", test1);
    free(test1);

    char *test2 = string_concat("empty second", "");
    printf("String + empty: \"%s\"\n", test2);
    free(test2);

    char *test3 = string_concat("", "");
    printf("Empty + empty: \"%s\"\n", test3);
    free(test3);

    return 0;
}

char *string_concat(const char *s1, const char *s2) {
    // TODO: Implement this function
    // 1. Calculate total length needed (len1 + len2 + 1 for null terminator)
    // 2. Allocate memory with malloc
    // 3. Check for allocation failure (return NULL)
    // 4. Copy s1 to result
    // 5. Copy s2 to result (after s1)
    // 6. Return result

    return NULL;  // Replace with your implementation
}
