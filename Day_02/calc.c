#include <stdio.h>
#include <limits.h>   // INT_MAX, INT_MIN

void calc(void) {
    char op;
    float a, b, result;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter first number: ");
    scanf("%f", &a);

    printf("Enter second number: ");
    scanf("%f", &b);

    // ---- CHECK IF INPUT OUTSIDE INT RANGE ----
    if (a > INT_MAX || a < INT_MIN || b > INT_MAX || b < INT_MIN) {
        printf("I'm sorry, there is overflow in your logic.\n");
        printf("One of the numbers is above MAX_INT (%d) or below MIN_INT (%d).\n",
               INT_MAX, INT_MIN);
        return;
    }

    // ---- CHECK FOR OVERFLOW BEFORE CALCULATION ----
    if (op == '+') {
        if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
            printf("Overflow detected: addition exceeds int range!\n");
            return;
        }
        result = a + b;
    }
    else if (op == '-') {
        if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b)) {
            printf("Overflow detected: subtraction exceeds int range!\n");
            return;
        }
        result = a - b;
    }
    else if (op == '*') {
        if (a != 0 && b != 0) {
            if ((a > 0 && b > 0 && a > INT_MAX / b) ||
                (a > 0 && b < 0 && b < INT_MIN / a) ||
                (a < 0 && b > 0 && a < INT_MIN / b) ||
                (a < 0 && b < 0 && a < INT_MAX / b)) {
                printf("Overflow detected: multiplication exceeds int range!\n");
                return;
            }
        }
        result = a * b;
    }
    else if (op == '/') {
        if (b == 0) {
            printf("Error: Cannot divide by zero!\n");
            return;
        }
        if (a == INT_MIN && b == -1) {
            printf("Overflow detected: INT_MIN / -1 exceeds int range!\n");
            return;
        }
        result = a / b;
    }
    else {
        printf("Invalid operation!\n");
        return;
    }

    printf("Result: %.6f\n", result);
}

