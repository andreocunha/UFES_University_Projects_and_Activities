#ifndef point_h
#define point_h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point Point;

/*Inicializa um Ponto
 * inputs: o nome do Ponto, a dimensao e as coordenadas do Ponto
 * output: ponteiro para a Ponto inicializado
 * pre-condicao: uma string, um inteiro e um vetor de double existentes
 * pos-condicao: Ponto de retorno existe e os dados estao inseridos no Ponto
 */
Point* new_point(char* nome, int M, double* coords);

/*Retorna o nome do Ponto
 * inputs: um Ponto
 * output: a string do nome do Ponto
 * pre-condicao: Ponto existe
 * pos-condicao: Ponto não é modificado
 */
char* get_name_point(Point* p);

/*Retorna a distancia entre dois Pontos
 * inputs: dois Pontos
 * output: um double da distancia dos Pontos
 * pre-condicao: os Pontos existem
 * pos-condicao: os Pontos não sao modificados
 */
double distance(Point* a, Point* b);

/*Imprime um Ponto
 * inputs: um Ponto
 * output: nenhum
 * pre-condicao: Ponto existe
 * pos-condicao: Ponto não é modificado
 */
void print_point(Point* p);

/*Libera memória alocada para o Ponto
 * inputs: Ponto
 * output: nenhum
 * pre-condicao: Ponto existe
 * pos-condicao: toda a memória alocada para o Ponto foi liberada
 */
void destroy_point(Point* p);

#endif /* point_h */