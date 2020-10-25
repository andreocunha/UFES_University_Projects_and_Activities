/*
 *********************************
 * Programa testador do listaMat
 *********************************
 */
#include <stdio.h>
#include "listaMat.h"

//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 4
#define NCOLUNAS 3

int main()
{
    Matriz* mat1;
    Matriz* mat2;
    Matriz* mat3;


    //chamando a funcao do TAD Matriz que inicializa a matriz
    mat1 = inicializaMatriz(NLINHAS, NCOLUNAS);
    mat2 = inicializaMatriz(NLINHAS, NCOLUNAS);
    mat3 = inicializaMatriz(NLINHAS, NCOLUNAS);


    int i, j;
    //preenchendo a matriz 1 com valores para teste
    for (i=0;i<NLINHAS;i++)
        for (j=0;j<NCOLUNAS; j++)
            //chamando a funcao do TAD matriz para modificar um dado elemento da matriz
            modificaElemento(mat1, i, j,i+j);

    //preenchendo a matriz 2 com valores para teste
    for (i=0;i<NLINHAS;i++)
        for (j=0;j<NCOLUNAS; j++)
            modificaElemento(mat2, i, j,i*j);

    //preenchendo a matriz 3 com valores para teste
    for (i=0;i<NLINHAS;i++)
        for (j=0;j<NCOLUNAS; j++)
            modificaElemento(mat3, i, j,i+(5*j));


    // inicializa uma lista
    Lista* lista1;
    lista1 = inicializaLista();

    //insere a matriz na lista criada
    insereLista(lista1, mat1);
    insereLista(lista1, mat2);
    insereLista(lista1, mat3);
    

    // inicializa outra lista
    Lista* lista2;
    lista2 = inicializaLista();

    //chamando a função do TAD para gerar a matriz transposta
    Matriz* trp1 = transposta(mat1);
    Matriz* trp2 = transposta(mat2);
    Matriz* trp3 = transposta(mat3);

    // insere as transpostas na lista 2
    insereLista(lista2, trp1);
    insereLista(lista2, trp2);
    insereLista(lista2, trp3);
    

    // mostra as duas listas
    printf("Lista 1 das matrizes normais:\n");
    imprimeLista(lista1);

    printf("Lista 2 das matrizes transpostas:\n");
    imprimeLista(lista2);


    // remove as primeiras matrizes e depois as insere novamente nas listas
    printf("---------------------------------------------------------\n");
    printf("Removendo a primeira matriz de cada lista:\n\n");
    removeLista(lista1, 0);
    printf("Lista1:\n");
    imprimeLista(lista1);

    removeLista(lista2, 0);
    printf("Lista2:\n");
    imprimeLista(lista2);

    printf("\nInserindo as matrizes novamente na lista:\n\n");
    insereLista(lista1, mat3);
    printf("Lista1:\n");
    imprimeLista(lista1);

    insereLista(lista2, trp3);
    printf("Lista2:\n");
    imprimeLista(lista2);



    // remove as matrizes do meio e depois as insere novamente nas listas
    printf("---------------------------------------------------------\n");
    printf("Removendo a matriz do meio de cada lista:\n\n");
    removeLista(lista1, 1);
    printf("Lista1:\n");
    imprimeLista(lista1);

    removeLista(lista2, 1);
    printf("Lista2:\n");
    imprimeLista(lista2);

    printf("\nInserindo as matrizes novamente na lista:\n\n");
    insereLista(lista1, mat2);
    printf("Lista1:\n");
    imprimeLista(lista1);

    insereLista(lista2, trp2);
    printf("Lista2:\n");
    imprimeLista(lista2);



    // remove as ultimas matrizes e depois as insere novamente nas listas
    printf("---------------------------------------------------------\n");
    printf("Removendo a ultima matriz de cada lista:\n\n");
    removeLista(lista1, 2);
    printf("Lista1:\n");
    imprimeLista(lista1);

    removeLista(lista2, 2);
    printf("Lista2:\n");
    imprimeLista(lista2);

    printf("\nInserindo as matrizes novamente na lista:\n\n");
    insereLista(lista1, mat1);
    printf("Lista1:\n");
    imprimeLista(lista1);

    insereLista(lista2, trp1);
    printf("Lista2:\n");
    imprimeLista(lista2);

    
    // libera as listas
    printf("Liberando as listas...\n");
    destroiLista(lista1);
    destroiLista(lista2);
    
    //libera as matrizes
    printf("Liberando as matrizes...\n");
    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);
    destroiMatriz(trp1);
    destroiMatriz(trp2);
    destroiMatriz(trp3);

    printf("\nTudo liberado!\n");
}