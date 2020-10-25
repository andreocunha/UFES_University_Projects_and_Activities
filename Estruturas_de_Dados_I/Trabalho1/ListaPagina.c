#include "ListaPagina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct celulaPagina
{
    Pagina* pag;
    CelulaPagina* prox;
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

    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL)
    {
        lista->ult = nova;
    }

}


Pagina* RemoveListaPagina(ListaPagina* lista, char* chave)
{
    CelulaPagina* p = lista->prim;
    Pagina* pag;
    CelulaPagina* ant = NULL;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomePagina (p->pag), chave)== 0)
        {
            break;
        }
        ant = p;
    }

    // Atribui a Pagina de retorno
    pag = p->pag;

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

    return pag;
}

void ImprimeListaPagina(ListaPagina* lista)
{
    CelulaPagina* p;

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        ImprimePagina(p->pag);
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
        free(temp);
    }
    free(lista);
}

