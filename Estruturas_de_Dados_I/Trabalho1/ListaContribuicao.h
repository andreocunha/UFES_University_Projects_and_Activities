#ifndef ListaContribuicao_h
#define ListaContribuicao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"
#include "Editor.h"

typedef struct celulaContribuicao CelulaContribuicao;
typedef struct listaContribuicao ListaContribuicao;

/*Inicializa uma lista de contribuicao
 * inputs: nenhum
 * output: ponteiro para a lista de contribuicao inicializada
 * pre-condicao: nehuma
 * pos-condicao: lista de contribuicao de retorno existe
 */
ListaContribuicao* InicializaListaContribuicao (void);

/*Insere uma contribuicao na lista de contribuicao
 * inputs: uma lista de contribuicao, uma contribuicao e um editor
 * output: nenhum
 * pre-condicao: lista, contribuicao e editor existem
 * pos-condicao: contribuicao e editor sao inseridos na lista
 */
void InsereListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib, Editor* ed);

/*Remove uma contribuicao da lista de contribuicao
 * inputs: uma lista de contribuicao e o nome da contribuicao
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: contribuicao eh removida da lista
 */
void RemoveListaContribuicao(ListaContribuicao* lista, char* chave);

/*Remove uma celula da lista de contribuicao
 * inputs: uma lista de contribuicao e o nome do contribuicao
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: a celula eh removida da lista
 */
void RemoveCelulaListaContribuicao(ListaContribuicao* lista, char* chave);

/*Retorna uma contribuicao da lista de contribuicao
 * inputs: uma lista de contribuicao e o nome da contribuicao
 * output: uma contribuicao
 * pre-condicao: lista de contribuicao existe
 * pos-condicao: lista de contribuicao não é modificada
 */
Contribuicao* RetornaContribuicaoLista(ListaContribuicao* lista, char* chave);

/*Retorna um editor da lista de contribuicao
 * inputs: uma lista de contribuicao e o uma contribuicao
 * output: um editor
 * pre-condicao: lista de contribuicao e a contribucao existem
 * pos-condicao: lista de contribuicao não é modificada
 */
Editor* RetornaEditorListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib);

/*Imprime a lista de contribuicao
 * inputs: uma lista de contribuicao e um arquivo
 * output: nenhum
 * pre-condicao: lista de contribuicao e arquivo existem
 * pos-condicao: lista de contribuicao não é modificada e o arquivo contem o conteudo da lista de contribuicao
 */
void ImprimeListaContribuicao(ListaContribuicao* lista, FILE* arq);

/*Imprime a lista de contribuicao de um editor
 * inputs: uma lista de contribuicao
 * output: nenhum
 * pre-condicao: lista de contribuicao
 * pos-condicao: lista de contribuicao não é modificada
 */
void ImprimeListaContribuicaoEditor(ListaContribuicao* lista);

/*Imprime o historico da lista de contribuicao
 * inputs: uma lista de contribuicao e um arquivo
 * output: nenhum
 * pre-condicao: lista de contribuicao e arquivo existem
 * pos-condicao: lista de contribuicao não é modificado e o arquivo contem o conteudo do historico
 */
void ImprimeListaHistoricoContribuicao(ListaContribuicao* lista, FILE* arq);

/*Libera memória alocada para a lista de contribuicao
 * inputs: lista de contribuicao
 * output: nenhum
 * pre-condicao: lista de contribuicao existe
 * pos-condicao: toda a memória alocada para a lista de contribuicao foi liberada
 */
void DestroiListaContribuicao(ListaContribuicao* lista);

/*Libera memória alocada para uma celula da lista de contribuicao
 * inputs: lista de contribuicao
 * output: nenhum
 * pre-condicao: lista de contribuicao existe
 * pos-condicao: a memória alocada para a celula da lista de contribuicao foi liberada
 */
void DestroiCelulaListaContribuicao(ListaContribuicao* lista);


#endif /* ListaContribuicao_h */