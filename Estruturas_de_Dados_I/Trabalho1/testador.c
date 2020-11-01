#define _GNU_SOURCE // Para funcionar o strdup sem dar warning
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEditor.h"
#include "ListaPagina.h"
#include "ListaContribuicao.h"
#include "ListaLink.h"
#include "ListaHistorico.h"


void INSEREPAGINA(FILE *arq, ListaPagina* lista);
void RETIRAPAGINA(FILE* arq, FILE* log, ListaPagina* lista);
void INSEREEDITOR(FILE *arq, ListaEditor* lista);
void INSERECONTRIBUICAO(FILE *arq, ListaPagina* lista, ListaEditor* listaEditor);
void RETIRACONTRIBUICAO(FILE *arq, ListaPagina* listaPagina, ListaEditor* listaEditor);
void INSERELINK(FILE *arq, ListaPagina* lista);
void RETIRALINK(FILE *arq, ListaPagina* lista);
void CAMINHO(FILE* arq, FILE* log, ListaPagina* lista);
void IMPRIMEPAGINA(FILE *arq, ListaPagina* lista);
void IMPRIMEWIKED(ListaPagina* listaPagina, ListaEditor* listaEditor);


int
main(int argc, char *argv[])
{
    ListaPagina* listaPagina = InicializaListaPagina();
    ListaEditor* listaEditor = InicializaListaEditor();

    FILE *arq;
    FILE *log;
    char palavra[50];
    char c = '@';
    palavra[0] = '\0';

    arq = fopen(argv[1], "r");
    log = fopen("log.txt", "w");
    

    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    while (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
    {
        fscanf(arq, "%c", &c);
    }
    

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
        RETIRAPAGINA(arq, log, listaPagina);
    }
    else if(strcmp(palavra, "INSEREEDITOR")== 0)
    {
        INSEREEDITOR(arq, listaEditor);
    }
    else if(strcmp(palavra, "INSERECONTRIBUICAO")== 0)
    {
        INSERECONTRIBUICAO(arq, listaPagina, listaEditor);
    }
    else if(strcmp(palavra, "RETIRACONTRIBUICAO")== 0)
    {
        RETIRACONTRIBUICAO(arq, listaPagina, listaEditor);
    }
    else if(strcmp(palavra, "INSERELINK")== 0)
    {
        INSERELINK(arq, listaPagina);
    }
    else if(strcmp(palavra, "RETIRALINK")== 0)
    {
        
    }
    else if(strcmp(palavra, "CAMINHO")== 0)
    {
        CAMINHO(arq, log, listaPagina);
    }
    else if(strcmp(palavra, "IMPRIMEPAGINA")== 0)
    {
        IMPRIMEPAGINA(arq, listaPagina);
    }
    else if(strcmp(palavra, "IMPRIMEWIKED")== 0)
    {
        IMPRIMEWIKED(listaPagina, listaEditor);
    }
    else if(strcmp(palavra, "FIM")== 0)
    {
        DestroiListaPagina(listaPagina);
        DestroiListaEditor(listaEditor);
        break;
    }

    palavra[0] = '\0';
    fscanf(arq,"%s",palavra);

    } while (c != EOF);
    
    fclose(arq);
    fclose(log);

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

}

void RETIRAPAGINA(FILE* arq, FILE* log, ListaPagina* lista)
{
    char nomePag[50];
    fscanf(arq,"%s",nomePag);

    RemoveListaPagina(lista, nomePag, log);
}

void INSEREEDITOR(FILE *arq, ListaEditor* lista)
{
    Editor* editor;
    char nomeEditor[50];
    fscanf(arq,"%s",nomeEditor);

    editor = InicializaEditor(nomeEditor);
    InsereListaEditor(lista, editor);
}

void INSERECONTRIBUICAO(FILE *arq, ListaPagina* listaPagina, ListaEditor* listaEditor)
{
    Contribuicao* contrib;
    Historico* hist;
    Editor* ed;

    char nomePag[50];
    char nomeEditor[50];
    char nomeArq[50];
    char texto[10000];
    char caminho[50] = "./Entradas/";
    char c;

    fscanf(arq,"%s",nomePag);
    fscanf(arq,"%s",nomeEditor);
    fscanf(arq,"%s",nomeArq);

    FILE *arq2;
    texto[0] = '\0';
    for (int j = 0; j < 10000; j++)
    {
        texto[j] = '\0';
    }
    

    strcat(caminho, nomeArq);
    arq2 = fopen(caminho, "r");

    if (arq2 == NULL) // Pode-se fazer o teste dessa forma
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    int i = 0;
    while( !feof(arq2)) {
		// fgets(texto, 10000, arq2);
        c = fgetc(arq2);
        texto[i] = c;
        i++;
	}
    texto[i-1] = '\0';
    fclose(arq2);

    ed = RetornaEditor(listaEditor, nomeEditor);

    contrib = InicializaContribuicao(texto, nomeArq);
    hist = InicializaHistorico(nomeEditor, nomeArq);

    InsereListaContribuicao(RetornaListaContribuicaoPagina(listaPagina, nomePag), contrib, ed);
    InsereListaHistorico(RetornaListaHistoricoPagina(listaPagina, nomePag), hist);
    // InsereContribuicaoListaEditor(listaEditor, contrib, nomeEditor);

}

void RETIRACONTRIBUICAO(FILE *arq, ListaPagina* listaPagina, ListaEditor* listaEditor)
{
    Contribuicao* contrib;
    ListaContribuicao* listaContrib;
    Editor* ed;
    
    char nomePag[50];
    char nomeEditor[50];
    char nomeArq[50];

    fscanf(arq,"%s",nomePag);
    fscanf(arq,"%s",nomeEditor);
    fscanf(arq,"%s",nomeArq);

    ed = RetornaEditor(listaEditor, nomeEditor);
    listaContrib = RetornaListaContribuicaoPagina(listaPagina, nomePag);
    contrib = RetornaContribuicaoLista(listaContrib, nomeArq);

    if(RetornaEditorListaContribuicao(listaContrib, contrib) != ed)
    {
        printf("Esse usuario nao tem permissao de remover essa contribuicao\n");
        return;
    }
    RemoveListaContribuicao(listaContrib, nomeArq);
}

void INSERELINK(FILE *arq, ListaPagina* lista)
{
    ListaLink* listaLink;
    Pagina* pag;

    char origem[50];
    char destino[50];

    fscanf(arq,"%s",origem);
    fscanf(arq,"%s",destino);

    listaLink = RetornaListaLinkPagina(lista, origem);

    pag = RetornaPagina(lista, destino);
    InsereListaLink(listaLink, pag);
}

void RETIRALINK(FILE *arq, ListaPagina* lista)
{
    ListaLink* listaLink;

    char origem[50];
    char destino[50];

    fscanf(arq,"%s",origem);
    fscanf(arq,"%s",destino);

    listaLink = RetornaListaLinkPagina(lista, origem);

    RemoveListaLink(listaLink, destino);
}

void CAMINHO(FILE* arq, FILE* log, ListaPagina* lista)
{
    ListaLink* listaLink;
    Pagina* pagDestino;


    char origem[50];
    char destino[50];

    fscanf(arq,"%s",origem);
    fscanf(arq,"%s",destino);

    listaLink = RetornaListaLinkPagina(lista, origem);
    pagDestino = RetornaPaginaListaLink(listaLink, destino);

    if(pagDestino == NULL)
    {
        fprintf(log, "NAO HA CAMINHO DA PAGINA %s PARA %s\n", origem, destino);
    }
    else
    {
        fprintf(log, "HA CAMINHO DA PAGINA %s PARA %s\n", origem, destino);
    }
    

}

void IMPRIMEPAGINA(FILE *arq, ListaPagina* lista)
{
    Pagina* pag;
    char nomePag[50];

    fscanf(arq,"%s",nomePag);
    pag = RetornaPagina(lista, nomePag);
    ImprimeUnicaPaginaLista(lista, pag);
}

void IMPRIMEWIKED(ListaPagina* listaPagina, ListaEditor* listaEditor)
{
    ImprimeListaPagina(listaPagina);
    ImprimeListaEditor(listaEditor);
}
