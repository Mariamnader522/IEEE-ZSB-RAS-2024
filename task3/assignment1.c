#include <stdio.h>
float add(float a, float b)
{
    printf("Result of addition :%.2f\n", a + b);
    float result = a + b;
    return result;
}
float sub(float a, float b)
{
    printf("Result of subtraction :%.2f\n", a - b);
    float result = a - b;
    return result;
}
float mul(float a, float b)
{
    printf("Result of multiplication :%.2f\n", a * b);
    float result = a * b;
    return result;
}
float div(float a, float b)
{
    printf("Result of division :%.2f\n", a / b);
    float result = a / b;
    return result;
}
int main()
{
    int ch;
    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    printf("Enter your choice :");
    scanf("%d", &ch);
    while (ch < 1 || ch > 4)
    {
        printf("Invalid choice. Please enter a valid choice: ");
        scanf("%d", &ch);
    }

    float a, b;
    printf("Enter the first number :");
    scanf("%f", &a);
    printf("Enter the second number :");
    scanf("%f", &b);

    float (*operation[])(float, float) = {add, sub, mul, div};
    float result = (*operation[ch - 1])(a, b);
    // printf("Result  :%f\n", result);

    return 0;
}