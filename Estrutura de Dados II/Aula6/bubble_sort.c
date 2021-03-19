#include "item.h"

void sort(Item* a, int lo, int hi) {

    for (int i = 1; i <= hi; i++) 
    {
        for (int j = 0, k = 1; k <= hi; j++, k++)
        {
            if(a[k] < a[j])
            {
                int temp = a[k];
                a[k] = a[j];
                a[j] = temp;
            }
        }
    }
}