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
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
    {

        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); // tìm vị trí của chốt
        quickSort(arr, l, p - 1);     // trị nửa bên trái
        quickSort(arr, p + 1, h);     // trị nửa bên phải
    }
}
int main()
{
    int a[100], n;
    nhapMang(a, n);
    quickSort(a, 0, n - 1);
    xuatMang(a, n);
}