#ifndef INCLUDED_FUNCOES_H
#define INCLUDED_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct bandeira {
    int info;
    struct bandeira *dir, *esq;
}Bandeira;

typedef struct pilha{
    struct bandeira *prox;
}Pilha;

/*
Função: criarBandeira
Descrição:
    Aloca dinamicamente um espaço na memória armazenado o valor passado como parâmetro.
Entrada:
    int info: O valor que o a banderia armazenará
Saída:
    Fila*: A banderia já alocada, e armazenando seu respectivo valor.
*/
Bandeira* criaBandeira(int info);

/*
Função: inserirBandeira
Descrição:
    Aloca dinamicamente um espaço na memória armazenado o valor passado como parâmetro.
Entrada:
    Bandeira *A: A árvore na qual será inserido uma bandeira.
    int info: O valor que o a banderia armazenará.
Saída:
    void
*/
void inserirBandeira(Bandeira *A, int info);

/*
Função: imprimirTabuleiro
Descrição:
    Aloca dinamicamente um espaço na memória armazenado o valor passado como parâmetro.
Entrada:
    Bandeira *A: A árvore na qual será inserido uma bandeira.
    int info: O valor que o a banderia armazenará.
Saída:
    void
*/
void imprimirTabuleiro(Bandeira *A);

#endif