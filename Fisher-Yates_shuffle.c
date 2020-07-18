#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y) {

    int tmp = *x;
    *x = *y;
    *y = tmp;

}

int main(void) {

    int array[5] = {1, 2, 3, 4, 5};
    srand((unsigned int)time(NULL));
    for(int i = 4; i > 0; i--) {
        int r = rand() % i;
        swap(&array[i], &array[r]); 
    }
    for(int i = 0; i < 5; i++) {
        printf("%d ",array[i]);
    }

}