#include <stdio.h>

// Code to make bubble sort ordenation

void bubble_sort (int *vetor, int tam);

int main (void)
{
    int vetor[10] = {5, 3, 2, 7, 6, 8, 1, 4, 0, 9};
    bubble_sort(vetor, 10);

    return 0;
}

void bubble_sort (int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);    
    }
    
}
