#include <stdio.h>

int main()
{
    int arr[100]; // Declare an integer array to store the elements
    int size, counter = 0; // Declare variables to store the size of the array and the count of duplicate elements

    printf("Enter the size of the array: ");
    scanf("%d", &size); // Read the size of the array from user input

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]); // Read each element of the array from user input
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                counter++; // Increment the counter if a duplicate element is found
                break; // Exit the inner loop as soon as a duplicate element is found
            }
        }
    }

    printf("The total number of duplicate elements is %d\n", counter); // Print the count of duplicate elements

    return 0;
}