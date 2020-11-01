/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * TAD Historico
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "Historico.h"


struct historico 
{
    char* nomeEditor;
    char* arquivo;
};



Historico* InicializaHistorico (char* nomeEditor, char* arquivo) 
{
    Historico* historico = (Historico*)malloc(sizeof(Historico));

    int n = strlen(nomeEditor) + 1;
    char *editor_nome = malloc(n);
    if(editor_nome)
    {
        strcpy(editor_nome, nomeEditor);
    }

    n = strlen(arquivo) + 1;
    char *arquivo_nome = malloc(n);
    if(arquivo_nome)
    {
        strcpy(arquivo_nome, arquivo);
    }

    historico->nomeEditor = editor_nome;
    historico->arquivo = arquivo_nome;
    
    return historico;
}

void ImprimeHistorico(Historico* hist, FILE* arq)
{
    printf("%s %s\n", hist->nomeEditor, hist->arquivo);
    fprintf(arq, "%s %s\n", hist->nomeEditor, hist->arquivo);
}

void DestroiHistorico(Historico* hist){
    free(hist->nomeEditor);
    free(hist->arquivo);
    free(hist);
}
