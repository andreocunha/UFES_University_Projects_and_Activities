#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(int argc, char* argv[]){
    char nomeArquivo[80];
    char ch;
    FILE *arq;
    int qtdDeAlunos = 0;

    if(argc == 1){
        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);
    }
    else{
        strcpy(nomeArquivo, argv[1]);
    }

    arq = fopen(nomeArquivo, "r");
    if(arq == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else
    {
        fscanf(arq, "%d", &qtdDeAlunos);
        Aluno* aluno[qtdDeAlunos];
        char nome[80];
        float nota = 0;
        float media = 0;

        for (int i = 0; i < qtdDeAlunos; i++)
        {
            fscanf(arq, "%f", &nota);
            fscanf(arq, "%s", nome);
            aluno[i] = InicAluno(nome, nota);
        }

        media = RetornaMedia(aluno, qtdDeAlunos);
        
        for (int i = 0; i < qtdDeAlunos; i++)
        {
            if(RetornaNota(aluno[i]) > media){
                printf("O aluno %s tirou a nota ", RetornaNome(aluno[i]));
                printf("%.2f\n", RetornaNota(aluno[i]));
            }
        }
        
        for (int i = 0; i < qtdDeAlunos; i++)
        {
            DestroiAluno(aluno[i]);
        }
        
    }
    
    fclose(arq);

    return 0;
}