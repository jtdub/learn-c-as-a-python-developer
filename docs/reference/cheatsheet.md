# Python to C Cheatsheet

A quick reference for Python developers writing C.

## Basic Syntax

| Python | C |
|--------|---|
| `print("hello")` | `printf("hello\n");` |
| `# comment` | `// comment` or `/* */` |
| `x = 5` | `int x = 5;` |
| `x = 3.14` | `double x = 3.14;` |
| `s = "hello"` | `char s[] = "hello";` |
| `pass` | `{ }` or `;` |
| `:` (block start) | `{` |
| (indentation end) | `}` |

## Types

| Python | C |
|--------|---|
| `int` (unlimited) | `int` (32-bit), `long` (64-bit) |
| `float` | `double` (prefer) or `float` |
| `str` | `char *` or `char[]` |
| `bool` | `int` (0/1) or `bool` (with `<stdbool.h>`) |
| `None` | `NULL` |
| `True` / `False` | `1` / `0` (or `true`/`false` with stdbool) |
| `list` | arrays or custom implementation |
| `dict` | custom implementation (hash table) |
| `class` | `struct` (no methods) |

## Operators

| Python | C | Notes |
|--------|---|-------|
| `and` | `&&` | |
| `or` | `\|\|` | |
| `not` | `!` | |
| `//` (int div) | `/` | Only for int operands |
| `%` | `%` | |
| `**` | `pow(x, y)` | Need `<math.h>` |
| `==` | `==` | For strings, use `strcmp()` |
| `+=`, `-=` | `+=`, `-=` | |
| `++`, `--` | (none) | `x++` or `++x` |

## Control Flow

### If/Else

=== "Python"

    ```python
    if x > 0:
        print("positive")
    elif x < 0:
        print("negative")
    else:
        print("zero")
    ```

=== "C"

    ```c
    if (x > 0) {
        printf("positive\n");
    } else if (x < 0) {
        printf("negative\n");
    } else {
        printf("zero\n");
    }
    ```

### For Loop

=== "Python"

    ```python
    for i in range(10):
        print(i)
    ```

=== "C"

    ```c
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    ```

### While Loop

=== "Python"

    ```python
    while x > 0:
        print(x)
        x -= 1
    ```

=== "C"

    ```c
    while (x > 0) {
        printf("%d\n", x);
        x--;
    }
    ```

## Functions

=== "Python"

    ```python
    def add(a, b):
        return a + b
    ```

=== "C"

    ```c
    int add(int a, int b) {
        return a + b;
    }
    ```

## Strings

| Python | C |
|--------|---|
| `len(s)` | `strlen(s)` (need `<string.h>`) |
| `s1 + s2` | `strcat(dest, src)` (dangerous!) |
| `s1 == s2` | `strcmp(s1, s2) == 0` |
| `s[0]` | `s[0]` |
| `s[0] = 'X'` | (error in Python) | `s[0] = 'X';` (works in C with `char[]`) |
| `f"x={x}"` | `sprintf(buf, "x=%d", x)` |

## Arrays

| Python | C |
|--------|---|
| `arr = []` | `int arr[SIZE];` (fixed size) |
| `arr = [1, 2, 3]` | `int arr[] = {1, 2, 3};` |
| `len(arr)` | `sizeof(arr)/sizeof(arr[0])` (only for stack arrays) |
| `arr.append(x)` | (not built-in, use dynamic arrays) |
| `arr[-1]` | `arr[len-1]` (no negative indexing) |

## Pointers Quick Reference

```c
int x = 42;
int *p = &x;    // p points to x

*p = 100;       // x is now 100
printf("%d", x); // 100

// Function that modifies original
void double_it(int *val) {
    *val = *val * 2;
}
double_it(&x);  // x is now 200
```

## Memory

| Operation | Python | C |
|-----------|--------|---|
| Allocate | `x = [0] * 100` | `int *x = malloc(100 * sizeof(int));` |
| Free | (automatic) | `free(x);` |
| Resize | `x.extend(...)` | `x = realloc(x, new_size);` |

## Structs vs Classes

=== "Python"

    ```python
    class Point:
        def __init__(self, x, y):
            self.x = x
            self.y = y

    p = Point(10, 20)
    print(p.x)
    ```

=== "C"

    ```c
    typedef struct {
        int x;
        int y;
    } Point;

    Point p = {10, 20};
    printf("%d\n", p.x);

    // With pointer:
    Point *pp = &p;
    printf("%d\n", pp->x);  // Arrow for pointer
    ```

## File I/O

=== "Python"

    ```python
    with open("file.txt", "r") as f:
        for line in f:
            print(line, end="")
    ```

=== "C"

    ```c
    FILE *f = fopen("file.txt", "r");
    if (f == NULL) {
        perror("Error");
        return 1;
    }
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
    ```

## printf Format Specifiers

| Specifier | Type |
|-----------|------|
| `%d` | int |
| `%ld` | long |
| `%f` | float/double |
| `%.2f` | float with 2 decimals |
| `%c` | char |
| `%s` | string |
| `%p` | pointer |
| `%x` | hex |
| `%zu` | size_t |
| `%%` | literal % |

## Common Includes

```c
#include <stdio.h>   // printf, scanf, FILE operations
#include <stdlib.h>  // malloc, free, exit, atoi
#include <string.h>  // strlen, strcpy, strcmp, memcpy
#include <stdbool.h> // bool, true, false
#include <math.h>    // pow, sqrt, sin, cos
#include <ctype.h>   // isalpha, isdigit, toupper
#include <time.h>    // time, clock
#include <limits.h>  // INT_MAX, INT_MIN
```

## Quick Gotchas

1. **Semicolons**: End every statement with `;`
2. **Strings**: `==` compares addresses, use `strcmp()`
3. **Arrays**: No bounds checking, no negative indices
4. **Truthiness**: `0` is false, everything else is true
5. **Integer division**: `5/2` = `2`, not `2.5`
6. **Uninitialized**: Variables contain garbage, not `None`
7. **Memory**: `malloc` needs `free`, every time
8. **scanf**: `scanf("%d", &x)` — don't forget the `&`
9. **Braces**: Forgetting `{}` after `if` is a bug
10. **Assignment**: `if (x = 5)` assigns, doesn't compare
