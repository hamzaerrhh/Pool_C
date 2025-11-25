#include <stdio.h>

int sqrt_x(int nb) {
    if (nb < 0) {
        return -1; // Not defined for negative numbers
    }

    int i = 0;
    while (i * i <= nb) {
        i++;
    }

    return i - 1; // Rounded down
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int result = sqrt_x(n);

    if (result == -1) {
        printf("Square root is not defined for negative numbers.\n");
    } else {
        printf("Square root of %d rounded down is %d\n", n, result);
    }

    return 0;
}
