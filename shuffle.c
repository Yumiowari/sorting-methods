// Rafael Renó Corrêa
// 22/09/2023
// Algoritmo para geração de sequência embaralhada de números inteiros
// v.1.2.1
// Complexidade no pior caso: O(n)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// códigos de erro:
// 1: problema na leitura de parâmetros
// 2: memória indisponível
int main(int argc, char * argv[]){ // uso: ./shuffle (nome do arquivo) (qtd de elementos)
    FILE *f = NULL; // ponteiro para o arquivo
    int i = 0; // para contagem
    int flag = 0; // para verificação do arquivo
    int qtd; // qtd pretendida de elementos
    int r; // para manter valor pseudo-aleatório 
    int aux; // auxiliar para o embaralhamento
    int *vet = NULL; // vetor para o embaralhamento

    if(argc < 3){
        printf("Parâmetros insuficientes.\n");
        return 1;
    }

    // LEITURA DO NOME DO ARQUIVO

    while(argv[1][i] != '\0'){
        i++;
        if(i == 15){
            printf("O nome do arquivo não pode extrapolar 15 caracteres.\n");
            return 1;
        }
    }

    for(int j = i - 1; j >= i - 4; j--){
        if(argv[1][j] != 't' && flag == 0)break;
        if(argv[1][j] != 'x' && flag == 1)break;
        if(argv[1][j] != 't' && flag == 2)break;
        if(argv[1][j] != '.' && flag == 3)break;
        flag++;
    }

    if(flag != 4){
        printf("O tipo do arquivo deve ser especificado.\n");
        return 1;
    }

    //



    // LEITURA DA QTD DE ELEMENTOS

    i = 0;
    while(argv[2][i] != '\0'){
        if(argv[2][i] < 48 && argv[2][i] > 57){
            printf("A quantidade deve ser um número inteiro.\n");
            return 1;
        }
        i++;
        if(i == 8){
            printf("A quantidade não pode extrapolar 7 dígitos.\n");
            return 1;
        }
    }

    qtd = atoi(argv[2]); // converte a string para inteiro

    vet = (int*) malloc(sizeof(int*) * qtd);
    if(vet == NULL)return 2;

    //



    // GERAÇÃO DOS NÚMEROS

    i = 0;
    while(i < qtd){ // preenche o vetor de forma ordenada
        vet[i] = i + 1;
        i++;
    }

    srand(time(NULL));

    i = 0;
    while(i < qtd){ // embaralha o vetor
        r = rand() % qtd;

        aux = vet[r];
        vet[r] = vet[i];
        vet[i] = aux;

        i++;
    }

    //



    // GUARDA NO ARQUIVO

    f = fopen(argv[1], "w+");

    fprintf(f, "%d\n", qtd);

    for(i = 0; i < qtd; i++){
        fprintf(f, "%d\n", vet[i]);
    }

    fclose(f);

    //

    return 0;
}

// https://github.com/Yumiowari/sorting-methods