#include <stdio.h>

int main()
{
    int i = 0;
    char str1[100]; // Original string
    char str2[100]; // Copied string

    printf("Enter the string: ");
    scanf("%[^\n]%*c", str1); // Read the string from user input

    // Copy characters from str1 to str2 until the null character is encountered
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }

    str2[i] = '\0'; // Add the null character at the end to terminate the string

    printf("The copied string is: %s ", str2); // Print the copied string

    return 0;
}