#ifndef Utils_H
#define Utils_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "commands.h"

/*Faz a separacao dos comandos com base no caracter delimitador
 * inputs: string com o comando, caracter delimitador
 * output: um vetor de strings com os comandos
 * pre-condicao: string existe e delimitador eh um caracter valido
 * pos-condicao: nenhuma
 */
char **splitString(char *str, char *delimiter);

/*Remove os espacos em branco do comeco e final de uma string
 * inputs: vetor de strings
 * output: nenhum
 * pre-condicao: vetor de strings existe
 * pos-condicao: vetores de strings eh modificado
 */
void removeSpaces(char **arr);

/*Imprime o personagem gandalf
 * inputs: nenhum
 * output: nenhum
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
void imprimeGandalf();

/*Redireciona o stdout para um arquivo
 * inputs: nome do arquivo (string)
 * output: um inteiro com o valor do arquivo criado
 * pre-condicao: nome do arquivo eh valido
 * pos-condicao: nenhuma
 */
int redirecionaStdout(char *arquivo);

/*Pega o valor do pid do grupo de vacinados que esta no pipe
 * inputs: pipe
 * output: um inteiro com o valor do pid do grupo de vacinados
 * pre-condicao: pipe existe
 * pos-condicao: pipe nao eh modificado
 */
int pegarPgid(int pipe1[2]);

/*Roda os processos que estavam em background para o foreground durante 30s e depois volta ao background
 * inputs: pid do grupo de processos vacinados
 * output: nenhum
 * pre-condicao: pid do grupo de processos vacinados eh valido
 * pos-condicao: nenhuma
 */
void backgroundWait(int pgid);

#endif