#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, in[10001] = {0}, a, b;
	vector<int> topo;
	vector<vector<int> > arr(10001);
	priority_queue<int, vector<int>, greater<int> > pq;

	cin >> n >> m;

	while (m--){
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		++in[b];
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!in[i])pq.push(i);
	}

	while (!pq.empty()){
		int temp = pq.top();
		pq.pop();
		topo.push_back(temp);
		for (auto i(arr[temp].begin()); i != arr[temp].end(); ++i){
			if (--in[*i] == 0){
                pq.push(*i);
            }
		}
	}

	if (topo.size() < n){
        cout << "Sandro fails.";
    }
    else{ 
        for (int i = 0; i != topo.size(); ++i){
            if(i){
                putchar(' ');
            }
            cout << topo[i];
        }
    }

	putchar('\n');
	return 0;
}