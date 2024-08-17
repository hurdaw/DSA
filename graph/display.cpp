#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// 5 9
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 2 5
// 3 4
// 3 5
// 4 5
// chuyển đổi danh sách cạnh sang ma trận kề
void maTranKe(int a[][100], int n, int m)
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
// danh sách cạnh chuyển sang danh sách kề
void danhSachKe(vector<int> adj[], int n, int m)
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
// 5
// 0 1 1 1 0
// 1 0 1 1 1
// 1 1 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0
// chuyển ma trận kề sang danh sách cạnh
void danhSachCanh(int a[][100], vector<pair<int, int>> edge, int n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] && i < j)
            {
                edge.push_back({i, j});
            }
        }
    }
    for (auto x : edge)
    {
        cout << x.first << " " << x.second << endl;
    }
}
// ma trận kề sang danh sách kề
void mtk2DanhSachKe(vector<int> adj[], int a[][100], int n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
                adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
// 5
// 2 3 4
// 1 3 4 5
// 1 2 4 5
// 1 2 3 5
// 2 3 4
// chuyển đổi từ danh sách kề sang ma trận kề
void dsk2Mtk()
{
    int n, a[100][100];
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num)
        {
            a[i][stoi(num)] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
// danh sách kề sang danh sách cạnh
void dsk2Dsc()
{
    int n;
    vector<pair<int, int>> edge;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num)
        {
            if (i < stoi(num))
                edge.push_back({i, stoi(num)});
        }
    }
    for (auto x : edge)
    {
        cout << x.first << " " << x.second << endl;
    }
}
int main()
{
    int m, n, a[100][100], x, y;
    vector<int> adj[100];
    vector<pair<int, int>> edge;
    dsk2Dsc();
}