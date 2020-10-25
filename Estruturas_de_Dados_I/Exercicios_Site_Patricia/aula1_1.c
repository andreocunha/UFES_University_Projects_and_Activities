//Andre Oliveira Cunha - 3 periodo Engenharia de Computacao - UFES
//Programa para modificar inteiros usando ponteiro

//incluindo as bibliotecas padroes
#include <stdio.h>
#include <stdlib.h>

void alteraInteiro(int* ptr); //Funcao para modificar o valor de um inteiro a partir do endereco da variavel

int main(){
    int n1, n2, n3, n4; //definindo 4 inteiros localmente
    int* p1, *p2, *p3, *p4; //definindo 4 ponteiros de inteiro

    //copiando o endereco dos inteiros nos ponteiros de inteiros
    p1 = &n1;
    p2 = &n2;
    p3 = &n3;
    p4 = &n4;

    //solicita numeros na entrada padrao
    printf("Digite 4 numeros:\n");
    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    printf("N3: ");
    scanf("%d", &n3);

    printf("N4: ");
    scanf("%d", &n4);     

    //mostra na tela os numeros iniciais dos inteiros
    printf("\nNumeros digitados inicialmente:\n");
    printf("N1: %d\n", n1);
    printf("N2: %d\n", n2);
    printf("N3: %d\n", n3);
    printf("N4: %d\n\n", n4);

    //chama a funcao para alterar os inteiros, passando o endereco deles
    alteraInteiro(p1);
    alteraInteiro(p2);
    alteraInteiro(p3);
    alteraInteiro(p4);

    //mostra na tela os valores que foram alterados
    printf("\nNumeros alterados:\n");
    printf("N1: %d\n", n1);
    printf("N2: %d\n", n2);
    printf("N3: %d\n", n3);
    printf("N4: %d\n", n4);

    return 0;
}

void alteraInteiro(int* ptr){
    printf("Digite um novo numero: ");
    scanf("%d", ptr);
}