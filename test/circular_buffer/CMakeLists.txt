cmake_minimum_required(VERSION 3.5)

project(circular_buffer_tests)

# Unity is a library that we have to include
# Unity has some sources we need to add to the executable

# src/circular_buffer is a library?, whatever it is, we need to include it
# src/circular_buffer/include is an "include directory" that has some header files we need
# src/circular_buffer has some source files we need to add to the executable

# List all the .c source files that need to be compiled for the test suite to run
set(CIRC_BUF_SOURCES
    test_circular_buffer.c
    ../../src/circular_buffer/circular_buffer.c
    ../../../Unity/src/unity.c   
)

# Create an executable target for make based on all the source files
add_executable(circular_buffer_basic_test ${CIRC_BUF_SOURCES})

# specify the directories where to look for all the included header files 
target_include_directories(circular_buffer_basic_test PRIVATE 
    ../../src/circular_buffer 
    ../../src/circular_buffer/include 
    ../../../Unity/src
)

# TODO: clean this up to not have to use relative paths for every single source file and header
# TODO: investigate library concept for adding the non-test files (unity files, circbuf files)