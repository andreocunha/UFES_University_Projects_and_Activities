#ifndef LISTCIRCULAR_H_
#define LISTCIRCULAR_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct listacircular Listacircular;
typedef struct cel Celula;


Listacircular* inicializaLista(void);

void insereLista(Listacircular* lista, int num);

int encontraLider(Listacircular* lista, int num);

void imprimeLista(Listacircular* lista);

void destroiLista(Listacircular* lista);


#endif /*LISTCIRCULAR_H_*/