#include <stdio.h>

void binSort (int arr[])
{
    int aux;
    
    for (int i = 0; i < 9; ++i)
    {
        printf("--->%d<---\n", i);

        while (i != arr[i])
        {
            printf("arr[arr[%d]] = %d e arr[%d] = %d -> ", i, arr[arr[i]], i, arr[i]);

            aux = arr[arr[i]];
            arr[arr[i]] =  arr[i];
            arr[i] = aux;

            printf("arr[arr[%d]] = %d e arr[%d] = %d\n", i, arr[arr[i]], i, arr[i]);
        }
    }

    return;
}

int main ()
{
    int arr[10] = {2, 5, 7, 8, 4, 1, 9, 6, 3, 0};

    /*for (int i = 0; i < 10; ++i) //leitura dos valores
    {
        printf("%d° valor: ", i + 1);
        scanf("%d", &arr[i]);
    }*/

    for (int i = 0; i < 10; ++i) //impressão dos valores
    {
        printf("ANTES DA ORDENAÇÃO\nPosição %d°: %d\n", i, arr[i]);
    }

    binSort(arr);

    for (int i = 0; i < 10; ++i) //impressão dos valores
    {
        printf("DEPOIS DA ORDENAÇÃO\nPosição %d°: %d\n", i, arr[i]);
    }

    return 0;
}