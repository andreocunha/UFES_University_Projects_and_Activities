#include <stdio.h>
#include "unionfind.h"
#include <time.h>

int
main()
{
    clock_t t; //variável para armazenar tempo
    t = clock(); //armazena tempo
    int num=100;
    Unionfind* vetor[num];
    inicLista(vetor, num);
    encontraPrimos(vetor, num);
    imprimePrimos(vetor, num);
    destroiVetor(vetor, num);
    
    t = clock() - t; //tempo final - tempo inicial
    printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));//imprime o tempo na tela

    return 0;
}