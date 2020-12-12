#ifndef Fila_h
#define Fila_h

#include <stdio.h>
#include "Aluno.h"

typedef struct fila Fila;

Fila *inicFila(void);

//insere fila (sempre no final da fila)
void insereFila(Fila *f, Aluno *al);

// retira fila (sempre no inicio)
Aluno *retiraFila(Fila *f);

//Imprime do inicio ao fim da fila
void imprimeFila(Fila *f);

//libera memoria da fila (e nao dos alunos)
void destroiFila(Fila *f);

#endif