// single source shortest path probelm in a weighted graph

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
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    // min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    int src = 0;
    dist[src] = 0;

    pq.push({dist[src], src});

    while (!pq.empty())
    {
        auto prev2 = pq.top();
        pq.pop();

        int curDis = prev2.first;
        int prev = prev2.second;

        for (auto it : adj[prev])
        {
            if (dist[it.first] > curDis + it.second)
            {
                pq.push({curDis + it.second, it.first});
                dist[it.first] = curDis + it.second;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}