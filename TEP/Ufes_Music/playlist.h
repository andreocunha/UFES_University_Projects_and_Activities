#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "midia.h"

//Tipo playlist (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct playlist Playlist;

/*Aloca um Playlist vazio
*inputs: vazio;
*outputs: retorna um playlist vazio, alocada
* pre-condicao: nenhuma
* pos-condicao: retorna um playlist vazio, alocada
*/
Playlist* AlocaPlaylist();

/*Cria um novo playlist
*inputs: varios dados que compoe um playlist
* pre-condicao: um playlist alocado e varios ponteiros de char e inteiros
* pos-condicao: Cria um novo playlist no sistema
*/
void CriaPlaylist(Playlist *p, char* nomep, char* colab1, char* colab2, int qtdColab, int qtdMidia);

/*Adiciona uma playlist de playlist
*inputs: uma playlist alocado e uma midia
* pre-condicao: um playlist alocado
* pos-condicao: Adiciona uma playlist de playlist
*/
void AdicionaMidiaPlaylist(Playlist *p, Midia *m);

/*Retorna a quantidade de midias
*inputs: um playlist alocado
* pre-condicao: um playlist alocado
* pos-condicao: Retorna a quantidade de midias
*/
int RetornaQtdMidias(Playlist *p);

/*Apaga uma midia playlist de playlist
*inputs: um playlist alocado e um inteiro
* pre-condicao: um playlist alocado
* pos-condicao: Apaga uma midia playlist de playlist
*/
void ApagaMidiaPlaylist(Playlist *p, int posicao);

/*Troca a ordem de duas midias na playlist
*inputs: um playlist alocado e dois inteiros
* pre-condicao: um playlist alocado
* pos-condicao: Troca a ordem de duas midias na playlist
*/
void TrocaMidia(Playlist *p, int posicao1, int posicao2);

/*Mostra as playlists
*inputs: um playlist alocado e varios ponteiros de char
* pre-condicao: um playlist alocado
* pos-condicao: nenhuma
*/
void ImprimePlaylist(Playlist *p);

/*Mostra o nome da playlist
*inputs: um playlist alocado e varios ponteiros de char
* pre-condicao: um playlist alocado
* pos-condicao: nenhum
*/
void ImprimeNomePlaylist(Playlist *p);   

/*Mostra os colaboradores
*inputs: um playlist alocado e varios ponteiros de char
* pre-condicao: um playlist alocado
* pos-condicao: nenhum
*/
void ImprimeColaboradoresPlaylist(Playlist *p);

/*Mostra as midias da playlist
*inputs: um playlist alocado e varios ponteiros de char
* pre-condicao: um playlist alocado
* pos-condicao: nenhum
*/
void ImprimeMidiasPlaylist(Playlist *p);

/*Edita o nome da playlist
*inputs: um playlist alocado e varios ponteiros de char
* pre-condicao: um playlist alocado
* pos-condicao: Edita o nome da playlist
*/
void AtribuiNomePlaylist(Playlist *p, char *nomep);

/*Troca a ordem das midias
*inputs: um playlist alocado e varios ponteiros de char
* pre-condicao: um playlist alocado
* pos-condicao: Troca a ordem das midias
*/
void trocaMidias(Playlist *p, int pos1, int pos2);


#endif