#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    srand((unsigned int)time(NULL));
    int omikuji = rand() % 6 + 1;

    if (omikuji <= 2) {
        printf("大吉\n");
    } else if (omikuji <=5) {
        printf("吉\n");
    } else {
        printf("凶");
    }
    
    return 0;
}