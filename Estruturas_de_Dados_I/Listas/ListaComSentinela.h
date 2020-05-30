#ifndef ListaComSentinela_h
#define ListaComSentinela_h


#include <stdio.h>
#include "Aluno.h"

typedef struct lista Lista;

Lista* InicLista();

void InsereLista(Lista* l, Aluno* aluno);

void ImprimeLista(Lista* l);

Aluno* RetiraLista(Lista* l, char* chave);

void DestroiLista(Lista* l);

#endif
