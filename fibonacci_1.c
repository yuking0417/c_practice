#include<stdio.h>
int main(void) {

    int f0,f1,f2,N;
    f0 = 0;
    f1 = 1;
    scanf("%d", &N);

    for(int i = 0; i < N - 2; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }

    if(N == 1) {
        printf("%d\n", f0);
    } else if(N == 2) {
        printf("%d\n", f1);
    } else {
        printf("%d\n", f2);
    }
}