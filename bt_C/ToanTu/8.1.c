#include <stdio.h>
// hàm tìm ước chung lớn nhất
int UCLN(int u, int v);
// hàm tính giá trị tuyệt đối
float abs(float x);
// hàm tính căn bậc 2 của 1 số nguyên không âm
float SQRT(float x);
int main()
{
    int a = 10, b = 20;
    float x = 36;
    printf("%d\n", UCLN(a, b));
    printf("%.2f\n", abs(x));
    printf("%.2f\n", SQRT(x));
}
// hàm tìm ước chung lớn nhất
int UCLN(int u, int v)
{
    int temp;
    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }
    return u;
}
// hàm tính giá trị tuyệt đối
float abs(float x)
{
    if (x < 0)
    {
        x = -x;
    }
    return x;
}
// hàm tính căn bậc 2 của 1 số nguyên không âm
float SQRT(float x)
{
    const float epsilon = .000001;
    float guess = 1.0;
    if (x < 0)
    {
        printf("Khong the tinh can bac hai cua so am \n");
        guess = -1.0;
    }
    else
    {
        while (abs(guess * guess - x) >= epsilon)
        {
            guess = (x / guess + guess) / 2.0;
        }
        return guess;
    }
}