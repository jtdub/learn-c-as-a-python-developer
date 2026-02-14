# Chapter 3: Control Flow

Control flow in C is similar to Python, but with different syntax. If you know Python's `if`, `for`, and `while`, you'll adapt quickly.

## If/Else Statements

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

### Key Differences

1. **Parentheses required** around conditions
2. **Braces `{}`** instead of colons and indentation
3. **`else if`** instead of `elif`
4. **Semicolons** after statements, not after `if`/`else`

### Single-Statement Bodies

If a block has only one statement, braces are optional:

```c
if (x > 0)
    printf("positive\n");
else
    printf("not positive\n");
```

!!! warning "Always Use Braces"
    Optional braces cause bugs. This is a famous Apple SSL bug:
    ```c
    if (condition)
        do_thing();
        do_other_thing();  // Always runs! Not part of if!
    ```
    Always use braces.

## Comparison Operators

| Python | C | Meaning |
|--------|---|---------|
| `==` | `==` | Equal |
| `!=` | `!=` | Not equal |
| `<` | `<` | Less than |
| `>` | `>` | Greater than |
| `<=` | `<=` | Less or equal |
| `>=` | `>=` | Greater or equal |

## Logical Operators

| Python | C | Meaning |
|--------|---|---------|
| `and` | `&&` | Logical AND |
| `or` | `\|\|` | Logical OR |
| `not` | `!` | Logical NOT |

```c
if (x > 0 && x < 100) {
    printf("x is between 0 and 100\n");
}

if (x < 0 || x > 100) {
    printf("x is out of range\n");
}

if (!is_valid) {
    printf("invalid\n");
}
```

## Truthiness in C

C's rule is simple: **zero is false, everything else is true**.

```c
if (0)       // false
if (1)       // true
if (-1)      // true (non-zero!)
if (42)      // true
if (0.0)     // false
if (NULL)    // false (NULL is 0)
if (ptr)     // true if ptr is not NULL
if ("")     // true! (pointer to empty string is non-zero)
```

!!! info "Python vs C Truthiness"
    Python: Empty containers (`[]`, `{}`, `""`) are falsy.
    C: Empty strings are just pointers, and non-NULL pointers are truthy.

## While Loops

=== "Python"

    ```python
    count = 5
    while count > 0:
        print(count)
        count -= 1
    ```

=== "C"

    ```c
    int count = 5;
    while (count > 0) {
        printf("%d\n", count);
        count--;  // or count = count - 1
    }
    ```

### Increment and Decrement

C has special operators for adding/subtracting 1:

```c
int x = 5;

x++;  // Post-increment: x becomes 6
++x;  // Pre-increment: x becomes 7

x--;  // Post-decrement: x becomes 6
--x;  // Pre-decrement: x becomes 5

// The difference matters in expressions:
int a = 5;
int b = a++;  // b = 5, a = 6 (use then increment)
int c = ++a;  // c = 7, a = 7 (increment then use)
```

## For Loops

This is where C and Python diverge significantly.

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

### For Loop Structure

```c
for (initialization; condition; update) {
    // body
}
```

| Part | Purpose | Equivalent in `for i in range(10)` |
|------|---------|-----------------------------------|
| `int i = 0` | Initialize | Start at 0 |
| `i < 10` | Continue while true | Stop before 10 |
| `i++` | After each iteration | Increment by 1 |

### Common Patterns

```c
// Forward: 0 to 9
for (int i = 0; i < 10; i++) { }

// Backward: 9 to 0
for (int i = 9; i >= 0; i--) { }

// Step by 2: 0, 2, 4, 6, 8
for (int i = 0; i < 10; i += 2) { }

// Iterate over array
int arr[] = {10, 20, 30};
int len = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
}
```

## Do-While Loop

C has a loop that Python lacks: `do-while`. It runs at least once.

```c
int input;
do {
    printf("Enter a positive number: ");
    scanf("%d", &input);
} while (input <= 0);
// The prompt shows at least once, even if input is already valid
```

## Break and Continue

These work the same as Python:

```c
// break: exit the loop
for (int i = 0; i < 100; i++) {
    if (i == 10) {
        break;  // Exit loop when i is 10
    }
    printf("%d\n", i);
}

// continue: skip to next iteration
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;  // Skip even numbers
    }
    printf("%d\n", i);  // Prints only odd numbers
}
```

## Switch Statement

`switch` is like Python's `match` statement (Python 3.10+):

```c
char grade = 'B';

switch (grade) {
    case 'A':
        printf("Excellent!\n");
        break;
    case 'B':
        printf("Good!\n");
        break;
    case 'C':
        printf("Average\n");
        break;
    default:
        printf("Unknown grade\n");
}
```

!!! danger "Don't Forget `break`!"
    Without `break`, execution "falls through" to the next case:
    ```c
    switch (x) {
        case 1:
            printf("one\n");
            // No break! Falls through!
        case 2:
            printf("two\n");
            break;
    }
    // If x is 1, prints "one" AND "two"!
    ```

### Intentional Fall-Through

Sometimes fall-through is useful:

```c
switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("vowel\n");
        break;
    default:
        printf("consonant\n");
}
```

## Ternary Operator

C has a compact if-else expression:

```c
// Python: result = "yes" if condition else "no"
// C:
char *result = (condition) ? "yes" : "no";

// Example
int x = 10;
int abs_x = (x < 0) ? -x : x;  // Absolute value
```

---

## Exercises

### Exercise 3.1: FizzBuzz

The classic interview problem.

**Python version:**
```python
for i in range(1, 101):
    if i % 15 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)
```

**Your task:** Create `exercises/ch03/ex01_fizzbuzz.c`

### Exercise 3.2: Prime Number Checker

Write a function that checks if a number is prime.

**Python version:**
```python
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
```

**Your task:** Create `exercises/ch03/ex02_prime.c`

Print all primes from 1 to 100.

### Exercise 3.3: Number Guessing Game

Create a simple guessing game with user input.

**Requirements:**

1. Generate a "random" number (or hardcode one for now)
2. Ask user to guess
3. Say "too high", "too low", or "correct!"
4. Count guesses

**Your task:** Create `exercises/ch03/ex03_guessing_game.c`

??? tip "Reading Input"
    ```c
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);  // Note the & !
    ```

---

## Key Takeaways

1. **Parentheses required** around conditions: `if (x > 0)`
2. **Use braces** even for single statements
3. **`else if`** not `elif`
4. **C's for loop** has three parts: init, condition, update
5. **`break`** in switch is critical—don't forget it
6. **Truthiness is simple**: 0 is false, non-zero is true
7. **`++` and `--`** are handy shortcuts for increment/decrement

## Next Chapter

Ready to organize code into functions? Continue to [Chapter 4: Functions](04-functions.md).
