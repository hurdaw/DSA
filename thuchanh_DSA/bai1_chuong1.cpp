#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

string convertToBase(int n, int base) {
    if (n == 0) return "0";

    string result = "";
    string digits = "0123456789ABCDEF"; // Dùng cho cả decimal và hexadecimal

    while (n > 0) {
        result = digits[n % base] + result;
        n /= base;
    }

    return result;
}
int main() {
    fstream fileIn, fileOut;
    fileIn.open("Input11.txt", ios_base::in);
    fileOut.open("Output11.txt", ios_base::out);

    int k; // Số bộ test
    fileIn >> k;

    for (int i = 0; i < k; i++) {
        int num, base;
        fileIn >> num >> base;

        string result = convertToBase(num, base);

        // Ghi số gốc, cơ số, và biểu diễn sau chuyển đổi vào file Output.txt
        fileOut << num << " " << base << " " << result << endl;
    }

    fileIn.close();
    fileOut.close();
    return 0;
}

