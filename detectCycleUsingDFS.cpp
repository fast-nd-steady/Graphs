#include <bits/stdc++.h>
using namespace std;

bool cycle(int node, int parent, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (cycle(it, node, adj, vis))
                return true;
        }
        else if (it != parent)
            return true;
    }
    return false;
}
bool hasCycle(int v, vector<int> adj[])
{
    vector<bool> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (cycle(i, -1, adj, vis))
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
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << hasCycle(n, adj);

    cout << endl;
}