/**
 * @file 35.radixsort.c
 * @brief Implementação do Radix Sort (LSD e MSD) em C.
 * 
 * Este arquivo contém a implementação do Radix Sort usando as abordagens de Dígito Menos Significativo (LSD)
 * e Dígito Mais Significativo (MSD). Também inclui uma função para medir o tempo de execução dos algoritmos de ordenação.
 * 
 * @autor [Seu Nome]
 * @data [Data]
 */
 * @brief Implementation of Radix Sort (LSD and MSD) in C.
 * 
 * This file contains the implementation of Radix Sort using both Least Significant Digit (LSD)
 * and Most Significant Digit (MSD) approaches. It also includes a function to measure the 
 * execution time of the sorting algorithms.
 * 
 * @author Giovanni Persio Gonçalves
 * @date 30/10/2024
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 20

// Função para realizar o Counting Sort
void counting_sort(int *arr, int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Contar ocorrências
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcular a posição de cada dígito
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar o array de saída de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função do Radix Sort LSD para números
void radix_sort_lsd(int *arr, int n) {
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    for (int exp = 1; max_num / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
    }
}

// Função do Counting Sort para MSD
void counting_sort_msd(int *arr, int n, int exp, int base) {
    int output[n];
    int count[base];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % base;
        count[index]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % base;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função do Radix Sort MSD
void radix_sort_msd(int *arr, int n) {
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    for (int exp = 1; max_num / exp > 0; exp *= 10) {
        counting_sort_msd(arr, n, exp, 10);
    }
}

// Função para medir o tempo de execução
double measure_time(void (*sort_function)(int *, int), int *data, int n) {
    clock_t start_time = clock();
    sort_function(data, n);
    clock_t end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

int main() {
    int numbers[] = {
        170, 45, 75, 90, 802, 24, 2, 66,
        1023, 2048, 5678, 8765, 4321, 9999,
        123456, 654321, 987654, 456789, 54321,
        12, 8, 5, 9, 34, 78, 90, 100,
        543, 2345, 6789, 999, 333, 4444,
        567, 890, 3456, 7890, 13579, 24680,
        11111, 22222, 33333, 44444, 55555,
        9999, 8888, 7777, 6666, 5555,
        1234, 4321, 567, 890, 1000, 2000,
        101, 203, 304, 405, 506, 607, 708, 809,
        99999, 88888, 77777, 66666, 55555, 44444, 33333, 22222, 11111,
        10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000,
        100000, 250000, 500000, 750000, 999999, 1234567, 7654321
    };
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int lsd_array[n];
    memcpy(lsd_array, numbers, sizeof(numbers));
    double time_lsd = measure_time(radix_sort_lsd, lsd_array, n);
    printf("Números ordenados (LSD): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lsd_array[i]);
    }
    printf("\nTempo de processamento (LSD): %.6f segundos\n", time_lsd);

    int msd_array[n];
    memcpy(msd_array, numbers, sizeof(numbers));
    double time_msd = measure_time(radix_sort_msd, msd_array, n);
    printf("Números ordenados (MSD): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", msd_array[i]);
    }
    printf("\nTempo de processamento (MSD): %.6f segundos\n", time_msd);

    return 0;
}
