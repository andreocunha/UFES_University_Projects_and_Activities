#ifndef PAGINA_H
#define PAGINA_H

#include "ListaContribuicao.h"

typedef struct pagina Pagina;

Pagina* InicializaPagina (char* nome);
void ImprimePagina(Pagina* pag);
char* RetornaNomePagina(Pagina* pag);
ListaContribuicao* RetornaContribuicaoPagina(Pagina* pag);
void DestroiPagina(Pagina* pag);


#endif /*PAGINA_H*/

