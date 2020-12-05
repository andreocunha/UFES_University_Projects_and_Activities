#include "FilaComSentinela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula
{
    Aluno *aluno;
    Celula *prox;
};

struct lista
{
    Celula *prim;
    Celula *ult;
};

Lista *InicLista(void)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void ImprimeLista(Lista *l)
{
    Celula *auxiliar;
    if (l == NULL)
    {
        printf("Lista vazia");
        return;
    }
    for (auxiliar = l->prim; auxiliar != NULL; auxiliar = auxiliar->prox)
    {
        ImprimeAluno(auxiliar->aluno);
    }
}

void InsereLista(Lista * l, Aluno *al)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->aluno = al;
    nova->prox = l->prim;
    l->prim = nova;

    if (l->ult == NULL)
        l->ult = nova;
}
void InsereListaUlt(Lista *l, Aluno *al)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->aluno = al;
    nova->prox = NULL;

    if (l->prim == NULL)
    {
        l->prim = l->ult = nova;
        return;
    }
    l->ult->prox = nova;
    l->ult = nova;
}

Aluno *RetiraLista(Lista *lista, char *chave)
{
    Celula *celulaAuxiliar = lista->prim;
    Aluno *alunoAuxiliar;
    Celula *anterior = NULL;

    while (celulaAuxiliar != NULL && strcmp(RetornaNomeAluno(celulaAuxiliar->aluno), chave))
    {
        anterior = celulaAuxiliar;
        celulaAuxiliar = celulaAuxiliar->prox;
    }

    if (celulaAuxiliar == NULL)
        return NULL;

    alunoAuxiliar = celulaAuxiliar->aluno;

    if (lista->prim == celulaAuxiliar && lista->ult == celulaAuxiliar)
    { 
        lista->prim = lista->ult = NULL;
    }
    else if (lista->prim == celulaAuxiliar)
    {
        lista->prim = celulaAuxiliar->prox; 
    }
    else if (lista->ult == celulaAuxiliar)
    {
        lista->ult = anterior;
        lista->ult->prox = NULL; 
    }

    else
    { 
        anterior->prox = celulaAuxiliar->prox;
    }

    free(celulaAuxiliar);

    return alunoAuxiliar;
}

Aluno *RetiraPosicao(Lista *lista, int posicao)
{
    Celula *celulaAuxiliar = lista->prim;
    Aluno *alunoAuxiliar;
    Celula *anterior = NULL;
    int i = 0;

    while (i < posicao && celulaAuxiliar != NULL)
    {
        anterior = celulaAuxiliar;
        i++;
        celulaAuxiliar = celulaAuxiliar->prox;
    }

    if (celulaAuxiliar == NULL)
        return NULL;

    alunoAuxiliar = celulaAuxiliar->aluno;

    if (lista->prim == celulaAuxiliar && lista->ult == celulaAuxiliar)
    { 
        lista->prim = lista->ult = NULL;
    }
    else if (lista->prim == celulaAuxiliar)
    {
        lista->prim = celulaAuxiliar->prox; 
    }
    else if (lista->ult == celulaAuxiliar)
    { 
        lista->ult = anterior;
        lista->ult->prox = NULL; 
    }

    else
    { 
        anterior->prox = celulaAuxiliar->prox;
    }

    free(celulaAuxiliar);

    return alunoAuxiliar;
}

void DestroiLista(Lista *l)
{
    Celula *p = l->prim;
    Celula *t = NULL;

    while (p != NULL)
    {
        t = p->prox;
        if (p->aluno != NULL)
        {
            free(p);
        }
        p = t;
    }
    free(l);
}