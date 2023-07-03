#include "funcoes.h"


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