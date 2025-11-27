#include <stdio.h>

void f_tableau_multi(int n) {
    for (int i = 0; i <= 10; ++i) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}