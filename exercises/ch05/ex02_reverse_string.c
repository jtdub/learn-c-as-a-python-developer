/*
 * Exercise 5.2: String Reversal
 *
 * Reverse a string IN PLACE (modify the original).
 * This is different from Python where strings are immutable.
 *
 * Python equivalent (creates new string):
 *   s = "hello"
 *   s = s[::-1]  # "olleh"
 *
 * C version modifies the original array.
 *
 * Compile: cc -Wall -o ex02_reverse_string ex02_reverse_string.c
 * Run: ./ex02_reverse_string
 */

#include <stdio.h>
#include <string.h>

// TODO: Implement reverse_string
// Hint: Swap characters from both ends, moving toward middle
void reverse_string(char *s);

int main(void) {
    // Note: We need mutable strings (char arrays, not string literals)
    char s1[] = "hello";
    char s2[] = "C programming";
    char s3[] = "a";
    char s4[] = "";

    printf("Original: \"%s\"\n", s1);
    reverse_string(s1);
    printf("Reversed: \"%s\"\n\n", s1);

    printf("Original: \"%s\"\n", s2);
    reverse_string(s2);
    printf("Reversed: \"%s\"\n\n", s2);

    printf("Original: \"%s\"\n", s3);
    reverse_string(s3);
    printf("Reversed: \"%s\"\n\n", s3);

    printf("Original: \"%s\"\n", s4);
    reverse_string(s4);
    printf("Reversed: \"%s\"\n", s4);

    return 0;
}

void reverse_string(char *s) {
    // TODO: Implement in-place string reversal
    // Hint: Use strlen() to get length
    // Hint: Swap s[i] with s[len-1-i]
}
