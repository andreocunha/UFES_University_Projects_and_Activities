#include <string.h>
#include "Aluno.h"

struct aluno{
    int mat;
    char* nome;
    float CR;
};

Aluno* InicAluno (int mat, char* nome, float CR){
    Aluno* al = (Aluno*)malloc(sizeof(Aluno));
    al->mat = mat;
    al->CR = CR;

    int n = strlen(nome) + 1;
    char *aluno_nome = malloc(n);
    if(aluno_nome)
    {
        strcpy(aluno_nome, nome);
    }

    al->nome = aluno_nome;

    return al;
}

void ImprimeAluno( Aluno* al){
    printf("mat: %d, nome: %s, CR: %.2f\n", al->mat, al->nome, al->CR);

}

int RetornaMat(Aluno* al){
    return al->mat;
}

char* RetornaNomeAluno(Aluno* al){
    return al->nome;
}

float RetornaCR(Aluno* al){
    return al->CR;
}

void DestroiAluno(Aluno* al){
    free(al->nome);
    free(al);
}
