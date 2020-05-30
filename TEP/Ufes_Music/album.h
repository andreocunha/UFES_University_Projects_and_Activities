#ifndef ALBUM_H
#define ALBUM_H
#include "midia.h"
#include "album.h"

//Tipo album (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct album Album;

/*Aloca um Album vazio
*inputs: vazio;
*outputs: retorna um Album vazio, alocado
* pre-condicao: nenhuma
* pos-condicao: retorna um Album vazio, alocado
*/
Album* AlocaAlbum();

/*Cria um Album, com suas informaçoes
*inputs: Um album previamente Alocado, dados do album (nome, genero, produtor...)
*Cria um album com seus dados ja atribuidos, porém o album está vazio
* pre-condicao: ponteiros de caracteres
* pos-condicao: Cria um album
*/
void CriaAlbum(Album *a,char* nomeAlb, char* nArtista,char* gen, char* produtor,int ano,int qtd);

/*Adiciona uma midia pre existente em um album
*inputs: um album e uma midia
* Atribui uma midia a uma posicao da quantidade de midias atuais no album
* pre-condicao: um album e midia alocados
* pos-condicao: adiciona midia no album
*/
void AdicionaMidiaAlbum(Album* a,Midia* m);

/*Atribui um nome ao album
*inputs: um album e uma string com o nome digitado
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: adiciona um nome no album
*/
void AtribuiNomeAlbum(Album *a, char* nome);

/*Atribui um nome de Artista ao album
*inputs: um album e uma string com o nome digitado
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: adiciona um arista no album
*/
void AtribuiArtistaAlbum(Album *a, char* nomeArtista);

/*Atribui um Ano ao album
*inputs: um album e um inteiro com o ano digitado
* pre-condicao: um album alocado e um ponteiro para inteiro
* pos-condicao: adiciona um ano no album
*/
void AtribuiAnoAlbum(Album *a, int ano);

/*Atribui uma quantidade de midias ao album
*inputs: um album e um inteiro com a quantidade digitada
* pre-condicao: um album alocado e um ponteiro para inteiro
* pos-condicao: adiciona uma quantidade de midias no album
*/
void AtribuiqtdMidias(Album *a, int qtd);

/*Atribui um Genero ao album
*inputs: um album e uma string com o nome digitado
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: adiciona um genero no album
*/
void AtribuiGenero(Album *a, char* genero);

/*Atribui uma Produtora ao album
*inputs: um album e uma string com o nome digitado
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: adiciona um produtor no album
*/
void AtribuiProdutoraAlbum(Album *a, char* produtora);

/*Imprime os dados basicos do album, sem imprimir suas midias
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeDadosBasicosAlbum(Album *a);

/*Imprime os dados completos do album, assim como imprime suas midias
*inputs: um album
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeAlbum(Album *a);

/*Imprime o nome do album
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeNomeAlbum(Album *a);    

/*Imprime o nome do Artista do album
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeArtistaAlbum(Album *a);

/*Imprime o Genero do album
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeGeneroAlbum(Album *a);

/*Imprime o nome da Produtora do album
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeProdutoraAlbum(Album *a);

/*Imprime a quantidade de midias do album
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeqtdMidias(Album *a);

/*Imprime o ano do album
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void ImprimeAnoAlbum(Album *a);

/*Pesquisa e Imprime os albuns que possuem um nome igual ao nome digitado pelo usuario
*inputs: um album e um nome
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: nenhuma
*/
void PesquisaAlbum(Album *a, char *nome);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: nenhuma
*/
void PesquisaMidiaAlbum(Album *a, char* nomeM);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome de Artista igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: nenhuma
*/
void PesquisaArtistaMidiaAlbum(Album *a, char* nomeA);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome de Compositor igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: nenhuma
*/
void PesquisarNomeCompositorAlbum(Album *a, char* nomeC);

/*Pesquisa dentro do Album e Imprime as midias que possuem um Genero  gual ao gemero digitado pelo usuario;
*inputs: um album e um nome;
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: nenhuma
*/
void PesquisarGeneroAlbum(Album *a, char* nomeG);

/*Pesquisa dentro do Album e Imprime as midias que possuem um nome de Produtora igual ao nome digitado pelo usuario;
*inputs: um album e um nome;
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: nenhuma
*/
void PesquisarProdutoraAlbum(Album *a, char* nomeP);

/*Retorna Midia de um Album;
*inputs: um album e a posição em que essa midia se encontra;
* pre-condicao: um album alocado e um ponteiro para caracter
* pos-condicao: retorna uma midia
*/
Midia* RetornaMidiaAlbum(Album *a, int posicao);


/*Salva dados no arquivo.txt
*inputs: um arquivo e um album
* pre-condicao: um album alocado e um arquivo
* pos-condicao: nenhuma
*/
void salvaDadosArquivoAlbum(FILE *arquivo, Album *a);

/*Apaga uma midia do Album
*inputs: um album 
* pre-condicao: um album alocado
* pos-condicao: nenhuma
*/
void apagaMidiaDoAlbum(Album *album, int id);

#endif