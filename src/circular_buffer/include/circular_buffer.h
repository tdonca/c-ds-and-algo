#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>

//TODO: Add API descriptions

// Struct type definition, later defined in the implementation file
typedef struct circular_buffer_t circular_buffer_t;

// Handler to create abstraction
typedef circular_buffer_t* circbuf_handle_t;

// Input is a caller-provided underying array and associated size
// Dynamically allocates a circular buffer instance
circbuf_handle_t circbuf_init(int* buffer, size_t size);

// Clears all data in the buffer
void circbuf_reset(circbuf_handle_t circbuf);

// Frees the dynamically allocated circular buffer instance
// The caller is still responsible to free the provided underlying array
void circbuf_free(circbuf_handle_t circbuf);

// APIs assume the input circbuf is already initialized

// Full status API
bool circbuf_is_full(circbuf_handle_t circbuf);

// Empty status API
bool circbuf_is_empty(circbuf_handle_t circbuf);

// Get current size API
size_t circbuf_size(circbuf_handle_t circbuf);

// Get max capacity API
size_t circbuf_capacity(circbuf_handle_t circbuf);

// Write API
void circbuf_write_head(circbuf_handle_t circbuf, int value);

// Read API
int circbuf_read_tail(circbuf_handle_t circbuf);

#endif // CIRCULAR_BUFFER_H_