#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "point.h"

/* Faz uma equivalencia entre um ponto e um inteiro, 
 * para que seja possível realizar o union_find em um vetor de pontos.
 */
typedef struct equivalence Equivalence;

/*Inicializa um Equivalence
 * inputs: um Ponto e um inteiro
 * output: ponteiro para a Equivalence inicializado
 * pre-condicao: Ponto e inteiro existem
 * pos-condicao: Equivalence de retorno existe
 */
Equivalence* new_equivalence(Point* p, int parent);

/*Inicializa um vetor de Equivalence
 * inputs: um inteiro
 * output: ponteiro para um vetor de Equivalence inicializado
 * pre-condicao: inteiro existem
 * pos-condicao: vetor de Equivalence de retorno existe
 */
Equivalence** new_equivalence_vector(int v);

/*Retorna um Ponto de Equivalence
 * inputs: um Equivalence
 * output: o ponteiro do Ponto
 * pre-condicao: Equivalence existe
 * pos-condicao: Equivalence não é modificado
 */
Point* get_point(Equivalence* e);

/*Retorna o indice do pai de Equivalence
 * inputs: um Equivalence
 * output: um inteiro
 * pre-condicao: Equivalence existe
 * pos-condicao: Equivalence não é modificado
 */
int get_parent(Equivalence* e);

/*Adiciona o indice do pai no Equivalence
 * inputs: um Equivalence
 * output: nenhum
 * pre-condicao: Equivalence e um inteiro existem
 * pos-condicao: Equivalence é modificado
 */
void set_parent(Equivalence* e, int parent);

/*Insere um vetor de Equivalence os Pontos
 * inputs: um Equivalence, um inteiro, vetor de inteiro referente a
altura de cada nó da árvore, um vetor de Ponto
 * output: nenhum
 * pre-condicao: Equivalence, inteiro, vetor de inteiro e vetor de Ponto existem
 * pos-condicao: Equivalence é modificado
 */
void UF_init(Equivalence** e, int size, int* sz, Point** points);

/*Retorna o index da raiz de um Ponto
 * inputs: Vetor de Equivalence, um inteiro
 * output: inteiro referente ao index da raiz de um Ponto
 * pre-condicao: Equivalence existe, posição do ponto é válida
 * pos-condicao: Vetor de Equivalence não é alterado
 */
int UF_find(Equivalence** e, int i);

/*Faz a ligação de dois Pontos
 * inputs: Vetor de Equivalence, inteiro referente parente do ponto de origem,
inteiro referente ao parente do ponto de destino, vetor de inteiro referente a
altura de cada nó da árvore
 * output: nenhum
 * pre-condicao: Equivalence existe, posição dos pontos é válida
 * pos-condicao: Vetor de Equivalence é alterado
 */
void UF_union(Equivalence** e, int parent_o, int parent_d, int* sz);

/*Verifica qual index o Ponto p está no vetor de Equivalencia
 * inputs: Vetor de Equivalence, inteiro referente ao ao tamanho do vetor, Ponto
 * output: inteiro referente ao index do Ponto informado
 * pre-condicao: Equivalence existe, Ponto existe
 * pos-condicao: Vetor de Equivalence não é alterado
 */
int find_equivalence_index(Equivalence** e, int size, Point* p);

/*Libera memória alocada para o Equivalence
 * inputs: Equivalence
 * output: nenhum
 * pre-condicao: Equivalence existe
 * pos-condicao: toda a memória alocada para o Equivalence foi liberada
 */
void destroy_equivalence(Equivalence* e);

/*Libera memória alocada para o Equivalence**
 * inputs: Vetor de Equivalence e inteiro do tamanho dele
 * output: nenhum
 * pre-condicao: Equivalence existe
 * pos-condicao: toda a memória alocada para o vetor de Equivalence foi liberada
 */
void destroy_equivalence_vector(Equivalence** e, int size);