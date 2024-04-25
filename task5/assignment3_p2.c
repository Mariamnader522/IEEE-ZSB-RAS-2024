#include <stdio.h>

#define addition
// #define subtraction

#ifdef addition
    #define operation(x, y) ((x) + (y))
#elif defined(subtraction)
    #define operation(x, y) ((x) - (y))
#else
    #error "No operation"
#endif

int main() {
    int num1, num2;
    int result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    result = operation(num1, num2);

    printf("The result is: %d", result);

    return 0;
}