#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "album.h"
#include "midia.h"
#include "usuario.h"

//Tipo midia (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct servidor Servidor;

/*Aloca um servidor vazio
*inputs: vazio;
*outputs: retorna um servidor vazio, alocado
* pre-condicao: nenhuma
* pos-condicao: retorna um servidor vazio, alocado
*/
Servidor* AlocaServidor();

/*Retorna a quantidade de albuns
*inputs: servidor
* pre-condicao: servidor alocado
* pos-condicao: retorna um inteiro
*/
int RetornaQtdAlbum(Servidor *s);

/*Retorna a quantidade de usuarios
*inputs: servidor
* pre-condicao: servidor alocado
* pos-condicao: retorna um inteiro
*/
int RetornaQtdUsuario(Servidor *s);

/*Adiciona album no servidor
*inputs: um album e um servidor
* pre-condicao: servidor alocado
* pos-condicao: Adiciona album no servidor
*/
void AdicionaAlbumServidor(Servidor *s, Album *a);

/*Adiciona um usuario no servidor
*inputs: um album e um servidor
* pre-condicao: servidor alocado e album alocado
* pos-condicao: Adiciona um usuario no servidor
*/
void AdicionaUsuarioServidor(Servidor *s, Usuario *u);

/*Mostra os albuns do servidor
*inputs: servidor
* pre-condicao: servidor alocado e album alocado
* pos-condicao: nenhum
*/
void ImprimeAlbunsServidor(Servidor *s);

/*Mostra os usuarios no servidor
*inputs: servidor
* pre-condicao: servidor alocado
* pos-condicao: nenhum
*/
void ImprimeUsuarioServidor(Servidor *s);

/*Retorna um usuario
*inputs: servidor alocado
* pre-condicao: um servidor alocado e dois ponteiros para caracter
* pos-condicao: retorna uma midia
*/
Usuario* VerificaUsuarioServidor(Servidor *s,char *nickname, char *senha);

/*Retorna um album
*inputs: servidor alocado e um inteiro
* pre-condicao: um album alocado e um inteiro
* pos-condicao: retorna uma midia
*/
Album* RetornaAlbumEscolhido(Servidor *s, int identificador);

/*Retorna uma Midia
*inputs: um album e a posição em que essa midia se encontra;
* pre-condicao: um album alocado e dois inteiros
* pos-condicao: retorna uma midia
*/
Midia* RetornaMidia(Servidor *s, int idAlbum, int idMidia);

/*Pesquisa pelo nome do album
*inputs: um servidor, um ponteiro para caracter
* pre-condicao: um servidor alocado e um ponteiro para caracter
* pos-condicao: nenhum
*/
void PequisarNomeAlbum(Servidor *s, char* nomeAlb);

/*Adiciona uma midia pre existente em um album
*inputs: um servidor, um ponteiro para caracter
* pre-condicao: um servidor alocado e um ponteiro para caracter
* pos-condicao: nenhum
*/
void PesquisarNomeMidia(Servidor *s, char* nomeMid);

/*Adiciona uma midia pre existente em um album
*inputs: um servidor, um ponteiro para caracter
* pre-condicao: um servidor alocado e um ponteiro para caracter
* pos-condicao: nenhum
*/
void PesquisarNomeArtista(Servidor *s, char* nomeArt);

/*Adiciona uma midia pre existente em um album
*inputs: um servidor, um ponteiro para caracter
* pre-condicao: um servidor alocado e um ponteiro para caracter
* pos-condicao: nenhum
*/
void PesquisarNomeCompositor(Servidor *s, char* nomeC);

/*Adiciona uma midia pre existente em um album
*inputs: um servidor, um ponteiro para caracter
* pre-condicao: um servidor alocado e um ponteiro para caracter
* pos-condicao: nenhum
*/
void PesquisarGenero(Servidor *s, char* nomeG);

/*Adiciona uma midia pre existente em um album
*inputs: um servidor, um ponteiro para caracter
* pre-condicao: um servidor alocado e um ponteiro para caracter
* pos-condicao: nenhum
*/
void PesquisarProdutora(Servidor *s, char* nomeP);

/*Retorna um servidor
*inputs: um arquivo e um servidor
* pre-condicao: um arquivo e um servidor alocado
* pos-condicao: le os dados
*/
Servidor *lerDadosArquivo(FILE *arquivo, Servidor *servidor);

/*Salva os dados no arquivo
*inputs: um arquivo e um servidor
* pre-condicao: um arquivo e um servidor alocado
* pos-condicao: salva os dados
*/
void salvaDadosArquivo(FILE *arquivo, Servidor *servidor);

/*Mostra o album escolhido
*inputs: um servidor e um inteiro
* pre-condicao: um servidor alocado e um inteiro
* pos-condicao: nenhum
*/
void ImprimeAlbumEscolhidoServidor(Servidor *s, int id);

/*Retorna o id do usuario
*inputs: um servidor e um ponteiro para caracter
* pre-condicao: um servidor e um ponteiro para caracter alocados
* pos-condicao: retorna um inteiro
*/
int verificaLogin(Servidor *s, char *nickname);

/*Mostra todos os usuarios do sistema
*inputs: um servidor e um ponteiro para caracter
* pre-condicao: um servidor alocado
* pos-condicao: nenhum
*/
void ImprimeTodosUsuariosServidor(Servidor *servidor);

/*Mostra todos os albuns e midias do sistema
*inputs: um servidor
* pre-condicao: um servidor alocado
* pos-condicao: nenhum
*/
void ImprimeAlbunsEMidiasServidor(Servidor *servidor);

/*Apaga uma midia do servidor
*inputs: um servidor e dois inteiros
* pre-condicao: um servidor alocado
* pos-condicao: apaga uma midia
*/
void ApagaMidiaDoServidor(Servidor *servidor, int idAlbum, int idMidia);

#endif 