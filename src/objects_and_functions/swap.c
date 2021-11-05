#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

void swap(int* pA, int* pB) {
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}

int main(void) {
    int a = 21;
    int b = 17;

    swap(&a, &b);
    printf("main: a = %d, b = %d\n", a, b);
    
    return EXIT_SUCCESS;
}