#include <stdio.h>
// Nhập một số bất kỳ từ bàn phím và đặt bit thứ 5 của số đã nhập thành bit 1 và đưa kết quả ra màn hình.
int main()
{
    int a;
    scanf("%d", &a);
    a |= (1 << 4);
    printf("ket qua can tim la: %d", a);
}