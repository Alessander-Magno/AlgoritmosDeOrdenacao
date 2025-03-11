#include <stdio.h>

void insertSort(int arr[])
{
    int i, j, aux;

    for (i = 0; i < 9; ++i)
    {
        j = i + 1;

        while ((arr[j] < arr[j - 1]) && (j > 0))
        {
            aux = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = aux;

            --j;
        }
    }

    return;
}

int main ()
{
    int arr[10];

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

    insertSort(arr);

    printf("Depois da ordenação:\n");

    for (int i = 0; i < 10; ++i)
    {
        printf("Valor n°%d: = %d\n", i + 1, arr[i]);
    }

    return 0;
}