#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equivalence.h"
#include "point.h"

typedef struct edge Edge;

typedef struct graph Graph;

/*Inicializa um grafo
 * inputs: quantidade de vertices
 * output: ponteiro para a grafo inicializado
 * pre-condicao: inteiro existente
 * pos-condicao: grafo de retorno existe
 */
Graph* new_graph(int V);

/*Imprime um grafo
 * inputs: um grafo
 * output: nenhum
 * pre-condicao: grafo existe
 * pos-condicao: grafo não é modificado
 */
void print_graph(Graph* g);

/*Adiciona no Grafo dois pontos e a distancia entre eles
 * inputs: um grafo e um vetor com os dois pontos
 * output: nenhum
 * pre-condicao: grafo e os dois pontos existem
 * pos-condicao: o grafo e os pontos não são modificado
 */
void populate_graph(Graph* g, Point** points);

/*Produz a árvore geradora mínima para um grafo conexo com os pesos das distancias
 * inputs: um grafo, um vetor com os dois pontos, um vetor de equivalencias e um inteiro
 * output: nenhum
 * pre-condicao: grafo, vetor dos dois pontos e vetor de equivalencias existem
 * pos-condicao: o grafo é modificado. Os outros parametros nao sao modificados
 */
void generate_clusters(Graph* g, Point** points, Equivalence** id, int K);

/*Libera memória alocada para o grafo
 * inputs: grafo
 * output: nenhum
 * pre-condicao: grafo existe
 * pos-condicao: toda a memória alocada para o grafo foi liberada
 */
void destroy_graph(Graph* g);

#endif /* graph_h */