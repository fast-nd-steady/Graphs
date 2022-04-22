#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int n, vector<int> adj[])
{
    queue<int> q;
    int indegree[n];
    memset(indegree, 0, sizeof(indegree));
    for (int i = 0; i < n; i++)
    {
        for (auto ele : adj[i])
        {
            indegree[ele]++;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        res.push_back(node);
        q.pop();

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return res;
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
    }
    vector<int> res = topoSort(n, adj);
    for (auto ele : res)
        cout << ele << " ";
}