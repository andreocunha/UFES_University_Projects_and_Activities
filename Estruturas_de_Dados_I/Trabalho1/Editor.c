/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * TAD Editor
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "Editor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct editor 
{
    char* nome;
    ListaContribuicao* contrib;
};



Editor* InicializaEditor (char* nome) 
{
    Editor* editor = (Editor*)malloc(sizeof(Editor));
    
    editor->contrib = InicializaListaContribuicao(); // cria uma lista vazia

    int n = strlen(nome) + 1;
    char *editor_nome = malloc(n);
    if(editor_nome)
    {
        strcpy(editor_nome, nome);
    }

    editor->nome = editor_nome;
    return editor;
}

void ImprimeEditor(Editor* ed)
{
    printf("%s\n", ed->nome);
}

void InsereContribuicaoEditor(Editor* ed, Contribuicao* contrib)
{
    InsereListaContribuicao(ed->contrib, contrib);
}


char* RetornaNomeEditor(Editor* ed){
    return ed->nome;
}

void DestroiEditor(Editor* ed){
    free(ed->nome);
    free(ed->contrib);
    free(ed);
}
