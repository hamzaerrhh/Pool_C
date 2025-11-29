#ifndef CALCULATOR_H
#define CALCULATOR_H

// Basic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Advanced operations
long long factorial(int n);
double square_root(double x);
double power_2(double x);
double power_3(double x);

// Utility functions
void display_menu();
double get_number(const char* prompt);
int get_integer(const char* prompt);
void clear_input_buffer();

#endif