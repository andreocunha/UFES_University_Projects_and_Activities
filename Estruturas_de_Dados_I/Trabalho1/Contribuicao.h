#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H


typedef struct contribuicao Contribuicao;

#include "Editor.h"

Contribuicao* InicializaContribuicao (char* texto, char* arq, Editor* ed);
void ImprimeContribuicao(Contribuicao* contrib);
char* RetornaTextoContribuicao(Contribuicao* contrib);
void DestroiContribuicao(Contribuicao* contrib);


#endif /*CONTRIBUICAO_H*/

