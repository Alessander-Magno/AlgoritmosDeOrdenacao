#include <stdio.h>

#define TOTAL 10


void printArray (int arr[], int max)
{
    for (int i = 0; i < max; ++i)
    {
        printf("%d ", arr[i]);
    }

    return;
}

int main ()
{
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

    return  0;
}