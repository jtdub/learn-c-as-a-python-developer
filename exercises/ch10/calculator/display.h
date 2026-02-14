/*
 * display.h - Display/output functions header
 * Exercise 10.1: Multi-file Calculator
 */

#ifndef DISPLAY_H
#define DISPLAY_H

// Function declarations
void display_welcome(void);
void display_result(const char *operation, double a, double b, double result);
void display_error(const char *message);
void display_menu(void);

#endif /* DISPLAY_H */
