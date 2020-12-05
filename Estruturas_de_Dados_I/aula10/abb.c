#include "abb.h"
#include <stdlib.h>
#include <stdio.h>

struct arv
{
    Aluno *info;
    Arv *esq;
    Arv *dir;
};


Arv *abb_cria(void)
{
    return NULL;
}

// Insere sempre como folha da árvore
Arv *abb_insere(Arv *a, Aluno *al)
{
    if (a == NULL)
    {
        a = (Arv *)malloc(sizeof(Arv));
        a->info = al;
        a->esq = a->dir = NULL;
    }
    // procura onde inserir 
    else if (RetornaMat(al) < RetornaMat(a->info)){
        a->esq = abb_insere(a->esq, al);
    }
    else{
        a->dir = abb_insere(a->dir, al);
    }
    return a;
}

void abb_imprime(Arv *a)
{
    if (a != NULL)
    {
        abb_imprime(a->esq);
        ImprimeAluno(a->info);
        abb_imprime(a->dir);
    }
}

//Se encontrar, retorna o nó que contém o aluno
//Se não encontrar, retorna NULL
Arv *abb_busca(Arv *r, int chave)
{
    if (r == NULL)
        return NULL;
    else if (RetornaMat(r->info) > chave)
        return abb_busca(r->esq, chave);
    else if (RetornaMat(r->info) < chave)
        return abb_busca(r->dir, chave);
    else
        return r;
}

Arv *abb_retira(Arv *r, int v)
{
    if (r == NULL)
        return NULL;
    else if (RetornaMat(r->info) > v)
        r->esq = abb_retira(r->esq, v);
    else if (RetornaMat(r->info) < v)
        r->dir = abb_retira(r->dir, v);
    //achou!
    else
    {
        // nó é folha! Aqui é tranquilo...
        if (r->esq == NULL && r->dir == NULL)
        {
            free(r);
            r = NULL;
        }

        // no só tem filho à direita
        else if (r->esq == NULL)
        {
            Arv *t = r;
            r = r->dir;
            free(t);
        }
        // no só tem filho à esquerda
        else if (r->dir == NULL)
        {
            Arv *t = r;
            r = r->esq;
            free(t);
        }

        // nó tem os dois filhos I
        else
        {
            //acha o antecessor do no
            Arv *f = r->esq;
            while (f->dir != NULL)
                f = f->dir;
            //faz as trocas das informações
            Aluno *t = r->info;
            r->info = f->info;
            f->info = t;
            //chama recursivamente para o nó agora em alguma das situações anteriores
            r->esq = abb_retira(r->esq, v);
        }
    }
    return r;
}

Arv *abb_libera(Arv *r)
{
    if (r != NULL)
    {
        abb_libera(r->esq);
        abb_libera(r->dir);
        free(r);
    }
    return NULL;
}