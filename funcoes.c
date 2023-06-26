#include "funcoes.h"

Bandeira* criaBandeira(int info) {
    Bandeira *newFlag = (Bandeira*)calloc(1, sizeof(Bandeira));
    
    if(!newFlag) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    newFlag->info = info;
    return newFlag;
}

void inserirBandeira(Bandeira *A, int info) {
    if(A == NULL)
        A = criaBandeira(info);
    else {
        Bandeira *aux = A;
        Bandeira *pred = NULL;
        while(aux != NULL) {
            if(aux->dir == NULL)
                A->dir = criaBandeira(info);
            aux = aux->dir;
        }
    }
}

void imprimirTabuleiro(Bandeira *A) {
    if(A) {
        printf("%d", A->info);

        Bandeira *aux = A->esq;
        if(aux == NULL)
            aux = A->dir;
        Bandeira *pred = NULL;
        
        int nivel = 0;

        while(aux != NULL) {
            for(int i = 0; i < nivel; i++) 
                printf("\t");
            printf("%d", aux->info);
            
        }
    }
}
