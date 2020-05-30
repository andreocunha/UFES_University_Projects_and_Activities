#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "servidor.h"

struct playlist{
    int tipo;                //1publica,2privada;
    char *nomePlaylist;    
    char *colaboradores[2];
    int qtdColaboradores;
    int qtdMidias;
    Midia *midia[50];
};

Playlist* AlocaPlaylist(){
    Playlist *p=(Playlist*)malloc(sizeof(Playlist));
    p->nomePlaylist=(char*)malloc(50);
    
    for(int i=0;i<2;i++){
        p->colaboradores[i]=(char*)malloc(50);
    }
    for(int i=0;i<50;i++){
        p->midia[i]=AlocaMidia();
    }
    return p;
}

void CriaPlaylist(Playlist *p, char* nomep, char* colab1, char* colab2, int qtdColab, int qtdMidia){
    strcpy(p->nomePlaylist,nomep);
    p->qtdColaboradores=qtdColab;
    p->qtdMidias=0;
    if(qtdColab==1){
        strcpy(p->colaboradores[0],colab1);
    }
    else if(qtdColab==2){
        strcpy(p->colaboradores[0],colab1);
        strcpy(p->colaboradores[1],colab2);
    }
}

int RetornaQtdMidias(Playlist *p){
    return p->qtdMidias;
}

void AdicionaMidiaPlaylist(Playlist *p, Midia *m){    
    p->midia[p->qtdMidias]=m;
    p->qtdMidias++;
}

void ImprimePlaylist(Playlist *p){
    printf("\n");
    ImprimeNomePlaylist(p);
    ImprimeColaboradoresPlaylist(p);
    ImprimeMidiasPlaylist(p);
}


void ApagaMidiaPlaylist(Playlist *p,int posicao){
    p->midia[50] = p->midia[posicao];
    for(int i=posicao;i<p->qtdMidias;i++){
        TrocaMidia(p,i,i+1);
    }
    p->qtdMidias--;
    printf("\nMidia apagada com sucesso!");
}

void TrocaMidia(Playlist *p, int posicao1, int posicao2){
    Midia *auxiliar;
    auxiliar=AlocaMidia();
    auxiliar=p->midia[posicao1];
    p->midia[posicao1]=p->midia[posicao2];
    p->midia[posicao2]=auxiliar;
}

void ImprimeNomePlaylist(Playlist *p){
        printf("Nome da Playlist: %s\n",p->nomePlaylist);
    }    
void ImprimeColaboradoresPlaylist(Playlist *p){
    for(int i=0;i<p->qtdColaboradores;i++){
        printf("%d- ",i);
        printf("Colaborador: %s\n",p->colaboradores[i]);
        }
    }  
void ImprimeMidiasPlaylist(Playlist *p){
    printf("\n");
    for(int i=0;i<p->qtdMidias;i++){
        printf("[%02d]",i);
        ImprimeMidia(p->midia[i]);
        printf("\n");
        }
    }  
  

void AtribuiNomePlaylist(Playlist *p, char *nomep){
    p->nomePlaylist=nomep;
}

void trocaMidias(Playlist *p, int pos1, int pos2){
    Midia *aux;

    aux = AlocaMidia();
    aux = p->midia[pos1];
    p->midia[pos1] = p->midia[pos2];
    p->midia[pos2] = aux;

}