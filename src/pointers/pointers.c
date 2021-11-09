#include <stdlib.h>
#include <stdio.h>

int main(void) {

    // intialize array of 100 ints with all 0 values
    // automatic variable due to local declaration
    // requires explicit initialization
    int arr[100] = {0};

    // arrp1 is a pointer to the array element at index 40
    // arrp1 = address of arr[40]
    int *arrp1 = &arr[40];

    // arrp2 is a pointer to the array element at index 60
    // arrp2 = memory address offset by [20 * sizeof(int)] bytes from address of arr[40]
    // pointer arithmetic allows computing new addresses
    int *arrp2 = arrp1 + 20;

    printf("arr[40]: %d\n", arr[40]);
    printf("&arr[40]: %p\n", &arr[40]);
    printf("arrp1: %p\n", arrp1);
    printf("arrp2: %p\n", arrp2);

    // pointer arithmetic allows computing address "distances"
    // resulting value depends on the underlying memory types
    // pointer arithmetic on arrays is scaled to array element sizes
    // &arr[60] - &arr[40] = 20 
    // although the memory offset is 80 bytes [20 * (4bytes/int)]
    printf("arrp2-arrp1: %ld\n", arrp2-arrp1);

    return EXIT_SUCCESS;
}

