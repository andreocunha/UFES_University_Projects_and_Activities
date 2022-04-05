#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>


int main()
{
    int pipe1[2], pipe2[2], pipe3[2];

    if (pipe(pipe1) == -1)
    {
        perror("erro ao criar pipe");
        exit(1);
    }

    if (pipe(pipe2) == -1)
    {
        perror("erro ao criar pipe");
        exit(1);
    }

    if (pipe(pipe3) == -1)
    {
        perror("erro ao criar pipe");
        exit(1);
    }

    // Criando o primeiro filho
    int n1 = fork();
  
    // Criando o segundo filho, como o primeiro filho tambem vai executar, sera criado um neto (ou terceiro filho)
    int n2 = fork();

  
    if (n1 > 0 && n2 > 0) { // pai
        close(pipe1[0]); // fecha o lado de leitura
        close(pipe2[0]); // fecha o lado de leitura
        close(pipe3[0]); // fecha o lado de leitura

        int x, y;
        char msg1[150] = "Meu filho, crie e envie para o seu irmão P3 um array de tamanho randômico entre 100 e 200, preenchido completamente com o valor ";
        char msg2[150] = "Meu filho, crie e envie para o seu irmão P3 um array de tamanho randômico entre 100 e 200, preenchido completamente com o valor ";

        // lendo e verificando se o valor de x e y sao validos
        printf("Digite o valor de X (entre 1 - 5): ");
        while(scanf("%d", &x) != 1 || x < 1 || x > 5)
        {
            printf("Valor inválido, digite novamente: ");
            while(getchar() != '\n');
        }
        printf("Digite o valor de Y (entre 6 - 10): ");
        while(scanf("%d", &y) != 1 || y < 6 || y > 10)
        {
            printf("Valor inválido, digite novamente: ");
            while(getchar() != '\n');
        }
        write(pipe1[1], &x, sizeof(x)); // envia o valor de x via pipe1
        write(pipe2[1], &y, sizeof(y)); // envia o valor de y via pipe2

        // convertendo o valor de x para string
        char x_str[2];
        sprintf(x_str, "%d", x);
        // concatenando a mensagem com o valor de x
        strcat(msg1, x_str);
        write(pipe1[1], &msg1, sizeof(msg1)); // envia a mensagem via pipe1

        sleep(1);

        // convertendo o valor de y para string
        char y_str[2];
        sprintf(y_str, "%d", y);
        // concatenando a mensagem com o valor de y
        strcat(msg2, y_str);
        write(pipe2[1], &msg2, sizeof(msg2)); // envia a mensagem via pipe2

        // fecha o lado de escrita de todos os pipes
        close(pipe1[1]);
        close(pipe2[1]);
        close(pipe3[1]);
    }
    else if (n1 == 0 && n2 > 0) // primeiro filho
    {
        int x;
        char msg[150];

        close(pipe1[1]); // fecha o lado de escrita
        close(pipe3[0]); // fecha o lado de leitura
        read(pipe1[0], &x, sizeof(x)); // lê o valor de x via pipe1
        read(pipe1[0], &msg, sizeof(msg)); // lê a mensagem via pipe1

        // Usa o tempo atual como semente para o gerador de numeros aleatorios
        srand(time(0));

        // criar um vetor de tamanho aleatorio entre 100 e 200 e preenche com o valor x (transformado em string)
        int tam = rand() % 100 + 100;
        char vetor[tam];
        char x_str[2];
        sprintf(x_str, "%d", x);
        int i;
        for (i = 0; i < tam - 1; i++)
        {
            vetor[i] = x_str[0];
        }
        vetor[tam - 1] = '\0';
        write(pipe3[1], &vetor, sizeof(vetor)); // enviando o vetor para o terceiro filho
        
        printf("P1: %s\n", msg); // imprime a mensagem recebida do pai pelo pipe1

        // fecha os pipes usados aqui e termina o primeiro filho
        close(pipe1[0]);
        close(pipe3[1]);
    }
    else if (n1 > 0 && n2 == 0) // segundo filho
    {
        int y;
        char msg[150];

        close(pipe2[1]); // fecha o lado de escrita
        close(pipe3[0]); // fecha o lado de leitura
        read(pipe2[0], &y, sizeof(y));
        read(pipe2[0], &msg, sizeof(msg));

        // Usa o tempo atual como semente para o gerador de numeros aleatorios
        srand(time(0));

        // criar um vetor de tamanho aleatorio entre 100 e 200 e preenche com o valor y
        int tam = rand() % 100 + 100;
        char vetor[tam];
        char y_str[2];
        sprintf(y_str, "%d", y);
        int i;
        for (i = 0; i < tam; i++)
        {
            vetor[i] = y_str[0];
        }
        vetor[tam - 1] = '\0';
        write(pipe3[1], &vetor, sizeof(vetor)); // enviando o vetor para o terceiro filho

        printf("P2: %s\n", msg); // imprime a mensagem recebida do pai pelo pipe2

        // fecha os pipes usados aqui e termina o segundo filho
        close(pipe2[0]);
        close(pipe3[1]);
    }
    else { // terceiro filho
        char msg1[200], msg2[200];

        close(pipe3[1]); // fecha o lado de escrita
        read(pipe3[0], &msg1, sizeof(msg1));
        read(pipe3[0], &msg2, sizeof(msg2));

        printf("P3 - P1: %s\n", msg1);
        printf("P3 - P2: %s\n", msg2);

        close(pipe3[0]); // fecha o lado de leitura
    }
    return 0;
}