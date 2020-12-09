#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arvore.h"

void limpaVetor(char* vet)
{
    for(int i = 0; i< (int)sizeof(vet); i++)
    {
        vet[i] = '\0';
    }
}


int main(int argc, char **argv)
{
    FILE* arq;
    char entrada[300];

    arq = fopen(argv[1], "r");

    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    while (!feof(arq))
    {
        limpaVetor(entrada);
        fscanf(arq, "%s", entrada);

        Arvore *arv = criaArvore();
        int pos = 0;

        arv = Parsing(arv, entrada, &pos);
        imprimeArvore(arv);

        printf("\n%.2f\n", calculaEquacao(arv));
        liberaArvore(arv);
    }


    fclose(arq);
    return 0;
}
