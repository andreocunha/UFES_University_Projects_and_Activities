#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno{
    int mat;
    char* nome;
    float CR;
};

Aluno* InicAliuno (int mat, char* nome, float CR){
    Aluno* al = (Aluno*)malloc(sizeof(Aluno));
    al->mat = mat;
    al->CR = CR;
    al->nome = strdup(nome);

    return al;
}

void ImprimeAluno( Aluno* al){
    printf("mat: %d, nome: %s, CR: %.2f\n", al->mat, al->nome, al->CR);

}

int RetornaMat(Aluno* al){
    return al->mat;
}

char* RetornaNome(Aluno* al){
    return al->nome;
}

float RetornaCR(Aluno* al){
    return al->CR;
}

void DestroiAluno(Aluno* al){
    free(al->nome);
    free(al);
}
