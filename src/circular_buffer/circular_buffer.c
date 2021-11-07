#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include <"circular_buffer.h">

// TODO: where to update active_size?
// TODO: where to update is_full?

static int buffer[BUFFER_SIZE]; 
static bool is_full;
static int active_size;
static int head;
static int tail;

static void MoveHead(void) {
    // adjust the tail index when overwriting in a full buffer
    // the oldest value in the buffer is lost
    if (is_full) {
        MoveTail();
    }

    // handle wrap-around
    head++;
    if (head == BUFFER_SIZE) {
        head = 0;
    }
}

static void MoveTail(void) {
    // only move the tail index when the buffer is not empty
    if (tail != head || is_full) {
        tail++;
    }
}

void WriteHead(int value) {
    // write to the next available index 
    // update the head pointer, handling wrap-around
    buffer[head] = value;
    MoveHead();

    if (!is_full) {
        active_size++;
        is_full = (active_size == BUFFER_SIZE);
    }
}

int ReadTail(void) {
    // update the tail pointer, handling wrap-around
    // return the data from the tail index
    int value = buffer[tail];
    MoveIndex(tail);

    //TODO: how to handle someone calling read() on empty buffer?
    active_size--;
    is_full = (active_size == BUFFER_SIZE);

    return value;
}

bool IsEmpty() {
    return (head == tail && !is_full);
}

void ClearBuffer(void) {
    // set all values in the buffer array to 0
    // reset the head and tail pointers
    head = 0;
    tail = 0;
    is_full = false;
    active_size = 0;
    memset(buffer, 0, sizeof(buffer));
}

int main(void) {
    // add data to the buffer, past the wrap-around point
    for (int i = 0; i < BUFFER_SIZE + 50; i++) {
        WriteHead(i);
    }

    // verify the data was saved with wrap-around
    assert(buffer[0] == BUFFER_SIZE);
    assert(buffer[127] == BUFFER_SIZE - 1);

    return EXIT_SUCCESS;
}