#ifndef ListaLink_h
#define ListaLink_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celulaLink CelulaLink;
typedef struct listaLink ListaLink;

#include "ListaPagina.h"

/*Inicializa uma lista de links
 * inputs: nenhum
 * output: ponteiro para a lista de links inicializada
 * pre-condicao: nehuma
 * pos-condicao: lista de links de retorno existe
 */
ListaLink* InicializaListaLink (void);

/*Insere uma pagina na lista de links
 * inputs: uma lista de links e uma pagina
 * output: nenhum
 * pre-condicao: lista e pagina existem
 * pos-condicao: pagina eh inserida na lista
 */
void InsereListaLink(ListaLink* lista, Pagina* pag);

/*Remove uma pagina da lista de links
 * inputs: uma lista de links e o nome do pagina
 * output: nenhum
 * pre-condicao: lista existe
 * pos-condicao: pagina eh removida da lista
 */
void RemoveListaLink(ListaLink* lista, char* chave);

/*Imprime a lista de links
 * inputs: uma lista de links e um arquivo
 * output: nenhum
 * pre-condicao: lista de links e arquivo existem
 * pos-condicao: lista de links não é modificado e o arquivo contem o conteudo da lista de links
 */
void ImprimeListaLink(ListaLink* lista, FILE* arq);

/*Retorna uma pagina da lista de links
 * inputs: uma lista de links e o nome da pagina
 * output: uma pagina
 * pre-condicao: lista de links existe
 * pos-condicao: lista de links não é modificada
 */
Pagina* RetornaPaginaListaLink(ListaLink* lista, char* chave);

/*Insere todas as paginas de um caminho em uma linsta de links
 * inputs: uma lista de pagina, uma pagina e uma lista de links
 * output: nenhum
 * pre-condicao: listas e pagina existem
 * pos-condicao: as paginas sao inserida na lista links
 */
void ListaTodosCaminhosPossiveis(Pagina* pag, ListaLink* visited, ListaPagina* listaPag);

/*Libera memória alocada para a lista de links
 * inputs: lista de links
 * output: nenhum
 * pre-condicao: lista de links existe
 * pos-condicao: toda a memória alocada para a lista de links foi liberada
 */
void DestroiListaLink(ListaLink* lista);


#endif /* ListaLink_h */