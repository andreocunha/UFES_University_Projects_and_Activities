#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

const int N = 200000;

int n;

int tree[2 * N];

void build( int arr[])
{
	for (int i=0; i<n; i++)
		tree[n+i] = arr[i];
	
	for (int i = n - 1; i > 0; --i)	
		tree[i] = tree[i<<1] + tree[i<<1 | 1];
}

void updateTreeNode(int p, int value)
{
	tree[p+n] = value;
	p = p+n;
	
	for (int i=p; i > 1; i >>= 1)
		tree[i>>1] = tree[i] + tree[i^1];
}

int query(int l, int r)
{
	int res = 0;
	
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1)
			res += tree[l++];
	
		if (r&1)
			res += tree[--r];
	}
	
	return res;
}

int main()
{
    int caso = 1;
    while (1)
    {
        cin >> n;
        if(n == 0){
            break;
        }
        int a[n] = {};

        caso != 1 ? 
            cout << "\nCase " << caso << ":\n" 
            : 
            cout << "Case " << caso << ":\n";
        
        caso++;
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        build(a);

        while (1)
        {
            string comando = "";
            cin >> comando;

            if(comando.compare("END") == 0){
                break;
            }
            
            int num1 = 0, num2 = 0;

            cin >> num1;
            cin >> num2;

            if(comando == "M"){
                cout << query(num1-1, num2) << endl;
            }
            else if (comando == "S"){
                updateTreeNode(num1-1, num2);
            }
        }
    }
	return 0;
}
