#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// input
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
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
void DFS(vector<int> adj[], bool visited[], int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int x : adj[u])
    {
        if (!visited[x])
        {
            DFS(adj, visited, x);
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
}