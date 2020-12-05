#ifndef FilaComSentinela_h
#define FilaComSentinela_h

#include "Aluno.h"

typedef struct lista Lista;

Lista *InicLista(void);

void InsereLista(Lista * l, Aluno *al);

void InsereListaUlt(Lista * l, Aluno *aluno);

void ImprimeLista(Lista * l);

Aluno *RetiraLista(Lista *l, char* chave);

//Retira de uma determinada posicao da lista
Aluno *RetiraPosicao(Lista * l, int pos);

void DestroiLista(Lista * l);

#endif /* FilaComSentinela_h */