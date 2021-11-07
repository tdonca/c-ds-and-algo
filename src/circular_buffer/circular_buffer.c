#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// TODO: remove explicit path dependency when switching to CMake
#include "include/circular_buffer.h"

static int buffer[BUFFER_SIZE]; 
static bool is_full;
static int active_size;
static int head;
static int tail;

static void MoveTail(void) {
    // only move the tail index when the buffer is not empty
    if (tail != head || is_full) {
        tail++;
    }
}

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
    MoveTail();

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
    printf("Buffer[0]: %d\n", buffer[0]);
    assert(buffer[127] == BUFFER_SIZE - 1);
    printf("Buffer[127]: %d\n", buffer[127]);
    assert(IsEmpty() == false);
    assert(is_full == true);
    int tailElem = ReadTail(); 
    printf("Read tail: %d\n", tailElem);
    assert(tailElem == 50);
    assert(is_full == false);


    return EXIT_SUCCESS;
}