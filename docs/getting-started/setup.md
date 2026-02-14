# Setting Up Your Environment

Let's get you ready to compile and run C programs.

## Installing a C Compiler

=== "macOS"

    macOS includes Clang as part of the Xcode Command Line Tools:

    ```bash
    xcode-select --install
    ```

    Verify the installation:

    ```bash
    cc --version
    # or
    clang --version
    ```

=== "Linux (Ubuntu/Debian)"

    Install the GCC compiler and build tools:

    ```bash
    sudo apt update
    sudo apt install build-essential
    ```

    Verify:

    ```bash
    gcc --version
    ```

=== "Linux (Fedora/RHEL)"

    ```bash
    sudo dnf groupinstall "Development Tools"
    ```

    Verify:

    ```bash
    gcc --version
    ```

=== "Windows"

    **Option 1: WSL (Recommended)**

    Install Windows Subsystem for Linux, then follow Linux instructions.

    **Option 2: MinGW-w64**

    1. Download from [MinGW-w64](https://www.mingw-w64.org/)
    2. Add to PATH
    3. Use `gcc` from Command Prompt

## Your First Compilation

Create a file named `hello.c`:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

### Compile and Run

```bash
# Compile
cc hello.c -o hello

# Run
./hello
```

You should see:
```
Hello, World!
```

## Recommended Compiler Flags

Always compile with warnings enabled:

```bash
cc -Wall -Wextra -o program program.c
```

| Flag | Purpose |
|------|---------|
| `-Wall` | Enable most warnings |
| `-Wextra` | Enable additional warnings |
| `-Werror` | Treat warnings as errors |
| `-g` | Include debug symbols |
| `-O2` | Enable optimizations |
| `-std=c99` | Use C99 standard |
| `-std=c11` | Use C11 standard |

!!! tip "Start Strict"
    Using `-Wall -Wextra` catches many bugs early. C is permissive by default—the compiler won't warn about many dangerous patterns unless you ask.

## IDE and Editor Options

### VS Code (Recommended)

1. Install [VS Code](https://code.visualstudio.com/)
2. Install the "C/C++" extension by Microsoft
3. For better experience, also install "Code Runner"

### Vim/Neovim

Works out of the box. Consider adding:

- `vim-lsp` or `coc.nvim` for language server support
- `clangd` as your language server

### CLion

JetBrains' C/C++ IDE. Excellent but requires a license.

### Xcode (macOS)

Full IDE with debugger. Overkill for learning, but powerful.

## Debugging with GDB/LLDB

When things go wrong (and they will), you'll need a debugger.

=== "GDB (Linux)"

    ```bash
    # Compile with debug symbols
    gcc -g -o program program.c

    # Run in debugger
    gdb ./program

    # Common commands:
    # run          - Start program
    # break main   - Set breakpoint at main
    # next         - Step over
    # step         - Step into
    # print x      - Print variable x
    # backtrace    - Show call stack
    # quit         - Exit
    ```

=== "LLDB (macOS)"

    ```bash
    # Compile with debug symbols
    cc -g -o program program.c

    # Run in debugger
    lldb ./program

    # Common commands:
    # run          - Start program
    # b main       - Set breakpoint at main
    # n            - Step over
    # s            - Step into
    # p x          - Print variable x
    # bt           - Show call stack
    # quit         - Exit
    ```

## Project Structure

For this guide, use this structure:

```
learn-c-as-a-python-developer/
├── exercises/
│   ├── ch01/
│   │   ├── ex01_hello.c
│   │   └── ex02_ascii_art.c
│   ├── ch02/
│   │   └── ...
│   └── ...
├── docs/
│   └── (this documentation)
└── solutions/
    └── (optional reference solutions)
```

## Verify Your Setup

Create this test program and compile it with full warnings:

```c
// test_setup.c
#include <stdio.h>

int main(void) {
    int x = 42;
    double pi = 3.14159;
    char c = 'A';

    printf("Integer: %d\n", x);
    printf("Double: %f\n", pi);
    printf("Char: %c\n", c);
    printf("Size of int: %zu bytes\n", sizeof(int));

    printf("\nSetup complete! You're ready to learn C.\n");
    return 0;
}
```

```bash
cc -Wall -Wextra -o test_setup test_setup.c && ./test_setup
```

Expected output:
```
Integer: 42
Double: 3.141590
Char: A
Size of int: 4 bytes

Setup complete! You're ready to learn C.
```

## Ready to Code!

Your environment is set up. Let's write your first real C program in [Chapter 1: Hello World](../chapters/01-hello-world.md).
