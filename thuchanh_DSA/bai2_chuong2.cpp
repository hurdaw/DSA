#include <iostream>
#include <fstream>
using namespace std;

bool check = false;
void nextBin(int b[], int m)
{
    int i = m - 1;
    while (i >= 0 && b[i] == 1)
    {
        b[i] = 0;
        i--;
    }
    if (i >= 0)
    {
        b[i] = 1;
    }
    else
    {
        check = true;
    }
}
bool checkSum(int a[], int b[], int m, int k)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == 1)
            sum += a[i];
    }
    return sum == k;
}

int main()
{
    fstream fileIn, fileOut;
    fileIn.open("Input22.txt", ios_base::in);
    fileOut.open("Onput22.txt", ios_base::out);
    int a[100], b[100] = {0}, n, m, k, cnt = 0;
    fileIn >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
    }
    while (!check)
    {
        if (checkSum(a, b, m, k))
        {
            for (int i = 0; i < m; i++)
            {
                if (b[i] == 1)
                    fileOut << a[i] << " ";
            }
            fileOut << endl;
            cnt++;
        }
        nextBin(b, m);
    }
    fileOut << cnt;
    fileIn.close();
    fileOut.close();
}