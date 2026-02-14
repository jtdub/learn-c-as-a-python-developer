# Chapter 1: Hello World and Basic Syntax

Every programming journey starts here. Let's see how C's "Hello World" compares to Python's.

## Python vs C: Hello World

=== "Python"

    ```python
    print("Hello, World!")
    ```

=== "C"

    ```c
    #include <stdio.h>

    int main(void) {
        printf("Hello, World!\n");
        return 0;
    }
    ```

That's a lot more code! Let's break it down.

## Breaking Down the C Code

### `#include <stdio.h>`

This is a **preprocessor directive**. Before compilation, the preprocessor copies the contents of `stdio.h` (standard I/O header) into your file.

| C | Python Equivalent |
|---|-------------------|
| `#include <stdio.h>` | `import sys` (sort of) |

The angle brackets `< >` mean "look in system directories." For your own headers, use quotes: `#include "myfile.h"`.

### `int main(void)`

This declares the **main function**—the entry point of every C program.

- `int` — the function returns an integer
- `main` — special name; execution starts here
- `void` — the function takes no parameters

```python
# Python equivalent concept
if __name__ == "__main__":
    main()
```

### The Braces `{ }`

Braces define code blocks in C. They replace Python's indentation.

```c
// Braces define the function body
int main(void) {
    // code here
}
```

!!! warning "Indentation in C"
    C ignores indentation. This is valid (but terrible):
    ```c
    int main(void){printf("Hello");return 0;}
    ```
    Always indent properly for readability!

### `printf("Hello, World!\n");`

`printf` (print formatted) is C's print function.

| Aspect | Python `print()` | C `printf()` |
|--------|------------------|--------------|
| Newline | Automatic | Manual (`\n`) |
| Format | f-strings | Format specifiers |
| Return | `None` | Number of chars printed |

The `\n` is an **escape sequence** for newline. Without it:

```c
printf("Hello");
printf("World");
// Output: HelloWorld (no line break)
```

### `return 0;`

The `main` function returns an exit status to the operating system.

| Value | Meaning |
|-------|---------|
| 0 | Success |
| Non-zero | Error |

```bash
./program
echo $?  # Prints the exit status
```

### The Semicolon `;`

Every statement in C ends with a semicolon. This is the most common error for Python developers.

```c
printf("Line 1\n");  // Semicolon required
printf("Line 2\n");  // Semicolon required
```

## Compiling and Running

```bash
# Create the file
cat > hello.c << 'EOF'
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
EOF

# Compile
cc -Wall -o hello hello.c

# Run
./hello
```

## Comments in C

```c
// Single-line comment (C99 and later)

/* Multi-line
   comment */

/*
 * Common style for
 * longer comments
 */
```

## Format Specifiers Preview

`printf` uses format specifiers to print different types:

```c
printf("Integer: %d\n", 42);
printf("Float: %f\n", 3.14);
printf("String: %s\n", "hello");
printf("Character: %c\n", 'A');
```

More on this in Chapter 2.

---

## Exercises

### Exercise 1.1: Personal Introduction

Create a program that prints your name and favorite programming language.

**Python version for reference:**
```python
name = "Alice"
language = "Python"
print(f"Hi, I'm {name} and I love {language}!")
```

**Your task:** Write the C equivalent in `exercises/ch01/ex01_hello.c`

??? tip "Hint"
    Use `printf` with the `%s` format specifier for strings.

### Exercise 1.2: ASCII Art

Print a multi-line ASCII art pattern.

**Example output:**
```
  *
 ***
*****
 ***
  *
```

**Your task:** Create `exercises/ch01/ex02_ascii_art.c`

??? tip "Hint"
    You'll need multiple `printf` statements or use `\n` within a single string.

### Exercise 1.3: Escape Sequences

Create a program that demonstrates these escape sequences:

| Sequence | Meaning |
|----------|---------|
| `\n` | Newline |
| `\t` | Tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `\'` | Single quote |

**Your task:** Create `exercises/ch01/ex03_escapes.c`

---

## Key Takeaways

1. **`#include`** imports functionality (like Python's `import`)
2. **`main()`** is the entry point (like `if __name__ == "__main__"`)
3. **Braces `{}`** replace Python's indentation
4. **Semicolons** end every statement
5. **`printf`** requires manual `\n` for newlines
6. **`return 0`** indicates successful execution

## Next Chapter

Ready to learn about types and variables? Continue to [Chapter 2: Types and Variables](02-types-variables.md).
