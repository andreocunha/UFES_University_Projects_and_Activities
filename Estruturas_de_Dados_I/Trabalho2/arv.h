#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arvore;

/*Inicializa uma arvore
 * inputs: nenhum
 * output: ponteiro para a arvore inicializado
 * pre-condicao: nenhuma
 * pos-condicao: arvore de retorno existe
 */
Arvore *criaArvore(void);

/*Monta a arvore binaria aritmetica
 * inputs: uma arvore, uma string com a expressao matematica e um inteiro referente a posicao da string
 * output: uma arvore binaria montada
 * pre-condicao: arvore e texto existem
 * pos-condicao: arvore é modificada
 */
Arvore *parsing(Arvore *arv, char *texto, int *pos);

/*Retorna o resultado da expressao matematica
 * inputs: uma arvore
 * output: um float com o resultado da expressao
 * pre-condicao: arvore existe
 * pos-condicao: arvore não é modificada
 */
float resultado(Arvore *arv);

/*Verifica se a arvore esta vazia
 * inputs: uma arvore
 * output: um inteiro (1 para arvore varia e 0 caso contrario)
 * pre-condicao: arvore existe
 * pos-condicao: arvore não é modificada
 */
int vaziaArvore(Arvore *arv);

/*Imprime a arvore
 * inputs: uma arvore
 * output: nenhum
 * pre-condicao: arvore existe
 * pos-condicao: arvore não é modificada
 */
void imprimeArvore(Arvore *arv);

/*Libera memória alocada para a arvore
 * inputs: arvore
 * output: nenhum
 * pre-condicao: arvore existe
 * pos-condicao: toda a memória alocada para a arvore foi liberada
 */
Arvore *liberaArvore(Arvore *arv);

#endif /*ARVORE_H_*/