#ifndef LISTAGENERICA_H_
#define LISTAGENERICA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct listagenerica ListaGenerica;

ListaGenerica *criaLista();
ListaGenerica *insereLista(ListaGenerica *lista, void *item);
ListaGenerica *retiraLista(ListaGenerica *lista, int (*cb)(void *, void *), void *chave);
int percorreLista(ListaGenerica *lista, int (*cb)(void *, void *), void *dado);
void liberaLista(ListaGenerica *lista);

#endif /* LISTAGENERICA_H_ */