#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaComSentinela.h"
#include "Fila.h"

#define TAM 10

struct fila
{
  Lista *lista;
};

Fila *inicFila(void)
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->lista = InicLista();
  return fila;
}

//insere no final
void insereFila(Fila *fila, Aluno *aluno)
{
    if (!fila || !aluno)
    {
        printf("\nPilha invalida, cheia ou aluno invalido!\n");
        return;
    }
  InsereListaUlt(fila->lista, aluno);
}

//retira do começo
Aluno *retiraFila(Fila *fila)
{
  return RetiraPosicao(fila->lista, 0);
}

//do inicio ao fim
void imprimeFila(Fila *fila)
{
  ImprimeLista(fila->lista);
}

void destroiFila(Fila *fila)
{
  DestroiLista(fila->lista);
  free(fila);
}