/*
 * Exercise 9.1: File Copy
 *
 * Create a program that copies one file to another.
 *
 * Usage: ./ex01_file_copy source.txt dest.txt
 *
 * Requirements:
 * - Handle binary files correctly (use "rb" and "wb")
 * - Check for errors (file not found, write failed)
 * - Report bytes copied
 *
 * Compile: cc -Wall -o ex01_file_copy ex01_file_copy.c
 * Run: ./ex01_file_copy source.txt dest.txt
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    const char *source_path = argv[1];
    const char *dest_path = argv[2];

    // TODO: Open source file for reading (binary mode)

    // TODO: Open destination file for writing (binary mode)
    // Don't forget to close source if dest fails to open!

    // TODO: Copy file in chunks using a buffer
    // Use fread and fwrite
    // Track total bytes copied

    // TODO: Close files

    // TODO: Print summary
    // printf("Copied %zu bytes from %s to %s\n", bytes_copied, source_path, dest_path);

    return 0;
}
