#ifndef bst_h
#define bst_h

#include <stdio.h>
typedef struct arv Arv;
#include "fila.h"

Arv* bst_cria (void); 

void bst_imprime (Arv* a);

void bst_imprime_no(Arv *a);

void bst_level_order(Arv* arv, Fila* fila);

void printGivenLevel(Arv* arv, int level, Fila* fila);

Arv *bst_inicia(Arv *esq, Arv* dir, char valor);

int altura(Arv *a);

Arv* bst_libera (Arv* a);

#endif /* bst_h */