#include "pilha.h"
#define TAM 200

struct pilha
{
    Arv* no[TAM];
    int topo;
};

Pilha *inicializaPilha(void)
{
    Pilha* nova = (Pilha *)malloc(sizeof(Pilha));
    nova->topo = 0;
    return nova;
}

void pushPilha(Pilha* pilha, Arv* no)
{
    int posicao = pilha->topo;
    pilha->no[posicao] = no;
    pilha->topo++;
}

Arv* popPilha(Pilha *pilha)
{
    if (!pilha || pilha->topo == 0)
    {
        printf("Pilha vazia!!!\n");
        return NULL;
    }
    Arv* no = pilha->no[pilha->topo - 1]; 
    pilha->topo--;

    return no;
}

void resetPilha(Pilha* pilha)
{
    pilha->topo = 0;
}

int pilhaVazia(Pilha* pilha)
{
    if (!pilha || pilha->topo == 0)
    {
        return 1;
    }
    return 0;
}

void imprimePilha(Pilha *pilha)
{
    int i;
    if (!pilha)
        return;
    for (i = 0; i <= (pilha->topo - 1); i++)
    {
        bst_imprime_no(pilha->no[i]);
    }
    printf("\n");
}

void destroiPilha(Pilha *pilha)
{
    if (!pilha)
        return;

    free(pilha);
}