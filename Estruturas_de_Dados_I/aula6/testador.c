/*
 *********************************
 * Programa testador do ListaHet
 *********************************
 */

#include <stdio.h>
#include "ListaHet.h"

int main (){

    // Alunos
    Aluno* patricia = InicAluno(123, "Patricia", 10);
    Aluno* alice = InicAluno(124, "Alice", 7);
    Aluno* maria = InicAluno(125, "Maria", 8);
    Aluno* andre = InicAluno(126, "Andre", 10);

    // Professores
    Professor* roberta = InicProfessor(234234, "Roberta", 9435.00);
    Professor* flavio = InicProfessor(234234, "Flavio", 7432.00);

    ListaHet* lista = InicLista();
    InsereAluno(lista, patricia);
    InsereProfessor(lista, roberta);
    InsereAluno(lista, alice);
    InsereAluno(lista, maria);
    InsereProfessor(lista, flavio);
    InsereAluno(lista, andre);

    printf("Imprimindo a lista\n");
    ImprimeListaHet(lista);

    printf("VALOR: %.2f ", ValorChurrasco(lista));


    DestroiLista(lista);
    DestroiAluno(andre);
    DestroiAluno(patricia);
    DestroiAluno(maria);
    DestroiAluno(alice);
    DestroiProfessor(roberta);
    DestroiProfessor(flavio);


    return 0;
}
