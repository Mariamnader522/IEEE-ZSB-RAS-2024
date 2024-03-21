#include <stdio.h>

// Function to compare two strings
// Returns 0 if the strings are the same, 1 otherwise
int compare(char str1[], char str2[]) {
    int i = 0, flag;

    // Iterate through the characters of both strings until a null character is encountered in either string
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] == str2[i]) {
            flag = 0; // Set flag to 0 if characters at the current position are the same
        } else {
            flag = 1; // Set flag to 1 if characters at the current position are different
        }
        i++;
    }

    return flag;
}

int main() {
    char str1[100];
    printf("Enter the 1st string: ");
    scanf("%s", str1);

    char str2[100];
    printf("Enter the 2nd string: ");
    scanf("%s", str2);

    int result = compare(str1, str2); // Call the compare function

    if (result == 0) {
        printf("The strings are the same\n");
    } else {
        printf("The strings are not the same\n");
    }

    return 0;
}