#ifndef PILHA_H_
#define PILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha Pilha;
#include "bst.h"

Pilha *inicializaPilha(void);
void pushPilha(Pilha* pilha, Arv* no);
Arv* popPilha(Pilha *pilha);
void resetPilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void imprimePilha(Pilha *pilha);
void destroiPilha(Pilha *pilha);

#endif /*PILHA_H_*/