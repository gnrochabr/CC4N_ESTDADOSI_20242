// This code is the implementation of the quicksort algorithm in C language.

#include <stdio.h>
#include <stdlib.h>

void quicksort(int *v, int left, int right);
int partition(int *v, int left, int right);

int main (void)
{
    int v[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int n = 8;
    int i;
    quicksort(v, 0, n - 1);

    // Print the sorted array
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}

void quicksort(int *v, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(v, left, right);
    quicksort(v, left, pivot - 1);
    quicksort(v, pivot + 1, right);
}

int partition(int *v, int left, int right)
{
    int pivot = v[right];
    int i = left - 1;
    int j;

    for (j = left; j < right; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[right];
    v[right] = temp;

    return i + 1;
}

