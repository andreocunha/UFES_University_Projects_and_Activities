#include "PilhaDupla.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct
{
    int topo;
} IndicePilha;

struct pilha
{
    Aluno *alunos[TAM];
    IndicePilha Pilha1, Pilha2;
};

//Inicializa a estrutura da pilha dupla
Pilha *inicPilha(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->Pilha1.topo = 0;

    p->Pilha2.topo = TAM - 1;
    return p;
}

//inclui no da topo pilha 1
void pushPilha1(Pilha *p, Aluno *al)
{
    if (!p || p->Pilha1.topo >= p->Pilha2.topo || !al)
    {
        printf("\nPilha cheia ou aluno invalido!!!");
        return;
    }
    p->alunos[p->Pilha1.topo] = al;
    p->Pilha1.topo++;
}

//inclui no da topo pilha 2
void pushPilha2(Pilha *p, Aluno *al)
{
    if (!p || p->Pilha2.topo <= p->Pilha1.topo || !al)
    {
        printf("\nPilha cheia ou aluno invalido!!!");
        return;
    }
    p->alunos[p->Pilha2.topo] = al;
    p->Pilha2.topo--;
}

//retira do top da pilha 1
Aluno *popPilha1(Pilha *p)
{
    if (!p || p->Pilha1.topo == 0)
    {
        printf("Pilha vazia!!!");
        return NULL;
    }
    Aluno *al = p->alunos[p->Pilha1.topo - 1];
    p->Pilha1.topo--;
    return al;
}

//retira do top da pilha 2
Aluno *popPilha2(Pilha *p)
{
    if (!p || p->Pilha1.topo == 0)
    {
        printf("Pilha vazia!!!");
        return NULL;
    }
    Aluno *al = p->alunos[p->Pilha2.topo + 1];
    p->Pilha2.topo++;
    return al;
}

//imprime do topo para a base da pilha 1
void imprimePilha1(Pilha *p)
{
    int i;
    if (!p)
        return;
    for (i = (p->Pilha1.topo - 1); i >= 0; i--)
        ImprimeAluno(p->alunos[i]);
}

//imprime do topo para a base da pilha 2
void imprimePilha2(Pilha *p)
{
    int i;
    if (!p)
        return;
    for (i = (p->Pilha2.topo + 1); i < TAM; i++)
        ImprimeAluno(p->alunos[i]);
}

//Destroi a pilha para não os alunos...
void destroi(Pilha *p)
{
    if (!p)
        return;
    free(p);
}