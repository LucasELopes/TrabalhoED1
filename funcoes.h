#ifndef INCLUDED_FUNCOES_H
#define INCLUDED_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NoPilha{
    int* flag;
    int x, y;
    struct NoPilha *prox;
}NoPilha;

typedef struct noFila
{
    int x, y;
    struct noFila *prox, *ant;    
}NoFila;

/*
Função: criarNo
Descrição:
    Aloca dinamicamente um espaço na memória armazenado o valor passado como parâmetro.
Entrada:
    int info: O valor que o a banderia armazenará
Saída:
    No*: O nó alocado dinamicamente.
*/
NoPilha* criarNo(int *info, int x, int y);

/*
Função: criarTabuleiro
Descrição:
    Cria uma tabuleiro com base nas entradas do usuário.
Entrada:
    int linhas: O número de linhas do tabuleiro.
    int colunas: O número de colunas do tabuleiro.
Saída:
    int**: O tabuleiro criado.
*/
int** criarTabuleiro(int linhas, int colunas);

/*
Função: inserirBandeira
Descrição:
    Aloca dinamicamente um nó com o valor passado, e insere o mesmo na pilha.
Entrada:
    Pilha *P: Pilha onde será inserido o nó.
    int info: O valor que o nó armazenará.
    int x: O valor da coordenada X.
    int Y: O valor da coordenada Y.
Saída:
    void
*/
void inserirBandeira(NoPilha *P, int *info, int x, int y);

/*
Função: inserirNo
Descrição:
    Insere um nó já alocado na pilha.
Entrada:
    Pilha *P: Pilha onde será inserido o nó.
    No *novoNo: insere o Nó já alocado na pilha.
Saída:
    void
*/
void inserirNo(NoPilha *P, NoPilha *novoNo);

/*
Função: removeNo
Descrição:
    Remove o último nó inserido na pilha.
Entrada:
    Pilha *P: Pilha onde será removido o nó.
Saída:
    No*: nó removido.
*/
NoPilha* removeNo(NoPilha *P);

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

void imprimirPilha(NoPilha *P, int colunas);

/*
Função: repeticao
Descrição:
    retorna o inteiro que menos se repetiu na pilha.
Entrada:
    int **tabuleiro: O tabuleiro onde será procurado o elemento que menos se repetiu.
    int linhas: As quatidades de linhas do tabuleiro
    int colunas: As quatidades de colunas do tabuleiro
    int *flags: vetor contendo os tipos de bandeiras presentes no tabuleiro.
    int numFlags: A quantidade de bandeiras.
Saída:
   int: O inteiro que menos repetiu na pilha.
*/
int repeticao(int **tabuleiro, int linhas, int colunas, int *flags, int numFlags, int menorOuMaior);


/*
Função: mudarBandeiraInicial
Descrição:
    retorna o inteiro que menos se repetiu na pilha.
Entrada:
    int **tabuleiro: O tabuleiro onde será modificado a casa de posicao 0,0.
    int linhas: As quatidades de linhas do tabuleiro
    int colunas: As quatidades de colunas do tabuleiro
    int *flags: vetor contendo os tipos de bandeiras presentes no tabuleiro.
    int numFlags: A quantidade de bandeiras.
Saída:
   void
*/
int mudarBandeiraInicial(int **tabueleiro, int linhas, int colunas, int *flags, int numFlags);

/*
Função: mudarAdjacente
Descrição:
    faz a busca em profundidade da matriz, e modifica os elementos.
Entrada:
    int **tabuleiro: O tabuleiro onde será modificado as casas adjacentes.
    int linhas: As quatidades de linhas do tabuleiro
    int colunas: As quatidades de colunas do tabuleiro
    int *flags: vetor contendo os tipos de bandeiras presentes no tabuleiro.
    int numFlags: A quantidade de bandeiras.
Saída:
   void
*/
void mudarAdjacente(int **tabuleiro, int linhas, int colunas, int *flag, int numFlags);

#endif