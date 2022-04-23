/// warning: incomplete code!

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int dist[n];

    queue<pair<int, int>> q;
    int src = 0;
    dist[src] = 0;
    q.push({src, 0});
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        int dest = node.first;
        int wt = node.second;

        for (auto it : adj[dest])
        {
            q.push({it.first, it.second});
            if (dist[dest] + dist[it.second] < dist[it.first])
                dist[it.first] = dist[dest] + dist[it.second];
        }
    }
}