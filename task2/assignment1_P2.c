#include <stdio.h>

int main()
{
    unsigned int x = 0xABCDEF;
    unsigned int y = 0xFFFFFF;
    unsigned int result = x & y; // to make 3 bytes hex variable

    int *ptr = (int *)&result;

    printf("value of *ptr is 0x%x\n", *ptr);

    printf("value of *ptr++ is  a0x%x\n", *ptr++); // post increment : go to pointer then increment
    printf("value of *++ptr is a0x%x\n", *++ptr);  // pre increment : first increment then update the pointer
    printf("value of ++*ptr is a0x%x\n", ++*ptr);  // pre increment + go to pinter then increment
    return 0;
}