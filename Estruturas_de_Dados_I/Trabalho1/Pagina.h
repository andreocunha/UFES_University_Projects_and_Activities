#ifndef PAGINA_H
#define PAGINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pagina Pagina;

/*Inicializa uma pagina
 * inputs: um texto e o nome do arquivo
 * output: ponteiro para a pagina inicializada
 * pre-condicao: uma string e o nome do arquivo existente
 * pos-condicao: pagina de retorno existe e contem duas strings
 */
Pagina* InicializaPagina (char* nome, char* arquivo);

/*Imprime a pagina
 * inputs: uma pagina e um arquivo
 * output: nenhum
 * pre-condicao: pagina e o arquivo existem
 * pos-condicao: o arquivo contem o conteudo da pagina
 */
void ImprimePagina(Pagina* pag, FILE *arq);

/*Retorna o nome da pagina
 * inputs: uma pagina
 * output: a string do nome da pagina
 * pre-condicao: pagina existe
 * pos-condicao: pagina não é modificada
 */
char* RetornaNomePagina(Pagina* pag);

/*Retorna o nome do arquivo da pagina
 * inputs: uma pagina
 * output: a string do nome do arquivo da pagina
 * pre-condicao: pagina existe
 * pos-condicao: pagina não é modificada
 */
char* RetornaNomeArquivo(Pagina* pag);

/*Libera memória alocada para a pagina
 * inputs: pagina
 * output: nenhum
 * pre-condicao: pagina existe
 * pos-condicao: toda a memória alocada para a pagina foi liberada
 */
void DestroiPagina(Pagina* pag);


#endif /*PAGINA_H*/

