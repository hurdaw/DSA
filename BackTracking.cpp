#include <bits/stdc++.h>
using namespace std;
// thuật toán
// Back-track(int i){
// for (int j=<khả năng>, j<=n;j++){
//      if(khả năng j đúng)    {
//          x[i]=<khả năng>;
//          if(i==n)    result();
//          else Back-track(i+1);
//}
//}
//}
#define MAX 100
int x[MAX];
void init(int &n)
{
    cout << "nhap n: ";
    cin >> n;
}
void result(int n) // in ra xau nhi phan
{
    int static cnt = 0;
    cout << "\nket qua " << ++cnt << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << setw(3);
    }
}
void Try(int i, int n)
{
    for (int j = 0; j <= 1; j++) // duyệt khả năng j giành cho xi
    {
        x[i] = j;   // thiết lập thành phần xi là j
        if (i == n) // nếu i là thành phần cuối cùng ta ỉn ra kết quả
            result(n);
        else
            Try(i + 1, n); // unless then Try(i+1)
    }
}
void initToHop(int &n, int &k)
{
    cout << "nhap n: ";
    cin >> n;
    cout << "nhap k: ";
    cin >> k;
}
void resultToHop(int i, int k)
{
    int static cnt = 0;
    cout << "\n ket qua " << ++cnt << ": ";
    for (int i = 1; i <= k; i++)
    {
        cout << x[i] << setw(3);
    }
}
void TryToHop(int i, int n, int k)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
            resultToHop(i, k);
        else
            TryToHop(i + 1, n, k);
    }
}
int main()
{
    int n, k;
    initToHop(n, k);
    x[0] = 0;
    TryToHop(1, n, k);
}