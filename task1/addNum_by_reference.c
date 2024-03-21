#include <stdio.h>

// Function to add two numbers and store the result in sum
void add(int *num1, int *num2, int *sum) {
    *sum = *num1 + *num2;
}

int main() {
    int a, b, sum;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b); // Read the two numbers from user input

    add(&a, &b, &sum); // Call the add function, passing the addresses of a, b, and sum

    printf("The sum is: %d", sum); // Print the sum

    return 0;
}