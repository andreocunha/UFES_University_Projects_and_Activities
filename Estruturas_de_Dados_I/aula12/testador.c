#include <stdio.h>
#include "listaalunos.h"

int main(int argc, char const *argv[])
{
    ListaGenerica *lista = criaLista();

    Aluno *a1 = InicAluno(1, "joao", 7.0);
    lista = insereLista(lista, a1);
    Aluno *a2 = InicAluno(2, "patricia", 9.0);
    lista = insereLista(lista, a2);

    Aluno *a3 = InicAluno(3, "lucas", 9.0);
    lista = insereLista(lista, a3);

    Aluno *a4 = InicAluno(4, "andre", 10.0);
    lista = insereLista(lista, a4);

    Aluno *a5 = InicAluno(5, "larissa", 10.0);
    lista = insereLista(lista, a5);

    imprimeListaAlunos(lista);

    lista = retiraAluno(lista, 3);
    lista = retiraAluno(lista, 1);

    printf("\n");
    imprimeListaAlunos(lista);
    printf("\n");

    //Verificar se aluno esta na lista
    int i = pertenceAluno(lista, 1);
    if (i == 0)
    {
        printf("\nAluno esta na lista\n");
    }
    else
    {
        printf("Aluno nao esta na lista\n");
    }

    printf("\nA media da turma é: %.2f\n", mediaTurma(lista)); 

    liberaLista(lista);

    DestroiAluno(a1);
    DestroiAluno(a2);
    DestroiAluno(a3);
    DestroiAluno(a4);
    DestroiAluno(a5);

    return 0;
}
