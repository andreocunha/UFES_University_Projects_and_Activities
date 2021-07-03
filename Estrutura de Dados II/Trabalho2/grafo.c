#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct grafo{
    int vertices;
    ListaAdj* vetor; // vetor de listas
};

Grafo* initGrafo(int vert){
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->vertices = vert;
    g->vetor = (ListaAdj*)malloc(vert * sizeof(ListaAdj));

    // inicializa o vetor com todos igual a NULL
    for(int i = 0; i< vert; i++){
        g->vetor[i].Lista = NULL;
    }
    return g;
}

void addAresta(Grafo* g, int vert, int ares, double peso){
    if(g != NULL){
        NohLista* noh = adicionaNoh(ares, peso);
        noh->prox = g->vetor[vert].Lista;
        g->vetor[vert].Lista = noh;
    }
}

NohLista* adicionaNoh(int vert, double peso){
    NohLista* n = (NohLista*)malloc(sizeof(NohLista));
    n->vDest = vert;
    n->peso = peso;
    n->prox = NULL;
    return n;
}

int retornaNvertices(Grafo * g){
    return g->vertices;
}

//retorna a lista de adjacencias do vertice indice
NohLista* getCabeca(Grafo * g, int indice){
    return g->vetor[indice].Lista;
}

//retorna o vertice destino
int getVerticeDest(NohLista* n){
    return n->vDest;
}
//retorna o peso do vertice destino
double getVerticePeso(NohLista *n){
    return n->peso;
}
//retorna o prox elemento da lista
NohLista * proximoListaNoh(NohLista * n){
    return n->prox;
}

void liberaGrafo(Grafo* g){
    if(g!=NULL){
        for(int i = 0; i < g->vertices; i++){
            liberaLista(g->vetor[i].Lista);
        }
        free(g->vetor);
        free(g);
    }
    //printf("Grafo vazio\n");

}

void liberaLista(NohLista* l){
    if(l != NULL){
        NohLista* aux = NULL;
        while(l != NULL){
            aux = l->prox;
            free(l);
            l = aux;
        }
    }
}

void imprimeGrafo(Grafo* g){
    if(g!=NULL){
        for(int i = 0; i < g->vertices; i++){
            printf("Noh: %d  ", i);
            imprimeLista(g->vetor[i].Lista);

        }
    }
    return;
}

void imprimeLista(NohLista* l){
    NohLista* aux = l;
    if(l != NULL){
        while(aux != NULL){
            printf("Vertice:%d e peso:%.2f  ",aux->vDest,aux->peso);
            aux = aux->prox;
        }
        printf("\n");
    }
}

