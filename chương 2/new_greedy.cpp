#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;
typedef struct things
{
    char name[MAX];
    int m; // khối lượng
} THINGS;
void sort_khoiLuong(THINGS t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].m < t[j].m)
            {
                swap(t[i], t[j]);
            }
        }
    }
}
void greedy_things(int value, THINGS t[], THINGS ans[], int n)
{
    cout << "nhap khoi luong gioi han: ";
    cin >> value;
    // nhập dữ liệu các vật
    for (int i = 0; i < n; i++)
    {
        cout << "nhap ten: ";
        cin >> t[i].name;
        cout << "nhap khoi luong: ";
        cin >> t[i].m;
    }
    sort_khoiLuong(t, n);
    // 1 3 5 7 8
    // 35
    for (int i = 0; i < n; i++)
    {
        strcpy(ans[i].name, t[i].name);
        ans[i].m = 0;
    }
    int indexAns = 0;
    for (int i = 0; i < n; i++)
    {
        while (t[i].m <= value)
        {
            value -= t[i].m;
            ans[indexAns].m = t[i].m;
            indexAns++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i].m > 0)
            cout << "thing: " << ans[i].name << " - Khoi luong: " << ans[i].m << endl;
    }
}
int main()
{
    int n, value;
    cout<<"nhap so luong do vat";
    cin >> n;
    THINGS t[n], ans[n];
    greedy_things(value, t, ans, n);
}