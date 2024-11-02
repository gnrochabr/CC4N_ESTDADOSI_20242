// This algorithm aims to create a selection sort

#include <stdio.h>

// Functions prototype
void selection_sort (int *array, int array_len);

// Main function
int main (void)
{
    int array[] = {44, 6, 8, 1, 0, 2, 3, 4, 7, 9, 89, 21};
    
    // Calculate the array size
    int array_len = sizeof(array) / sizeof(array[0]);

    selection_sort(array, array_len);
    printf("Array ordered: ");
    for (int i = 0; i < array_len; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}

// Selection sort function
void selection_sort (int *array, int array_len)
{
    int max_idp = 0;
    int step = 0;

    for (int i = 0; i < array_len; i++)
    {
        max_idp = i;
        for (int j = i + 1; j < array_len; j++)
        {
            if (array[j] < array[max_idp])
            {
                max_idp = j;
            }
        }
        step = array[i];
        array[i] = array[max_idp];
        array[max_idp] = step;
    }    
}
