//
// Created by AbeSantos on 30/03/2021.
//

#include "mark.h"
#include <stdlib.h>
#include <stdio.h>

//estrutura utilizada para armazenar os subconjuntos
struct mark{
    int* vet;
    int tam;
    int mValor;
};

//inicializa mark e faz a leitura dos subconjuntos
Mark * inicializa_Mark(int n, FILE * in){

    Mark * new = (Mark*) malloc(sizeof(Mark));
    //verifica se foi alocado
    if (!new){
        printf("Erro, alocacao mark!!\n");
        exit(1);
    }
    //seta o tamanho do vetor
    new->tam = n;
    // maior valor pro mark
    new->mValor = -1;
    //aloca o vetor
    new->vet = (int*) malloc(sizeof(int) * n);
    //verifica se foi alocado
    if (!new->vet){
        printf("Erro, alocacao mark!!\n");
        exit(1);
    }

    //faz a leitura dos nós pertencentes a este subconjunto
    for (int i = 0; i < new->tam; ++i) {
        fscanf(in, "%d", &new->vet[i]);
        if(new->vet[i] > new->mValor){
            new->mValor = new->vet[i];
        }
    }
    return new;
}
//retorna o no com base no indice q ele se encontra no vetor
int get_Mark(int i, Mark *m){
    if (i < m->tam)
        return m->vet[i];
    else
        return -1;
}

// retorna o maior valor
int get_maiorValor(Mark* m){
    return m->mValor;
}

//retorna a posicao do vetor que tem o valor
int get_position(Mark *m, int value){
    for (int i = 0; i < m->tam; ++i) {
        if(m->vet[i] == value){
            return i;
        }
    }
    return 0;
}

//retorna o tamanho do vetor
int getsize_Mark(Mark *m){
    return m->tam;
}

//retorna o proprio vetor
int* getVet_Mark(Mark *m){
    return m->vet;
}

//imprime mark
void imprime_Mark(Mark *m){
    printf("Mark: ");
    for (int i = 0; i < m->tam; ++i) {
        printf("%d ", m->vet[i]);
    }
    printf("\n");
}

//libera mark da memoria
void destroi_Mark(Mark *m){
    if (!m)
        exit(1);

    free(m->vet);
    free(m);
}
