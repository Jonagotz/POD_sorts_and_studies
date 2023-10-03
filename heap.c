#include <stdio.h>

void heap_heap(int *arr, int i, int f)
{
    int aux = arr[i];
    int j = i * 2 + 1;

    while (j <= f){
        if (j < f){   
            if (arr[j] < arr[j + 1]){ 
                j = j + 1;
            }
        }

        if (aux < arr[j]){
            arr[i] = arr[j];
            i = j;
            j = 2 * i + 1;
        } else {
            j = f + 1;
        }
    }

    arr[i] = aux;
}

void heap_sort(int *arr, int N)
{
    int i, aux;
    for (i = (N - 1) / 2; i >= 0; i--)
    {
        heap_heap(arr, i, N - 1);
    }

    for (i = N - 1; i >= 1; i--)
    {
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;
        heap_heap(arr, 0, i - 1); 
    }
}

int main(){
    
    int i, array[] = { 12, 5, 90, 4, 13, 2, 6, 8, 45, 69}; // array de 10 posições
    int tamanho = sizeof(array)/sizeof(array[0]);

    printf("Antes da ordenação:\n");
    for (int i=0; i < tamanho; i++){
        printf("posição[%d] = %d\n", i, array[i]);
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    heap_sort(array, tamanho);

    printf("Depois da ordenação:\n");
    for (int i=0; i<tamanho; i++){
        printf("posição[%d] = %d\n", i, array[i]);
    }
    
    return 0;
}