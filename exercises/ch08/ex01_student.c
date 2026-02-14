/*
 * Exercise 8.1: Student Database
 *
 * Create a program that manages a list of students using structs.
 *
 * Compile: cc -Wall -o ex01_student ex01_student.c
 * Run: ./ex01_student
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    double gpa;
} Student;

// Function prototypes
void print_student(Student s);
void print_all_students(Student students[], int count);
Student *find_highest_gpa(Student students[], int count);
Student *find_by_id(Student students[], int count, int id);

int main(void) {
    Student students[] = {
        {"Alice Johnson", 1001, 3.8},
        {"Bob Smith", 1002, 3.5},
        {"Charlie Brown", 1003, 3.9},
        {"Diana Ross", 1004, 3.7},
        {"Eve Williams", 1005, 4.0}
    };
    int count = sizeof(students) / sizeof(students[0]);

    printf("=== Student Database ===\n\n");

    printf("All students:\n");
    print_all_students(students, count);

    printf("\nStudent with highest GPA:\n");
    Student *top = find_highest_gpa(students, count);
    if (top != NULL) {
        print_student(*top);
    }

    printf("\nSearching for student ID 1003:\n");
    Student *found = find_by_id(students, count, 1003);
    if (found != NULL) {
        print_student(*found);
    } else {
        printf("Student not found.\n");
    }

    printf("\nSearching for student ID 9999:\n");
    found = find_by_id(students, count, 9999);
    if (found != NULL) {
        print_student(*found);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}

// TODO: Implement these functions

void print_student(Student s) {
    // Print: "ID: 1001, Name: Alice Johnson, GPA: 3.80"
}

void print_all_students(Student students[], int count) {
    // Loop and print each student
}

Student *find_highest_gpa(Student students[], int count) {
    // Return pointer to student with highest GPA
    // Return NULL if count is 0
    return NULL;
}

Student *find_by_id(Student students[], int count, int id) {
    // Return pointer to student with matching ID
    // Return NULL if not found
    return NULL;
}
