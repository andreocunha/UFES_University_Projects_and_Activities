#ifndef EDITOR_H
#define EDITOR_H


typedef struct editor Editor;

Editor* InicializaEditor (char* nome);
void ImprimeEditor(Editor* ed);
char* RetornaNomeEditor(Editor* ed);
void DestroiEditor(Editor* ed);


#endif /*EDITOR_H*/

