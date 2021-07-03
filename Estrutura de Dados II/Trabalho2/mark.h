#ifndef TRAB2_1_MARK_H
#define TRAB2_1_MARK_H
#include <stdio.h>

typedef struct mark Mark;

/*Inicializa um Mark
 * inputs: um inteiro e um arquivo de entrada(leitura)
 * output: ponteiro para Mark inicializado
 * pre-condicao: o inteiro e o arquivo existem
 * pos-condicao: ponteiro para Mark de retorno existe
 */
Mark * inicializa_Mark(int n, FILE * in);

/*Imprime um Mark
 * inputs: um Mark
 * output: nenhum
 * pre-condicao: Mark existe
 * pos-condicao: Mark não é modificado
 */
void imprime_Mark(Mark *m);

/*Libera memória alocada para um de Mark
 * inputs: um Mark
 * output: nenhum
 * pre-condicao: de Mark e inteiro existem
 * pos-condicao: toda a memória alocada para Mark foi liberada
 */
void destroi_Mark(Mark *m);

/*Retorna o no com base no indice (i) que ele se encontra no vetor
 * inputs: um Mark
 * output: o valor do no de Mark
 * pre-condicao: Mark existe
 * pos-condicao: Mark não é modificado
 */
int get_Mark(int i, Mark *m);

/*Retorna o valor do tamanho de Mark
 * inputs: um Mark
 * output: o valor do tamanho de Mark
 * pre-condicao: Mark existe
 * pos-condicao: Mark não é modificado
 */
int getsize_Mark(Mark *m);

/*Retorna o valor do vetor de Mark
 * inputs: um Mark
 * output: o valor do vetor de Mark
 * pre-condicao: Mark existe
 * pos-condicao: Mark não é modificado
 */
int* getVet_Mark(Mark *m);

/*Retorna maior valor do Mark
 * inputs: um Mark
 * output: o maior valor de Mark
 * pre-condicao: Mark existe
 * pos-condicao: Mark não é modificado
 */
int get_maiorValor(Mark* m);

#endif //TRAB2_1_MARK_H
