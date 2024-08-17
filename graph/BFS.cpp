#include <bits/stdc++.h>
using namespace std;
// input
// 10 11
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9
void inp(vector<int> adj[], int &n, int &m, bool visited[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void BFS(vector<int> adj[], bool visited[], int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main()
{
    int n, m;
    vector<int> adj[100];
    vector<pair<int, int>> edge;
    bool visited[100];
    inp(adj, n, m, visited);
    BFS(adj, visited, 1);
}