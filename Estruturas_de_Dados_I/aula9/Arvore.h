#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

typedef struct arvore Arvore;
Arvore *inicArvore(void);
Arvore *criaArvore(Aluno *aluno, Arvore *esquerda, Arvore *direita);
Arvore *arvorePai(Arvore *arvore, char *nome);
Aluno *informacaoNoArvore(Arvore *arvore);
int vaziaArvore(Arvore *arvore);
int pertenceArvore(Arvore *arvore, char *nome);
int folhas(Arvore *arvore);
int ocorrencias(Arvore *arvore, char *nome);
int altura(Arvore *arvore);
void imprimeArvore(Arvore *arvore);
Arvore *liberaArvore(Arvore *arvore);

#endif /*ARVORE_H_*/
