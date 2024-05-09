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
int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}
int main()
{
    int a[100], n;
    nhapMang(a, n);
    shellSort(a, n);
    xuatMang(a, n);
}