#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "history.h"

int main() {
    init_history();
    
    printf("Welcome to the CLI Calculator!\n");
    printf("Type '0' to exit at any time.\n");
    
    int running = 1;
    
    while (running) {
        display_menu();
        
        printf("\nEnter your choice (0-9): ");
        int choice;
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 0 and 9.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
        
        switch (choice) {
            case 0: // Exit
                running = 0;
                printf("Thank you for using the CLI Calculator. Goodbye!\n");
                break;
                
            case 1: { // Addition
                printf("\n--- Addition ---\n");
                double a = get_number("Enter first number: ");
                double b = get_number("Enter second number: ");
                double result = add(a, b);
                printf("Result: %.2lf + %.2lf = %.2lf\n", a, b, result);
                break;
            }
                
            case 2: { // Subtraction
                printf("\n--- Subtraction ---\n");
                double a = get_number("Enter first number: ");
                double b = get_number("Enter second number: ");
                double result = subtract(a, b);
                printf("Result: %.2lf - %.2lf = %.2lf\n", a, b, result);
                break;
            }
                
            case 3: { // Multiplication
                printf("\n--- Multiplication ---\n");
                double a = get_number("Enter first number: ");
                double b = get_number("Enter second number: ");
                double result = multiply(a, b);
                printf("Result: %.2lf * %.2lf = %.2lf\n", a, b, result);
                break;
            }
                
            case 4: { // Division
                printf("\n--- Division ---\n");
                double a = get_number("Enter numerator: ");
                double b = get_number("Enter denominator: ");
                double result = divide(a, b);
                if (b != 0) {
                    printf("Result: %.2lf / %.2lf = %.2lf\n", a, b, result);
                }
                break;
            }
                
            case 5: { // Factorial
                printf("\n--- Factorial ---\n");
                int n = get_integer("Enter a non-negative integer: ");
                long long result = factorial(n);
                if (result != -1) {
                    printf("Result: fact(%d) = %lld\n", n, result);
                }
                break;
            }
                
            case 6: { // Square Root
                printf("\n--- Square Root ---\n");
                double x = get_number("Enter a non-negative number: ");
                double result = square_root(x);
                if (result != -1) {
                    printf("Result: sqrt(%.2lf) = %.2lf\n", x, result);
                }
                break;
            }
                
            case 7: { // Power of 2
                printf("\n--- Power of 2 ---\n");
                double x = get_number("Enter a number: ");
                double result = power_2(x);
                printf("Result: pwr2(%.2lf) = %.2lf\n", x, result);
                break;
            }
                
            case 8: { // Power of 3
                printf("\n--- Power of 3 ---\n");
                double x = get_number("Enter a number: ");
                double result = power_3(x);
                printf("Result: pwr3(%.2lf) = %.2lf\n", x, result);
                break;
            }
                
            case 9: // Show History
                show_history();
                break;
                
            default:
                printf("Invalid choice! Please enter a number between 0 and 9.\n");
                break;
        }
    }
    
    free_history();
    return 0;
}