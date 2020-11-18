#ifndef EDITOR_H
#define EDITOR_H

typedef struct editor Editor;

/*Inicializa um editor
 * inputs: o nome do editor
 * output: ponteiro para a editor inicializada
 * pre-condicao: uma string existente
 * pos-condicao: editor de retorno existe e contem uma string
 */
Editor* InicializaEditor (char* nome);

/*Imprime um editor
 * inputs: um editor
 * output: nenhum
 * pre-condicao: editor existe
 * pos-condicao: editor não é modificado
 */
void ImprimeEditor(Editor* ed);

/*Retorna o nome do editor
 * inputs: um editor
 * output: a string do nome do editor
 * pre-condicao: editor existe
 * pos-condicao: editor não é modificado
 */
char* RetornaNomeEditor(Editor* ed);

/*Libera memória alocada para o editor
 * inputs: editor
 * output: nenhum
 * pre-condicao: editor existe
 * pos-condicao: toda a memória alocada para o editor foi liberada
 */
void DestroiEditor(Editor* ed);


#endif /*EDITOR_H*/

