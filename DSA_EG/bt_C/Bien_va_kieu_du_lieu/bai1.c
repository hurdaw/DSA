#include <stdio.h>

int main()
{
    float chieuDai, chieuRong;
    printf("nhap chieu dai: ");
    scanf("%f", &chieuDai);
    printf("nhap chieu rong: ");
    scanf("%f", &chieuRong);
    printf("\nChu vi cua hinh chu nhat co chieu dai %.1f va chieu rong %.1f la: %.1f", chieuDai, chieuRong, (chieuDai + chieuRong) * 2);
    printf("\nDien tich cua hinh chu nhat co chieu dai %.1f va chieu rong %.1f la: %.1f", chieuDai, chieuRong, chieuDai * chieuRong);
}