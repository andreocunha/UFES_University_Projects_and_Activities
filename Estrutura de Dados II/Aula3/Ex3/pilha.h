#ifndef PILHA_H_
#define PILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha Pilha;

Pilha *inicializaPilha(void);
float calculaExpressao(Pilha* operando, Pilha* operador, char* expressao);
void pushPilha(Pilha* pilha, char* valor);
char* popPilha(Pilha *pilha);
void imprimePilha(Pilha *pilha);
void destroi(Pilha *pilha);

#endif /*PILHA_H_*/