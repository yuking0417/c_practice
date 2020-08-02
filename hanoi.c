#include<stdio.h>

int count = 0;

void hanoi(int N, char *from, char *work, char *dest) {

    if(N >= 1) {
        hanoi(N-1, from, dest, work);
        count++;
        printf("%d:%dを%sから%sへ\n",count, N, from, dest);
    }
    if(N >= 1) {
        hanoi(N-1, work, from, dest);
    }

}

int main(void) {
    int N;
    scanf("%d", &N);
    hanoi(N, "A", "B", "C");
}