#include<stdio.h>

 void insertion_sort(int array[], int array_size) {  
    for(int i = 1; i < array_size; i++) {                
        int tmp = array[i];                          
        int ins = 0;
        for(int j = i -1; j >= 0; j--) {
            if(array[j] > tmp) {
                array[j+1] = array[j];
            } else {
                ins =  j + 1;
                break;
            }
        }
    array[ins] = tmp;
    }
}

int main(void) {
    int array[10] = {9, 5, 10, 8, 2 ,1, 4, 3, 6, 7};
    insertion_sort(array, 10);
    for(int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
}