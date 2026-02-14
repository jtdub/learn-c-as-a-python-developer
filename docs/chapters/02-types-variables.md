# Chapter 2: Types and Variables

In Python, types belong to values. In C, types belong to variables. This fundamental difference affects everything.

## The Type System

```python
# Python: x can be anything
x = 42
x = "hello"    # Totally fine
x = [1, 2, 3]  # Still fine
```

```c
// C: x is forever an int
int x = 42;
x = "hello";   // ERROR: incompatible types
```

## Primitive Types

C has several built-in types. Here are the most common:

### Integer Types

| Type | Size (typical) | Range | Use Case |
|------|---------------|-------|----------|
| `char` | 1 byte | -128 to 127 | Characters, small numbers |
| `unsigned char` | 1 byte | 0 to 255 | Bytes, positive small numbers |
| `short` | 2 bytes | ±32,767 | Small integers |
| `int` | 4 bytes | ±2.1 billion | General integers |
| `unsigned int` | 4 bytes | 0 to 4.2 billion | Non-negative integers |
| `long` | 8 bytes | ±9.2 quintillion | Large integers |

### Floating-Point Types

| Type | Size | Precision | Python Equivalent |
|------|------|-----------|-------------------|
| `float` | 4 bytes | ~7 digits | — |
| `double` | 8 bytes | ~15 digits | `float` |

!!! info "Python's `int` is Unlimited"
    Python integers can be arbitrarily large. C integers have fixed limits and will **overflow** if exceeded.

## Variable Declaration

### Declaration and Initialization

```c
// Declare and initialize
int age = 30;
double pi = 3.14159;
char grade = 'A';  // Single quotes for characters!

// Declare only (DANGER: contains garbage!)
int count;
printf("%d\n", count);  // Undefined behavior!

// Safe: initialize after declaration
int count;
count = 0;  // Now it's safe

// Multiple declarations
int x, y, z;
int a = 1, b = 2, c = 3;
```

!!! danger "Uninitialized Variables"
    In Python, you can't use undefined variables. In C, uninitialized variables contain **garbage**—whatever was previously in that memory location.

### Constants

```c
// Using const (preferred)
const double PI = 3.14159265359;
PI = 3.0;  // ERROR: can't modify const

// Using #define (preprocessor macro)
#define MAX_SIZE 100
// MAX_SIZE is replaced with 100 before compilation
```

## Format Specifiers

To print variables, use format specifiers in `printf`:

```c
int i = 42;
double d = 3.14;
char c = 'A';
char *s = "hello";

printf("Integer: %d\n", i);       // Integer: 42
printf("Double: %f\n", d);        // Double: 3.140000
printf("Double: %.2f\n", d);      // Double: 3.14
printf("Char: %c\n", c);          // Char: A
printf("String: %s\n", s);        // String: hello
printf("Hex: %x\n", i);           // Hex: 2a
printf("Unsigned: %u\n", 42u);    // Unsigned: 42
printf("Long: %ld\n", 42L);       // Long: 42
```

### Common Format Specifiers

| Specifier | Type | Example |
|-----------|------|---------|
| `%d` | int (decimal) | `42` |
| `%i` | int (decimal) | `42` |
| `%u` | unsigned int | `42` |
| `%ld` | long | `42` |
| `%f` | float/double | `3.140000` |
| `%.2f` | float (2 decimals) | `3.14` |
| `%e` | scientific notation | `3.14e+00` |
| `%c` | char | `A` |
| `%s` | string | `hello` |
| `%x` | hex (lowercase) | `2a` |
| `%X` | hex (uppercase) | `2A` |
| `%p` | pointer address | `0x7fff5fc` |
| `%%` | literal % | `%` |

## The `sizeof` Operator

`sizeof` returns the size of a type or variable in bytes:

```c
printf("char: %zu bytes\n", sizeof(char));      // 1
printf("int: %zu bytes\n", sizeof(int));        // 4 (typically)
printf("double: %zu bytes\n", sizeof(double));  // 8
printf("long: %zu bytes\n", sizeof(long));      // 8 (typically)

int x = 42;
printf("x: %zu bytes\n", sizeof(x));            // 4
```

!!! note "The `%zu` Specifier"
    `sizeof` returns `size_t`, an unsigned type. Use `%zu` to print it correctly.

## Type Conversion

### Implicit Conversion

C automatically converts between compatible types:

```c
int i = 42;
double d = i;      // OK: int to double (widening)
printf("%f\n", d); // 42.000000

double pi = 3.14159;
int truncated = pi;  // WARNING: double to int (narrowing)
printf("%d\n", truncated);  // 3 (fractional part lost!)
```

### Explicit Casting

Use casts to convert explicitly:

```c
double pi = 3.14159;
int truncated = (int)pi;  // Explicit cast

// Useful for division
int a = 5, b = 2;
printf("%d\n", a / b);           // 2 (integer division)
printf("%f\n", (double)a / b);   // 2.500000
```

## Comparing with Python

| Python | C |
|--------|---|
| `x = 42` | `int x = 42;` |
| `type(x)` | (no runtime equivalent) |
| `x = 3.14` | `double x = 3.14;` |
| `x = "hello"` | `char x[] = "hello";` |
| `x = True` | `int x = 1;` (or `bool x = true;` with stdbool.h) |
| `x = None` | `void *x = NULL;` |

## Boolean Values

C89 has no built-in boolean type. Zero is false, non-zero is true.

```c
// C89 style
int is_valid = 1;  // true
int is_empty = 0;  // false

if (is_valid) {
    printf("Valid!\n");
}
```

C99 added `_Bool`, and with `stdbool.h`:

```c
#include <stdbool.h>

bool is_valid = true;
bool is_empty = false;
```

---

## Exercises

### Exercise 2.1: Type Exploration

Write a program that declares variables of different types and prints their sizes using `sizeof()`.

**Expected output:**
```
Type sizes on this system:
char:      1 bytes
short:     2 bytes
int:       4 bytes
long:      8 bytes
float:     4 bytes
double:    8 bytes
```

**Your task:** Create `exercises/ch02/ex01_types.c`

### Exercise 2.2: Temperature Converter

Convert Celsius to Fahrenheit using proper types.

**Python version:**
```python
def celsius_to_fahrenheit(celsius):
    return celsius * 9/5 + 32

temp_c = 100.0
temp_f = celsius_to_fahrenheit(temp_c)
print(f"{temp_c}°C = {temp_f}°F")
```

**Your task:** Create `exercises/ch02/ex02_temperature.c`

??? tip "Hint"
    Use `double` for temperature values to maintain precision.

### Exercise 2.3: Integer Overflow Demo

Demonstrate what happens when you exceed a type's range.

**Example:**
```c
unsigned char small = 255;
small = small + 1;  // What happens?
```

**Your task:** Create `exercises/ch02/ex03_overflow.c`

Show overflow behavior for:

1. `unsigned char` (0-255)
2. `signed char` (-128 to 127)
3. `int` (optional: takes longer to overflow)

---

## Key Takeaways

1. **Declare types explicitly** — `int x`, not just `x`
2. **Initialize variables** — uninitialized = garbage
3. **Mind the limits** — integers overflow, floats lose precision
4. **Use `sizeof`** — don't assume sizes, check them
5. **Format specifiers must match** — `%d` for int, `%f` for double
6. **Casting is explicit** — `(int)3.14` truncates to `3`

## Next Chapter

Ready to control program flow? Continue to [Chapter 3: Control Flow](03-control-flow.md).
