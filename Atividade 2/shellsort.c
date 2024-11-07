// This code is the implementation of the shellsort algorithm in C language.

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void shellsort(int *v, int n);

int main (void)
{
    int v[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int n = 8;
    int i;
    shellsort(v, n);

    // Print the sorted array
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}

void shellsort(int *v, int n)
{
    int i, j, gap, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = v[i];
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
    }
}