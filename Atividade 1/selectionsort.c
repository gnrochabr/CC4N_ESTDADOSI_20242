#include <stdio.h>

// Function prototype for selection sort
void selection_sort(int *array, int array_len);

// Main function
int main(void)
{
    // Initial array to be sorted
    int array[] = {44, 6, 8, 1, 0, 2, 3, 4, 7, 9, 89, 21};
    
    // Calculate the array size
    int array_len = sizeof(array) / sizeof(array[0]);

    // Perform the selection sort
    selection_sort(array, array_len);

    // Print the sorted array
    printf("Array ordered: ");
    for (int i = 0; i < array_len; i++)
    {
        printf("%d ", array[i]);  // Print each element
    }
    
    return 0;
}

// Selection Sort implementation
void selection_sort(int *array, int array_len)
{
    int max_idp = 0;  // Variable to hold the index of the minimum element
    int step = 0;     // Temporary variable for swapping

    // Loop through the array
    for (int i = 0; i < array_len - 1; i++)  // Decrease the loop count by 1 as last element is already sorted
    {
        max_idp = i;  // Assume the current index as the minimum element
        for (int j = i + 1; j < array_len; j++)  // Start comparing from the next element
        {
            // If the element at index j is smaller, update the index of the minimum element
            if (array[j] < array[max_idp])
            {
                max_idp = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (max_idp != i)  // Only swap if the minimum is not already in the correct position
        {
            step = array[i];
            array[i] = array[max_idp];
            array[max_idp] = step;
        }
    }    
}
