#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void MenuPrincipal(){
    system("clear");
    printf("\n\n            |                                  |\n");
    printf("            |          ♬  UFES Music  ♬        |\n");
    printf("            |                                  |\n\n");

}

void MenuLogin(){

    printf("\nDigite:\n");
    printf("1- Criar novo usuario\n");
    printf("2- Logar\n");
    printf("3- Sair\n");

}

void MenuUsuario(){

    printf("\nDigite:\n");
    printf("1- Criar playlist\n");
    printf("2- Pesquisar\n");
    printf("3- Acessar playlist\n");
    printf("4- Voltar\n");
}

void MenuPlaylist (){

    printf("\nDigite:\n");
    printf("1- Mostrar todas as playlists\n");
    printf("2- Apagar playlist\n");
    printf("3- Editar playlist\n");
    printf("4- Altera ordem midias\n");
    printf("5- Voltar\n");        
}

void MenuDesenvolvedor(){

    printf("\nModo Administrador\n");
    printf("\nDigite:\n");
    printf("1- Criar Album\n");
    printf("2- Editar Midia\n");
    printf("3- Editar Album\n");
    printf("4- Adicionar midia em um album\n");    
    printf("5- Mostrar todos usuarios cadastrados\n"); 
    printf("6- Mostrar todos os albuns e midias\n");
    printf("7- Apagar midia\n");
    printf("8- Sair do Menu\n");
}

void MenuPesquisar(){

    printf("\nPesquisar por: \n");    
    printf("1- Nome do Album\n");
    printf("2- Nome da Midia\n");     
    printf("3- Artista\n");    
    printf("4- Compositor\n");
    printf("5- Produtor(a)\n");
    printf("6- Genero\n"); 
    printf("7- Voltar\n");        
}

void MenuAlteraAlbum(){

    printf("\nDigite o que sera atualizado: \n");    
    printf("1- Nome do Album\n");    
    printf("2- Artista\n");    
    printf("3- Genero\n");
    printf("4- Produtora\n"); 
    printf("5- Ano do Album\n");
    printf("6- Voltar\n");     

}

void MenuAlteraMidia(){

    printf("\nDigite o que sera atualizado: \n");    
    printf("1- Nome da Midia\n");    
    printf("2- Artista\n");    
    printf("3- Compositor\n");
    printf("4- Genero\n"); 
    printf("5- Tipo\n");
    printf("6- Duracao\n");  
    printf("7- Produtora\n");     
    printf("8- Voltar\n");    
}

void MenuAlteraPlaylist(){

    printf("\nDigite o que sera editado: \n");     
    printf("1- Nome da Playlist\n");
    printf("2- Apagar Midia\n");      
    printf("3- Voltar\n");
}