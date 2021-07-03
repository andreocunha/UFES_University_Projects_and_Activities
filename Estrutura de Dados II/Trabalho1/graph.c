#include "graph.h"

struct edge {
    Point* src;
    Point* dst;
    double dist;
};

struct graph {
    int V;
    int E;
    Edge** edges;
};

Graph* new_graph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    if (g == NULL) {
        printf("erro de alocação\n");
        exit(1);
    }
    g->V = V;
    int numEdge = (V * (V - 1)) / 2;
    g->E = numEdge;
    g->edges = (Edge**)malloc(sizeof(Edge*) * numEdge);
    if (g->edges == NULL) {
        printf("erro de alocação\n");
        exit(1);
    }
    return g;
}

static Edge* new_edge(Point* src, Point* dst, double dist) {
    Edge* a = (Edge*)malloc(sizeof(Edge));
    if (a == NULL) {
        printf("erro de alocação\n");
        exit(1);
    }

    a->src = src;
    a->dst = dst;
    a->dist = dist;

    return a;
}

void print_graph(Graph* g) {
    int i;
    for (i = 0; i < g->E; i++) {
        print_point(g->edges[i]->src);
        print_point(g->edges[i]->dst);
        printf("DISTANCIA: %lf\n\n", g->edges[i]->dist);
    }
}

void populate_graph(Graph* g, Point** points) {
    int i, j, k = 0;
    double d;

    for (i = 0; i < g->V; i++) {
        for (j = i + 1; j < g->V; j++, k++) {
            d = distance(points[i], points[j]);
            g->edges[k] = new_edge(points[j], points[i], d);
        }
    }
}

static int compare_edge(const void* a, const void* b) {
    /*
    * > 0 -> primeiro parametro maior que o segundo
    * = 0 -> parametros iguais
    * < 0 -> segundo parametro maior que o primeiro
    */
    Edge* e1 = *(Edge**)a;
    Edge* e2 = *(Edge**)b;

    if (e1->dist - e2->dist > 0)
        return 1;
    if (e1->dist - e2->dist < 0)
        return -1;
    else
        return 0;
}

static void destroy_edge(Edge* a) {
    free(a);
}

void generate_clusters(Graph* g, Point** points, Equivalence** id, int K) {
    int V = g->V;
    int qtd_edges = 0;
    int i = 0;
    int sz[V];
    Edge** result = (Edge**)malloc(sizeof(Edge*) * (V - K));
    if (result == NULL) {
        printf("erro de alocação\n");
        exit(1);
    }

    UF_init(id, V, sz, points);

    qsort(g->edges, g->E, sizeof(Edge*), compare_edge);

    // Repete o algorítmo até que o número de arestas seja menor que V-K, isso garante que ao final teremos K grupos
    while (qtd_edges < V - K) {
        // Pega a próxima menor aresta
        Edge* next_edge = g->edges[i];

        // Pega a raíz de dois pontos para verificar se estão conectados
        int index_o = find_equivalence_index(id, V, next_edge->src);
        int index_d = find_equivalence_index(id, V, next_edge->dst);
        int root_o = UF_find(id, index_o);
        int root_d = UF_find(id, index_d);

        // Se os pontos ainda não estiverem conectados, eles são conectados, e o número de arestas aumenta
        if (root_o != root_d) {
            result[qtd_edges] = new_edge(next_edge->src, next_edge->dst, next_edge->dist);
            UF_union(id, root_o, root_d, sz);
            qtd_edges++;
        }
        i++;
    }

    for (i = 0; i < g->E; i++)
        destroy_edge(g->edges[i]);
    free(g->edges);

    g->edges = result;
    g->E = V - K;
}

void destroy_graph(Graph* g) {
    int i;
    for (i = 0; i < g->E; i++)
        destroy_edge(g->edges[i]);
    free(g->edges);
    free(g);
}
