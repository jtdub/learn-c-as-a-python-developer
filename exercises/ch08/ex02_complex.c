/*
 * Exercise 8.2: Complex Numbers
 *
 * Implement complex number arithmetic using structs.
 *
 * Python equivalent:
 *   c1 = complex(3, 4)
 *   c2 = complex(1, 2)
 *   print(c1 + c2)  # (4+6j)
 *
 * Complex number operations:
 *   (a + bi) + (c + di) = (a+c) + (b+d)i
 *   (a + bi) - (c + di) = (a-c) + (b-d)i
 *   (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
 *
 * Compile: cc -Wall -o ex02_complex ex02_complex.c -lm
 * Run: ./ex02_complex
 */

#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

// Function prototypes
Complex complex_create(double real, double imag);
Complex complex_add(Complex a, Complex b);
Complex complex_subtract(Complex a, Complex b);
Complex complex_multiply(Complex a, Complex b);
double complex_magnitude(Complex c);
void complex_print(Complex c);

int main(void) {
    Complex c1 = complex_create(3, 4);
    Complex c2 = complex_create(1, 2);

    printf("c1 = ");
    complex_print(c1);

    printf("c2 = ");
    complex_print(c2);

    printf("\nc1 + c2 = ");
    complex_print(complex_add(c1, c2));

    printf("c1 - c2 = ");
    complex_print(complex_subtract(c1, c2));

    printf("c1 * c2 = ");
    complex_print(complex_multiply(c1, c2));

    printf("\n|c1| = %.2f\n", complex_magnitude(c1));
    printf("|c2| = %.2f\n", complex_magnitude(c2));

    return 0;
}

// TODO: Implement these functions

Complex complex_create(double real, double imag) {
    Complex c;
    // Set c.real and c.imag
    return c;
}

Complex complex_add(Complex a, Complex b) {
    // Return (a.real + b.real) + (a.imag + b.imag)i
    Complex result = {0, 0};
    return result;
}

Complex complex_subtract(Complex a, Complex b) {
    Complex result = {0, 0};
    return result;
}

Complex complex_multiply(Complex a, Complex b) {
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    Complex result = {0, 0};
    return result;
}

double complex_magnitude(Complex c) {
    // |c| = sqrt(real^2 + imag^2)
    return 0.0;
}

void complex_print(Complex c) {
    // Print in format: "3.00 + 4.00i" or "3.00 - 4.00i"
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}
