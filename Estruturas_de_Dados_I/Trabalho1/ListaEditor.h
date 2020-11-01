#ifndef ListaEditor_h
#define ListaEditor_h

typedef struct celulaEditor CelulaEditor;
typedef struct listaEditor ListaEditor;

#include "Editor.h"
#include "ListaContribuicao.h"

ListaEditor* InicializaListaEditor (void);

void InsereListaEditor(ListaEditor* lista, Editor* ed);

Editor* RetornaEditor(ListaEditor* lista ,char* chave);

void RemoveListaEditor(ListaEditor* lista, char* chave);

void InsereContribuicaoListaEditor(ListaEditor* lista, Contribuicao* contrib, char* chave);

void ImprimeListaEditor(ListaEditor* lista);

void DestroiListaEditor(ListaEditor* lista);


#endif /* ListaEditor_h */