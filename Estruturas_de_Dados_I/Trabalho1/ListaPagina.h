#ifndef ListaPagina_h
#define ListaPagina_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"
#include "ListaContribuicao.h"


typedef struct celulaPagina CelulaPagina;
typedef struct listaPagina ListaPagina;

#include "ListaLink.h"

/*Inicializa uma lista de pagina
 * inputs: nenhum
 * output: ponteiro para a lista de pagina inicializada
 * pre-condicao: nehuma
 * pos-condicao: lista de pagina de retorno existem
 */
ListaPagina* InicializaListaPagina (void);

/*Insere uma pagina na lista de paginas
 * inputs: uma lista de pagina e uma pagina
 * output: nenhum
 * pre-condicao: lista e pagina existem
 * pos-condicao: pagina eh inserida na lista
 */
void InsereListaPagina(ListaPagina* lista, Pagina* pag);

/*Remove uma pagina da lista de paginas
 * inputs: uma lista de pagina, o nome do pagina e um arquivo
 * output: nenhum
 * pre-condicao: lista e pagina existem
 * pos-condicao: pagina eh removida da lista
 */
void RemoveListaPagina(ListaPagina* lista, char* chave, FILE* log);

/*Retorna uma pagina da lista
 * inputs: uma lista de pagina e o nome da pagina
 * output: uma pagina
 * pre-condicao: lista de pagina existe
 * pos-condicao: lista de pagina não é modificada
 */
Pagina* RetornaPagina(ListaPagina* lista, char* chave);

/*Retorna a lista de contribuicoes de uma pagina
 * inputs: uma pagina e o nome da pagina
 * output: uma lista de contribuicoes
 * pre-condicao: lista de pagina existe
 * pos-condicao: lista de pagina não é modificada
 */
ListaContribuicao* RetornaListaContribuicaoPagina(ListaPagina* lista, char* chave);

/*Retorna a lista de links de uma pagina
 * inputs: uma pagina e o nome da pagina
 * output: uma lista de links
 * pre-condicao: lista de pagina existe
 * pos-condicao: lista de pagina não é modificada
 */
ListaLink* RetornaListaLinkPagina(ListaPagina* lista, char* chave);

/*Remove um link de uma pagina
 * inputs: uma lista de pagina e o nome do pagina
 * output: nenhum
 * pre-condicao: lista de pagina existe
 * pos-condicao: um link eh removido de uma pagina
 */
void RemoveLinkListaLinkListaPagina(ListaPagina* lista, char* chave);

/*Imprime a lista de paginas
 * inputs: uma lista de paginas
 * output: nenhum
 * pre-condicao: lista de paginas existe
 * pos-condicao: lista de paginas não é modificado
 */
void ImprimeListaPagina(ListaPagina* lista);

/*Imprime uma unica pagina da lista de paginas
 * inputs: uma lista de paginas e uma pagina
 * output: nenhum
 * pre-condicao: lista de paginas e pagina existem
 * pos-condicao: lista de paginas não é modificada
 */
void ImprimeUnicaPaginaLista(ListaPagina* lista, Pagina* pag);

/*Libera memória alocada para a lista de paginas
 * inputs: lista de paginas
 * output: nenhum
 * pre-condicao: lista de paginas existe
 * pos-condicao: toda a memória alocada para a lista de paginas foi liberada
 */
void DestroiListaPagina(ListaPagina* lista);


#endif /* ListaPagina_h */