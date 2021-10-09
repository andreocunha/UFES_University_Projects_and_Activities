#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool all_have_sweetness(priority_queue<int, vector<int>, greater<int>> p, int sweetness) {
    for(; !p.empty(); p.pop()) {
        int val = p.top();
        if(val < sweetness) return false;
    }
    return true;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    priority_queue<int, vector<int>, greater<int>> fila;

    vector<int> A;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        A.push_back(val);
        fila.push(A[i]);
    }

    int count = 0;
    while(true) {
        if(fila.size() < 2) {
            if(fila.top() < k) {
                printf("-1\n");
                return 0;
            }
            else
                break;
        }
        int min1 = fila.top();
        fila.pop();
        if(min1 >= k) break;
        int min2 = fila.top();
        fila.pop();

        fila.push(min1 + min2 * 2);

        count++;
    }

    printf("%d\n", count);

    return 0;
}