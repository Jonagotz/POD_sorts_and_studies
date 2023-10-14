/**
 * @file T1.c
 * @author Jonathan Gotz Correa
 * @version 0.3
 * @date 2023-09-20
 *
 * @copyright Copyright (c) 2023
 *
 *
  * Atenção: Antes de entregar, conferir se dos dados acima da documentação estão
 * preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copia(int *A,int *v, int size);
// void bubbleSort(int *A, int size);
// void selectionSort(int *A, int size);
// void insertionSort(int *A, int size);
void quickSort(int *A, int baixo, int alto, long int *contador);

void copia(int *A, int *V, int size){
	for (int i = 0 ; i < size ; i++)
    	     V[i] = A[i];
}

void printaArray (char texto[], int *A, int size) {
    printf("\n%s ", texto);
    for (int i = 0; i < size; i++){
        printf("%d ", A[i]);
    };
}

void swap (int *a,int *b){
    int temp=*(b);
    *b=*a;
    *a=temp;
};

void bubbleSort(int *A, int size){
    int i, j, t;   
    long int contador = 0;
    for (i = 0; i < size; i++) {   
        for (j = i + 1; j < size; j++) {   
            if (*(A + j) < *(A + i)) {
                swap((A + j), (A + i)); 
                contador++;
            } 
        } 
    }
    printf("\n Trocas no bubble: %ld\n", contador);
}

void selectionSort(int *A, int size) {
    long int contador = 0;

    for(int i = 0; i < size - 1; i++){ 
        int min = i;
         for (int j = i + 1; j < size; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        
        if(i != min){
            int aux = A[i];
            A[i] = A[min];
            A[min] = aux;
            contador++;
        }
    }

    printf("\n Trocas no selection: %ld\n", contador);
}

void insertionSort(int *A, int size) {
    long int contador = 0;
    int aux, j;
    for(int i = 1; i < size; i++){
        aux = A[i];
        for(j = i - 1; j >= 0 && A[j] > aux; j--){
            A[j+1] = A[j]; 
            contador++;
        }

        A[j+1] = aux;
        contador++;
    }

    printf("\n Trocas no insertion: %ld\n", contador);
}

int particiona(int *A, int baixo, int alto, long int *contador) {
    int pivo = A[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (A[j] < pivo) {
            i++;
            swap(&A[i], &A[j]);
            (*contador)++;
        }
    }
    swap(&A[i + 1], &A[alto]);
    (*contador)++;
    return (i + 1);
}

void quickSort(int *A, int baixo, int alto, long int *contador) {
    if (baixo < alto) {
        int indicePivo = particiona(A, baixo, alto, contador);
        quickSort(A, baixo, indicePivo - 1, contador);
        quickSort(A, indicePivo + 1, alto, contador);
    }

}

void programa (int n) {
    int *vet = (int *)malloc(n * sizeof(int));

    // alimentando array
    for (int i = 0; i < n; i++) {
        vet[i] = rand();
    }

    // printaArray("vetor original:", vet, n);
	printf("\nVetor tamanho = %d\n", n);

	// bubble sort
    int *bubbleVec = (int *)malloc(n * sizeof(int));
	copia(vet, bubbleVec, n);
    clock_t begin = clock();
	bubbleSort(bubbleVec, n);
    clock_t end = clock();
    // printaArray("Bubble sort:", bubbleVec, n);
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf(" tempo usado para usar o bubble: %f\n", time_spent);

	// selection sort
    int *selectionVec = (int *)malloc(n * sizeof(int));
	copia(vet, selectionVec, n);
    begin = clock();
	selectionSort(selectionVec, n);
    end = clock();
    // printaArray("Selection sort:", selectionVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf(" tempo usado para usar o selection: %f\n", time_spent);

	// insertion sort
    int *insertionVec = (int *)malloc(n * sizeof(int));
	copia(vet, insertionVec, n);
    begin = clock();
	insertionSort(insertionVec, n);
    end = clock();
	// printaArray("Insertion sort:", insertionVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf(" tempo usado para usar o insertion: %f\n", time_spent);

	// quickSort
    int *quickVec = (int *)malloc(n * sizeof(int));
    long int contadorQuick = 0;
	copia(vet, quickVec, n);
    begin = clock();
	quickSort(quickVec, 0, n - 1, &contadorQuick);
    end = clock();
	// printaArray("Quick sort:", quickVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no quick: %ld\n", contadorQuick);
    printf(" tempo usado para usar o quick: %f\n", time_spent);

    printf("================================================================================");
    
    // liberando memória
    free(vet);
    free(bubbleVec);
    free(selectionVec);
    free(insertionVec);
    free(quickVec);
}


int main(){
    srand(time(NULL));
    // tamanho do vetor
    // valores para ordenar, em ordem: 1000, 5000, 10000, 50000, 100000, 1000000
    int n[] = {1000, 5000, 10000, 50000, 100000, 1000000};
    int size = sizeof(n)/sizeof(n[0]);

    // chama programa em loop
    for (int i; i < size; i++){
        programa(n[i]);
    }
	return 0;
}