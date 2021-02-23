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
Arv *bst_inicia(Arv *esq, Arv *dir, char valor)
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
        printf("%c\n", a->valor);
        bst_imprime(a->dir);
    }
}

void bst_imprime_no(Arv *a)
{
    if (a != NULL)
    {
        printf("%c ", a->valor);
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

void rec_preorder(Arv *a, Pilha *p)
{
    if (a == NULL){ return; }

    pushPilha(p, a);

    while (!pilhaVazia(p))
    {
        Arv * temp = popPilha(p);
        bst_imprime_no(temp);
        // pushPilha(p, temp);

        if (temp->dir != NULL)
        {
            pushPilha(p, temp->dir);
        }
        if (temp->esq != NULL)
        {
            pushPilha(p, temp->esq);
        }
    }
    printf("\n");
}

void in_order(Arv *a, Pilha *p)
{
    if (a == NULL){ return; }

    Arv *temp = a;

    while (!pilhaVazia(p) || temp != NULL)
    {
        if(temp != NULL)
        {
            pushPilha(p, temp);
            temp = temp->esq;
        }
        else
        {
            temp = popPilha(p);
            bst_imprime_no(temp);
            temp = temp->dir;
        }
    }
    printf("\n");

}

void post_order(Arv *a, Pilha *p)
{
    if (a == NULL){ return; }
    printf("\n");

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