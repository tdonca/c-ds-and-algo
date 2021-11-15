#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Compile, link with the malloc library, and create a macro flag
// $> gcc -DDMALLOC caesar.c -ocaesar -ldmalloc
#ifdef DMALLOC
#include "dmalloc.h"
#endif

// Error - causes double-free error
void usage(char* msg) {
    fprintf(stderr, "%s", msg);
    free(msg);
    return;
}

int main(int argc, char* argv[]) {
    if (argc != 3 && argc != 4) {

        char* errmsg = (char*)malloc(80);
        // Error - could overwrite past the 80 char limit if the USER env var is too long
        sprintf(errmsg, 
                "Sorry %s,\n Usage:caesar secret_file keys_file [output_file]\n",
                getenv("USER"));
        usage(errmsg);
        free(errmsg);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}