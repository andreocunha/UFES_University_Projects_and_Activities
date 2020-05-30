#include <stdio.h>
#include "ListaComSentinela.h"

int main (){

    Aluno* patricia = InicAliuno(123, "Patricia", 10);
    Aluno* alice = InicAliuno(123, "Alice", 10);
    Aluno* maria = InicAliuno(123, "Maria", 10);
    Aluno* joao = InicAliuno(123, "Joao", 10);

    Lista* lista = InicLista();
    InsereLista(lista, patricia);
    InsereLista(lista, alice);
    InsereLista(lista, maria);
    InsereLista(lista, joao);

    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    RetiraLista(lista, "Alice");
    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    InsereLista(lista, alice);
    printf("Imprimindo a lista\n");
    ImprimeLista(lista);

    DestroiLista(lista);
    return 0;
}
