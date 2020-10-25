#ifndef ListaLink_h
#define ListaLink_h

typedef struct celulaLink CelulaLink;
typedef struct listaLink ListaLink;

#include "Pagina.h"

ListaLink* InicializaListaLink (void);

void InsereListaLink(ListaLink* lista, Pagina* pag);

Pagina* RemoveListaLink(ListaLink* lista, char* chave);

void ImprimeListaLink(ListaLink* lista);

void DestroiListaLink(ListaLink* lista);


#endif /* ListaLink_h */