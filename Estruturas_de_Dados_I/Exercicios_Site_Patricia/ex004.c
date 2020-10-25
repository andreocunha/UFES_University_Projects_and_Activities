//Andre Oliveira Cunha - 3 periodo Engenharia de Computacao - UFES
//Programa para armazenar numeros em um vetor e o endereco em um vetor de ponteiros, ordenando em ordem crescente os valores armazenados

//incluindo as bibliotecas padroes
#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[10]; //vetor para armazenar 10 inteiros
    int* ptr; //um ponteiro de inteiro

    ptr = (int*)malloc(10 * sizeof(int)); //alocando o ponteiro para um espaco de 10 inteiros

    //loop para ler 10 inteiros
    for(int i=0; i<9; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &vet[i]);
    }

    //loop para ordernar de forma crescente os numeros em vet nos espacos do ponteiro alocado
    int aux=0;
    for (int i = 0; i < 9; i++){
        for(int j=i+1; j<9; j++){
            if(vet[i]>vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    for(int i=0; i<9; i++){
        ptr[i] = vet[i];
    }
    
    for(int i = 0; i<9; i++){
        printf("%d\n", *(ptr+i));
    }
    
    return 0;
}