#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "servidor.h"

struct usuario{   
    char *nomeCompleto;
    char *nickname;
    char *senha;
    int qtdplay;    
    Playlist *playlist[10];
    Playlist *favoritos[10];
};

Usuario* AlocaUsuario(){
    Usuario* u=(Usuario*)malloc(sizeof(Usuario));
    u->nomeCompleto=(char*)malloc(50);
    u->nickname=(char*)malloc(30);
    u->senha=(char*)malloc(30);

    for(int i=0;i<10;i++){
        u->playlist[i]=AlocaPlaylist();
    }

    for(int i=0;i<10;i++){
        u->favoritos[i]=AlocaPlaylist();
    }    

    return u;
}

void criaUsuarioMestre(Usuario *usuario){
    usuario->nomeCompleto = "root";
    usuario->nickname = "root";
    usuario->senha = "mestre";
}

void AdicionaPlaylistUsuario(Usuario *u, Playlist *p){
    u->playlist[u->qtdplay]=p;
    u->qtdplay++;
}

void CriaUsuario(Usuario* u,char *nomeCompleto, char* nickname,char* senha){ 
    strcpy(u->nomeCompleto, nomeCompleto); 
    strcpy(u->nickname, nickname);
    strcpy(u->senha, senha);
    u->qtdplay=0;        
}

void ApagaPlaylistUsuario(Usuario *u, int posicao){
    for(int i=posicao;i<u->qtdplay;i++){
        TrocaPlaylist(u,i,(i+1));
    }
    u->qtdplay--;
}

void TrocaPlaylist(Usuario *u, int posicao1, int posicao2){
    Playlist *auxiliar=AlocaPlaylist();
    auxiliar=u->playlist[posicao1];
    u->playlist[posicao1]=u->playlist[posicao2];
    u->playlist[posicao2]=auxiliar;
}

void ImprimeUsuario(Usuario *u){
    printf("Nickname: %s\n", u->nickname);
    for(int i=0;i<u->qtdplay;i++){
        printf("\n[%02d] ",i);
        ImprimePlaylist(u->playlist[i]);
    }
}


char* RetornaNickname(Usuario *u){
    return u->nickname;
}

char* RetornaSenha(Usuario *u){
    return u->senha;
}

Playlist* RetornaPlaylistUsuario(Usuario *u, int idplay){
    return u->playlist[idplay];
}

void imprimeTodosUsuarios(Usuario *u){
    int tam=0;
    printf("Nome completo: %s\n", u->nomeCompleto);
    printf("Nickname: %s\n", u->nickname);
    
    tam = strlen(u->senha);
    printf("Senha :");
    for(int i=0; i<tam; i++){
        printf("*");
    }
    printf("\n");
    printf("\n|----------------------------------------|\n");
}

void SalvaDadosArquivoUsuario(FILE *arquivo, Usuario *usuario){
    fprintf(arquivo, "%s\n", usuario->nomeCompleto);
    fprintf(arquivo, "%s\n", usuario->nickname);
    fprintf(arquivo, "%s\n", usuario->senha);
}
