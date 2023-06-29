#ifndef INCLUDED_FUNCOES_H
#define INCLUDED_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct pilha{
    int flag;
    struct pilha *prox;
}Pilha;

/*
Função: criarNo
Descrição:
    Aloca dinamicamente um espaço na memória armazenado o valor passado como parâmetro.
Entrada:
    int info: O valor que o a banderia armazenará
Saída:
    Fila*: A banderia já alocada, e armazenando seu respectivo valor.
*/
Pilha* criarNo(int info);


/*
Função: inserirNaPilha
Descrição:
    Aloca dinamicamente um nó com o valor passado, e insere o mesmo na pilha.
Entrada:
    Pilha *P: Pilha onde será inserido o nó.
    int info: O valor que o nó armazenará.
Saída:
    Pilha*: Pilha com o nó inserido.
*/
Pilha* inserirNaPilha(Pilha *P, int info);

/*
Função: imprimirPilha
Descrição:
    Imprime a pilha passada com entrada.
Entrada:
    Pilha *P: A pilha que será impressa.
Saída:
    void
*/
void imprimirPilha(Pilha *P);

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
int menorRepeticao(Pilha *P, int *flags, int numFlags);

/*
    Função juscelino será resposável por executar o objetivo que o trabalho propõe
    ele executará outras funções implementadas, para chegar no objetivo do desafio.
    A mesma se encontra em desenvolvimento.
*/
int juscelino(Pilha *P, int *bandeiras);

#endif