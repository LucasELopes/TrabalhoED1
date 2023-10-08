#include "funcoes.h"


int main() {
    NoPilha *P = criarNo((int*)-1, -1, -1);

    int linhas, colunas, numFlags;
    int** tabuleiro;
    scanf("%d %d", &linhas, &colunas);
    scanf("%d", &numFlags);

    int flags[numFlags];
    for(int i = 0; i < numFlags; i++)
        flags[i] = i;

    tabuleiro = criarTabuleiro(linhas, colunas);
    imprimirTabuleiro(tabuleiro, linhas, colunas);

    // printf("Mais se repetiu: %d\n", repeticao(tabuleiro, linhas, colunas, flags, numFlags, 0));
    // printf("Menos se repetiu: %d\n", repeticao(tabuleiro, linhas, colunas, flags, numFlags, -1));

    mudarAdjacente(tabuleiro, linhas, colunas, flags, numFlags); 

}