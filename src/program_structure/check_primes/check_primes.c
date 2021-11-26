#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#include "isprime.h"

#define PRIMETEST_NUM_ITERATIONS 100

#define BASE_TEN 10

static void print_help(void) {
    printf("%s\n\n", "primetest num1 [num2 num3 ... numN]");
    printf("%s", "Tests positive integers for primality. Supports testing ");
    printf("%s [2-%llu]. \n", "numbers in the range", ULLONG_MAX);
}

static bool convert_arg(const char *arg, unsigned long long *num) {
    char *endptr;
    errno = 0;

    // https://linux.die.net/man/3/strtoull
    *num = strtoull(arg, &endptr, BASE_TEN);
    
    if (((*num == ULLONG_MAX || *num == 0) && errno != 0)
            || endptr == arg) {
        return false;
    }

    return (*num > 1);
}

static unsigned long long *convert_command_line_args(int argc, 
        const char *argv[], size_t *num_converted) {
    
    *num_converted = 0;

    if (argc <= 1) {
        print_help();
        return NULL;
    }

    unsigned long long *converted_nums = malloc((argc-1) * sizeof(unsigned long long));
    bool conversion_success = (converted_nums != NULL);

    for (int i = 1; i < argc && conversion_success; i++) {
        unsigned long long num;
        conversion_success = convert_arg(argv[i], &num);
        converted_nums[i-1] = num;
    }

    if (!conversion_success) {
        free(converted_nums);
        print_help();
        return NULL;
    }

    *num_converted = argc - 1;
    return converted_nums;
}

int main (int argc, const char *argv[]) {
    size_t num_args;
    unsigned long long *vals = convert_command_line_args(argc, argv, &num_args);

    if (vals == NULL) {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < num_args; i++) {
        bool primetest = is_prime(vals[i], PRIMETEST_NUM_ITERATIONS);
        printf("%llu is %s. \n", 
                vals[i], 
                primetest ? "probably prime" : "not prime");
    }

    free(vals);
    return EXIT_SUCCESS;
}