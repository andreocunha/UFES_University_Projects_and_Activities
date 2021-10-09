#include <stdio.h>

int findNthValue(int n) {
    int count = 0, atual = 0;
  
    while(1){
        int soma = 0;
        for (int i = atual; i > 0; i /= 10){
            soma += i % 10;
        }

        soma == 10 && count++;
  
        if (count == n){
            return atual;
        }
        atual++;
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);

    printf("%d\n", findNthValue(n));
    return 0;
}