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
void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int maxArr(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];   

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int a[], int n)
{
    int m = maxArr(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
int main()
{
    int a[100], n;
    nhapMang(a, n);
    radixsort(a, n);
    xuatMang(a, n);
}