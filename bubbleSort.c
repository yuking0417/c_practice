#include <stdio.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(int array[], int array_size) {
    for (int i = 0; i < array_size - 1; i++) {
        for (int j = array_size - 1; j > i; i--) {
            if (array[j] < array[j-1]) {
                swap(&array[j], &array[j-1]);
            }
        }
    }
}

int main(void) {
    int array[] = {9,5,1,10,23};
    int array_size = sizeof(array) / sizeof(int);
    
    bubble_sort(array, array_size);

    for (int i = 0; i < array_size; i++) {
        printf("%d", array[i]);
    }

}