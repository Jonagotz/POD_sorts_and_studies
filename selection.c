#include <stdio.h>

int main(){
    int i, j, aux, min; 
    int arr[] = {7, 10, 5, 3, 8, 4, 2, 9, 6};

    int tamanho = sizeof(arr)/sizeof(arr[0]); // pega o sizeof da array de forma independente de quão grande for a array

    for(i = 0; i < tamanho - 1; i++){ 
        min = i; // guarda o valor de i em min para testar no próximo loop se é o menor
         for (j = i + 1; j < tamanho; j++){ 
            if(arr[j] < arr[min]){ // o valor da array que esta sendo acessado neste momento é o menor até agora?
                min = j; // se sim atualiza o valor da variável min
            } 
            if(i != min){ // se não for atualiza a array trocando os valores de lugar com um auxiliar
                aux = arr[i]; 
                arr[i] = arr[min];
                arr[min] = aux;
            }
        }
    }

    for(i = 0; i < tamanho; i++){
        printf("array[%d] = %d\n", i, arr[i]);
    }

    return 0;
}