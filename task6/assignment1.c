#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1, *ptr2, *ptr3, *ptr4;
    int i;
    int x = 5;
    int y = 10;
    int z = 15;

    ptr1 = (int *)malloc(x * sizeof(int));
    if (ptr1 == NULL)
    {
        printf("Failed to allocate memory using malloc\n");
    }
    else
    {
        printf("Memory allocated successfully using malloc\n");
    }

    ptr2 = (int *)calloc(y, sizeof(int));
    if (ptr2 == NULL)
    {
        printf("Failed to allocate memory using calloc\n");
        free(ptr1);
    }
    else
    {
        printf("Memory allocated successfully using malloc\n");
    }

    ptr3 = (int *)malloc(z * sizeof(int));
    if (ptr3 == NULL)
    {
        printf("Failed to allocate memory using malloc\n");
        free(ptr1);
        free(ptr2);
    }
    else
    {
        printf("Memory allocated successfully using malloc\n");
    }

    ptr4 = (int *)realloc(ptr1, 20 * sizeof(int));
    if (ptr4 == NULL)
    {
        printf("Failed to reallocate memory using realloc.\n");
        free(ptr1);
        free(ptr2);
        free(ptr3);
    }
    else
    {
        printf("Memory allocated successfully using malloc\n");
    }

    for (i = 0; i < 20; ++i)
    {
        ptr4[i] = i + 1;
    }
    for (i = 0; i < y; ++i)
    {
        ptr2[i] = i + 1;
    }
    for (i = 0; i < z; ++i)
    {
        ptr3[i] = i + 1;
    }

    printf("Values of first block:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", ptr4[i]);
    }
    printf("\n");

    printf("Values of second block:\n");
    for (int i = 0; i < y; i++)
    {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    printf("Values of third block:\n");
    for (int i = 0; i < z; i++)
    {
        printf("%d ", ptr3[i]);
    }
    printf("\n");

    free(ptr4);
    free(ptr2);
    free(ptr3);

    return 0;
}