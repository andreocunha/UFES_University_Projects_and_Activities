#ifndef ListaPagina_h
#define ListaPagina_h

typedef struct celulaPagina CelulaPagina;
typedef struct listaPagina ListaPagina;

#include "Pagina.h"

ListaPagina* InicializaListaPagina (void);

void InsereListaPagina(ListaPagina* lista, Pagina* pag);

Pagina* RemoveListaPagina(ListaPagina* lista, char* chave);

void ImprimeListaPagina(ListaPagina* lista);

void DestroiListaPagina(ListaPagina* lista);


#endif /* ListaPagina_h */