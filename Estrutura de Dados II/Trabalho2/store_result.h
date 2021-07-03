#ifndef STORE_RESULT_H_
#define STORE_RESULT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct result Result;

/*Inicializa um Result (que contera o server, client e rtt_min/rtt)
 * inputs: dois inteiros e um double
 * output: ponteiro para Result inicializado
 * pre-condicao: os inteiros e o double existirem
 * pos-condicao: ponteiro para Result de retorno existe
 */
Result* new_result(int server, int client, double rtt);

/*Retorna o valor de rtt_min/rtt do Result
 * inputs: um Result
 * output: o valor de rtt_min/rtt do Result
 * pre-condicao: Result existe
 * pos-condicao: Result não é modificado
 */
double get_rtt(Result* result);

/*Salva uma lista de Result no arquivo de saida
 * inputs: uma lista Result, um inteiro e um arquivo de saida
 * output: a lista de Result no arquivo
 * pre-condicao: Result e inteiro existem e o arquivo foi incializado para escrita e aberto
 * pos-condicao: Result não é modificado
 */
void imprime_results(Result** results, int qtd, FILE* out);

/*Libera memória alocada para uma lista de Result
 * inputs: uma lista de Result e um inteiro (tamanho da lista)
 * output: nenhum
 * pre-condicao: lista de Result e inteiro existem
 * pos-condicao: toda a memória alocada para a lista de Result foi liberada
 */
void destroi_result(Result** results, int qtd);

/*Ordena de forma crescente uma lista de Result (com base no valor de rtt)
 * inputs: uma lista de Result, um inteiro(comeco da lista), um inteiro(final da lista)
 * output: nenhum
 * pre-condicao: lista de Result existe
 * pos-condicao: a lista de Result foi modificada e ordenada
 */
void quicksort(Result** results, int lo, int hi);

#endif