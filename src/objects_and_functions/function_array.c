#include <stdlib.h>
#include <stdio.h>

// pFunc is an alias for a function pointer 
// that takes an integer parameter 
// and has void return type
typedef void (*pFunc)(int);

// execute one of the functions in the function pointer array
void execute_func(pFunc *func_array, size_t size, int execute_num, int func_param) {
    // check for index bounds before attempting array access
    if (execute_num >= 0 && execute_num < size) {
        // select the function pointer in the array at index 'execute_num'
        // dereference the function pointer to call the actual function
        // pass 'func_param' as the function parameter
        (*func_array[execute_num])(func_param);
    } else {
        printf("Error, invalid function number\n");
    }
}

void function1(int input) {
    printf("Called function 1 with input: %d\n", input);
}

void function2(int input) {
    printf("Called function 2 with input: %d\n", input);
}

void function3(int input) {
    printf("Called function 3 with input: %d\n", input);
}

int main(void) {
    int num_funcs = 3;

    // create an array of function pointers of length 'num_funcs'
    pFunc func_array[num_funcs];
    func_array[0] = &function1;
    func_array[1] = &function2;
    func_array[2] = &function3;
    
    // execute the function at index 0 in the array
    execute_func(func_array, num_funcs, 0, 77);

    // execute the function at index 1 in the array
    execute_func(func_array, num_funcs, 1, 88);

    // execute the function at index 2 in the array
    execute_func(func_array, num_funcs, 2, 99);

    // try to execute a function at index 3 (out-of-bounds)
    execute_func(func_array, num_funcs, 3, 100);

    return EXIT_SUCCESS;
}