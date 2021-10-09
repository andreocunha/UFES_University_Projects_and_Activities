#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int const N = 1e4 + 1;
int const M = 1e9 + 1;

bool visited[N];
vector<vector<pair<int,int>>>vetor;
priority_queue<pair<int,int>>priority;
int n, m, cost[N];

void Dijkstra(int src) {
    int v, c;
    
    cost[src] = 0;
    priority.push(make_pair(0, src));
    
    while(!priority.empty()) {
        v = priority.top().second;
        c = -priority.top().first;
        priority.pop();
        
        if(visited[v]){
            continue;
        }
        visited[v] = true;
        
        for(int i = 0; i < vetor[v].size(); i++){
            if(vetor[v][i].second + c < cost[vetor[v][i].first]) {
                cost[vetor[v][i].first] = vetor[v][i].second + c;
                priority.push(make_pair(-(vetor[v][i].second + c), vetor[v][i].first));
            }
        }
    }
}

int main() {
    int t;
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        
        vetor.clear();
        vetor.resize(n);
        while(!priority.empty()){
            priority.pop();
        } 
        
        for(int i = 0; i < n; i++){
            cost[i] = M;
        } 
        memset(visited, false, sizeof visited);
        
        int v, u, c;
        
        while(m--) {
            cin >> v >> u >> c;
            v = v -1;
            u = u -1;
            vetor[v].push_back(make_pair(u, c));
        }
        
        cin >> v >> u;
        v = v -1; 
        u = u -1;
        
        Dijkstra(v);
        
        if(cost[u] == M){
            cout << "NO" << endl;
        } 
        else{
            cout << cost[u] << endl;
        }
    }
    return 0;
}
