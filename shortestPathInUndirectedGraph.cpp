#include <bits/stdc++.h>
using namespace std;
void func(int src, int dist[], int n, vector<int> adj[])
{
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dist[it] == INT_MAX)
            {
                q.push(it);
                dist[it] = dist[node]+1;
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
    int dist[n];
    int src = 0;
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    func(src, dist, n, adj);

    for (int i = 0; i < n; i++)
        cout << i << " " << dist[i] << endl;
}