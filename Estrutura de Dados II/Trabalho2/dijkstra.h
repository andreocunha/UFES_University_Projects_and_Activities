#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "grafo.h"
#include "mark.h"
#include "store_result.h"

/*Retorna um vetor com todas as menores distancias em relacao ao ponto de origem
 * inputs: um Grafo, a origem (inteiro)
 * output: um vetor de double
 * pre-condicao: Grafo existe e os pontos de origem existe
 * pos-condicao: Grafo não é modificado
 */
double* dijkstra_function(Grafo* graph, int orig);

/*Retorna o RTT entre o ponto de origem e destino
 * inputs: uma matriz(double), a origem (inteiro), destino (inteiro)
 * output: o RTT entre os pontos da matriz
 * pre-condicao: Matriz existe e os pontos de origem e destino existem na matriz
 * pos-condicao: Matriz não é modificado
 */
double RTT(int orig, int dest, double** matriz);

/*Retorna o RTT* entre o ponto de origem e destino
 * inputs: uma matriz, um vetor com os monitores, quantidade de monitores, a origem, destino
 * output: o RTT* entre os pontos da matriz (double)
 * pre-condicao: Matriz e vetor de monitores existem, ponto de origem e destino existem na matriz
 * pos-condicao: Matriz e monitores não são modificados
 */
double RTT_min(int orig, int dest, int* monitores, int modM, double** matriz);

/*Calcula todos os RTTs, ordena e imprime as saidas
 * inputs: um Grafo, servidores, clientes, monitores e um arquivo de saida
 * output: nenhum
 * pre-condicao: O Grafo e os Marks existem, e o arquivo de saida foi inicializado
 * pos-condicao: Grafo e Marks nao são modificados
 */
void RTT_all(Grafo* grafo, Mark *server, Mark *client, Mark *monitor, FILE* out);

double** faztudo(int tamanhoMatriz);

#endif