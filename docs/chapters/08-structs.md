# Chapter 8: Structs and Data Organization

Structs are C's way of grouping related data together—like Python classes, but without methods.

## Defining a Struct

=== "Python"

    ```python
    class Point:
        def __init__(self, x, y):
            self.x = x
            self.y = y

    p = Point(10, 20)
    print(p.x, p.y)
    ```

=== "C"

    ```c
    struct Point {
        int x;
        int y;
    };

    int main(void) {
        struct Point p = {10, 20};
        printf("%d, %d\n", p.x, p.y);
        return 0;
    }
    ```

## Struct Syntax

### Declaration

```c
// Struct definition
struct Person {
    char name[50];
    int age;
    double height;
};

// Creating instances
struct Person alice;
struct Person bob = {"Bob", 30, 5.9};
```

### Accessing Members

```c
struct Person p = {"Alice", 25, 5.5};

// Read
printf("Name: %s\n", p.name);
printf("Age: %d\n", p.age);

// Write
p.age = 26;
strcpy(p.name, "Alicia");  // Use strcpy for strings!
```

## Using typedef

Typing `struct Person` everywhere is tedious. Use `typedef`:

```c
// Method 1: Separate typedef
struct Point {
    int x;
    int y;
};
typedef struct Point Point;

// Method 2: Combined (most common)
typedef struct {
    int x;
    int y;
} Point;

// Now you can use just "Point"
Point p = {10, 20};
```

## Structs and Functions

### Pass by Value (Copies the Struct)

```c
typedef struct {
    char name[50];
    int age;
} Person;

void birthday_broken(Person p) {
    p.age++;  // Only modifies the copy!
}

int main(void) {
    Person alice = {"Alice", 30};
    birthday_broken(alice);
    printf("%d\n", alice.age);  // Still 30!
    return 0;
}
```

### Pass by Pointer (Modifies Original)

```c
void birthday(Person *p) {
    p->age++;  // Arrow operator for pointer to struct
}

int main(void) {
    Person alice = {"Alice", 30};
    birthday(&alice);
    printf("%d\n", alice.age);  // Now 31!
    return 0;
}
```

### The Arrow Operator `->`

When you have a **pointer to struct**, use `->` to access members:

```c
Person alice = {"Alice", 30};
Person *p = &alice;

// These are equivalent:
(*p).age = 31;   // Dereference then access
p->age = 31;     // Arrow operator (preferred)
```

## Nested Structs

```c
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point top_left;
    Point bottom_right;
    char color[20];
} Rectangle;

Rectangle r = {
    {0, 0},      // top_left
    {100, 50},   // bottom_right
    "red"        // color
};

printf("Width: %d\n", r.bottom_right.x - r.top_left.x);
```

## Arrays of Structs

```c
typedef struct {
    char name[50];
    int score;
} Student;

Student class[3] = {
    {"Alice", 95},
    {"Bob", 87},
    {"Charlie", 92}
};

// Access
printf("%s: %d\n", class[0].name, class[0].score);

// Iterate
for (int i = 0; i < 3; i++) {
    printf("%s: %d\n", class[i].name, class[i].score);
}
```

## Dynamic Struct Allocation

```c
typedef struct {
    char *name;  // Pointer, not array
    int age;
} Person;

Person *create_person(const char *name, int age) {
    Person *p = malloc(sizeof(Person));
    if (p == NULL) return NULL;

    p->name = malloc(strlen(name) + 1);
    if (p->name == NULL) {
        free(p);
        return NULL;
    }

    strcpy(p->name, name);
    p->age = age;
    return p;
}

void free_person(Person *p) {
    if (p != NULL) {
        free(p->name);  // Free nested allocation first
        free(p);
    }
}
```

## Structs vs Python Classes

| Feature | Python Class | C Struct |
|---------|--------------|----------|
| Data members | Yes | Yes |
| Methods | Yes | No (use functions) |
| Inheritance | Yes | No (use composition) |
| Encapsulation | `_private` convention | None (all public) |
| Initialization | `__init__` | Manual or designated initializers |
| Memory | Automatic | Manual with `malloc` |

## Designated Initializers (C99)

Initialize specific fields by name:

```c
typedef struct {
    int x;
    int y;
    int z;
} Point3D;

// Initialize only some fields (others are 0)
Point3D p = {.x = 10, .z = 30};  // y is 0

// Out of order is fine
Point3D q = {.z = 3, .x = 1, .y = 2};
```

---

## Exercises

### Exercise 8.1: Student Database

Create a program that manages a list of students.

```c
typedef struct {
    char name[50];
    int id;
    double gpa;
} Student;
```

**Requirements:**

1. Create an array of 5 students
2. Print all students
3. Find the student with the highest GPA
4. Find a student by ID

**Your task:** Create `exercises/ch08/ex01_student.c`

### Exercise 8.2: Complex Numbers

Implement complex number arithmetic using structs.

```c
typedef struct {
    double real;
    double imag;
} Complex;

Complex complex_add(Complex a, Complex b);
Complex complex_subtract(Complex a, Complex b);
Complex complex_multiply(Complex a, Complex b);
void complex_print(Complex c);
```

**Python equivalent:**
```python
c1 = complex(3, 4)
c2 = complex(1, 2)
print(c1 + c2)  # (4+6j)
```

**Your task:** Create `exercises/ch08/ex02_complex.c`

### Exercise 8.3: Date Struct

Create a Date struct with comparison and validation functions.

```c
typedef struct {
    int year;
    int month;
    int day;
} Date;

int is_valid_date(Date d);
int compare_dates(Date a, Date b);  // -1, 0, or 1
Date add_days(Date d, int days);
void print_date(Date d);
```

**Your task:** Create `exercises/ch08/ex03_date.c`

### Exercise 8.4: Linked List with Structs

Extend the linked list from Chapter 7 to store structs instead of ints.

```c
typedef struct {
    char name[50];
    int age;
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;
```

**Your task:** Create `exercises/ch08/ex04_person_list.c`

---

## Key Takeaways

1. **Structs group related data** — like Python classes without methods
2. **Use `typedef`** to avoid typing `struct` everywhere
3. **Dot `.`** for struct members, **arrow `->`** for pointer to struct
4. **Pass large structs by pointer** — avoids copying
5. **Methods are just functions** that take struct pointer as first argument
6. **Designated initializers** make initialization clearer
7. **Nested allocations need nested frees** — free inner before outer

## Next Chapter

Ready to work with files? Continue to [Chapter 9: File I/O](09-file-io.md).
