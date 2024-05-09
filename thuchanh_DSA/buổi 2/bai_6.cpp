#include <bits/stdc++.h>
using namespace std;
void nhapMang(int a[], int &n)
{
    cout << "nhap n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int linearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int a[100], n;
    nhapMang(a, n);
    int result = linearSearch(a, n, 5);
    if (result != -1)
    {
        cout << "da tim ra o vi tri " << result << endl;
    }
    else
    {
        cout << "khong tim thay" << endl;
    }
}