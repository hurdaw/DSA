#include <iostream>
#include <fstream>
using namespace std;
bool check = false;
void gen(int b[], int n)
{
    // 1101
    int i = n - 1;
    while (i >= 0 && b[i] == 1)
    {
        b[i] = 0;
        i--;
    }
    if (i >= 0)
        b[i] = 1;
    else
        check = true;
}
bool checkSum(int a[], int b[], int n, int m, int k)
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            sum += a[i];
            cnt++;
        }
    }
    return (sum == k && cnt == m);
}
// 0 1  2  3  4
// 5 10 15 20 25
//
int main()
{
    fstream fileIn, fileOut;
    fileIn.open("Input22.txt", ios_base::in);
    fileOut.open("Output22.txt", ios_base::out);
    int a[100], b[100] = {0}, n, x, m, cnt = 0;
    fileIn >> n >> m >> x;
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
    }
    while (!check)
    {
        if (checkSum(a, b, n, m, x))
        {
            for (int i = 0; i < n; i++)
            {
                if (b[i] == 1)
                {
                    fileOut << a[i] << " ";
                }
            }
            fileOut << endl;
            cnt++;
        }
        gen(b, n);
    }
    fileOut<<cnt;
    fileIn.close();
    fileOut.close();
}