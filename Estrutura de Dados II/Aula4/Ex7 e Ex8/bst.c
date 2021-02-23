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
        printf("%c ",a->valor);
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

static char maiorValor(char a, char b)
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
        return 1 + maiorValor(altura(a->esq), altura(a->dir));
}


void bst_level_order(Arv* arv, Fila* fila)
{
    int h = altura(arv)+1;
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(arv, i, fila);
}
 
void printGivenLevel(Arv* arv, int level, Fila* fila)
{
    if (arv == NULL)
        return;
    if (level == 1)
    {
        enqueue(fila, arv);
    }
    else if (level > 1)
    {
        printGivenLevel(arv->esq, level-1, fila);
        printGivenLevel(arv->dir, level-1, fila);
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