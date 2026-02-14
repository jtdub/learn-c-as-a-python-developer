/*
 * Exercise 2.2: Temperature Converter
 *
 * Convert Celsius to Fahrenheit using proper types.
 * Formula: F = C * 9/5 + 32
 *
 * Python version:
 *   def celsius_to_fahrenheit(celsius):
 *       return celsius * 9/5 + 32
 *
 *   temp_c = 100.0
 *   temp_f = celsius_to_fahrenheit(temp_c)
 *   print(f"{temp_c}°C = {temp_f}°F")
 *
 * Expected output (for sample values):
 *   0.00°C = 32.00°F
 *   100.00°C = 212.00°F
 *   -40.00°C = -40.00°F
 *
 * Compile: cc -Wall -o ex02_temperature ex02_temperature.c
 * Run: ./ex02_temperature
 */

#include <stdio.h>

// TODO: Implement the conversion function
// double celsius_to_fahrenheit(double celsius)

int main(void) {
    // Test values
    double test_temps[] = {0.0, 100.0, -40.0, 37.0, 20.0};
    int num_temps = sizeof(test_temps) / sizeof(test_temps[0]);

    printf("Celsius to Fahrenheit Conversion\n");
    printf("================================\n");

    // TODO: Loop through test_temps and print conversions
    // Use %.2f for 2 decimal places

    return 0;
}
