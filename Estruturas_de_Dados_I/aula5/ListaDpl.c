/****************************************************************************
 * Andre Oliveira Cunha
 * 
 * Aula 5
 *
 * Exercicio 5
 *
 * Engenharia de Computacao - UFES
 ***************************************************************************/

#include "ListaDpl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct listadpl {
    Aluno* al;
    ListaDpl* prox;
    ListaDpl* ant;
};

ListaDpl* InicLista () {
    return NULL;
}

//insere no início
ListaDpl* InsereLista (ListaDpl* lista, Aluno* aluno) {
    ListaDpl* nova = (ListaDpl*)malloc(sizeof (ListaDpl));
    nova->al = aluno;
    nova->ant = NULL;
    nova->prox = lista;
    
    if(lista != NULL)
    {
        lista->ant = nova;
    }
    return nova;

}

static ListaDpl* busca (ListaDpl* lista, char* chave) {
    ListaDpl* p;

    //faz a busca
    for (p = lista; p!=NULL; p = p->prox) {
        if (strcmp(RetornaNome (p->al), chave)== 0)
            return p;
    }
    return NULL;
}


ListaDpl* RetiraLista (ListaDpl* lista, char* chave){
    //Retorna o ponteiro para a celula a ser retirada (ou NULL)
    ListaDpl* p = busca(lista, chave);
    
    if (p == NULL)
    /* não achou o elemento: retorna lista inalterada */
        return lista;
    
    /* retira elemento do encadeamento */
    if (lista == p){ /* testa se é o primeiro elemento */
        lista = p->prox;
        lista->ant = NULL;
    } 
    else
        p->ant->prox = p->prox;
    if (p->prox != NULL) /* testa se é o último elemento */
        p->prox->ant = p->ant;
    
    free(p);
    
    return lista;
}
        
void ImprimeLista (ListaDpl* lista){
    ListaDpl* p;
    for (p = lista; p != NULL; p = p->prox){
        ImprimeAluno(p->al);
    }
    printf("\n");
}

void DestroiLista (ListaDpl* lista) {
    ListaDpl* p = lista;
    ListaDpl* t;
    
    while (p != NULL) {
        t = p->prox;
        // DestroiAluno(p->al);
        free (p);
        p = t;
    }
}