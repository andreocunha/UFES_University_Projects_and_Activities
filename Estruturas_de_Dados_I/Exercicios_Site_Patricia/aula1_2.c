//Andre Oliveira Cunha - 3 periodo Engenharia de Computacao - UFES
//Programa para trabalhar com implementacao de funcoes e ponteiros

//incluindo as bibliotecas padroes
#include <stdio.h>
#include <stdlib.h>

//definindo globalmente o valor de pi
#define pi 3.14159

//Funcoes que serao usadas
void calc_esfera(float r, float* area, float* volume);
void fatorial (int n, int* f);
int negativos (int n, float*vet);
void inverte (int n, int* vet);


/*
// main da 2.1
int main(){
    float r, area, volume;

    r = 4.0;
    calc_esfera(r, &area, &volume);
    printf("%f\n", area);
    printf("%f\n", volume);

    return 0;
}
*/

/*
//main da 2.2
int main(){
    int n, f;
    n = 5;

    fatorial(n, &f);
    printf("%d\n", f);
    return 0;
}*/

/*
//main da 2.3
int main(){
    int n = 4, qtd=0;
    float* vet;
    vet = (float*)malloc(4*sizeof(float));

    *(vet+0) = 2.0;
    *(vet+1) = -1.0;
    *(vet+2) = -2.0;
    *(vet+3) = 4.0;


    qtd= negativos(n, vet);
    printf("%d\n", qtd);

    return 0;
}*/

//main da 2.4
int main(){
    int n = 4;
    int* vet;
    vet = (int*)malloc(4*sizeof(int));

    *(vet+0) = 1;
    *(vet+1) = 2;
    *(vet+2) = 3;
    *(vet+3) = 4;

    inverte(n, vet);

    for(int i=0; i<n; i++){
        printf("%d\n", *(vet+i));
    }

    free(vet);
    return 0;
}

//funcao para calcular a area da superficie e do volume de uma esfera
void calc_esfera(float r, float* area, float* volume){
    *area = 4*pi*(r*r);
    *volume = (4*pi*(r*r*r))/3;
}

//funcao para calcular o vetorial de um numero
void fatorial (int n, int* f){
    *f = 1;
    while(n != 0){
        *f = *f * n;
        n--;
    }
}

//funcao para retornar a quantidade de numeros negativos de um vetor
int negativos (int n, float*vet){
    int qtd=0;
    for(int i=0; i<n; i++){
        if(*(vet + i)<0){
            qtd++;
        }
    }
    return qtd;
}

//funcao para inverter numeros de um vetor
void inverte (int n, int* vet){
    int* aux;
    aux = (int*)malloc(4*sizeof(int));

    for(int i=0, j=n-1; i<n; i++, j--){
        *(aux + j) = *(vet + i);
    }
    for(int i=0; i<n; i++){
        *(vet + i) = *(aux + i);
    }

    free(aux);
}