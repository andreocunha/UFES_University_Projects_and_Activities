#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "servidor.h"


struct album{
    char *nomeAlbum;
    char *nomeArtista;       
    char *genero;
    char *produzidoPor;        
    Midia *midia[20];
    int qtdMidias;
    int qtdMidiasTotal;
    int ano;
};

void CriaAlbum(Album *album,char* nomeAlb, char* nArtista,char* gen, char* produtor,int ano,int qtd){
    strcpy(album->nomeAlbum,nomeAlb);
    strcpy(album->nomeArtista,nArtista);
    strcpy(album->genero,gen);
    strcpy(album->produzidoPor,produtor);
    album->ano=ano;
    album->qtdMidiasTotal=qtd;
    album->qtdMidias=0;
}

Album* AlocaAlbum(){
    Album* album=(Album*)malloc(sizeof(Album));
    album->nomeAlbum=(char*)malloc(50);
    album->nomeArtista= (char*)malloc(50);
    album->genero= (char*)malloc(50);        
    album->produzidoPor =(char*)malloc(50);

    for(int i=0;i<21;i++){
        album->midia[i]=AlocaMidia();
    }
    return album;
}
void ImprimeAlbum(Album *album){

    printf("Nome do Album: %s\n", album->nomeAlbum);
    printf("Nome do Artista: %s\n", album->nomeArtista);
    printf("Ano do Album: %d\n", album->ano);
    printf("Genero: %s\n", album->genero);
    printf("Produtor: %s\n", album->produzidoPor);

}

void AdicionaMidiaAlbum(Album* album,Midia* m){
    album->midia[album->qtdMidias]=m;
    album->qtdMidias++;
}


void AtribuiNomeAlbum(Album *album, char* nome){album->nomeAlbum=nome;}
void AtribuiArtistaAlbum(Album *album, char* nomeArtista){album->nomeArtista=nomeArtista;}
void AtribuiGenero(Album *album, char* genero){album->genero=genero;}


void AtribuiProdutoraAlbum(Album *album, char* produtora){album->produzidoPor=produtora;}
void AtribuiAnoAlbum(Album *album, int ano){album->ano=ano;}
void AtribuiqtdMidias(Album *album, int qtd){album->qtdMidias=qtd;}

void ImprimeNomeAlbum(Album *album){printf("\n\t\tNome do Album: %s",album->nomeAlbum);}    
void ImprimeArtistaAlbum(Album *album){printf("\n\t\tNome do Artista: %s",album->nomeArtista);}  
void ImprimeGeneroAlbum(Album *album){printf("\n\t\tGenero: %s",album->genero);}  
void ImprimeProdutoraAlbum(Album *album){printf("\n\t\tProduzido por: %s\n",album->produzidoPor);}  
void ImprimeqtdMidias(Album *album){printf("\n\t\tQuantidade de Midias: %d",album->qtdMidias);}  
void ImprimeAnoAlbum(Album *album){printf("\n\t\tAno: %d",album->ano);}  

Midia* RetornaMidiaAlbum(Album *album, int posicao){
    return album->midia[posicao];
}

void ImprimeDadosBasicosAlbum(Album *album){
    printf("\nNome do Album: %s\n", album->nomeAlbum);
    printf("Nome do Artista: %s\n", album->nomeArtista);
    printf("Ano do Album: %d\n", album->ano);
    printf("Genero: %s\n", album->genero);
    printf("Produtor: %s\n\n", album->produzidoPor);

    printf("\nMidias do Album:\n\n");

    for(int i=0; i<album->qtdMidias; i++){
        printf("--------------------------------------------------\n");
        printf("ID midia: %02d\n", i);
        ImprimeMidia(album->midia[i]);
        printf("--------------------------------------------------\n");
        printf("\n");
    }
    
    printf("\n");
}

void PesquisaAlbum(Album *album, char *nome){
    if(!(strcmp(album->nomeAlbum,nome))){
        printf("\n");
        ImprimeAlbum(album);
    }
}

void PesquisaMidiaAlbum(Album *album, char* nomeM){
    for(int i=0;i<album->qtdMidiasTotal;i++){
        PesquisaMidia(album->midia[i],nomeM);
    }
}

void PesquisaArtistaMidiaAlbum(Album *album, char* nomeDoArtista){
    for(int i=0;i<album->qtdMidiasTotal;i++){
       PesquisaArtistaMidia(album->midia[i],nomeDoArtista);
    }
}

void PesquisarNomeCompositorAlbum(Album *album, char* nomeC){
    for(int i=0;i<album->qtdMidiasTotal;i++){
       PesquisarNomeCompositorMidia(album->midia[i],nomeC);
    }
}
void PesquisarGeneroAlbum(Album *album, char* nomeG){
    for(int i=0;i<album->qtdMidiasTotal;i++){
       PesquisarGeneroMidia(album->midia[i], nomeG);
    }
}
void PesquisarProdutoraAlbum(Album *album, char* nomeP){
    for(int i=0;i<album->qtdMidiasTotal;i++){
        PesquisarProdutoraMidia(album->midia[i], nomeP);
       
    }
}

void salvaDadosArquivoAlbum(FILE *arquivo, Album *album){
    fprintf(arquivo, "%s\n", album->nomeAlbum);
    fprintf(arquivo, "%s\n", album->nomeArtista);
    fprintf(arquivo, "%s\n", album->genero);
    fprintf(arquivo, "%s\n", album->produzidoPor);
    fprintf(arquivo, "%d\n", album->ano);
    fprintf(arquivo, "%d\n", album->qtdMidias);
    
    for(int i=0; i<album->qtdMidias; i++){
        salvaDadosArquivoMidia(arquivo, album->midia[i]);
    }
}

void apagaMidiaDoAlbum(Album *album, int id){
    DeletaMidiaPrograma(album->midia[id]);
    album->qtdMidias--;
}