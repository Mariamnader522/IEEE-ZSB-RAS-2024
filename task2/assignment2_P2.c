#include <stdio.h>

int main()
{

    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;
    printf("the array elements are :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }
    return 0;
}