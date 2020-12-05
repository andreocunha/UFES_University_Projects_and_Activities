#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Professor.h"

struct professor{
    int siape;
    char* nome;
    float salario;
};

Professor* InicProfessor (int siape, char* nome, float salario){
    Professor* prof = (Professor*)malloc(sizeof(Professor));
    prof->siape = siape;
    prof->salario = salario;

    int n = strlen(nome) + 1;
    char *professor_nome = malloc(n);
    if(professor_nome)
    {
        strcpy(professor_nome, nome);
    }

    prof->nome = professor_nome;

    return prof;
}

void ImprimeProfessor( Professor* prof){
    printf("Siape: %d, Nome: %s, Salario: %.2f\n", prof->siape, prof->nome, prof->salario);

}

int RetornaSiape(Professor* prof){
    return prof->siape;
}

char* RetornaNomeProfessor(Professor* prof){
    return prof->nome;
}

float RetornaSalario(Professor* prof){
    return prof->salario;
}

void DestroiProfessor(Professor* prof){
    free(prof->nome);
    free(prof);
}
