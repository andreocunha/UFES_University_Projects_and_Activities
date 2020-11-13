#ifndef ListaLink_h
#define ListaLink_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"

typedef struct celulaLink CelulaLink;
typedef struct listaLink ListaLink;

#include "ListaPagina.h"

ListaLink* InicializaListaLink (void);

void InsereListaLink(ListaLink* lista, Pagina* pag);

void RemoveListaLink(ListaLink* lista, char* chave);

void ImprimeListaLink(ListaLink* lista, FILE* arq);

Pagina* RetornaPaginaListaLink(ListaLink* lista, char* chave);

void listaTodosCaminhosPossiveis(Pagina* pag, ListaLink* visited, ListaPagina* listaPag);

void DestroiListaLink(ListaLink* lista);


#endif /* ListaLink_h */