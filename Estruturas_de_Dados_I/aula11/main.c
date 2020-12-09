#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
#define NPAL 64
#define NTAB 127

int le_palavra(FILE *fp, char *s)
{
    int i = 0;
    int c;
    //pula carac que nao sao letras
    while ((c = fgetc(fp)) != EOF)
    {
        if (isalpha(c))
            break;
    }
    if (c == EOF)
        return 0;
    else
        s[i++] = c;
    while ((i < NPAL - 1) && (c = fgetc(fp)) != EOF && isalpha(c)){
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

int main(int argc, char **argv)
{
    FILE *fp;
    Hash *tab;
    char s[NPAL];
    if (argc != 2)
    {
        printf(" Arquivo nao encontrado!\n");
        return 0;
    }
    fp = fopen(argv[1], "rt");
    if (fp == NULL)
    {
        printf(" Erro na abertura do Arquivo!\n");
        return 0;
    }

    //começando a brincadeira
    tab = inicHash(NTAB);

    while (le_palavra(fp, s))
    {
        Palavra *p = acessa(tab, s);
        //incrementa a ocorrencia da palavra
        atualizaOcorrencias(p);
    }
    //deve-se imprimir a tabela agora
    imprimeHash(tab);

    //agora devemos liberar todo espaço alocado para a hash
    liberaHash(tab);

    fclose(fp);

    return (EXIT_SUCCESS);
}
