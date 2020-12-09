#ifndef hash_h
#define hash_h

#include <stdio.h>
#include "palavra.h"
//Define o tipo opaco que contém a Hash
typedef struct hash Hash;
Hash* inicHash (int tamanho);
//Faz acesso à hash realizando 2 possíveis operações:
//1) inserção, caso a palavra não esteja na hash
//2) incremento de ocorrência, caso a palavra já esteja na hash
Palavra* acessa (Hash* h, char* string);
int contaPalavras (Hash* h);
void imprimeHash (Hash* h);
void liberaHash(Hash* h);

#endif