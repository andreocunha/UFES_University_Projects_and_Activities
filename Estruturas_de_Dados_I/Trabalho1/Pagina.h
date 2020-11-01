#ifndef PAGINA_H
#define PAGINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pagina Pagina;

Pagina* InicializaPagina (char* nome, char* arquivo);
void ImprimePagina(Pagina* pag, FILE *arq);
char* RetornaNomePagina(Pagina* pag);
char* RetornaNomeArquivo(Pagina* pag);
void DestroiPagina(Pagina* pag);


#endif /*PAGINA_H*/

