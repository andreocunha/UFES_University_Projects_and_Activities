/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * Aula 6
 *
 * Exercicio 6
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "ListaHet.h"
#include <stdlib.h>
#include <string.h>

#define PROF 0
#define ALU 1

typedef struct cel Celula;

struct  cel
{
    Celula* prox;
    void* item;
    int tipo;
};


struct listhet
{
    Celula* prim;
    Celula* ult;
};

ListaHet* InicLista(void)
{
    ListaHet* lista = (ListaHet*)malloc(sizeof(ListaHet));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void InsereAluno(ListaHet* lista, Aluno* al)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = al;
    nova->tipo = ALU;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL)
    {
        lista->ult = nova;
    }
}

void InsereProfessor(ListaHet* lista, Professor* prof)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = prof;
    nova->tipo = PROF;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL)
    {
        lista->ult = nova;
    }
}


void ImprimeListaHet(ListaHet* lista)
{
    Celula* p;

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        if(p->tipo == ALU)
        {
            printf("ALUNO: ");
            ImprimeAluno(p->item);
        }
        if(p->tipo == PROF)
        {
            printf("PROFESSOR: ");
            ImprimeProfessor(p->item);
        }
    }
}

float ValorChurrasco(ListaHet* lista)
{
    Celula* p = lista->prim;
    float valor = 0.0;

    while (p != NULL)
    {
        if(p->tipo == PROF)
        {
            valor = valor + 0.02*RetornaSalario(p->item);
        }
        if(p->tipo == ALU)
        {
            valor = valor + 30;
        }
        p = p->prox;
    }
    return valor;
}

void DestroiLista(ListaHet* lista)
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
