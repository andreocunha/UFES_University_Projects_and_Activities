/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * Aula 1
 *
 * Exercicio aula1_1
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include <stdio.h>

void modificarValores(int *ptr);

int
main(void)
{
    int num1=0, num2=0, num3=0, num4=0;
    int *ptr1, *ptr2, *ptr3, *ptr4;

    ptr1 = &num1;
    ptr2 = &num2;
    ptr3 = &num3;
    ptr4 = &num4;

    modificarValores(ptr1);
    printf("num1 = %d\n", num1);

    modificarValores(ptr2);
    printf("num2 = %d\n", num2);

    modificarValores(ptr3);
    printf("num3 = %d\n", num3);

    modificarValores(ptr4);
    printf("num4 = %d\n", num4);

    printf("\nValor de todas as variaveis:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    printf("num3 = %d\n", num3);
    printf("num4 = %d\n", num4);

    return 0;
}

void modificarValores(int *ptr)
{
    printf("Digite um valor: ");
    scanf("%d", ptr);
}