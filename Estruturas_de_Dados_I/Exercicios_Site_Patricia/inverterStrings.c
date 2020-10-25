//Programa para inverter uma string usando ponteiro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* LeNome(char* nome){
    nome = (char*)malloc(sizeof(char));

    scanf("%s", nome);
    return nome;
}

char* InverteString(char* nome){
    int qtd=0;
    char* nomeInvertido;

    nomeInvertido = (char*)malloc(sizeof(char));

    qtd = strlen(nome);

    for(int i=0, j=qtd; i<qtd; i++, j--){
        nomeInvertido[i] = nome[j-1];
    }
    return nomeInvertido;
}

int main(){
    char* nome;

    printf("Digite um nome: ");
    nome = LeNome(nome);
    printf("\nO nome digitado foi: %s\n", nome);

    nome = InverteString(nome);
    printf("O nome invertido eh: %s\n", nome);

    free(nome);
    
    return 0;
}