#ifndef Commands_H
#define Commands_H

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct processos Processos;

/*Inicializa um vetor de processos
 * inputs: nenhum
 * output: ponteiro para uma struct de processos inicializado
 * pre-condicao: nenhuma
 * pos-condicao: processos de retorno existe
 */
Processos* inicializaProcessos();

/*Adiciona um processo ao vetor de processos
 * inputs: ponteiro para uma struct de processos, inteiro do pid do processo
 * output: nenhum
 * pre-condicao: processos existe
 * pos-condicao: processos de retorno contem o pid do processo adicionado ao vetor e a quantidade de processos aumenta em 1
 */
void adicionaProcesso(Processos* p, int pid);

/*Mata todos os processos de um vetor de processos
 * inputs: ponteiro para uma struct de processos
 * output: nenhum
 * pre-condicao: processos existe
 * pos-condicao: todos os processos de processos de retorno foram mortos
 */
void mataProcessos(Processos* p);

/*Imprime um vetor de processos
 * inputs: ponteiro para uma struct de processos
 * output: nenhum
 * pre-condicao: processos existe
 * pos-condicao: processos nao eh modificado
 */
void imprimeProcessos(Processos* p);

/*Libera memória alocada para a struct de processos
 * inputs: ponteiro para uma struct de processos
 * output: nenhum
 * pre-condicao: processos existe
 * pos-condicao: toda a memória alocada para a struct processos foi liberada
 */
void liberaProcessos(Processos* p);

#endif