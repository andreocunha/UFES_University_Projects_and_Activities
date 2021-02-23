#include "aluno.h"

struct aluno{
    char* nome;
    float nota;
};

Aluno* InicAluno (char* nome, float nota){
    Aluno* al = (Aluno*)malloc(sizeof(Aluno));
    al->nota = nota;

    int n = strlen(nome) + 1;
    char *aluno_nome = malloc(n);
    if(aluno_nome)
    {
        strcpy(aluno_nome, nome);
    }

    al->nome = aluno_nome;

    return al;
}

char* RetornaNome(Aluno* al){
    return al->nome;
}

float RetornaNota(Aluno* al){
    return al->nota;
}

float RetornaMedia(Aluno** al, int qtd){
    float media = 0.0;
    
    for (int i = 0; i < qtd; i++)
    {
        media += al[i]->nota;
    }
    media = media/qtd;
    
    return media;
}

void DestroiAluno(Aluno* al){
    free(al->nome);
    free(al);
}