#include <stdio.h>
#include "abb.h"

int main(int argc, char const *argv[])
{
    Arv *arvore = abb_cria();

    Aluno *a1 = InicAluno(12, "Andre", 10.0);
    Aluno *a2 = InicAluno(13, "Joao", 8.0);
    Aluno *a3 = InicAluno(14, "Lucas", 9.0);
    Aluno *a4 = InicAluno(15, "Andre", 10.0);
    Aluno *a5 = InicAluno(16, "Lucas", 6.0);

    arvore = abb_insere(arvore, a1);
    arvore = abb_insere(arvore, a2);
    arvore = abb_insere(arvore, a3);
    arvore = abb_insere(arvore, a4);
    arvore = abb_insere(arvore, a5);
    

    abb_imprime(arvore);

    arvore = abb_libera(arvore);

    DestroiAluno(a1);
    DestroiAluno(a2);
    DestroiAluno(a3);
    DestroiAluno(a4);
    DestroiAluno(a5);

    return 0;
}
