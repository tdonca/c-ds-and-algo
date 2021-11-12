# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

project(c_data_structures_and_algorithms)

# Implementations
add_subdirectory(src/circular_buffer)

# Test Framework
add_subdirectory(test/Unity)

# Tests
add_subdirectory(test/circular_buffer)
