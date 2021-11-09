#include <stdlib.h>
#include <assert.h>
#include "include/circular_buffer.h"

#define BUFFER_SIZE 128

// Simple test runner for the circular buffer implementation
// TODO: replace with unit test framework
int main(void) {
    int arr[BUFFER_SIZE] = {0};
    circbuf_handle_t circbuf = circbuf_init(arr, BUFFER_SIZE);

    assert(circbuf_is_empty(circbuf));
    assert(circbuf_size(circbuf) == 0);

    circbuf_write_head(circbuf, 10);
    circbuf_write_head(circbuf, 20);

    assert(circbuf_size(circbuf) == 2);
    assert(!circbuf_is_empty(circbuf));
    assert(!circbuf_is_full(circbuf));

    int first = circbuf_read_tail(circbuf);
    int second = circbuf_read_tail(circbuf);

    assert(first == 10);
    assert(second == 20);
    assert(circbuf_is_empty(circbuf));

    circbuf_free(circbuf);

    return EXIT_SUCCESS;
}
