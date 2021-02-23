#include "listacircular.h"

struct cel
{
    int num;
     Celula* prox;
};


struct listacircular
{
    Celula* prim;
};


Listacircular* inicializaLista (void)
{
    Listacircular* lista = (Listacircular*)malloc(sizeof(Listacircular));
    lista->prim = NULL;
    return lista;
}

static Celula* encontraUltimoLista(Listacircular* lista){
    Celula* anterior = lista->prim;
    Celula* temp = lista->prim->prox;

    while (temp != lista->prim)
    {
        anterior = temp;
        temp = temp->prox;
    }
    return anterior;
}

void insereLista(Listacircular* lista, int num)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->num = num;

    if(lista->prim == NULL)
    {
        lista->prim = nova;
        nova->prox = nova;
    }
    else
    {
        Celula* ultima = encontraUltimoLista(lista);
        ultima->prox = nova;
        nova->prox = lista->prim;
    }
}

void imprimeLista(Listacircular* lista)
{
    Celula* temp = lista->prim;

    do
    {
        printf("%d ", temp->num);
        temp = temp->prox;
    } while (temp != lista->prim);
    
    printf("\n");
}

int encontraLider(Listacircular* lista, int num)
{
    Celula* ant = lista->prim;
    Celula* atual = lista->prim;

    do
    {
        for(int i = 1; i< num; i++)
        {
            ant = atual;
            atual = atual->prox;
        }
        if(ant != atual){
            Celula* temp = atual;
            atual = atual->prox;
            lista->prim = atual;
            ant->prox = atual;
            // printf("%d ", temp->num);
            free(temp);
        }
    }while (ant != atual);

    printf("\n");
    return atual->num;
}

void destroiLista(Listacircular* lista)
{

    if(lista->prim == lista->prim->prox)
    {
        free(lista->prim);
        free(lista);
        return;
    }

    Celula* temp = lista->prim;

    do
    {
        Celula* liberar = temp;
        temp = temp->prox;
        free(liberar);
    } while (temp != lista->prim);

    free(lista);    
}