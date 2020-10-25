#ifndef ListaEditor_h
#define ListaEditor_h

#include "Editor.h"

typedef struct celulaEditor CelulaEditor;
typedef struct listaEditor ListaEditor;


ListaEditor* InicializaListaEditor (void);

void InsereListaEditor(ListaEditor* lista, Editor* ed);

Editor* RemoveListaEditor(ListaEditor* lista, char* chave);

void ImprimeListaEditor(ListaEditor* lista);

void DestroiListaEditor(ListaEditor* lista);


#endif /* ListaEditor_h */