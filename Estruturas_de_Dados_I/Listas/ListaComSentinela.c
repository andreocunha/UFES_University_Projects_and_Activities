#include <stdlib.h>
#include <string.h>
#include "ListaComSentinela.h"

typedef struct cel Celula;

struct cel{
    Aluno* al;
    Celula* prox;
};

struct lista{
    Celula* Prim;
    Celula* Ult;
};

Lista* InicLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->Prim = NULL;
    lista->Ult = NULL;
    
    return lista;
}

void ImprimeLista(Lista* l){
    Celula* p; //ponteiro auxiliar

    for(p = l->Prim; p != NULL; p=p->prox){
        ImprimeAluno(p->al);
    }
}

void InsereLista(Lista* l, Aluno* aluno){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->al = aluno;

    nova->prox = l->Prim;

    l->Prim = nova;

    if(l->Ult == NULL){
        l->Ult = nova;
    }

}

Aluno* RetiraLista(Lista* l, char* chave){
    Celula* p = l->Prim;
    Aluno* al;
    Celula* ant = NULL;
    
    //faz a busca
    while (p!=NULL && strcmp(RetornaNome(p->al), chave))
    {
        ant = p;
        p = p->prox;
    }

    //lista vazia ou não encontrou o aluno
    if(p == NULL){
        return NULL;
    }

    //atribui o aluno de retorno
    al = p->al;

    //se for o unico
    if(p == l->Prim && p == l->Ult){
        l->Prim = l->Ult = NULL;
    }
    else if (p == l->Prim){ //se for o primeiro
        l->Prim = p->prox;
    }
    else if(p == l->Ult){
        l->Ult = ant;
        l->Ult->prox = NULL;
    }
    
    else{ //caso comum
        ant->prox = p->prox;

        free(p);
        return al;
    }
}

void DestroiLista(Lista* l){
    Celula* p = l->Prim;
    Celula* t;

    while(p != NULL){
        t = p->prox;
        DestroiAluno(p->al);
        free(p);
        p = t;
    }

    free(l);
}
