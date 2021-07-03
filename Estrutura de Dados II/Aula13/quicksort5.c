#include "item.h"
#define push2(A, B) push(B); push(A)

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

void insert_sort(Item *a, int lo, int hi)
{
    for (int i = lo + 1; i <= hi; ++i)
    {
        int j = i - 1;
        int k = a[i];
        while (j >= lo && less(k, a[j]))
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = k;
    }
}

int median_of_3(Item *a, int p, int r)
{
    return (p + r) / 2;
}

void quick_sort(Item *a, int lo, int hi)
{
    stack_init();
    push2(lo, hi);
    while (!stack_empty())
    {
        lo = pop();
        hi = pop();
        if (hi <= lo)
            continue; // Could add cutoff here.
        int i = partition(a, lo, hi);
        if (i - lo > hi - i)
        {                     // Test the size of sub-arrays.
            push2(lo, i - 1); // Push the larger one.
            push2(i + 1, hi); // Sort the smaller one first.
        }
        else
        {
            push2(i + 1, hi);
            push2(lo, i - 1);
        }
    }
}

void sort(Item *a, int lo, int hi)
{
    shuffle(a, hi - lo + 1); // Needed for performance guarantee.
    quick_sort(a, lo, hi);
}