#ifndef ListaPagina_h
#define ListaPagina_h

typedef struct celulaPagina CelulaPagina;
typedef struct listaPagina ListaPagina;

#include "Pagina.h"
#include "ListaContribuicao.h"
#include "ListaLink.h"

ListaPagina* InicializaListaPagina (void);

void InsereListaPagina(ListaPagina* lista, Pagina* pag);

void RemoveListaPagina(ListaPagina* lista, char* chave);

ListaContribuicao* RetornaListaContribuicaoPagina(ListaPagina* lista, char* chave);

ListaLink* RetornaListaLinkPagina(ListaPagina* lista, char* chave);

void ImprimeListaPagina(ListaPagina* lista);

void DestroiListaPagina(ListaPagina* lista);


#endif /* ListaPagina_h */