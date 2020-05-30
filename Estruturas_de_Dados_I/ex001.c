#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverteString(char* palavra);


int main(){

    char* palavra;

    palavra = (char*)malloc(30*sizeof(char));

    printf("Escreva uma palavra: ");
    scanf("%s", palavra);

    inverteString(palavra);
    printf("A palavra invertida eh: %s\n", palavra);
    free(palavra);

    return 0;
}

void inverteString(char* palavra){
    int qtd=0;
    char* palavraInvertida;

    palavraInvertida = (char*)malloc(30*sizeof(char));

    qtd = strlen(palavra);

    for(int i=0, j=qtd; i<qtd; i++, j--){
        palavraInvertida[i] = palavra[j-1];
    }

    for(int i=0; i<qtd; i++){
        palavra[i] = palavraInvertida[i];
    }
    free(palavraInvertida);
}