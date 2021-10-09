#include <stdio.h>

int allDiferentsValue(int q1, int q2, int q3, int q4){
    if (q1 != q2 && q1 != q3 && q1 != q4 && q2 != q3 && q2 != q4 && q3 != q4) {
        return 1;
    } else {
        return 0;
    }
}

int allNumbersIsPositive(int q1, int q2, int q3, int q4){
    if (q1 > 0 && q2 > 0 && q3 > 0 && q4 > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(void){
    int r1, r2, c1, c2, d1, d2;

    scanf("%d %d", &r1, &r2);
    scanf("%d %d", &c1, &c2);
    scanf("%d %d", &d1, &d2);

    /*
        q1 q2
        q3 q4
    */
    for(int i = 1; i <= 9; i++){
        int q1=0, q2=0, q3=0, q4=0;

        q1 = i;
        q2 = r1 - q1;
        q3 = c1 - q1;
        q4 = r2 - q3;

        if((q1+q2 == r1) && (q3+q4 == r2) && (q1+q3 == c1) && (q2+q4 == c2) && (q1+q4 == d1) && (q2+q3 == d2) && allDiferentsValue(q1, q2, q3, q4)){
            if(allNumbersIsPositive(q1, q2, q3, q4)){
                if(q1 < 10 && q2 < 10 && q3 < 10 && q4 < 10){
                    printf("%d %d\n", q1, q2);
                    printf("%d %d\n", q3, q4);
                    return 0;        
                }
            }
        }
    }
    printf("-1\n");

    return 0;
}