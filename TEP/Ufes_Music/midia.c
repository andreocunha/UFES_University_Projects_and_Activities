#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midia.h"

struct midia{
  
    char *nomeMidia; 
    char *artista[2];
    char *compositor[3];   
    char *genero;
    char *produtor;
    float duracao;
    int qtdArtista;
    int qtdCompositor; 
    int  tipo;//(1)musica, (2)video, (3)podcast;  
};


void ImprimeMidia(Midia *midia){

    //imprime o tipo da midia
    printf("O tipo da midia: ");
    switch (midia->tipo)
    {
    case 1:
        printf("Musica\n");
        break;
    
    case 2:
        printf("Video\n");
        break;

    case 3:
        printf("Podcast\n");
        break;
    }

    printf("Nome da midia: %s\n", midia->nomeMidia);

    switch (midia->qtdCompositor){
    case 1:
        printf("Nome do copositor: %s\n", midia->compositor[0]);
        break;
    
    case 2:
        printf("0- Nome do copositor: %s\n", midia->compositor[0]);
        printf("1- Nome do copositor: %s\n", midia->compositor[1]);
        break;

    case 3:
        printf("0- Nome do copositor: %s\n", midia->compositor[0]);
        printf("1- Nome do copositor: %s\n", midia->compositor[1]);
        printf("2- Nome do copositor: %s\n", midia->compositor[2]);
        break;
    }

    switch (midia->qtdArtista){
    case 1:
        printf("Nome do artista: %s\n", midia->artista[0]);
        break;
    
    case 2:
        printf("0- Nome do artista: %s\n", midia->artista[0]);
        printf("0- Nome do artista: %s\n", midia->artista[1]);
        break;
    }
    printf("Nome do(a) produtor(a): %s\n", midia->produtor);
    printf("Genero: %s\n", midia->genero);
    printf("Duracao: %.2f\n", midia->duracao);

}
  
void CriaMidia(Midia* midia, char* nome, char* artista,char* artista2,
                char* compositor,char* compositor2, char* compositor3, 
                char* genero, char* produtora,  int tipo, float duracao, 
                int qtdArtista, int qtdCompositor){
    
    midia->nomeMidia=nome;
    switch (qtdArtista)
    {
    case 1:
        midia->artista[0]=artista;
        break;
    
    case 2:
        midia->artista[0]=artista;
        midia->artista[1]=artista2;
        break;
    default:
        break;
    }

    switch (qtdCompositor){
    case 1:
        midia->compositor[0]=compositor;
        break;
    case 2:
        midia->compositor[0]=compositor;
        midia->compositor[1]=compositor2;

    case 3:
        midia->compositor[0]=compositor;
        midia->compositor[1]=compositor2;
        midia->compositor[2]=compositor3;
    }   
    
    midia->genero=genero;
    midia->produtor=produtora;
    midia->tipo=tipo;
    midia->duracao=duracao;
    midia->qtdCompositor=qtdCompositor;
    midia->qtdArtista=qtdArtista;
}

void DeletaMidiaPrograma(Midia *midia){
    if(midia){
        if(midia->nomeMidia)free(midia->nomeMidia);
        for(int i=0;i<midia->qtdArtista;i++){
            if(midia->artista[i])free(midia->artista[i]);
        }        
        if(midia->genero)free(midia->genero);
        if(midia->produtor)free(midia->produtor);

        for(int i=0;i<midia->qtdCompositor;i++){
            if(midia->compositor[i])free(midia->compositor[i]);
        }
        free(midia);
        printf("\nMidia apagada com sucesso!\n");
    }    
}

Midia* AlocaMidia(){
    Midia* midia=(Midia*)malloc(sizeof(Midia));
    midia->nomeMidia=(char*)malloc(50);
    midia->artista[0]= (char*)malloc(50);
    midia->artista[1]= (char*)malloc(50);
    midia->genero= (char*)malloc(50);        
    midia->produtor =(char*)malloc(50);   
    midia->compositor[0]= (char*)malloc(50); 
    midia->compositor[1]= (char*)malloc(50); 
    midia->compositor[2]= (char*)malloc(50); 
    return midia;    
}

void EditaNomeMidia(Midia *midia, char* nome){
    midia->nomeMidia=nome;
}

void EditaArtista1(Midia *midia, char* artista){
    midia->artista[0]=artista;
}

void EditaCompositor1(Midia *midia, char* compositor){
    midia->compositor[0]=compositor;
}

void EditaArtista2(Midia *midia, char* artista){
    midia->artista[1]=artista;
}

void EditaCompositor2(Midia *midia, char* compositor){
    midia->compositor[1]=compositor;
}

void EditaCompositor3(Midia *midia, char* compositor){
    midia->compositor[2]=compositor;
}

void EditaNomeGenero(Midia *midia, char* genero){
    midia->genero=genero;
}

void EditaTipo(Midia *midia, int tipo){
    midia->tipo=tipo;
}

void EditaDuracao(Midia *midia, float duracao){
    midia->duracao=duracao;
}

void EditaNomeProdutora(Midia *midia, char* produtora){
    midia->produtor=produtora;
}

void PesquisaMidia(Midia *midia, char* nome){
    if(!(strcmp(midia->nomeMidia,nome))){
        printf("\n");
        ImprimeMidia(midia);
    }
}

int RetornaQtdArtista(Midia *midia){
    return midia->qtdArtista;
}
int RetornaQtdCompositor(Midia *midia){
     return midia->qtdCompositor;
}

void PesquisarNomeCompositorMidia(Midia *midia, char* nomeC){
    if(!(strcmp(midia->compositor[0],nomeC))){
        printf("\n");
        ImprimeMidia(midia);
    }
    else if(!(strcmp(midia->compositor[1],nomeC))){
        printf("\n");
        ImprimeMidia(midia);
    }
}
void PesquisarGeneroMidia(Midia *midia, char* nomeG){
    if(!(strcmp(midia->genero,nomeG))){
        printf("\n");
        ImprimeMidia(midia);
    }
}
void PesquisarProdutoraMidia(Midia *midia, char* nomeP){
    if(!(strcmp(midia->produtor,nomeP))){
        printf("\n");
        ImprimeMidia(midia);
    }
}

void PesquisaArtistaMidia(Midia *midia, char* nomeA){
    if(!(strcmp(midia->artista[0],nomeA))){
        printf("\n");
        ImprimeMidia(midia);
    }
    else if(!(strcmp(midia->artista[1],nomeA))){
        printf("\n");
        ImprimeMidia(midia);
    }
}

void salvaDadosArquivoMidia(FILE *arquivo, Midia *midia){
    
    fprintf(arquivo, "%s\n", midia->nomeMidia);
    fprintf(arquivo, "%d\n", midia->qtdArtista);
    for(int i=0; i<midia->qtdArtista; i++){
        fprintf(arquivo, "%s\n", midia->artista[i]);
    }
    fprintf(arquivo, "%d\n", midia->qtdCompositor);
    for(int i=0; i<midia->qtdCompositor; i++){
        fprintf(arquivo, "%s\n", midia->compositor[i]);
    }
    fprintf(arquivo, "%s\n", midia->genero);
    fprintf(arquivo, "%.2f\n", midia->duracao);
    fprintf(arquivo, "%d\n", midia->tipo);
}