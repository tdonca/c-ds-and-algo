#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

int main(void) {
    unsigned int ui = UINT_MAX;
    ui++;
    assert(ui == 0);
    ui--;
    assert(ui = UINT_MAX);

    // infinite loop
    // for (unsigned int i = 10; i >= 0; i--) {
    //     ;
    // }

    // incorrect unsigned comparison due to wraparound
    // unsigned int sum = 10;
    // if (sum + ui > UINT_MAX) {
    //     printf("Too big");
    // } else {
    //     sum += ui;
    // }

    // correct unsigned comparison ensuring arithmetic operations remain within bounds
    unsigned int sum = 10;
    if (sum > UINT_MAX - ui) {
        printf("Too big\n");
    } else {
        sum += ui;
    }

    // floating point values
    float value = 0.1F;
    printf("%f\n", value);

    return EXIT_SUCCESS;
}

