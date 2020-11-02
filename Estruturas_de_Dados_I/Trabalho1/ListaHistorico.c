#include "ListaHistorico.h"



struct celulaHistorico
{
    Historico* hist;
    CelulaHistorico* prox;
};


struct listaHistorico
{
    CelulaHistorico* prim;
    CelulaHistorico* ult;
};

ListaHistorico* InicializaListaHistorico (void)
{
    ListaHistorico* lista = (ListaHistorico*)malloc(sizeof(ListaHistorico));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void InsereListaHistorico(ListaHistorico* lista, Historico* hist)
{
    CelulaHistorico* nova = (CelulaHistorico*)malloc(sizeof(CelulaHistorico));
    nova->hist = hist;
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

void ImprimeListaHistorico(ListaHistorico* lista, FILE* arq)
{
    CelulaHistorico* p;

    printf("--> Historico de contribuicoes\n");
    fprintf(arq, "--> Historico de contribuicoes\n");

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        ImprimeHistorico(p->hist, arq);
    }
    printf("\n");
    fprintf(arq, "\n");
}

Historico* RetornaHistorico(ListaHistorico* lista, char* chave)
{
    CelulaHistorico* p = lista->prim;

    for (p = lista->prim; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNomeEditorHistorico(p->hist), chave)== 0)
        {
            return p->hist;
        }
    }
    return NULL;
}

void DestroiListaHistorico(ListaHistorico* lista)
{
    CelulaHistorico* p = lista->prim;
    CelulaHistorico* temp;

    while (p != NULL)
    {
        temp = p;
        p = p->prox;
        DestroiHistorico(temp->hist);
        free(temp);
    }
    free(lista);
}

