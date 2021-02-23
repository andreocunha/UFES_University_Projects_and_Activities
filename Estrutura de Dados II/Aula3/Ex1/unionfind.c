#include "unionfind.h"
#include <stdlib.h>
#include <string.h>

struct unionfind
{
    int num;
    int marcador;
    // char marcador;
};

Unionfind** inicLista(Unionfind** vetor, int num)
{
    for (int i = 0; i < num; i++)
    {
        Unionfind* valor = (Unionfind*)malloc(sizeof(Unionfind));
        valor->num = i+2;
        valor->marcador = 1; //marcador int
        // valor->marcador = '1'; //marcador char
        vetor[i] = valor;
    }
    return vetor;
}

static void encontraMultiplos(Unionfind** vetor, int num, int pos)
{
    for (int i = pos+1; i < num; i++)
    {
        if(vetor[i]->num % vetor[pos]->num == 0)
        {
            vetor[i]->marcador = 0;//marcador int
            // vetor[i]->marcador = '0'; //marcador char
            
        }
    }
    
}

void encontraPrimos(Unionfind** vetor, int num)
{
    for (int i = 0; i < num; i++)
    {
        // marcador int
        if(vetor[i]->marcador == 1)
        {
            encontraMultiplos(vetor, num, i);
        }

        // marcador char
        // if(vetor[i]->marcador == '1')
        // {
        //     encontraMultiplos(vetor, num, i);
        // }
    }
}

void imprimePrimos(Unionfind** vetor, int num)
{
    for (int i = 0; i < num; i++)
    {
        // marcador int
        if(vetor[i]->marcador == 1){
            printf("%d ", vetor[i]->num);
        }

        // marcador char
        // if(vetor[i]->marcador == '1'){
        //     printf("%d ", vetor[i]->num);
        // }
    }
    printf("\n");
}

void destroiVetor(Unionfind** vetor, int num)
{
    for (int i = 0; i < num; i++)
    {
        free(vetor[i]);
    }
}