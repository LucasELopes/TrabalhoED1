#include "funcoes.h"

Pilha* criarNo(int info) {
    Pilha *newFlag = (Pilha*)calloc(1, sizeof(Pilha));
    
    if(!newFlag) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    newFlag->flag = info;
    return newFlag;
}

Pilha* inserirNaPilha(Pilha *P, int info) {
    Pilha *novoNo = criarNo(info);
    if(P)
        novoNo->prox = P;
    return novoNo;
}

void imprimirPilha(Pilha *P) {
    if(P == NULL)
        printf("Pilha vazia!\n");
    else {
        Pilha *aux = P;
        while(aux) {
            printf("%d ", aux->flag);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int menorRepeticao(Pilha *P, int *flags, int numFlags){
    if(!P) 
        printf("Pilha vazia!\n");
    else {
        int repeticao = 0, indice = 0;
        int menor[2] = {*(flags + 0), INT_MAX}; // menor[0] = Armazenar a bandeira que menos se repetiu.
        Pilha *aux = P;                         // menor[1] = O números de repetições da bandeiras armazenada no menor[0]; 

        while(indice < numFlags) {           
            if(aux == NULL) {
                aux = P;
                if(repeticao < menor[1]){
                    menor[0] = *(flags + indice);
                    menor[1] = repeticao;
                }
                repeticao = 0;
                indice++;
            }
            else{
                printf("valor do aux: %d\n", aux->flag);
                if(aux->flag == *(flags+indice))
                    repeticao++;
                aux = aux->prox;
            }
            printf("Indice %d\n", indice);
            printf("repeticao: %d\n", repeticao);
            printf("menor[0] %d\n\n", menor[0]);
        }

        return menor[0];
    }
}
