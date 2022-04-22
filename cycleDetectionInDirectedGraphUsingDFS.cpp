#include <bits/stdc++.h>
using namespace std;
bool hasCycle(int node, bool vis[], bool dfsvis[], vector<int> adj[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == false)
        {
            if (hasCycle(it, vis, dfsvis, adj) == true)
                return true;
        }
        else if (dfsvis[it] == true)
            return true;
    }
    dfsvis[node] = 0;
    return false;
}
bool isCyclic(int v, vector<int> adj[])
{
    bool vis[v], dfsvis[v];
    memset(vis, 0, sizeof(vis));
    memset(dfsvis, 0, sizeof(dfsvis));
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == false)
        {
            if (hasCycle(i, vis, dfsvis, adj))
                return true;
        }
    }
    return false;
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
    }
    cout << isCyclic(n, adj);
}