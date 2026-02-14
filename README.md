# Learn C as a Python Developer

A comprehensive guide to learning C programming, specifically designed for Python developers. This guide leverages your existing Python knowledge to help you understand C concepts more quickly.

## Quick Start

### View the Documentation

```bash
# Install mkdocs
pip install -r requirements.txt

# Serve locally
mkdocs serve

# Open http://127.0.0.1:8000 in your browser
```

### Build Static Site

```bash
mkdocs build
# Output in site/ directory
```

## Contents

### Getting Started
- **Why Learn C?** — Benefits for Python developers
- **Mental Model Shifts** — Key differences between Python and C
- **Setting Up** — Compiler installation and environment setup

### Chapters
1. **Hello World** — Basic syntax and compilation
2. **Types and Variables** — Static typing, primitive types
3. **Control Flow** — If/else, loops, switch
4. **Functions** — Prototypes, pass by value
5. **Arrays and Strings** — Fixed arrays, null-terminated strings
6. **Pointers** — Memory addresses, dereferencing
7. **Memory Management** — Stack vs heap, malloc/free
8. **Structs** — Custom data types
9. **File I/O** — Reading and writing files
10. **Building Larger Programs** — Headers, multiple files, Make

### Reference
- **Python to C Cheatsheet** — Quick translation guide
- **Common Gotchas** — Traps for Python developers
- **Next Steps** — Where to go after this guide

## Exercises

Each chapter includes hands-on exercises in the `exercises/` directory:

```
exercises/
├── ch01/          # Hello World exercises
├── ch02/          # Types exercises
├── ch03/          # Control flow exercises
├── ch04/          # Function exercises
├── ch05/          # Array/string exercises
├── ch06/          # Pointer exercises
├── ch07/          # Memory management exercises
├── ch08/          # Struct exercises
├── ch09/          # File I/O exercises
└── ch10/          # Multi-file project exercises
```

### Compiling Exercises

```bash
# Basic compilation
cc -Wall -o exercise exercise.c

# With debug symbols
cc -Wall -g -o exercise exercise.c

# With math library (some exercises need this)
cc -Wall -o exercise exercise.c -lm
```

## Prerequisites

- Python programming experience
- Basic command line familiarity
- A C compiler (gcc, clang, or equivalent)

## License

See [LICENSE](LICENSE) for details.
