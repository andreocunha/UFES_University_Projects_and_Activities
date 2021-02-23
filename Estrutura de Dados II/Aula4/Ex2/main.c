#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char const *argv[])
{
    Arv *arvore = bst_cria();

    srand(time(NULL)); // should only be called once
    
    int qtd = 0;

    printf("Quantidade de chaves a serem geradas: ");
    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++)
    {
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        arvore = bst_insere(arvore, r);
    }

    int alt = altura(arvore);

    printf("A altura da arvore eh: %d\n", alt);
    

    // bst_imprime(arvore);

    arvore = bst_libera(arvore);

    return 0;
}
