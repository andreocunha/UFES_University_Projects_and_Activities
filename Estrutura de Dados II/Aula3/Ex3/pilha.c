#include "pilha.h"
#define TAM 200

struct pilha
{
    char* valor[TAM];
    int topo;
};

Pilha *inicializaPilha(void)
{
    Pilha* nova = (Pilha *)malloc(sizeof(Pilha));
    nova->topo = 0;
    return nova;
}

static int ehOperador(char valor)
{
    if(valor == '+' || valor == '-' || valor == '*' || valor == '/'){
        return 1;
    }
    return 0;
}

static void fazOperacao(Pilha* operando, Pilha* operador)
{
    char* operando1 = popPilha(operando);
    char* operando2 = popPilha(operando);
    char* valorOperador = popPilha(operador);
    double res = 0.0;
    char resultado[20];

    if (valorOperador[0] == '+')
    {
        res = atof(operando2) + atof(operando1);
        sprintf(resultado, "%.2f", res); 
        pushPilha(operando, resultado);
    }
    else if (valorOperador[0] == '-')
    {
        res = atof(operando2) - atof(operando1);
        sprintf(resultado, "%.2f", res); 
        pushPilha(operando, resultado);
    }
    else if (valorOperador[0] == '*')
    {
        res = atof(operando2) * atof(operando1);
        sprintf(resultado, "%.2f", res); 
        pushPilha(operando, resultado);
    }
    else if (valorOperador[0] == '/')
    {
        res = atof(operando2) / atof(operando1);
        sprintf(resultado, "%.2f", res); 
        pushPilha(operando, resultado);
    }

    free(operando1);
    free(operando2);
    free(valorOperador);
}

float calculaExpressao(Pilha* operando, Pilha* operador, char* expressao)
{
    int tamanho = strlen(expressao);

    for(int i = 0; i < tamanho; i++)
    {
        if(expressao[i] == '(' || expressao[i] == ' ')
        {
        }
        else if(expressao[i] == ')')
        {
            fazOperacao(operando, operador);
        }
        else if(ehOperador(expressao[i])){
            char op[2] = "\0\0";
            op[0] = expressao[i];
            i++;
            pushPilha(operador, op);
        }
        else{
            char val[2] = "\0\0";
            val[0] = expressao[i];
            i++;
            pushPilha(operando, val);
        }
    }

    return atof(operando->valor[0]);
}

void pushPilha(Pilha* pilha, char* valor)
{
    int posicao = pilha->topo;
    pilha->valor[posicao] = strdup(valor);
    pilha->topo++;
}

char* popPilha(Pilha *pilha)
{
    if (!pilha || pilha->topo == 0)
    {
        printf("Pilha vazia!!!\n");
        return "\0\0";
    }
    char* valor = strdup(pilha->valor[pilha->topo - 1]);
    free(pilha->valor[pilha->topo - 1]);
    pilha->topo--;

    return valor;
}

void imprimePilha(Pilha *pilha)
{
    int i;
    if (!pilha)
        return;
    for (i = (pilha->topo - 1); i >= 0; i--)
    {
        printf("%s", pilha->valor[i]);
    }
    printf("\n");
}

void destroi(Pilha *pilha)
{
    if (!pilha)
        return;
    for (int i = (pilha->topo - 1); i >= 0; i--)
    {
        free(pilha->valor[i]);
    }
    free(pilha);
}