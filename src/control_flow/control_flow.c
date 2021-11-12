#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int absolute_value(int a) {
    // INT_MIN cannot be negated without signed overflow
    assert(a != INT_MIN);
    if (a < 0) {
        return -a;
    }
    return a;
}

size_t find_element(size_t len, int* arr, int key) {
    size_t pos = -1;

    for (size_t i = 0; i < len; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }

    return pos;
}

int main(void) {
    size_t length = 8;
    int arr[] = {7, 12, -2, 999, 0, 13, 4, 99};
    printf("Array: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Position of 12: %ld\n", find_element(length, arr, 12));
    printf("Position of 80: %ld\n", find_element(length, arr, 80));

    printf("Absolute value of -10: %d\n", absolute_value(-10));
    printf("Absolute value of INT_MIN: %d\n", absolute_value(INT_MIN));
}