#include <bits/stdc++.h>
using namespace std;
#define MAX 100
void init_bin(int a[], int &n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}
void result_bin(int a[], int n, int &cnt)
{
    cout << "\nxau thu " << ++cnt << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}
void gen_bin(int a[], int n, bool &OK)
{
    int i = n;
    while (i > 0 && a[i])
    {
        a[i] = 0;
        i--;
    }
    if (i > 0)
        a[i] = 1;
    else
        OK = false;
}
string gen(string s)
{
    int n = s.size();
    int i = n;
    for (int i = n - 1; i >= 0; i++)
    {
        if (s[i] == '1')
            s[i] == '0';
    }
    if (i > 0)
        s[i] = '1';
    return s;
}
void init_combination(int a[], int &n, int &k)
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}
void result_combination(int a[], int k, int &cnt)
{
    cout << "\ntap con thu " << ++cnt << ": ";
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
}
void gen_combination(int a[], int n, int k, bool &OK)
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        OK = false;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
void gen_com(int a[], int n, int k)
{
    cin >> n;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        cout << "day la tap cuoi cung";
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
}
void init_P(int a[], int &n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}
void result_P(int a[], int n, int &cnt)
{
    cout << "\nhoan vi thu " << ++cnt << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}
void gen_P(int a[], int n, bool &OK)
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        OK = false;
    }
    else
    {
        int j = n;
        while (a[i] > a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while (l < r)
        {
            swap(a[l++], a[r--]);
        }
    }
}
void gen_Permu(int a[], int n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
    }
    else
    {
        int j = n;
        while (a[i] > a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while (l <= r)
        {
            swap(a[l++], a[r--]);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    int n, a[MAX], cnt = 0, k;
    bool OK = true;

    // init_P(a, n);
    // while (OK)
    // {
    //     result_P(a, n, cnt);
    //     gen_P(a, n, OK);
    // }

    int t;
    cin >> t;
    while (t--)
    {
        gen_Permu(a, n);
    }
}