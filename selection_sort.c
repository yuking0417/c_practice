#include<stdio.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selection_sort(int array[], int array_size) {
    for(int i = 0; i < array_size - 1; i++) {
        int k = i;
        int min = array[i];
        for(int j = i + 1; j < array_size - 1; j++) {
            if(min > array[j]) {
                k = j;
                min = array[j];
            }
            swap(&array[i], &min);
        } 
    }
}

int main(void) {
    int array[10] = {1, 3, 4, 2, 9, 5 ,6, 8, 7, 10};   
    selection_sort(array, 10);
    for(int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
}