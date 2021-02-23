#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct arv
{
    char valor;
    Arv *esq;
    Arv *dir;
};


Arv *bst_cria(void)
{
    return NULL;
}

// Insere sempre como folha da árvore
Arv *bst_inicia(Arv *esq, Arv* dir, char valor)
{
    Arv *novaArvore = (Arv *)malloc(sizeof(Arv));
    novaArvore->valor = valor;
    novaArvore->esq = esq;
    novaArvore->dir = dir;

    return novaArvore;
}

void bst_imprime(Arv *a)
{
    if (a != NULL)
    {
        bst_imprime(a->esq);
        printf("%c\n",a->valor);
        bst_imprime(a->dir);
    }
}

static char maiorNumero(char a, char b)
{
    return (a > b) ? a : b;
}

int altura(Arv *a)
{
    if (a == NULL)
    {
        return -1;
    }
    else
        return 1 + maiorNumero(altura(a->esq), altura(a->dir));
}

void rec_preorder(Arv *a)
{
    if (a != NULL)
    {
        printf("%c ",a->valor);
        rec_preorder(a->esq);
        rec_preorder(a->dir);
    }
}

void in_order(Arv *a)
{
    if (a != NULL)
    {
        in_order(a->esq);
        printf("%c ",a->valor);
        in_order(a->dir);
    }
}

void post_order(Arv *a)
{
    if (a != NULL)
    {
        post_order(a->esq);
        post_order(a->dir);
        printf("%c ",a->valor);
    }
}

Arv *bst_libera(Arv *r)
{
    if (r != NULL)
    {
        bst_libera(r->esq);
        bst_libera(r->dir);
        free(r);
    }
    return NULL;
}