#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contribuicao Contribuicao;

/*Inicializa uma contribuicao
 * inputs: um texto e o nome do arquivo
 * output: ponteiro para a contribuicao inicializada
 * pre-condicao: uma string e o nome do arquivo existente
 * pos-condicao: contribuicao de retorno existe e contem duas strings
 */
Contribuicao* InicializaContribuicao (char* texto, char* arq);

/*Imprime a contribuicao
 * inputs: uma contribuicao e um arquivo
 * output: nenhum
 * pre-condicao: contribuicao e o arquivo existem
 * pos-condicao: o arquivo contem o conteudo da contribuicao
 */
void ImprimeContribuicao(Contribuicao* contrib, FILE* arq);

/*Retorna o texto da contribuicao
 * inputs: uma contribuicao
 * output: a string do texto
 * pre-condicao: contribuicao existe
 * pos-condicao: contribuicao não é modificada
 */
char* RetornaTextoContribuicao(Contribuicao* contrib);

/*Retorna a string com o nome do arquivo da contribuicao
 * inputs: uma contribuicao
 * output: a string do arquivo
 * pre-condicao: contribuicao existe
 * pos-condicao: contribuicao não é modificada
 */
char* RetornaArquivoContribuicao(Contribuicao* contrib);

/*Libera memória alocada para a contribuicao
 * inputs: contribuicao
 * output: nenhum
 * pre-condicao: contribuicao existe
 * pos-condicao: toda a memória alocada para a contribuicao foi liberada
 */
void DestroiContribuicao(Contribuicao* contrib);

/*Altera o status da contribuicao
 * inputs: uma contribuicao
 * output: nenhum
 * pre-condicao: contribuicao existe
 * pos-condicao: o status da contribuicao eh modificado
 */
void AlteraStatusContribuicao(Contribuicao* contrib);

/*Retorna o status da contribuicao
 * inputs: uma contribuicao
 * output: a string do status
 * pre-condicao: contribuicao existe
 * pos-condicao: contribuicao não é modificada
 */
char RetornaStatusContribuicao(Contribuicao* contrib);

/*Imprime o hitorico da contribuicao
 * inputs: uma contribuicao, o nome do editor e um arquivo
 * output: nenhum
 * pre-condicao: contribuicao, nome do editor e o arquivo existem
 * pos-condicao: o arquivo contem o conteudo do historico da contribuicao
 */
void ImprimeHistoricoContribuicao(Contribuicao* contrib, char* editor, FILE* arq);

#endif /*CONTRIBUICAO_H*/

