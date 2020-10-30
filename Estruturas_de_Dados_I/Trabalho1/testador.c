#define _GNU_SOURCE // Para funcionar o strdup sem dar warning
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEditor.h"
#include "ListaPagina.h"
#include "ListaContribuicao.h"
#include "ListaLink.h"


void INSEREPAGINA(FILE *arq, ListaPagina* lista);
void RETIRAPAGINA(FILE *arq, ListaPagina* lista);
void INSEREEDITOR(FILE *arq, ListaEditor* lista);
void INSERECONTRIBUICAO(FILE *arq, ListaPagina* lista);
void RETIRACONTRIBUICAO(FILE *arq, ListaPagina* lista);
void INSERELINK(FILE *arq, ListaPagina* lista);
void RETIRALINK(FILE *arq, ListaPagina* lista);
void CAMINHO(FILE *arq, ListaPagina* lista);
void IMPRIMEPAGINA(FILE *arq, ListaPagina* lista);
void IMPRIMEWIKED(FILE *arq, ListaPagina* lista);


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
    // Pagina* fisica = InicializaPagina("fisica", "fisica.txt");
    // Pagina* artes = InicializaPagina("artes", "artes.txt");
    // Pagina* ufes = InicializaPagina("ufes", "artes.txt");

    // Contribuicao* contribuicao1 = InicializaContribuicao("contribuicao1111", "c4.txt", andre);
    // Contribuicao* contribuicao2 = InicializaContribuicao("contribuicao2");
    // Contribuicao* contribuicao3 = InicializaContribuicao("contribuicao3");
    
    // InsereListaContribuicao(RetornaListaContribuicaoPagina(fisica, "fisica"), contribuicao1);
    // InsereListaContribuicao(RetornaContribuicaoPagina(fisica), contribuicao2);
    // InsereListaContribuicao(RetornaContribuicaoPagina(fisica), contribuicao3);
    
    // ListaPagina* listaPagina = InicializaListaPagina();
    // InsereListaPagina(listaPagina, fisica);
    // InsereListaPagina(listaPagina, artes);
    // InsereListaPagina(listaPagina, ufes);

    // InsereListaContribuicao(RetornaListaContribuicaoPagina(listaPagina, "fisica"), contribuicao1);

    // InsereListaLink(RetornaLinkPagina(fisica), ufes);
    

    // ImprimeListaPagina(listaPagina);
    // RemoveListaPagina(listaPagina, "artes");

    // printf("\n");
    

    // DestroiListaPagina(listaPagina);
    // DestroiPagina(fisica);
    // DestroiPagina(artes);
    // DestroiPagina(ufes);
    // DestroiContribuicao(contribuicao1);
    // DestroiContribuicao(contribuicao2);
    // DestroiContribuicao(contribuicao3);

    ListaPagina* listaPagina = InicializaListaPagina();
    ListaEditor* listaEditor = InicializaListaEditor();

    FILE *arq;
    char palavra[50];
    char c = '@';
    palavra[0] = '\0';

    arq = fopen("./Entradas/entrada.txt", "r");

    if (arq == NULL) // Pode-se fazer o teste dessa forma
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    while (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
    {
        fscanf(arq, "%c", &c);
    }
    
    // fscanf(arq,"%s",palavra);

    palavra[0] = c;
    for(int i = 1; c!= ' '; i++)
    {
        fscanf(arq, "%c", &c);
        if(c != ' ')
        {
           palavra[i] = c; 
        }
        else
        {
            palavra[i] = '\0';
        }
        
    }


    do
    {
        if(strcmp(palavra, "INSEREPAGINA")== 0)
    {
        INSEREPAGINA(arq, listaPagina);
    }
    else if(strcmp(palavra, "RETIRAPAGINA")== 0)
    {
        RETIRAPAGINA(arq, listaPagina);
    }
    else if(strcmp(palavra, "INSEREEDITOR")== 0)
    {
        INSEREEDITOR(arq, listaEditor);
    }
    else if(strcmp(palavra, "INSERECONTRIBUICAO")== 0)
    {
        
    }
    else if(strcmp(palavra, "RETIRACONTRIBUICAO")== 0)
    {
        
    }
    else if(strcmp(palavra, "INSERELINK")== 0)
    {
        
    }
    else if(strcmp(palavra, "RETIRALINK")== 0)
    {
        
    }
    else if(strcmp(palavra, "CAMINHO")== 0)
    {
        
    }
    else if(strcmp(palavra, "IMPRIMEPAGINA")== 0)
    {
        
    }
    else if(strcmp(palavra, "IMPRIMEWIKED")== 0)
    {
        ImprimeListaPagina(listaPagina);
        ImprimeListaEditor(listaEditor);
    }
    else if(strcmp(palavra, "FIM")== 0)
    {
        DestroiListaPagina(listaPagina);
        DestroiListaEditor(listaEditor);
        printf("Chegou aqui\n");
        break;
    }

    palavra[0] = '\0';
    fscanf(arq,"%s",palavra);

    } while (c != EOF);
    
    fclose(arq);

    return 0;
}

void INSEREPAGINA(FILE *arq, ListaPagina* lista)
{
    char nomePag[50];
    char nomeArq[50];
    
    fscanf(arq,"%s",nomePag);
    fscanf(arq,"%s",nomeArq);

    Pagina* nova = InicializaPagina(nomePag, nomeArq);
    InsereListaPagina(lista, nova);

    printf("Passou aqui\n");

}

void RETIRAPAGINA(FILE *arq, ListaPagina* lista)
{
    char nomePag[50];
    fscanf(arq,"%s",nomePag);

    RemoveListaPagina(lista, nomePag);
}

void INSEREEDITOR(FILE *arq, ListaEditor* lista)
{
    Editor* editor;
    char nomeEditor[50];
    fscanf(arq,"%s",nomeEditor);

    editor = InicializaEditor(nomeEditor);
    InsereListaEditor(lista, editor);
}

void INSERECONTRIBUICAO(FILE *arq, ListaPagina* lista)
{
    Contribuicao* contrib;

    // contrib = InicializaContribuicao();
}

void RETIRACONTRIBUICAO(FILE *arq, ListaPagina* lista)
{

}

void INSERELINK(FILE *arq, ListaPagina* lista)
{

}

void RETIRALINK(FILE *arq, ListaPagina* lista)
{

}

void CAMINHO(FILE *arq, ListaPagina* lista)
{

}

void IMPRIMEPAGINA(FILE *arq, ListaPagina* lista)
{

}

void IMPRIMEWIKED(FILE *arq, ListaPagina* lista)
{

}
