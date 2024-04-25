#include <stdio.h>
typedef enum
{
    add = '+',
    sub = '-',
    mul = '*',
    div = '/',
        and = '&',
    or = '|',
    not = '!'
} cal;
float operation(float operand1, float operand2, cal operation_char)
{
    switch (operation_char)
    {
    case add:
        return operand1 + operand2;

    case sub:
        return operand1 - operand2;

    case mul:
        return operand1 * operand2;

    case div:
        return operand1 / operand2;

    case and:
        return (int)operand1 & (int)operand2;

    case or:
        return (int)operand1 | (int)operand2;

    case not:
        return !(int)operand1;

    default:
        printf("Invalid operation!\n");

        return 0.0;
    }
}

int main()
{
    float operand1, operand2;
    char op;
    cal operation_char;
    printf("Enter first num: ");
    scanf("%f", &operand1);
    printf("Enter second num: ");
    scanf("%f", &operand2);
    printf("Enter operation_char[ +, -, *, /, &,, ! ]: ");
    scanf(" %c", &op);
    operation_char = (cal)op;
    float result = operation(operand1, operand2, operation_char);

    printf("the result: %f\n", result);
    printf("size of enum is %zu", sizeof(cal));
    /*the size of the enum will remain the same if added some members
    cause it determined by the underlying type which is int*/
    return 0;
}