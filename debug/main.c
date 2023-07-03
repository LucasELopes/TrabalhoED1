#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No{
    int* flag;
    int x, y;
    struct No *prox;
}No;

No* criarNo(int *info, int x, int y) {
    No *newFlag = (No*)calloc(1, sizeof(No));
    if(!newFlag) {
        printf("Erro na alocação!\n");
        exit(1);
    }
    newFlag->flag = info;
    newFlag->x = x;
    newFlag->y = y;
    return newFlag;
}

int** criarTabuleiro(int linhas, int colunas) {
    int** tabuleiro;

    tabuleiro = (int**)calloc(linhas, sizeof(int*));

    for(int i = 0; i < colunas; i++)
        tabuleiro[i] = (int*)calloc(colunas, sizeof(int));
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &tabuleiro[i][j]);
        }
    }

    return tabuleiro;
}

void inserirBandeira(No *P, int *info, int x, int y) {
    No *novoNo = criarNo(info, x, y);
    novoNo->flag = info;
    if(P->prox)
        novoNo->prox = P->prox;
    P->prox = novoNo;
}

void inserirNo(No *P, No *novoNo) {
    No *aux = P->prox;
    if(P->prox)
        novoNo->prox = P->prox;
    P->prox = novoNo;
}

No* removeNo(No *P) {
    No *aux = P->prox;
    if(P->prox) {
        P->prox = aux->prox;
        aux->prox = NULL;
    }
    return aux;
}

void imprimirTabuleiro(int **tabuleiro, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirPilha(No *P, int colunas) {
    if(P->prox) {
        int split = 0;
        No *aux = P->prox;
        while(aux) {
            printf("%d ", *(aux->flag));
            aux = aux->prox;
            if(split == colunas-1) {
                printf("\n");
                split = 0;
            }
            else 
                split++;
        }
        printf("\n");
    }
    else 
        printf("Pilha vazia!\n");
}

// int menorRepeticao(No *P, int *flags, int numFlags){
//     if(!P) 
//         printf("Pilha vazia!\n");
//     else {
//         int repeticao = 0, indice = 0;
//         int menor[2] = {*(flags + indice), INT_MAX}; // menor[0] = Armazenar a bandeira que menos se repetiu.
//         No *start = P->prox;
//         No *aux = start;                         // menor[1] = O números de repetições da bandeiras armazenada no menor[0]; 

//         while(indice < numFlags) {           
//             if(aux == NULL) {
//                 start = start->prox;
//                 aux = start;
//                 if(repeticao < menor[1]){
//                     menor[0] = *(flags + indice);
//                     menor[1] = repeticao;
//                 }
//                 repeticao = 0;
//                 indice++;
//             }
//             else{
//                 if(*(aux->flag) == *(flags+indice))
//                     repeticao++;
//                 aux = aux->prox;
//             }
//         }
//         return menor[0];
//     }
// }

int menorRepeticao(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags){
    if(!tabuleiro) 
        printf("tabuleiro vazio!\n");
    else {
        int repeticao = 0, indice = 0;
        int menor[2] = {*(flags + indice), INT_MAX}; // menor[0] = Armazenar a bandeira que menos se repetiu.
                                                     // menor[1] = O números de repetições da bandeiras armazenada no menor[0]; 
        while(indice < numFlags) {

            for(int i = 0; i < linhas; i++) {
                for(int j = 0; j < colunas; j++) {
                    if(tabuleiro[i][j] == *(flags+indice))
                        repeticao++;
                }
            }
            if(menor[1] > repeticao) {
                menor[0] = *(flags+indice);
                menor[1] = repeticao;
            }
            repeticao = 0;
            indice++;
        }
        return menor[0];
    }
}

void mudarBandeiraInicial(int **tabueleiro, int linhas, int colunas, int *flags, int numFlags) {
    if(numFlags <= 2) {
        if(tabueleiro[0][0] == *(flags+1)) 
            tabueleiro[0][0] = *(flags);
        else 
            tabueleiro[0][0] = *(flags+1);
    }
    else {
        int menor = menorRepeticao(tabueleiro, linhas, colunas, flags, numFlags);
        if(menor != tabueleiro[0][0])
            tabueleiro[0][0] = menor;
        else {
            int retirandoMenor[numFlags-1], indice = 0;
            for(int i = 0; i < numFlags; i++) {
                if(menor != *(flags+i))  {
                    retirandoMenor[indice] = i;
                    indice++;
                }
                i++;
            }
        }
    } 
}

int mudarAdjacente(No *P1, int **tabuleiro, int linhas, int colunas, int *flags, int numFlags) {
    //Pilhas
    No* P2 = criarNo((int*)-1, -1, -1);

    // Auxiliares das pilhas 
    No* aux = P2->prox;

    int menorELem = menorRepeticao(tabuleiro, linhas, colunas, flags, numFlags);
    int finalizado = 0;
    
    No* noRemovido = NULL;
    No* encontrarAdjacentes = NULL;

    // for(int i = 0; i < linhas; i++){
    //     for(int j = 0; j < colunas; j++){
    //     }
    // }


    inserirBandeira(P2, &tabuleiro[0][0], 0, 0);

    mudarBandeiraInicial(tabuleiro, linhas, colunas, flags, numFlags);
    imprimirTabuleiro(tabuleiro, linhas , colunas);

    while(P2->prox) {
        noRemovido = removeNo(P2);
        printf("x: %d y: %d valor: %d\n", noRemovido->x, noRemovido->y, *(noRemovido->flag));
        if(!noRemovido)
            break;

        for(int i = 0; i < linhas; i++) {
            for(int j = 0; j < colunas; j++){ 
                if(tabuleiro[i][j] != *(noRemovido->flag) && 
                ((noRemovido->x == i-1 && noRemovido->y == j) || 
                (noRemovido->y == j-1 && noRemovido->x == i))) 
                {   
                    printf("Entrou!\n");
                    tabuleiro[i][j] = *(noRemovido->flag);
                    inserirBandeira(P2, &tabuleiro[i][j],i,j);
                    imprimirTabuleiro(tabuleiro, linhas, colunas);
                }
            }
        }
    }

    imprimirTabuleiro(tabuleiro, linhas , colunas);
}

void juscelino(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags) {
    if(!tabuleiro) 
        return;
    // int menor = menorRepeticao(tabuleiro, flags, numFlags,); dassssssssssss
    
}

int main() {
    No *P = criarNo((int*)-1, -1, -1);

    int linhas, colunas, numFlags;
    int** tabuleiro;
    scanf("%d %d", &linhas, &colunas);
    scanf("%d", &numFlags);

    int flags[numFlags];
    for(int i = 0; i < numFlags; i++)
        flags[i] = i;

    tabuleiro = criarTabuleiro(linhas, colunas);
    imprimirTabuleiro(tabuleiro, linhas, colunas);

    // mudarBandeiraInicial(tabuleiro, flags, numFlags);
    // imprimirTabuleiro(tabuleiro, linhas, colunas);

    mudarAdjacente(P, tabuleiro, linhas, colunas, flags, numFlags); 

}