#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "servidor.h"

struct servidor{
    Album *albuns[10];
    Usuario *usuarios[10];
    int qtdUsuario;
    int qtdAlbuns;
};

Servidor* AlocaServidor(){
    Servidor* servidor=(Servidor*)malloc(sizeof(Servidor));
    for(int i=0;i<11;i++){
        servidor->albuns[i]=AlocaAlbum();
    }
    for(int i=0;i<5;i++){
        servidor->usuarios[i]=AlocaUsuario();
    }
    servidor->qtdAlbuns=0;
    servidor->qtdUsuario=0;
}


Servidor *lerDadosArquivo(FILE *arquivo, Servidor *servidor){
    Album *album;
    Midia *midia;
    Usuario *usuario;
    int qtdAlbuns=0, qtdUsuarios=0;

    fscanf(arquivo,"%d%*c", &qtdAlbuns); //quantidade de albuns
    fscanf(arquivo,"%d%*c", &qtdUsuarios); //quantidade de usuarios

    //------------------------------------------------------------------------------------------
    for(int i=0; i<qtdAlbuns; i++){ //para adicionar todas os albuns que estavam no arquivo
        album = AlocaAlbum();
        char *nomeDoAlbum, *nomeDoArtista, *genero, *produtor;
        int ano=0, qtdMidia=0;

        nomeDoAlbum=(char*)malloc(50);
        nomeDoArtista=(char*)malloc(50);
        genero=(char*)malloc(50);
        produtor=(char*)malloc(50);

        fscanf(arquivo, "%[^\n]%*c", nomeDoAlbum);
        fscanf(arquivo, "%[^\n]%*c", nomeDoArtista);
        fscanf(arquivo, "%[^\n]%*c", genero);
        fscanf(arquivo, "%[^\n]%*c", produtor);
        fscanf(arquivo, "%d%*c", &ano);
        fscanf(arquivo, "%d%*c", &qtdMidia);

        CriaAlbum(album, nomeDoAlbum, nomeDoArtista, genero, produtor, ano, qtdMidia);
       
        for(int j=0; j<qtdMidia; j++){ //para adicionar todas as midias que estavam no arquivo
            midia = AlocaMidia();
            char *nomeDaMidia, *nomeArtista, *nomeArtista2, *nomeCompositor, *nomeCompositor2,
            *nomeCompositor3, *genero, *produtora;
            int tipo,qtdArtista, qtdCompositor;
            float duracao;

            nomeDaMidia=(char*)malloc(50);
            nomeArtista=(char*)malloc(50);
            nomeArtista2=(char*)malloc(50);
            nomeCompositor=(char*)malloc(50);
            nomeCompositor2=(char*)malloc(50);
            nomeCompositor3=(char*)malloc(50);
            genero=(char*)malloc(50);
            produtora=(char*)malloc(50);

            fscanf(arquivo, "%[^\n]%*c", nomeDaMidia);
            fscanf(arquivo, "%d%*c", &qtdArtista);
            if(qtdArtista == 1){
            fscanf(arquivo, "%[^\n]%*c", nomeArtista); 
            }
            else if(qtdArtista == 2){
                fscanf(arquivo, "%[^\n]%*c", nomeArtista); 
                fscanf(arquivo, "%[^\n]%*c", nomeArtista2);
            }

            fscanf(arquivo, "%d%*c", &qtdCompositor);
            if(qtdCompositor == 1){
                fscanf(arquivo, "%[^\n]%*c", nomeCompositor);
            }
            else if(qtdCompositor == 2){
                fscanf(arquivo, "%[^\n]%*c", nomeCompositor);
                fscanf(arquivo, "%[^\n]%*c", nomeCompositor2);
            }
            else if(qtdCompositor == 3){
                fscanf(arquivo, "%[^\n]%*c", nomeCompositor);
                fscanf(arquivo, "%[^\n]%*c", nomeCompositor2);
                fscanf(arquivo, "%[^\n]%*c", nomeCompositor3);
            }
            
            fscanf(arquivo, "%[^\n]%*c", genero);
            fscanf(arquivo, "%f%*c", &duracao);
            fscanf(arquivo, "%d%*c", &tipo);


            CriaMidia(midia, nomeDaMidia, nomeArtista, nomeArtista2, nomeCompositor, nomeCompositor2,
            nomeCompositor3, genero, produtor, tipo, duracao, qtdArtista, qtdCompositor);

            AdicionaMidiaAlbum(album, midia);
        }
        AdicionaAlbumServidor(servidor, album);
        }
    //------------------------------------------------------------------------------------------

    //Ler os usuarios    
    for(int k=1; k<qtdUsuarios; k++){
        usuario = AlocaUsuario();
        char *nomeCompleto, *nickname, *senha;
        int qtdPlaylist=0, qtdMidia=0;

        nomeCompleto =(char*)malloc(50);
        nickname = (char*)malloc(50);
        senha = (char*)malloc(50); 

        fscanf(arquivo, "%[^\n]%*c", nomeCompleto);
        fscanf(arquivo, "%[^\n]%*c", nickname);
        fscanf(arquivo, "%[^\n]%*c", senha);

        CriaUsuario(usuario, nomeCompleto, nickname, senha);
        AdicionaUsuarioServidor(servidor, usuario);

    }
    //------------------------------------------------------------------------------------------

    while (!feof(arquivo)) {
        fscanf(arquivo, "%*c"); //consome os \n restantes no config.txt
    }
    return servidor;
}

void salvaDadosArquivo(FILE *arquivo, Servidor *servidor){
    fprintf(arquivo, "%d\n", servidor->qtdAlbuns);
    fprintf(arquivo, "%d\n", servidor->qtdUsuario);

    for(int i=0; i<servidor->qtdAlbuns; i++){
        salvaDadosArquivoAlbum(arquivo, servidor->albuns[i]);
    }

    for(int i=1; i<servidor->qtdUsuario; i++){
        SalvaDadosArquivoUsuario(arquivo, servidor->usuarios[i]);
    }

    fclose(arquivo);
}

int RetornaQtdAlbum(Servidor *servidor){
    return servidor->qtdAlbuns;
}
int RetornaQtdUsuario(Servidor *servidor){
    return servidor->qtdUsuario;
}
void AdicionaAlbumServidor(Servidor *servidor, Album *a){
    servidor->albuns[servidor->qtdAlbuns]=a;
    servidor->qtdAlbuns++;
}
void AdicionaUsuarioServidor(Servidor *servidor, Usuario *u){
    servidor->usuarios[servidor->qtdUsuario]=u;
    servidor->qtdUsuario++;
}

void ImprimeAlbunsServidor(Servidor *servidor){
    for(int i=0;i<servidor->qtdAlbuns;i++){
        printf("\nAlbum [%02d]: ",i);
        ImprimeAlbum(servidor->albuns[i]);
    }
}

void ImprimeAlbunsEMidiasServidor(Servidor *servidor){
    for(int i=0;i<servidor->qtdAlbuns;i++){
        printf("\n##############################################################\n");
        printf("\nID Album [%02d]: ",i);
        ImprimeDadosBasicosAlbum(servidor->albuns[i]);
    }
}

void ImprimeAlbumEscolhidoServidor(Servidor *servidor, int id){
    ImprimeDadosBasicosAlbum(servidor->albuns[id]);
}

void ImprimeUsuarioServidor(Servidor *servidor){
    for(int i=0;i<servidor->qtdUsuario;i++){
        printf("Usuario [%02d]\n",i);
        ImprimeUsuario(servidor->usuarios[i]);
    }
}

Usuario* VerificaUsuarioServidor(Servidor *servidor,char *nickname, char *senha){
    char *nome, *senhaUsuario;
    nome = (char*)malloc(sizeof (char));
    senhaUsuario = (char*)malloc(sizeof (char));

    if(strcmp(nickname, "root") == 0 && strcmp(senha, "mestre") == 0){
        return servidor->usuarios[0];
    } 

    for(int i=0; i< servidor->qtdUsuario; i++){
       nome = RetornaNickname(servidor->usuarios[i]);
       senhaUsuario = RetornaSenha(servidor->usuarios[i]);
       if(strcmp(nickname, nome) == 0 && strcmp(senha, senhaUsuario) == 0){
           return servidor->usuarios[i];
       } 
    }
}



Album* RetornaAlbumEscolhido(Servidor *servidor, int identificador){
    return servidor->albuns[identificador];
}

Midia* RetornaMidia(Servidor *servidor, int idAlbum, int idMidia){
    return RetornaMidiaAlbum(servidor->albuns[idAlbum], idMidia);
}


void PequisarNomeAlbum(Servidor *servidor, char* nomeAlb){
    for(int i=0;i<servidor->qtdAlbuns;i++){
        PesquisaAlbum(servidor->albuns[i], nomeAlb);
    }
}
void PesquisarNomeMidia(Servidor *servidor, char* nomeMid){
    for(int j=0;j<servidor->qtdAlbuns;j++){
        PesquisaMidiaAlbum(servidor->albuns[j],nomeMid);
    }
}
void PesquisarNomeArtista(Servidor *servidor, char* nomeArt){
    for(int j=0;j<servidor->qtdAlbuns;j++){
        PesquisaArtistaMidiaAlbum(servidor->albuns[j],nomeArt);
    }
}

void PesquisarNomeCompositor(Servidor *servidor, char* nomeC){
    for(int j=0;j<servidor->qtdAlbuns;j++){
        PesquisarNomeCompositorAlbum(servidor->albuns[j],nomeC);
    }

}
void PesquisarGenero(Servidor *servidor, char* nomeG){
    for(int j=0;j<servidor->qtdAlbuns;j++){
        PesquisarGeneroAlbum(servidor->albuns[j],nomeG);
    }
}
void PesquisarProdutora(Servidor *servidor, char* nomeP){
    for(int j=0;j<servidor->qtdAlbuns;j++){
        PesquisarProdutoraAlbum(servidor->albuns[j],nomeP);
    }
}

int verificaLogin(Servidor *servidor, char *nickname){
    char *nome;
    nome = (char*)malloc(sizeof (char));

    if(strcmp(nickname, "root") == 0){
        return 1;
    } 

    for(int i=0; i< servidor->qtdUsuario; i++){
        nome = RetornaNickname(servidor->usuarios[i]);
       if(strcmp(nickname, nome) == 0){
           return 2;
       } 
    }
    return 0;
}

void ImprimeTodosUsuariosServidor(Servidor *servidor){
    printf("\nUsuarios cadastrados:\n\n");
    for(int i=0; i< servidor->qtdUsuario; i++){
        printf("\n|----------------------------------------|\n\n");
        printf("ID: %d\n\n", i);
        imprimeTodosUsuarios(servidor->usuarios[i]);
    }
}

void ApagaMidiaDoServidor(Servidor *servidor, int idAlbum, int idMidia){
    apagaMidiaDoAlbum(servidor->albuns[idAlbum], idMidia);
    
}