# Chapter 5: Arrays and Strings

In Python, you have lists and strings as flexible, powerful data types. In C, you have arrays—fixed-size, same-type collections—and strings that are just arrays of characters.

## Arrays

### Python Lists vs C Arrays

| Feature | Python List | C Array |
|---------|-------------|---------|
| Size | Dynamic (grows/shrinks) | Fixed at creation |
| Types | Heterogeneous (mixed) | Homogeneous (one type) |
| Bounds | Checked (IndexError) | Unchecked (undefined behavior!) |
| Length | `len(lst)` | You track it yourself |

### Declaring Arrays

```c
// Fixed size, uninitialized (DANGER: contains garbage!)
int numbers[5];

// Declaration with initialization
int scores[5] = {90, 85, 78, 92, 88};

// Partial initialization (rest become 0)
int partial[5] = {1, 2};  // {1, 2, 0, 0, 0}

// Let compiler count the size
int auto_size[] = {1, 2, 3, 4, 5};  // Size is 5

// Initialize all to zero
int zeros[100] = {0};
```

### Accessing Elements

```c
int scores[5] = {90, 85, 78, 92, 88};

// Read (0-indexed, like Python)
printf("%d\n", scores[0]);  // 90
printf("%d\n", scores[4]);  // 88

// Write
scores[0] = 100;

// DANGER: No bounds checking!
scores[10] = 999;   // Writes to random memory
printf("%d\n", scores[-1]);  // Reads random memory
```

!!! danger "No Bounds Checking!"
    C will happily let you read/write outside array bounds. This causes:

    - **Buffer overflows** (security vulnerabilities)
    - **Data corruption** (overwriting other variables)
    - **Crashes** (segmentation faults)
    - **Silent bugs** (program seems to work but has undefined behavior)

### Array Size

C has no built-in `len()`. Calculate it yourself:

```c
int arr[] = {10, 20, 30, 40, 50};
int size = sizeof(arr) / sizeof(arr[0]);

printf("Array size: %d\n", size);  // 5
```

!!! warning "This Only Works for Stack Arrays"
    Once an array is passed to a function, it "decays" to a pointer and loses its size information. You must pass the size separately.

### Iterating Arrays

```c
int arr[] = {10, 20, 30, 40, 50};
int size = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < size; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
}
```

### Multidimensional Arrays

```c
// 2D array (3 rows, 4 columns)
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Access
printf("%d\n", matrix[1][2]);  // 7

// Iterate
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
```

## Strings

In C, strings are **arrays of characters terminated by a null character** (`'\0'`).

### String Basics

```c
// These are equivalent:
char greeting[] = "Hello";
char greeting[] = {'H', 'e', 'l', 'l', 'o', '\0'};

// The null terminator is crucial!
// "Hello" in memory: ['H']['e']['l']['l']['o']['\0']
// That's 6 bytes, not 5!
```

### String vs Character

```c
char c = 'A';       // Single character (1 byte)
char *s = "A";      // String with 'A' and '\0' (2 bytes)

// Single quotes: character
// Double quotes: string (null-terminated)
```

### String Length

```c
#include <string.h>

char s[] = "Hello";
printf("Length: %zu\n", strlen(s));  // 5 (doesn't count \0)
printf("Size: %zu\n", sizeof(s));    // 6 (includes \0)
```

### Mutable vs Immutable

```c
// Array form: mutable
char s1[] = "Hello";
s1[0] = 'J';  // OK: "Jello"

// Pointer form: immutable (string literal)
char *s2 = "Hello";
s2[0] = 'J';  // UNDEFINED BEHAVIOR! Likely crash
```

!!! info "Why the Difference?"
    `char s[] = "Hello"` copies the string to the stack (mutable).
    `char *s = "Hello"` points to a string literal in read-only memory.

### String Functions

Include `<string.h>` for these:

```c
#include <string.h>

char s1[20] = "Hello";
char s2[] = "World";

// Length
size_t len = strlen(s1);  // 5

// Copy
strcpy(s1, s2);  // s1 is now "World"

// Concatenate
char dest[20] = "Hello";
strcat(dest, " World");  // dest is "Hello World"

// Compare
int result = strcmp("abc", "abd");  // < 0 (abc comes before abd)
// Returns: 0 if equal, < 0 if s1 < s2, > 0 if s1 > s2

// Find character
char *p = strchr("Hello", 'l');  // Points to first 'l'

// Find substring
char *p = strstr("Hello World", "World");  // Points to "World"
```

!!! danger "Buffer Overflow Danger"
    `strcpy` and `strcat` don't check bounds. Prefer `strncpy` and `strncat`:
    ```c
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';  // Ensure null-termination
    ```

### Reading Strings

```c
char name[50];

// scanf with %s (stops at whitespace, dangerous)
scanf("%s", name);  // No & needed for arrays!

// Safer: limit length
scanf("%49s", name);  // Leave room for \0

// Read whole line including spaces
fgets(name, sizeof(name), stdin);
// Note: fgets keeps the newline character!
```

### Comparing Strings

```c
char s1[] = "hello";
char s2[] = "hello";

// WRONG: compares addresses, not content
if (s1 == s2) { }  // Always false! Different arrays

// RIGHT: use strcmp
if (strcmp(s1, s2) == 0) {
    printf("Strings are equal\n");
}
```

---

## Exercises

### Exercise 5.1: Array Statistics

Calculate sum, average, min, and max of an array.

**Python version:**
```python
numbers = [23, 45, 12, 67, 34, 89, 21]
print(f"Sum: {sum(numbers)}")
print(f"Average: {sum(numbers)/len(numbers)}")
print(f"Min: {min(numbers)}, Max: {max(numbers)}")
```

**Your task:** Create `exercises/ch05/ex01_array_stats.c`

Implement these functions:
```c
int array_sum(int arr[], int size);
double array_average(int arr[], int size);
int array_min(int arr[], int size);
int array_max(int arr[], int size);
```

### Exercise 5.2: String Reversal

Reverse a string **in place** (modify the original).

**Python equivalent:**
```python
s = "hello"
s = s[::-1]  # Creates new string in Python
```

**Your task:** Create `exercises/ch05/ex02_reverse_string.c`

```c
void reverse_string(char *s);
```

??? tip "Hint"
    Swap characters from both ends, moving toward the middle.

### Exercise 5.3: Word Counter

Count words in a string (words are separated by spaces).

**Python version:**
```python
text = "Hello World from C programming"
word_count = len(text.split())
```

**Your task:** Create `exercises/ch05/ex03_word_count.c`

### Exercise 5.4: Array Rotation

Rotate an array left by k positions.

**Example:**
```
Input:  [1, 2, 3, 4, 5], k=2
Output: [3, 4, 5, 1, 2]
```

**Your task:** Create `exercises/ch05/ex04_rotate.c`

### Exercise 5.5: Palindrome Checker

Check if a string is a palindrome.

**Python version:**
```python
def is_palindrome(s):
    return s == s[::-1]
```

**Your task:** Create `exercises/ch05/ex05_palindrome.c`

---

## Key Takeaways

1. **Arrays are fixed-size** — you can't append or resize
2. **No bounds checking** — you must track size and stay in bounds
3. **Calculate size** with `sizeof(arr) / sizeof(arr[0])`
4. **Strings are char arrays** ending in `'\0'`
5. **Never compare strings with `==`** — use `strcmp()`
6. **String literals are read-only** — use `char[]` for mutable strings
7. **Buffer overflows are dangerous** — always check sizes

## Next Chapter

Ready for the most important concept in C? Continue to [Chapter 6: Pointers](06-pointers.md).
