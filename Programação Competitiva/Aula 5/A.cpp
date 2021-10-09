#include <stdio.h>

int main()
{

    while (1)
    {
        int tam = 0,
            linhaImpar = -1,
            colunaImpar = -1,
            qtdLinhaImpar = 0,
            qtdColunaImpar = 0,
            soma = 0;

        scanf("%d", &tam);
        if(tam == 0){
            break;
        }
        int matrix[tam][tam];

        // adiciona os elementos na matriz e verifica as linhas
        for (int linha = 0; linha < tam; linha++)
        {
            for (int coluna = 0; coluna < tam; coluna++)
            {
                scanf("%d", &matrix[linha][coluna]);

                if (matrix[linha][coluna] == 1)
                {
                    soma++;
                }
            }
            if (soma % 2 != 0)
            {
                qtdLinhaImpar++;
                linhaImpar = linha + 1;
            }
            soma = 0;
        }

        // verifica as colunas
        for (int coluna = 0; coluna < tam; coluna++)
        {
            for (int linha = 0; linha < tam; linha++)
            {
                if (matrix[linha][coluna] == 1)
                {
                    soma++;
                }
            }
            if (soma % 2 != 0)
            {
                qtdColunaImpar++;
                colunaImpar = coluna + 1;
            }
            soma = 0;
        }

        if (qtdLinhaImpar == 0 && qtdColunaImpar == 0)
        {
            printf("OK\n");
        }
        else if (qtdLinhaImpar == 1 && qtdColunaImpar == 1)
        {
            printf("Change bit (%d,%d)\n", linhaImpar, colunaImpar);
        }
        else
        {
            printf("Corrupt\n");
        }
    }

    return 0;
}