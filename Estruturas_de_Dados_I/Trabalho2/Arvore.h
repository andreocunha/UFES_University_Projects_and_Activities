#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore Arvore;
Arvore *criaArvore(void);
Arvore *Parsing(Arvore *arv, char *texto, int *pos);
float calculaEquacao(Arvore *arvore);
int vaziaArvore(Arvore *arvore);
void imprimeArvore(Arvore *arvore);
Arvore *liberaArvore(Arvore *arvore);

#endif /*ARVORE_H_*/
