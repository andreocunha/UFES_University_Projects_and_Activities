#include "arv.h"

struct arvore
{
    char *valor;
    Arvore *esq;
    Arvore *dir;
};

Arvore *criaArvore(void)
{
    Arvore *novaArvore = (Arvore *)malloc(sizeof(Arvore));
    novaArvore->esq = NULL;
    novaArvore->dir = NULL;

    return novaArvore;
}

int vaziaArvore(Arvore *arv)
{
    if (arv == NULL)
    {
        return 1;
    }

    return 0;
}

void imprimeArvore(Arvore *arv)
{
    if (!vaziaArvore(arv))
    {
        printf("(");
        imprimeArvore(arv->esq);
        printf("%s", arv->valor);
        imprimeArvore(arv->dir);
        printf(")");
    }
}

Arvore *liberaArvore(Arvore *arv)
{
    if (!vaziaArvore(arv))
    {
        liberaArvore(arv->esq);
        free(arv->valor);
        liberaArvore(arv->dir);
        free(arv);
    }
    return NULL;
}

Arvore *parsing(Arvore *arv, char *texto, int *pos)
{
    if (texto[*pos] == '(')
    {
        // verifica se eh um numero depois do "("
        if (texto[*pos + 1] >= '0' && texto[*pos + 1] <= '9')
        {
            *pos = *pos + 1;
        }

        //caso contrario
        else if (texto[*pos] == '(')
        {
            *pos += 1;

            if (arv->esq == NULL)
            {
                arv->esq = criaArvore(); //cria uma nova arvore na esquerda
            }
            arv->esq = parsing(arv->esq, texto, pos); //chama a função novamente com os novos parametros (para a esquerda)
        }
    }

    // se for um numero
    if (texto[*pos] >= '0' && texto[*pos] <= '9')
    {
        char *valor = NULL;

        valor = strtok(texto + (*pos), ")"); // pega o valor do numero ate o ")"

        arv->valor = (char *)malloc(sizeof(char) * 50);
        strcpy(arv->valor, valor); // copia o valor do numero

        //atualiza a posicao na string da expressao matematica
        *pos += strlen(valor) + 1;

        return arv;
    }

    //se for um operador matematico
    if ((texto[*pos] == '+') || (texto[*pos] == '-') || (texto[*pos] == '/') || (texto[*pos] == '*'))
    {
        //armazena o valor da expressao
        arv->valor = (char *)malloc(sizeof(char) * 2);
        if (texto[*pos] == '+')
        {
            strcpy(arv->valor, "+\0");
        }
        else if (texto[*pos] == '-')
        {
            strcpy(arv->valor, "-\0");
        }
        else if (texto[*pos] == '/')
        {
            strcpy(arv->valor, "/\0");
        }
        else if (texto[*pos] == '*')
        {
            strcpy(arv->valor, "*\0");
        }

        *pos += 1; //atualiza a posição na string

        //cria uma arvore para a direita
        if (arv->dir == NULL)
        {
            arv->dir = criaArvore();
        }

        arv->dir = parsing(arv->dir, texto, pos); //chama a função novamente com os novos parametros (para a direita)
    }

    if (texto[*pos] == ')')
    {
        *pos += 1; //atualiza a posição na string
        return arv; //retorna a arvore
    }

    return arv; // retorna a arvore completa
}

float resultado(Arvore *arv)
{
    float resultEsq = 0.0, resultDir = 0.0;

    if (vaziaArvore(arv))
    {
        return 0;
    }

    //se for um numero
    if (vaziaArvore(arv->esq) && vaziaArvore(arv->dir))
    {
        return atof(arv->valor); //retorna o valor do numero
    }

    //calcula o resulatado a esquerda
    resultEsq = resultado(arv->esq);

    //calcula o resulatado a direita
    resultDir = resultado(arv->dir);

    //faz a soma
    if (arv->valor[0] == '+')
    {
        resultEsq += resultDir;
        return resultEsq;
    }
    //faz a subtracao
    else if (arv->valor[0] == '-')
    {
        resultEsq -= resultDir;
        return resultEsq;
    }
    //faz a multiplicacao
    else if (arv->valor[0] == '*')
    {
        resultEsq *= resultDir;
        return resultEsq;
    }
    //faz a divisao
    else if (arv->valor[0] == '/')
    {
        resultEsq /= resultDir;
        return resultEsq;
    }

    return resultEsq; // retorna o resultado final
}