# List all the source files that make up the test suite
set(CIRC_BUF_SOURCES
    test_circular_buffer.c  
)

# Create an executable target based on all the source files
add_executable(circular_buffer_basic_test ${CIRC_BUF_SOURCES})

# Link the unit test framework and the circbuf implementation as libraries
target_link_libraries(circular_buffer_basic_test
    unity
    circular_buffer
)

install(TARGETS circular_buffer_basic_test DESTINATION bin/tests)