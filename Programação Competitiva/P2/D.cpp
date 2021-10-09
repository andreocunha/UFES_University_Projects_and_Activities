#include <stdio.h>

int bin_search(int arr[], int left, int right, int worm, int tam)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;
        //printf("%d %d %d %d\n", arr[mid], arr[mid+1], worm, mid);
        if(mid+1 < tam) {
            if (arr[mid] < worm && arr[mid+1] >= worm) {
                return mid;
            }
        }
        else {
            return mid; //ultimo do vetor
        }
  
        if (arr[mid] > worm)
            return bin_search(arr, left, mid - 1, worm, tam);
        
        if (arr[mid] < worm)
            return bin_search(arr, mid + 1, right, worm, tam);
        
        else
            return mid-1;
    }
    return -1;
}

int main() {

    int n;
    scanf("%d", &n);
    int tam_montes[n];
    int som = 0, num;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        tam_montes[i] = som;
        som += num;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m;i++) {
        int worm;
        scanf("%d", &worm);
        // for(int j = n-1; j >= 0; j--) {
        //     if(worm > tam_montes[j]) {
        //         printf("%d\n", j+1);
        //         break;
        //     }
        // }
        printf("%d\n", bin_search(tam_montes, 0, n-1, worm, n) + 1);
        //printf("%d\n", count);
    }

    return 0;
}