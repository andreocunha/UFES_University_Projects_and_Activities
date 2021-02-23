#ifndef bst_h
#define bst_h

#include <stdio.h>
typedef struct arv Arv;
#include "pilha.h"

Arv* bst_cria (void); 

void bst_imprime (Arv* a);

void bst_imprime_no(Arv *a);

void rec_preorder(Arv *a, Pilha* p);

void in_order(Arv *a, Pilha* p);

void post_order(Arv *a, Pilha* p);

Arv *bst_inicia(Arv *esq, Arv* dir, char valor);

int altura(Arv *a);

Arv* bst_libera (Arv* a);

#endif /* bst_h */