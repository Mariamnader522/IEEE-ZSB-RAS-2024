#include <stdio.h>

#define debug 1 // define the macro 'debug' with a value of 1

int main() {
    #if debug
        printf("debug mode is enabled.\n"); // it will be included during compilation because 'debug' is defined and non-zero
    #else
        printf("debug mode is disabled.\n"); // it will be excluded during compilation because 'debug' is defined and non-zero
    #endif

    if (debug) {
        printf("debug mode is enabled.\n"); // it will be executed at runtime because 'debug' is non-zero
    } else {
        printf("debug mode is disabled.\n"); // it will not be executed because 'debug' is non-zero
    }

    return 0;
}