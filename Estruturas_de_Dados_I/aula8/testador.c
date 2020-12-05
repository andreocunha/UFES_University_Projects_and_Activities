#include <stdio.h>
#include "Aluno.h"
#include "Fila.h"

int 
main()
{
    Aluno *patricia = InicAluno(123, "Patricia", 10);
    Aluno *alice = InicAluno(656, "alice", 5);
    Aluno *maria = InicAluno(21, "Maria", 9);
    Aluno *joao = InicAluno(999, "Joao", 8);

    Fila* f1 = inicFila();
    Fila* f2 = inicFila();

    insereFila(f1, patricia);
    insereFila(f1, alice);
    insereFila(f1, maria);
    insereFila(f1, joao);

    printf("\n Imprimindo fila f1:\n");
    imprimeFila(f1);

    insereFila(f2, retiraFila(f1));

    printf("\n Imprimindo fila f1:\n");
    imprimeFila(f1);

    printf("\n Imprimindo fila f2:\n");
    imprimeFila(f2);

    insereFila(f2, retiraFila(f1));
    insereFila(f2, retiraFila(f1));
    insereFila(f2, retiraFila(f1));
    insereFila(f2, retiraFila(f1));

    printf("\n Imprimindo fila f1:\n");
    imprimeFila(f1);

    printf("\n Imprimindo fila f2:\n");
    imprimeFila(f2);

    destroiFila(f1);
    destroiFila(f2);


    DestroiAluno(patricia);
    DestroiAluno(alice);
    DestroiAluno(maria);
    DestroiAluno(joao);

    return 0;
}