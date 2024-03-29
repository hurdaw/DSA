#include <iostream>
using namespace std;
void nhapMang(int *&a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
bool incr(int a, int b) { return a > b; }
bool decr(int a, int b) { return a < b; }
void sort(int *a, int n, bool (*compareFunc)(int, int))
{
    int index;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (compareFunc(a[index], a[j]))
                index = j;
        }
        swap(a[index], a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int *a, n;
    nhapMang(a, n);
    sort(a, n, decr);
    cout << endl;
    sort(a, n, incr);
}