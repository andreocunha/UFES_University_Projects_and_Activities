#include "arv.h"

void limpaVetor(char *vet);

int main(int argc, char *argv[])
{
    FILE *arqEntrada;
    FILE *arqSaida;
    char entrada[300];

    arqEntrada = fopen(argv[1], "r");
    arqSaida = fopen("saida.txt", "w");

    if (arqEntrada == NULL)
    {
        printf("Erro na abertura do arquivo de entrada");
        exit(1);
    }
    if (arqSaida == NULL)
    {
        printf("Erro ao gerar o arquivo de saida");
        exit(2);
    }

    //enquanto nao for o final do arquivo
    while (!feof(arqEntrada))
    {
        limpaVetor(entrada);
        fscanf(arqEntrada, "%s", entrada); //le a entrada no arquivo

        Arvore *arv = criaArvore();
        int pos = 0;

        arv = parsing(arv, entrada, &pos); //monta a arvore binaria
        fprintf(arqSaida, "%.0f\n", resultado(arv)); //salva o resultado no arquivo de saida
        liberaArvore(arv); //libera a arvore
    }

    fclose(arqEntrada);
    fclose(arqSaida);
    return 0;
}

//funcao que limpa um vetor de char
void limpaVetor(char *vet)
{
    for (int i = 0; i < (int)sizeof(vet); i++)
    {
        vet[i] = '\0';
    }
}