#include <stdio.h>

// Função auxiliar: Encontra o maior valor no array
int getMax(int arr[], int n) 
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }    
    }
        
    return max;
}

// Função auxiliar: Counting Sort para um dígito específico
void countingSort(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0}; 

    // Contagem de ocorrências de cada dígito
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Ajustando a posição dos elementos
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construindo o array ordenado
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiando de volta para o array original
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Função principal do Radix Sort
void radixSort(int arr[], int n) 
{
    int max = getMax(arr, n);

    // Aplica Counting Sort para cada casa decimal (1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Testando o Radix Sort
int main() 
{
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 10; i++)
    {
        printf("N°%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array desordenado: ");
    printArray(arr, n);
    
    radixSort(arr, n);
    
    printf("Array ordenado: ");
    printArray(arr, n);

    return 0;
}