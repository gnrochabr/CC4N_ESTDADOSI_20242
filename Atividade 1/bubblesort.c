#include <stdio.h>

// Function that implements Bubble Sort
void bubble_sort(int *array, int size);
void print_array(int *array, int size);

int main()
{
    int array[10] = {5, 3, 2, 7, 6, 8, 1, 4, 0, 9};
    
    bubble_sort(array, 10);  // Sorting the array
    print_array(array, 10);   // Printing the sorted array

    return 0;
}

// Function Bubble Sort
void bubble_sort(int *array, int size)
{
    int swapped;  // Flag to check if a swap has occurred
    for (int i = 0; i < size - 1; i++)
    {
        swapped = 0;  // Reset the flag at the start of each iteration
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swap the elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;  // Mark that a swap occurred
            }
        }
        // If no swaps occurred, the array is already sorted
        if (swapped == 0)
            break;
    }
}

// Function to print the array
void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
