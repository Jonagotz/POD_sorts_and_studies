#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_se_erro(FILE *arquivo) {
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
}

void alimenta_array (int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand();
    }
}

void escreve_texto (const char *texto, FILE *arquivo) {
    fprintf(arquivo, "%s" ,texto);
}

void escreve_numeros_vetorizados(int *vetor, FILE *arquivo, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    printf(" Vetor de inteiros salvo com sucesso com %d valores diferentes.\n\n", tamanho);
}

int calcula_media (int *contador, int *soma, FILE *arquivo, int *vetor) {
    int numero, it = 0;

    while (fscanf(arquivo, "%d", &numero) != EOF) {
        (*soma) += numero;
        (*contador)++;
        vetor[it] = numero;
        it++;
    }
    printf(" Soma: %d\n Contador: %d\n", *soma, *contador);
    // calcula média
    if (contador > 0) {
        double media = *soma / *contador;
        printf(" Media: %.2f\n", media);
        return media;
    } else {
        printf(" Nenhum valor foi lido no arquivo.\n");
        return 0;
    }
}

void remove_maior_que_media (double *media, int *vetor) {
    int novo_tamanho = 0;
    for (int i = 0; i < 500; i++) {
        if (vetor[i] <= *media) {
            vetor[novo_tamanho] = vetor[i];
            novo_tamanho++;
        }
    }

    FILE *arquivo = fopen("vetor_500_inteiros.txt", "w");
    verifica_se_erro(arquivo);
    
    for (int i = 0; i < novo_tamanho; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    printf(" Números maiores que a média foram removidos e o arquivo foi atualizado.\n\n");
}

void substitui_texto(const char *texto_antigo, const char *texto_novo) { // método só funciona para substituir últimos dígitos de uma linha
    FILE *arquivo = fopen("eu_sei_trabalhar.txt", "r+");
    verifica_se_erro(arquivo);
    
    fseek(arquivo, -strlen(texto_antigo), SEEK_END);
    fputs(texto_novo, arquivo);
    
    fclose(arquivo);
    printf(" Texto substituido com sucesso\n\n");
}

void adiciona_texto_no_meio (const char *arquivo_nome) {
    FILE *arquivo = fopen(arquivo_nome, "r");
    FILE *arquivo_temp = fopen("temp.txt", "w");
    verifica_se_erro(arquivo);

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *posicao = strstr(linha, "em");
        if (posicao != NULL) {
            int posicao_final = posicao - linha + 2; // Posição final da palavra "em"
            fprintf(arquivo_temp, "%.*s quase%s", posicao_final, linha, linha + posicao_final);
        } else {
            fputs(linha, arquivo_temp);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    // Substitui o arquivo original pelo arquivo temporário
    remove(arquivo_nome);
    rename("temp.txt", arquivo_nome);

    printf("\n Texto modificado com sucesso.\n");
}

int main() {
    
    // ---------------------------------------------------------------------------------------------------------------------------------------------------
    
    printf("Exercício 1 = Faça uma função capaz de salvar um vetor de inteiros de 1 até 10 em um arquivo.\n");
    int n = 10;
    int *vetor_1 = (int *)malloc(n * sizeof(int));
    FILE *arquivo_1 = fopen("vetor_inteiros.txt", "w");

    alimenta_array(vetor_1, n);
    verifica_se_erro(arquivo_1);
    escreve_numeros_vetorizados(vetor_1, arquivo_1, n);
    fclose(arquivo_1);
    free(vetor_1);

    // ---------------------------------------------------------------------------------------------------------------------------------------------------
    
    printf("Exercício 2 = Faça um código em C para armazenar um vetor randômico com 500 valores inteiros.\n");
    n = 500;
    int *vetor_2 = (int *)malloc(n * sizeof(int));
    FILE *arquivo = fopen("vetor_500_inteiros.txt", "w+");

    alimenta_array(vetor_2, n);
    verifica_se_erro(arquivo);
    escreve_numeros_vetorizados(vetor_2, arquivo, n);
    fclose(arquivo);
    free(vetor_2);

    // ---------------------------------------------------------------------------------------------------------------------------------------------------

    printf("Exercício 3 = No arquivo da questão 2, faça uma função capaz de remover os números maiores que a média, e refazer o salvamento no arquivo\n");
    FILE *arq = fopen("vetor_500_inteiros.txt", "r+");
    int contador = 0, soma = 0;
    int *vet = (int *)malloc(n * sizeof(int));;
    double media = calcula_media(&contador, &soma, arq, vet);
    fclose(arq);

    remove_maior_que_media(&media, vet);

    // ---------------------------------------------------------------------------------------------------------------------------------------------------

    printf("Exercício 4 = Crie um código em C para armazenar o seguinte texto em C: “Eu sei trabalhar com arquivos em C”\n\n");
    FILE *arquivo_2 = fopen("eu_sei_trabalhar.txt", "w+");
    escreve_texto("Eu sei trabalhar com arquivos em C", arquivo_2);
    fclose(arquivo_2);

    // ---------------------------------------------------------------------------------------------------------------------------------------------------

    printf("Exercício 5 = Abra o arquivo anterior, apague a string “em C” e adiciona a string “em todas as linguagens de programação” usando o Fseek.\n");
    // Saída: “Eu sei trabalhar com arquivos em todas as linguagens de programação”
    substitui_texto("em c","em todas as linguagens de programação");

    // ---------------------------------------------------------------------------------------------------------------------------------------------------

    printf("Exercício 6 = Altere o arquivo para adicionar a string “quase”.");
    // Saída:  “Eu sei trabalhar com arquivos em quase todas as linguagens de programação”
    adiciona_texto_no_meio("eu_sei_trabalhar.txt");

    return 0;
}
