/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * Aula 3
 *
 * Exercicio 3
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz{
    int nlinhas;
    int ncolunas;
    int **mat;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
    matriz->mat = (int**)malloc(sizeof(int*) * nlinhas);
    matriz->nlinhas = nlinhas;
    matriz->ncolunas = ncolunas;

    for(int i = 0; i < nlinhas; i++)
    {
        int* linha = (int*)malloc(sizeof(int) * ncolunas);
        matriz->mat[i] = linha;
    }
    return matriz;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    return mat->mat[linha][coluna];
}

int recuperaNColunas (Matriz* mat)
{
    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat)
{
    return mat->nlinhas;
}

Matriz* transposta (Matriz* mat)
{
    int linha=0, coluna=0;
    linha = recuperaNLinhas(mat);
    coluna = recuperaNColunas(mat);
    Matriz *transp = inicializaMatriz(coluna, linha);

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            modificaElemento(transp, j, i, recuperaElemento(mat, i, j));
        }
    }
    return transp;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
    int linha=0, coluna=0, soma=0;
    linha = recuperaNLinhas(mat1);
    coluna = recuperaNColunas(mat2);

    Matriz *matriz = inicializaMatriz(linha, linha);

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            for (int k = 0; k < mat1->ncolunas; k++)
            {
                soma += recuperaElemento(mat1, i, k)*recuperaElemento(mat2, k, j);
            }
            modificaElemento(matriz, i, j, soma);
            soma = 0;
        }
    }
    
    return matriz;
}


void imprimeMatriz(Matriz* mat)
{
    int linha=0, coluna=0;
    linha = recuperaNLinhas(mat);
    coluna = recuperaNColunas(mat);

    for(int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", recuperaElemento(mat, i, j));
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat)
{
    int linha=0;
    linha = recuperaNLinhas(mat);

    for (int i = 0; i < linha; i++)
    {
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}