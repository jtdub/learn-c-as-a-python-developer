# Common Gotchas for Python Developers

A collection of traps that catch Python developers learning C.

## 1. Forgetting Semicolons

**Python:**
```python
x = 5
print(x)
```

**C (wrong):**
```c
int x = 5
printf("%d\n", x)  // ERROR: expected ';'
```

**C (correct):**
```c
int x = 5;
printf("%d\n", x);
```

## 2. Assignment vs Comparison

**The bug:**
```c
if (x = 5) {  // ASSIGNS 5 to x, always true!
    printf("x is 5\n");
}
```

**The fix:**
```c
if (x == 5) {  // COMPARES x to 5
    printf("x is 5\n");
}
```

**Pro tip:** Some developers write `5 == x` (Yoda conditions) so `5 = x` would error.

## 3. String Comparison with ==

**Python:**
```python
if name == "Alice":
    print("Hello Alice")
```

**C (wrong):**
```c
if (name == "Alice") {  // Compares ADDRESSES, not content!
    printf("Hello Alice\n");
}
```

**C (correct):**
```c
if (strcmp(name, "Alice") == 0) {  // strcmp returns 0 if equal
    printf("Hello Alice\n");
}
```

## 4. Uninitialized Variables

**Python:**
```python
# This would raise NameError
print(x)  # Error: x is not defined
```

**C (dangerous):**
```c
int x;
printf("%d\n", x);  // Prints garbage! No error.
```

**C (safe):**
```c
int x = 0;  // Always initialize
printf("%d\n", x);
```

## 5. Integer Division

**Python 3:**
```python
result = 5 / 2  # 2.5
```

**C:**
```c
int result = 5 / 2;  // 2 (integer division!)
double result = 5 / 2;  // Still 2.0! Division happens first

// Correct:
double result = 5.0 / 2;  // 2.5
double result = (double)5 / 2;  // 2.5
```

## 6. Array Bounds

**Python:**
```python
arr = [1, 2, 3]
print(arr[10])  # IndexError
print(arr[-1])  # 3 (last element)
```

**C:**
```c
int arr[] = {1, 2, 3};
printf("%d\n", arr[10]);  // No error! Reads garbage
printf("%d\n", arr[-1]);  // No error! Reads garbage

// No negative indexing - must do:
printf("%d\n", arr[2]);  // arr[len-1]
```

## 7. Missing Braces

**The bug:**
```c
if (x > 0)
    printf("positive\n");
    do_something();  // ALWAYS runs! Not part of if!
```

**The fix:**
```c
if (x > 0) {
    printf("positive\n");
    do_something();  // Only runs if x > 0
}
```

## 8. Forgetting & in scanf

**Wrong:**
```c
int x;
scanf("%d", x);  // Undefined behavior! Missing &
```

**Correct:**
```c
int x;
scanf("%d", &x);  // Pass address of x

// Exception: arrays don't need &
char name[50];
scanf("%s", name);  // Array name IS an address
```

## 9. String Mutability Confusion

**Python:**
```python
s = "hello"
s[0] = "H"  # Error: strings are immutable
```

**C (it depends):**
```c
// Array form: mutable
char s1[] = "hello";
s1[0] = 'H';  // OK: "Hello"

// Pointer form: immutable
char *s2 = "hello";
s2[0] = 'H';  // CRASH or undefined behavior!
```

## 10. printf Type Mismatch

**Wrong:**
```c
double pi = 3.14159;
printf("%d\n", pi);  // Wrong! %d is for int
// May print garbage or crash
```

**Correct:**
```c
double pi = 3.14159;
printf("%f\n", pi);  // Correct! %f for double
```

## 11. Returning Local Variables

**Wrong:**
```c
char *get_greeting(void) {
    char greeting[] = "Hello";  // Local variable
    return greeting;  // DANGER: greeting is destroyed!
}
// Returned pointer is dangling (points to freed memory)
```

**Correct options:**
```c
// Option 1: Static (not thread-safe)
char *get_greeting(void) {
    static char greeting[] = "Hello";
    return greeting;
}

// Option 2: Heap allocation (caller must free)
char *get_greeting(void) {
    char *greeting = malloc(6);
    strcpy(greeting, "Hello");
    return greeting;
}

// Option 3: Caller provides buffer
void get_greeting(char *buffer, size_t size) {
    strncpy(buffer, "Hello", size - 1);
    buffer[size - 1] = '\0';
}
```

## 12. Switch Fallthrough

**Wrong (maybe):**
```c
switch (grade) {
    case 'A':
        printf("Excellent\n");
        // No break! Falls through to B!
    case 'B':
        printf("Good\n");
        break;
}
// If grade is 'A', prints "Excellent" AND "Good"
```

**Correct:**
```c
switch (grade) {
    case 'A':
        printf("Excellent\n");
        break;  // Don't forget!
    case 'B':
        printf("Good\n");
        break;
}
```

## 13. sizeof with Pointers

**Wrong:**
```c
void print_array(int *arr) {
    int size = sizeof(arr) / sizeof(arr[0]);  // WRONG!
    // sizeof(arr) is pointer size (4 or 8), not array size
}
```

**Correct:**
```c
void print_array(int *arr, int size) {
    // Size must be passed explicitly
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
```

## 14. Buffer Overflow with strcpy

**Wrong:**
```c
char dest[5];
strcpy(dest, "Hello World");  // Overflow! dest is too small
```

**Correct:**
```c
char dest[20];
strncpy(dest, "Hello World", sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';  // Ensure null termination
```

## 15. Modifying Loop Variable

**Unexpected in C:**
```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
    i += 2;  // This affects the loop!
}
// Prints: 0, 3, 6, 9 (not 0-9)
```

Unlike Python's `for i in range()`, C's for loop directly uses the variable.

## 16. Truthiness Differences

**Python:**
```python
if []:  # Empty list is False
    pass
if "":  # Empty string is False
    pass
```

**C:**
```c
char *s = "";
if (s) {    // TRUE! Pointer is not NULL
}

int arr[] = {};
// Can't check if array is "empty" - arrays don't work that way
```

## 17. Memory Leaks

**Python:**
```python
def process():
    data = [0] * 1000000
    return data[0]
# Memory automatically freed when data goes out of scope
```

**C (leaky):**
```c
int process(void) {
    int *data = malloc(1000000 * sizeof(int));
    return data[0];
    // Memory leak! data is never freed
}
```

**C (correct):**
```c
int process(void) {
    int *data = malloc(1000000 * sizeof(int));
    int result = data[0];
    free(data);
    return result;
}
```

## Summary: Mental Checklist

Before compiling, ask yourself:

- [ ] Did I end every statement with `;`?
- [ ] Did I use `==` for comparison, not `=`?
- [ ] Did I use `strcmp()` for string comparison?
- [ ] Did I initialize all variables?
- [ ] Did I use braces `{}` around all blocks?
- [ ] Did I use `&` in `scanf` (except for arrays)?
- [ ] Did I match `printf` format specifiers to types?
- [ ] Did I `free()` everything I `malloc()`ed?
- [ ] Did I check `malloc` return for NULL?
- [ ] Did I avoid returning pointers to local variables?
