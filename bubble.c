#include <stdio.h>

int main(){
    int i, j, aux, lenght;
    int matriz[] = {2, 4, 6, 8, 12, 23, 5, 1, 2, 3};

    lenght = sizeof(matriz)/sizeof(matriz[0]);
    
    for(i = 0; i < lenght; i++){
        for(j = 0; j < lenght - 1 - i; j++){
            if( matriz[j] > matriz[j+1]){
                aux = matriz[j];
                matriz[j] = matriz[j+1];
                matriz[j+1] = aux;
            }
        }
    }
     
    for(i = 0; i < lenght; i++){
        printf("matriz[%d] = %d\n", i, matriz[i]);
    }
    return 0;
}