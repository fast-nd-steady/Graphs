#include <bits/stdc++.h>
using namespace std;
bool cycle(int node,int parent,vector<int> adj[],vector<bool> &vis)
{
    queue<pair<int,int>> q;
    q.push({node,parent});
    vis[node]=true;
    while(!q.empty())
    {
        int cur=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it:adj[cur])
        {
            if(!vis[it])
            {
                q.push({it,cur});
                vis[it]=true;
            }
            else if(it!=par)
            {
                return true;
            }
        }
    }
    return false;
}
bool hasCycle(int v, vector<int> adj[])
{
    vector<bool> vis(v+1,0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if(cycle(i,-1,adj,vis))
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
}