#ifndef ListaHistorico_h
#define ListaHistorico_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Historico.h"

typedef struct celulaHistorico CelulaHistorico;
typedef struct listaHistorico ListaHistorico;

ListaHistorico* InicializaListaHistorico (void);

void InsereListaHistorico(ListaHistorico* lista, Historico* hist);

void ImprimeListaHistorico(ListaHistorico* lista, FILE* arq);

Historico* RetornaHistorico(ListaHistorico* lista, char* chave);

void DestroiListaHistorico(ListaHistorico* lista);


#endif /* ListaHistorico_h */