//
// Created by AbeSantos on 31/03/2021.
//

#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct pqueue{
    Item ** queue;
    int tam;
    int * pos;
};

//trabalhamos com vet[1] pra cima, logo temos q malocar 1 espaco a mais
Pqueue * inicializa_PQ(int tam){
    Pqueue * new = (Pqueue*) malloc(sizeof(Pqueue));
    if (!new){
        printf("Erro: Alocação de PQ!!\n");
        exit(1);
    }

    //aponta pro elemento antes do primeiro
    new->tam = 0;

    //aloca um vetor de ponteiros para estrutura Item
    new->queue = inicializa_Item(tam+1);

    //aloca um vetor para guardar as posicoes de cada vet
    new->pos = (int *) malloc(sizeof(int)* (tam+1));
    if (!new->queue){
        printf("Erro: Alocação de PQ!!\n");
        exit(1);
    }

    return new;
}

//para quando o filho eh menor que o pai
static void fix_up(Pqueue * pq, int k) {
    while (k > 1 && greater(getPeso(pq->queue[k/2]), getPeso(pq->queue[k]))) {

        int v1 = getVertice(pq->queue[k]);
        int v2 = getVertice(pq->queue[k/2]);
        //troca o armazenamento dos itens na PQ
        int aux = pq->pos[v1];
        pq->pos[v1] = pq->pos[v2];
        pq->pos[v2] = aux;

        exch(pq->queue[k], pq->queue[k/2])

        k = k/2;
    }
}

//para quando o pai eh maior que o filho
static void fix_down(Pqueue *pq, int k){
    while (2*k <= pq->tam) {
        int j = 2*k;
        if (j < pq->tam && greater(getPeso(pq->queue[j]), getPeso(pq->queue[j+1]))){
            j++;
        }
        if (!greater(getPeso(pq->queue[k]), getPeso(pq->queue[j]))) {
            break;
        }

        int v1 = getVertice(pq->queue[k]);
        int v2 = getVertice(pq->queue[j]);
        //troca o armazenamento dos itens na PQ
        int aux = pq->pos[v1];
        pq->pos[v1] = pq->pos[v2];
        pq->pos[v2] = aux;

        exch(pq->queue[k], pq->queue[j])


        k = j;
    }
}

Item * delmax_PQ(Pqueue * pq) {
    //tira o elemento menor
    Item * min = pq->queue[1];

    int v1 = getVertice(pq->queue[1]);
    int v2 = getVertice(pq->queue[pq->tam]);

    int aux = pq->pos[v1];
    pq->pos[v1] = pq->pos[v2];
    pq->pos[v2] = aux;

    //troca o menor elemento com o ultimo da fila
    exch(pq->queue[1], pq->queue[pq->tam])

    //decrementa o tamanho
    pq->tam--;
    //conserta a fila de cima pra baixo
    fix_down(pq,1);
    //retorna o elemento
    return min;
}

// insere um item na fila de prioridade
void insere_PQ(Pqueue * pq, Item* i){
    //incrementa o tamanho
    pq->tam++;
    //insere no final
    pq->queue[pq->tam] = i;

    //guarda a posicao do vertice na pq
    pq->pos[getVertice(i)] = pq->tam;

    //conserta a fila de baixo pra cima
    fix_up(pq, pq->tam);
}

// Testa se a fila ta vazia
int vazio_PQ(Pqueue * pq){
    //ela eh vazia se o tamanho for 0
    if (pq->tam == 0)
        return 1;
    else
        return 0;
}

//libera a fila da memoria
void destroi_PQ(Pqueue * pq, int n){
    if (pq != NULL){
        //destroi o vetor de Itens primeiro
        destroi_Item(pq->queue, n);
        free(pq->pos);
        free(pq);
    }
}

//modifica o peso do vertice ver na fila
void setPeso_PQ(Pqueue * pq, int vet, double peso){
    //pega a posicao do vertice na pq diretamente
    int i = pq->pos[vet];

    //verifica se o vet esta valido
    if (vet >= 0){
        //busca o vertice na fila

        //seta o peso do vertice
        setpeso_Item(pq->queue[i], peso);
        //conserta a fila de baixo pra cima
        fix_up(pq, i);

    }

}

//verifica se o vertice pertence a fila
int buscaVertice_PQ(Pqueue * pq, int vertice){
    return pq->pos[vertice] <= pq->tam;
}

//imprime a fila (debug)
void imprime_PQ(Pqueue * pq){
    for (int i = 1; i <= pq->tam; ++i) {
        imprime_Item(pq->queue[i]);
    }
}
