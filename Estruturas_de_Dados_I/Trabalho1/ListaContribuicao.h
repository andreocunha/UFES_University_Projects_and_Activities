#ifndef ListaContribuicao_h
#define ListaContribuicao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"
#include "Editor.h"

typedef struct celulaContribuicao CelulaContribuicao;
typedef struct listaContribuicao ListaContribuicao;


ListaContribuicao* InicializaListaContribuicao (void);

void InsereListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib, Editor* ed);

void RemoveListaContribuicao(ListaContribuicao* lista, char* chave);

void RemoveCelulaListaContribuicao(ListaContribuicao* lista, char* chave);

Contribuicao* RetornaContribuicaoLista(ListaContribuicao* lista, char* chave);

Editor* RetornaEditorListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib);

void ImprimeListaContribuicao(ListaContribuicao* lista, FILE* arq);

void ImprimeListaContribuicaoEditor(ListaContribuicao* lista);

void DestroiListaContribuicao(ListaContribuicao* lista);

void DestroiCelulaListaContribuicao(ListaContribuicao* lista);


#endif /* ListaContribuicao_h */