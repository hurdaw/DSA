#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;
void getData(int start[], int end[], bool res[], int &n)
{
    ifstream f("input.txt", ios_base::in);
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> start[i];
        f >> end[i];
        res[i] = false;
    }
    f.close();
}
void sendData(bool res[], int n, int cnt)
{
    ofstream f("output.txt", ios_base::out);
    f << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        if (res[i])
            f << i << " ";
    }
}
void sort(int start[], int end[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (end[i] > end[j])
            {
                swap(end[i], end[j]);
                swap(start[i], end[j]);
            }
        }
    }
}
int partition_greedy(int start[], int end[], int l, int r)
{
    int x = end[r], i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (end[j] <= x)
        {
            i++;
            swap(start[i], start[j]);
            swap(end[i], end[j]);
        }
    }
    swap(start[i + 1], start[r]);
    swap(end[i + 1], end[r]);
    return i + 1;
}
void quickSort_greedy(int start[], int end[], int l, int r)
{
    if (l < r)
    {
        int p = partition_greedy(start, end, l, r);
        quickSort_greedy(start, end, l, p - 1);
        quickSort_greedy(start, end, p + 1, r);
    }
}
void greedyActivityAction(int start[], int end[], bool res[], int n, int &cnt)
{
    getData(start, end, res, n);
    quickSort_greedy(start, end, 1, n);
    int i = 1;
    res[i] = true;
    for (int j = 2; j <= n; j++)
    {
        if (end[i] <= start[j])
        {
            ++cnt;
            i = j;
            res[i] = true;
        }
    }
    sendData(res, n, cnt);
}
typedef struct tanSuat
{
    char kyTu;
    int soLan;
} F;
int search(F x[], int n, char t)
{
    for (int i = 0; i <= n; i++)
    {
        if (x[i].kyTu == t)
        {
            return i;
        }
    }
    return n + 1;
}
int tachKytu(char s[], F x[], int n)
{
    int k = strlen(s);
    for (int i = 0; i < k; i++)
    {
        int p = search(x, n, s[i]);
        if (p <= n)
            x[p].soLan++;
        else
        {
            n = p;
            x[p].kyTu = s[i];
            x[p].soLan = 1;
        }
    }
    return n;
}
void sort_tanXuat(F x[], int n)
{ // sắp xếp giảm dần theo số lần xuất hiện của ký tự
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (x[i].soLan < x[j].soLan)
            {
                swap(x[i], x[j]);
            }
        }
    }
}
void xauKyTu_greedy()
{
    char s[MAX];
    cout << "nhap string: ";
    cin >> s;
    int d;
    cout << "nhap khoang cach: ";
    cin >> d;
    int m = -1, n = strlen(s), chuaXet[MAX];
    F x[255];
    char res[MAX]; // xâu kết quả
    for (int i = 0; i < n; i++)
    {
        chuaXet[i] = true;
    }
    // bước 1: tìm tập ký tự và số lần xuất hiện của mỗi ký tự
    m = tachKytu(s, x, m);
    // bước 2: sắp xếp giảm dần theo số lần xuất hiện
    sort_tanXuat(x, m);
    // lặp
    for (int i = 0; i <= m; i++)
    {
        int k = x[i].soLan; // lấy kí tự có số lần xuất hiện nhiều nhất
        int t = 0;
        while (!chuaXet[t])
            t++;
        for (int q = 0; q < k; q++)
        { // duyệt theo số lần xuất hiện
            if (t + q * d > n)
            {
                cout << "no solution";
                return;
            }
            res[t + q * d] = x[i].kyTu;
            chuaXet[t + q * d] = false;
        }
    }
    res[n] = '\0';
    cout << res;
}
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
    // 35=25=15=5=5
    // 25 15 5
    // 10 7 5 2 1
    // 10 10 10 5
    // 10, 10, 10, 5
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
    int start[MAX], end[MAX], cnt = 1, n, value;
    //cin >> n;
    bool res[MAX];
    THINGS t[n], ans[n];
    greedyActivityAction(start, end, res, n, cnt);
    // xauKyTu_greedy();
    // greedy_things(value, t, ans, n);
}