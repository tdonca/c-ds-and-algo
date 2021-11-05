#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define BUFFER_SIZE 128

int buffer[BUFFER_SIZE]; 

void write_head(int value) {
    // write to the next available index 
    // update the head pointer, handling wrap-around
}

int read_tail() {
    // update the tail pointer, handling wrap-around
    // return the data from the tail index
}

void clear_buffer() {
    // set all values in the buffer array to 0
    // reset the head and tail pointers
}

int main(void) {
    // add data to the buffer, past the wrap-around point
    for (int i = 0; i < BUFFER_SIZE + 50; i++) {
        write_head(i);
    }

    // verify the data was saved with wrap-around
    assert(buffer[0] == BUFFER_SIZE);
    assert(buffer[127] == BUFFER_SIZE - 1);

    return EXIT_SUCCESS;
}