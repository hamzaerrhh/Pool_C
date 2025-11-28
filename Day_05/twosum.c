#include <stdio.h>

void two_sum(int arr[], int size, int target) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("[%d, %d]\n", i + 1, j + 1); // 1-based indices
                return;
            }
        }
    }
    printf("No pair found.\n");
}
