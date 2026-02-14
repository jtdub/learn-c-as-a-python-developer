/*
 * Exercise 9.3: CSV Parser
 *
 * Parse a simple CSV file and print as a formatted table.
 *
 * Input (data.csv):
 *   Name,Age,City
 *   Alice,30,New York
 *   Bob,25,Los Angeles
 *   Charlie,35,Chicago
 *
 * Output:
 *   | Name    | Age | City        |
 *   |---------|-----|-------------|
 *   | Alice   | 30  | New York    |
 *   | Bob     | 25  | Los Angeles |
 *   | Charlie | 35  | Chicago     |
 *
 * Compile: cc -Wall -o ex03_csv_parser ex03_csv_parser.c
 * Run: ./ex03_csv_parser data.csv
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024
#define MAX_FIELDS 10
#define MAX_FIELD_LEN 100

// Parse a line into fields, return number of fields
int parse_line(char *line, char fields[][MAX_FIELD_LEN], int max_fields);

// Print a row of the table
void print_row(char fields[][MAX_FIELD_LEN], int num_fields, int widths[]);

// Print separator line
void print_separator(int widths[], int num_fields);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csvfile>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }

    char line[MAX_LINE];
    char fields[MAX_FIELDS][MAX_FIELD_LEN];

    // For simplicity, use fixed column widths
    // (A more complete solution would calculate optimal widths)
    int widths[] = {12, 6, 15, 10, 10, 10, 10, 10, 10, 10};

    int line_num = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';

        int num_fields = parse_line(line, fields, MAX_FIELDS);

        if (line_num == 0) {
            // Header row
            print_row(fields, num_fields, widths);
            print_separator(widths, num_fields);
        } else {
            // Data row
            print_row(fields, num_fields, widths);
        }

        line_num++;
    }

    fclose(f);
    return 0;
}

int parse_line(char *line, char fields[][MAX_FIELD_LEN], int max_fields) {
    // TODO: Parse comma-separated values into fields array
    // Return number of fields found
    //
    // Hint: Use strtok() or manual parsing
    // strtok(line, ",") returns first token
    // strtok(NULL, ",") returns next token

    return 0;
}

void print_row(char fields[][MAX_FIELD_LEN], int num_fields, int widths[]) {
    printf("|");
    for (int i = 0; i < num_fields; i++) {
        printf(" %-*s |", widths[i], fields[i]);
    }
    printf("\n");
}

void print_separator(int widths[], int num_fields) {
    printf("|");
    for (int i = 0; i < num_fields; i++) {
        for (int j = 0; j < widths[i] + 2; j++) {
            printf("-");
        }
        printf("|");
    }
    printf("\n");
}
