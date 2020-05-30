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

    //definindo os valores dos inteiros
    n1 = 1;
    n2 = 2;
    n3 = 3;
    n4 = 4;

    //mostra na tela os numeros iniciais dos inteiros
    printf("Numeros iniciais:\n");
    printf("%d\n", n1);
    printf("%d\n", n2);
    printf("%d\n", n3);
    printf("%d\n", n4);

    //chama a funcao para alterar os inteiros, passando o endereco deles
    alteraInteiro(p1);
    alteraInteiro(p2);
    alteraInteiro(p3);
    alteraInteiro(p4);

    //mostra na tela os valores que foram alterados
    printf("Numeros alterados:\n");
    printf("%d\n", n1);
    printf("%d\n", n2);
    printf("%d\n", n3);
    printf("%d\n", n4);


    return 0;
}

void alteraInteiro(int* ptr){
    printf("Digite um novo numero: ");
    scanf("%d", ptr);
}