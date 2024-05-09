#include <stdio.h>
// nhập số bất kỳ rồi kiểm tra bit thứ 3 là bit 0 hay bit 1
int main()
{
    int a;
    scanf("%d", &a);
    int b = (a >> 2) & 1;
    if (b)
    {
        printf("bit thu 3 la bit 1");
    }
    else
    {
        printf("bit thu 3 la bit 0");
    }
}