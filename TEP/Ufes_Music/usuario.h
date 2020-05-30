#ifndef USUARIO_H
#define USUARIO_H
#include "playlist.h"

//Tipo usuario (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct usuario Usuario;

/*Aloca um Usuario vazio
*inputs: vazio;
*outputs: retorna um Usuario vazio, alocada
* pre-condicao: nenhuma
* pos-condicao: retorna um Usuario vazio, alocada
*/
Usuario* AlocaUsuario();

/*Cria um novo usuario
*inputs: varios dados que compoe um usuario
* pre-condicao: um usuario alocado e varios ponteiros de char, inteiro e float
* pos-condicao: Cria um novo usuario no sistema
*/
void CriaUsuario(Usuario* u,char *nomeCompleto, char* nickname,char* senha);

/*Apaga uma playlist de usuario
*inputs: um usuario alocado e varios ponteiros de char
* pre-condicao: um usuario alocado
* pos-condicao: Apaga uma playlist de usuario
*/
void ApagaPlaylistUsuario(Usuario *u, int posicao);

/* Adiciona uma playlist pro usuario
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: Adiciona uma playlist pro usuario
*/
void AdicionaPlaylistUsuario(Usuario *u, Playlist *p);

/* Troca duas midias de posicao na playlist
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: Troca duas midias de posicao na playlist
*/
void TrocaPlaylist(Usuario *u, int posicao1, int posicao2);

/*Mostra os dados de um usuario
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: nenhuma
*/
void ImprimeUsuario(Usuario *u);

/*Retrona um nickname
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: nenhuma
*/
char* RetornaNickname(Usuario *u);

/*Retorna uma senha
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: nenhuma
*/
char* RetornaSenha(Usuario *u);

/*Retorna uma playlist pro usuario
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: uma playlist alocada
*/
Playlist* RetornaPlaylistUsuario(Usuario *u, int idplay);

/*cria o administrador no sistema
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: cria um usuario
*/
void criaUsuarioMestre(Usuario *usuario);

/*Mostra todos os usuarios
*inputs: um usuario alocado
* pre-condicao: um usuario alocado
* pos-condicao: nenhuma
*/
void imprimeTodosUsuarios(Usuario *u);

/*Salva dados no arquivo.txt
*inputs: um arquivo e uma midia
* pre-condicao: um usuario alocado e um arquivo
* pos-condicao: escreve no txt
*/
void SalvaDadosArquivoUsuario(FILE *arquivo, Usuario *usuario);

#endif 
