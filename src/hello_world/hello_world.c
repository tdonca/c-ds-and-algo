#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (puts("Hello, world") == EOF) {
        return EXIT_FAILURE;
    }

    printf("%s\n", "Hello, world formatted");
    
    return EXIT_SUCCESS;
}