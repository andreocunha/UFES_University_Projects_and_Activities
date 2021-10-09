#include <bits/stdc++.h>
using namespace std;

int n,m,i,j,k,fa[1000001],t,qwq,b[1000001];

int main(){
    scanf("%d", &n);

    for(i=2;i<=n;i++){
        scanf("%d", &fa[i]);
    }
    j=0;
    qwq=n;
    fa[1]=0;
    while(fa[qwq]!=0){
        j++;
        b[j]=qwq;
        qwq=fa[qwq];
    }
    cout << 1 << " ";
    for(i=j;i>=1;i--){
        cout << b[i] << " ";
    }
    return 0;
}