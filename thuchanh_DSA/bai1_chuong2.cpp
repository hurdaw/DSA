#include <iostream>
#include <fstream>
using namespace std;

bool check = false;
void gen(int b[], int n)
{
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
bool checkSum(int a[], int b[], int n, int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            sum += a[i];
        }
    }
    return sum == k;
}
int main()
{
    fstream fileIn, fileOut;
    fileIn.open("Input21.txt", ios_base::in);
    fileOut.open("Output21.txt", ios_base::out);
    // n là số phần tử trong mảng a[], k là tổng
    int n, k, a[100], b[100] = {0}, cnt = 0;
    fileIn >> n >> k;
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
    }
    while (!check)
    {
        if (checkSum(a, b, n, k))
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
    fileOut << cnt;
    fileIn.close();
    fileOut.close();
}