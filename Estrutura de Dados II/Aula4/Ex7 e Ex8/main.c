#include <stdio.h>
#include "bst.h"
#include "fila.h"

int main(int argc, char const *argv[])
{
    Fila* fila = cria_fila();

    Arv *arvore1 = bst_cria();
    Arv *arvore2 = bst_cria();
    Arv *arvore3 = bst_cria();
    Arv *arvore4 = bst_cria();
    Arv *arvore5 = bst_cria();
    Arv *arvore6 = bst_cria();
    Arv *arvore7 = bst_cria();
    Arv *arvore8 = bst_cria();
    Arv *arvore9 = bst_cria();


    arvore1 = bst_inicia(bst_cria(), bst_cria(), 'C');
    arvore2 = bst_inicia(bst_cria(), bst_cria(), 'E');
    arvore3 = bst_inicia(bst_cria(), bst_cria(), 'H');
    arvore4 = bst_inicia(arvore1, arvore2, 'D');
    arvore5 = bst_inicia(arvore3, bst_cria(), 'I');
    arvore6 = bst_inicia(bst_cria(), arvore5, 'G');
    arvore7 = bst_inicia(bst_cria(), bst_cria(), 'A');
    arvore8 = bst_inicia(arvore7, arvore4, 'B');
    arvore9 = bst_inicia(arvore8, arvore6, 'F');

    enqueue(fila, arvore1);
    enqueue(fila, arvore2);
    enqueue(fila, arvore3);
    
    printf("Arvore: ");
    bst_imprime(arvore9);
    printf("\n");

    printf("Fila: ");
    imprime_fila(fila);
    printf("\n");

    printf("Retirando primeiro item da fila: ");
    bst_imprime_no(dequeue(fila));
    printf("\n");

    printf("Fila: ");
    imprime_fila(fila);
    printf("\n");

    printf("\nDestruindo fila...\n\n");
    destroi_fila(fila);
    fila = cria_fila();

    printf("Level order fila: ");
    bst_level_order(arvore9, fila);
    imprime_fila(fila);
    printf("\n");

    
    arvore9 = bst_libera(arvore9);
    destroi_fila(fila);

    return 0;
}
