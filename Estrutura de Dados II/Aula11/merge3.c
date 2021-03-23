#include "item.h"

void merge(Item *a, Item *aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k]; // Copy array
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    { // Merge
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
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

void merge_sort(Item *a, Item *aux, int lo, int hi) {
    if (hi <= lo) {
        insert_sort(a, lo, hi);
        return;
    }

    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    if (!less(a[mid+1], a[mid])) return;
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi)
{
    int n = hi;
    Item *aux = (Item*)malloc(sizeof(Item) * n);
    merge_sort(a, aux, lo, hi-1);
    free(aux);
}