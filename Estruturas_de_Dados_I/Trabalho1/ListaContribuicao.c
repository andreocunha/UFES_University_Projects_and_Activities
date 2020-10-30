#include "ListaContribuicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct celulaContribuicao
{
    Contribuicao* contrib;
    CelulaContribuicao* prox;
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


void InsereListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib)
{
    CelulaContribuicao* nova = (CelulaContribuicao*)malloc(sizeof(CelulaContribuicao));
    nova->contrib = contrib;
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


Contribuicao* RemoveListaContribuicao(ListaContribuicao* lista, char* chave)
{
    CelulaContribuicao* p = lista->prim;
    Contribuicao* contrib;
    CelulaContribuicao* ant = NULL;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaTextoContribuicao (p->contrib), chave)== 0)
        {
            break;
        }
        ant = p;
    }

    // Atribui a Contribuicao de retorno
    contrib = p->contrib;

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
    
    free(p);

    return contrib;
}

void ImprimeListaContribuicao(ListaContribuicao* lista)
{
    CelulaContribuicao* p;

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        ImprimeContribuicao(p->contrib);
    }
}

void DestroiListaContribuicao(ListaContribuicao* lista)
{
    CelulaContribuicao* p = lista->prim;
    CelulaContribuicao* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        free(temp);
    }
    free(lista);
}

