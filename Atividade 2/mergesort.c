#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge_sort(int *arr, int n);
void merge(int *arr, int *temp_arr, int left, int mid, int right);

int main(void)
{
    int arr[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int n = 8;
    int i;
    
    merge_sort(arr, n);
    
    // Print the sorted array
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

// Merge function to merge two sorted halves
void merge(int *arr, int *temp_arr, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    
    // Merge the two halves
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp_arr[k++] = arr[i++];
        else
            temp_arr[k++] = arr[j++];
    }

    // Copy remaining elements from the left half (if any)
    while (i <= mid)
        temp_arr[k++] = arr[i++];
    
    // Copy remaining elements from the right half (if any)
    while (j <= right)
        temp_arr[k++] = arr[j++];
    
    // Copy the merged result back into the original array
    for (i = left; i <= right; i++)
        arr[i] = temp_arr[i];
}

// Merge Sort function (iterative implementation)
void merge_sort(int *arr, int n)
{
    if (arr == NULL || n < 2)
        return; // Avoid unnecessary work if the array is empty or has only one element

    int i, j, k, m;
    int *temp_arr = (int *)malloc(n * sizeof(int));
    
    // Bottom-up iterative merge sort
    for (i = 1; i < n; i *= 2)
    {
        for (j = 0; j < n - i; j += 2 * i)
        {
            m = j + i - 1;
            k = j + 2 * i - 1;
            if (k >= n)
                k = n - 1;
            merge(arr, temp_arr, j, m, k);
        }
    }
    
    // Free the memory used by the temporary array
    free(temp_arr);
}
