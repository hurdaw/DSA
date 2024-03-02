#include <bits/stdc++.h>
using namespace std;
#define TRUE 1
#define FALSE 0
#define MAX 100
void nhapMang(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
// binary generation
void next_bin(string s)
{
    int i = s.length();
    while (i >= 0 && s[i] != '0')
    {
        s[i] = '0';
        i--;
    }
    if (i > 0)
    {
        s[i] = '1';
    }
    for (int j = 0; j < s.length(); j++)
    {
        cout << s[j];
    }
}
int main()
{
    int OK = TRUE, a[MAX], t, n;
    string s;
    cin >> t;
    getchar();
    while (t--)
    {
        cin >> s;
        next_bin(s);
    }
}