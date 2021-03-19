#include "item.h"

void sort(Item* a, int lo, int hi) {
    int i = 0, j = 0, temp = 0;

    for (i = 1; i <= hi; i++) 
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) 
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}