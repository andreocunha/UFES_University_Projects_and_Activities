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
    char statusRetirado;
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
    contrib->statusRetirado = 'n';
    return contrib;
}

void ImprimeContribuicao(Contribuicao* contrib, FILE* arq)
{
    if(contrib->statusRetirado == 'n')
    {
        printf("%s\n", contrib->texto);
        fprintf(arq, "%s\n", contrib->texto);
    }    
}

void ImprimeHistoricoContribuicao(Contribuicao* contrib, char* editor, FILE* arq)
{
    if(contrib->statusRetirado == 'n')
    {
        printf("%s %s\n", editor, contrib->arquivo);
        fprintf(arq, "%s %s\n", editor, contrib->arquivo);
    }
    else if(contrib->statusRetirado == 's')
    {
        printf("%s %s <<retirada>>\n", editor, contrib->arquivo);
        fprintf(arq, "%s %s <<retirada>>\n", editor, contrib->arquivo);
    }
}

void AlteraStatusContribuicao(Contribuicao* contrib)
{
    contrib->statusRetirado = 's';
}

char RetornaStatusContribuicao(Contribuicao* contrib)
{
    return contrib->statusRetirado;
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
