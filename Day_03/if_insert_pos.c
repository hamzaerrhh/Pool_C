#include <stdio.h>

int if_insert_pos(int arr[], int size, int n) {
    for (int i = 0; i < size; i++) {
        if (n <= arr[i]) {
            return i;   
        }
    }
    return size;         
}

