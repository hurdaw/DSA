#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE 0
int n, k, X[MAX], OK = TRUE, dem = 0;
void Init(void)
{
    cout << "\n Nhap n=";
    cin >> n;
    cout << "\n Nhap k=";
    cin >> k;
    for (int i = 1; i <= k; i++)
        X[i] = i;
}
void Result(void)
{
    cout << "\n Ket qua buoc " << ++dem << ":";
    for (int i = 1; i <= k; i++)
        cout << X[i] << " ";
}
void Next_Combination(void)
{
    int i = k;
    while (i > 0 && X[i] == n - k + i)
        i--;
    if (i > 0)
    {
        X[i] = X[i] + 1;
        for (int j = i + 1; j <= k; j++)
            X[j] = X[i] + j - i;
    }
    else
        OK = FALSE;
}
int main()
{
    Init(); // Nhap n = 5, k = 3
    while (OK)
    {
        Result();
        Next_Combination();
    }
}