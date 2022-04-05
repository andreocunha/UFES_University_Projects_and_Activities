#include "commands.h"

struct processos {
  int pidsProcessos[100];
  int qtdProcessos;
};

Processos* inicializaProcessos(){
    Processos* p = (Processos*)malloc(sizeof(Processos));
    p->qtdProcessos = 0;
    return p;
}

void adicionaProcesso(Processos* p, int pid){
    p->pidsProcessos[p->qtdProcessos] = pid;
    p->qtdProcessos++;
}

void mataProcessos(Processos* p){
    for(int i = 0; i < p->qtdProcessos; i++){
        kill(p->pidsProcessos[i], SIGKILL);
    }
}

void imprimeProcessos(Processos* p){
    for(int i = 0; i < p->qtdProcessos; i++){
        printf("%d\n", p->pidsProcessos[i]);
    }
    if(p->qtdProcessos == 0){
        printf("Nenhum processo em execução\n");
    }
    printf("QTD: %d\n", p->qtdProcessos);
}

void liberaProcessos(Processos* p){
  free(p);
}