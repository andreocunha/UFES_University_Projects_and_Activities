#ifndef GRAFO_H_
#define GRAFO_H_

#include <stdio.h>
#include <stdlib.h>


struct nohLista{
    int vDest;
    double peso;
    struct nohLista* prox;
};


struct listaAdjacencia{
    struct nohLista* Lista;
};

typedef struct grafo Grafo;
typedef struct listaAdjacencia ListaAdj;
typedef struct nohLista NohLista;

/*Inicializa um grafo
 * inputs: quantidade de vertices
 * output: ponteiro para a grafo inicializado
 * pre-condicao: inteiro existente
 * pos-condicao: grafo de retorno existe
 */
Grafo* initGrafo(int vert);

/*
// Funcao que vai adicionar os vértices A e B no grafo
*/
void addAresta(Grafo* g, int vert, int ares, double peso);

/* Funcao responsavel para criar noh na lista de Adjacencias do vertice A para o
// B com o peso entre eles. Como é uma vetor de Listas, o vértice A já está sendo
// referenciado na posicao do grafo, essa aqui é para mostrar qual o vértice que
// está sendo ligado.
*/
NohLista* adicionaNoh(int vert, double peso);

int retornaNvertices(Grafo* graph);

NohLista* getCabeca(Grafo * g, int indice);

//retorna o vertice da lista
int getVerticeDest(NohLista *n);

//retorna o peso da lista
double getVerticePeso(NohLista *n);

NohLista * proximoListaNoh(NohLista * n);

/*Libera memória alocada para o grafo
 * inputs: grafo
 * output: nenhum
 * pre-condicao: grafo existe
 * pos-condicao: toda a memória alocada para o grafo foi liberada
 */
void liberaGrafo(Grafo* g);

/*Libera memória alocada para um lista de Noh
 * inputs: NohLista
 * output: nenhum
 * pre-condicao: NohLista existe
 * pos-condicao: toda a memória alocada para a NohLista foi liberada
 */
void liberaLista(NohLista* l);

/*Imprime um grafo
 * inputs: um grafo
 * output: nenhum
 * pre-condicao: grafo existe
 * pos-condicao: grafo não é modificado
 */
void imprimeGrafo(Grafo* g);

/*Imprime uma lista
 * inputs: uma NohLista
 * output: nenhum
 * pre-condicao: NohLista existe
 * pos-condicao: NohLista não é modificada
 */
void imprimeLista(NohLista* l);


#endif