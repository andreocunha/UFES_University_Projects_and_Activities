#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct arv
{
    int num;
    Arv *esq;
    Arv *dir;
};


Arv *bst_cria(void)
{
    return NULL;
}

// Insere sempre como folha da árvore
Arv *bst_insere(Arv *a, int num)
{
    if (a == NULL)
    {
        a = (Arv *)malloc(sizeof(Arv));
        a->num = num;
        a->esq = a->dir = NULL;
    }
    // procura onde inserir 
    else if (num < a->num){
        a->esq = bst_insere(a->esq, num);
    }
    else{
        a->dir = bst_insere(a->dir, num);
    }
    return a;
}

void bst_imprime(Arv *a)
{
    printf("(");
    if (a != NULL)
    {
        printf(" %d ",a->num);
        bst_imprime(a->esq);
        bst_imprime(a->dir);
    }
    printf(")");
}

static int maiorNumero(int a, int b)
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