#include <stdio.h>
#include <limits.h>  

int factorial(int nb) {
    if (nb < 0) {
        return -1;  
    }
    if (nb == 0 || nb == 1) {
        return 1;  
    }

    
    if (nb > INT_MAX / factorial(nb - 1)) {
        return -2;  /
    }

    return nb * factorial(nb - 1);
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int result = factorial(n);

    if (result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (result == -2) {
        printf("Overflow detected! Factorial is too large for int.\n");
    } else {
        printf("Factorial of %d is %d\n", n, result);
    }

    return 0;
}
