#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void quicksort(int *v, int left, int right);
int partition(int *v, int left, int right);
void swap(int *a, int *b);

int main(void)
{
    int v[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int n = 8;
    
    if (n > 0) {
        quicksort(v, 0, n - 1);  // QuickSort call
        
        // Print the sorted array
        for (int i = 0; i < n; i++)
            printf("%d ", v[i]);
        printf("\n");
    }
    else {
        printf("The array is empty.\n");
    }

    return 0;
}

// QuickSort Function
void quicksort(int *v, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(v, left, right);
    quicksort(v, left, pivot - 1);  // Recursively sort the left subarray
    quicksort(v, pivot + 1, right); // Recursively sort the right subarray
}

// Partition Function
int partition(int *v, int left, int right)
{
    int pivot = v[right];  // Choosing the rightmost element as the pivot
    int i = left - 1;  // Index of smaller element
    int j;

    // Rearrange the elements based on the pivot
    for (j = left; j < right; j++)
    {
        if (v[j] < pivot)  // If the current element is smaller than the pivot
        {
            i++;
            swap(&v[i], &v[j]);  // Swap to put smaller element on the left side of the pivot
        }
    }

    swap(&v[i + 1], &v[right]);  // Place the pivot in its correct sorted position

    return i + 1;  // Return the pivot's final position
}

// Swap Function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

