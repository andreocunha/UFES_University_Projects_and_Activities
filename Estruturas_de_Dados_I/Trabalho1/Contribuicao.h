#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contribuicao Contribuicao;

/*Inicializa uma contribuicao
 * inputs: um texto e um arquivo
 * output: ponteiro para a contribuicao inicializada
 * pre-condicao: uma string e um arquivo existente
 * pos-condicao: contribuicao de retorno existe e contem um string
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


void AlteraStatusContribuicao(Contribuicao* contrib);

char RetornaStatusContribuicao(Contribuicao* contrib);

void ImprimeHistoricoContribuicao(Contribuicao* contrib, char* editor, FILE* arq);

#endif /*CONTRIBUICAO_H*/

