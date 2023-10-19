// Rafael Renó Corrêa
// 22/09/2023
// Algoritmo para ordenação pelo método burro
// v.1.0.0
// Complexidade no pior caso: O(n!)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *vet, int qtd, int s); // shuffle.c (portátil)

// códigos de erro:
// 1: erro na leitura de arquivo ou parâmetros
// 2: memória indisponível
int main(int argc, char * argv[]){ // uso: ./bogosort (nome do arquivo)
    FILE *f = NULL; // ponteiro para o arquivo
    int n; // recebe a qtd de elementos
    int i = 0; // para contagem
    int flag = 0; // para verificação
    int *vet = NULL; // vetor dos elementos
    int s = 0; // seed: (time(NULL) não alcança o clock processador)

    if(argc < 2){
        printf("Parâmetros insuficientes.\n");
        return 1;
    }

    // LEITURA DO ARQUIVO

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

    f = fopen(argv[1], "r");
    if(f != NULL){
        fscanf(f, "%d\n", &n);

        vet = (int*) malloc(sizeof(int*) * n);
        if(vet == NULL)return 2;

        for(i = 0; i < n; i++){
            fscanf(f ,"%d\n", &vet[i]);
        }
    }else return 1;

    //



    // BOGOSORT
    
    do{
        flag = 1;
        shuffle(vet, n, s);
        s++;

        for(i = 1; i < n; i++){ // verifica se está ordenado
            printf("%d ", vet[i - 1]);
            if(vet[i] < vet[i - 1]){
                flag = 0;
                break;
            }
        }
        printf("%d\n", vet[n - 1]);
    }while(flag == 0);

    //



    // GUARDA NO ARQUIVO

    f = fopen(argv[1], "r");
    fprintf(f, "%d\n", n);
    for(i = 0; i < n; i++)fprintf(f, "%d\n", vet[i]);

    //

    return 0;
}

// https://github.com/Yumiowari/sorting-methods

void shuffle(int *vet, int qtd, int s){
    int i = 0; // para contagem
    int r; // para manter valor pseudo-aleatório 
    int aux; // auxiliar para o embaralhamento

    srand(s);

    while(i < qtd){ // embaralha o vetor
        r = rand() % qtd;

        aux = vet[r];
        vet[r] = vet[i];
        vet[i] = aux;

        i++;
    }
}