#include <stdio.h>

int main()
{
    char str[100]; // Declare a character array to store the string

    printf("Enter the string: ");
    scanf("%[^\n]%*c", str); // Read the string from user input, %[^\n] is used to read the string until a newline character is encountered

    printf("The string is: %s", str); // Print the entered string

    return 0;
}