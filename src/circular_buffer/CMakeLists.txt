# Header files
set(HEADERS
    include/circular_buffer.h
)

# Source files
set(SOURCES 
    circular_buffer.c
)

# Create a public library for the implementation
add_library(circular_buffer ${HEADERS} ${SOURCES})

# add the include directory to the overall project for visibility
target_include_directories(circular_buffer PUBLIC
    include
)

# Specify installation instructions for the lib and header files
install(TARGETS circular_buffer DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/circular_buffer)