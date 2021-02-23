#include <stdio.h>
#include "aluno.h"

int main(){
    Aluno* aluno;

    aluno = InicAluno("Andre", 10.0);

    printf("Nome: %s\n", RetornaNome(aluno));
    printf("Nota: %.2f\n", RetornaNota(aluno));

    DestroiAluno(aluno);
    return 0;
}