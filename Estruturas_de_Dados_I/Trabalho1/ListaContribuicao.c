#include "ListaContribuicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct celulaContribuicao
{
    Contribuicao* contrib;
    CelulaContribuicao* prox;
    Editor* editor;
};


struct listaContribuicao
{
    CelulaContribuicao* prim;
    CelulaContribuicao* ult;
};

ListaContribuicao* InicializaListaContribuicao (void)
{
    ListaContribuicao* lista = (ListaContribuicao*)malloc(sizeof(ListaContribuicao));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void InsereListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib, Editor* ed)
{
    CelulaContribuicao* nova = (CelulaContribuicao*)malloc(sizeof(CelulaContribuicao));
    nova->contrib = contrib;
    nova->prox = NULL;
    
    nova->editor = ed;

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


void RemoveListaContribuicao(ListaContribuicao* lista, char* chave)
{
    CelulaContribuicao* p = lista->prim;
    CelulaContribuicao* ant = NULL;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaArquivoContribuicao(p->contrib), chave)== 0)
        {
            break;
        }
        ant = p;
    }

    if(p == NULL)
    {
        printf("ERRO: não existe a contribuicao %s\n", chave);
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
    
    DestroiContribuicao(p->contrib);
    free(p);

}


Contribuicao* RetornaContribuicaoLista(ListaContribuicao* lista, char* chave)
{
    CelulaContribuicao* p = lista->prim;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaArquivoContribuicao (p->contrib), chave)== 0)
        {
            return p->contrib;
        }
    }
    return NULL;
}

void ImprimeListaContribuicao(ListaContribuicao* lista)
{
    CelulaContribuicao* p;
    Editor* ed;

    printf("CONTRIBUICOES: \n");

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        ed = RetornaEditorListaContribuicao(lista, p->contrib);
        printf("\n-------- %s (%s) --------\n\n", RetornaArquivoContribuicao(p->contrib), RetornaNomeEditor(ed));
        ImprimeContribuicao(p->contrib);
    }
}


Editor* RetornaEditorListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib)
{
    CelulaContribuicao* p = lista->prim;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (p->contrib == contrib)
        {
            return p->editor;
        }
    }
    return NULL;
}

void DestroiListaContribuicao(ListaContribuicao* lista)
{
    CelulaContribuicao* p = lista->prim;
    CelulaContribuicao* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        DestroiContribuicao(temp->contrib);
        free(temp);
    }
    free(lista);
}

