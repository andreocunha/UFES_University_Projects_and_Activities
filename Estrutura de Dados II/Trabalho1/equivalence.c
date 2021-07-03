#include "equivalence.h"

struct equivalence {
    Point* point;
    int parent;
};

Equivalence* new_equivalence(Point* p, int parent) {
    Equivalence* equivalence = (Equivalence*)malloc(sizeof(Equivalence));

    equivalence->point = p;
    equivalence->parent = parent;

    return equivalence;
}

Equivalence** new_equivalence_vector(int v) {
    Equivalence** equivalence = (Equivalence**)malloc(sizeof(Equivalence*) * v);
    return equivalence;
}

Point* get_point(Equivalence* e) {
    return e->point;
}

int get_parent(Equivalence* e) {
    return e->parent;
}

void set_parent(Equivalence* e, int parent) {
    e->parent = parent;
}

void UF_init(Equivalence** e, int size, int* sz, Point** points) {
    for (int i = 0; i < size; i++) {
        e[i] = new_equivalence(points[i], i);  // Cada objeto comeca na sua propria componente.
        sz[i] = 1;
    }  // N acessos ao array.
}

int UF_find(Equivalence** e, int i) {
    while (i != e[i]->parent) {
        e[i]->parent = e[e[i]->parent]->parent;
        i = e[i]->parent;  // Buscar o pai ate a raiz.
    }
    return i;
}

void UF_union(Equivalence** e, int parent_o, int parent_d, int* sz) {
    if (sz[parent_o] < sz[parent_d]) {
        e[parent_o]->parent = parent_d;
        sz[parent_d] += sz[parent_o];
    } else {
        e[parent_d]->parent = parent_o;
        sz[parent_o] += sz[parent_d];
    }
}

int find_equivalence_index(Equivalence** e, int size, Point* p) {
    int i;
    int maior = size, menor = 0;

    while (e[(maior + menor) / 2]->point != p) {
        if (strcmp(get_name_point(p), get_name_point(e[(maior + menor) / 2]->point)) > 0) {
            menor = (maior + menor) / 2;
        } else {
            maior = (maior + menor) / 2;
        }
    }

    i = (maior + menor) / 2;

    return i;
}

void destroy_equivalence(Equivalence* e) {
    free(e);
}

void destroy_equivalence_vector(Equivalence** e, int size) {
    int i;
    for (i = 0; i < size; i++) {
        destroy_equivalence(e[i]);
    }
    free(e);
}