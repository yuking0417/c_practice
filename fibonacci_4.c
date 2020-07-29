#include<stdio.h>
#include<math.h>
int main(void) {
    int f,N;
    scanf("%d", &N);
    f = (int)((pow((1+sqrt(5))/2, N) - pow((1-sqrt(5))/2, N)) / sqrt(5));
    printf("%d",f);
}