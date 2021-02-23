#include <stdio.h>
#include <string.h>
#include "pilha.h"

int
main()
{
    Pilha* operando = inicializaPilha();
    Pilha* operador = inicializaPilha();

    char expressao[] = "( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )";

    float result = calculaExpressao(operando, operador, expressao);

    printf("O resultado eh %.2f\n", result);

    destroi(operando);
    destroi(operador);
    return 0;
}