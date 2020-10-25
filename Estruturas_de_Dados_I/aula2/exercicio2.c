/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * Aula 2
 *
 * Exercicio 2
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

struct aluno
{
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};

void lerNome(char** nome);
void lerDados(Aluno* aluno);
void imprimeTurma(Aluno** turma, int n);
void imprime_aprovados(int n ,Aluno** turma);
float media_turma(int n ,Aluno** turma);

int
main(void)
{
    int n;
    float media=0;
    printf("Quantidade de alunos: ");
    scanf("%d", &n);
    Aluno** turma = (Aluno**)malloc(n * sizeof(Aluno*));


    for(int i=0; i<n; i++)
    {
        Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
        turma[i] = aluno;
        lerDados(turma[i]);
        printf("\n");
    }

    imprimeTurma(turma, n);
    imprime_aprovados(n, turma);
    media = media_turma(n, turma);

    printf("Media da turma: %.2f\n", media);
    
    for(int i=0; i<n; i++)
    {
        free(turma[i]->nome);
        free(turma[i]);
    }
    free(turma);

    return 0;
}

void lerNome(char** nome)
{
    setbuf(stdin, NULL);
    char* aux;
    aux = (char*)malloc(150* sizeof(char));

    printf("Digite o nome: ");
    scanf("%[^\n]s", aux);
    setbuf(stdin, NULL);

    *nome = strdup(aux);
    free(aux);

}

void lerDados(Aluno* aluno)
{
    lerNome(&aluno->nome);
    printf("Matricula: ");
    scanf("%d", &aluno->matricula);
    printf("Nota p1: ");
    scanf("%f", &aluno->p1);
    printf("Nota p2: ");
    scanf("%f", &aluno->p2);
    printf("Nota p3: ");
    scanf("%f", &aluno->p3);
}

void imprimeTurma(Aluno** turma, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Nome: %s\n", turma[i]->nome);
        printf("Matricula: %d\n", turma[i]->matricula);
        printf("Notas:\nP1: %.2f, P2: %.2f, P3: %.2f\n", turma[i]->p1, turma[i]->p2, turma[i]->p3);
        printf("\n");
    }
}

void imprime_aprovados(int n ,Aluno** turma)
{
    float media = 0;
    printf("Alunos aprovados: ");

    for(int i=0; i<n; i++)
    {
        media = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3;
        if(media >= 5)
        {   
            if(i>0)
                printf(", ");
            printf("%s", turma[i]->nome);
        }
    }
    printf("\n");
}

float media_turma(int n ,Aluno** turma)
{
    float media = 0;

    for(int i=0; i<n; i++)
    {
        media += (turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3;
    }
    return (media/n);
}