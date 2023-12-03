#include <stdio.h>

int particiona(int array[], int inicio, int fim){
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = fim;
    pivo = array[inicio];

    while(esquerda < direita){
        while(array[esquerda] <= pivo){
            esquerda++; // enquanto não acha elemento do inicio ao fim menor que o pivo avança até o final do vetor
        }

        while(array[direita] > pivo){
            direita--; // enquanto não acha elemento do fim ao inicio maior que o pivo retrai até o começo do vetor
        }

        if(esquerda < direita){ // etapa de particionamento após verificar se havia elementos maiores ou menores que o pivo
            aux = array[esquerda]; // realiza a troca dos elementos da direita pra esquerda de lugar encontrados nos whiles anteriores
            array[esquerda] = array[direita];
            array[direita] = aux;
        }

    }
    
    array[inicio] = array[direita]; // inicio recebe ultimo valor da direita
    array[direita] = pivo; // o ponto onde foi parado com a direita é a posição onde todo mundo antes é menor e todo mundo depois é maior
    return direita;
}

void quickSort(int array[], int inicio, int fim){
    int pivo;
    if(fim > inicio){ 
        pivo = particiona(array, inicio, fim); // calculo a posiçõa do pivo
        quickSort(array, inicio, pivo - 1); // tendo o pivo chama a função com os dados rearranjados para os elementos que estão antes do pivo
        quickSort(array, pivo + 1, fim); // e do elemento seguinte do pivo até o fim do vetor ordernando as duas metades
    }

}

int main(){
    int i, array[] = { 12, 5, 90, 4, 13, 2, 6, 8, 45, 69}; // array de 10 posições
    int tamanho = sizeof(array)/sizeof(array[0]);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n   -- Array antes da ordenação --\n");

    for( i = 0; i < tamanho; i++){
        printf("Array[%d] = %d\n", i, array[i]);
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n   -- Array depois da ordenação --\n");  

    quickSort(array, 0, tamanho - 1);

    for( i = 0; i < tamanho; i++){
        printf("Array[%d] = %d\n", i, array[i]);
    }

    return 0;
}