/*
 * Exercise 7.3: Linked List
 *
 * Implement a singly linked list with proper memory management.
 *
 * This is a fundamental data structure that doesn't exist built-in to C.
 * It demonstrates dynamic memory allocation and pointer manipulation.
 *
 * Compile: cc -Wall -o ex03_linked_list ex03_linked_list.c
 * Run: ./ex03_linked_list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;  // Pointer to next node (or NULL if last)
} Node;

typedef struct {
    Node *head;  // Pointer to first node (or NULL if empty)
} LinkedList;

// Function prototypes
void list_init(LinkedList *list);
void list_append(LinkedList *list, int value);
void list_prepend(LinkedList *list, int value);
void list_print(LinkedList *list);
int list_length(LinkedList *list);
void list_free(LinkedList *list);

int main(void) {
    LinkedList list;
    list_init(&list);

    printf("Appending 1, 2, 3...\n");
    list_append(&list, 1);
    list_append(&list, 2);
    list_append(&list, 3);
    list_print(&list);
    printf("Length: %d\n", list_length(&list));

    printf("\nPrepending 0...\n");
    list_prepend(&list, 0);
    list_print(&list);

    printf("\nAppending 4, 5...\n");
    list_append(&list, 4);
    list_append(&list, 5);
    list_print(&list);
    printf("Length: %d\n", list_length(&list));

    printf("\nFreeing list...\n");
    list_free(&list);
    list_print(&list);  // Should show empty

    return 0;
}

// TODO: Implement these functions

void list_init(LinkedList *list) {
    // Initialize head to NULL
}

void list_append(LinkedList *list, int value) {
    // 1. Allocate new node
    // 2. Set data = value, next = NULL
    // 3. If list is empty, set head to new node
    // 4. Otherwise, traverse to end and append
}

void list_prepend(LinkedList *list, int value) {
    // 1. Allocate new node
    // 2. Set data = value
    // 3. Set next to current head
    // 4. Set head to new node
}

void list_print(LinkedList *list) {
    printf("[");
    Node *current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]\n");
}

int list_length(LinkedList *list) {
    // Traverse and count nodes
    return 0;
}

void list_free(LinkedList *list) {
    // Free all nodes!
    // Be careful: save next pointer before freeing current
    // Set head to NULL when done
}
