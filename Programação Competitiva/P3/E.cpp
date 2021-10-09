#include<bits/stdc++.h>
#include <vector>
using namespace std;
# define INF 0x3f3f3f3f

vector<int> path;
  
typedef pair<int, int> iPair;
  
class Graph
{
    int V;
    list< pair<int, int> > *adj;
  
public:
    Graph(int V);
  
    void addEdge(int u, int v, long long w);
  
    void shortestPath(int s, vector<int>& parent);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
  
void Graph::addEdge(int u, int v, long long w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void printPath(vector<int>& parent, int j)
{
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
   
    printPath(parent, parent[j]);
   
    printf(" %d", j+1);
}

void Graph::shortestPath(int src, vector<int>& parent)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<int> dist(V, INF);
  
    pq.push(make_pair(0, src));
    path.push_back(src);
    dist[src] = 0;

    for(int i = 0; i < V; i++) {
        parent[i] = -1;
    }
  
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
  
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
  
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
}
  
int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    Graph g(V);
    for(int i = 0; i < E; i++) {
        int a, b;
        long long w;
        scanf("%d%d%I64d", &a, &b, &w);
        g.addEdge(a-1, b-1, w);
    }
    vector<int> parent(V);
    g.shortestPath(0, parent);
    
    if(parent[V-1] == -1) {
        printf("-1\n");
    } else {
        printf("1");
        printPath(parent, V-1);
        printf("\n");
    }
  
    return 0;
}