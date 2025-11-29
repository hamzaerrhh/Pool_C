#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculator.h"
#include "history.h"

double add(double a, double b) {
    double result = a + b;
    char operation[50];
    snprintf(operation, sizeof(operation), "%.2lf + %.2lf = %.2lf", a, b, result);
    add_to_history(operation);
    return result;
}

double subtract(double a, double b) {
    double result = a - b;
    char operation[50];
    snprintf(operation, sizeof(operation), "%.2lf - %.2lf = %.2lf", a, b, result);
    add_to_history(operation);
    return result;
}

double multiply(double a, double b) {
    double result = a * b;
    char operation[50];
    snprintf(operation, sizeof(operation), "%.2lf * %.2lf = %.2lf", a, b, result);
    add_to_history(operation);
    return result;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero!\n");
        return 0;
    }
    double result = a / b;
    char operation[50];
    snprintf(operation, sizeof(operation), "%.2lf / %.2lf = %.2lf", a, b, result);
    add_to_history(operation);
    return result;
}

long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers!\n");
        return -1;
    }
    if (n > 20) { // Prevent overflow
        printf("Error: Number too large for factorial calculation!\n");
        return -1;
    }
    
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    char operation[50];
    snprintf(operation, sizeof(operation), "fact(%d) = %lld", n, result);
    add_to_history(operation);
    return result;
}

double square_root(double x) {
    if (x < 0) {
        printf("Error: Cannot calculate square root of negative number!\n");
        return -1;
    }
    double result = sqrt(x);
    char operation[50];
    snprintf(operation, sizeof(operation), "sqrt(%.2lf) = %.2lf", x, result);
    add_to_history(operation);
    return result;
}

double power_2(double x) {
    double result = x * x;
    char operation[50];
    snprintf(operation, sizeof(operation), "pwr2(%.2lf) = %.2lf", x, result);
    add_to_history(operation);
    return result;
}

double power_3(double x) {
    double result = x * x * x;
    char operation[50];
    snprintf(operation, sizeof(operation), "pwr3(%.2lf) = %.2lf", x, result);
    add_to_history(operation);
    return result;
}

void display_menu() {
    printf("\n==================================================\n");
    printf("               CLI CALCULATOR\n");
    printf("==================================================\n");
    printf("Basic Operations:\n");
    printf("  1. Addition (+)\n");
    printf("  2. Subtraction (-)\n");
    printf("  3. Multiplication (*)\n");
    printf("  4. Division (/)\n");
    printf("\nAdvanced Operations:\n");
    printf("  5. Factorial (fact)\n");
    printf("  6. Square Root (sqrt)\n");
    printf("  7. Power of 2 (pwr2)\n");
    printf("  8. Power of 3 (pwr3)\n");
    printf("\nOther Commands:\n");
    printf("  9. Show History\n");
    printf("  0. Exit\n");
    printf("==================================================\n");
}

double get_number(const char* prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1) {
        printf("Invalid input. Please enter a number: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

int get_integer(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}