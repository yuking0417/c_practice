#include <stdio.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quick_sort(int *array, int startID, int endID) {
    int pivot = array[(int)((startID + endID) / 2)];
    int left = startID;
    int right = endID;

    while (1) {
        while (array[left] < pivot) {
            left++;
        }
        while (pivot < array[right]) {
            right--;
        }
        if (right <= left) {
            break;
        }
        swap(&array[left], &array[right]);
        left++;
        right--;
    }

    if (startID < left - 1) {
        quick_sort(array, startID, left - 1);
    }
    if (right + 1 < endID) {
        quick_sort(array, right + 1, endID);
    }   
}

int main (void) {
    int array[] = {10, 3, 1, 9, 7, 6, 8, 2, 4, 5};
    quick_sort(array, 0, 10 - 1);
    for (int i = 0; i < 10; i++) {
        printf("%d", array[i]);
    }
    return 0;
}