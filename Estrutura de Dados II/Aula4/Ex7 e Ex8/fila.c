#include "fila.h"

struct cel
{
    Arv* no;
    Cel* prox;
};


struct fila
{ 
    Cel* prim;
    Cel* ult;
};

Fila* cria_fila()
{
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->prim = NULL;
    fila->ult = NULL;
    return fila;
}

void enqueue(Fila* fila, Arv* arv)
{
    Cel *nova = (Cel *)malloc(sizeof(Cel));
    nova->no = arv;
    nova->prox = NULL;

    if (fila->prim == NULL)
    {
        fila->prim = fila->ult = nova;
        return;
    }
    fila->ult->prox = nova;
    fila->ult = nova;
}

Arv* dequeue(Fila *fila)
{
    if(fila->ult == NULL){ return NULL; }

    Cel *auxiliar = fila->prim;
    
    fila->prim = auxiliar->prox;
    Arv* arv = auxiliar->no;

    free(auxiliar);

    return arv;

}

void imprime_fila(Fila* fila)
{
    Cel *auxiliar;
    if (fila == NULL)
    {
        printf("Fila vazia");
        return;
    }
    for (auxiliar = fila->prim; auxiliar != NULL; auxiliar = auxiliar->prox)
    {
        bst_imprime_no(auxiliar->no);
    }
}

void destroi_fila(Fila* fila)
{
    Cel *p = fila->prim;
    Cel *t = NULL;

    while (p != NULL)
    {
        t = p->prox;
        if (p->no != NULL)
        {
            free(p);
        }
        p = t;
    }
    free(fila);
}
