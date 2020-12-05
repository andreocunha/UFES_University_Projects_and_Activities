#include <stdio.h>
#include "Aluno.h"
#include "PilhaDupla.h"

int 
main()
{
    Aluno *patricia = InicAluno(123, "Patricia", 10);
    Aluno *alice = InicAluno(656, "alice", 5);
    Aluno *maria = InicAluno(21, "Maria", 9);
    Aluno *joao = InicAluno(999, "Joao", 8);

    Pilha *p = inicPilha();

    pushPilha1(p, patricia);
    pushPilha1(p, alice);
    pushPilha1(p, maria);
    pushPilha1(p, joao);

    // Imprime a pilha 1
    printf("Imprimindo a pilha 1: \n");
    imprimePilha1(p);

    pushPilha2(p, popPilha1(p));
    pushPilha2(p, popPilha1(p));
    pushPilha2(p, popPilha1(p));
    pushPilha2(p, popPilha1(p));


    pushPilha2(p, popPilha1(p));

    //Imprime a pilha 1
    printf ("\nImprimindo a pilha 1:\n");
    imprimePilha1(p);

    //Imprime a pilha 2
    printf ("\nImprimindo a pilha 2: \n");
    imprimePilha2(p);

    destroi(p);

    DestroiAluno(patricia);
    DestroiAluno(alice);
    DestroiAluno(maria);
    DestroiAluno(joao);

    return 0;
}