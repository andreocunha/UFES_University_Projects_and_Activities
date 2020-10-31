#ifndef ListaEditor_h
#define ListaEditor_h

typedef struct celulaEditor CelulaEditor;
typedef struct listaEditor ListaEditor;

#include "Editor.h"

ListaEditor* InicializaListaEditor (void);

void InsereListaEditor(ListaEditor* lista, Editor* ed);

Editor* RetornaEditor(ListaEditor* lista ,char* chave);

void RemoveListaEditor(ListaEditor* lista, char* chave);

void ImprimeListaEditor(ListaEditor* lista);

void DestroiListaEditor(ListaEditor* lista);


#endif /* ListaEditor_h */