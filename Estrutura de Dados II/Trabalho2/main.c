#include <stdio.h>
#include "dijkstra.h"

int main(int argc, char const *argv[]) {
    
    //verifica a linha do terminal se esta correta
    if(argc < 3 ) {
        printf("Falta argumentos de entrada\n");
        exit(1);
    }
    //abre os arquivos de entrada e saida
    FILE* arqIn =  fopen(argv[1],"r");
    FILE* arqOut = fopen(argv[2],"w");

    //verifica se foram abertos
    if(arqIn == NULL || arqOut == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    int nVertices;
    int nArestas;
    int modS, modC, modM;
    //faz a leitura da primeira linha
    fscanf(arqIn,"%d %d",&nVertices, &nArestas);
    //faz a leitura da segunda linha
    fscanf(arqIn,"%d %d %d",&modS, &modC, &modM);

    //inicializa a estrutura que armazena os subconjuntos
    Mark * Server = inicializa_Mark(modS, arqIn);
    Mark * Clients = inicializa_Mark(modC, arqIn);
    Mark * Monitor = inicializa_Mark(modM, arqIn);

    //inicializa o grafo
    Grafo* graph = initGrafo(nVertices);

    int orig=0, dest=0;
    double peso=0;
    //faz a leitura das arestas e adiciona no grafo
    for (int i = 0; i < nArestas; i++)
    {
        fscanf(arqIn, "%d", &orig);
        fscanf(arqIn, "%d", &dest);
        fscanf(arqIn, "%lf", &peso);
        addAresta(graph, orig, dest, peso);
    }

    //realiza os calculos e as impressoes
    RTT_all(graph, Server, Clients, Monitor, arqOut);

    //fecha arquivos e libera memoria das estruturas
    fclose(arqIn);
    fclose(arqOut);
    destroi_Mark(Server);
    destroi_Mark(Clients);
    destroi_Mark(Monitor);
    liberaGrafo(graph);

    return 0;
}
