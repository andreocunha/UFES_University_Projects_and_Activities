#ifndef List_H
#define List_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list List;

/*Inicializa uma Lista
 * inputs: nenhum
 * output: ponteiro para a lista inicializada
 * pre-condicao: nenhum
 * pos-condicao: lista de retorno existe
 */
List* new_list();

/*Insere uma string em no final de uma lista
 * inputs: uma lista e uma string
 * output: nenhum
 * pre-condicao: lista e string existem
 * pos-condicao: lista nao eh modificada
 */
void insert_end_list(List* l, char* m);

/*Retorna o ponteiro do nome da lista
 * inputs: uma lista, um inteiro
 * output: o ponteiro do nome da lista
 * pre-condicao: lista existe
 * pos-condicao: lista não é modificado
 */
char* get_by_index_list(List* l, int i);

/*Imprime uma lista
 * inputs: uma lista
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: lista não é modificado
 */
void print_list(List* l, FILE* output);

/*Verifica se uma lista está vazia
 * inputs: uma lista
 * output: um inteiro ( 1 vazia / 0 não vazia )
 * pre-condicao: lista existe
 * pos-condicao: lista não é modificado
 */
int empty_list(List* l);

/*Libera memória alocada para uma lista
 * inputs: uma lista
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: toda a memória alocada para a lista foi liberada
 */
void destroy_list(List* l);

#endif