#include <stdio.h>

int main(){
    int i, j, aux;
    int array[] = { 12, 5, 90, 4, 13, 2, 6, 8, 45, 69};
    
    int tamanho = sizeof(array)/sizeof(array[0]);

    for(i = 1; i < tamanho; i++){ //inclui inicialmente o primeiro elemento começando com array[1]
        aux = array[i];

        for(j = i - 1; j >= 0 && array[j] > aux; j--){ //começando as comparações na primeira posição e dando loop até q o valor da array em j ser maior que o valor do aux (i)
            array[j+1] = array[j]; 
        }

        array[j+1] = aux;
    }

    for(i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }

    return 0;
}