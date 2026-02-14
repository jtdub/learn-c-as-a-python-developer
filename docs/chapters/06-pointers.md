# Chapter 6: Pointers — The Big Leap

This is where C diverges most from Python. Pointers are powerful, dangerous, and essential. Understanding them is the key to mastering C.

## What is a Pointer?

A pointer is a variable that stores a **memory address**.

```
Regular variable:              Pointer variable:
┌─────────────┐               ┌─────────────┐
│     42      │ int x         │   0x1000    │ int *p
└─────────────┘               └──────┬──────┘
   at address 0x1000                 │
        ▲                            │
        └────────────────────────────┘
                 p "points to" x
```

## Basic Pointer Syntax

```c
int x = 42;

// The & operator gets the ADDRESS of a variable
int *p = &x;  // p now holds the address of x

// The * operator DEREFERENCES (follows) a pointer
printf("%d\n", *p);   // Prints 42 (the value AT that address)

// Modify through pointer
*p = 100;
printf("%d\n", x);    // Prints 100 (x was modified through p!)
```

### Reading Pointer Declarations

```c
int *p;      // p is a pointer to an int
char *s;     // s is a pointer to a char
double *d;   // d is a pointer to a double
```

Read `int *p` as: "p is a pointer to int" or "dereferencing p gives an int."

## Why Pointers?

### 1. Modify Variables in Functions

Without pointers, you can't modify the caller's variables:

```c
void broken_double(int x) {
    x = x * 2;  // Only modifies local copy
}

void working_double(int *p) {
    *p = *p * 2;  // Modifies the original!
}

int main(void) {
    int num = 10;

    broken_double(num);
    printf("%d\n", num);  // Still 10

    working_double(&num);
    printf("%d\n", num);  // Now 20!

    return 0;
}
```

### 2. Return Multiple Values

```c
void get_quotient_remainder(int a, int b, int *quotient, int *remainder) {
    *quotient = a / b;
    *remainder = a % b;
}

int main(void) {
    int q, r;
    get_quotient_remainder(17, 5, &q, &r);
    printf("17 / 5 = %d remainder %d\n", q, r);  // 3 remainder 2
    return 0;
}
```

### 3. Work with Dynamic Memory (Chapter 7)

### 4. Efficient Large Data Passing

Passing a large struct by pointer is cheaper than copying it.

## Python Analogy

Python hides pointers, but they're there:

```python
# Python lists are passed by reference (like pointers)
def modify_list(lst):
    lst[0] = 999

my_list = [1, 2, 3]
modify_list(my_list)
print(my_list)  # [999, 2, 3] - modified!

# But integers are immutable - "pass by value" semantics
def try_modify(x):
    x = 999  # Creates new local binding

num = 42
try_modify(num)
print(num)  # Still 42
```

In C, you choose: pass by value (copy) or pass by pointer (reference).

## Pointers and Arrays

Arrays and pointers are closely related in C:

```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr;  // Array name "decays" to pointer to first element

// These are all equivalent:
printf("%d\n", arr[0]);    // 10
printf("%d\n", *p);        // 10
printf("%d\n", *arr);      // 10
printf("%d\n", p[0]);      // 10 (yes, you can index pointers!)
```

### Pointer Arithmetic

```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr;

printf("%d\n", *p);        // 10 (arr[0])
printf("%d\n", *(p + 1));  // 20 (arr[1])
printf("%d\n", *(p + 2));  // 30 (arr[2])

p++;  // Move to next element
printf("%d\n", *p);        // 20

// Pointer difference
int *start = arr;
int *end = arr + 5;
printf("Distance: %ld\n", end - start);  // 5 elements
```

When you add 1 to a pointer, it moves by `sizeof(type)` bytes, not 1 byte.

### Iterating with Pointers

```c
int arr[] = {10, 20, 30, 40, 50};
int *end = arr + 5;  // One past the last element

// Pointer iteration
for (int *p = arr; p < end; p++) {
    printf("%d\n", *p);
}
```

## NULL Pointers

`NULL` is a special pointer value meaning "points to nothing."

```c
int *p = NULL;  // Initialize to NULL if you don't have a value yet

// Always check before dereferencing!
if (p != NULL) {
    printf("%d\n", *p);
}

// Or more idiomatically:
if (p) {
    printf("%d\n", *p);
}
```

## Common Pointer Pitfalls

### 1. Uninitialized Pointer

```c
int *p;       // Contains garbage (random address)
*p = 42;      // CRASH! Writing to random memory
```

**Fix:** Always initialize pointers.

### 2. NULL Dereference

```c
int *p = NULL;
*p = 42;      // CRASH! Can't dereference NULL
```

**Fix:** Check for NULL before use.

### 3. Dangling Pointer

```c
int *p;
{
    int x = 42;
    p = &x;
}  // x goes out of scope here

*p = 100;  // UNDEFINED BEHAVIOR! x no longer exists
```

**Fix:** Don't keep pointers to out-of-scope variables.

### 4. Memory Leaks (Chapter 7)

Allocating memory and forgetting to free it.

## Double Pointers

A pointer to a pointer:

```c
int x = 42;
int *p = &x;
int **pp = &p;

printf("%d\n", x);     // 42
printf("%d\n", *p);    // 42
printf("%d\n", **pp);  // 42

**pp = 100;
printf("%d\n", x);     // 100
```

Used for:

- Modifying a pointer in a function
- 2D arrays / arrays of strings
- Dynamic data structures

---

## Exercises

### Exercise 6.1: Swap Function

Implement a function that swaps two integers using pointers.

**Python can't do this directly:**
```python
def swap(a, b):
    return b, a

x, y = 5, 10
x, y = swap(x, y)
```

**Your task:** Create `exercises/ch06/ex01_swap.c`

```c
void swap(int *a, int *b);
```

### Exercise 6.2: Array with Pointers

Traverse and modify an array using pointer arithmetic (no indexing with `[]`).

**Requirements:**

1. Double every element using only pointer arithmetic
2. Print the array using only pointer iteration

**Your task:** Create `exercises/ch06/ex02_pointer_array.c`

### Exercise 6.3: Find Min and Max

Return both minimum and maximum of an array via pointer parameters.

**Your task:** Create `exercises/ch06/ex03_minmax.c`

```c
void find_minmax(int arr[], int size, int *min, int *max);
```

### Exercise 6.4: String Copy with Pointers

Implement your own `strcpy` using pointer arithmetic.

**Your task:** Create `exercises/ch06/ex04_strcpy.c`

```c
void my_strcpy(char *dest, const char *src);
```

### Exercise 6.5: Array Reversal with Pointers

Reverse an array in-place using two pointers.

**Your task:** Create `exercises/ch06/ex05_reverse_array.c`

??? tip "Hint"
    Use one pointer at the start, one at the end. Swap and move inward.

---

## Key Takeaways

1. **`&`** gets the address of a variable
2. **`*`** dereferences a pointer (gets the value at that address)
3. **`int *p`** declares a pointer to an int
4. **Pass pointers** to modify variables in functions
5. **Arrays decay to pointers** when passed to functions
6. **Pointer arithmetic** moves by `sizeof(type)` bytes
7. **Always initialize pointers** — use `NULL` if no value yet
8. **Always check for NULL** before dereferencing

## Next Chapter

Ready to manage memory manually? Continue to [Chapter 7: Memory Management](07-memory.md).
