// #include "Fila.h"
// #include <stdio.h>
// #include <stdlib.h>

// #define TAM 10

// struct fila
// {
//     int ini; //indice do inicio da fila
//     int n;   //numero de alunos na fila
//     Aluno *alunos[TAM];
// };

// Fila *inicFila(void)
// {
//     Fila *f = (Fila *)malloc(sizeof(Fila));
//     f->ini = 0;
//     f->n = 0;
//     return f;
// }

// //insere fila (sempre no final da fila)
// void insereFila(Fila *f, Aluno *al)
// {
//     //testa se fila cheia
//     if (!f || f->n >= TAM || !al)
//     {
//         printf("\nPilha invalida, cheia ou aluno invalido!\n");
//         return;
//     }
//     //achando o final da fila circular!
//     int pos = (f->ini + f->n) % TAM;
//     //inserindo no final
//     f->alunos[pos] = al;
//     //incrementa numero de alunos
//     f->n++;
// }

// //Imprime do inicio ao fim da fila
// void imprimeFila(Fila *f)
// {
//     int i;
//     int pos = 0;
//     if (!f)
//         return;
//     for (i = 0; i < f->n; i++)
//     {
//         pos = (f->ini + i) % TAM;
//         ImprimeAluno(f->alunos[pos]);
//     }
// }

// // retira fila (sempre no inicio)
// Aluno *retiraFila(Fila *f)
// {
//     if (!f || f->n == 0)
//     {
//         printf("\nPilha invalida ou vazia!\n");
//         return NULL;
//     }
//     Aluno *al = f->alunos[f->ini];
//     //faz incremento circular do indice do inicio
//     f->ini = (f->ini + 1) % TAM;
//     f->n--;
//     return al;
// }

// //libera memoria da fila (e nao dos alunos)
// void destroiFila(Fila *f)
// {
//     if (!f)
//         return;
//     free(f);
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaComSentinela.h"
#include "Fila.h"

#define TAM 10

struct fila
{
  Lista *lista;
};

Fila *inicFila(void)
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->lista = InicLista();
  return fila;
}

//insere no final
void insereFila(Fila *fila, Aluno *aluno)
{
    if (!fila || !aluno)
    {
        printf("\nPilha invalida, cheia ou aluno invalido!\n");
        return;
    }
  InsereListaUlt(fila->lista, aluno);
}

//retira do começo
Aluno *retiraFila(Fila *fila)
{
  return RetiraPosicao(fila->lista, 0);
}

//do inicio ao fim
void imprimeFila(Fila *fila)
{
  ImprimeLista(fila->lista);
}

void destroiFila(Fila *fila)
{
  DestroiLista(fila->lista);
  free(fila);
}