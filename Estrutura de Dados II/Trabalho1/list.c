#include "list.h"

typedef struct cell Cell;

struct cell {
    char* name_point;
    Cell* next;
};

struct list {
    Cell* first;
    Cell* last;
};

List* new_list() {
    List* list = (List*)malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;

    return list;
}

void insert_end_list(List* l, char* name_point) {
    Cell* nova = (Cell*)malloc(sizeof(Cell));
    nova->name_point = name_point;
    nova->next = NULL;

    if (l->last == NULL)
        l->first = nova;
    else
        l->last->next = nova;

    l->last = nova;
}

char* get_by_index_list(List* l, int i) {
    int j = 0;
    Cell* aux = l->first;

    if (empty_list(l)) return NULL;

    while (aux != NULL && j != i) {
        aux = aux->next;
        j++;
    }
    return aux->name_point;
}

int empty_list(List* l) {
    if (l->first == NULL && l->last == NULL)
        return 1;
    return 0;
}

void print_list(List* l, FILE* output) {
    Cell* aux = l->first;

    while (aux != NULL) {
        fprintf(output, "%s", aux->name_point);
        if (aux->next != NULL) {
            fprintf(output, ",");
        }
        aux = aux->next;
    }
    fprintf(output, "\n");
}

void destroy_list(List* l) {
    Cell* aux = l->first;
    Cell* next;

    if (aux) {
        while (aux) {
            next = aux->next;
            free(aux);
            aux = next;
        }
    }
    free(l);
}