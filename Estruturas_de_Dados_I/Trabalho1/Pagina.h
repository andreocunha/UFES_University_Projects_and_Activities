#ifndef PAGINA_H
#define PAGINA_H

typedef struct pagina Pagina;

#include "ListaContribuicao.h"
#include "ListaLink.h"

Pagina* InicializaPagina (char* nome);
void ImprimePagina(Pagina* pag);
char* RetornaNomePagina(Pagina* pag);
ListaContribuicao* RetornaContribuicaoPagina(Pagina* pag);
ListaLink* RetornaLinkPagina(Pagina* pag);
void DestroiPagina(Pagina* pag);


#endif /*PAGINA_H*/

