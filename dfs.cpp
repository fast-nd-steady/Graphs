#include <bits/stdc++.h>
using namespace std;
void dfs(int src, int n, vector<int> adj[], vector<bool> &vis)
{
    vis[src] = 1;
    cout << src << " ";
    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            dfs(it, n, adj, vis);
        }
    }
    return;
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
    vector<bool> vis(n, 0);
    int src = 0;
    vis[src] = 1;
    dfs(src, n, adj, vis);
}