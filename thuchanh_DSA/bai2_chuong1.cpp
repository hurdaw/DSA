#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
// kiểm tra n có phải k chữ số không
bool hasKDigits(int n, int k)
{
    if (n == 0)
        return k == 1; // Trường hợp n = 0, coi là có 1 chữ số
    int count = 0;
    while (n != 0)
    {
        n /= 10; // Loại bỏ chữ số cuối cùng của n
        count++; // Tăng số lượng chữ số lên 1
    }
    return count == k;
}
// hàm đảo ngược
int reverseNumber(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        int digit = n % 10;               // Lấy chữ số cuối cùng
        reversed = reversed * 10 + digit; // Thêm chữ số vào số đảo ngược
        n /= 10;                          // Loại bỏ chữ số cuối cùng đã xử lý
    }
    return reversed;
}
// kiểm tra đảo ngược các chữ số của N cũng là một số nguyên tố
bool isReversedPrime(int n)
{
    int reversed = reverseNumber(n);
    return isPrime(reversed);
}
// hàm tính tổng các chữ số
int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10; // Thêm chữ số cuối cùng vào tổng
        n /= 10;       // Loại bỏ chữ số cuối cùng
    }
    return sum;
}
// hàm kiểm tra xem tổng các chữ số có phải là số nguyên tố không?
bool isSumOfDigitsPrime(int n)
{
    int sum = sumOfDigits(n);
    return isPrime(sum);
}
// kiểm tra số nguyên tố 1 chữ số
bool isDigitPrime(int digit)
{
    return digit == 2 || digit == 3 || digit == 5 || digit == 7;
}
// kiểm tra các chữ số của n là số nguyên tố
bool areAllDigitsPrime(int n)
{
    if (n == 0)
        return false; // 0 không có chữ số nào là số nguyên tố

    while (n > 0)
    {
        int digit = n % 10; // Lấy chữ số cuối cùng
        if (!isDigitPrime(digit))
        {
            // Nếu có bất kỳ chữ số nào không phải là số nguyên tố
            return false;
        }
        n /= 10; // Loại bỏ chữ số cuối cùng đã xử lý
    }
    return true; // Tất cả chữ số đều là số nguyên tố
}
int countSatisfyingNumbers(int k)
{
    int start = pow(10, k - 1);
    int end = pow(10, k) - 1;
    int count = 0;

    for (int num = start; num <= end; ++num)
    {
        if (isPrime(num) && isReversedPrime(num) && isSumOfDigitsPrime(num) && areAllDigitsPrime(num))
        {
            ++count;
        }
    }
    return count;
}
//
int countSafitified(int n)
{
    int start = pow(10, n - 1);
    int end = pow(10, n) - 1;
    int count = 0;
    for (int i = start; i <= end; ++i)
    {
        if (hasKDigits(i, n) && isPrime(i) && isReversedPrime(i) && isSumOfDigitsPrime(i) && areAllDigitsPrime(i))
            ++count;
    }
    return count;
}
int main()
{
    fstream fileIn, fileOut;
    fileIn.open("Input12.txt", ios_base::in);
    fileOut.open("Output12.txt", ios_base::out);

    int k; // Number of test cases
    fileIn >> k;
    for (int i = 0; i < k; i++)
    {

        int x;
        fileIn >> x;
        int result = countSafitified(x);
        fileOut << x << " " << result << endl;
    }
    fileIn.close();
    fileOut.close();
    return 0;
}
