#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// TODO: Remove explicit path dependency when switching to CMake
#include "include/circular_buffer.h"

// TODO: Should this be static?
struct circular_buffer_t {
    int* buffer; // underlying array, provided by the user during init
    size_t max; // size of underlying array
    size_t head; // size type for array index of latest buffer element
    size_t tail; // size type for array index of earliest buffer element
    bool is_full;
};

//TODO: Add description
static void move_head(circbuf_handle_t circbuf);

// TODO: Add description
static void move_tail(circbuf_handle_t circbuf);

/*-----------------------------------------------*/

static void move_head(circbuf_handle_t circbuf) {
    // Also move the tail up if the buffer is full 
    if (circbuf->is_full) {
        move_tail(circbuf);
    }

    circbuf->head++;

    // Handle array wrap-around
    if (circbuf->head == circbuf->max) {
        circbuf->head = 0;
    }
}

static void move_tail(circbuf_handle_t circbuf) {
    circbuf->tail++;

    // Handle array wrap-around
    if (circbuf->tail == circbuf->max) {
        circbuf->tail = 0;
    }
}

/*-----------------------------------------------*/

circbuf_handle_t circbuf_init(int* buffer, size_t size) {
    assert(buffer != NULL);
    assert(size > 0);

    // Dynamically allocate an instance of the circular buffer struct
    circbuf_handle_t handle = malloc(sizeof(circular_buffer_t));
    assert(handle != NULL);

    handle->buffer = buffer;
    handle->max = size;
    circbuf_reset(handle);
    assert(circbuf_is_empty(handle));

    return handle; 
}

void circbuf_reset(circbuf_handle_t circbuf) {
    assert(circbuf != NULL);

    // Clear the provided buffer array
    memset(circbuf->buffer, 0, circbuf->max);

    // Reset the head and tail pointers
    circbuf->head = 0;
    circbuf->tail = 0;
    circbuf->is_full = false;
}

void circbuf_free(circbuf_handle_t circbuf) {
    assert(circbuf != NULL);
    free(circbuf);
}

bool circbuf_is_full(circbuf_handle_t circbuf) {
    assert(circbuf != NULL);
    return circbuf->is_full;
}

bool circbuf_is_empty(circbuf_handle_t circbuf) {
    assert(circbuf != NULL);
    return (circbuf->tail == circbuf->head) && !circbuf->is_full;
}

size_t circbuf_size(circbuf_handle_t circbuf) {
    assert(circbuf != NULL);
    int size = 0;

    // The size of a full buffer is the max capacity
    if (circbuf->is_full) {
        size = circbuf->max;

    // If both head and tail point to the same index and the buffer isn't full
    // Then the buffer is empty
    } else if (circbuf->tail == circbuf->head) {
        size = 0;

    // Compute the size based on the head and tail, handling wrap-around
    } else {

        // No wrap-around
        if (circbuf->tail < circbuf->head) {
            size = circbuf->head - circbuf->tail; 
        
        // Handle wrap-around
        } else {
            size = (circbuf->max - circbuf->tail) + circbuf->head;
        }
    }

    return size;
}

size_t circbuf_capacity(circbuf_handle_t circbuf) {
    assert(circbuf != NULL);
    return circbuf->max;
}

void circbuf_write_head(circbuf_handle_t circbuf, int value) {
    assert(circbuf != NULL);
    
    // Write the value
    circbuf->buffer[circbuf->head] = value;
    
    // Update the head and tail
    // Overwrite the tail element if the buffer was full
    move_head(circbuf);
    
    // Update full status
    // The buffer is now necessarily not empty, but it could have just become full
    if (circbuf->head == circbuf->tail) {
        circbuf->is_full = true;
    }
}

int circbuf_read_tail(circbuf_handle_t circbuf) {
    assert(circbuf != NULL);
    assert(!circbuf_is_empty(circbuf));

    // Read the value
    int value = circbuf->buffer[circbuf->tail];

    // Update the pointers
    move_tail(circbuf);

    // Update full status
    // The buffer is now necessarily not full, since we just decreased it by one element
    circbuf->is_full = false;

    return value;
}
