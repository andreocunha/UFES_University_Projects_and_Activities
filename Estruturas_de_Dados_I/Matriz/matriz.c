//Feito por: Andre Oliveira Cunha
// 3 periodo de Engenharia de Computacao UFES

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


struct matriz{
    int linha;
    int coluna;
    int* elem;
};


Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *mat;

    mat = (Matriz*)malloc(sizeof(Matriz));

    if (mat == NULL){
        printf("Memoria insuficiente\n");
    }

    mat->linha = nlinhas;
    mat ->coluna = ncolunas;
    mat->elem = (int*)malloc(nlinhas*ncolunas*sizeof(int));

    return mat;
}


void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    int nColunas = recuperaNColunas(mat);
    mat->elem[(linha)*nColunas + (coluna)] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    int nColunas = recuperaNColunas(mat);
    return mat->elem[linha*nColunas + coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->coluna;
}

int recuperaNLinhas (Matriz* mat){
    return mat->linha;
}


Matriz* transposta (Matriz* mat){
    int nLinhas = recuperaNLinhas(mat);
    int nColunas = recuperaNColunas(mat);
    Matriz* transp = inicializaMatriz(nColunas, nLinhas);
    
    for(int l=0; l<nLinhas; l++){
        for(int c=0; c<nColunas; c++){
            transp->elem[(c)*nLinhas + (l)] = mat->elem[(l)*nColunas + (c)];
        }
    }
    return transp;
}


Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    int nLinhas = recuperaNLinhas(mat1);
    int nColunas = recuperaNColunas(mat2);
    int produto=0, elem1=0, elem2=0;
    Matriz* mult = inicializaMatriz(nLinhas, nColunas);
    
    for (int l = 0; l < nLinhas; l++){
        for(int c=0; c < nColunas; c++){
            produto = 0;
            for(int i=0; i< mat1->coluna; i++){
                elem1 = recuperaElemento(mat1, l, i);
                elem2 = recuperaElemento(mat2, i, c);
                produto = produto + elem1*elem2;
            }
            mult->elem[(l)*mult->coluna + (c)] = produto;
        }
    }
    return mult;
}

void imprimeMatriz(Matriz* mat){
    int nLinhas = recuperaNLinhas(mat);
    int nColunas = recuperaNColunas(mat);
    int elem=0;

    for(int l=0; l < nLinhas; l++){
        for(int c=0; c < nColunas; c++){
            elem = recuperaElemento(mat, l, c);
            printf("%d ", elem);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat){
    free(mat->elem);
    free(mat);
}
