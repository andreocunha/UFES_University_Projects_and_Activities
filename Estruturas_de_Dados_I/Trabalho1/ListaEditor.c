#include "ListaEditor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct celulaEditor
{
    Editor* ed;
    CelulaEditor* prox;
    ListaContribuicao* contrib;
};


struct listaEditor
{
    CelulaEditor* prim;
    CelulaEditor* ult;
};

ListaEditor* InicializaListaEditor (void)
{
    ListaEditor* lista = (ListaEditor*)malloc(sizeof(ListaEditor));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void InsereListaEditor(ListaEditor* lista, Editor* ed)
{
    CelulaEditor* nova = (CelulaEditor*)malloc(sizeof(CelulaEditor));
    nova->contrib = InicializaListaContribuicao(); // cria uma lista vazia
    nova->ed = ed;
    nova->prox = NULL;

    if(lista->prim == NULL && lista->ult == NULL)
    {
        lista->prim = nova;
        lista->ult = nova;
    }
    else
    {
        lista->ult->prox = nova;
        lista->ult = nova; 
    }

}


Editor* RetornaEditor(ListaEditor* lista ,char* chave)
{
    CelulaEditor* p = lista->prim;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomeEditor (p->ed), chave)== 0)
        {
            return p->ed;
        }
    }
    return NULL;
}



void RemoveListaEditor(ListaEditor* lista, char* chave)
{
    CelulaEditor* p = lista->prim;
    CelulaEditor* ant = NULL;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomeEditor (p->ed), chave)== 0)
        {
            break;
        }
        ant = p;
    }

    if(p == NULL)
    {
        return;
    }

    // se for o unico
    if(p == lista->prim && p == lista->ult)
    {
        lista->prim = lista->ult = NULL;
    }
    else if (p == lista->prim) // se for o primeiro da lista
    {
        lista->prim = p->prox;
    }
    else if (p == lista->ult) // se for o ultim da lista
    {
        lista->ult = ant;
        lista->ult->prox = NULL;
    }
    else // caso comum
    {
        ant->prox = p->prox;
    }
    
    DestroiEditor(p->ed);
    free(p);

}

static CelulaEditor* RetornaCelulaEditor(ListaEditor* lista ,char* chave)
{
    CelulaEditor* p = lista->prim;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomeEditor (p->ed), chave)== 0)
        {
            return p;
        }
    }
    return NULL;
}

void InsereContribuicaoListaEditor(ListaEditor* lista, Contribuicao* contrib, char* chave)
{
    CelulaEditor* p = RetornaCelulaEditor(lista, chave);
    if(p == NULL){
        printf("Esse editor nao existe...\n");
        return;
    }
    InsereListaContribuicao(p->contrib, contrib, p->ed);
}

void ImprimeListaEditor(ListaEditor* lista)
{
    CelulaEditor* p;

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        ImprimeEditor(p->ed);
    }
}

void DestroiListaEditor(ListaEditor* lista)
{
    CelulaEditor* p = lista->prim;
    CelulaEditor* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        DestroiEditor(temp->ed);
        free(temp->contrib);
        free(temp);
    }
    free(lista);
}

