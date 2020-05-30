#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "midia.h"
#include "usuario.h"
#include "album.h"
#include "playlist.h"
#include "servidor.h"

char* LerString(char* texto);
void cadastroUsuario(Usuario *usuario);
void adicionaPlaylistDoUsuario(Usuario *usuario, Album *album);
void opcoesDeAdministrador(Servidor *servidor);
void criaNovoAlbum(Servidor *servidor);
void ModificaAlbum(Album *album,int escolha);
void AlteraMidia(Midia *midia,int escolha);
Midia* criaNovaMidia();
void UsuarioNormal(Servidor *servidor, Usuario *usuario);


int main(){
    int opcaoMenuLogin = 0, opcaoMenuUsuario=0, opcaoMenuPlaylist=0, opcaoMenuDesenvolvedor,
    opcaoMenuPesquisar=0, opcaoMenuAlteraAlbum=0, opcaoMenuAlteraMidia=0, opcaoMenuAlteraPlaylist=0;
    FILE *arquivo;
    Servidor *servidor;
    servidor = AlocaServidor();

    arquivo= fopen("arquivo.txt", "r");
    if ( !arquivo ){
        printf("Error ao abrir o arquivo.txt\n");
        return 1;
    }
    
    while (!feof(arquivo)) { 
        servidor= lerDadosArquivo(arquivo, servidor);
    }

    fclose(arquivo);

    Usuario *usuario;
    usuario = AlocaUsuario();
    criaUsuarioMestre(usuario);
    AdicionaUsuarioServidor(servidor, usuario);
    

    

    MenuPrincipal(); //imprime o menu incial do programa

    while(opcaoMenuLogin != 3){
        MenuLogin();
        scanf("%d", &opcaoMenuLogin);
        
        switch(opcaoMenuLogin){
            case 1: //cria um novo usuario
                if(opcaoMenuLogin == 1){
                    int opcaoMenuUsuario=0, id=0;
                    Usuario *usuario;
                    usuario = AlocaUsuario();
                    cadastroUsuario(usuario);
                    AdicionaUsuarioServidor(servidor, usuario);

                    printf("\nBem vindo!\n");

                    while (opcaoMenuUsuario != 4){
                        MenuUsuario();
                        scanf("%d", &opcaoMenuUsuario);

                        switch (opcaoMenuUsuario){

                        case 1: //cria a playlist do usuario
                            ImprimeAlbunsServidor(servidor);
                            printf("\n\nDidite o Id do Album que deseja visualizar as Midias: ");
                            scanf("%d", &id);
                            ImprimeAlbumEscolhidoServidor(servidor, id);
                            Album *album=AlocaAlbum();
                            album=RetornaAlbumEscolhido(servidor, id);
                            adicionaPlaylistDoUsuario(usuario, album);
                            //ImprimeUsuarioServidor(servidor);

                            while (opcaoMenuPlaylist != 5){
                                int id=0;
                                MenuPlaylist();
                                scanf("%d", &opcaoMenuPlaylist);

                                switch (opcaoMenuPlaylist){
                                case 1: //mostra as playlist do usuario
                                    printf("Imprimindo playlists...\n\n");
                                    ImprimeUsuario(usuario);
                                    break;

                                case 2: //apaga uma playlist do usuario
                                    printf("Digite o ID da playlist que sera apagada: ");
                                    scanf("%d", &id);
                                    ApagaPlaylistUsuario(usuario, id);
                                    break;

                                case 3: //edita a playlist
                                    if(opcaoMenuPlaylist == 3){
                                        Playlist* playlist=AlocaPlaylist();
                                        ImprimeUsuario(usuario);
                                        printf("Digite o id da Playlist que deseja editar: ");
                                        scanf("%d", &id);
                                        playlist=RetornaPlaylistUsuario(usuario, id);

                                        MenuAlteraPlaylist();
                                        scanf("%d", &opcaoMenuAlteraPlaylist);

                                        switch (opcaoMenuAlteraPlaylist){

                                        case 1: //Altera o nome da playlist
                                            if(opcaoMenuAlteraPlaylist == 1){
                                                char *nome=(char*)malloc(50);
                                                printf("Digite o nome da Playlist: ");
                                                nome = LerString(nome);
                                                AtribuiNomePlaylist(playlist, nome);
                                            }
                                            break;

                                        case 2: //Apaga uma midia da playlist
                                            if(opcaoMenuAlteraPlaylist == 2){
                                                ImprimePlaylist(playlist);
                                                printf("Digite o ID da midia que deseja apagar: ");
                                                scanf("%d", &id);
                                                ApagaMidiaPlaylist(playlist, id);
                                                ImprimePlaylist(playlist);
                                            }
                                            break;

                                        case 3: //volta
                                            break;
                                        
                                        default:
                                            printf("Digite uma opcao valida!\n");
                                            break;
                                        }
                                    }
                                    
                                    
                                    break;

                                case 4: 
                                    if(opcaoMenuPlaylist == 4){
                                        Playlist* playlist=AlocaPlaylist();
                                        ImprimeUsuario(usuario);
                                        printf("Digite o id da Playlist que deseja ver as midias: ");
                                        scanf("%d", &id);
                                        playlist=RetornaPlaylistUsuario(usuario, id);
                                        ImprimeMidiasPlaylist(playlist);
                                        int pos1 =0, pos2=0;
                                        printf("ID da midia 1: ");
                                        scanf("%d", &pos1);
                                        printf("ID da midia 2: ");
                                        scanf("%d", &pos2);
                                        trocaMidias(playlist, pos1, pos2);
                                    }
                                    break;

                                case 5: //volta
                                    break;
                                
                                default:
                                printf("Digite uma opcao valida!\n");
                                    break;
                                }
                            }
                            break;

                        case 2: //pesquisar
                            while(1){
                                int op=0;
                                char *nome;
                                MenuPesquisar();
                                scanf("%d", &op);
                                if(op==1){//Nome Album
                                    printf("Digite o nome do Album que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PequisarNomeAlbum(servidor,nome);
                                    continue;
                                }
                                else if(op==2){//Nome Midia
                                    printf("Digite o nome da Midia que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarNomeMidia(servidor,nome);
                                    continue;
                                }
                                else if(op==3){//Nome Artista
                                    printf("Digite o nome do Artista que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarNomeArtista(servidor,nome);
                                    continue;
                                }
                                else if(op==4){
                                    printf("Digite o nome do Compositor que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarNomeCompositor(servidor,nome);
                                }
                                else if(op==5){
                                    printf("Digite o nome da Produtora que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarProdutora(servidor,nome);
                                    
                                }
                                else if(op==6){
                                    printf("Digite o Genero que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarGenero(servidor,nome);
                                }
                                else if(op==7){break;}
                                else continue;

                            }
                            break;

                        case 3://acessa uma playlist
                            printf("Mostrando todas as suas playlists\n\n");
                            ImprimeUsuario(usuario);
                            break;

                        case 4://volta
                            break;
                        
                        default:
                            printf("Digite uma opcao valida.\n");
                            break;
                        }
                    }

                }
                break;

            case 2: //Login
                if(opcaoMenuLogin == 2){
                    int i=0;
                    char *nome, *senha;
                    nome = (char*)malloc(sizeof(char));
                    senha = (char*)malloc(sizeof(char));

                    printf("\nDigite o nickname: ");
                    nome = LerString(nome);

                    printf("\nDigite a senha: ");
                    senha = LerString(senha);

                    i = verificaLogin(servidor, nome);

                    if(i == 0){
                        printf("\nUsuario nao cadastrado!\n");
                    }
                    else if(i == 1){
                        if(strcmp (senha,"mestre") == 0){
                            opcoesDeAdministrador(servidor);
                        }
                        else{
                            while (!(strcmp (senha,"mestre") == 0)){
                                setbuf(stdin, NULL); //limpa tudo que estava armazenado na entrada
                                printf("Senha incorreta!\n");
                                printf("Digite a senha novamente: ");
                                senha = LerString(senha);
                            }
                            opcoesDeAdministrador(servidor);
                        }
                    }
                    else if (i == 2){
                        usuario = VerificaUsuarioServidor(servidor, nome, senha);
                        printf("\nBem vindo!\n");
                        UsuarioNormal(servidor, usuario);
                    }
                }

                break;

            case 3://Encerra o programa
                break;

            default:
                printf("Digite uma opcao valida.\n");
                break;
        }
    }


    arquivo= fopen("arquivo.txt", "w");
    if ( !arquivo ){
        printf("Error ao tentar criar o arquivo.txt\n");
        return 1;
    } 

    salvaDadosArquivo(arquivo, servidor);


    return 0;
}

//-----------------------------------------------------------------------------------------------------------

char* LerString(char* texto){
    setbuf(stdin, NULL); //limpa tudo que estava armazenado na entrada

    char leitura[200]; //vetor auxiliar para ler uma string
    int tam = 0; //para saber o tamanho do texto

    scanf("%[^\n]s", leitura); //le o texto digitado ate o \n, lendo os espacos como caracter tambem
    setbuf(stdin, NULL); //limpa tudo que estava armazenado na entrada

    tam = strlen(leitura); //verifica o tamanho do texto lido
    texto = (char *)malloc(tam+1); //aloca dinamicamente o texto com o tamanho da palavra lida
    strncpy(texto,leitura, tam); //copia a palavra de leitura (vetor auxiliar) para o "texto"

    //como eh uma funcao, o espaco alocado para o vetor "leitura" sera liberado apos o return
    return texto;

}

//-----------------------------------------------------------------------------------------------------------

void cadastroUsuario(Usuario *usuario){
    char *nomeCompleto, *nickname, *senha;
    nomeCompleto = (char*)malloc(50);
    nickname = (char*)malloc(30);
    senha = (char*)malloc(30);

    printf("Nome completo: ");
    nomeCompleto = LerString(nomeCompleto);

    printf("nickname: ");
    nickname = LerString(nickname);

    printf("Senha: ");
    senha = LerString(senha);

    CriaUsuario(usuario, nomeCompleto, nickname, senha);


}

//-----------------------------------------------------------------------------------------------------------

void adicionaPlaylistDoUsuario(Usuario *usuario, Album *album){
    char *nomeDaPlaylist = (char*)malloc(30);
    char *colaborador1 = (char*)malloc(30);
    char *colaborador2 = (char*)malloc(30);
    int qtdMidia=0, qtdColaboradores=0, tipo=0;
    Playlist *playlist;
    playlist = AlocaPlaylist();

    printf("Nome da playlist: ");
    nomeDaPlaylist = LerString(nomeDaPlaylist);

    printf("Quantidade de Colaboradores: ");
    scanf("%d", &qtdColaboradores);

    if(qtdColaboradores == 1){
        printf("Nome do colaborador: ");
        colaborador1 = LerString(colaborador1);
    }
    else if(qtdColaboradores == 2){
        printf("Nome do colaborador 1: ");
        colaborador1 = LerString(colaborador1);

        printf("Nome do colaborador 2: ");
        colaborador2 = LerString(colaborador2);
    }
    
    printf("Quantidade de midias que serao adicionadas na playlist: ");
    scanf("%d", &qtdMidia);
    
    printf("Tipo de Playlist (1-Publica ou 2-Privada): ");
    scanf("%d", &tipo);

    CriaPlaylist(playlist, nomeDaPlaylist, colaborador1, colaborador2, qtdColaboradores,qtdMidia);

    for(int j=0; j<qtdMidia; j++){
        int n=0;
        Midia *midia;
        midia=AlocaMidia();
        //ImprimeAlbum(album);
        printf("Digite o ID da musica que sera adicionada: ");
        scanf("%d", &n);
        midia=RetornaMidiaAlbum(album,n);
        AdicionaMidiaPlaylist(playlist, midia);
    }
    AdicionaPlaylistUsuario(usuario, playlist);
}


//-----------------------------------------------------------------------------------------------------------

void opcoesDeAdministrador(Servidor *servidor){
    int opcao=0;
    
    while(opcao !=8){
        MenuDesenvolvedor();
        scanf("%d", &opcao);
        switch(opcao){
            case 1: //cria novo album
                criaNovoAlbum(servidor);
                break;
            
            case 2: //Edita midia
                if(opcao == 2){
                    int mid=0,alb=0, opM=0;
                    Album *alterar=AlocaAlbum();
                    Midia *midiaAltera=AlocaMidia();
                    ImprimeAlbunsServidor(servidor);
                    printf("\n\t\tSelecione o Album: ");
                    scanf("%d", &alb);
                    alterar=RetornaAlbumEscolhido(servidor,alb);
                    ImprimeAlbum(alterar);
                    printf("Escolha a Midia que deseja editar: ");
                    scanf("%d", &mid);
                    midiaAltera=RetornaMidia(servidor,alb,mid);
                    while(1){
                        opM=0;
                        MenuAlteraMidia();
                        scanf("%d", &opM);
                        if(opM<1 || opM>8){continue;}
                        else if(opM==8){opM=0;break;}
                        else{AlteraMidia(midiaAltera,opM);opM=0; break;}
                    }
                }

                break;
                
            case 3: //Edita album
                if(opcao == 3){
                    int alb=0;
                    int opA=0;
                    Album *alterar=AlocaAlbum();
                    ImprimeAlbunsServidor(servidor);
                    printf("Escolha o Album que deseja editar: ");
                    scanf("%d", &alb);
                    alterar=RetornaAlbumEscolhido(servidor,alb);
                    while(1){
                        opA=0;
                        MenuAlteraAlbum();
                        scanf("%d", &opA);
                        if(opA<1 ||opA>6){continue;}
                        else if(opA==6){opA=0;break;}
                        else{ModificaAlbum(alterar,opA); opA=0; break;}}
                    }
                
                break;
              
            case 4: //adiciona uma midia em um album
                if(opcao == 4){
                    int alb =0;
                    Album *album=AlocaAlbum();
                    Midia *midia = AlocaMidia();
                    ImprimeAlbunsServidor(servidor);
                    printf("\nSelecione o Album: ");
                    scanf("%d", &alb);
                    album=RetornaAlbumEscolhido(servidor,alb);
                    ImprimeAlbum(album);
                    midia = criaNovaMidia();
                    printf("\nMidia adicionada com sucesso!\n");
                    AdicionaMidiaAlbum(album, midia);
                    ImprimeDadosBasicosAlbum(album);

                }
                
                break;
                
            case 5: //Mostra todos os usuarios
                ImprimeTodosUsuariosServidor(servidor);
                break;

            case 6: //Mostra todos os albuns
                ImprimeAlbunsEMidiasServidor(servidor);
                break;

            case 7: //Apaga midia
                if(opcao == 7){
                    int i=0, j=0;
                    printf("Digite o ID do album: ");
                    scanf("%d", &i);

                    printf("Digite o ID da midia: ");
                    scanf("%d", &j);

                    ApagaMidiaDoServidor(servidor, i, j);
                }
                
                break;

            case 8: //Volta
                break;

            default:
                printf("Digite uma opcao valida\n");
                break;
        }
    }
}

//-----------------------------------------------------------------------------------------------------------


void criaNovoAlbum(Servidor *servidor){
    Album *album;
    Midia *midia;
    album = AlocaAlbum();
    
    setbuf(stdin, NULL); //limpa tudo que estava armazenado na entrada
    
    char *nomeDoAlbum, *nomeDoArtista, *genero, *produtor;
    int ano=0, qtdMidia=0;

    nomeDoAlbum=(char*)malloc(50);
    nomeDoArtista=(char*)malloc(50);
    genero=(char*)malloc(50);
    produtor=(char*)malloc(50);
    
    printf("Nome do album: ");
    nomeDoAlbum = LerString(nomeDoAlbum);
    
    printf("Nome do artista: ");
    nomeDoArtista = LerString(nomeDoArtista);
    
    printf("Genero: ");
    genero = LerString(genero);
    
    printf("Produtor(a): ");
    produtor = LerString(produtor);

    printf("Ano do album: ");
    scanf("%d", &ano);
    
    printf("Quantidade de midias no album: ");
    scanf("%d", &qtdMidia);
    
    CriaAlbum(album, nomeDoAlbum, nomeDoArtista, genero, produtor, ano, qtdMidia);
    
    for(int i=0; i<qtdMidia; i++){
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
        
        printf("Nome da midia: ");
        nomeDaMidia = LerString(nomeDaMidia);
        
        printf("Quantidade de Artistas: ");
        scanf("%d", &qtdArtista);
        
        if(qtdArtista == 1){
            printf("Nome do artista: ");
            nomeArtista = LerString(nomeArtista);
        }
        if(qtdArtista == 2){
            printf("Nome do artista 1: ");
            nomeArtista = LerString(nomeArtista);
            printf("Nome do artista 2: ");
            nomeArtista2 = LerString(nomeArtista2);
        }
        
        printf("Quantidade de Compositores: ");
        scanf("%d", &qtdCompositor);
        
        if(qtdCompositor == 1){
            printf("Nome do compositor: ");
            nomeCompositor = LerString(nomeCompositor);
        }
        
        if(qtdCompositor == 2){
            printf("Nome do compositor 1: ");
            nomeCompositor = LerString(nomeCompositor);
            printf("Nome do compositor 2: ");
            nomeCompositor2 = LerString(nomeCompositor2);
        }
        
        if(qtdCompositor == 3){
            printf("Nome do compositor 1: ");
            nomeCompositor = LerString(nomeCompositor);
            printf("Nome do compositor 2: ");
            nomeCompositor2 = LerString(nomeCompositor2);
            printf("Nome do compositor 3: ");
            nomeCompositor3 = LerString(nomeCompositor3);
        }
        
        printf("Genero: ");
        genero = LerString(genero);
        
        printf("Produtor(a): ");
        produtora = LerString(produtora);
        
        printf("Duracao da midia: ");
        scanf("%f", &duracao);
        
        printf("Tipo da midia:\n");
        printf("(1)Musica, (2)Video, (3)Podcast: ");
        scanf("%d", &tipo);
        
        
        CriaMidia(midia, nomeDaMidia, nomeArtista, nomeArtista2, nomeCompositor, nomeCompositor2,
                nomeCompositor3, genero, produtora, tipo, duracao, qtdArtista, qtdCompositor);
        
        AdicionaMidiaAlbum(album, midia);
    }
    
    AdicionaAlbumServidor(servidor, album);

    ImprimeAlbum(album);

    printf("\n\n");

    ImprimeAlbunsServidor(servidor);
    
}

//-----------------------------------------------------------------------------------------------------------

void ModificaAlbum(Album *album,int escolha){
    char *nome=(char*)malloc(50);
    int num;    
    if(escolha==1){
        printf("\n\t\tNome do Album: ");
        nome = LerString(nome);
        AtribuiNomeAlbum(album,nome);
    }
    else if(escolha==2){
        printf("\n\t\tNome do artista: ");
        nome = LerString(nome);
        AtribuiArtistaAlbum(album,nome);
    }
    else if(escolha==3){
        printf("\n\t\tGenero: ");
        nome = LerString(nome);
        AtribuiGenero(album,nome);
    }
    else if(escolha==4){
       printf("\n\t\tNome produtora: ");
       nome = LerString(nome);
       AtribuiProdutoraAlbum(album,nome); 
    }
    else if(escolha==5){
        printf("\n\t\tAno do Album: ");
        scanf("%d", &num);
        AtribuiAnoAlbum(album,num);
    }
}

//-----------------------------------------------------------------------------------------------------------


void AlteraMidia(Midia *midia,int escolha){
    char *nome=(char*)malloc(50);
    int num,op,qtdA,qtdC;
    float fnum;
    if(escolha==1){
        printf("\n\t\tNome da midia: ");
        nome = LerString(nome);
        EditaNomeMidia(midia,nome);
    }
    else if(escolha==2){   
            qtdA=RetornaQtdArtista(midia);
            if(qtdA==1){     
                printf("\n\t\tNome do artista: ");
                nome = LerString(nome);
                EditaArtista1(midia,nome);
            }
            else if(qtdA==2){
                printf("\n\t\tQual dos Artistas deseja alterar (0 ou 1): ");
                scanf("%d", &op);
                if(op==1){
                    printf("\n\t\tNome do artista: ");
                    nome = LerString(nome);
                    EditaArtista1(midia,nome);
                }
                else if(op==2){
                    printf("\n\t\tNome do artista: ");
                    nome = LerString(nome);
                    EditaArtista2(midia,nome);
                }
            }
        }
    else if(escolha==3){
        qtdC=RetornaQtdCompositor(midia);
        if(qtdC==1){
            printf("\n\t\tNome Compositor: ");
            nome = LerString(nome);
            EditaCompositor1(midia,nome);
        }
        else if(qtdC==2){
            printf("\n\t\tQual dos Compositores deseja alterar (0 ou 1): ");
            scanf("%d", &op);        
            if(op==1){
                printf("\n\t\tNome Compositor: ");
                nome = LerString(nome);
                EditaCompositor1(midia,nome);
            }
            else if(op==2){
                printf("\n\t\tNome Compositor: ");
                nome = LerString(nome);
                EditaCompositor2(midia,nome);
            }
        
        }
    }
        
    else if(escolha==4){
        printf("\n\t\tGenero: ");
        nome = LerString(nome);
        EditaNomeGenero(midia,nome);
    }
    else if(escolha==5){
        printf("\n\t\tTipo, [01]Musica [02]Video [03]Podcast:  ");
        scanf("%d", &num);
        EditaTipo(midia,num);
    }
    else if(escolha==6){
        printf("\n\t\tDuracao: ");
        scanf("%f", &fnum);
        EditaDuracao(midia,fnum);
    }
    else if(escolha==7){
       printf("\n\t\tNome produtora: ");
       nome = LerString(nome);
       EditaNomeProdutora(midia,nome);
    }
}

Midia* criaNovaMidia(){
    Midia *midia;
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

        setbuf(stdin, NULL); //limpa tudo que estava armazenado na entrada
        
        printf("Nome da midia: ");
        nomeDaMidia = LerString(nomeDaMidia);
        
        printf("Quantidade de Artistas: ");
        scanf("%d", &qtdArtista);
        
        if(qtdArtista == 1){
            printf("Nome do artista: ");
            nomeArtista = LerString(nomeArtista);
        }
        if(qtdArtista == 2){
            printf("Nome do artista 1: ");
            nomeArtista = LerString(nomeArtista);
            printf("Nome do artista 2: ");
            nomeArtista2 = LerString(nomeArtista2);
        }
        
        printf("Quantidade de Compositores: ");
        scanf("%d", &qtdCompositor);
        
        if(qtdCompositor == 1){
            printf("Nome do compositor: ");
            nomeCompositor = LerString(nomeCompositor);
        }
        
        if(qtdCompositor == 2){
            printf("Nome do compositor 1: ");
            nomeCompositor = LerString(nomeCompositor);
            printf("Nome do compositor 2: ");
            nomeCompositor2 = LerString(nomeCompositor2);
        }
        
        if(qtdCompositor == 3){
            printf("Nome do compositor 1: ");
            nomeCompositor = LerString(nomeCompositor);
            printf("Nome do compositor 2: ");
            nomeCompositor2 = LerString(nomeCompositor2);
            printf("Nome do compositor 3: ");
            nomeCompositor3 = LerString(nomeCompositor3);
        }
        
        printf("Genero: ");
        genero = LerString(genero);
        
        printf("Produtor(a): ");
        produtora = LerString(produtora);
        
        printf("Duracao da midia: ");
        scanf("%f", &duracao);
        
        printf("Tipo da midia:\n");
        printf("(1)Musica, (2)Video, (3)Podcast: ");
        scanf("%d", &tipo);
        
        
        CriaMidia(midia, nomeDaMidia, nomeArtista, nomeArtista2, nomeCompositor, nomeCompositor2,
                nomeCompositor3, genero, produtora, tipo, duracao, qtdArtista, qtdCompositor);
        
        return midia;
}

void UsuarioNormal(Servidor *servidor, Usuario *usuario){
    int opcao = 0, id=0;
    while (opcao != 4){
                        MenuUsuario();
                        scanf("%d", &opcao);

                        switch (opcao){

                        case 1: //cria a playlist do usuario
                            ImprimeAlbunsServidor(servidor);
                            printf("\n\nDidite o Id do Album que deseja visualizar as Midias: ");
                            scanf("%d", &id);
                            ImprimeAlbumEscolhidoServidor(servidor, id);
                            Album *album=AlocaAlbum();
                            album=RetornaAlbumEscolhido(servidor, id);
                            adicionaPlaylistDoUsuario(usuario, album);
                            ImprimeUsuarioServidor(servidor);

                            while (opcao != 5){
                                int id=0;
                                MenuPlaylist();
                                scanf("%d", &opcao);

                                switch (opcao){
                                case 1: //mostra as playlist do usuario
                                    printf("Imprimindo playlists...\n\n");
                                    ImprimeUsuario(usuario);
                                    break;

                                case 2: //apaga uma playlist do usuario
                                    printf("Digite o ID da playlist que sera apagada: ");
                                    scanf("%d", &id);
                                    ApagaPlaylistUsuario(usuario, id);
                                    break;

                                case 3: //edita a playlist
                                    if(opcao == 3){
                                        Playlist* playlist=AlocaPlaylist();
                                        ImprimeUsuario(usuario);
                                        printf("Digite o id da Playlist que deseja editar: ");
                                        scanf("%d", &id);
                                        playlist=RetornaPlaylistUsuario(usuario, id);

                                        MenuAlteraPlaylist();
                                        scanf("%d", &opcao);

                                        switch (opcao){

                                        case 1: //Altera o nome da playlist
                                            if(opcao == 1){
                                                char *nome=(char*)malloc(50);
                                                printf("Digite o nome da Playlist: ");
                                                nome = LerString(nome);
                                                AtribuiNomePlaylist(playlist, nome);
                                            }
                                            break;

                                        case 2: //Apaga uma midia da playlist
                                            if(opcao == 2){
                                                ImprimePlaylist(playlist);
                                                printf("Digite o ID da midia que deseja apagar: ");
                                                scanf("%d", &id);
                                                ApagaMidiaPlaylist(playlist, id);
                                                ImprimePlaylist(playlist);
                                            }
                                            break;

                                        case 3: //volta
                                            break;
                                        
                                        default:
                                            printf("Digite uma opcao valida!\n");
                                            break;
                                        }
                                    }
                                    
                                    
                                    break;

                                case 4: 
                                    if(opcao == 4){
                                        Playlist* playlist=AlocaPlaylist();
                                        ImprimeUsuario(usuario);
                                        printf("Digite o id da Playlist que deseja ver as midias: ");
                                        scanf("%d", &id);
                                        playlist=RetornaPlaylistUsuario(usuario, id);
                                        ImprimeMidiasPlaylist(playlist);
                                        int pos1 =0, pos2=0;
                                        printf("ID da midia 1: ");
                                        scanf("%d", &pos1);
                                        printf("ID da midia 2: ");
                                        scanf("%d", &pos2);
                                        trocaMidias(playlist, pos1, pos2);
                                    }
                                    break;

                                case 5: //volta
                                    break;
                                
                                default:
                                printf("Digite uma opcao valida!\n");
                                    break;
                                }
                            }
                            break;

                        case 2: //pesquisar
                            while(1){
                                int op=0;
                                char *nome;
                                MenuPesquisar();
                                scanf("%d", &op);
                                if(op==1){//Nome Album
                                    printf("Digite o nome do Album que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PequisarNomeAlbum(servidor,nome);
                                    continue;
                                }
                                else if(op==2){//Nome Midia
                                    printf("Digite o nome da Midia que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarNomeMidia(servidor,nome);
                                    continue;
                                }
                                else if(op==3){//Nome Artista
                                    printf("Digite o nome do Artista que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarNomeArtista(servidor,nome);
                                    continue;
                                }
                                else if(op==4){
                                    printf("Digite o nome do Compositor que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarNomeCompositor(servidor,nome);
                                }
                                else if(op==5){
                                    printf("Digite o nome da Produtora que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarProdutora(servidor,nome);
                                    
                                }
                                else if(op==6){
                                    printf("Digite o Genero que sera pesquisado: ");
                                    nome = LerString(nome);
                                    PesquisarGenero(servidor,nome);
                                }
                                else if(op==7){break;}
                                else continue;

                            }
                            break;

                        case 3://acessa uma playlist
                            printf("Mostrando todas as suas playlists\n\n");
                            ImprimeUsuario(usuario);
                            break;

                        case 4://volta
                            break;
                        
                        default:
                            printf("Digite uma opcao valida.\n");
                            break;
                        }
}
}