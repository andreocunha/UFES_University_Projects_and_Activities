#ifndef bst_h
#define bst_h

#include <stdio.h>
typedef struct arv Arv;

Arv* bst_cria (void); 

void bst_imprime (Arv* a);

Arv* bst_insere (Arv* a, int num);

Arv* bst_libera (Arv* a);

#endif /* bst_h */