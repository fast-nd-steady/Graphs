#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &s, bool vis[], vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == false)
        {
            dfs(it, s, vis, adj);
        }
    }
    s.push(node);
}
vector<int> topoSort(int n, vector<int> adj[])
{
    stack<int> s;
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i, s, vis, adj);
        }
    }
    vector<int> v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
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
    vector<int> res = topoSort(n, adj);
    for (auto ele : res)
        cout << ele << " ";
}