#include<stdio.h>

int fibonacci(int f0, int f1, int N){
    if(N == 0) {
        return f0;
    }
    return fibonacci(f0 + f1, f0, N -1);
}

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d", fibonacci(0, 1, N));
}