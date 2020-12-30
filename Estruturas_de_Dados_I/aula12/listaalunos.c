#include "listaalunos.h"

struct cr
{
    int n;    //n de alunos
    float CR; //CR acumulado
};

static int comparaMat(void *aluno, void *mat)
{
    Aluno *a = (Aluno *)aluno;
    int *imat = (int *)mat;

    //retorna 0 se forem iguais
    if (RetornaMat(a) == *imat)
    {
        return 0;
    }

    //Retorna 1 se forem diferentes
    return 1;
}

static int imprime(void *aluno, void *dado)
{
    ImprimeAluno(aluno);
    return 1;
}

static int acumula(void *aluno, void *dado)
{
    struct cr *acumulado = (struct cr *)dado;
    acumulado->CR += RetornaCR(aluno);
    acumulado->n++;
    return 1;
}

ListaGenerica *retiraAluno(ListaGenerica *lista, int mat)
{
    return retiraLista(lista, comparaMat, &mat);
}

int pertenceAluno(ListaGenerica *lista, int mat)
{
    return percorreLista(lista, comparaMat, &mat);
}

void imprimeListaAlunos(ListaGenerica *lista)
{
    percorreLista(lista, imprime, NULL);
}

float mediaTurma(ListaGenerica *lista)
{
    struct cr *acumulado = (struct cr *)malloc(sizeof(struct cr));
    acumulado->CR = 0.0;
    acumulado->n = 0;

    percorreLista(lista, acumula, acumulado);

    float media = acumulado->CR / acumulado->n;

    free(acumulado);
    return media;
}