#include "ListaPagina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct celulaPagina
{
    Pagina* pag;
    CelulaPagina* prox;
    ListaContribuicao* contrib;
    ListaLink* link;
};


struct listaPagina
{
    CelulaPagina* prim;
    CelulaPagina* ult;
};

ListaPagina* InicializaListaPagina (void)
{
    ListaPagina* lista = (ListaPagina*)malloc(sizeof(ListaPagina));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void InsereListaPagina(ListaPagina* lista, Pagina* pag)
{
    CelulaPagina* nova = (CelulaPagina*)malloc(sizeof(CelulaPagina));
    nova->pag = pag;
    nova->prox = NULL;

    nova->contrib = InicializaListaContribuicao();
    nova->link = InicializaListaLink();

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


void RemoveListaPagina(ListaPagina* lista, char* chave)
{
    CelulaPagina* p;
    CelulaPagina* ant = NULL;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomePagina(p->pag), chave)== 0)
        {
            break;
        }
        ant = p;
    }

    if(p == NULL)
    {
        printf("ERRO: não existe a pagina %s\n", chave);
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

    DestroiListaContribuicao(p->contrib);
    DestroiListaLink(p->link);
    DestroiPagina(p->pag);
    free(p); 
    
}

static CelulaPagina* RetornaCelulaPagina(ListaPagina* lista ,char* chave)
{
    CelulaPagina* p = lista->prim;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomePagina (p->pag), chave)== 0)
        {
            return p;
        }
    }
    return NULL;
}

Pagina* RetornaPagina(ListaPagina* lista, char* chave)
{
    CelulaPagina* pag = RetornaCelulaPagina(lista, chave);
    return pag->pag;
}

ListaContribuicao* RetornaListaContribuicaoPagina(ListaPagina* lista, char* chave)
{
    CelulaPagina* pag = RetornaCelulaPagina(lista, chave);
    return pag->contrib;
}

ListaLink* RetornaListaLinkPagina(ListaPagina* lista, char* chave)
{
    CelulaPagina* pag = RetornaCelulaPagina(lista, chave);
    return pag->link;
}

void ImprimeListaPagina(ListaPagina* lista)
{
    CelulaPagina* p;

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        ImprimePagina(p->pag);
        ImprimeListaContribuicao(p->contrib);
        ImprimeListaLink(p->link);

        printf("\n");
    }
}

void DestroiListaPagina(ListaPagina* lista)
{
    CelulaPagina* p = lista->prim;
    CelulaPagina* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        DestroiPagina(temp->pag);
        DestroiListaContribuicao(temp->contrib);
        DestroiListaLink(temp->link);
        free(temp);
    }
    free(lista);
}

