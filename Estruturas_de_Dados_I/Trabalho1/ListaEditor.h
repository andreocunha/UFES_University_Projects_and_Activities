#ifndef ListaEditor_h
#define ListaEditor_h

typedef struct celulaEditor CelulaEditor;
typedef struct listaEditor ListaEditor;

#include "Editor.h"
#include "ListaContribuicao.h"

/*Inicializa uma lista de editor
 * inputs: nenhum
 * output: ponteiro para a lista de editor inicializada
 * pre-condicao: nehuma
 * pos-condicao: lista de editor de retorno existe
 */
ListaEditor* InicializaListaEditor (void);

/*Insere um editor na lista de editores
 * inputs: uma lista de editor e um editor
 * output: nenhum
 * pre-condicao: lista e editor existe
 * pos-condicao: editor eh inserido na lista
 */
void InsereListaEditor(ListaEditor* lista, Editor* ed);

/*Retorna um editor da lista
 * inputs: um editor e o nome do editor
 * output: um editor
 * pre-condicao: lista de editor existe
 * pos-condicao: lista de editor não é modificado
 */
Editor* RetornaEditor(ListaEditor* lista ,char* chave);

/*Remove um editor da lista de editores
 * inputs: uma lista de editor e o nome do editor
 * output: nenhum
 * pre-condicao: lista e editor existe
 * pos-condicao: editor eh removido da lista
 */
void RemoveListaEditor(ListaEditor* lista, char* chave);

/*Insere uma contribuicao na lista de contribuicoes de um editor
 * inputs: uma lista de editor, uma contribuicao e o nome do editor
 * output: nenhum
 * pre-condicao: lista de editores e contribuicao existem
 * pos-condicao: contribucao eh inserido na lista do editor
 */
void InsereContribuicaoListaEditor(ListaEditor* lista, Contribuicao* contrib, char* chave);

/*Retorna a lista de contribuicao do editor
 * inputs: lista de editores e o nome do editor
 * output: uma lista de contribuicoes
 * pre-condicao: lista de editor existe
 * pos-condicao: lista de editor não é modificado
 */
ListaContribuicao* RetornaListaContribuicaoEditor(ListaEditor* lista, char* chave);

/*Imprime a lista de editores
 * inputs: uma lista de editores
 * output: nenhum
 * pre-condicao: lista de editores existe
 * pos-condicao: lista de editores não é modificado
 */
void ImprimeListaEditor(ListaEditor* lista);

/*Libera memória alocada para a lista de editores
 * inputs: lista de editores
 * output: nenhum
 * pre-condicao: lista de editores existe
 * pos-condicao: toda a memória alocada para a lista de editores foi liberada
 */
void DestroiListaEditor(ListaEditor* lista);


#endif /* ListaEditor_h */