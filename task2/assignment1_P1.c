#include <stdio.h>

int main()
{
    int x = 10;
    char y = 'a';
    long long z = 100000;
    int *p1 = &x;
    char *p2 = &y;
    long long *p3 = &z;

    printf("the value of x %d\n", *p1);
    printf("the value of y %c\n ", *p2);
    printf("the value of z %lld\n", *p3);


    printf("The address stored in p1: %p\n", (void *)p1);
    printf("The address stored in p2: %p\n", (void *)p2);
    printf("The address stored in p3: %p\n", (void *)p3);

    p1++;
    p2++;
    p3++;

    printf("After incrementing the pointers:\n");
    printf("the value of x %d\n", *p1);
    printf("the value of y %c\n ", *p2);
    printf("the value of z %lld\n", *p3);

    printf("The address stored in p1: %p\n", (void *)p1); // +4 bytes 
    printf("The address stored in p2: %p\n", (void *)p2); // +1 byte
    printf("The address stored in p3: %p\n", (void *)p3); // +8 bytes 

    return 0;
}