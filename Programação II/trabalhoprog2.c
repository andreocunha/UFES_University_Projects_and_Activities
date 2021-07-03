#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int turnos;
    int tamanhoDaMatriz;
    char matrizDasPalavras[100][101];
}tTabuleiro;

typedef struct{
    char nomeJogador1[17];
    char nomeJogador2[17];
    
}tJogador;

typedef struct{
    int quantidadeDePalavrasPorJogador;
    int quantidadeDePalavrasDoJogador1;
    int quantidadeDePalavrasDoJogador2;
    char palavrasDoJogador1[25][17];
    char palavrasDoJogador2[25][17];
    
}tPalavras;

typedef struct{
    int pontuacaoJogador1;
    int pontuacaoJogador2;
    int pontuacaoRecebidaJogador1;
    int pontuacaoRecebidaJogador2;
}tPontos;

typedef struct{
    int linha;
    int coluna;
}tCoordenada;

typedef struct{
    int j1;//serve apenas como contador das palavras do jogador 1
    int j2;//serve apenas como contador das palavras do jogador 2
    int pontosPorPalavra[50];
    int numDoTurno[50];
    char palavrasEstatistica[50][17];
}tEstatistica;


tTabuleiro LeTabuleiro(FILE *config);

tPalavras LePalavras(FILE *config);

tJogador LeJogador();

tPontos InicializaPontuacao();

tTabuleiro InicializaTabuleiro(tTabuleiro tabuleiro);

int VerificaCoordenadaValida(tCoordenada coordenada, tTabuleiro tabuleiroVazio);

tEstatistica OrdenaEstatistica(tEstatistica *dadosEstatistica, 
        tPalavras palavras, int qtdDePalavrasPorJogador);

int AtualizaPontuacao(tPontos *pontos, int palavraDoJogadorX, int jogaJogador);

void IniciaJogo(FILE *estatisticas, tTabuleiro tabuleiro, tPalavras palavras, 
        tJogador jogador, tPontos pontos);

void ImprimeTabela(tJogador jogador, tPalavras palavras, tPontos pontos);

void ImprimeTabuleiro(tTabuleiro tabuleiro);

void GeraArquivoInicializacao(tPalavras palavras, tJogador jogador, 
        FILE *incializacao);

void InicializaEstatistica(tEstatistica *estatistica, tPalavras palavras);

void GeraArquivoEstatisticas(FILE *estatisticas, tJogador jogador, 
    tPontos pontos, tEstatistica dadosEstatistica, int qtdDePalavrasPorJogador);

void AtualizaListaDePalavras(tPalavras *palavras, int i, int palavraDoJogadorX);

void AtualizaEstatistica(int numDaPalavra, tPalavras *palavra, 
   tEstatistica *dadosEstatistica, int ponto, int palavraDoJogadorX, int turno);

void VerificaPalavra(tTabuleiro tabuleiro, tTabuleiro *tabuleiroVazio, 
        tCoordenada coordenada, tPalavras *palavras, int jogaJogador, 
        tPontos *pontos, tEstatistica *dadosEstatistica, int turno);

void NaoEhInicioDePalavra(tCoordenada coordenada, tTabuleiro tabuleiro, 
        tTabuleiro *tabuleiroVazio);

void PalavraSentidoNorte(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

void PalavraSentidoSul(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

void PalavraSentidoLeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

void PalavraSentidoOeste(tCoordenada coordenada, tTabuleiro tabuleiro,
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

void PalavraSentidoNordeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

void PalavraSentidoNoroeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

void PalavraSentidoSudeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

void PalavraSentidoSudoeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX);

int main(int argc, char** argv) {
    tTabuleiro tabuleiro;
    tPalavras palavras;
    tJogador jogador;
    tPontos pontos;
    FILE * config, *incializacao, *estatisticas;
    char caminhoDaLeituraDoConfig[1000];
    char saidaInicializacao[1000];
    char saidaEstatistica[1000];
    
    //Concatenacao do caminho digitado pelo usuario
    sprintf(caminhoDaLeituraDoConfig, "%s/config.txt", argv[1]); 
    sprintf(saidaInicializacao, "%s/saida/Inicializacao.txt", argv[1]);
    sprintf(saidaEstatistica, "%s/saida/Estatisticas.txt", argv[1]);
    
    config= fopen(caminhoDaLeituraDoConfig, "r");
    if ( !config ){
        printf("Error ao abrir o arquivo config.txt no endereco %s\n", 
                caminhoDaLeituraDoConfig);
        return 1;
    }
    
    incializacao = fopen (saidaInicializacao, "w");
    if ( !incializacao ){
        printf("Error ao criar o arquivo Inicializacao.txt no endereco %s\n",
                saidaInicializacao);
        fclose (incializacao);
        return 1;
    }
    
    estatisticas = fopen (saidaEstatistica,"w");
    if ( !estatisticas ){
        printf("Error ao criar o arquivo Estatistica.txt no endereco %s\n", 
                saidaEstatistica);
        fclose (estatisticas);
        return 1;
    }
    
    //executará esse loop até que se leia todos os caracteres do arquivo config
    while (!feof(config)) { 
        tabuleiro= LeTabuleiro(config);
        palavras= LePalavras(config);
        jogador= LeJogador(); 
        GeraArquivoInicializacao(palavras, jogador, incializacao);
    }
    
    pontos= InicializaPontuacao();
    IniciaJogo(estatisticas, tabuleiro, palavras, jogador, pontos);
    
    fclose (config);
    fclose (incializacao);
    fclose (estatisticas);
    return (EXIT_SUCCESS);
}

tTabuleiro LeTabuleiro(FILE *config){
    tTabuleiro tabuleiro;
    int i=0;

    fscanf(config,"%d",&tabuleiro.turnos); //quantidade de turno
    fscanf(config,"%d",&tabuleiro.tamanhoDaMatriz); //tamanho da matriz
    
    int tam= tabuleiro.tamanhoDaMatriz;
    char atual[tam+1]; //CORRECAO: O tamanho da string "atual" nao estava considerando o \0 final. Foi necessario adicionar "+1" para corrigir o problema
    
    for(i=0; i<tam; i++){
        fscanf(config,"%s",atual); 
        strcpy(tabuleiro.matrizDasPalavras[i],atual); //palavras da matriz
    }
    return tabuleiro;
}

tPalavras LePalavras(FILE *config){
    int i;
    tPalavras palavras;
    
    //quantidade de palavras por jogador
    fscanf(config, "%d", &palavras.quantidadeDePalavrasPorJogador); 
    int tam= palavras.quantidadeDePalavrasPorJogador;
    
    for(i=0; i<tam; i++){//palavras do jogador 1
        fscanf(config,"%s", palavras.palavrasDoJogador1[i]); 
    }
    for(i=0; i<tam; i++){//palavras do jogador 2
        fscanf(config,"%s", palavras.palavrasDoJogador2[i]); 
    }
    
    while (!feof(config)) {
        fscanf(config, "%*c"); //consome os \n restantes no config.txt
    }
    
    return palavras;
}

tJogador LeJogador(){
    tJogador jogador;
    
    printf("Nome do Jogador 1:\n");
    scanf("%s", jogador.nomeJogador1);
    
    printf("Nome do Jogador 2:\n");
    scanf("%s", jogador.nomeJogador2);
    
    return jogador;
}

tPontos InicializaPontuacao(){
    tPontos pontos;
    pontos.pontuacaoJogador1 = 0;
    pontos.pontuacaoJogador2 = 0;
    pontos.pontuacaoRecebidaJogador1=0;
    pontos.pontuacaoRecebidaJogador2=0;
    return pontos;
}

void GeraArquivoInicializacao(tPalavras palavras, tJogador jogador, 
        FILE *incializacao){
    //funcao para preencher o arquivo de saida incializacao.txt
    char maiorPalavra[17];
    char letra;
    int i, j, qtd=0, tamanho;
    
    strcpy(maiorPalavra, palavras.palavrasDoJogador1[0]);
    tamanho= strlen(maiorPalavra);
    
    fprintf(incializacao,"--Jogador 1--\n");
    fprintf(incializacao,"Nome: %s\n", jogador.nomeJogador1);
    fprintf(incializacao,"Palavras:\n");
    
    for(i=0; i<palavras.quantidadeDePalavrasPorJogador; i++){
        fprintf(incializacao,"%s\n", palavras.palavrasDoJogador1[i]);
        
         //compara os tamanhos das palavras do jogador 1
        if(strlen (palavras.palavrasDoJogador1[i])> tamanho){
            strcpy(maiorPalavra, palavras.palavrasDoJogador1[i]);
            tamanho= strlen(palavras.palavrasDoJogador1[i]);
        }
    }
    fprintf(incializacao,"Maior Palavra: \n");
    fprintf(incializacao,"%s\n", maiorPalavra);
    fprintf(incializacao,"Letras Iniciais: \n");
    
    for(j='a'; j<='z'; j++){
        for(i=0; i<palavras.quantidadeDePalavrasPorJogador; i++){
            letra= palavras.palavrasDoJogador1[i][0];
            if(letra==j){
                qtd++;
            }
        }
        if(qtd>0)
            fprintf(incializacao,"%c -> %d\n", j, qtd);
        qtd=0;
    }
    fprintf(incializacao,"\n");
    
    strcpy(maiorPalavra, palavras.palavrasDoJogador2[0]);
    tamanho= strlen(maiorPalavra);
    
    fprintf(incializacao,"--Jogador 2--\n");
    fprintf(incializacao,"Nome: %s\n", jogador.nomeJogador2);
    fprintf(incializacao,"Palavras:\n");
    
    for(i=0; i<palavras.quantidadeDePalavrasPorJogador; i++){
        fprintf(incializacao,"%s\n", palavras.palavrasDoJogador2[i]);
        
        //compara os tamanhos das palavras do jogador 1
        if(strlen (palavras.palavrasDoJogador2[i])> tamanho){ 
            strcpy(maiorPalavra, palavras.palavrasDoJogador2[i]);
            tamanho= strlen(palavras.palavrasDoJogador2[i]);
        }
    }
    fprintf(incializacao,"Maior Palavra: \n");
    fprintf(incializacao,"%s\n", maiorPalavra);
    fprintf(incializacao,"Letras Iniciais: \n");
    
    for(j='a'; j<='z'; j++){
        for(i=0; i<palavras.quantidadeDePalavrasPorJogador; i++){
            letra= palavras.palavrasDoJogador2[i][0];
            if(letra==j){
                qtd++;
            }
        }
        if(qtd>0)
            fprintf(incializacao,"%c -> %d\n", j, qtd);
        qtd=0;
    }
}

void GeraArquivoEstatisticas(FILE *estatisticas, tJogador jogador, 
    //funcao para preencher o arquivo de saida estatisticas.txt
    tPontos pontos, tEstatistica dadosEstatistica, int qtdDePalavrasPorJogador){
    int i;
    
    fprintf(estatisticas, "--------------\n--- PONTOS ---\n--------------\n\n");
    fprintf(estatisticas,"%s\n", jogador.nomeJogador1);
    fprintf(estatisticas,"Feitos: %d\n", 
      pontos.pontuacaoJogador1-pontos.pontuacaoRecebidaJogador1);//total menos recebido
    fprintf(estatisticas,"Recebidos: %d\n", pontos.pontuacaoRecebidaJogador1);
    fprintf(estatisticas,"Total: %d\n", pontos.pontuacaoJogador1);
    fprintf(estatisticas,"\n");
    
    fprintf(estatisticas,"%s\n", jogador.nomeJogador2);
    fprintf(estatisticas,"Feitos: %d\n", 
      pontos.pontuacaoJogador2-pontos.pontuacaoRecebidaJogador2);
    fprintf(estatisticas,"Recebidos: %d\n", pontos.pontuacaoRecebidaJogador2);
    fprintf(estatisticas,"Total: %d\n", pontos.pontuacaoJogador2);
    fprintf(estatisticas,"\n");
    
    fprintf(estatisticas, "---------------------------\n--- "
            "PALAVRAS POR PONTOS ---\n---------------------------\n\n");
    fprintf(estatisticas, "|P|     Palavra    | T |\n");
    fprintf(estatisticas, "|-|----------------|---|\n");
    for(i=0; i<2*qtdDePalavrasPorJogador; i++){
        fprintf(estatisticas, "|%d|%-16s|%03d|\n",
                dadosEstatistica.pontosPorPalavra[i],
                dadosEstatistica.palavrasEstatistica[i],
                dadosEstatistica.numDoTurno[i]);
    }

}

void IniciaJogo(FILE *estatisticas, tTabuleiro tabuleiro, tPalavras palavras,
        tJogador jogador, tPontos pontos){
    int i=0, j, jogaJogador, turno=0, qtdDePalavrasPorJogador;
    int jogadaValida=0;
    tCoordenada coordenada;
    tTabuleiro tabuleiroVazio;
    tEstatistica dadosEstatistica;

    palavras.quantidadeDePalavrasDoJogador1= palavras.quantidadeDePalavrasPorJogador;
    palavras.quantidadeDePalavrasDoJogador2= palavras.quantidadeDePalavrasPorJogador;
    qtdDePalavrasPorJogador= palavras.quantidadeDePalavrasPorJogador;
    tabuleiroVazio= InicializaTabuleiro(tabuleiro);
    
    ImprimeTabela(jogador, palavras, pontos);
    printf("\n");
    ImprimeTabuleiro(tabuleiroVazio);
    printf("\n");
    
    InicializaEstatistica(&dadosEstatistica, palavras);
    i=0;
    
    while(i<tabuleiro.turnos && palavras.quantidadeDePalavrasDoJogador1 !=0 && 
            palavras.quantidadeDePalavrasDoJogador2 !=0){
        printf("%s por favor entre com as coordenadas para a sua jogada:\n", 
                jogador.nomeJogador1);
        
        while(jogadaValida != 1){
            scanf("%d %d", &coordenada.linha, &coordenada.coluna);
            switch(VerificaCoordenadaValida(coordenada, tabuleiroVazio)){
                
                case 1:
                    jogadaValida=1;
                    break;
                case 2:
                    ImprimeTabela(jogador, palavras, pontos);
                    printf("\n");
                    ImprimeTabuleiro(tabuleiroVazio);
                    printf("\n");
                    printf("Coordenadas fora do tabuleiro.%s por favor entre "
                            "com novas coordenadas para a sua jogada:\n",
                            jogador.nomeJogador1);
                    break;
                case 3:
                    ImprimeTabela(jogador, palavras, pontos);
                    printf("\n");
                    ImprimeTabuleiro(tabuleiroVazio);
                    printf("\n");
                    printf("Coordenadas ja jogadas.%s por favor entre com "
                            "novas coordenadas para a sua jogada:\n", 
                            jogador.nomeJogador1);
                    break;
            }
        }
        turno++;
        jogadaValida =0;
        jogaJogador=1;
        VerificaPalavra(tabuleiro, &tabuleiroVazio, coordenada, &palavras, 
                jogaJogador, &pontos, &dadosEstatistica, turno);
        ImprimeTabela(jogador, palavras, pontos);
        printf("\n");
        ImprimeTabuleiro(tabuleiroVazio);
        printf("\n");
        
        if(palavras.quantidadeDePalavrasDoJogador1 ==0 || 
                palavras.quantidadeDePalavrasDoJogador2 ==0)
            break;
        
        printf("%s por favor entre com as coordenadas para a sua jogada:\n", 
                jogador.nomeJogador2);
        while(jogadaValida != 1){
            scanf("%d %d", &coordenada.linha, &coordenada.coluna);
            switch(VerificaCoordenadaValida(coordenada, tabuleiroVazio)){
                
                case 1:
                    jogadaValida=1;
                    break;
                case 2:
                    ImprimeTabela(jogador, palavras, pontos);
                    printf("\n");
                    ImprimeTabuleiro(tabuleiroVazio);
                    printf("\n");
                    printf("Coordenadas fora do tabuleiro.%s por favor entre "
                            "com novas coordenadas para a sua jogada:\n", 
                            jogador.nomeJogador2);
                    break;
                case 3:
                    ImprimeTabela(jogador, palavras, pontos);
                    printf("\n");
                    ImprimeTabuleiro(tabuleiroVazio);
                    printf("\n");
                    printf("Coordenadas ja jogadas.%s por favor entre com novas"
                            " coordenadas para a sua jogada:\n", 
                            jogador.nomeJogador2);
                    break;
            }
        }
        turno++;
        jogadaValida=0;
        jogaJogador=2;
        VerificaPalavra(tabuleiro, &tabuleiroVazio, coordenada, &palavras, 
                jogaJogador, &pontos, &dadosEstatistica, turno);
        ImprimeTabela(jogador, palavras, pontos);
        printf("\n");
        ImprimeTabuleiro(tabuleiroVazio);
        printf("\n");
        
        i++;
    }
    if(palavras.quantidadeDePalavrasDoJogador1 ==0 || 
            palavras.quantidadeDePalavrasDoJogador2 ==0 || i==tabuleiro.turnos){
        if(pontos.pontuacaoJogador1>pontos.pontuacaoJogador2)
            printf("%s Ganhou!!!\n", jogador.nomeJogador1);
        if(pontos.pontuacaoJogador2>pontos.pontuacaoJogador1)
            printf("%s Ganhou!!!\n", jogador.nomeJogador2);
        if(pontos.pontuacaoJogador1==pontos.pontuacaoJogador2)
            printf("Empate\n");
    }
    
    dadosEstatistica= OrdenaEstatistica(&dadosEstatistica, 
            palavras, qtdDePalavrasPorJogador);
    GeraArquivoEstatisticas(estatisticas, jogador, pontos, dadosEstatistica, 
            qtdDePalavrasPorJogador);
}
 
void ImprimeTabela(tJogador jogador, tPalavras palavras, tPontos pontos){
    int i;
    
    printf("|%20s %-20s|\n", "Palavras", "Restantes");
    
    printf("|%-16s", jogador.nomeJogador1);
    printf("(%02d)|", pontos.pontuacaoJogador1);
    
    printf("%-16s", jogador.nomeJogador2);
    printf("(%02d)|\n", pontos.pontuacaoJogador2);

    
    for(i=0; i<=21; i++){
        if(i==0 || i==21)
            printf("|");
        
        else
            printf("-");
    }
        
    for(i=0; i<=20; i++){
        if(i==20)
            printf("|");
        
        else
            printf("-");
    }
    printf("\n");
    
    for(i=0; i<palavras.quantidadeDePalavrasPorJogador; i++){
        printf("|%-20s|", palavras.palavrasDoJogador1[i]);
        printf("%-20s|", palavras.palavrasDoJogador2[i]);
        printf("\n");
    }
}

tTabuleiro InicializaTabuleiro(tTabuleiro tabuleiro){
    tTabuleiro tabuleiroVazio;
    
    tabuleiroVazio.turnos= tabuleiro.turnos;
    tabuleiroVazio.tamanhoDaMatriz= tabuleiro.tamanhoDaMatriz;
    int linha, coluna;
        for(linha=0 ; linha < tabuleiro.tamanhoDaMatriz ; linha++ ){
            for(coluna=0 ; coluna < tabuleiro.tamanhoDaMatriz ; coluna++ ){
                tabuleiroVazio.matrizDasPalavras[linha][coluna]=-1;
            }
        }
    return tabuleiroVazio;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int linha, coluna;
    
    printf("   ");
    for(coluna=0; coluna<tabuleiro.tamanhoDaMatriz; coluna++){
        printf(" %02d", coluna);
    }
    printf("\n");
    
    for(linha=0; linha<tabuleiro.tamanhoDaMatriz; linha++){
        printf("%02d|", linha);
        for(coluna=0; coluna<tabuleiro.tamanhoDaMatriz; coluna++){
            if(tabuleiro.matrizDasPalavras[linha][coluna]==-1 || 
                    tabuleiro.matrizDasPalavras[linha][coluna]=='\0'){
                printf(" - ");
            }
            else{
                printf(" %c ", tabuleiro.matrizDasPalavras[linha][coluna]);
            }
        }
        printf("|\n");
    }

}

void VerificaPalavra(tTabuleiro tabuleiro, tTabuleiro *tabuleiroVazio, 
        tCoordenada coordenada, tPalavras *palavras, int jogaJogador, 
        tPontos *pontos, tEstatistica *dadosEstatistica, int turno){
    int l, c, i=0, t=0; //contadores
    int encontrada; // SIM = 1. NÃO = 0.
    int qtdPalavras; //qauntidade de palavras por jogador
    int palavraDoJogadorX; //representa de qual jogador a palavra foi encontrada. palavraDoJogadorX=1 (palavra encontrada do jogador1), palavraDoJogadorX=2 (palavra encontrada do jogador2)
    int ponto; // variavel para armazenar a pontuacao recebida pela palavra encontrada e atualizar na estatistica
    
    l= coordenada.linha;
    c= coordenada.coluna;
    qtdPalavras= palavras->quantidadeDePalavrasPorJogador;
    
    //Inicialmente a palavra é considerada Não-Encontrada.
    encontrada = 0;
        
    //loop para verificar se a coordenada inserida eh a letra incial de alguma palavra do jogador 1
    for(i=0; i<qtdPalavras; i++){
        if (palavras->palavrasDoJogador1[i][0] == tabuleiro.matrizDasPalavras[l][c]) 
            //Se a primeira letra for encontrada
        {
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l - 1][c])
                //Se a segunda letra for encontrada acima (Norte)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l - t][c])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoNorte(coordenada, tabuleiro, tabuleiroVazio, 
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l + 1][c])
                //Se a segunda letra for encontrada abaixo (Sul)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l + t][c])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoSul(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto,
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
                
            }
            
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l][c + 1])
                //Se a segunda letra for encontrada a direita (Leste)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l][c + t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoLeste(coordenada, tabuleiro, tabuleiroVazio, 
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l][c - 1]) 
                //Se a segunda letra for encontrada a esquerda (Oeste)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l][c - t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoOeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l - 1][c + 1])
                //Se a segunda letra for encontrada acima-direita (Nordeste)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l - t][c + t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoNordeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto,
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l - 1][c - 1])
                //Se a segunda letra for encontrada acima-esquerda (Noroeste)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l - t][c - t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoNoroeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l + 1][c + 1]) 
                //Se a segunda letra for encontrada abaixo-direita (Sudeste)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l + t][c + t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoSudeste(coordenada, tabuleiro, tabuleiroVazio, 
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto,
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador1[i][1] == tabuleiro.matrizDasPalavras[l + 1][c - 1]) 
                //Se a segunda letra for encontrada abaixo-esquerda (Sudoeste)
            {
                encontrada = 1;
                palavraDoJogadorX=1;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++)
                    if (palavras->palavrasDoJogador1[i][t] != tabuleiro.matrizDasPalavras[l + t][c - t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoSudoeste(coordenada, tabuleiro, tabuleiroVazio, 
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
        }
    }
    
    
    //loop para verificar se a coordenada inserida eh a letra incial de alguma palavra do jogador 2
    for(i=0; i<qtdPalavras; i++){
        if (palavras->palavrasDoJogador2[i][0] == tabuleiro.matrizDasPalavras[l][c]) 
            //Se a primeira letra for encontrada
        {
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l - 1][c]) 
                //Se a segunda letra for encontrada acima (Norte)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l - t][c])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoNorte(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l + 1][c])
                //Se a segunda letra for encontrada abaixo (Sul)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l + t][c])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoSul(coordenada, tabuleiro, tabuleiroVazio, 
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
                
            }
            
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l][c + 1])
                //Se a segunda letra for encontrada a direita (Leste)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l][c + t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoLeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto,
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l][c - 1]) 
                //Se a segunda letra for encontrada a esquerda (Oeste)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l][c - t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoOeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l - 1][c + 1]) 
                //Se a segunda letra for encontrada acima-direita (Nordeste)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l - t][c + t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoNordeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l - 1][c - 1]) 
                //Se a segunda letra for encontrada acima-esquerda (Noroeste)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l - t][c - t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoNoroeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l + 1][c + 1]) 
                //Se a segunda letra for encontrada abaixo-direita (Sudeste)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l + t][c + t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoSudeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
            
            if (palavras->palavrasDoJogador2[i][1] == tabuleiro.matrizDasPalavras[l + 1][c - 1]) 
                //Se a segunda letra for encontrada abaixo-esquerda (Sudoeste)
            {
                encontrada = 1;
                palavraDoJogadorX=2;
                
                for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++)
                    if (palavras->palavrasDoJogador2[i][t] != tabuleiro.matrizDasPalavras[l + t][c - t])
                        encontrada = 0;
 
                if (encontrada){
                    PalavraSentidoSudoeste(coordenada, tabuleiro, tabuleiroVazio,
                            palavras, i, palavraDoJogadorX);
                    ponto = AtualizaPontuacao(pontos, palavraDoJogadorX, jogaJogador);
                    AtualizaEstatistica(i, palavras, dadosEstatistica, ponto, 
                            palavraDoJogadorX, turno);
                    AtualizaListaDePalavras(palavras, i, palavraDoJogadorX);
                    break;
                }
            }
        }
    }
    if(encontrada==0)
        NaoEhInicioDePalavra(coordenada, tabuleiro, tabuleiroVazio);
}

int VerificaCoordenadaValida(tCoordenada coordenada, tTabuleiro tabuleiroVazio){
    int l, c;
    l=coordenada.linha;
    c=coordenada.coluna;
    if(l>=tabuleiroVazio.tamanhoDaMatriz || c>=tabuleiroVazio.tamanhoDaMatriz)
        return 2; //jogada fora do tabuleiro
    if(l<0 || c<0)
        return 2;//jogada fora do tabuleiro
    if(tabuleiroVazio.matrizDasPalavras[l][c]>='A' && 
            tabuleiroVazio.matrizDasPalavras[l][c]<='Z')
        return 3; //coordenadas ja jogadas anteriormente
    return 1; //retorna 1 se a jogada for valida e nao foi jogada anteriormente
}

int AtualizaPontuacao(tPontos *pontos, int palavraDoJogadorX, int jogaJogador){
    //adiciona 2 pontos ao jogador1 se a palavra encontrada era dele e foi no turno dele
    if(jogaJogador==1 && palavraDoJogadorX== 1){
        pontos->pontuacaoJogador1= pontos->pontuacaoJogador1 + 2;
        return 2;
    }
    
    //adiciona 2 pontos ao jogador2 se a palavra encontrada era dele e foi no turno dele
    if(jogaJogador==2 && palavraDoJogadorX== 2){
        pontos->pontuacaoJogador2= pontos->pontuacaoJogador2 + 2;
        return 2;
    }
    
    //adiciona 1 ponto ao jogador2 se a palavra encontrada era dele, mas foi no turno do outro jogador
    if(jogaJogador==1 && palavraDoJogadorX==2){
        pontos->pontuacaoJogador2= pontos->pontuacaoJogador2 + 1;
        pontos->pontuacaoRecebidaJogador2= pontos->pontuacaoRecebidaJogador2 + 1;
        return 1;
    }
    
    //adiciona 1 ponto ao jogador1 se a palavra encontrada era dele, mas foi no turno do outro jogador
    if(jogaJogador==2 && palavraDoJogadorX==1){
        pontos->pontuacaoJogador1= pontos->pontuacaoJogador1 + 1;
        pontos->pontuacaoRecebidaJogador1= pontos->pontuacaoRecebidaJogador1 + 1;
        return 1;
    }
}

void AtualizaListaDePalavras(tPalavras *palavras, int i, int palavraDoJogadorX){
    int j, k, qtdDePalavras;
    char novaListaJogador[25][17];
    
    for(k=0; k<25; k++){
        novaListaJogador[k][0]= '\0';
    }
    
    k=0;
    qtdDePalavras= palavras->quantidadeDePalavrasPorJogador;
    if(palavraDoJogadorX==1){
        for(j=0; j<qtdDePalavras; j++){
            if(j!=i){
                strcpy(novaListaJogador[k], palavras->palavrasDoJogador1[j]);
                k++;
            }
        }
        palavras->quantidadeDePalavrasDoJogador1--;
        for(j=0; j<qtdDePalavras; j++){
            strcpy(palavras->palavrasDoJogador1[j], novaListaJogador[j]);
        }
    }
    
    if(palavraDoJogadorX==2){
        for(j=0; j<qtdDePalavras; j++){
            if(j!=i){
                strcpy(novaListaJogador[k], palavras->palavrasDoJogador2[j]);
                k++;
            }
        }
        palavras->quantidadeDePalavrasDoJogador2--;
        for(j=0; j<qtdDePalavras; j++){
            strcpy(palavras->palavrasDoJogador2[j], novaListaJogador[j]);
        }
    }
    if((palavras->quantidadeDePalavrasDoJogador1 && 
            palavras->quantidadeDePalavrasDoJogador2) < qtdDePalavras){
        if(palavras->quantidadeDePalavrasDoJogador1>=palavras->quantidadeDePalavrasDoJogador2)
            palavras->quantidadeDePalavrasPorJogador= palavras->quantidadeDePalavrasDoJogador1;
        
        if(palavras->quantidadeDePalavrasDoJogador2>=palavras->quantidadeDePalavrasDoJogador1)
            palavras->quantidadeDePalavrasPorJogador= palavras->quantidadeDePalavrasDoJogador2;
    }
}

void NaoEhInicioDePalavra(tCoordenada coordenada, tTabuleiro tabuleiro, 
        tTabuleiro *tabuleiroVazio){
    int linha, coluna;
    
    linha=coordenada.linha;
    coluna=coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[linha][coluna]= 
            ((tabuleiro.matrizDasPalavras[linha][coluna]-'a')+'A');
    
}

void PalavraSentidoNorte(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= 
            ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l - t][c]==-1)
            tabuleiroVazio->matrizDasPalavras[l - t][c]=palavras->palavrasDoJogador1[i][t];
        }
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l - t][c]==-1)
            tabuleiroVazio->matrizDasPalavras[l - t][c]=palavras->palavrasDoJogador2[i][t];
        }
    }
}

void PalavraSentidoSul(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l + t][c]==-1)
            tabuleiroVazio->matrizDasPalavras[l + t][c]=palavras->palavrasDoJogador1[i][t];
        }
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l + t][c]==-1)
            tabuleiroVazio->matrizDasPalavras[l + t][c]=palavras->palavrasDoJogador2[i][t];
        }
    }
}

void PalavraSentidoLeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l][c + t]==-1)
            tabuleiroVazio->matrizDasPalavras[l][c + t]=palavras->palavrasDoJogador1[i][t];
        }
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l][c + t]==-1)
            tabuleiroVazio->matrizDasPalavras[l][c + t]=palavras->palavrasDoJogador2[i][t];
        }
    }
}

void PalavraSentidoOeste(tCoordenada coordenada, tTabuleiro tabuleiro,
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l][c - t]==-1)
            tabuleiroVazio->matrizDasPalavras[l][c - t]=palavras->palavrasDoJogador1[i][t];
        }   
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l][c - t]==-1)
            tabuleiroVazio->matrizDasPalavras[l][c - t]=palavras->palavrasDoJogador2[i][t];
        }   
    }
}

void PalavraSentidoNordeste(tCoordenada coordenada, tTabuleiro tabuleiro,
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l - t][c + t]==-1)
            tabuleiroVazio->matrizDasPalavras[l - t][c + t]=palavras->palavrasDoJogador1[i][t];
        }    
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l - t][c + t]==-1)
            tabuleiroVazio->matrizDasPalavras[l - t][c + t]=palavras->palavrasDoJogador2[i][t];
        }    
    }
}

void PalavraSentidoNoroeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l - t][c - t]==-1)
            tabuleiroVazio->matrizDasPalavras[l - t][c - t]=palavras->palavrasDoJogador1[i][t];
        }    
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l - t][c - t]==-1)
            tabuleiroVazio->matrizDasPalavras[l - t][c - t]=palavras->palavrasDoJogador2[i][t];
        }    
    }
}

void PalavraSentidoSudeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l + t][c + t]==-1)
            tabuleiroVazio->matrizDasPalavras[l + t][c + t]=palavras->palavrasDoJogador1[i][t];
        }   
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l + t][c + t]==-1)
            tabuleiroVazio->matrizDasPalavras[l + t][c + t]=palavras->palavrasDoJogador2[i][t];
        }   
    } 
}

void PalavraSentidoSudoeste(tCoordenada coordenada, tTabuleiro tabuleiro, 
  tTabuleiro *tabuleiroVazio,tPalavras *palavras, int i, int palavraDoJogadorX){
    int t,l,c;
    
    l= coordenada.linha;
    c= coordenada.coluna;
    tabuleiroVazio->matrizDasPalavras[l][c]= ((tabuleiro.matrizDasPalavras[l][c]-'a')+'A');
    if(palavraDoJogadorX==1){
        for (t = 0; t < strlen(palavras->palavrasDoJogador1[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l + t][c - t]==-1)
            tabuleiroVazio->matrizDasPalavras[l + t][c - t]=palavras->palavrasDoJogador1[i][t];
        }   
    }
    if(palavraDoJogadorX==2){
        for (t = 0; t < strlen(palavras->palavrasDoJogador2[i]); t++){
        if(tabuleiroVazio->matrizDasPalavras[l + t][c - t]==-1)
            tabuleiroVazio->matrizDasPalavras[l + t][c - t]=palavras->palavrasDoJogador2[i][t];
        }   
    } 
}

tEstatistica OrdenaEstatistica(tEstatistica *dadosEstatistica, 
        tPalavras palavras, int qtdDePalavrasPorJogador){
    //essa funcao ordena em prioridade a pontuacao da palavra, 
    //seguida da ordem alfabetica da palavra
    
    int i, j, qtd1, qtd2, qtd3;
    qtd1=palavras.quantidadeDePalavrasDoJogador1;
    qtd2=palavras.quantidadeDePalavrasDoJogador2;
    tEstatistica estatisticaOrdenada;
    
    //completa o vetor de palavras das estatiticas com as palavras do jogador 1 
    //nao encontradas durante o jogo
    for(i=0; i<25; i++){
        if(dadosEstatistica->pontosPorPalavra[i]==-1){
            for(j=0;j<qtd1;j++){
                if(palavras.palavrasDoJogador1[j][0]!='\0'){
                    strcpy(dadosEstatistica->palavrasEstatistica[i], 
                            palavras.palavrasDoJogador1[j]);
                    dadosEstatistica->pontosPorPalavra[i]=0;
                    dadosEstatistica->numDoTurno[i]=0;
                    palavras.palavrasDoJogador1[j][0]='\0';
                    break;
                }
            }
        }
    }
    //completa o vetor de palavras das estatiticas com as palavras do jogador 2 
    //nao encontradas durante o jogo
    for(i=0; i<50; i++){
        if(dadosEstatistica->pontosPorPalavra[i]==-1){
            for(j=0;j<qtd2;j++){
                if(palavras.palavrasDoJogador2[j][0]!='\0'){
                    strcpy(dadosEstatistica->palavrasEstatistica[i], 
                            palavras.palavrasDoJogador2[j]);
                    dadosEstatistica->pontosPorPalavra[i]=0;
                    dadosEstatistica->numDoTurno[i]=0;
                    palavras.palavrasDoJogador2[j][0]='\0';
                    break;
                }
            }
        }
    }
    j=0, qtd1=0, qtd2=0, qtd3=0;
    for(i=0; i<2*qtdDePalavrasPorJogador; i++){ 
        //ordena primeiro as palavras com pontuacao igua a dois
        if(dadosEstatistica->pontosPorPalavra[i]==2){
            estatisticaOrdenada.pontosPorPalavra[j]= dadosEstatistica->pontosPorPalavra[i];
            estatisticaOrdenada.numDoTurno[j]= dadosEstatistica->numDoTurno[i];
            strcpy(estatisticaOrdenada.palavrasEstatistica[j], 
                    dadosEstatistica->palavrasEstatistica[i]);
            j++;
            qtd1++;
        }
    }
    for(i=0; i<2*qtdDePalavrasPorJogador; i++){
        if(dadosEstatistica->pontosPorPalavra[i]==1){ 
            //ordena as palavras com pontuacao igua a 1
            estatisticaOrdenada.pontosPorPalavra[j]= dadosEstatistica->pontosPorPalavra[i];
            estatisticaOrdenada.numDoTurno[j]= dadosEstatistica->numDoTurno[i];
            strcpy(estatisticaOrdenada.palavrasEstatistica[j],
                    dadosEstatistica->palavrasEstatistica[i]);
            j++;
            qtd2++;
        }
    }
    for(i=0; i<2*qtdDePalavrasPorJogador; i++){
        if(dadosEstatistica->pontosPorPalavra[i]==0){ //ordena as palavras sem pontuacao
            estatisticaOrdenada.pontosPorPalavra[j]= dadosEstatistica->pontosPorPalavra[i];
            estatisticaOrdenada.numDoTurno[j]= dadosEstatistica->numDoTurno[i];
            strcpy(estatisticaOrdenada.palavrasEstatistica[j], 
                    dadosEstatistica->palavrasEstatistica[i]);
            j++;
            qtd3++;
        }
    }
    
    j=0; int k;
    for(j=0; j<qtd1; j++){//organizar em ordem alfabetica as palavras de pontuacao igual a 2
        for(k=j+1; k<qtd1; k++){
            if(strcmp(estatisticaOrdenada.palavrasEstatistica[j], 
                    estatisticaOrdenada.palavrasEstatistica[k])>0){
                strcpy(dadosEstatistica->palavrasEstatistica[0], 
                        estatisticaOrdenada.palavrasEstatistica[k]);
                dadosEstatistica->pontosPorPalavra[0]=
                        estatisticaOrdenada.pontosPorPalavra[k];
                dadosEstatistica->numDoTurno[0]= 
                        estatisticaOrdenada.numDoTurno[k];
                
                strcpy(estatisticaOrdenada.palavrasEstatistica[k], 
                        estatisticaOrdenada.palavrasEstatistica[j]);
                estatisticaOrdenada.pontosPorPalavra[k]= 
                        estatisticaOrdenada.pontosPorPalavra[j];
                estatisticaOrdenada.numDoTurno[k]= 
                        estatisticaOrdenada.numDoTurno[j];
                
                strcpy(estatisticaOrdenada.palavrasEstatistica[j], 
                        dadosEstatistica->palavrasEstatistica[0]);
                estatisticaOrdenada.pontosPorPalavra[j]= 
                        dadosEstatistica->pontosPorPalavra[0];
                estatisticaOrdenada.numDoTurno[j]= dadosEstatistica->numDoTurno[0];
            }
        }
    }
    
    qtd2= qtd2+qtd1;
    for(j; j<qtd2; j++){//organizar em ordem alfabetica as palavras de pontuacao igual a 1
        for(k=j+1; k<qtd2; k++){
            if(strcmp(estatisticaOrdenada.palavrasEstatistica[j],
                    estatisticaOrdenada.palavrasEstatistica[k])>0){
                strcpy(dadosEstatistica->palavrasEstatistica[0], 
                        estatisticaOrdenada.palavrasEstatistica[k]);
                dadosEstatistica->pontosPorPalavra[0]= 
                        estatisticaOrdenada.pontosPorPalavra[k];
                dadosEstatistica->numDoTurno[0]= 
                        estatisticaOrdenada.numDoTurno[k];
                
                strcpy(estatisticaOrdenada.palavrasEstatistica[k], 
                        estatisticaOrdenada.palavrasEstatistica[j]);
                estatisticaOrdenada.pontosPorPalavra[k]= 
                        estatisticaOrdenada.pontosPorPalavra[j];
                estatisticaOrdenada.numDoTurno[k]= 
                        estatisticaOrdenada.numDoTurno[j];
                
                strcpy(estatisticaOrdenada.palavrasEstatistica[j], 
                        dadosEstatistica->palavrasEstatistica[0]);
                estatisticaOrdenada.pontosPorPalavra[j]= 
                        dadosEstatistica->pontosPorPalavra[0];
                estatisticaOrdenada.numDoTurno[j]= dadosEstatistica->numDoTurno[0];
            }
        }
    }
    
    qtd3= qtd3+qtd2;
    for(j; j<qtd3; j++){//organizar em ordem alfabetica as palavras de pontuacao igual a 0
        for(k=j+1; k<qtd3; k++){
            if(strcmp(estatisticaOrdenada.palavrasEstatistica[j],
                    estatisticaOrdenada.palavrasEstatistica[k])>0){
                strcpy(dadosEstatistica->palavrasEstatistica[0], 
                        estatisticaOrdenada.palavrasEstatistica[k]);
                dadosEstatistica->pontosPorPalavra[0]= 
                        estatisticaOrdenada.pontosPorPalavra[k];
                dadosEstatistica->numDoTurno[0]= estatisticaOrdenada.numDoTurno[k];
                
                strcpy(estatisticaOrdenada.palavrasEstatistica[k], 
                        estatisticaOrdenada.palavrasEstatistica[j]);
                estatisticaOrdenada.pontosPorPalavra[k]= 
                        estatisticaOrdenada.pontosPorPalavra[j];
                estatisticaOrdenada.numDoTurno[k]= estatisticaOrdenada.numDoTurno[j];
                
                strcpy(estatisticaOrdenada.palavrasEstatistica[j], 
                        dadosEstatistica->palavrasEstatistica[0]);
                estatisticaOrdenada.pontosPorPalavra[j]= 
                        dadosEstatistica->pontosPorPalavra[0];
                estatisticaOrdenada.numDoTurno[j]= dadosEstatistica->numDoTurno[0];
            }
        }
    }
    
    return estatisticaOrdenada;
}

void InicializaEstatistica(tEstatistica *dadosEstatistica, tPalavras palavras){
    int i;
    dadosEstatistica->j1=0;
    dadosEstatistica->j2= palavras.quantidadeDePalavrasPorJogador;
    
    for(i=0; i<50; i++){
        dadosEstatistica->numDoTurno[i]=-1;
        dadosEstatistica->pontosPorPalavra[i]=-1;
    }
}

void AtualizaEstatistica(int numDaPalavra, tPalavras *palavra, 
   tEstatistica *dadosEstatistica, int ponto, int palavraDoJogadorX, int turno){
    int i, j1, j2, qtdPalavras;
    i= numDaPalavra;
    qtdPalavras = palavra->quantidadeDePalavrasPorJogador;
    j1= dadosEstatistica->j1;
    j2= dadosEstatistica->j2;
    
    if(palavraDoJogadorX==1){
        // armazena o ponto da palavra encontrada para estatistica
        dadosEstatistica->pontosPorPalavra[j1]= ponto; 
        
        // armazena o turno da palavra encontrada para estatistica
        dadosEstatistica->numDoTurno[j1]= turno;
        
        // armazena a palavra encontrada para estatistica
        strcpy(dadosEstatistica->palavrasEstatistica[j1], palavra->palavrasDoJogador1[i]);
        dadosEstatistica->j1= j1+1;
    }
    
    if(palavraDoJogadorX==2){
        // armazena o ponto da palavra encontrada para estatistica
        dadosEstatistica->pontosPorPalavra[j2]= ponto; 
        
        // armazena o turno da palavra encontrada para estatistica
        dadosEstatistica->numDoTurno[j2]= turno; 
        
        // armazena a palavra encontrada para estatistica
        strcpy(dadosEstatistica->palavrasEstatistica[j2], palavra->palavrasDoJogador2[i]);
        dadosEstatistica->j2= j2+1;
    }
}