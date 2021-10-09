#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;

int n;
string s[N];
int used[27];
//index array saves the corresponding arrangement of the given string.
//Sad,happy,min then index['s'-'h'] = 1
int index[N];
//g[i] represents the character after the character i.
vector<int> g[N];
int cnt = 0;

void bfs()
{
    queue<int> q;
    //Put the characters in normal order.
    for (int i = 0; i < 26; i++)
    {
        if (index[i] == 0)
        {
            q.push(i);
        }
    }
    vector<char> ans;
    while (!q.empty())
    {
        cnt++;
        int top = q.front();
        q.pop();
        ans.push_back('a' + top);
        for (int x : g[top])
        {
            index[x]--;
            if (index[x] == 0)
            {
                q.push(x);
            }
        }
    }
    if (cnt != 26)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        for (char x : ans)
        {
            cout << x;
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int j = 0, k = 0;
        int len1 = s[i].length(), len2 = s[i + 1].length();
        //If the first letter is the same, compare the next one in turn
        while (s[i][j] == s[i + 1][k])
        {
            j++;
            k++;
        }
        if (j == len1)
            continue;
        if (k == len2)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        g[s[i][j] - 'a'].push_back(s[i + 1][k] - 'a');
    }

    for (int i = 0; i < 26; i++)
    {
        for (int x : g[i])
        {
            index[x]++;
        }
    }
    bfs();
    return 0;
}