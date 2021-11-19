# Header files
set(HEADERS
    include/hash_table.h
)

# Source files
set(SOURCES 
    hash_table.c
)

# Create a public library for the implementation
add_library(hash_table ${HEADERS} ${SOURCES})

# add the include directory to the overall project for visibility
target_include_directories(hash_table PUBLIC
    include
)

# Specify installation instructions for the lib and header files
install(TARGETS hash_table DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/hash_table)