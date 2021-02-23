#ifndef aluno_h
#define aluno_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* InicAluno (char* nome, float nota);

char* RetornaNome(Aluno* al);

float RetornaNota(Aluno* al);

float RetornaMedia(Aluno** al, int qtd);

void DestroiAluno(Aluno* al);

#endif