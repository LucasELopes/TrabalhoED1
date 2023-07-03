#ifndef INCLUDED_FUNCOES_H
#define INCLUDED_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No{
    int* flag;
    int x, y;
    struct No *prox;
}No;

/*
Função: criarNo
Descrição:
    Aloca dinamicamente um espaço na memória armazenado o valor passado como parâmetro.
Entrada:
    int info: O valor que o a banderia armazenará
Saída:
    Fila*: A banderia já alocada, e armazenando seu respectivo valor.
*/
No* criarNo(int *info, int x, int y);

int** criarTabuleiro(int linhas, int colunas);

/*
Função: inserirBandeira
Descrição:
    Aloca dinamicamente um nó com o valor passado, e insere o mesmo na pilha.
Entrada:
    Pilha *P: Pilha onde será inserido o nó.
    int info: O valor que o nó armazenará.
Saída:
    Pilha*: Pilha com o nó inserido.
*/
void inserirBandeira(No *P, int *info, int x, int y);

void inserirNo(No *P, No *novoNo);

No* removeNo(No *P);

/*
Função: imprimirPilha
Descrição:
    Imprime a pilha passada com entrada, no formato de uma matriz.
Entrada:
    Pilha *P: A pilha que será impressa.
    int colunas: O número que colunas presentes na matriz.
Saída:
    void
*/
void imprimirTabuleiro(int **tabuleiro, int linhas, int colunas);

void imprimirPilha(No *P, int colunas);

/*
Função: menorRepeticao
Descrição:
    retorna o inteiro que menos se repetiu na pilha.
Entrada:
    Pilha *P: A pilha que será feita a busca do inteiro.
    int *flags: Um vetor com as bandeiras que a pilha possui.
    int numFlags: O tamanho do vetor *flags.
Saída:
   int: O inteiro que menos repetiu-se na pilha.
*/

// int menorRepeticao(No *P, int *flags, int numFlags);
int menorRepeticao(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags);


// void mudarBandeiraInicial(int **tabueleiro, int *flags, int numFlags);
void mudarBandeiraInicial(int **tabueleiro, int linhas, int colunas, int *flags, int numFlags);

int mudarAdjacente(No *P, int **tabuleiro, int linhas, int colunas, int *flag, int numFlags);

//Funcao certa
// void mudarAdjacente(No *P, No *flag);

/*
    Função juscelino será resposável por executar o objetivo que o trabalho propõe
    ele executará outras funções implementadas, para chegar no objetivo do desafio.
    A mesma se encontra em desenvolvimento.
*/
void juscelino(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags);

#endif