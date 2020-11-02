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
    char statusRetirado;
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
    historico->statusRetirado = 'n';
    
    return historico;
}

void AlteraStatusHistorico(Historico* hist)
{
    hist->statusRetirado = 's';
}

char RetornaStatusHistorico(Historico* hist)
{
    return hist->statusRetirado;
}

char* RetornaNomeEditorHistorico(Historico* hist)
{
    return hist->nomeEditor;
}

void ImprimeHistorico(Historico* hist, FILE* arq)
{
    if(hist->statusRetirado == 's')
    {
        printf("%s %s <<retirada>>\n", hist->nomeEditor, hist->arquivo);
        fprintf(arq, "%s %s <<retirada>>\n", hist->nomeEditor, hist->arquivo);
    }
    else
    {
        printf("%s %s\n", hist->nomeEditor, hist->arquivo);
        fprintf(arq, "%s %s\n", hist->nomeEditor, hist->arquivo);
    }
}

void DestroiHistorico(Historico* hist){
    free(hist->nomeEditor);
    free(hist->arquivo);
    free(hist);
}
