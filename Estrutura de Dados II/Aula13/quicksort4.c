#include "item.h"
#define CUTOFF 7

int partition(Item *a, int lo, int hi)
{
    int i = lo, j = hi + 1;
    Item v = a[lo];
    while (1)
    {
        while (less(a[++i], v)) // Find item on left to swap.
            if (i == hi)
                break;
        while (less(v, a[--j])) // Find item on right to swap.
            if (j == lo)
                break;
        if (i >= j)
            break; // Check if pointers cross.
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Swap with partitioning item.
    return j;          // Return index of item known to be in place.
}

void shuffle(Item *a, int N)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N - 1; i > 0; i--)
    {
        int j = (unsigned int)(drand48() * (i + 1));
        exch(a[i], a[j]);
    }
}

void insert_sort(Item *a, int lo, int hi){
    for (int i = lo + 1; i <= hi; ++i) {
        int j = i - 1;
        int k = a[i];
        while (j>=lo && less(k, a[j])){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = k;
    }
}

int median_of_3(Item *a, int p, int r)
{
    return (p+r)/2;
}

void quick_sort(Item *a, int lo, int hi)
{
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j - 1);
    quick_sort(a, j + 1, hi);
}

void sort(Item *a, int lo, int hi)
{
    shuffle(a, hi - lo + 1); // Needed for performance guarantee.
    quick_sort(a, lo, hi);
}