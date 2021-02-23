#include <stdio.h>
#include "bst.h"

int main(int argc, char const *argv[])
{
    Arv *arvore = bst_cria();
    // Arv *arvore1 = bst_cria();
    // Arv *arvore2 = bst_cria();
    // Arv *arvore3 = bst_cria();
    // Arv *arvore4 = bst_cria();
    // Arv *arvore5 = bst_cria();
    // Arv *arvore6 = bst_cria();
    // Arv *arvore7 = bst_cria();
    // Arv *arvore8 = bst_cria();
    // Arv *arvore9 = bst_cria();


    // arvore1 = bst_inicia(bst_cria(), bst_cria(), 'C');
    // arvore2 = bst_inicia(bst_cria(), bst_cria(), 'E');
    // arvore3 = bst_inicia(bst_cria(), bst_cria(), 'H');
    // arvore4 = bst_inicia(arvore1, arvore2, 'D');
    // arvore5 = bst_inicia(arvore3, bst_cria(), 'I');
    // arvore6 = bst_inicia(bst_cria(), arvore5, 'G');
    // arvore7 = bst_inicia(bst_cria(), bst_cria(), 'A');
    // arvore8 = bst_inicia(arvore7, arvore4, 'B');
    // arvore9 = bst_inicia(arvore8, arvore6, 'F');
    
    arvore = bst_inicia(bst_inicia(bst_inicia(NULL, NULL, 'A'), bst_inicia(bst_inicia(NULL, NULL, 'C'), bst_inicia(NULL, NULL, 'E'), 'D'), 'B'), bst_inicia(NULL, bst_inicia(bst_inicia(NULL, NULL, 'H'), NULL, 'I'), 'G'), 'F');

    rec_preorder(arvore);
    printf("\n");

    in_order(arvore);
    printf("\n");
    
    post_order(arvore);
    printf("\n");

    arvore = bst_libera(arvore);

    return 0;
}
