#include <bits/stdc++.h>
using namespace std;
int linearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int a[] = {9, 7, 12, 8, 6, 5}, x = 13;
    int result = linearSearch(a, 5, x);
    if (result != -1)
    {
        cout << "da tim thay x o vi tri: " << result;
    }
    else
    {
        cout << "khong tim thay x";
    }
}