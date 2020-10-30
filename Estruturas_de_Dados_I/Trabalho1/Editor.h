#ifndef EDITOR_H
#define EDITOR_H


typedef struct editor Editor;

#include "ListaContribuicao.h"

Editor* InicializaEditor (char* nome);
void ImprimeEditor(Editor* ed);
void InsereContribuicaoEditor(Editor* ed, Contribuicao* contrib);
char* RetornaNomeEditor(Editor* ed);
void DestroiEditor(Editor* ed);


#endif /*EDITOR_H*/

