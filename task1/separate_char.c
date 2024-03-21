#include <stdio.h>

int main()
{
    int lastChar = 0; // Variable to keep track of the index of the last character in the string
    char str[100]; // Array to store the input string

    printf("Enter the string: ");
    scanf("%[^\n]%*c", str); // Read the string from user input, allowing spaces

    printf("The characters of the string are: \n");
    while (str[lastChar] != '\0')
    {
        printf("%c\n", str[lastChar]); // Print each character of the string
        lastChar++; // Move to the next character
    }

    return 0;
}