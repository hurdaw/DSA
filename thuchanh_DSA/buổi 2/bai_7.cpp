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
int binarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (x < a[mid])
            right = mid - 1;
        else if (x > a[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int a[100], n;
    nhapMang(a, n);
    int result = binarySearch(a, n, 10);
    if (result != -1)
    {
        cout << "da tim ra o vi tri " << result << endl;
    }
    else
    {
        cout << "khong tim thay" << endl;
    }
}