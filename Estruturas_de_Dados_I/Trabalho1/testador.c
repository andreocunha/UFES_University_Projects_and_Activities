#define _GNU_SOURCE // Para funcionar o strdup sem dar warning
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEditor.h"
#include "ListaPagina.h"
#include "ListaContribuicao.h"
#include "ListaLink.h"


void INSEREPAGINA(FILE *arq, ListaPagina* lista);
void RETIRAPAGINA(FILE* arq, FILE* log, ListaPagina* lista);
void INSEREEDITOR(FILE *arq, ListaEditor* lista);
void INSERECONTRIBUICAO(FILE *arq, FILE* log, ListaPagina* listaPagina, ListaEditor* listaEditor);
void RETIRACONTRIBUICAO(FILE *arq, FILE* log, ListaPagina* listaPagina, ListaEditor* listaEditor);
void INSERELINK(FILE *arq, FILE* log, ListaPagina* lista);
void RETIRALINK(FILE *arq, FILE* log, ListaPagina* lista);
void CAMINHO(FILE* arq, FILE* log, ListaPagina* lista);
void IMPRIMEPAGINA(FILE* arq, FILE* log, ListaPagina* lista);
void IMPRIMEWIKED(ListaPagina* listaPagina, ListaEditor* listaEditor);
int verificaExistenciaPagina(FILE* log, ListaPagina* lista, char* nomePag);

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
        INSERECONTRIBUICAO(arq, log, listaPagina, listaEditor);
    }
    else if(strcmp(palavra, "RETIRACONTRIBUICAO")== 0)
    {
        RETIRACONTRIBUICAO(arq, log, listaPagina, listaEditor);
    }
    else if(strcmp(palavra, "INSERELINK")== 0)
    {
        INSERELINK(arq, log, listaPagina);
    }
    else if(strcmp(palavra, "RETIRALINK")== 0)
    {
        RETIRALINK(arq, log, listaPagina);
    }
    else if(strcmp(palavra, "CAMINHO")== 0)
    {
        CAMINHO(arq, log, listaPagina);
    }
    else if(strcmp(palavra, "IMPRIMEPAGINA")== 0)
    {
        IMPRIMEPAGINA(arq, log, listaPagina);
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

int verificaExistenciaPagina(FILE* log, ListaPagina* lista, char* nomePag)
{
    if(RetornaPagina(lista, nomePag) == NULL)
    {
        fprintf(log,"ERRO: não existe a pagina %s\n", nomePag);
        printf("ERRO: não existe a pagina %s\n", nomePag);
        return 0;
    }
    return 1;
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

    if(verificaExistenciaPagina(log, lista, nomePag) == 0)
    {
        return;
    }
    
    RemoveLinkListaLinkListaPagina(lista, nomePag);
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

void INSERECONTRIBUICAO(FILE *arq, FILE* log, ListaPagina* listaPagina, ListaEditor* listaEditor)
{
    Contribuicao* contrib;
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
        fprintf(log,"ERRO: abertura do arquivo");
        printf("ERRO: abertura do arquivo");
        exit(1);
    }

    int i = 0;
    while( !feof(arq2) && i<10000) {
		// fgets(texto, 10000, arq2);
        c = fgetc(arq2);
        texto[i] = c;
        i++;
	}
    texto[i-1] = '\0';
    fclose(arq2);

    if(verificaExistenciaPagina(log, listaPagina, nomePag) == 0)
    {
        return;
    }
    
    ed = RetornaEditor(listaEditor, nomeEditor);

    if ( ed == NULL)
    {
        fprintf(log,"ERRO: não existe o editor%s\n", nomeEditor);
        printf("ERRO: não existe o editor%s\n", nomeEditor);
        return;
    }
    

    contrib = InicializaContribuicao(texto, nomeArq);

    InsereListaContribuicao(RetornaListaContribuicaoPagina(listaPagina, nomePag), contrib, ed);
    InsereListaContribuicao(RetornaListaContribuicaoEditor(listaEditor, nomeEditor), contrib, ed);
}

void RETIRACONTRIBUICAO(FILE *arq, FILE* log, ListaPagina* listaPagina, ListaEditor* listaEditor)
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

    if(verificaExistenciaPagina(log, listaPagina, nomePag) == 0)
    {
        return;
    }


    ed = RetornaEditor(listaEditor, nomeEditor);
    listaContrib = RetornaListaContribuicaoPagina(listaPagina, nomePag);
    contrib = RetornaContribuicaoLista(listaContrib, nomeArq);

    if(RetornaEditorListaContribuicao(listaContrib, contrib) != ed)
    {
        fprintf(log,"ERRO: o usuario %s nao tem permissao de remover a contribuicao %s\n", nomeEditor, nomeArq);
        printf("ERRO: o usuario %s nao tem permissao de remover a contribuicao %s\n", nomeEditor, nomeArq);
        return;
    }
    AlteraStatusContribuicao(contrib);
    RemoveCelulaListaContribuicao(RetornaListaContribuicaoEditor(listaEditor, nomeEditor), nomeArq);

}

void INSERELINK(FILE *arq, FILE* log, ListaPagina* lista)
{
    ListaLink* listaLink;
    Pagina* pag;

    char origem[50];
    char destino[50];

    fscanf(arq,"%s",origem);
    fscanf(arq,"%s",destino);

    if(verificaExistenciaPagina(log, lista, origem) == 0)
    {
        return;
    }
    if(verificaExistenciaPagina(log, lista, destino) == 0)
    {
        return;
    }

    listaLink = RetornaListaLinkPagina(lista, origem);
    pag = RetornaPagina(lista, destino);

    InsereListaLink(listaLink, pag);
}

void RETIRALINK(FILE *arq, FILE* log, ListaPagina* lista)
{
    ListaLink* listaLink;

    char origem[50];
    char destino[50];

    fscanf(arq,"%s",origem);
    fscanf(arq,"%s",destino);

    if(verificaExistenciaPagina(log, lista, origem) == 0)
    {
        return;
    }
    if(verificaExistenciaPagina(log, lista, destino) == 0)
    {
        return;
    }

    listaLink = RetornaListaLinkPagina(lista, origem);

    RemoveListaLink(listaLink, destino);
}

void CAMINHO(FILE* arq, FILE* log, ListaPagina* lista)
{
    ListaLink* visited;
    Pagina* pagOrigem;

    char origem[50];
    char destino[50];

    fscanf(arq,"%s",origem);
    fscanf(arq,"%s",destino);

    pagOrigem = RetornaPagina(lista, origem);

    visited = InicializaListaLink();

    if(verificaExistenciaPagina(log, lista, origem) == 0)
    {
        DestroiListaLink(visited);
        return;
    }
    if(verificaExistenciaPagina(log, lista, destino) == 0)
    {
        DestroiListaLink(visited);
        return;
    }

    listaTodosCaminhosPossiveis(pagOrigem, visited, lista);
    // ImprimeListaLink(visited, log);

    if(RetornaPaginaListaLink(visited, destino) == NULL)
    {
        fprintf(log, "NAO HA CAMINHO DA PAGINA %s PARA %s\n", origem, destino);
    }
    else
    {
        fprintf(log, "HA CAMINHO DA PAGINA %s PARA %s\n", origem, destino);
    }
    
    DestroiListaLink(visited);

}

void IMPRIMEPAGINA(FILE* arq, FILE* log, ListaPagina* lista)
{
    Pagina* pag;
    char nomePag[50];

    fscanf(arq,"%s",nomePag);

    if(verificaExistenciaPagina(log, lista, nomePag) == 0)
    {
        return;
    }

    pag = RetornaPagina(lista, nomePag);
    ImprimeUnicaPaginaLista(lista, pag);
}

void IMPRIMEWIKED(ListaPagina* listaPagina, ListaEditor* listaEditor)
{
    ImprimeListaPagina(listaPagina);
    // ImprimeListaEditor(listaEditor);
}
