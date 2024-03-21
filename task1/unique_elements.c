#include <stdio.h>

int main()
{
    int arr[100]; // Declare an array to store the input elements
    int newArr[100], unique = 1; // Declare an array to store the unique elements and a variable to track uniqueness
    int size; // Variable to store the size of the array

    printf("Enter the array size: ");
    scanf("%d", &size); // Read the size of the array from user input

    printf("Enter the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]); // Read each element of the array from user input
    }

    for (int i = 0; i < size; i++)
    {
        unique = 1; // Assume the element is unique initially

        for (int j = 0; j < size; j++)
        {
            // Check if the element is not the same element at a different index
            // and if it is equal to any other element in the array
            if (i != j && arr[i] == arr[j])
            {
                unique = 0; // Set uniqueness to 0 as the element is found to be non-unique
                break; // Exit the inner loop as uniqueness is already determined
            }
        }

        if (unique)
        {
            printf("The unique elements are : \n%d", arr[i]); // Print the unique element
        }
    }

    return 0;
}