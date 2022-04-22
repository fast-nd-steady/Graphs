#include <bits/stdc++.h>
using namespace std;
bool func(int node, vector<int> adj[], int color[])
{
    if (color[node] == -1)
        color[node] = 1;
    for (auto it : adj[node])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[node];
            if(!func(it,adj,color))
                return false;
        }
        else if(color[it]==color[node])
            return false;
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
            if (func(i, adj, color) == false)
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
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << checkBipartite(n, adj);
}