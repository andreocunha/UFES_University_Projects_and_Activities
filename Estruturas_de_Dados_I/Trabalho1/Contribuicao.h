#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contribuicao Contribuicao;

Contribuicao* InicializaContribuicao (char* texto, char* arq);
void ImprimeContribuicao(Contribuicao* contrib, FILE* arq);
char* RetornaTextoContribuicao(Contribuicao* contrib);
char* RetornaArquivoContribuicao(Contribuicao* contrib);
void DestroiContribuicao(Contribuicao* contrib);


#endif /*CONTRIBUICAO_H*/

