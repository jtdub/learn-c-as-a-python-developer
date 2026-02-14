/*
 * Exercise 5.3: Word Counter
 *
 * Count words in a string (words separated by spaces).
 *
 * Python version:
 *   text = "Hello World from C programming"
 *   word_count = len(text.split())
 *
 * Compile: cc -Wall -o ex03_word_count ex03_word_count.c
 * Run: ./ex03_word_count
 */

#include <stdio.h>
#include <ctype.h>  // For isspace()

// TODO: Implement count_words
// Hint: Count transitions from space to non-space
int count_words(const char *s);

int main(void) {
    const char *tests[] = {
        "Hello World",
        "  multiple   spaces   between  ",
        "single",
        "",
        "   ",
        "one two three four five"
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) {
        printf("Text: \"%s\"\n", tests[i]);
        printf("Words: %d\n\n", count_words(tests[i]));
    }

    return 0;
}

int count_words(const char *s) {
    // TODO: Implement word counting
    // Hint: Track whether you're currently "in a word"
    // Hint: Use isspace(c) to check if c is whitespace
    return 0;
}
