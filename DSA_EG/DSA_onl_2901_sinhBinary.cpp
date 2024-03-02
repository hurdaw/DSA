#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE 0
void digit(int n, int b)
{
    int coSo[MAX], soDu, k = 1;
    while (n != 0)
    {
        soDu = n % 10;
        n /= 10;
        coSo[k++] = soDu;
    }
    for (int j = k - 1; j >= 1; j--)
    {
        cout << coSo[j] << " ";
    }
}
void init_Bin(int x[], int &n)
{
    cout << "\nnhap n= ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
}
void result_Bin(int x[], int n)
{
    static int cnt = 0;
    cout << "\nKet qua " << ++cnt << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
}
void next_bit_string_Bin(int x[], int n, int &OK)
{
    int i = n;
    while (i > 0 && x[i] != 0)
    {
        x[i] = 0;
        i--;
    }
    if (i > 0)
        x[i] = 1;
    else
        OK = FALSE;
}
void init_toHop(int x[], int &n, int &k)
{
    cout << "\n Nhap n=";
    cin >> n;
    cout << "\n Nhap k=";
    cin >> k;
    for (int i = 1; i <= k; i++)
        x[i] = i;
}
void result_toHop(int x[], int k)
{
    static int cnt = 0;
    cout << "\n Ket qua buoc " << ++cnt << ": ";
    for (int i = 1; i <= k; i++)
        cout << x[i] << " ";
}
void next_Combination_toHop(int x[], int n, int k, int &OK)
{
    int i = k;
    while (i > 0 && x[i] == n - k + i)
        i--;
    if (i > 0)
    {
        x[i] = x[i] + 1;
        for (int j = i + 1; j <= k; j++)
            x[j] = x[i] + j - i;
    }
    else
        OK = FALSE;
}
void init_P(int x[], int &n)
{
    cout << "nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
}
void result_P(int x[], int n)
{
    static int cnt = 0;
    cout << "\nKet qua " << ++cnt << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
}
void next_P(int x[], int n, int &OK)
{
    int j = n - 1;
    while (j > 0 && x[j] > x[j + 1])
        j--;
    if (j > 0) // nếu chưa phải hoán vị cuối cùng
    {
        int k = n;
        while (x[j] > x[k])
            k--;
        int t = x[j];
        x[j] = x[k];
        x[k] = t;
        int r = j + 1, s = n;
        while (r <= s)
        {
            t = x[r];
            x[r] = x[s];
            x[s] = t;
            r++;
            s--;
        }
    }
    else
    {
        OK = false;
    }
}
int main()
{
    int OK = TRUE;
    int n, k, x[MAX];
    init_P(x, n);
    while (OK)
    {
        result_P(x, n);
        next_P(x, n, OK);
    }
}