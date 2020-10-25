/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * Aula 4
 *
 * Exercicio 4
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "listaMat.h"
#include <stdio.h>
#include <stdlib.h>

struct  cel
{
    Matriz* mat;
    Celula* prox;
};


struct lista
{
    Celula* prim;
    Celula* ult;
};

Lista* inicializaLista (void)
{
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void insereLista(Lista* lista, Matriz* mat)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->mat = mat;

    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL)
    {
        lista->ult = nova;
    }


}

Matriz* removeLista(Lista* lista, int posicao)
{
    Celula* p = lista->prim;
    Matriz* matriz;
    Celula* ant = NULL;

    //Faz a busca
    for (int i = 0; i < posicao; i++)
    {
        ant = p;
        p = p->prox;
    }

    // Atribui a matriz de retorno
    matriz = p->mat;

    // se for o unico
    if(p == lista->prim && p == lista->ult)
    {
        lista->prim = lista->ult = NULL;
    }
    else if (p == lista->prim) // se for a primeira matriz
    {
        lista->prim = p->prox;
    }
    else if (p == lista->ult) // se for a ultima matriz
    {
        lista->ult = ant;
        lista->ult->prox = NULL;
    }
    else // caso comum
    {
        ant->prox = p->prox;
    }
    
    free(p);

    return matriz;
}

void imprimeLista(Lista* lista)
{
    Celula* p;

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        imprimeMatriz(p->mat);
        printf("\n");
    }
}

void destroiLista(Lista* lista)
{
    Celula* p = lista->prim;
    Celula* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        free(temp);
    }
    free(lista);
}
