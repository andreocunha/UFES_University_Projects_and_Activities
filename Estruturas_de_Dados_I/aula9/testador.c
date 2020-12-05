#include <stdio.h>
#include "Arvore.h"

int main(int argc, char const *argv[])
{
    Arvore *arvore1 = inicArvore();
    Arvore *arvore2 = inicArvore();
    Arvore *arvore3 = inicArvore();
    Arvore *arvore4 = inicArvore();
    Arvore *arvore5 = inicArvore();
    Arvore *arvore6 = inicArvore();

    Aluno *a1 = InicAluno(12, "Andre", 10.0);
    Aluno *a2 = InicAluno(13, "Joao", 8.0);
    Aluno *a3 = InicAluno(14, "Lucas", 9.0);
    Aluno *a4 = InicAluno(15, "Andre", 10.0);
    Aluno *a5 = InicAluno(16, "Lucas", 6.0);

    arvore3 = criaArvore(a5, inicArvore(), inicArvore());
    arvore5 = criaArvore(a3, inicArvore(), inicArvore());
    arvore6 = criaArvore(a2, inicArvore(), arvore5);
    arvore4 = criaArvore(a4, arvore2, arvore3);
    arvore1 = criaArvore(a1, arvore6, arvore4);

    int qtdFolhas = 0;
    int alt = 0;
    int qtdOcorrencias = 0;

    qtdOcorrencias = ocorrencias(arvore1, "Andre");
    printf("Numero de ocorrencias: %d\n", qtdOcorrencias);
    alt = altura(arvore1);
    printf("Altura da arvore: %d\n", alt);
    qtdFolhas = folhas(arvore1);
    printf("Quantidade de folhas: %d\n", qtdFolhas);

    printf("Vazia arvore3: %d\n", vaziaArvore(arvore3));
    printf("Vazia arvore2: %d\n", vaziaArvore(arvore2));

    imprimeArvore(arvore1);
    printf("\n");

    arvore1 = liberaArvore(arvore1);

    DestroiAluno(a1);
    DestroiAluno(a2);
    DestroiAluno(a3);
    DestroiAluno(a4);
    DestroiAluno(a5);

    return 0;
}
