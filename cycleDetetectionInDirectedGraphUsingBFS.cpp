#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int n, vector<int> adj[])
{
    queue<int> q;
    int indegree[n];
    memset(indegree, 0, sizeof(indegree));
    for (int i = 0; i < n; i++)
    {
        for (auto ele : adj[i])
            indegree[ele]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int c = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        c++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return c == n;
}
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << isCyclic(n, adj);
}