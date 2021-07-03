#define _GNU_SOURCE  // Para funcionar o strdup sem dar warning
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equivalence.h"
#include "graph.h"
#include "list.h"
#include "point.h"

static int compare_point(const void* a, const void* b);

static int compare_list(const void* a, const void* b);

static void print_result(Equivalence** id, int size_id, int K, FILE* output);

int main(int argc, char* argv[]) {
    char *coord, *word;
    char div[2] = ",";
    int count = 0;

    //variáveis usadas no getline
    char* line_buf = NULL;
    size_t line_buf_size = 0;
    ssize_t line_size;

    int N = 0;  //N é o número de pontos
    int M = 0;  //M é oúero de coordenadas em um ponto

    //verifica se todos argumentos foram usados
    if (argc < 4) {  //./trab1 <nome_arquivo_entrada> k <nome_arquivo_saida>
        printf("Falta argumentos!!\n");
        return 0;
    }

    //pega o valor de K dos argumentos passados para o programa
    int K = atoi(argv[2]);

    //tenta abrir o arquivo de entrada no modo de leitura
    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Arquivo invalido.\n");
        return 0;
    }
    //tenta abrir o arquivo de saída no modo de escrita
    FILE* output = fopen(argv[3], "w");
    if (output == NULL) {
        printf("Arquivo invalido.\n");
        return 0;
    }

    //lê todo o arquivo de entrada para pegar o valor de M e N

    line_size = getline(&line_buf, &line_buf_size, input);
    while (line_size >= 0) {
        N++;
        if (M == 0) {
            coord = strtok(line_buf, div);
            while (coord != NULL) {
                coord = strtok(NULL, div);
                M++;
            }
        }
        line_size = getline(&line_buf, &line_buf_size, input);
    }
    M--;

    //volta para o início do arquivo
    rewind(input);

    //agora que sabe-se o valor de N, é possível iniciar as variáveis que faltavam
    double coord_double[M];
    Point* points[N];
    Graph* graph = new_graph(N);
    Equivalence** id = new_equivalence_vector(N);

    //armazena os valores do arquivo de entrada
    line_size = getline(&line_buf, &line_buf_size, input);
    while (line_size >= 0) {
        int i = 0;

        //Pega o nome da coordenada
        word = strtok(line_buf, div);

        //Pega as coodernadas
        coord = strtok(NULL, div);
        while (coord != NULL) {
            coord_double[i] = atof(coord);
            coord = strtok(NULL, div);
            i++;
        }
        Point* p = new_point(word, M, coord_double);
        points[count] = p;
        count++;
        line_size = getline(&line_buf, &line_buf_size, input);
    }

    //organiza os pontos por ordem alfabética
    qsort(points, N, sizeof(Point*), compare_point);

    //gera os valores de distância entra os pontos
    populate_graph(graph, points);

    //roda o algoritmo para gerar as clusters
    generate_clusters(graph, points, id, K);

    //gera o arquivo de saída com os resultados
    print_result(id, N, K, output);

    //libera a memória
    destroy_equivalence_vector(id, N);
    destroy_graph(graph);

    for (int i = 0; i < N; i++)
        destroy_point(points[i]);

    fclose(input);
    fclose(output);
    free(line_buf);
    return 0;
}

static int compare_point(const void* a, const void* b) {
    /*
    * Segundo a ordem alfabética retorna um valor:
    * > 0 -> primeiro parametro maior que o segundo
    * = 0 -> parametros iguais
    * < 0 -> segundo parametro maior que o primeiro
    */
    Point* a1 = *(Point**)a;
    Point* a2 = *(Point**)b;

    return strcmp(get_name_point(a1), get_name_point(a2));
}

static int compare_list(const void* a, const void* b) {
    /*
    * Retorna:
    * > 0 -> primeiro parametro maior que o segundo
    * = 0 -> parametros iguais
    * < 0 -> segundo parametro maior que o primeiro
    * 
    * De acordo com a ordem alfabédica do primeiro elemento de cada grupo, se a lista estiver vazia, retornará NULL
    * e ele será ordenado para o fim da lista
    */
    List* a1 = *(List**)a;
    List* a2 = *(List**)b;

    char* name1 = get_by_index_list(a1, 0);
    char* name2 = get_by_index_list(a2, 0);

    if (name1 == NULL && name2) return 1;
    if (name1 && name2 == NULL) return -1;
    if (name1 == NULL && name2 == NULL) return 0;

    return strcmp(name1, name2);
}

static void print_result(Equivalence** id, int size_id, int K, FILE* output) {
    /*
     * Imprime o resultado no arquivo de saída recebido
     */
    List* vet_list[size_id];

    for (int i = 0; i < size_id; i++) {
        vet_list[i] = new_list();
    }

    for (int i = 0; i < size_id; i++) {
        int index = find_equivalence_index(id, size_id, get_point(id[i]));
        int root = UF_find(id, index);
        insert_end_list(vet_list[root], get_name_point(get_point(id[i])));
    }

    qsort(vet_list, size_id, sizeof(List*), compare_list);

    for (int i = 0; i < size_id; i++) {
        if (!empty_list(vet_list[i])) {
            print_list(vet_list[i], output);
        }
        destroy_list(vet_list[i]);
    }
}
