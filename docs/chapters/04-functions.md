# Chapter 4: Functions

Functions in C are similar to Python, but with explicit type declarations and some important differences in how arguments are passed.

## Function Syntax

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

### Anatomy of a C Function

```c
return_type function_name(parameter_type parameter_name, ...) {
    // body
    return value;
}
```

| Part | Description |
|------|-------------|
| `return_type` | Type of value returned (or `void` for nothing) |
| `function_name` | How you call the function |
| `parameters` | Each must have a type |
| `return` | Required if return type isn't `void` |

## Void Functions

When a function doesn't return anything:

=== "Python"

    ```python
    def greet(name):
        print(f"Hello, {name}!")
        # Implicit return None
    ```

=== "C"

    ```c
    void greet(char *name) {
        printf("Hello, %s!\n", name);
        // No return needed (or use: return;)
    }
    ```

## Function Prototypes

In C, functions must be **declared before use**. You have two options:

### Option 1: Define Before `main()`

```c
#include <stdio.h>

// Function defined before it's called
int square(int x) {
    return x * x;
}

int main(void) {
    printf("%d\n", square(5));  // Works
    return 0;
}
```

### Option 2: Use a Prototype

```c
#include <stdio.h>

// Prototype (declaration only)
int square(int x);

int main(void) {
    printf("%d\n", square(5));  // Works because of prototype
    return 0;
}

// Full definition later
int square(int x) {
    return x * x;
}
```

Prototypes are essential for:

- Organizing code (main at top)
- Multiple files (headers)
- Mutual recursion

## Pass by Value

C passes **everything by value**. This means functions receive copies of arguments.

```c
void try_to_modify(int x) {
    x = 999;  // Only modifies the local copy
    printf("Inside function: %d\n", x);  // 999
}

int main(void) {
    int num = 42;
    try_to_modify(num);
    printf("After function: %d\n", num);  // Still 42!
    return 0;
}
```

### Python Comparison

```python
# Python: immutables work similarly
def try_modify(x):
    x = 999  # Rebinds local name

num = 42
try_modify(num)
print(num)  # Still 42

# But lists are different!
def modify_list(lst):
    lst[0] = 999  # Modifies the actual list

my_list = [1, 2, 3]
modify_list(my_list)
print(my_list)  # [999, 2, 3] - modified!
```

In C, to modify the original variable, you need **pointers** (Chapter 6).

## Multiple Return Values?

C functions can only return one value. To return multiple values, you use:

1. **Pointers** (most common) — Chapter 6
2. **Structs** — Chapter 8

```c
// Python can do this:
// def minmax(a, b):
//     return min(a, b), max(a, b)

// C: Use pointers (preview)
void minmax(int a, int b, int *min, int *max) {
    *min = (a < b) ? a : b;
    *max = (a > b) ? a : b;
}

int main(void) {
    int minimum, maximum;
    minmax(5, 3, &minimum, &maximum);
    printf("Min: %d, Max: %d\n", minimum, maximum);
    return 0;
}
```

## Recursion

Recursion works the same as Python:

```c
// Factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

!!! warning "Stack Overflow"
    C has a limited call stack (typically 1-8 MB). Deep recursion will crash with a stack overflow. Python has a recursion limit (~1000) and raises `RecursionError`. C just crashes.

## Static Variables

Functions can have **static local variables** that persist between calls:

```c
int counter(void) {
    static int count = 0;  // Initialized only once
    count++;
    return count;
}

int main(void) {
    printf("%d\n", counter());  // 1
    printf("%d\n", counter());  // 2
    printf("%d\n", counter());  // 3
    return 0;
}
```

This is like a Python closure or class attribute for maintaining state.

## Function Pointers (Preview)

In Python, functions are first-class objects. C has function pointers:

```python
# Python
def apply(func, x):
    return func(x)

result = apply(lambda x: x*2, 5)  # 10
```

```c
// C
int double_it(int x) {
    return x * 2;
}

int apply(int (*func)(int), int x) {
    return func(x);
}

int main(void) {
    int result = apply(double_it, 5);  // 10
    return 0;
}
```

More on this in advanced topics.

---

## Exercises

### Exercise 4.1: Calculator Functions

Implement basic math operations as functions.

**Requirements:**

- `add(a, b)` — returns sum
- `subtract(a, b)` — returns difference
- `multiply(a, b)` — returns product
- `divide(a, b)` — returns quotient (handle division by zero!)

**Your task:** Create `exercises/ch04/ex01_calculator.c`

```c
// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);  // Returns double for precision
```

### Exercise 4.2: Recursive Factorial

Implement factorial using recursion.

**Python version:**
```python
def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n - 1)
```

**Your task:** Create `exercises/ch04/ex02_factorial.c`

Print factorials from 0! to 12! (beyond that, you'll overflow `int`).

### Exercise 4.3: Fibonacci Sequence

Generate Fibonacci numbers iteratively and recursively.

**Requirements:**

1. `fib_recursive(n)` — recursive implementation
2. `fib_iterative(n)` — iterative implementation
3. Compare them: which is faster for `n = 40`?

**Your task:** Create `exercises/ch04/ex03_fibonacci.c`

??? tip "Hint"
    For timing, use `clock()` from `<time.h>`:
    ```c
    #include <time.h>

    clock_t start = clock();
    // ... code to time ...
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    ```

### Exercise 4.4: Power Function

Implement an integer power function without using `math.h`.

**Python version:**
```python
def power(base, exp):
    result = 1
    for _ in range(exp):
        result *= base
    return result
```

**Your task:** Create `exercises/ch04/ex04_power.c`

Bonus: Implement efficient exponentiation by squaring.

---

## Key Takeaways

1. **Declare return type and parameter types** explicitly
2. **`void`** means no parameters or no return value
3. **Prototypes** declare functions before use
4. **Pass by value** means functions get copies
5. **Recursion** works but watch for stack overflow
6. **Static variables** persist between function calls

## Next Chapter

Ready to work with collections of data? Continue to [Chapter 5: Arrays and Strings](05-arrays-strings.md).
