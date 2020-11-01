#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct historico Historico;

Historico* InicializaHistorico (char* nomeEditor, char* arquivo);
void ImprimeHistorico(Historico* hist, FILE* arq);
void DestroiHistorico(Historico* hist);


#endif /*HISTORICO_H*/

