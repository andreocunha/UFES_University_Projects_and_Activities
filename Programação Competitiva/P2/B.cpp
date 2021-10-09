#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        //leitura
        int lin, col, price1, price2;
        scanf("%d %d %d %d", &lin, &col, &price1, &price2);
        char theatre[lin][col];
        //scanf("%*c");
        for(int j = 0; j < lin; j++) {
            scanf("%*c");
            for( int k = 0; k < col; k++) {
                scanf("%c", &theatre[j][k]);
            }
        }

        int preco = 0;
        for(int j = 0; j < lin; j++) {
            for( int k = 0; k < col; k++) {
                if(theatre[j][k] == '*' || theatre[j][k] == '-')
                    continue;
                
                if(k+1 < col && theatre[j][k+1] == '.' && price2/2.0 <= price1) {
                    theatre[j][k] = '-';
                    theatre[j][k+1] = '-';
                    preco += price2;
                    k++;
                    continue;
                }

                theatre[j][k] = '-';
                preco += price1;
            }
        }
        printf("%d\n", preco);
    }

    return 0;
}