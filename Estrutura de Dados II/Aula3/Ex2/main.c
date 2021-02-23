#include <stdio.h>
#include <time.h>
#include "listacircular.h"

int
main()
{
    clock_t t; //variável para armazenar tempo
    t = clock(); //armazena tempo
    Listacircular* lista = inicializaLista();

    int N = 10;
    int M = 5;

    for(int i = 1; i <= N; i++)
    {
        insereLista(lista, i);
    }
    // imprimeLista(lista);
    int lider = encontraLider(lista, M);
    printf("Lider: %d\n", lider);
    destroiLista(lista);

    t = clock() - t; //tempo final - tempo inicial
    printf("Tempo de execucao: %lfms", ((double)t)/((CLOCKS_PER_SEC/1000)));//imprime o tempo na tela

    return 0;
}