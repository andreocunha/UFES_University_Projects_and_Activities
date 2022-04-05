#include "utils.h"

// funcao que faz o split de uma string com delimitador e retorna um vetor de strings
char **splitString(char *str, char *delimiter)
{
    char *token;
    char **arr = (char **)malloc(sizeof(char *) * 100);
    int i = 0;
    token = strtok(str, delimiter);
    while (token != NULL)
    {
        arr[i] = (char *)malloc(sizeof(char) * 100);
        strcpy(arr[i], token);
        i++;
        token = strtok(NULL, delimiter);
    }
    arr[i] = NULL;
    return arr;
}

// funcao que remove os espaços em branco no comeco e fim de uma string
void removeSpaces(char **arr){
    int i = 0;
    while (arr[i] != NULL)
    {
        if(arr[i][0] == ' '){
            arr[i] = arr[i] + 1;
        }
        if(arr[i][strlen(arr[i])-1] == ' '){
            arr[i][strlen(arr[i])-1] = '\0';
        }
        i++;
    }
}

// imprime o personagem gandalf
void imprimeGandalf(){
    printf("\n"
         "                         ,---.\n"
         "                        /    |\n"
         "                       /     |\n"
         "                      /      |\n"
         "                     /       |\n"
         "                ___,'        |\n"
         "              <  -'          :\n"
         "               `-.__..--'``-,_\\_\n"
         "                  |o/ ` :,.)_`>\n"
         "                  :/ `     ||/)\n"
         "                  (_.).__,-` |\\ \n"
         "                  /( `.``   `| :\n"
         "                  \'`-.)  `  ; ;\n"
         "                  | `       /-<\n"
         "                  |     `  /   `.\n"
         "  ,-_-..____     /|  `    :__..-'\\\n"
         " /,'-.__\\  ``-./ :`      ;       \\\n"
         " `\\ `\\  `\\  \\ :  (   `  /  ,   `. \\\n"
         "   \\` \\   \\   |  | `   :  :     .\\\\\n"
         "    \\ `\\_  ))  :  ;     |  |      ): :\n"
         "   (`-.-'\\ ||  |\\ \\   ` ;  ;       | |\n"
         "    \\-_   `;;._   ( `  /  /_       | |\n"
         "     `-.-.// ,'`-._\\__/_,'         ; |\n"
         "        \\:: :     /     `     ,   /  |\n"
         "         || |    (        ,' /   /   |\n"
         "         ||                ,'   /    |\n"
         " ________ Unfortunately all process died!________\n"
         " ___ Vaccination should be a social contract!____\n"
         " ____Cooperation was the morally right choice!___ \n");
    
}


// funcao que redireciona o stdout para um arquivo
int redirecionaStdout(char *arquivo){
    int fd = open(arquivo, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    return fd;
}

// pega o gpid que esta no pipe
int pegarPgid(int pipe1[2]){ 
    int pgid = 0;

    read(pipe1[0], &pgid, sizeof(pgid));
    write(pipe1[1], &pgid, sizeof(pgid));

    return pgid;
}

// coloca um grupo de processos em foreground, mantem por 30s e coloca novamente em background
void backgroundWait(int pgid){
    tcsetpgrp(0, pgid); // coloca o grupo de processos em foreground

    sleep(30); // espera 30s

    signal(SIGTTOU, SIG_IGN); // ignora o signal SIGTTOU
    tcsetpgrp(0, getppid()); // coloca o grupo de processos em background
    signal(SIGTTOU, SIG_DFL); // volta o signal SIGTTOU para o default

    printf("\nOs processos voltaram para Background\n");
}
