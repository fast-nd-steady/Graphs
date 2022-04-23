#include <bits/stdc++.h>
using namespace std;
void bfs(int src, int n, vector<int> adj[])
{
    queue<int> q;
    q.push(src);
    vector<bool> vis(n, 0);
    vis[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            if (vis[it] == false)
            {
                q.push(it);
                vis[it] = true;
            }
        }
    }
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
    bfs(0, n, adj);
}