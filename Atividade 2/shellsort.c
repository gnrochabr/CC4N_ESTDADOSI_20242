#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void shellsort(int *v, int n);
void swap(int *a, int *b);

int main(void)
{
    int v[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int n = 8;

    if (n > 0) {
        shellsort(v, n);  // ShellSort call

        // Print the sorted array
        for (int i = 0; i < n; i++)
            printf("%d ", v[i]);
        printf("\n");
    } else {
        printf("The array is empty.\n");
    }

    return 0;
}

// ShellSort Function
void shellsort(int *v, int n)
{
    int i, j, gap, temp;
    // Start with the largest gap and reduce it
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

// Swap Function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
