#include "point.h"

struct point {
    char* name;
    int M;
    double* num;
};

Point* new_point(char* nome, int M, double* coords) {
    Point* new = (Point*)malloc(sizeof(Point));
    if (new == NULL) {
        printf("erro de alocação\n");
        exit(1);
    }

    new->M = M;
    new->num = (double*)malloc(sizeof(double) * M);
    if (new->num == NULL) {
        printf("erro de alocação\n");
        exit(1);
    }

    new->name = strdup(nome);
    for (int i = 0; i < M; i++)
        new->num[i] = coords[i];

    return new;
}

char* get_name_point(Point* p) {
    return p->name;
}

double distance(Point* a, Point* b) {
    int i;
    double sum = 0;
    for (i = 0; i < a->M; i++) {
        sum += (a->num[i] - b->num[i]) * (a->num[i] - b->num[i]);
    }

    return sqrt(sum);
}

void print_point(Point* p) {
    printf("%s -> ", p->name);
    for (int i = 0; i < p->M; i++)
        printf("%f ", p->num[i]);
    printf("\n");
}

void destroy_point(Point* p) {
    if (p->num)
        free(p->num);
    if (p->name)
        free(p->name);
    free(p);
}