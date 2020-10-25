/*
 *********************************
 * Programa testador do ListaDpl
 *********************************
 */

#include <stdio.h>
#include "ListaDpl.h"

int main (){

    Aluno* patricia = InicAluno(123, "Patricia", 10);
    Aluno* alice = InicAluno(123, "Alice", 10);
    Aluno* maria = InicAluno(123, "Maria", 10);
    Aluno* andre = InicAluno(123, "Andre", 10);

    ListaDpl* lista = InicLista();
    lista = InsereLista(lista, patricia);
    lista = InsereLista(lista, alice);
    lista = InsereLista(lista, maria);
    lista = InsereLista(lista, andre);

    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    lista = RetiraLista(lista, "Alice");
    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    lista = InsereLista(lista, alice);
    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    lista = RetiraLista(lista, "Patricia");
    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    lista = RetiraLista(lista, "Alice");
    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    DestroiLista(lista);
    DestroiAluno(andre);
    DestroiAluno(patricia);
    DestroiAluno(maria);
    DestroiAluno(alice);
    return 0;
}
