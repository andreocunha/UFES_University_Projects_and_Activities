/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * Aula 1
 *
 * Exercicio aula1_2
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/


#include <stdio.h>
#include <math.h>

void calc_esfera(float r, float* area, float* volume);
int raizes(float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double* poli, int grau, double x);

/*
// Main da 2.1

int
main(void)
{
    float raio, area, volume;

    printf("Valor do raio: ");
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);

    printf("Area = %.2f\n", area);
    printf("Volume = %.2f\n", volume);

    return 0;
}
*/

/*
// Main da 2.2
int
main(void)
{
    float a=1, b=10, c=4, x1=0, x2=0;
    int qtd=0;

    qtd = raizes(a, b, c, &x1, &x2);

    printf("Quantidade de raizes: %d\n", qtd);
    if(qtd == 1)
    {
        printf("Raiz: %.2f\n", x1);
    }
    else if(qtd == 2)
    {
        printf("Raiz 1: %.2f\n", x1);
        printf("Raiz 2: %.2f\n", x2);
    }
    return 0;
}
*/

/*
// Main da 2.3
int
main(void)
{
    int tam = 4;
    int vet[tam];

    for (int i = 0; i < tam; i++)
    {
        printf("Valor %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    

    printf("Quantidade de numeros pares: %d\n", pares(tam, vet));
    return 0;
}
*/


/*
// Main da 2.4

int
main(void)
{
    int n = 4;
    int vet[n];

    for (int i = 0; i < n; i++)
    {
        printf("Valor %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    
    inverte(n, vet);

    printf("Vetor invertido:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vet[i]);
    }
    return 0;
}
*/

/*
// Main da 2.5
int
main(void)
{
    int grau = 2;
    double poli[grau+1], x = 7;

    for (int i = 0; i <= grau; i++)
    {
        printf("Coeficiente de expoente %d: ", i);
        scanf("%lf", &poli[i]);
    }

    printf("O polinomio eh avaliado em: %.2lf\n", avalia(poli, grau, x));

    return 0;
}
*/

void calc_esfera(float r, float* area, float* volume)
{
    *area = 4 * 3.14 * r*r;
    *volume = (4 * 3.14 * r*r*r)/3;
}

int raizes(float a, float b, float c, float* x1, float* x2)
{
    float delta;

    delta = b*b - 4*a*c;
    if(delta < 0)
    {
        return 0;
    }

    *x1 = (-b + sqrt(delta))/(2*a);
    *x2 = (-b - sqrt(delta))/(2*a);

    if(*x1 == *x2){
        return 1;
    }
    else
    {
        return 2;
    }
}

int pares (int n, int* vet)
{
    int qtdPar = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(vet + i) % 2 == 0)
        {
            qtdPar++;
        }
    }
    return qtdPar;
}

void inverte (int n, int* vet)
{
    int aux[n];

    for (int i = 0, j = n-1; i < n; i++, j--)
    {
        aux[i] = vet[j];
    }

    for(int i = 0; i < n; i++)
    {
        vet[i] = aux[i];
    }
}

double avalia (double* poli, int grau, double x)
{
    double result = 0;

    for (int i = 0; i <= grau; i++)
    {
        result += poli[i] * pow(x, i);
    }
    return result;
}