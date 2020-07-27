#include<stdio.h>

void binary_search(int a[],int search_value, int *find_id) {
    *find_id = -1;
    int left = 0;
    int right = 4;
    while(left <= right) {
        int middle = (int)((left + right) / 2);
        if(a[middle] == search_value) {
            *find_id = middle;
            break;
        } else if(a[middle] < search_value) {
            left += middle;
        } else {
            right -= middle;
        }
    } 
}

int main(void) {
    int a[] = {1, 2, 4, 5, 10}; //昇順にソート
    int search_value = 4;
    int find_id;
    binary_search(a, search_value, &find_id);
    printf("%d", find_id);
}