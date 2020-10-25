#ifndef ListaContribuicao_h
#define ListaContribuicao_h

#include "Contribuicao.h"

typedef struct celulaContribuicao CelulaContribuicao;
typedef struct listaContribuicao ListaContribuicao;


ListaContribuicao* InicializaListaContribuicao (void);

void InsereListaContribuicao(ListaContribuicao* lista, Contribuicao* contrib);

Contribuicao* RemoveListaContribuicao(ListaContribuicao* lista, char* chave);

void ImprimeListaContribuicao(ListaContribuicao* lista);

void DestroiListaContribuicao(ListaContribuicao* lista);


#endif /* ListaContribuicao_h */