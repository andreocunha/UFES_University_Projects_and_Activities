#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

#include "utils.h"
#include "shell.h"
#include "commands.h"

Processos *p;

// tratamento de sinais do shell
void trataSinais(int signal){
    printf("\nEstou vacinada… desista!!\n");
}

// mata todos os processos filhos
void mataTodosOsProcessos(int pgid){
    if(pgid > 0){
        kill(pgid * -1, SIGKILL);
    }
    mataProcessos(p);
    liberaProcessos(p);
    p = inicializaProcessos();
}

// conta o numero de comandos na linha de comando
int contaQuantidadeComandos(char** arr){
    int qtdComandos = 0;
    for (int i = 0; arr[i] != NULL; i++){
        qtdComandos++;
    }

    return qtdComandos;
}

// faz a leitura e parse da linha de comando
char** leComandos(){
    char *comand = (char *)malloc(sizeof(char) * 500);
        
    scanf("%[^\n]", comand);
    getchar(); // remove o caracter \n

    char **arr = splitString(comand, ";");

    removeSpaces(arr);

    return arr;
}

int main(){
    p = inicializaProcessos();
    int pipe1[2], flag = 0, pgid = 0;

    if (pipe(pipe1) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    while (1){
        // tratamento de sinais
        signal(SIGINT, trataSinais);
        signal(SIGQUIT, trataSinais);
        signal(SIGTSTP, trataSinais);
        signal(SIGUSR1, trataSinais);

        // verifica se um filho terminou
        int status;
        waitpid(-1, &status, WNOHANG);
        if (WTERMSIG(status) == SIGUSR1) {
            mataTodosOsProcessos(pgid);
            if(pgid > 0){
                read(pipe1[0], &pgid, sizeof(int)); // le o valor de flag que foi escrito no pipe
                flag = 0;
            }
            imprimeGandalf();
            status = 0;
        }

        printf("psh> ");

        char **arr = leComandos();
        int qtdComandos = contaQuantidadeComandos(arr);

        if (qtdComandos == 1) { // Para processos não vacinados
            if(strcmp(arr[0], "term") == 0){ // Termina o shell              
                mataTodosOsProcessos(pgid);
                liberaProcessos(p);               
                return 0;
            }
            else if(strcmp(arr[0], "fg") == 0){ // Entra em foreground
                printf("\nOs processos estao em Foreground durante 30s\n");
                backgroundWait(pgid);
            }
            pshLaunchNaoVacinado(arr[0], p);
        }
        else { // Para processos vacinados
            for (int i = 0; i < qtdComandos; i++){
                pshLaunchVacinados(arr[i], pipe1, flag++);
                pgid = pegarPgid(pipe1);
            }
        }
    }
    return 0;
}