#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

#define KEY 123

int semid ;
struct sembuf operacao[1] ;
char *path = "nome_de_arquivo_existente" ;

union {
     int val ;
     struct semid_ds *buf ;
     ushort array[4] ; } arg ;

int main()
{
 
    /* criacao de um conjunto de de 4 semaforos */ 
     if (( semid = semget(ftok(path,(key_t)KEY),4,IPC_CREAT|0600))==-1){
          perror("impossivel a criacao do conjunto de semaforos") ;
          return 1;
     }
     printf("\nprocesso1: acabo de criar um conjunto de semaforos:%d\n",semid);

    /* colocando 1 no terceiro semaforo */
     arg.val=1 ;
     if ((semctl(semid,2,SETVAL,arg))==-1){
         perror("Error semctl") ;
         return 1;
         }

    /* demanda de recurso pelo terceiro semaforo */
     printf("processo1: vou demandar um recurso\n") ;
     operacao[0].sem_num = 2 ; /* operacao sobre o terceiro semaforo */
     operacao[0].sem_op = -1 ; /* operacao de decremento */
     operacao[0].sem_flg = SEM_UNDO; /* para desfazer as operacoes */
     if ( semop(semid,operacao,1) == -1){
          perror("semop:operacao de decremento nao realizada") ;
          return 1;
     }
     
    /* espera para bloquear o segundo processo */
     printf("processo1: Esperando 10 sec\n") ;
     sleep(10) ; /* espera ... */
     printf("processo1: Acabei minha espera: liberando o recurso\n");
     
    /* liberacao do recurso */
     operacao[0].sem_op = 1 ; /* incremento */
     if ( semop(semid,operacao,1) == -1){
          perror("semop:operacao de incremento nao realizada") ;
          return 1;
     }
     
     printf("morte de processo1\n") ;
     return 0;
}