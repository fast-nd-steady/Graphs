#include <bits/stdc++.h>
using namespace std;
bool checkBFS(int i, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(i);

    color[i] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto ele : adj[cur])
        {
            if (color[ele] == -1)
            {
                q.push(ele);
                color[ele] = 1 - color[cur];
            }
            else if (color[ele] == color[cur])
                return false;
        }
    }
    return true;
}
bool checkBipartite(int v, vector<int> adj[])
{
    int color[v];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!checkBFS(i, adj, color))
                return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << checkBipartite(n, adj);
}