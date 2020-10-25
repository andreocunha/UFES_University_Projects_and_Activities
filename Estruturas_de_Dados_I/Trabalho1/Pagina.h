#ifndef PAGINA_H
#define PAGINA_H


typedef struct pagina Pagina;

Pagina* InicializaPagina (char* nome);
void ImprimePagina(Pagina* pag);
char* RetornaNomePagina(Pagina* pag);
void DestroiPagina(Pagina* pag);


#endif /*PAGINA_H*/

