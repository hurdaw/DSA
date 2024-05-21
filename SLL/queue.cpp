#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// tạo 10000 số nhị phân đầu tiên
void init(vector<string> &res)
{
    queue<string> q;
    q.push("1");
    res.push_back("1");
    while (res.size() < 1000)
    {
        string top = q.front();
        q.pop();
        res.push_back(top + "0");
        res.push_back(top + "1");
        q.push(top + "0");
        q.push(top + "1");
    }
}
//  bội số chỉ chứa số 0 và 9 của một số nguyên
void init_9(vector<ll> &res, ll ans[])
{
    queue<string> q;
    q.push("9");
    res.push_back(9);
    while (1)
    {
        string top = q.front();
        if (top.length() == 10)
            break;
        q.pop();
        res.push_back(stoll(top + "0"));
        res.push_back(stoll(top + "9"));
        q.push(top + "0");
        q.push(top + "9");
    }
    for (int i = 1; i <= 100; i++)
    {
        for (ll x : res)
        {
            if (x % i == 0)
            {
                ans[i] = x;
                break;
            }
        }
    }
}
// số lộc phát
void init_68(vector<string> &res)
{
    queue<string> q;
    q.push("6");
    q.push("8");
    res.push_back("6");
    res.push_back("8");
    while (1)
    {
        string top = q.front();
        if (top.length() == 15)
            break;
        q.pop();
        res.push_back(top + "6");
        res.push_back(top + "8");
        q.push(top + "6");
        q.push(top + "8");
    }
}
int main()
{
    vector<string> res, tmp;
    int n;
    cin >> n;
    init_68(res);
    for (string x : res)
    {
        if (x.length() == n + 1)
            break;
        tmp.push_back(x);
    }
    reverse(tmp.begin(), tmp.end());
    for (string x : tmp)
    {
        cout << x << " ";
    }
}