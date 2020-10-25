#ifndef ListaPagina_h
#define ListaPagina_h

#include "Pagina.h"

typedef struct celulaPagina CelulaPagina;
typedef struct listaPagina ListaPagina;


ListaPagina* InicializaListaPagina (void);

void InsereListaPagina(ListaPagina* lista, Pagina* ed);

Pagina* RemoveListaPagina(ListaPagina* lista, char* chave);

void ImprimeListaPagina(ListaPagina* lista);

void DestroiListaPagina(ListaPagina* lista);


#endif /* ListaPagina_h */