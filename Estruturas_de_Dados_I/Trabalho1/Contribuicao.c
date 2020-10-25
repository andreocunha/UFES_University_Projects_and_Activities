/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * TAD Contribuicao
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "Contribuicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct contribuicao 
{
    char* texto;
};

Contribuicao* InicializaContribuicao (char* texto) 
{
    Contribuicao* contrib = (Contribuicao*)malloc(sizeof(Contribuicao));

    int n = strlen(texto) + 1;
    char *contribuicao_texto = malloc(n);
    if(contribuicao_texto)
    {
        strcpy(contribuicao_texto, texto);
    }

    contrib->texto = contribuicao_texto;
    return contrib;
}

void ImprimeContribuicao(Contribuicao* contrib)
{
    printf("%s\n", contrib->texto);
}


char* RetornaTextoContribuicao(Contribuicao* contrib){
    return contrib->texto;
}

void DestroiContribuicao(Contribuicao* contrib){
    free(contrib->texto);
    free(contrib);
}
