#ifndef Shell_H
#define Shell_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

/*Executa os processos nao vacinados
 * inputs: string com o comando a ser executado e uma struct de processos
 * output: um inteiro com o valor 1 se tudo ocorreu bem
 * pre-condicao: comando existe e processos existe
 * pos-condicao: o comando foi executado e o pid do processo filho foi adicionado ao vetor de processos
 */
int pshLaunchNaoVacinado(char *args, Processos * p);

/*Executa os processos vacinados
 * inputs: string com o comando a ser executado, um pipe, e um inteiro com uma flag (indica se o processo eh o primeiro ou nao)
 * output: um inteiro com o valor 1 se tudo ocorreu bem
 * pre-condicao: comando existe, pipe existe e flag eh um inteiro
 * pos-condicao: o comando foi executado e o pid do grupo de processos foi adicionado no pipe
 */
int pshLaunchVacinados(char *args, int pipe1[2], int flag);

#endif