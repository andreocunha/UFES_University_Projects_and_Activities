/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * TAD PAGINA
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "Pagina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pagina 
{
    char* nome;
};


Pagina* InicializaPagina (char* nome) 
{
    Pagina* pagina = (Pagina*)malloc(sizeof(Pagina));

    int n = strlen(nome) + 1;
    char *pagina_nome = malloc(n);
    if(pagina_nome)
    {
        strcpy(pagina_nome, nome);
    }

    pagina->nome = pagina_nome;
    return pagina;
}

void ImprimePagina(Pagina* pag)
{
    printf("%s\n", pag->nome);
}


char* RetornaNomePagina(Pagina* pag){
    return pag->nome;
}

void DestroiPagina(Pagina* pag){
    free(pag->nome);
    free(pag);
}
