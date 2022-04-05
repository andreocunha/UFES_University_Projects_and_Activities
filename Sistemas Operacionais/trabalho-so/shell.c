#include "shell.h"

// funcao de tratar sinais para os nao vacinados
void trataSinaisNaoVacinados(int signal) {
  exit(0);
}

int pshLaunchNaoVacinado(char *args, Processos* p){
  pid_t pid, wpid;
  int status;

  // tratamento de sinais
  signal(SIGINT, trataSinaisNaoVacinados);
  signal(SIGTSTP, trataSinaisNaoVacinados);
  signal(SIGQUIT, trataSinaisNaoVacinados);
  signal(SIGUSR1, trataSinaisNaoVacinados);

  pid = fork();

  if (pid == 0) {// Children process
    int fd = -1;

    // se arr[0] tiver ">" dentro da string entao chama a funcao redirecionaStdout
    if (strstr(args, ">") != NULL){
      char **arquivo = splitString(args, ">");
      removeSpaces(arquivo);
      fd = redirecionaStdout(arquivo[1]);
    }
      
    setpgid(getpid(), getpid()); // cada processo tem seu proprio grupo de processos

    // faz um split na string args
    char *delimiter = " ";
    char **arr = splitString(args, delimiter);
    removeSpaces(arr);

    if (execvp(arr[0], arr) == -1) {
      perror("psh");
    }

    if(fd != -1) {
      close(fd);
    }

    exit(EXIT_FAILURE);
  }
  else {
    adicionaProcesso(p, pid); // adiciona o pid do processo na lista de processos
  }

  return 1;
}

int pshLaunchVacinados(char *args, int pipe1[2], int flag){
  pid_t pid, wpid;
  int status;

  pid = fork();

  if (pid == 0) { // Children process
    pid_t pgid = 0;

    // tratamento de sinais
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    
    if(flag == 0){
      close(pipe1[0]);
      pgid = getpid();
      write(pipe1[1], &pgid, sizeof(pgid));
    }
    else {
      read(pipe1[0], &pgid, sizeof(pgid));
      write(pipe1[1], &pgid, sizeof(pgid));
    }

    setpgid(getpid(), pgid); // cada processo vai ter o pid do grupo de processos do primeiro processo

    // faz um split na string args
    char *delimiter = " ";
    char **arr = splitString(args, delimiter);
    removeSpaces(arr);

    if (execvp(arr[0], arr) == -1) {
      perror("psh");
    }

    close(pipe1[0]);
    close(pipe1[1]);

    exit(EXIT_FAILURE);
  } 

  return 1;
}
