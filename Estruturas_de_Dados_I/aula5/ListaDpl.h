#ifndef ListaDpl_h
#define ListaDpl_h

#include <stdio.h>
#include "Aluno.h"

typedef struct listadpl ListaDpl;

ListaDpl* InicLista();

ListaDpl* InsereLista (ListaDpl* lista, Aluno* aluno);

ListaDpl* RetiraLista (ListaDpl* lista, char* chave);

void ImprimeLista (ListaDpl* lista);

void DestroiLista(ListaDpl* lista);

#endif /* ListaDpl_h */