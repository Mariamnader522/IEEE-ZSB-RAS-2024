#include <stdio.h>

// Function to compute the frequency of elements in an array
void frequencyArray(int arr[], int size)
{
    int freqArray[size]; // Declare an array to store the frequencies of elements
    int visited = -1; // A special value to mark visited elements

    for (int i = 0; i < size; i++)
    {
        int count = 1; // Initialize the count to 1 for each new element

        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++; // Increment the count if a duplicate element is found
                freqArray[j] = visited; // Mark the duplicate element as visited in the frequency array
            }
        }

        if (freqArray[i] != visited)
        {
            freqArray[i] = count; // Store the count in the frequency array for non-duplicate elements
        }
    }

    printf("Element\tFrequency\n");
    for (int i = 0; i < size; i++)
    {
        if (freqArray[i] != visited)
        {
            printf("%d\t%d\n", arr[i], freqArray[i]); // Print the element and its frequency
        }
    }
}

int main()
{
    int arr[100]; // Declare an array to store the elements
    int size, counter = 0; // Declare variables to store the size of the array and a counter

    printf("Enter the size of the array: ");
    scanf("%d", &size); // Read the size of the array from user input

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]); // Read each element of the array from user input
    }

    frequencyArray(arr, size); // Call the frequencyArray function to compute and print the frequencies

    return 0;
}