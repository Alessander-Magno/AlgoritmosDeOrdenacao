#include <stdio.h>

#define TOTAL 10

// Função para trocar dois elementos de posição
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para implementar o Selection Sort
void selectionSort(int arr[], int max) {
    int i, j, min_idx;

    // Percorre o array inteiro
    for (i = 0; i < max - 1; i++) {
        min_idx = i; // Assume que o menor elemento está na posição i

        // Encontra o menor elemento na parte não ordenada
        for (j = i + 1; j < max; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Atualiza o índice do menor elemento
            }
        }

        // Troca o menor elemento encontrado com o primeiro da parte não ordenada
        swap(&arr[min_idx], &arr[i]);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[TOTAL];

    for (int i = 0; i < TOTAL; i++)
    {
        printf("n%d°: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array original: ");
    printArray(arr, TOTAL);

    selectionSort(arr, TOTAL); // Chama a função Selection Sort

    printf("Array ordenado: ");
    printArray(arr, TOTAL);

    return 0;
}