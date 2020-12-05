#include "Arvore.h"

struct arvore
{
    Aluno *aluno;
    struct arvore *esq;
    struct arvore *dir;
};

Arvore* inicArvore(void)
{
    return NULL;
}

Arvore *criaArvore(Aluno *aluno, Arvore *esq, Arvore *dir)
{
    Arvore *novaArvore = (Arvore *)malloc(sizeof(Arvore));
    novaArvore->aluno = aluno;
    novaArvore->esq = esq;
    novaArvore->dir = dir;

    return novaArvore;
}

Arvore* arvorePai(Arvore *arvore, char *nome)
{
    if (vaziaArvore(arvore))
    {
        return NULL;
    }

    if (((!vaziaArvore(arvore->esq)) && (strcmp(RetornaNomeAluno(arvore->esq->aluno), nome) == 0)) || ((!vaziaArvore(arvore->dir)) && (strcmp(RetornaNomeAluno(arvore->dir->aluno), nome) == 0)))
    {
        return arvore;
    }

    Arvore *arvoreAuxiliar = arvorePai(arvore->esq, nome);
    if (arvoreAuxiliar == NULL)
    {
        arvoreAuxiliar = arvorePai(arvore->dir, nome);
    }
    return arvoreAuxiliar;
}

Aluno* informacaoNoArvore(Arvore *arvore)
{
    if (!vaziaArvore(arvore))
    {
        return arvore->aluno;
    }
    return NULL;
}

int folhas(Arvore *arvore)
{
    if (vaziaArvore(arvore->esq) && vaziaArvore(arvore->dir))
    {
        return 1;
    }
    else if (!vaziaArvore(arvore->esq) && vaziaArvore(arvore->dir))
    {
        return folhas(arvore->esq);
    }
    else if (vaziaArvore(arvore->esq) && !vaziaArvore(arvore->dir))
    {
        return folhas(arvore->dir);
    }
    return folhas(arvore->esq) + folhas(arvore->dir);
}

int vaziaArvore(Arvore *arvore)
{
    if (arvore == NULL)
    {
        return 1;
    }

    return 0;
}

int pertenceArvore(Arvore *arvore, char *nome)
{
    if (vaziaArvore(arvore))
    {
        return 0;
    }

    return !strcmp(RetornaNomeAluno(arvore->aluno), nome) ||
           pertenceArvore(arvore->esq, nome) ||
           pertenceArvore(arvore->dir, nome);
}

int ocorrencias(Arvore *arvore, char *nome)
{
    if (vaziaArvore(arvore))
    {
        return 0;
    }
    if (strcmp(RetornaNomeAluno(arvore->aluno), nome) == 0)
    {
        return (1 + ocorrencias(arvore->esq, nome) + ocorrencias(arvore->dir, nome));
    }
    return (ocorrencias(arvore->esq, nome) + ocorrencias(arvore->dir, nome));
}

static int maiorNumero(int a, int b)
{
    return (a > b) ? a : b;
}

int altura(Arvore *arvore)
{
    if (vaziaArvore(arvore))
    {
        return -1;
    }
    else
        return 1 + maiorNumero(altura(arvore->esq), altura(arvore->dir));
}

void imprimeArvore(Arvore *arvore)
{
    printf("<");
    if (!vaziaArvore(arvore))
    {
        printf("%s", RetornaNomeAluno(arvore->aluno));
        imprimeArvore(arvore->esq);
        imprimeArvore(arvore->dir);
    }
    printf(">");
}

Arvore *liberaArvore(Arvore *arvore)
{
    if (!vaziaArvore(arvore))
    {
        liberaArvore(arvore->esq);
        liberaArvore(arvore->dir);
        free(arvore);
    }
    return NULL;
}