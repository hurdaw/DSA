#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int UCLN(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int BCNN(int a, int b)
{
    return (a * b) / UCLN(a, b);
}
// số đầu cuối = nhau
bool beginEnd(int n)
{
    int x, y;
    if (n / 10 == 0)
        return true;
    x = n % 10;
    // 12451
    // 1245
    // 124
    // 12
    // 1
    while (n >= 10)
    {
        y = n / 10;
        n /= 10;
    }
    if (y == x)
    {
        return true;
    }
    return false;
}
// mảng đối xứng
bool palindromeArray(int a[], int n)
{
    if (n <= 0)
        return false;
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        if (a[i] != a[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
// phân tích thừa số nguyên tố
bool checkPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void thuaSoNT(int n)
{

    for (int i = 2; i <= sqrt(n); i++)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
        if (cnt > 0)
            cout << i << "(" << cnt << ")"
                 << " ";
    }
    if (n > 0)
        cout << n << "(1)";
}
void checkSum(int a, int b, int c)
{
    if (a + b == c)
        cout << "YES";
    else
        cout << "NO";
}
// số tăng giảm
bool tang(int n)
{
    // 1234
    // x=4, y=3
    while (n >= 10)
    {
        int x = n % 10;
        if (x < (n / 10) % 10)
            return false;
        n /= 10;
    }
    return true;
}
void chuanHoa1(char c[])
{
    // nGUYEn quaNG vInH
    char *str = strtok(c, " ");
    while (str)
    {
        printf("%s\n", str);
        str = strtok(NULL, " ");
    }
}
int main()
{
    int t, x, y, z, a[100], n;
    char str[100];
    cin >> t;
    while (t--)
    {
        scanf("%s", str);
        chuanHoa1(str);
    }
}