#include "item.h"

void sort(Item* a, int lo, int hi) {
    int bottom,top, swapped,aux;
    bottom = 0;
    top = hi;
    swapped = 0; 
    while(swapped == 0 && bottom < top)
    {                                   
        swapped = 1; 

        for(int i = bottom; i < top; i = i + 1)
        {
            if(a[i] > a[i + 1])   
            {   
                aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                swapped = 0;
            }
        }
        top = top - 1; 
        for(int i = top; i > bottom; i = i - 1)
        {  if(a[i] < a[i - 1]) 
            {
                aux=a[i];
                a[i]=a[i-1];
                a[i-1]=aux;
                swapped = 0;
            }
        }
        bottom = bottom + 1;  
    }
}