/*
 * Exercise 9.2: Word Count (wc clone)
 *
 * Count lines, words, and characters in a file.
 *
 * Example output:
 *   10   50  300 file.txt
 *   (lines, words, characters)
 *
 * Compile: cc -Wall -o ex02_wc ex02_wc.c
 * Run: ./ex02_wc filename.txt
 *
 * Or read from stdin:
 * echo "hello world" | ./ex02_wc
 */

#include <stdio.h>
#include <ctype.h>

typedef struct {
    long lines;
    long words;
    long chars;
} Counts;

Counts count_file(FILE *f);

int main(int argc, char *argv[]) {
    FILE *f;
    const char *filename;

    if (argc > 1) {
        // Read from file
        filename = argv[1];
        f = fopen(filename, "r");
        if (f == NULL) {
            perror(filename);
            return 1;
        }
    } else {
        // Read from stdin
        filename = "";
        f = stdin;
    }

    Counts c = count_file(f);

    printf("%7ld %7ld %7ld %s\n", c.lines, c.words, c.chars, filename);

    if (f != stdin) {
        fclose(f);
    }

    return 0;
}

Counts count_file(FILE *f) {
    Counts c = {0, 0, 0};

    // TODO: Implement counting
    // - Count every character read
    // - Count newlines
    // - Count words (sequences of non-whitespace)
    //   Hint: Track if you're "in a word" or not

    int ch;
    int in_word = 0;

    while ((ch = fgetc(f)) != EOF) {
        // Your counting logic here
    }

    return c;
}
