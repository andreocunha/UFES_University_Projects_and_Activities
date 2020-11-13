#ifndef ListaPagina_h
#define ListaPagina_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"
#include "ListaContribuicao.h"


typedef struct celulaPagina CelulaPagina;
typedef struct listaPagina ListaPagina;

#include "ListaLink.h"

ListaPagina* InicializaListaPagina (void);

void InsereListaPagina(ListaPagina* lista, Pagina* pag);

void RemoveListaPagina(ListaPagina* lista, char* chave, FILE* log);

Pagina* RetornaPagina(ListaPagina* lista, char* chave);

ListaContribuicao* RetornaListaContribuicaoPagina(ListaPagina* lista, char* chave);

ListaLink* RetornaListaLinkPagina(ListaPagina* lista, char* chave);

void RemoveLinkListaLinkListaPagina(ListaPagina* lista, char* chave);

void ImprimeListaPagina(ListaPagina* lista);

void ImprimeUnicaPaginaLista(ListaPagina* lista, Pagina* pag);

void DestroiListaPagina(ListaPagina* lista);


#endif /* ListaPagina_h */