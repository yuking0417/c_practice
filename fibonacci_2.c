#include<stdio.h>

int fibonacci(int N) {
    if(N == 1) {
        return 0;
    }
    if(N == 2) {
        return 1;
    }
    return fibonacci(N - 1) + fibonacci(N - 2);
}

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d", fibonacci(N));
}