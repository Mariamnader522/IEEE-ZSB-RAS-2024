#include <stdio.h>
//with macros
/* #define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))

int main() {
    int x;
    double y;
    char z;

    printf("Size of int: %zu\n", my_sizeof(x));
    printf("Size of double: %zu\n", my_sizeof(y));
    printf("Size of char: %zu\n", my_sizeof(z));

    return 0;
}
     */


//with inline Keywords

inline size_t my_sizeof(int type) {
    return (char *)(&type + 1) - (char *)(&type);
}

int main() {
    int x;
    double y;
    char z;

    printf("Size of int: %zu\n", my_sizeof(x));
    printf("Size of double: %zu\n", my_sizeof(y));
    printf("Size of char: %zu\n", my_sizeof(z));

    return 0;
}
/* macros are more flexible but lack type checking,
   inline functions provide type checking and 
   better code organization but are limited to built in types */