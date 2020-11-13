/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * TAD PAGINA
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "Pagina.h"


struct pagina 
{
    char* nome;
    char* arquivo;
};


Pagina* InicializaPagina (char* nome, char* arquivo) 
{
    Pagina* pagina = (Pagina*)malloc(sizeof(Pagina));

    int n = strlen(nome) + 1;
    char* pagina_nome = malloc(n);
    if(pagina_nome)
    {
        strcpy(pagina_nome, nome);
    }
    pagina->nome = pagina_nome;

    n = strlen(arquivo) + 1;
    char* arquivo_nome = malloc(n);
    if(arquivo_nome)
    {
        strcpy(arquivo_nome, arquivo);
    }
    pagina->arquivo = arquivo_nome;

    return pagina;
}

void ImprimePagina(Pagina* pag, FILE *arq)
{
    printf("%s\n\n", pag->nome);
    fprintf(arq,"%s\n\n", pag->nome);
}


char* RetornaNomePagina(Pagina* pag){
    return pag->nome;
}

char* RetornaNomeArquivo(Pagina* pag){
    return pag->arquivo;
}

void DestroiPagina(Pagina* pag){
    free(pag->nome);
    free(pag->arquivo);
    free(pag);
}
