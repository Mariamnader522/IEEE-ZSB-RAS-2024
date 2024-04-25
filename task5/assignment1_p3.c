#include <stdio.h>
typedef unsigned int in;
typedef unsigned short srt;
typedef unsigned long lg;
typedef float ft;
typedef double dbl;
typedef char cr;


int main()
{
    printf("size of integer is: %zu\n",sizeof(in));
    printf("size of short is: %zu\n",sizeof(srt));
    printf("size of long is: %zu\n",sizeof(lg));
    printf("size of float is: %zu\n",sizeof(ft));
    printf("size of double is: %zu\n",sizeof(dbl));
    printf("size of char is: %zu\n",sizeof(cr));
    
    return 0;
}