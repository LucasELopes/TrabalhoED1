#include "funcoes.h"

NoPilha* criarNo(int *info, int x, int y) {
    NoPilha *newFlag = (NoPilha*)calloc(1, sizeof(NoPilha));
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

    for(int i = 0; i < linhas; i++)
        tabuleiro[i] = (int*)calloc(colunas, sizeof(int));
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &tabuleiro[i][j]);
        }
    }

    return tabuleiro;
}

void inserirBandeira(NoPilha *P, int *info, int x, int y) {
    NoPilha *novoNo = criarNo(info, x, y);
    novoNo->flag = info;
    if(P->prox)
        novoNo->prox = P->prox;
    P->prox = novoNo;
}

void inserirNo(NoPilha *P, NoPilha *novoNo) {
    NoPilha *aux = P->prox;
    if(P->prox)
        novoNo->prox = P->prox;
    P->prox = novoNo;
}

NoPilha* removeNo(NoPilha *P) {
    NoPilha *aux = P->prox;
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

void imprimirPilha(NoPilha *P, int colunas) {
    if(P->prox) {
        int split = 0;
        NoPilha *aux = P->prox;
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

int repeticao(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags, int menorOuMaior){
    if(!tabuleiro) 
        printf("tabuleiro vazio!\n");
    else {
        int repeticao = 0, indice = 0;
        int menor[2] = {*(flags+indice)}; // menor[0] = Armazenar a bandeira que menos se repetiu.
                                                     // menor[1] = O números de repetições da bandeiras armazenada no menor[0]; 
        if(menorOuMaior >= 0)
            menor[1] = INT_MIN;
        else
            menor[1] = INT_MAX;
        while(indice < numFlags) {
            for(int i = 0; i < linhas; i++) {
                for(int j = 0; j < colunas; j++) {
                    if(tabuleiro[i][j] == *(flags+indice))
                        repeticao++;
                }
            }
            if(menorOuMaior >= 0){
                if(menor[1] < repeticao && *(flags+indice) != tabuleiro[0][0]) {
                    menor[0] = *(flags+indice);
                    menor[1] = repeticao;
                }
            }
            else {
                if(menor[1] > repeticao && *(flags+indice) != tabuleiro[0][0]) {
                    menor[0] = *(flags+indice);
                    menor[1] = repeticao;
                }
            }
            repeticao = 0;
            indice++;
        }
        return menor[0];
    }
}

int mudarBandeiraInicial(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags) {
    if(numFlags <= 2) {
        if(tabuleiro[0][0] == *(flags+1)) {
            tabuleiro[0][0] = *(flags);
            return *(flags+1);
        }
        else {
            tabuleiro[0][0] = *(flags+1);
            return *(flags);
        }
    }
    else {
        int valorAnterior = tabuleiro[0][0];
        if(linhas > 2 && colunas > 2) {
            if(tabuleiro[0][0] != tabuleiro[1][0] && tabuleiro[1][0] == tabuleiro[0][1]){
                tabuleiro[0][0] = tabuleiro[1][0];    
            }
            else {

                if(tabuleiro[2][0] == tabuleiro[1][1] || tabuleiro[1][1] == tabuleiro[1][0] || tabuleiro[2][0] == tabuleiro[1][0]) {
                    tabuleiro[0][0] = tabuleiro[1][0];
                }
                else if(tabuleiro[0][2] == tabuleiro[1][1] || tabuleiro[1][1] == tabuleiro[0][1] || tabuleiro[0][2] == tabuleiro[0][1]) {
                    tabuleiro[0][0] = tabuleiro[0][1];
                }
                else {
                    int maiorRepeticao = repeticao(tabuleiro, linhas, colunas, flags, numFlags, 0);
                    if(tabuleiro[0][0] != maiorRepeticao && (tabuleiro[1][0] == maiorRepeticao || tabuleiro[0][1] == maiorRepeticao)) {
                        tabuleiro[0][0] = maiorRepeticao;
                    }
                    else{
                        tabuleiro[0][0] = tabuleiro[1][0];
                    }
                }
            }
        }
        return valorAnterior;
        // int menor = menorRepeticao(tabueleiro, linhas, colunas, flags, numFlags);
        // if(menor != tabueleiro[0][0])
        //     tabueleiro[0][0] = menor;
        // else {
        //     int retirandoMenor[numFlags-1], indice = 0;
        //     for(int i = 0; i < numFlags; i++) {
        //         if(menor != *(flags+i))  {
        //             retirandoMenor[indice] = i;
        //             indice++;
        //         }
        //     }
        //     tabueleiro[0][0] = menorRepeticao(tabueleiro, linhas, colunas, retirandoMenor, (numFlags-1));
        // }
        // return menor;
    } 
    
}

int verificarTabuleiro(int** tabuleiro, int linhas, int colunas) {
    int comparador = tabuleiro[0][0]; 
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if(comparador != tabuleiro[i][j])
                return 0;
        }
    }
    return 1;
}

void mudarAdjacente(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags) {
    NoPilha* P = criarNo((int*)-1, -1, -1);
    NoPilha* noRemovido = NULL;

    int troca = 0;

    inserirBandeira(P, &tabuleiro[0][0], 0, 0);

    int k = mudarBandeiraInicial(tabuleiro, linhas, colunas, flags, numFlags);
    troca++;

    imprimirTabuleiro(tabuleiro, linhas , colunas);

    while(P->prox) {
        noRemovido = removeNo(P);

        for(int i = 0; i < linhas; i++) {
            for(int j = 0; j < colunas; j++) {
                if(*(noRemovido->flag) != tabuleiro[i][j] && 
                *(noRemovido->flag) == k &&
                ((noRemovido->x == i-1 && noRemovido->y == j) || 
                (noRemovido->y == j-1 && noRemovido->x == i))) 
                {   
                    tabuleiro[i][j] = *(noRemovido->flag);
                    inserirBandeira(P, &tabuleiro[i][j], i, j);
                    imprimirTabuleiro(tabuleiro, linhas, colunas);
                }
            }
        }
        if(!P->prox) {
            if(!verificarTabuleiro(tabuleiro, linhas, colunas)) {
                k = mudarBandeiraInicial(tabuleiro, linhas, colunas, flags, numFlags);
                troca++;
                inserirBandeira(P, &tabuleiro[0][0], 0, 0);
            }
        }
    }
    printf("%d\n", troca);
}

