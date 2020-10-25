#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H


typedef struct contribuicao Contribuicao;

Contribuicao* InicializaContribuicao (char* texto);
void ImprimeContribuicao(Contribuicao* contrib);
char* RetornaTextoContribuicao(Contribuicao* contrib);
void DestroiContribuicao(Contribuicao* contrib);


#endif /*CONTRIBUICAO_H*/

