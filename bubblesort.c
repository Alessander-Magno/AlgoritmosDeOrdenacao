#include <stdio.h>

#define MAX 10

void bubbleSort(int arr[], int j)
{
    int aux;
    
    for (int i = j; i > 0; --i)
    {
        for (int k = 1; k <= i; ++k)
        {
            if (arr[k] < arr[k - 1])
            {
                aux = arr[k - 1];
                arr[k - 1] = arr[k];
                arr[k] = aux;
            }
        }
    }

    return;
}

int main ()
{
    int arr[MAX];

    for (int i = 0; i < 10; ++i)
    {
        printf("Valor n°%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Antes da ordenação:\n");
    
    for (int i = 0; i < 10; ++i)
    {
        printf("Valor n°%d: = %d\n", i + 1, arr[i]);
    }

    bubbleSort(arr, MAX - 1);

    printf("Depois da ordenação:\n");

    for (int i = 0; i < 10; ++i)
    {
        printf("Valor n°%d: = %d\n", i + 1, arr[i]);
    }

    return 0;
}