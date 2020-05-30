//Andre Oliveira Cunha - 3 periodo Engenharia de Computacao - UFES
//Programa para armazenar numeros em matriz com ponteiros

//incluindo as bibliotecas padroes
#include <stdio.h>
#include <stdlib.h>

int main(){
    int* matriz; //ponteiro de inteiro para armazenar numeros

    matriz = (int*)malloc(10 * sizeof(int)); //alocando espaco para o ponteiro para armazenar 10 numeros inteiros

    //loop para ler numero por numero e armazenar eles
    for(int i=0; i<9; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &matriz[i]);
    }

    printf("\n\n");
    printf("Os numeros armazenados foram:\n");

    //loop para imprimir os numeros armazenados
    for(int i=0; i<9; i++){
        printf("Numero %d: %d\n", i+1, *(matriz+i));
        //printf("Numero %d: %d\n", i+1, matriz[i]); //Eh uma outra maneira de mostrar os valores armazenados
    }

    free(matriz); //liberando o espaco alocado para a matriz de inteiros
    return 0;
}