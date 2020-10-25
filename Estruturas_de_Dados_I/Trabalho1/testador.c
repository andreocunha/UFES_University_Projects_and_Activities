#include <stdio.h>
#include "ListaEditor.h"
#include "ListaPagina.h"

int
main(int argc, char *argv[])
{

    // Teste para os editores
    Editor* andre = InicializaEditor("Andre");
    Editor* artur = InicializaEditor("Artur");
    Editor* patricia = InicializaEditor("Patricia");
    
    ListaEditor* listaEditor = InicializaListaEditor();
    InsereListaEditor(listaEditor, andre);
    InsereListaEditor(listaEditor, artur);
    InsereListaEditor(listaEditor, patricia);

    ImprimeListaEditor(listaEditor);

    printf("\n");

    RemoveListaEditor(listaEditor, "Andre");

    ImprimeListaEditor(listaEditor);
    printf("\n");

    DestroiListaEditor(listaEditor);
    DestroiEditor(andre);
    DestroiEditor(artur);
    DestroiEditor(patricia);


    // Teste para as paginas
    Pagina* fisica = InicializaPagina("fisica");
    Pagina* artes = InicializaPagina("artes");
    Pagina* ufes = InicializaPagina("ufes");
    
    ListaPagina* listaPagina = InicializaListaPagina();
    InsereListaPagina(listaPagina, fisica);
    InsereListaPagina(listaPagina, artes);
    InsereListaPagina(listaPagina, ufes);

    ImprimeListaPagina(listaPagina);

    printf("\n");

    RemoveListaPagina(listaPagina, "fisica");

    ImprimeListaPagina(listaPagina);

    DestroiListaPagina(listaPagina);
    DestroiPagina(fisica);
    DestroiPagina(artes);
    DestroiPagina(ufes);


    return 0;
}