#include <stdio.h>
#include <limits.h>

int main(){
    int a, b;
    a = INT_MAX;
    b = INT_MAX;

    printf("Soma: %d + %d = %d\n", a, b, a+b);
    printf("Subtracao: %d - 0 = %d\n", b, b-0);
    return 0;
}
