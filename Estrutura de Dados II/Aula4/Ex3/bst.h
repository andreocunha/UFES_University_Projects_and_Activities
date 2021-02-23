#ifndef bst_h
#define bst_h

#include <stdio.h>
typedef struct arv Arv;

Arv* bst_cria (void); 

void bst_imprime (Arv* a);

void rec_preorder(Arv *a);

void in_order(Arv *a);

void post_order(Arv *a);

Arv *bst_inicia(Arv *esq, Arv* dir, char valor);

int altura(Arv *a);

Arv* bst_libera (Arv* a);

#endif /* bst_h */