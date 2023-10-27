/**
 * @file T2.c
 * @author Jonathan Gotz Correa
 * @version 0.3
 * @date 2023-10-23
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
void printaArray (char texto[], int *A, int size);
void swap (int *a,int *b);
void bubbleSort(int *A, int size, long int *contador);
void selectionSort(int *A, int size, long int *contador);
void insertionSort(int *A, int size, long int *contador);
void quickSort(int *A, int baixo, int alto, long int *contador);
int particiona(int *A, int baixo, int alto, long int *contador);
void heapify(int arr[], int N, int i, long int *contador);
void heapSort(int arr[], int N, long int *contador);
void countingSort(int *vet, int n, long int *contador);
void countSort(int n, int exp, int *vet, long int *contador);
void radixSort(int *vet, int n, long int *contador);
void programa (int n);

//////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////

void bubbleSort(int *A, int size, long int *contador){
    int i, j, t;
    for (i = 0; i < size; i++) {   
        for (j = i + 1; j < size; j++) {   
            if (*(A + j) < *(A + i)) {
                swap((A + j), (A + i)); 
                (*contador)++;
            } 
        } 
    }
}

///////////////////////////////////////////////////////////////////////////////////

void selectionSort(int *A, int size, long int *contador) {
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
            (*contador)++;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

void insertionSort(int *A, int size, long int *contador) {
    int aux, j;
    for(int i = 1; i < size; i++){
        aux = A[i];
        for(j = i - 1; j >= 0 && A[j] > aux; j--){
            A[j+1] = A[j]; 
            (*contador)++;
        }

        A[j+1] = aux;
        (*contador)++;
    }
}

///////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////

void heapify(int arr[], int N, int i, long int *contador){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;
        (*contador)++;
 
    if (right < N && arr[right] > arr[largest])
        largest = right;
        (*contador)++;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*contador)++;
        heapify(arr, N, largest, contador);
    }
}
 
void heapSort(int arr[], int N, long int *contador) {
    for (int i = N / 2 - 1; i >= 0; i--)
       heapify(arr, N, i, contador);
 
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, contador);
    }
}
///////////////////////////////////////////////////////////////////////////////////

void countingSort(int *vet, int n, long int *contador) {
    int k = vet[0];

    // Encontre o valor máximo no vetor
    for (int i = 1; i < n; i++) {
      if (vet[i] > k)
        k = vet[i];
        (*contador)++;
    }

    // Crie o array de contagem e inicialize-o com zeros
    int *a = (int*)calloc(k + 1, sizeof(int));

    // Contagem das ocorrências de cada elemento no vetor
    for (int i = 0; i < n; i++){
        a[vet[i]]++;
        (*contador)++;
    }

    // Reconstrua o vetor ordenado
    int index = 0;
    for (int i = 0; i <= k + 1; i++) {
        while (a[i] > 0) {
            vet[index] = i;
            index++;
            a[i]--;
            (*contador)++;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

void countSort(int n, int exp, int *vet, long int *contador) {
    int *a = malloc(n*sizeof(int));
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
        count[(vet[i] / exp) % 10]++;
        (*contador)++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
        (*contador)++;

    for (int i = n - 1; i >= 0; i--) {
        count[(vet[i] / exp) % 10]--;
        a[count[(vet[i] / exp) % 10]] = vet[i];
        (*contador)++;
    }

    for (int i = 0; i < n; i++)
        vet[i] = a[i];
        (*contador)++;
}

void radixSort(int *vet, int n, long int *contador) {
    int max = vet[0];

    for (int i = 1; i < n; i++)
        if (vet[i] > max) max = vet[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(n, exp, vet, contador);
}

///////////////////////////////////////////////////////////////////////////////////

void programa (int n) {
    int *vet = (int *)malloc(n * sizeof(int));

    // alimentando array
    for (int i = 0; i < n; i++) {
        vet[i] = n - i;
    }

    printaArray("Vetor original:", vet, n);
	printf("\nVetor tamanho = %d\n", n);

	// Bubble Sort
    int *bubbleVec = (int *)malloc(n * sizeof(int));
	long int contadorBubble = 0;
    copia(vet, bubbleVec, n);
    clock_t begin = clock();
	bubbleSort(bubbleVec, n, &contadorBubble);
    clock_t end = clock();
    printaArray("Bubble sort:", bubbleVec, n);
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no bubble: %ld\n", contadorBubble);    
    printf(" tempo usado para usar o bubble: %f\n", time_spent);

	// Selection Sort
    int *selectionVec = (int *)malloc(n * sizeof(int));
    long int contadorSelection = 0;
	copia(vet, selectionVec, n);
    begin = clock();
	selectionSort(selectionVec, n, &contadorSelection);
    end = clock();
    printaArray("Selection sort:", selectionVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no selection: %ld\n", contadorSelection);
    printf(" tempo usado para usar o selection: %f\n", time_spent);

	// Insertion Sort
    int *insertionVec = (int *)malloc(n * sizeof(int));
    long int contadorInsertion = 0;
	copia(vet, insertionVec, n);
    begin = clock();
	insertionSort(insertionVec, n, &contadorInsertion);
    end = clock();
	printaArray("Insertion sort:", insertionVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no insertion: %ld\n", contadorInsertion);
    printf(" tempo usado para usar o insertion: %f\n", time_spent);

	// Quick Sort
    int *quickVec = (int *)malloc(n * sizeof(int));
    long int contadorQuick = 0;
	copia(vet, quickVec, n);
    begin = clock();
	quickSort(quickVec, 0, n - 1, &contadorQuick);
    end = clock();
	printaArray("Quick sort:", quickVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no quick: %ld\n", contadorQuick);
    printf(" tempo usado para usar o quick: %f\n", time_spent);

    // Heap Sort
    int *heapVec = (int *)malloc(n * sizeof(int));
	long int contadorHeap = 0;
	copia(vet, heapVec, n);
    begin = clock();
	heapSort(heapVec, n, &contadorHeap);
    end = clock();
	printaArray("Heap sort:", heapVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no heap: %ld\n", contadorHeap);
    printf(" tempo usado para usar o heap: %f\n", time_spent);

    // Counting Sort
    int *countingVec = (int *)malloc(n * sizeof(int));
	long int contadorCounting = 0;
    copia(vet, countingVec, n);
    begin = clock();
	countingSort(countingVec, n, &contadorCounting);
    end = clock();
	printaArray("Counting sort:", countingVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no counting: %ld\n", contadorCounting);
    printf(" tempo usado para usar o counting: %f\n", time_spent);

    // Radix Sort
    int *radixVec = (int *)malloc(n * sizeof(int));
    long int contadorRadix = 0;
	copia(vet, radixVec, n);
    begin = clock();
	radixSort(radixVec, n, &contadorRadix);
    end = clock();
	printaArray("Radix sort:", radixVec, n);
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n Trocas no radix: %ld\n", contadorRadix);
    printf(" tempo usado para usar o radix: %f\n", time_spent);

    printf("================================================================================");
    
    // liberando memória
    free(vet);
    free(bubbleVec);
    free(selectionVec);
    free(insertionVec);
    free(quickVec);
    free(heapVec);
    free(countingVec);
    free(radixVec);
}


int main(){
    srand(time(NULL));
    // tamanho do vetor
    // valores para ordenar, em ordem: 1000, 5000, 10000, 50000, 100000, 1000000
    // int n[] = {1000, 5000, 10000, 50000, 100000, 1000000};
    int n[] = {10};
    int size = sizeof(n)/sizeof(n[0]);

    // chama programa em loop
    for (int i; i < size; i++){
        programa(n[i]);
    }
	return 0;
}