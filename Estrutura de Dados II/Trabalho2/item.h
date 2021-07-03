#ifndef TRAB2_2_ITEM_H
#define TRAB2_2_ITEM_H

#define key(A) (A)
#define greater(A, B) (key(A) > key(B))
#define exch(A, B) { Item *t = A; A = B; B = t; }

typedef struct item Item;

/*Inicializa uma lista de Itens
 * inputs: um inteiro, indicando o tamanho da lista
 * output: ponteiro para a lista de Itens inicializada
 * pre-condicao: nenhum
 * pos-condicao: lista de Itens de retorno existe
 */
Item ** inicializa_Item(int tam);

/*Inicializa um Item
 * inputs: um double e um inteiro
 * output: ponteiro para o Item inicializada
 * pre-condicao: peso (double) e vertice (int) existem
 * pos-condicao: Item de retorno existe
 */
Item * cria_Item(double peso, int vertice);

/*Retorna o vertice do Item
 * inputs: um Item
 * output: o vertice do Item
 * pre-condicao: Item existe
 * pos-condicao: Item não é modificado
 */
int getVertice(Item *a);

/*Retorna o peso do Item
 * inputs: um Item
 * output: o peso do Item
 * pre-condicao: Item existe
 * pos-condicao: Item não é modificado
 */
double getPeso(Item *a);

/*Imprime um Item
 * inputs: um Item
 * output: nenhum
 * pre-condicao: Item existe
 * pos-condicao: Item não é modificado
 */
void imprime_Item(Item * i);

/*Libera memória alocada para uma lista de Itens
 * inputs: uma lista de Itens e um inteiro (tamanho da lista)
 * output: nenhum
 * pre-condicao: lista de Itens e inteiro existem
 * pos-condicao: toda a memória alocada para a lista de Itens foi liberada
 */
void destroi_Item(Item **i, int tam);

/*Adiciona o peso no Item
 * inputs: um Item, um double
 * output: nenhum
 * pre-condicao: Item existe e o peso (double) existe
 * pos-condicao: o peso do Item é modificado
 */
void setpeso_Item(Item *i, double peso);

#endif //TRAB2_2_ITEM_H
