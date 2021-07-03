#include "store_result.h"

struct result
{
    int server;
    int client;
    double rtt;
};

Result* new_result(int server, int client, double rtt){
    Result* new = (Result*)malloc(sizeof(Result));
    new->server = server;
    new->client = client;
    new->rtt = rtt;
    return new;
}

double get_rtt(Result* result){
    return result->rtt;
}

void quicksort(Result** results, int lo, int hi)
{
    int i = lo, j = hi, center = (lo + hi) / 2;
    double v = get_rtt(results[center]);
    Result* aux;

    while (i <= j) {
        if (get_rtt(results[i]) < v){
            i++;
        } 
        else if (get_rtt(results[j]) > v) {
            j--;
        }
        else {
            aux = results[i];
            results[i++] = results[j];
            results[j--] = aux;
        }
    }
    if (lo < j)
        quicksort (results, lo, j);
    if (hi > i)
        quicksort (results, i , hi);
}

void imprime_results(Result** results, int qtd, FILE* out){
    for(int i = 0; i < qtd; i++){
        fprintf(out, "%d %d %.16lf\n", results[i]->server, results[i]->client, results[i]->rtt);
    }
}

void destroi_result(Result** results, int qtd){
    for(int i = 0; i < qtd; i++){
        free(results[i]);
    }
}

