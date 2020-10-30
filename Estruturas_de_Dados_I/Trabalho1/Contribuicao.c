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
    char* arquivo;
    Editor* editor;
};

Contribuicao* InicializaContribuicao (char* texto, char* arq, Editor* ed) 
{
    Contribuicao* contrib = (Contribuicao*)malloc(sizeof(Contribuicao));

    int n = strlen(texto) + 1;
    char *contribuicao_texto = malloc(n);
    if(contribuicao_texto)
    {
        strcpy(contribuicao_texto, texto);
    }

    n = strlen(arq) + 1;
    char *contribuicao_arq = malloc(n);
    if(contribuicao_arq)
    {
        strcpy(contribuicao_arq, arq);
    }

    contrib->texto = contribuicao_texto;
    contrib->arquivo = contribuicao_arq;
    contrib->editor = ed;

    return contrib;
}

void ImprimeContribuicao(Contribuicao* contrib)
{
    printf("\n-------- %s (%s) --------\n\n", contrib->arquivo, RetornaNomeEditor(contrib->editor));
    printf("%s\n", contrib->texto);
}


char* RetornaTextoContribuicao(Contribuicao* contrib){
    return contrib->texto;
}

void DestroiContribuicao(Contribuicao* contrib){
    free(contrib->texto);
    free(contrib->arquivo);
    free(contrib);
}
