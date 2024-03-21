#include <stdio.h>

int main()
{
    int *temp; // Declare a pointer variable to store temporary values during swapping
    int x = 5; // Declare and initialize variable x
    int y = 10; // Declare and initialize variable y
    int z = 15; // Declare and initialize variable z
    int *p = &x; // Declare and initialize pointer p to address of x
    int *q = &y; // Declare and initialize pointer q to address of y
    int *r = &z; // Declare and initialize pointer r to address of z

    // Print the values of x, y, and z
    printf("The value of x is: %d\n", x);
    printf("The value of y is: %d\n", y);
    printf("The value of z is: %d\n", z);

    // Print the addresses of x, y, and z
    printf("The address of x is: %p\n", (void *) p);
    printf("The address of y is: %p\n", (void *) q);
    printf("The address of z is: %p\n", (void *) r);

    // Print the values stored at the addresses pointed by p, q, and r
    printf("The value of x is: %d\n", *p);
    printf("The value of y is: %d\n", *q);
    printf("The value of z is: %d\n", *r);

    // Swap the pointers p, q, and r using a temporary variable
    printf("Swapping pointers\n");
    temp = p;
    p = q;
    q = r;
    r = temp;

    // Print the values of x, y, and z after swapping the pointers
    printf("The value of x is: %d\n", x);
    printf("The value of y is: %d\n", y);
    printf("The value of z is: %d\n", z);

    // Print the addresses of x, y, and z after swapping the pointers
    printf("The address of x is: %p\n", (void *) p);
    printf("The address of y is: %p\n", (void *) q);
    printf("The address of z is: %p\n", (void *) r);

    // Print the values stored at the addresses pointed by p, q, and r after swapping the pointers
    printf("The value of x is: %d\n", *p);
    printf("The value of y is: %d\n", *q);
    printf("The value of z is: %d\n", *r);

    return 0;
}