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
        return 1;
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

        FILE *pont_arq;
        pont_arq = fopen("saida.csv", "w");
        
        if(pont_arq == NULL)
        {
            printf("Erro na abertura do arquivo saida.csv");
            return 1;
        }
        fprintf(pont_arq, "%s", "Nome,Nota,Situação\n");

        for (int i = 0; i < qtdDeAlunos; i++)
        {
            if(RetornaNota(aluno[i]) >= 7){
                fprintf(pont_arq, "%s,", RetornaNome(aluno[i]));
                fprintf(pont_arq, "%.2f,", RetornaNota(aluno[i]));
                fprintf(pont_arq, "%s\n", "Aprovado");
            }
            else{
                fprintf(pont_arq, "%s,", RetornaNome(aluno[i]));
                fprintf(pont_arq, "%.2f,", RetornaNota(aluno[i]));
                fprintf(pont_arq, "%s\n", "Prova Final");
            }
        }
        fclose(pont_arq);
        
        for (int i = 0; i < qtdDeAlunos; i++)
        {
            DestroiAluno(aluno[i]);
        }
        
    }
    
    fclose(arq);

    return 0;
}