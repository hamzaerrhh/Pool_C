#include <stdio.h>

int min_max(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("Max = %d\n", max);  // printed, not returned
    return min;                 // only one value can be returned
}

