#include <stdio.h>

void remove_int(int arr[], int size, int target) {
    int i, j;

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            for (j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;  
            i--;      }
    }

    // print final array (optional)
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
