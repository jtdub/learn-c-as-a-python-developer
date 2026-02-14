/*
 * Exercise 8.3: Date Struct
 *
 * Create a Date struct with comparison and validation functions.
 *
 * Compile: cc -Wall -o ex03_datetime ex03_datetime.c
 * Run: ./ex03_datetime
 */

#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function prototypes
Date date_create(int year, int month, int day);
int is_leap_year(int year);
int days_in_month(int year, int month);
int is_valid_date(Date d);
int compare_dates(Date a, Date b);  // Returns -1, 0, or 1
void print_date(Date d);

int main(void) {
    Date dates[] = {
        date_create(2024, 1, 15),
        date_create(2024, 2, 29),   // Leap year
        date_create(2023, 2, 29),   // Invalid (not leap year)
        date_create(2024, 12, 31),
        date_create(2024, 13, 1),   // Invalid month
        date_create(2024, 4, 31),   // Invalid (April has 30 days)
    };
    int count = sizeof(dates) / sizeof(dates[0]);

    printf("=== Date Validation ===\n");
    for (int i = 0; i < count; i++) {
        print_date(dates[i]);
        printf(" - %s\n", is_valid_date(dates[i]) ? "Valid" : "Invalid");
    }

    printf("\n=== Date Comparison ===\n");
    Date d1 = date_create(2024, 6, 15);
    Date d2 = date_create(2024, 6, 20);
    Date d3 = date_create(2024, 6, 15);

    print_date(d1);
    printf(" vs ");
    print_date(d2);
    printf(" : %d\n", compare_dates(d1, d2));

    print_date(d2);
    printf(" vs ");
    print_date(d1);
    printf(" : %d\n", compare_dates(d2, d1));

    print_date(d1);
    printf(" vs ");
    print_date(d3);
    printf(" : %d\n", compare_dates(d1, d3));

    printf("\n=== Leap Year Check ===\n");
    int years[] = {2000, 2020, 2024, 2023, 1900, 2100};
    for (int i = 0; i < 6; i++) {
        printf("%d: %s\n", years[i],
               is_leap_year(years[i]) ? "Leap year" : "Not leap year");
    }

    return 0;
}

// TODO: Implement these functions

Date date_create(int year, int month, int day) {
    Date d = {year, month, day};
    return d;
}

int is_leap_year(int year) {
    // Leap year rules:
    // - Divisible by 4
    // - BUT not divisible by 100
    // - UNLESS also divisible by 400
    return 0;
}

int days_in_month(int year, int month) {
    // Return number of days in given month
    // Remember: February depends on leap year!
    return 0;
}

int is_valid_date(Date d) {
    // Check: year > 0, month 1-12, day 1-days_in_month
    return 0;
}

int compare_dates(Date a, Date b) {
    // Return -1 if a < b
    // Return  0 if a == b
    // Return  1 if a > b
    return 0;
}

void print_date(Date d) {
    printf("%04d-%02d-%02d", d.year, d.month, d.day);
}
