// This code is the implementation of the mergesort algorithm in C language.

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge_sort(int *v, int n);
void merge(int *v, int *w, int left, int mid, int right);

int main(void)
{
    int v[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int n = 8;
    int i;
    merge_sort(v, n);
    
    // Imprimir o array ordenado
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}

void merge(int *v, int *w, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i <= mid)
        w[k++] = v[i++];
    while (j <= right)
        w[k++] = v[j++];
    for (i = left; i <= right; i++)
        v[i] = w[i];
}

void merge_sort(int *v, int n)
{
    if (n < 2)
        return;

    int i, j, k, m;
    int *w;
    w = (int *)malloc(n * sizeof(int));
    for (i = 1; i < n; i *= 2)
    {
        for (j = 0; j < n - i; j += 2 * i)
        {
            m = j + i - 1;
            k = j + 2 * i - 1;
            if (k >= n)
                k = n - 1;
            merge(v, w, j, m, k);
        }
    }
    free(w);
}