#ifndef PilhaDupla_h
#define PilhaDupla_h

#include <stdio.h>
#include "Aluno.h"

typedef struct pilha Pilha;

//Inicializa a estrutura da pilha
Pilha* inicPilha (void);

//inclui no topo da pilha 1
void pushPilha1(Pilha* p, Aluno* al);

//inclui no topo da pilha 2
void pushPilha2(Pilha *p, Aluno *al);

//retira do top da pilha 1
Aluno *popPilha1(Pilha *p);

//retira do top da pilha 2
Aluno *popPilha2(Pilha *p);

//imprime do topo para a base da pilha 1
void imprimePilha1(Pilha *p);

//imprime do topo para a base da pilha 2
void imprimePilha2(Pilha *p);

//Destroi a pilha para não os alunos...
void destroi (Pilha* p);

#endif /* PilhaDupla_h */