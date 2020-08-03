#include<stdio.h>

#define N 10
typedef char* data_t;

data_t stack[N];
int size;

void init(void) {
    size = 0;
}

int push(data_t x) {

    if(size == 0) {
        return 1;
    }

    stack[size] = x;
    size++;
    return 0;
}

int pop(data_t *x) {

    if(size <= 0) {
        return 1;
    }

    *x = stack[size - 1];
    size--;
    return 0;
}

int main(void) {

    init();

    char subject1[] = "math";
    char subject2[] = "Japanese";
    char subject3[] = "social";
    char subject4[] = "science";  

    push(subject1);
    push(subject2);
    push(subject3);
    push(subject4);

    char *p;
    while(pop(&p) == 0) {
        printf("%s", p);
    }
}