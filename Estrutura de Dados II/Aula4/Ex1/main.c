#include <stdio.h>
#include "bst.h"

int main(int argc, char const *argv[])
{
    Arv *arvore = bst_cria();

    arvore = bst_insere(arvore, 2);
    arvore = bst_insere(arvore, 1);
    arvore = bst_insere(arvore, 3);
    arvore = bst_insere(arvore, 4);
    arvore = bst_insere(arvore, 5);
    

    bst_imprime(arvore);

    arvore = bst_libera(arvore);

    return 0;
}
