#include <stdio.h>

#define TOTAL 10

// Função para trocar dois elementos de posição
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Particiona o array e retorna o índice do pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhendo o último elemento como pivô
    int i = low - 1; // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Se o elemento atual for menor que o pivô
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Coloca o pivô na posição correta
    return i + 1;
}

// Função principal do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Encontra o pivô

        quickSort(arr, low, pi - 1); // Ordena os elementos antes do pivô
        quickSort(arr, pi + 1, high); // Ordena os elementos depois do pivô
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programa principal
int main() {
    int arr[TOTAL];

    for (int i = 0; i < TOTAL; i++)
    {
        printf("n%d°: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array original: ");
    printArray(arr, TOTAL);

    quickSort(arr, 0, TOTAL - 1);

    printf("Array ordenado: ");
    printArray(arr, TOTAL);

    return 0;
}