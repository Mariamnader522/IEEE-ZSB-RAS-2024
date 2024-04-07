#include <stdio.h>
void func(int *a)
{
    (*a)++;
}
int main()
{
    int num = 10;
    void (*ptr)(int *) = &func;
    printf("value before increment is : %d\n", num);
    ptr(&num);
    printf("value after increment is : %d\n", num);

    return 0;
}
