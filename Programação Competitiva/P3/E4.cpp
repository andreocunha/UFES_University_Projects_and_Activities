#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int Ni = 100005;
const long long INF = 100000000005;
struct node
{
    int x;
    long long d;
    node() {}
    node(int a, long long b)
    {
        x = a;
        d = b;
    }
    bool operator<(const node &a) const
    {
        if (d == a.d)
            return x < a.x;
        else
            return d > a.d;
    }
};

vector<node> eg[Ni];
long long dis[Ni], n;
int front[Ni];

void Dijkstra(int s)
{
    int i;
    for (i = 0; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    priority_queue<node> q;
    q.push(node(s, dis[s]));
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        for (i = 0; i < eg[x.x].size(); i++)
        {
            node y = eg[x.x][i];
            if (dis[y.x] > x.d + y.d)
            {
                dis[y.x] = x.d + y.d;
                q.push(node(y.x, dis[y.x]));
                front[y.x] = x.x;
            }
        }
    }
}

int main()
{
    int a, b, m, k, i;
    long long d;
    int tmp[Ni];

    scanf("%d%d", &n, &m);
    for (i = 0; i <= n; i++)
    {
        eg[i].clear();
        front[i] = i;
    }
    while (m--)
    {
        scanf("%d%d%I64d", &a, &b, &d);
        eg[a].push_back(node(b, d));
        eg[b].push_back(node(a, d));
    }
    Dijkstra(1);

    i = n;
    k = 0;
    while (i != front[i])
    {
        tmp[k++] = i;
        i = front[i];
    }
    if (i != 1)
        printf("-1\n");
    else
    {
        printf("1 ");
        for (i = k - 1; i >= 1; i--)
            printf("%d ", tmp[i]);
        printf("%d\n", n);
    }
    return 0;
}