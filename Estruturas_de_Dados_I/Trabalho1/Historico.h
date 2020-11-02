#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct historico Historico;

Historico* InicializaHistorico (char* nomeEditor, char* arquivo);
void ImprimeHistorico(Historico* hist, FILE* arq);
void AlteraStatusHistorico(Historico* hist);
char RetornaStatusHistorico(Historico* hist);
char* RetornaNomeEditorHistorico(Historico* hist);
void DestroiHistorico(Historico* hist);


#endif /*HISTORICO_H*/

