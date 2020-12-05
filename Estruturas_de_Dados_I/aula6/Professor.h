#ifndef Professor_h
#define Professor_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct professor Professor;

Professor* InicProfessor (int mat, char* nome, float CR);

void ImprimeProfessor( Professor* prof);

int RetornaSiape(Professor* prof);

char* RetornaNomeProfessor(Professor* prof);

float RetornaSalario(Professor* prof);

void DestroiProfessor(Professor* prof);


#endif