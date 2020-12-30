#ifndef LISTAALUNO_H_
#define LISTAALUNO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listagenerica.h"
#include "Aluno.h"

ListaGenerica *retiraAluno(ListaGenerica *lista, int mat);
int pertenceAluno(ListaGenerica *lista, int mat);
void imprimeListaAlunos(ListaGenerica *lista);
float mediaTurma(ListaGenerica *lista);

#endif /* LISTAALUNO_H_ */