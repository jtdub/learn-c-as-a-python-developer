# Chapter 10: Building Larger Programs

As your C programs grow, you'll need to split them into multiple files, create headers, and use build tools. This chapter covers the essentials.

## The Problem with Single Files

When your program is small, one `.c` file works fine. But as it grows:

- **Compilation is slow** — one change recompiles everything
- **Organization suffers** — hard to find things in 5000 lines
- **Collaboration is hard** — merge conflicts everywhere
- **Reusability is poor** — can't share code between programs

## Headers and Source Files

### The Split

- **Header files (`.h`)** — declarations (what exists)
- **Source files (`.c`)** — definitions (how it works)

### Example: Math Utilities

**math_utils.h:**
```c
#ifndef MATH_UTILS_H  // Include guard
#define MATH_UTILS_H

// Function declarations (prototypes)
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

// Constants
#define PI 3.14159265359

#endif
```

**math_utils.c:**
```c
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) return 0;  // Or handle error
    return (double)a / b;
}
```

**main.c:**
```c
#include <stdio.h>
#include "math_utils.h"

int main(void) {
    printf("5 + 3 = %d\n", add(5, 3));
    printf("5 - 3 = %d\n", subtract(5, 3));
    printf("5 * 3 = %d\n", multiply(5, 3));
    printf("5 / 3 = %.2f\n", divide(5, 3));
    printf("PI = %f\n", PI);
    return 0;
}
```

### Include Guards

Without include guards, the same header included twice causes errors:

```c
// WRONG: file.h included multiple times
#include "header.h"
#include "other.h"  // Also includes header.h internally
// Error: redefinition of struct/function/etc.
```

Include guards prevent this:

```c
#ifndef HEADER_H
#define HEADER_H

// Header content here...

#endif
```

Or use the modern pragma:

```c
#pragma once  // Non-standard but widely supported

// Header content here...
```

## Compiling Multiple Files

### Method 1: All at Once

```bash
cc -Wall -o program main.c math_utils.c
```

Simple, but recompiles everything each time.

### Method 2: Separate Compilation

```bash
# Compile each source to object file
cc -Wall -c main.c         # Creates main.o
cc -Wall -c math_utils.c   # Creates math_utils.o

# Link object files into executable
cc -o program main.o math_utils.o
```

Only recompile changed files:

```bash
# After modifying only main.c:
cc -Wall -c main.c
cc -o program main.o math_utils.o
```

## Makefiles

Manually tracking dependencies is tedious. Make automates it.

### Basic Makefile

```makefile
# Variables
CC = cc
CFLAGS = -Wall -Wextra -g

# Default target
program: main.o math_utils.o
	$(CC) -o program main.o math_utils.o

# Compile source files
main.o: main.c math_utils.h
	$(CC) $(CFLAGS) -c main.c

math_utils.o: math_utils.c math_utils.h
	$(CC) $(CFLAGS) -c math_utils.c

# Utility targets
clean:
	rm -f *.o program

.PHONY: clean
```

### Using Make

```bash
make          # Build the program
make clean    # Remove build files
make program  # Explicitly build 'program' target
```

### How Make Works

1. Checks if target is older than dependencies
2. If so, runs the recipe (indented commands)
3. Recursively builds dependencies first

```makefile
# Target: dependencies
#     recipe (must be indented with TAB, not spaces!)
program: main.o math_utils.o
	$(CC) -o program main.o math_utils.o
```

### Pattern Rules

Avoid repetition with pattern rules:

```makefile
CC = cc
CFLAGS = -Wall -Wextra -g

SRCS = main.c math_utils.c string_utils.c
OBJS = $(SRCS:.c=.o)

program: $(OBJS)
	$(CC) -o $@ $^

# Pattern rule: any .o depends on corresponding .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program

.PHONY: clean
```

Special variables:

- `$@` — the target name
- `$<` — first dependency
- `$^` — all dependencies

## Project Structure

A typical C project:

```
myproject/
├── Makefile
├── README.md
├── include/           # Header files
│   ├── math_utils.h
│   └── string_utils.h
├── src/               # Source files
│   ├── main.c
│   ├── math_utils.c
│   └── string_utils.c
├── tests/             # Test files
│   └── test_math.c
└── build/             # Build output (gitignored)
    ├── main.o
    └── program
```

### Makefile for This Structure

```makefile
CC = cc
CFLAGS = -Wall -Wextra -I./include -g

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET = $(BUILD_DIR)/program

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
```

## Static Libraries

Bundle object files into a library:

```bash
# Create library
ar rcs libmath.a math_utils.o string_utils.o

# Use it
cc -o program main.c -L. -lmath
```

Or in a Makefile:

```makefile
libmath.a: math_utils.o string_utils.o
	ar rcs $@ $^

program: main.o libmath.a
	$(CC) -o $@ main.o -L. -lmath
```

## Python Comparison

| Python | C |
|--------|---|
| `import module` | `#include "module.h"` |
| `module.py` | `module.h` + `module.c` |
| `__init__.py` | Include guards |
| `pip install` | Link libraries manually |
| `setup.py` / `pyproject.toml` | `Makefile` |
| `python script.py` | `./program` (after compilation) |

---

## Exercises

### Exercise 10.1: Multi-File Calculator

Split a calculator into multiple files.

**Structure:**
```
calculator/
├── Makefile
├── main.c
├── operations.h
├── operations.c
├── display.h
└── display.c
```

**operations.h/c:** Math functions
**display.h/c:** Output formatting

**Your task:** Create `exercises/ch10/calculator/`

### Exercise 10.2: String Library

Create a reusable string utility library.

**Functions:**
```c
// string_utils.h
char *str_upper(const char *s);      // Return uppercase copy
char *str_lower(const char *s);      // Return lowercase copy
char *str_trim(const char *s);       // Return trimmed copy
char **str_split(const char *s, char delim, int *count);
void str_split_free(char **parts, int count);
```

Include a main.c that demonstrates all functions.

**Your task:** Create `exercises/ch10/string_lib/`

### Exercise 10.3: Build System Practice

Take any previous exercise and reorganize it:

1. Create proper `include/` and `src/` directories
2. Write a complete Makefile
3. Add a `clean` target
4. Add a `test` target that runs basic tests

**Your task:** Reorganize in `exercises/ch10/structured_project/`

---

## Key Takeaways

1. **Headers declare, sources define** — separation of interface and implementation
2. **Include guards prevent multiple inclusion** — `#ifndef` or `#pragma once`
3. **Angle brackets for system headers** — `<stdio.h>`
4. **Quotes for your headers** — `"myheader.h"`
5. **Separate compilation is faster** — only rebuild what changed
6. **Make automates builds** — tracks dependencies for you
7. **Object files link together** — `cc -o prog a.o b.o c.o`
8. **Libraries bundle code** — `ar rcs lib.a ...`

## Congratulations!

You've completed the core C curriculum. You now understand:

- Types, variables, and control flow
- Functions and scope
- Arrays and strings
- Pointers and memory management
- Structs and data organization
- File I/O
- Multi-file programs and build systems

Continue to the [Python to C Cheatsheet](../reference/cheatsheet.md) for a quick reference, or see [Next Steps](../reference/next-steps.md) for where to go from here.
