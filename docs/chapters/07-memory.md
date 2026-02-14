# Chapter 7: Memory Management

In Python, memory is managed automatically by the garbage collector. In C, you're in complete control—and with great power comes great responsibility.

## Memory Layout

A C program's memory is divided into regions:

```
┌─────────────────────────┐ High addresses
│         Stack           │ ← Local variables, function calls
│           │             │   (grows downward)
│           ▼             │
│                         │
│           ▲             │
│           │             │
│         Heap            │ ← Dynamic allocation (malloc)
│                         │   (grows upward)
├─────────────────────────┤
│    Uninitialized Data   │ ← Global variables (uninitialized)
│         (BSS)           │
├─────────────────────────┤
│    Initialized Data     │ ← Global variables (initialized)
├─────────────────────────┤
│      Code (Text)        │ ← Your compiled program
└─────────────────────────┘ Low addresses
```

## Stack vs Heap

### Stack Allocation (Automatic)

```c
void function(void) {
    int x = 42;           // Allocated on stack
    int arr[100];         // Also on stack
    char name[50];        // Also on stack
}  // All automatically freed when function returns
```

**Pros:**

- Fast (just moving a pointer)
- Automatic cleanup
- No fragmentation

**Cons:**

- Limited size (~1-8 MB typically)
- Lifetime tied to scope
- Can't return pointers to local variables

### Heap Allocation (Manual)

```c
#include <stdlib.h>

int *create_array(int size) {
    int *arr = malloc(size * sizeof(int));  // Allocated on heap
    return arr;  // Safe! Memory persists after function returns
}

int main(void) {
    int *arr = create_array(1000);
    // Use arr...
    free(arr);  // YOU must free it
    return 0;
}
```

**Pros:**

- Large (limited only by system memory)
- Persists until explicitly freed
- Size determined at runtime

**Cons:**

- Slower than stack
- Manual management required
- Fragmentation possible
- Memory leaks if you forget `free()`

## Memory Functions

### malloc — Allocate Memory

```c
#include <stdlib.h>

// Allocate space for one int
int *p = malloc(sizeof(int));

// Allocate array of 100 ints
int *arr = malloc(100 * sizeof(int));

// Always check for failure!
if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
}
```

!!! warning "malloc Returns Uninitialized Memory"
    The memory contains garbage—whatever was there before.

### calloc — Allocate and Zero

```c
// Allocate AND initialize to zero
int *arr = calloc(100, sizeof(int));  // 100 ints, all zeros
```

### realloc — Resize Allocation

```c
int *arr = malloc(10 * sizeof(int));

// Need more space? Resize!
arr = realloc(arr, 20 * sizeof(int));

// IMPORTANT: realloc may move the data
// Always use the returned pointer
```

!!! danger "realloc Pitfall"
    ```c
    // WRONG: If realloc fails, you lose the original pointer
    arr = realloc(arr, new_size);

    // RIGHT: Use a temporary
    int *temp = realloc(arr, new_size);
    if (temp == NULL) {
        // Handle error, arr still valid
    } else {
        arr = temp;
    }
    ```

### free — Deallocate Memory

```c
int *p = malloc(sizeof(int));
// ... use p ...
free(p);
p = NULL;  // Good practice: prevent dangling pointer
```

## Common Memory Errors

### 1. Memory Leak

```c
void leak(void) {
    int *p = malloc(1000 * sizeof(int));
    // Oops, forgot free(p)!
}  // Memory is now unreachable but still allocated

// Called 1000 times = 4 MB leaked
```

**Fix:** Always pair `malloc` with `free`.

### 2. Use After Free

```c
int *p = malloc(sizeof(int));
*p = 42;
free(p);
printf("%d\n", *p);  // UNDEFINED BEHAVIOR!
```

**Fix:** Set pointer to NULL after freeing, don't use it.

### 3. Double Free

```c
int *p = malloc(sizeof(int));
free(p);
free(p);  // UNDEFINED BEHAVIOR! Corrupts heap
```

**Fix:** Set to NULL after free; `free(NULL)` is safe.

### 4. Freeing Stack Memory

```c
int x = 42;
free(&x);  // CRASH! x is not from malloc
```

**Fix:** Only `free()` what `malloc/calloc/realloc` gave you.

### 5. Buffer Overflow

```c
int *arr = malloc(5 * sizeof(int));
arr[10] = 999;  // Writing beyond allocated memory!
free(arr);      // May crash here or corrupt other data
```

**Fix:** Always track and respect allocation sizes.

### 6. Dangling Pointer

```c
int *get_value(void) {
    int x = 42;
    return &x;  // WRONG! x will be invalid after return
}
```

**Fix:** Return heap-allocated memory or pass pointer as parameter.

## Python Comparison

```python
# Python: Create, use, forget
my_list = list(range(1000000))
# ... use it ...
my_list = None  # Reference released
# Garbage collector eventually frees the memory
```

```c
// C: Create, use, FREE
int *arr = malloc(1000000 * sizeof(int));
// ... use it ...
free(arr);  // YOU must free it, NOW
arr = NULL;
```

## Memory-Safe Patterns

### Pattern 1: Initialize on Declaration

```c
int *p = NULL;  // Not malloc(sizeof(int)) if you don't need it yet
// ... later when you need it ...
p = malloc(sizeof(int));
```

### Pattern 2: NULL After Free

```c
free(p);
p = NULL;
```

### Pattern 3: Check Every Allocation

```c
int *arr = malloc(size * sizeof(int));
if (arr == NULL) {
    perror("malloc failed");
    exit(1);
}
```

### Pattern 4: Pair Alloc/Free in Same Scope When Possible

```c
void process_data(int n) {
    int *data = malloc(n * sizeof(int));
    if (data == NULL) return;

    // ... all processing here ...

    free(data);  // Freed at end of same function
}
```

---

## Exercises

### Exercise 7.1: Dynamic Array

Implement a dynamically resizing array (like Python's list).

```c
typedef struct {
    int *data;
    int size;      // Number of elements
    int capacity;  // Allocated size
} DynamicArray;

void da_init(DynamicArray *arr);
void da_append(DynamicArray *arr, int value);
int da_get(DynamicArray *arr, int index);
void da_free(DynamicArray *arr);
```

**Your task:** Create `exercises/ch07/ex01_dynamic_array.c`

### Exercise 7.2: String Concatenation

Implement a function that concatenates two strings into a new heap-allocated string.

```c
// Caller must free the returned string
char *string_concat(const char *s1, const char *s2);
```

**Python equivalent:**
```python
result = s1 + s2  # Creates new string automatically
```

**Your task:** Create `exercises/ch07/ex02_string_concat.c`

### Exercise 7.3: Linked List

Implement a singly linked list with proper memory management.

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void list_init(LinkedList *list);
void list_append(LinkedList *list, int value);
void list_print(LinkedList *list);
void list_free(LinkedList *list);  // Free all nodes!
```

**Your task:** Create `exercises/ch07/ex03_linked_list.c`

### Exercise 7.4: Matrix Operations

Create and manipulate a 2D matrix using dynamic allocation.

```c
int **create_matrix(int rows, int cols);
void free_matrix(int **matrix, int rows);
void fill_matrix(int **matrix, int rows, int cols, int value);
void print_matrix(int **matrix, int rows, int cols);
```

**Your task:** Create `exercises/ch07/ex04_matrix.c`

---

## Key Takeaways

1. **Stack is automatic** — local variables, limited size
2. **Heap is manual** — `malloc`/`free`, unlimited size
3. **Always check** `malloc` return value for NULL
4. **Every `malloc` needs a `free`** — no garbage collector
5. **Don't use after free** — set pointer to NULL
6. **Don't double free** — corrupts the heap
7. **Only free heap memory** — not stack variables
8. **Track your sizes** — C won't do it for you

## Next Chapter

Ready to create custom data types? Continue to [Chapter 8: Structs](08-structs.md).
