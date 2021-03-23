#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <string.h>

extern void sort(Item *a, int lo, int hi);

int main(int argc, char** argv)
{
    FILE *arqLeitura;
    FILE *arqSaida;
    int qtdNum = atoi(argv[1]);

    arqLeitura = fopen(argv[2], "rt");
    if (arqLeitura == NULL)  // Se houve erro na abertura
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }

    arqSaida = fopen(argv[3], "wt");
    if (arqSaida == NULL)
    {
        printf("Problemas na criacao do arquivo\n");
        exit(1);
    }

    Item* itens = (Item*)malloc(sizeof(int) * qtdNum);

    for(int i = 0; i < qtdNum; i++)
    {
        fscanf(arqLeitura, "%d", &itens[i]);
    }

    sort(itens, 0, qtdNum);

    for (int i = 0; i < qtdNum; i++)
    {
        fprintf(arqSaida, "%d\n", itens[i]);
    }

    printf("\n");

    fclose(arqLeitura);
    fclose(arqSaida);
    free(itens);

    return 0;
}