#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"
#include "priority_queue.h"

double* dijkstra_function(Grafo* graph, int orig)
{
    // Pega o numero de vertices do grafo
    int V = retornaNvertices(graph);

    // vetor auxiliar de distancias
    // double Pd[V];
    double* Pd = (double*)malloc(sizeof(double)*V);

    // Inicializa a priority queue
    Pqueue * pq = inicializa_PQ(V);

    //inicializa o vetor de distancias e a PQ
    for (int v = 0; v < V; ++v)
    {
        //armazena um numero muito grante no vetor
        Pd[v] = (double)INT_MAX;
        //cria o Item a ser inserido na PQ
        Item * it = cria_Item(Pd[v], v);
        //insere o Item na PQ
        insere_PQ(pq, it);
    }

    //setando o peso da origem para zero na priority queue
    setPeso_PQ(pq, orig, 0);
    //setando o peso da origem para zero no vetor de PD
    Pd[orig] = 0;

    while (!vazio_PQ(pq)){
        //extrai o primeiro elemento da lista
        Item * it = delmax_PQ(pq);
        //extrai o vertice de it
        int u = getVertice(it);
        //pega o primeiro elemento da lista de elentos ligados ao vertice it
        NohLista * lista = getCabeca(graph, u);

        while (lista != NULL){
            //pega o vertice da lista de adj
            int v = getVerticeDest(lista);
            //se v estiver na PQ e
            //Pd[u] ja tenha sido acessada e
            //se a distancia de u ate v mais a distancia da origem ate u eh menor que a distancia da origem ate v
            if (buscaVertice_PQ(pq, v) && Pd[u] != (double)INT_MAX && getVerticePeso(lista) + Pd[u] < Pd[v]){

                //atualiza o peso atual e coloca na PD
                Pd[v] = Pd[u] + getVerticePeso(lista);

                //atualiza o peso atual na priority queue
                setPeso_PQ(pq, v, Pd[v]);
            }
            //percorre a lista ate NULL
            lista = proximoListaNoh(lista);
        }
        //libera o item
        //destroi_ItemSolo(it);
    }
    //libera a PQ
    destroi_PQ(pq, V+1);

    //retorna a distancia da origem até o destino
    return Pd;
}

//calcula os RTTs normais
double RTT(int orig, int dest, double** matriz){
    return matriz[orig][dest] + matriz[dest][orig];
}

//calcula os RTTs minimos dos monitores
double RTT_min(int orig, int dest, int* monitores, int modM, double** matriz){
    double minimo = -1;
    //armazena o minimo caminho e retorna no final
    for(int i = 0; i < modM; i++){
        double atual = RTT(orig, monitores[i], matriz) + RTT(monitores[i], dest, matriz);
        if(atual < minimo || minimo == -1 ){
            minimo = atual;
        }
    }
    return minimo;
}

double** faztudo(int tamanhoMatriz){
    int i;
    double** matrizBolada = (double**)malloc((tamanhoMatriz) * sizeof(double*));
    for(i = 0; i < tamanhoMatriz; i++){
        matrizBolada[i] = ((double*)malloc((tamanhoMatriz) * sizeof(double)));
        // for(j = 0; j < tamanhoMatriz; j++){
        //     matrizBolada[i][j] = 0;
        // }
    } 
    
    return matrizBolada;
}


//calcula todos os RTTs e imprime as saidas
void RTT_all(Grafo* grafo, Mark *server, Mark *client, Mark *monitor, FILE* out){

    //pega o tamanho dos vetores de server, clientes e monitores
    int sizeS = getsize_Mark(server);
    int sizeC = getsize_Mark(client);
    int sizeM = getsize_Mark(monitor);
    
    int Mserver = get_maiorValor(server);
    int Mclient = get_maiorValor(client);
    int Mmonitor = get_maiorValor(monitor);
    
    int tamanhoMatriz = Mclient;
    if(Mserver > tamanhoMatriz){
        tamanhoMatriz = Mserver;
    }
    if(Mmonitor > tamanhoMatriz){
        tamanhoMatriz = Mmonitor;
    }
    tamanhoMatriz++;
    double** MatrizFinal = faztudo(tamanhoMatriz);

    //calcula o numero de linhas do resultado
    int rttsize = sizeS * sizeC;

    //cria dois vetores para armazenar os rtts
    double rtts[rttsize];
    double rtts_m[rttsize];

    Result* results[rttsize];
    int count = 0;

    //retorna o vetor de monitores para passar como parametro
    int * mon = getVet_Mark(monitor);

    for (int i = 0; i < sizeS; i++) {
        int a = get_Mark(i, server);
        free(MatrizFinal[a]);
        MatrizFinal[a] = dijkstra_function(grafo, a);
    }

    for (int i = 0; i < sizeC; ++i) {
        int a = get_Mark(i, client);
        free(MatrizFinal[a]);
        MatrizFinal[a] = dijkstra_function(grafo, a);
    }

    for (int i = 0; i < sizeM; ++i) {
        int a = get_Mark(i, monitor);
        free(MatrizFinal[a]);
        MatrizFinal[a] = dijkstra_function(grafo, a);
    }

    for (int i = 0; i < sizeS; ++i) {
        for (int j = 0; j < sizeC; ++j) {
            int orig = get_Mark(i, server);
            int dest = get_Mark(j, client);

            rtts[i + j] = RTT(orig, dest, MatrizFinal);

            rtts_m[i + j] = RTT_min(orig, dest, mon, sizeM, MatrizFinal);

            //salva os resultados no vetor
            results[count] = new_result(orig, dest, rtts_m[i + j]/rtts[i + j]);
            count++;
            
        }
    }

    //ordena os resultados em ordem crescente dos rtts
    quicksort(results, 0, rttsize - 1);

    //imprime os resultados no arquivo de saida
    imprime_results(results, rttsize, out);

    //deleta o vetor com os resultados
    destroi_result(results, rttsize);


    for(int i = 0; i < tamanhoMatriz; i++){
        free(MatrizFinal[i]);
    }
    free(MatrizFinal);
}