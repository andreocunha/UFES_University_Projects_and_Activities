#ifndef fila_h
#define fila_h

#include <stdlib.h>
#include <stdio.h>
typedef struct fila Fila;
typedef struct cel Cel;
#include "bst.h"


Fila* cria_fila();
void enqueue(Fila* fila, Arv* arv);
Arv* dequeue(Fila *fila);
void imprime_fila(Fila* fila);
void destroi_fila(Fila* fila);


#endif /* fila_h */