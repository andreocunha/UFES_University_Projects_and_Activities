#include "Arvore.h"
#include "stdlib.h"
#include "string.h"

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

int vaziaArvore(Arvore *arvore)
{
    if (arvore == NULL)
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




Arvore* Parsing(Arvore* arv, char* texto,int* pos){
        //Se o char for ( ele entra nessa função e verifica os casos que podem acontecer
        if(texto[*pos] == '(' ){
            
            //Se logo depois da '(' vier um numero, então é apenas um numero,a função deve apenas andar mais uma posição na string , e a função de tratar numeros ira resolver 
            if(texto[*pos + 1] >= '0' && texto[*pos + 1] <= '9'){
                *pos = *pos + 1;    //a função ira somente andar mais uma posição e ficar no inicio do numero que está dentro da chave
            }            
            
            //se não entrar no primeiro if(é apenas um numero), quer dizer que devemos criar um novo para a esquerda 
            else if(texto[*pos] == '(' ){
                *pos = *pos + 1;    //andamos uma posição na string
                    if(arv->esq== NULL){
                        arv->esq = criaArvore();  //criamos o ponteiro arvore alocado
                    }
                    arv->esq = Parsing(arv->esq,texto,pos);   //chamamos a função recursivamente para criar a arvore para aquele nó
            }
        }
       
        if(texto[*pos] >= '0' && texto[*pos] <= '9'){            
                char* valor = NULL;
            
                valor = strtok(texto+(*pos),")");
                
                // arv->num= atof(valor);
                arv->valor = (char*)malloc(sizeof(char)*50);
                strcpy(arv->valor, valor);

                //contando qual é o tamanho do numero(string salva em valor)
                int numero = 0;
                numero = strlen(valor);
                numero++;

                //avançando de acordo com o tamanho do numero
                *pos = *pos + numero;
            
            return arv;
        }
  
        //se for um operador ira entrar nessa condição e logo depois ira chamar a função de criar para a direita
        if((texto[*pos] == '+' ) || (texto[*pos] == '-') || (texto[*pos] == '/') || (texto[*pos] == '*') ){
            //já guarda  o sinal do operador na letra
            arv->valor = (char*)malloc(sizeof(char)*2);
            if(texto[*pos] == '+'){
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
            
            // arv->valor[0] = texto[*pos];
            *pos = *pos + 1;  //anda uma posição na string
        
            //cria um arv para a direita e aloca                 
            if(arv->dir == NULL){
                arv->dir = criaArvore();
            }

            //chamamos a função recursivamente para criar a arvore para aquele nó 
            arv->dir = Parsing(arv->dir,texto,pos);
        }
        
        //se for um ) , ira andar mais uma posição e depois retornar 
        if(texto[*pos] == ')' ){
            *pos = *pos + 1;
            return arv;
        }
        
    return arv;
}


float calculaEquacao(Arvore *arvore)
{
    float valorEsquerda = 0.0, valorDireita = 0.0;

    if (vaziaArvore(arvore))
    {
        return 0;
    }

    //Se for um número;
    if (vaziaArvore(arvore->esq) && vaziaArvore(arvore->dir))
    {

        return atof(arvore->valor);
    }

    //Calcular à esquerda
    valorEsquerda = calculaEquacao(arvore->esq);

    //Calcular à direita
    valorDireita = calculaEquacao(arvore->dir);

    //Se for operador, calcula;
    if (arvore->valor[0] == '+')
    {
        valorEsquerda = valorEsquerda + valorDireita;
        return valorEsquerda;
    }
    else if (arvore->valor[0] == '-')
    {
        valorEsquerda = valorEsquerda - valorDireita;
        return valorEsquerda;
    }
    else if (arvore->valor[0] == '*')
    {
        valorEsquerda = valorEsquerda * valorDireita;
        return valorEsquerda;
    }
    else if (arvore->valor[0] == '/')
    {
        valorEsquerda = valorEsquerda / valorDireita;
        return valorEsquerda;
    }

    return valorEsquerda;
}