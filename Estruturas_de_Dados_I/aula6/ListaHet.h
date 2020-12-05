#ifndef ListaHetH_
#define ListaHetH_

#include <stdio.h>
#include "Aluno.h"
#include "Professor.h"


typedef struct listhet ListaHet;


ListaHet* InicLista(void);

void InsereAluno(ListaHet* lista, Aluno* al);

void InsereProfessor(ListaHet* lista, Professor* prof);

void ImprimeListaHet(ListaHet* lista);

float ValorChurrasco(ListaHet* lista);

void DestroiLista(ListaHet* lista);


#endif