#ifndef TRAB2_2_PRIORITY_QUEUE_H
#define TRAB2_2_PRIORITY_QUEUE_H
#include "item.h"

//PQ = Priority queue

typedef struct pqueue Pqueue;

/*Inicializa uma priority queue
 * inputs: um inteiro, indicando o tamanho da priority queue
 * output: ponteiro para a priority queue inicializada
 * pre-condicao: nenhum
 * pos-condicao: priority queue de retorno existe
 */
Pqueue * inicializa_PQ(int tam);

/*Retorna o menor Item da PQ
 * inputs: a PQ
 * output: ponteiro para o Item de menor Custo da PQ
 * pre-condicao: PQ existe e tem pelo menos 1 Item inserido
 * pos-condicao: Item de retorno existe e retirado da PQ
 */
Item * delmax_PQ(Pqueue * pq);

/*Verifica se a PQ esta vazia
 * inputs: a PQ
 * output: inteiro 1 (vazia) ou 0 (nao vazia)
 * pre-condicao: PQ existe
 * pos-condicao: PQ nao eh modificada
 */
int vazio_PQ(Pqueue * pq);

/*Verifica se o vertice pertence a PQ
 * inputs: a PQ, int vertice
 * output: inteiro 1 (pertence) ou 0 (nao pertence)
 * pre-condicao: PQ existe, int vertice maior igual a 0
 * pos-condicao: PQ nao eh modificada
 */
int buscaVertice_PQ(Pqueue * pq, int vertice);

/*Insere um Item* na PQ
 * inputs: a PQ, um Item
 * output: nenhum
 * pre-condicao: PQ existe, Item existe
 * pos-condicao: Item eh inserido na PQ
 */
void insere_PQ(Pqueue * pq, Item* i);

/*Libera PQ da memoria
 * inputs: a PQ, int n definindo o tamanho do vetor da PQ
 * output: nenhum
 * pre-condicao: PQ existe, vetor dentro da PQ tem tamanho n
 * pos-condicao: PQ eh liberada da memoria
 */
void destroi_PQ(Pqueue * pq, int n);

/*Altera o Peso de determinado Item da PQ
 * inputs: a PQ, int indice, double peso
 * output: nenhum
 * pre-condicao: PQ existe, indice passado existe no vetor da PQ
 * pos-condicao: elemento de indice = indice eh modificado seu peso para o double peso
 */
void setPeso_PQ(Pqueue * pq, int indice, double peso);

#endif //TRAB2_2_PRIORITY_QUEUE_H
