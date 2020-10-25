#include "ListaLink.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct celulaLink
{
    Pagina* pag;
    CelulaLink* prox;
};


struct listaLink
{
    CelulaLink* prim;
    CelulaLink* ult;
};

ListaLink* InicializaListaLink (void)
{
    ListaLink* lista = (ListaLink*)malloc(sizeof(ListaLink));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void InsereListaLink(ListaLink* lista, Pagina* pag)
{
    CelulaLink* nova = (CelulaLink*)malloc(sizeof(CelulaLink));
    nova->pag = pag;
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


Pagina* RemoveListaLink(ListaLink* lista, char* chave)
{
    CelulaLink* p = lista->prim;
    Pagina* pag;
    CelulaLink* ant = NULL;

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

void ImprimeListaLink(ListaLink* lista)
{
    CelulaLink* p;

    printf("Links:\n");

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        printf("%s\n", RetornaNomePagina(p->pag));
    }
}

void DestroiListaLink(ListaLink* lista)
{
    CelulaLink* p = lista->prim;
    CelulaLink* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        free(temp);
    }
    free(lista);
}

