#include "ListaLink.h"


struct celulaLink
{
    Pagina* pag;
    CelulaLink* prox;
};


struct listaLink
{
    CelulaLink* prim;
    CelulaLink* ult;
};

ListaLink* InicializaListaLink (void)
{
    ListaLink* lista = (ListaLink*)malloc(sizeof(ListaLink));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void InsereListaLink(ListaLink* lista, Pagina* pag)
{
    CelulaLink* nova = (CelulaLink*)malloc(sizeof(CelulaLink));
    nova->pag = pag;
    nova->prox = NULL;

    if(lista->prim == NULL && lista->ult == NULL)
    {
        lista->prim = nova;
        lista->ult = nova;
    }
    else
    {
        lista->ult->prox = nova;
        lista->ult = nova; 
    }
}


void RemoveListaLink(ListaLink* lista, char* chave)
{
    CelulaLink* p = lista->prim;
    CelulaLink* ant = NULL;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomePagina (p->pag), chave)== 0)
        {
            break;
        }
        ant = p;
    }

    if(p == NULL)
    {
        return;
    }

    // se for o unico
    if(p == lista->prim && p == lista->ult)
    {
        lista->prim = lista->ult = NULL;
    }
    else if (p == lista->prim) // se for o primeiro da lista
    {
        lista->prim = p->prox;
    }
    else if (p == lista->ult) // se for o ultim da lista
    {
        lista->ult = ant;
        lista->ult->prox = NULL;
    }
    else // caso comum
    {
        ant->prox = p->prox;
    }
    
    free(p);
}

void ImprimeListaLink(ListaLink* lista, FILE* arq)
{
    CelulaLink* p;

    printf("--> Links\n");
    fprintf(arq, "--> Links\n");

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        printf("%s %s\n", RetornaNomePagina(p->pag), RetornaNomeArquivo(p->pag));
        fprintf(arq, "%s %s\n", RetornaNomePagina(p->pag), RetornaNomeArquivo(p->pag));
    }
    printf("\n");
    fprintf(arq, "\n");
}

static CelulaLink* RetornaCelulaLink(ListaLink* lista ,char* chave)
{
    CelulaLink* p = lista->prim;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomePagina (p->pag), chave)== 0)
        {
            return p;
        }
    }
    return NULL;
}


Pagina* RetornaPaginaListaLink(ListaLink* lista, char* chave)
{
    CelulaLink* link = RetornaCelulaLink(lista, chave);
    if(link == NULL)
    {
        return NULL;
    }
    return link->pag;
}


void listaTodosCaminhosPossiveis(Pagina* pag, ListaLink* visited, ListaPagina* listaPag)
{
    InsereListaLink(visited, pag);

    ListaLink* listaLink = RetornaListaLinkPagina(listaPag, RetornaNomePagina(pag));
    CelulaLink* p;
    char* nomePag;

    for (p = listaLink->prim; p!=NULL; p = p->prox) {
        nomePag = RetornaNomePagina(p->pag);

        if(RetornaCelulaLink(visited, nomePag) == NULL){
            listaTodosCaminhosPossiveis(p->pag, visited, listaPag);
        }
    }
}


void DestroiListaLink(ListaLink* lista)
{
    CelulaLink* p = lista->prim;
    CelulaLink* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        free(temp);
    }
    free(lista);
}

