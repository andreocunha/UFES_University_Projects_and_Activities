#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long int t1=0,t2=0,n=0;

    cin >> t1 >> t2 >> n; 

    unsigned long long int tab[20];
    tab[0] = t1;
    tab[1] = t2;
    
    for(int i=2; i<=n; i++){
        tab[i] = (tab[i-1]*tab[i-1])+ tab[i-2];
    }

    if(n >= 1){
        cout << tab[n-1] << endl;
    }
    else{
        cout << tab[n] << endl;
    }

    return 0;
}