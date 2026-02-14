# Chapter 9: File I/O

Reading and writing files in C is more manual than Python, but the concepts are similar.

## Opening and Closing Files

=== "Python"

    ```python
    with open("file.txt", "r") as f:
        content = f.read()
    ```

=== "C"

    ```c
    FILE *f = fopen("file.txt", "r");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    // ... use file ...

    fclose(f);
    ```

### File Modes

| Mode | Description | Python |
|------|-------------|--------|
| `"r"` | Read (must exist) | `"r"` |
| `"w"` | Write (creates/truncates) | `"w"` |
| `"a"` | Append (creates if needed) | `"a"` |
| `"r+"` | Read and write (must exist) | `"r+"` |
| `"w+"` | Read and write (creates/truncates) | `"w+"` |
| `"rb"` | Read binary | `"rb"` |
| `"wb"` | Write binary | `"wb"` |

### Error Checking

Always check if `fopen` succeeded:

```c
FILE *f = fopen("file.txt", "r");
if (f == NULL) {
    perror("fopen");  // Prints: "fopen: No such file or directory"
    return 1;
}
```

!!! warning "No Context Manager"
    C has no `with` statement. You must manually call `fclose()` when done, even if errors occur.

## Reading Files

### Character by Character

```c
FILE *f = fopen("file.txt", "r");
if (f == NULL) return 1;

int ch;  // int, not char (to detect EOF)
while ((ch = fgetc(f)) != EOF) {
    putchar(ch);  // Print character
}

fclose(f);
```

### Line by Line

```c
FILE *f = fopen("file.txt", "r");
if (f == NULL) return 1;

char line[256];
while (fgets(line, sizeof(line), f) != NULL) {
    printf("%s", line);  // fgets keeps the newline!
}

fclose(f);
```

!!! note "fgets Behavior"
    - Reads until newline, EOF, or buffer full
    - Includes the newline character in the string
    - Null-terminates the result
    - Returns NULL on EOF or error

### Formatted Reading (scanf from file)

```c
FILE *f = fopen("data.txt", "r");
if (f == NULL) return 1;

int num;
char name[50];
double value;

// Read: "42 Alice 3.14"
while (fscanf(f, "%d %s %lf", &num, name, &value) == 3) {
    printf("%d, %s, %f\n", num, name, value);
}

fclose(f);
```

### Read Entire File

```c
// Python: content = f.read()
// C: Manual approach

FILE *f = fopen("file.txt", "r");
if (f == NULL) return 1;

// Get file size
fseek(f, 0, SEEK_END);
long size = ftell(f);
fseek(f, 0, SEEK_SET);  // rewind

// Allocate buffer
char *content = malloc(size + 1);
if (content == NULL) {
    fclose(f);
    return 1;
}

// Read entire file
fread(content, 1, size, f);
content[size] = '\0';  // Null-terminate

printf("%s", content);

free(content);
fclose(f);
```

## Writing Files

### Basic Writing

```c
FILE *f = fopen("output.txt", "w");
if (f == NULL) return 1;

// Write string
fputs("Hello, World!\n", f);

// Write formatted (like printf to file)
fprintf(f, "Number: %d\n", 42);
fprintf(f, "Float: %.2f\n", 3.14);

// Write single character
fputc('X', f);

fclose(f);
```

### Appending

```c
FILE *f = fopen("log.txt", "a");
if (f == NULL) return 1;

fprintf(f, "New log entry\n");

fclose(f);
```

## Binary Files

For non-text data (images, structs, etc.):

### Writing Binary

```c
typedef struct {
    int id;
    char name[20];
    double score;
} Record;

Record records[] = {
    {1, "Alice", 95.5},
    {2, "Bob", 87.3},
    {3, "Charlie", 92.1}
};

FILE *f = fopen("data.bin", "wb");
if (f == NULL) return 1;

// Write array of structs
fwrite(records, sizeof(Record), 3, f);

fclose(f);
```

### Reading Binary

```c
Record records[3];

FILE *f = fopen("data.bin", "rb");
if (f == NULL) return 1;

// Read array of structs
size_t count = fread(records, sizeof(Record), 3, f);
printf("Read %zu records\n", count);

for (int i = 0; i < count; i++) {
    printf("%d: %s (%.1f)\n",
           records[i].id, records[i].name, records[i].score);
}

fclose(f);
```

## File Positioning

```c
FILE *f = fopen("file.txt", "r");

// Get current position
long pos = ftell(f);

// Seek to position
fseek(f, 0, SEEK_SET);   // Beginning of file
fseek(f, 0, SEEK_END);   // End of file
fseek(f, 10, SEEK_CUR);  // 10 bytes forward from current

// Rewind to beginning
rewind(f);  // Same as fseek(f, 0, SEEK_SET)

fclose(f);
```

## Standard Streams

C has three pre-opened file streams:

| Stream | Purpose | Python |
|--------|---------|--------|
| `stdin` | Standard input | `sys.stdin` |
| `stdout` | Standard output | `sys.stdout` |
| `stderr` | Standard error | `sys.stderr` |

```c
// Read from stdin
char line[100];
fgets(line, sizeof(line), stdin);

// printf is shorthand for fprintf(stdout, ...)
printf("Hello\n");
fprintf(stdout, "Hello\n");  // Equivalent

// Write errors to stderr
fprintf(stderr, "Error: something went wrong\n");
```

## Python Comparison

| Python | C |
|--------|---|
| `open(file, mode)` | `fopen(file, mode)` |
| `f.read()` | `fread` or loop with `fgetc` |
| `f.readline()` | `fgets` |
| `f.write(s)` | `fputs` or `fprintf` |
| `f.close()` | `fclose` |
| `with` context manager | Manual `fclose` |
| Exceptions | Check return values |

---

## Exercises

### Exercise 9.1: File Copy

Create a program that copies one file to another.

**Usage:** `./copy source.txt dest.txt`

**Requirements:**

1. Handle binary files correctly
2. Check for errors (file not found, write failed)
3. Report bytes copied

**Your task:** Create `exercises/ch09/ex01_file_copy.c`

### Exercise 9.2: Word Count (wc clone)

Count lines, words, and characters in a file.

**Example output:**
```
  10   50  300 file.txt
```

**Python equivalent:**
```python
with open("file.txt") as f:
    content = f.read()
    lines = content.count('\n')
    words = len(content.split())
    chars = len(content)
```

**Your task:** Create `exercises/ch09/ex02_wc.c`

### Exercise 9.3: CSV Parser

Parse a simple CSV file and print as a formatted table.

**Input (data.csv):**
```
Name,Age,City
Alice,30,New York
Bob,25,Los Angeles
Charlie,35,Chicago
```

**Output:**
```
| Name    | Age | City        |
|---------|-----|-------------|
| Alice   | 30  | New York    |
| Bob     | 25  | Los Angeles |
| Charlie | 35  | Chicago     |
```

**Your task:** Create `exercises/ch09/ex03_csv_parser.c`

### Exercise 9.4: Binary Record Storage

Create a program that stores and retrieves records in a binary file.

```c
typedef struct {
    int id;
    char name[50];
    double balance;
} Account;
```

**Operations:**

1. Add new account
2. List all accounts
3. Find account by ID
4. Update account balance

**Your task:** Create `exercises/ch09/ex04_accounts.c`

---

## Key Takeaways

1. **Always check `fopen` return** — NULL means failure
2. **Always call `fclose`** — no automatic cleanup
3. **Use `fgets` for lines** — includes newline, safer than `gets`
4. **Use `fprintf` for formatting** — like `printf` but to file
5. **Binary mode for non-text** — `"rb"`, `"wb"`
6. **`fread`/`fwrite` for binary** — efficient for structs
7. **Check return values** — `fread` returns count read, etc.
8. **`stderr` for errors** — separate from normal output

## Next Chapter

Ready to build larger programs? Continue to [Chapter 10: Building Larger Programs](10-building-programs.md).
