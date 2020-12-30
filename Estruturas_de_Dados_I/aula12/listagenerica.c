#include "listagenerica.h"

struct listagenerica
{
    void *item;
    ListaGenerica *prox;
};

ListaGenerica *criaLista()
{
    return NULL;
}

ListaGenerica *insereLista(ListaGenerica *lista, void *item)
{
    ListaGenerica *nova = (ListaGenerica *)malloc(sizeof(ListaGenerica));
    nova->item = item;
    nova->prox = lista;

    return nova;
}
ListaGenerica *retiraLista(ListaGenerica *lista, int (*cb)(void *, void *), void *chave)
{
    ListaGenerica *p = lista;
    ListaGenerica *ant = NULL;

    while (p != NULL && cb(p->item, chave))
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
    {
        return lista;
    }

    if (ant == NULL)
    {
        lista = lista->prox;
    }
    else
    {
        ant->prox = p->prox;
    }

    free(p);
    return lista;
}

int percorreLista(ListaGenerica *lista, int (*cb)(void *, void *), void *dado)
{
    ListaGenerica *p;

    for (p = lista; p != NULL; p = p->prox)
    {
        int r = cb(p->item, dado);
        if (r == 0)
        {
            return r;
        }
    }
    return 1;
}
void liberaLista(ListaGenerica *lista)
{
    ListaGenerica *p = lista;
    ListaGenerica *t;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }
}