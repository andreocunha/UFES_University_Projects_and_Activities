/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * TAD Contribuicao
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "Contribuicao.h"


struct contribuicao 
{
    char* texto;
    char* arquivo;
};

Contribuicao* InicializaContribuicao (char* texto, char* arq) 
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
    return contrib;
}

void ImprimeContribuicao(Contribuicao* contrib, FILE* arq)
{
    printf("%s\n", contrib->texto);
    fprintf(arq, "%s\n", contrib->texto);
}


char* RetornaTextoContribuicao(Contribuicao* contrib){
    return contrib->texto;
}

char* RetornaArquivoContribuicao(Contribuicao* contrib){
    return contrib->arquivo;
}

void DestroiContribuicao(Contribuicao* contrib){

    if(contrib != NULL)
    {
        free(contrib->texto);
        free(contrib->arquivo);
        free(contrib);
    }
    
}
