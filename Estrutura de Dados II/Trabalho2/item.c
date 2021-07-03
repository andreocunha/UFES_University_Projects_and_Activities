//
// Created by AbeSantos on 31/03/2021.
//

#include "item.h"
#include <stdlib.h>
#include <stdio.h>

//estrutura que guarda o peso e vertice na fila
struct item{
    double peso;
    int vertice;
};

//inicializa um vetor de ponteiros para Item
Item ** inicializa_Item(int tam){
    //aloca o vetor de ponteiros
    Item ** new = (Item**) malloc(sizeof(Item*) * tam);
    //verifica se foi alocado
    if (!new){
        printf("Erro: alocação de Item\n");
        exit(1);
    }
    //retorna o vetor de ponteiros
    return new;
}

//inicializa uma estrutura Item
Item * cria_Item(double peso, int vertice){
    //aloca o espaço para a estrutura
    Item * new = (Item*) malloc(sizeof(Item));
    //verifica se foi alocado
    if (!new){
        printf("Erro: alocação de Item\n");
        exit(1);
    }
    //seta os valores passados como parametro
    new->vertice = vertice;
    new->peso = peso;

    //retorna Item
    return new;
}

//altera o valor peso da estrutura
void setpeso_Item(Item *i, double peso){
    i->peso = peso;
}

//retorna o valor peso da estrutura
double getPeso(Item *a){
    return a->peso;
}

//retorna o valor vertice da estrutura
int getVertice(Item *a){
    return a->vertice;
}

//destroi a estrutura a partir do vetor de ponteiros
void destroi_Item(Item **i, int tam){
    for (int j = 1; j < tam; ++j) {
        free(i[j]);
    }
    free(i);
}

//imprime item
void imprime_Item(Item * i){
    printf("Vertice: %d e Peso: %.2f\n", i->vertice, i->peso);
}


