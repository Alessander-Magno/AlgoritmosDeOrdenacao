#include <stdio.h>

#define TOTAL 10

int getBig (int arr[], int max) //vai pegar o maior valor digitado para estabelecer um limite
{
    int maior = arr[0];
    
    for (int i = 1; i < max; ++i)
    {
        if (arr[i] > maior)
        {
            maior = arr[i];
        }
    }

    return maior;
}

void coutingSort (int arr[], int max, int div) //aqui é onde irá ocorrer a ordenação
{
    int algarismos[10] = {0};
    int temp[max];

    for (int i = 0; i < max; ++i) //função para contabilizar a quantidade de determinado algarismo
    {
        algarismos[(arr[i] / div) % 10]++;
    }

    for (int i = 1; i < max; ++i) //função para estabelecer a 1° ocorrência de determinado algarismo
    {
        algarismos[i] += algarismos[i - 1];
    }

    for (int i = max - 1; i >= 0; --i)
    {
        temp[algarismos[(arr[i] / div) % 10] - 1] = arr[i];
        algarismos[(arr[i] / div) % 10]--;
    }

    for (int i = 0; i < max; ++i)
    {
        arr[i] = temp[i];
    }

    return;
}

void radixSort (int arr[], int max)
{
    int maior = getBig(arr, max);

    for (int div = 1; (maior / div) > 0; div *= 10)
    {
        coutingSort (arr, max, div);
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

    printf("Array antes da ordenação\n");

    for (int i = 0; i < TOTAL; i++)
    {
        printf("n%d°: %d\n", i + 1, arr[i]);
    }

    radixSort(arr, TOTAL);

    printf("Array depois da ordenação\n");

    for (int i = 0; i < TOTAL; i++)
    {
        printf("n%d°: %d\n", i + 1, arr[i]);
    }

    return 0;
}