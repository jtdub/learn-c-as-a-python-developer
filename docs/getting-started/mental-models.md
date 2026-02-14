# Mental Model Shifts

Before writing C code, you need to adjust how you think about programs. This chapter covers the fundamental differences between Python and C.

## Key Differences at a Glance

| Aspect | Python | C |
|--------|--------|---|
| **Typing** | Dynamic, duck typing | Static, explicit types |
| **Memory** | Automatic (garbage collected) | Manual (you allocate and free) |
| **Compilation** | Interpreted | Compiled to machine code |
| **Strings** | Immutable objects | Character arrays (mutable) |
| **Arrays** | Lists (dynamic, heterogeneous) | Fixed-size, homogeneous |
| **Errors** | Exceptions | Return codes, segfaults |
| **Scope** | Indentation-based | Brace-based `{}` |

## The Compilation Process

Understanding compilation is crucial for C development.

### Python Execution

```
┌─────────────┐
│ script.py   │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   Python    │
│ Interpreter │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│  Execution  │
└─────────────┘
```

Python reads your source code and executes it line by line. Errors appear at runtime.

### C Compilation

```
┌─────────────┐
│  source.c   │
└──────┬──────┘
       │
       ▼ Preprocessor (#include, #define)
┌─────────────┐
│  Expanded   │
│   source    │
└──────┬──────┘
       │
       ▼ Compiler
┌─────────────┐
│ Object file │
│    (.o)     │
└──────┬──────┘
       │
       ▼ Linker
┌─────────────┐
│ Executable  │
│  (binary)   │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│  Execution  │
└─────────────┘
```

C transforms your source into machine code before running. Many errors are caught at compile time.

## Static vs Dynamic Typing

### Python: Types Belong to Values

```python
x = 42        # x references an int object
x = "hello"   # Now x references a str object
x = [1, 2, 3] # Now x references a list

# The variable x has no fixed type
```

### C: Types Belong to Variables

```c
int x = 42;      // x is forever an int
x = "hello";     // ERROR: incompatible types
x = 3.14;        // ERROR: loses precision (warning)
```

!!! info "Why This Matters"
    In C, the compiler needs to know exactly how much memory each variable needs. An `int` is 4 bytes, a `char` is 1 byte, etc.

## Memory: Manual vs Automatic

### Python: Garbage Collection

```python
def create_list():
    big_list = list(range(1000000))
    return big_list[0]  # big_list is cleaned up automatically

result = create_list()
# No memory leak - Python's GC handles it
```

### C: You're in Charge

```c
#include <stdlib.h>

int create_array() {
    int *big_array = malloc(1000000 * sizeof(int));
    int result = big_array[0];
    free(big_array);  // YOU must free it
    return result;
}

// Forget free()? Memory leak.
// free() twice? Crash.
// Use after free()? Undefined behavior.
```

## Arrays: Fixed vs Dynamic

### Python Lists

```python
numbers = []           # Empty, can grow
numbers.append(1)      # Add element
numbers.append("two")  # Different type, no problem
numbers.append([3])    # Nested structure, fine
print(len(numbers))    # Built-in length
```

### C Arrays

```c
int numbers[5];           // Fixed size of 5
// numbers[5] = 6;        // Out of bounds! (but C won't stop you)
// numbers.append(1);     // No such method
// No built-in length - you track it yourself

int size = sizeof(numbers) / sizeof(numbers[0]);  // Calculate size
```

## Strings: Objects vs Character Arrays

### Python Strings

```python
s = "hello"
s = s + " world"  # Creates new string
s[0] = "H"        # ERROR: strings are immutable
print(len(s))     # Built-in length
```

### C Strings

```c
char s[] = "hello";
s[0] = 'H';       // OK! C strings are mutable
// s = s + " world";  // ERROR: can't concatenate like this
strcat(s, " world");  // Use library function (dangerous!)

// Length calculation walks the string until \0
int len = strlen(s);
```

!!! warning "The Null Terminator"
    C strings end with a special character `'\0'`. The string `"hello"` is actually 6 bytes: `h`, `e`, `l`, `l`, `o`, `\0`.

## Error Handling: Exceptions vs Return Codes

### Python Exceptions

```python
try:
    result = risky_operation()
except ValueError as e:
    print(f"Error: {e}")
except FileNotFoundError:
    print("File not found")
```

### C Return Codes

```c
#include <stdio.h>
#include <errno.h>

FILE *f = fopen("file.txt", "r");
if (f == NULL) {
    perror("Error opening file");  // Prints system error
    return 1;  // Exit with error code
}
// No exceptions - you check every return value
```

## Truthiness

### Python

```python
if []:           # False (empty list)
if [0]:          # True (non-empty list)
if "":           # False (empty string)
if "0":          # True (non-empty string)
if None:         # False
```

### C

```c
if (0)      // False
if (1)      // True
if (-1)     // True (any non-zero is true)
if (NULL)   // False (NULL is 0)
if (ptr)    // True if ptr is not NULL
```

!!! tip "C's Simple Rule"
    Zero is false. Everything else is true.

## What About Objects?

Python has classes with methods, inheritance, and encapsulation. C has... none of that.

```python
class Dog:
    def __init__(self, name):
        self.name = name

    def bark(self):
        print(f"{self.name} says woof!")
```

```c
// C has structs - data without methods
struct Dog {
    char name[50];
};

// Functions are separate
void dog_bark(struct Dog *d) {
    printf("%s says woof!\n", d->name);
}
```

C achieves similar patterns through conventions, but there's no language support for OOP.

## Ready to Code?

Now that you understand the mental shifts, let's [set up your environment](setup.md).
