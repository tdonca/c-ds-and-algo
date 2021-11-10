
// TODO: switch to CMake and clean this up
#include "unity.h"
#include "circular_buffer.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_circbuf_init(void) {
    // test the initialization logic
}

void test_circbuf_basic_operations(void) {
    int arr[128] = {0};
    circbuf_handle_t circbuf = circbuf_init(arr, 128);

    TEST_ASSERT(circbuf_is_empty(circbuf));
    TEST_ASSERT(circbuf_size(circbuf) == 0);

    circbuf_write_head(circbuf, 10);
    circbuf_write_head(circbuf, 20);

    TEST_ASSERT(circbuf_size(circbuf) == 2);
    TEST_ASSERT(!circbuf_is_empty(circbuf));
    TEST_ASSERT(!circbuf_is_full(circbuf));

    int first = circbuf_read_tail(circbuf);
    int second = circbuf_read_tail(circbuf);

    TEST_ASSERT(first == 10);
    TEST_ASSERT(second == 20);
    TEST_ASSERT(circbuf_is_empty(circbuf));

    circbuf_free(circbuf);
}

//TODO: add more tests

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_circbuf_basic_operations);
    // TODO: add more RUN_TEST() invocations
    
    return UNITY_END();
}