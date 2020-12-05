#include <stdio.h>

typedef struct ARVORE {
    char operador;
    float valor;
    struct ARVORE *esquerda;
    struct ARVORE *direita;
} arvore;


float avalia(arvore *a)
{
    float x,y,res;

    // Se os ramos esquerdo e direito forem terminais, então o nodo contém um valor
    // Retornar esse valor
    if (a->esquerda == NULL && a->direita == NULL) {
        return a->valor;
    }
    else {
       

 // Senão, isto é, se os ramos esquerdo e direito não forem terminais, então o nodo contém um operador
        // Retornar recursivamente o resultado da operação requerida pelo nodo

        x = avalia(a->esquerda);
        y = avalia(a->direita);
        switch (a->operador) {
            case '+': res = x + y; break;
            case '-': res = x - y; break;
            case '*': res = x * y; break;
            case '/': res = x / y; break;
        }
        return res;
    }
}

int main()
{
    arvore nodo[9] = {
                        {'+',0,&nodo[1],&nodo[2]},
                        {'*',0,&nodo[3],&nodo[4]},    
                        {' ',5,NULL,NULL},            
                        {'-',0,&nodo[5],&nodo[6]},
                        {'+',0,&nodo[7],&nodo[8]},
                        {' ',6,NULL,NULL},
                        {' ',3,NULL,NULL},
                        {' ',4,NULL,NULL},
                        {' ',1,NULL,NULL}
                     };
    
    float resultado;
    resultado = avalia(&nodo[0]);
    printf("Resultado = %2.0f\n",resultado);
    
    return 0;
}