// #include <bits/stdc++.h>
// using namespace std;
// int power(int a, unsigned int n)
// {
//     if (n == 0)
//         return 1;
//     int temp = power(a, n / 2);
//     if (n % 2 == 0)
//         return temp * temp;
//     else
//         return a * temp * temp;
// }
// int main()
// {
//     int x, n;
//     cin >> x >> n;
//     cout << power(x, n);
// }
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        str1.insert(0, len2 - len1, '0');
        return len2;
    }
    else if (len1 > len2)
    {
        str2.insert(0, len1 - len2, '0');
    }
    return len1; // If len1 >= len2
}

string addStrings(string str1, string str2)
{
    string result;

    // Make the lengths of the strings equal
    int length = makeEqualLength(str1, str2);

    int carry = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        int sum = (str1[i] - '0') + (str2[i] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        result.insert(0, 1, sum + '0');
    }

    if (carry)
    {
        result.insert(0, 1, carry + '0');
    }

    return result;
}

string subtractStrings(string str1, string str2)
{
    string result;

    // Make the lengths of the strings equal
    int length = makeEqualLength(str1, str2);

    int borrow = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        int diff = (str1[i] - '0') - (str2[i] - '0') - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result.insert(0, 1, diff + '0');
    }

    // Remove leading zeros
    while (result[0] == '0' && result.size() > 1)
    {
        result.erase(0, 1);
    }

    return result;
}

string multiplySingleDigit(string num1, char digit)
{
    if (digit == '0')
    {
        return "0";
    }

    int carry = 0;
    string result;

    for (int i = num1.size() - 1; i >= 0; i--)
    {
        int product = (num1[i] - '0') * (digit - '0') + carry;
        carry = product / 10;
        product = product % 10;
        result.insert(0, 1, product + '0');
    }

    if (carry)
    {
        result.insert(0, 1, carry + '0');
    }

    return result;
}

string multiplyStrings(string num1, string num2)
{
    int length = makeEqualLength(num1, num2);

    if (length == 1)
    {
        int product = (num1[0] - '0') * (num2[0] - '0');
        return to_string(product);
    }

    int mid = length / 2;

    string x1 = num1.substr(0, mid);
    string x0 = num1.substr(mid);
    string y1 = num2.substr(0, mid);
    string y0 = num2.substr(mid);

    string z2 = multiplyStrings(x1, y1);
    string z0 = multiplyStrings(x0, y0);
    string z1 = multiplyStrings(addStrings(x1, x0), addStrings(y1, y0));
    z1 = subtractStrings(z1, addStrings(z2, z0));

    for (int i = 0; i < 2 * (length - mid); i++)
    {
        z2.append("0");
    }

    for (int i = 0; i < (length - mid); i++)
    {
        z1.append("0");
    }

    string result = addStrings(addStrings(z2, z1), z0);

    return result;
}
// tổng dãy con liên tục dài nhất
// -2, -5, 6, -2, -3, 1, 5, -6
// O(n2)
int max_subArray(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        int s = 0;
        for (int j = i + 1; j <= n; j++)
        {
            s += a[j];
            if (max < s)
                max = s;
        }
    }
    return max;
}
int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    { // Tìm tổng dãy con từ l đến m
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    for (int i = m + 1; i <= h; i++)
    { // //Tìm tổng dãy con từ m+1 đến h
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum; // Trả lại kết quả
}
int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];
    int m = (l + h) / 2; // Tìm điểm ở giữa
    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}
int main()
{
    string num1 = "1234";
    string num2 = "5678";
    int a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(a) / sizeof(a[0]);
    // cout << "The result of " << num1 << " * " << num2 << " is " << multiplyStrings(num1, num2) << endl;
    cout << max_subArray(a, n);
    return 0;
}
