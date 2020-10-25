#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "matriz.h"

//Tipo lista (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct lista Lista;

typedef struct cel Celula;

/* Inicializa uma lista
 * inputs: vazio
 * output: ponteiro para a lista inicializada
 * pre-condicao: nenhuma
 * pos-condicao: lista de retorno existe
 */
Lista* inicializaLista (void);

/* Insere uma matriz na lista
 * inputs: uma lista e uma matriz
 * output: nenhum
 * pre-condicao: matriz mat existe, lista existe
 * pos-condicao: a matriz eh inserida na lista
 */
void insereLista(Lista* lista, Matriz* mat);

/* Remove uma matriz da lista
 * inputs: uma lista e a posição da matriz
 * output: a matriz removida da lista
 * pre-condicao: lista existe e uma posicao valida
 * pos-condicao: matriz removida da lista
 */
Matriz* removeLista(Lista* lista, int posicao);

/* Imprime a lista
 * inputs: uma lista
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: nenhuma
 */
void imprimeLista(Lista* lista);

/* Libera memória alocada para a lista
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: toda a memória alocada para lista foi liberada
 */
void destroiLista(Lista* lista);


#endif /*LISTAMAT_H_*/