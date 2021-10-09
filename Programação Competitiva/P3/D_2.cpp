//https://medium.com/@aastharanjan7/topological-sort-kahns-algorithm-4b844d122e60
//a questao basicamente consistiu na aplicacao do algoritimo de kahn

#include <bits/stdc++.h>

using namespace std;

vector<int> arr[100001];
int in[100001];
vector<int> lista;


int kahn_algorithm(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int atual = pq.top();
        lista.push_back(atual);
        pq.pop();
        for (int child : arr[atual])
        {
            in[child]--;
            if (in[child] == 0)
            {
                pq.push(child);
            }
        }
    }
    if(lista.size() != n){
        return 0;
    }
    return lista.size();
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        arr[x].push_back(y); 
        in[y]++;
    }
        

    if (!kahn_algorithm(n)){
        cout << "Sandro fails.";
    }
    else
    {
        for (int node : lista)
            cout << node << " ";
    }

    return 0;
}