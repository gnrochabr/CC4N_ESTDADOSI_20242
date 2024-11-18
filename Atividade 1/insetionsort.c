#include <stdio.h>

// Function prototype for Insertion Sort
void insertion_sort(int arr[], int n);

int main(void)
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Perform Insertion Sort
    insertion_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

// Insertion Sort Function
void insertion_sort(int arr[], int n)
{
    if (n <= 1)  // If the array has one or no elements, it's already sorted
        return;

    // Insertion Sort Logic
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];  // Element to insert
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key to the right
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Insert the key into its correct position
    }
}
