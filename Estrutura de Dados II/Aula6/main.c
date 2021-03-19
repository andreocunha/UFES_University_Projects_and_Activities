#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char** argv)
{

    int qtdNum = atoi(argv[1]);;

    Item* itens = (Item*)malloc(sizeof(int) * qtdNum);

    for(int i = 0; i < qtdNum; i++)
    {
        scanf("%d", &itens[i]);
    }
    
    sort(itens, 0, qtdNum - 1);

    for (int i = 0; i < qtdNum; i++)
    {
        printf("%d ", itens[i]);
    }
    printf("\n");

    free(itens);

    return 0;
}