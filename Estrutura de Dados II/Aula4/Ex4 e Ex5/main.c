#include <stdio.h>
#include "bst.h"
#include "pilha.h"

int main(int argc, char const *argv[])
{
    Arv *arvore = bst_cria();
    Pilha* pilha = inicializaPilha();

    arvore = bst_inicia(bst_inicia(bst_inicia(NULL, NULL, 'A'), bst_inicia(bst_inicia(NULL, NULL, 'C'), bst_inicia(NULL, NULL, 'E'), 'D'), 'B'), bst_inicia(NULL, bst_inicia(bst_inicia(NULL, NULL, 'H'), NULL, 'I'), 'G'), 'F');

    rec_preorder(arvore, pilha);
    resetPilha(pilha);

    in_order(arvore, pilha);
    resetPilha(pilha);
    
    post_order(arvore, pilha);
    resetPilha(pilha);

    arvore = bst_libera(arvore);
    destroiPilha(pilha);

    return 0;
}
