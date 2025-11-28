#include <stdio.h>

void reverse_array(int arr[]) {
    printf("Array in reverse: ");
    for (int i = 4; i >= 0; i--) {  // Start from last element
        printf("%d ", arr[i]);
    }
    printf("\n");
}
