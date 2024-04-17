#include <stdio.h>

#define add(a,b) ((a)+(b))
#define sub(a,b) ((a)-(b))
#define mul(a,b) ((a)*(b))
#define div(a,b) ((a)/(b))

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

    float result;
    switch (ch)
    {
    case 1:
        result = add(a,b);
        printf("Result of addition: %.2f\n", result);
        break;
    case 2:
        result = sub(a,b);
        printf("Result of subtraction: %.2f\n", result);
        break;
    case 3:
        result = mul(a,b);
        printf("Result of multiplication: %.2f\n", result);
        break;
    case 4:
        result = div(a,b);
        printf("Result of division: %.2f\n", result);
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
    return 0;
}