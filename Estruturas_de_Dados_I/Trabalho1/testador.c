#include <stdio.h>
#include "ListaEditor.h"
#include "ListaPagina.h"
#include "ListaContribuicao.h"
#include "ListaLink.h"

int
main(int argc, char *argv[])
{

    // Teste para os editores
    // Editor* andre = InicializaEditor("Andre");
    // Editor* artur = InicializaEditor("Artur");
    // Editor* patricia = InicializaEditor("Patricia");
    
    // ListaEditor* listaEditor = InicializaListaEditor();
    // InsereListaEditor(listaEditor, andre);
    // InsereListaEditor(listaEditor, artur);
    // InsereListaEditor(listaEditor, patricia);

    // ImprimeListaEditor(listaEditor);

    // printf("\n");

    // RemoveListaEditor(listaEditor, "Andre");

    // ImprimeListaEditor(listaEditor);
    // printf("\n");

    // DestroiListaEditor(listaEditor);
    // DestroiEditor(andre);
    // DestroiEditor(artur);
    // DestroiEditor(patricia);


    // Teste para as paginas
    Pagina* fisica = InicializaPagina("fisica");
    Pagina* artes = InicializaPagina("artes");
    Pagina* ufes = InicializaPagina("ufes");

    Contribuicao* contribuicao1 = InicializaContribuicao("contribuicao1");
    Contribuicao* contribuicao2 = InicializaContribuicao("contribuicao2");
    Contribuicao* contribuicao3 = InicializaContribuicao("contribuicao3");
    
    InsereListaContribuicao(RetornaContribuicaoPagina(fisica), contribuicao1);
    InsereListaContribuicao(RetornaContribuicaoPagina(fisica), contribuicao2);
    InsereListaContribuicao(RetornaContribuicaoPagina(fisica), contribuicao3);
    
    ListaPagina* listaPagina = InicializaListaPagina();
    InsereListaPagina(listaPagina, fisica);
    InsereListaPagina(listaPagina, artes);
    InsereListaPagina(listaPagina, ufes);

    InsereListaLink(RetornaLinkPagina(fisica), ufes);
    

    ImprimeListaPagina(listaPagina);

    printf("\n");
    

    DestroiListaPagina(listaPagina);
    DestroiPagina(fisica);
    DestroiPagina(artes);
    DestroiPagina(ufes);
    DestroiContribuicao(contribuicao1);
    DestroiContribuicao(contribuicao2);
    DestroiContribuicao(contribuicao3);




    

    return 0;
}