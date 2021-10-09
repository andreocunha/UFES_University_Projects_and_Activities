#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;
const long long int INF = (long long int)1 << 60;

#define MAX 100000
vector<pair<int, int>> a[MAX + 5];

struct Node
{
    int pos;
    int value;
    Node(){};
    Node(int pos, int value)
    {
        this->pos = pos;
        this->value = value;
    }
    friend bool operator<(Node a, Node b)
    {
        return a.value > b.value;
    }
};
priority_queue<Node> q;
int vis[MAX + 5];
long long int d[MAX + 5];
int pre[MAX + 5];
int n, m;



void Dijstra()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    pre[1] = -1;
    d[1] = 0;
    q.push(Node(1, 0));
    while (!q.empty())
    {
        Node term = q.top();
        q.pop();
        if (vis[term.pos])
            continue;
        vis[term.pos] = 1;

        for (int i = 0; i < a[term.pos].size(); i++)
        {
            int v = a[term.pos][i].first;
            int w = a[term.pos][i].second;
            if (!vis[v] && d[term.pos] + w < d[v])
            {
                d[v] = d[term.pos] + w;
                pre[v] = term.pos;
                q.push(Node(v, d[v]));
            }
        }
    }
}

void print(int x)
{
    if (x == -1)
        return;
    print(pre[x]);
    if (x == n)
        cout << x << endl;
    else
        cout << x << " ";
}

int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        a[i].clear();
    int x, y, z;

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, z));
    }
    Dijstra();
    if (d[n] == INF)
        printf("-1\n");
    else
        print(n);
    return 0;
}