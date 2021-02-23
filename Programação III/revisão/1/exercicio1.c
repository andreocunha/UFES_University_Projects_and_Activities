#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char nomeArquivo[80];
    char ch;
    FILE *arq;

    if(argc == 1){
        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);
    }
    else{
        strcpy(nomeArquivo, argv[1]);
    }

    arq = fopen(nomeArquivo, "r");
    if(arq == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else
    {
        while( (ch=fgetc(arq))!= EOF )
        {
            putchar(ch);
        }
    }
    
    fclose(arq);

    return 0;
}