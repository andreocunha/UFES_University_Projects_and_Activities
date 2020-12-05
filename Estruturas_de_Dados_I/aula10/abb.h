#ifndef abb_h
#define abb_h

#include <stdio.h>
#include "Aluno.h"
typedef struct arv Arv;

Arv* abb_cria (void); 

void abb_imprime (Arv* a);

//retorna o ponteiro para o nó ou NULL 
Arv* abb_busca (Arv* r, int chave);

Arv* abb_insere (Arv* a, Aluno* al);

Arv* abb_retira (Arv* r, int v);

//essa fica com os alunos! :)
Arv* abb_libera (Arv* a);

#endif /* abb_h */