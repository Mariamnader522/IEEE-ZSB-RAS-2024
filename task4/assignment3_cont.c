#include <stdio.h>
struct test
{
    char name[30];
    int id;
    char class_id;
};

int main()
{

    struct test example2;
    printf("the size after is:%d\n", sizeof(example2));

    /*
    When defining a struct in C, the compiler may add padding bytes between struct members for alignment purposes.
    Data alignment ensures that each member of the struct is stored at a memory address that is a multiple of its size,
    which can improve memory access efficiency.

    The specific arrangement and types of struct members can affect the amount of padding added by the compiler.
    Placing larger-sized members before smaller-sized members may result in additional padding to align the smaller members correctly. 
    On the other hand, if smaller-sized members are placed before larger-sized members, 
    the padding requirements may be reduced.
    */
    
    return 0;
}