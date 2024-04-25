#include <stdio.h>

typedef struct num
{
    float real;
    float imaginary;
} numbers;

void add(numbers num1, numbers num2)
{
    float sum_real, sum_img;
    sum_img = num1.imaginary + num2.imaginary;
    sum_real = num1.real + num2.real;

    printf("Addition of 2 numbers is %f+j%f", sum_real, sum_img);
}

int main()
{
    numbers num1, num2;

    printf("Enter the real part for the first number: ");
    scanf("%f", &num1.real);
    printf("Enter the imaginary part for the first number: ");
    scanf("%f", &num1.imaginary);

    printf("Enter the real part for the second number: ");
    scanf("%f", &num2.real);
    printf("Enter the imaginary part for the second number: ");
    scanf("%f", &num2.imaginary);

    add(num1, num2);

    return 0;
}