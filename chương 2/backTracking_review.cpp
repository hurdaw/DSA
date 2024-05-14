#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#define MAX 100
using namespace std;
int cnt = 0;
void result_bin(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void try_bin(int a[], int n, int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
            result_bin(a, n);
        else
            try_bin(a, n, i + 1);
    }
}
void result_com(int a[], int n, int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void try_com(int a[], int n, int k, int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
            result_com(a, n, k);
        else
            try_com(a, n, k, i + 1);
    }
}
void result_P(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void try_P(int a[], int used[], int n, int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
        {
            used[j] = 1;
            a[i] = j;
            if (i == n)
                result_P(a, n);
            else
                try_P(a, used, n, i + 1);
            used[j] = 0;
        }
    }
}
void init_Queen(int a[], int &n, bool cot[], bool xuoi[], bool nguoc[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cot[i] = true;
    }
    for (int i = 1; i < 2 * n; i++)
    {
        xuoi[i] = true;
        nguoc[i] = true;
    }
}
void result_Queen(int a[], int x[][100], int n)
{
    memset(x, 0, n * 100 * sizeof(x));
    for (int i = 1; i <= n; i++)
    {
        x[i][a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void try_Queen(int a[], int n, bool cot[], bool xuoi[], bool nguoc[], int i, int x[][100])
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] && xuoi[i - j + n] && nguoc[i + j - 1])
        {
            a[i] = j;
            cot[j] = false;
            xuoi[i - j + n] = false;
            nguoc[i + j - 1] = false;
            if (i == n)
                // result_Queen(a, x, n);
                cnt++;
            else
                try_Queen(a, n, cot, xuoi, nguoc, i + 1, x);
            cot[j] = true;
            xuoi[i - j + n] = true;
            nguoc[i + j - 1] = true;
        }
    }
}
int main()
{
    clock_t start, end;
    double cpu_time_used;

    int a[MAX], used[MAX] = {0}, n, k, x[MAX][MAX];
    bool cot[MAX], xuoi[MAX], nguoc[MAX];
    start = clock();

    init_Queen(a, n, cot, xuoi, nguoc);
    try_Queen(a, n, cot, xuoi, nguoc, 1, x);
    cout << cnt << endl;
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Tính thời gian sử dụng CPU
    std::cout << "Function execution took " << cpu_time_used << " seconds." << std::endl;
}