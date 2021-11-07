#include <stdio.h>
#include <stdlib.h>

// file scope variable exists for the entire execution of the program
static unsigned int counter = 0;

void increment(void) {
    counter++;
    printf("Increment: %d\n", counter);
}

int retrieve(void) {
    return counter;
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        increment();
        printf("Retrieve: %d\n", retrieve());
    }

    return EXIT_SUCCESS;
}