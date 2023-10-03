#include <stdio.h>
#include <stdlib.h>

void intercala(int *array, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if (temp != NULL) {
        for(i = 0; i< tamanho; i++){
            if(!fim1 && !fim2){
                if(array[p1] < array[p2]){
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }

                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            }
            else {
                if(!fim1){
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }
            }
        }

        for(j = 0, k = inicio; j < tamanho; j++, k++){
            array[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(int array[], int inicio, int fim){
    if (inicio < fim){
        int meio = ((inicio + fim) / 2 );
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        intercala(array, inicio, meio, fim);
    }
}

int main(){

    int i, array[] = { 12, 5, 90, 4, 13, 2, 6, 8, 45, 69}; 
    int tamanho = sizeof(array)/sizeof(array[0]);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n   -- Array antes da ordenação --\n");

    for( i = 0; i < tamanho; i++){
        printf("Array[%d] = %d\n", i, array[i]);
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n   -- Array depois da ordenação --\n");
    
    mergeSort(array, 0, tamanho - 1);
    for( i = 0; i < tamanho; i++){
        printf("Array[%d] = %d\n", i, array[i]);
    }

    return 0;
}