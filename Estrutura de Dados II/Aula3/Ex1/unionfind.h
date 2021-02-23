#ifndef unionfind_h
#define unionfind_h

typedef struct unionfind Unionfind;

#include <stdio.h>

Unionfind** inicLista(Unionfind** vetor, int num);
void encontraPrimos(Unionfind** vetor, int num);
void imprimePrimos(Unionfind** vetor, int num);
void destroiVetor(Unionfind** vetor, int num);

#endif
