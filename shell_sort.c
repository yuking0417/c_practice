#include<stdio.h>

void shell_sort(int array[], int array_size) {
    int step,i,j;
    for(step = array_size / 2; step > 0; step /= 2) {
        for(i = step; i < array_size; i++) {
            int tmp = array[i];
            int j = i;
            for(j = i; j >= step; j -= step) {
                if(array[j-step] > tmp) {
                    array[j] = array[j-step];
                } else {
                    break;
                }
            }
            array[j] = tmp;
        }
    }
}

int main(void) {
    int array[] = {10, 3, 1, 9, 7, 6, 8, 2, 4, 5};
    shell_sort(array, 10);
    for(int i = 0; i < 10; i++) {
        printf("%d", array[i]);
    }
}