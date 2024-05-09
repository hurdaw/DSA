#include <stdio.h>
// Nhập số phút và chuyển đổi số phút thành đơn vị năm và ngày
int main()
{

    int minutes, days, years;
    scanf("%d", &minutes);
    days = minutes / 1440;
    years = days / 365;
    printf("%d\n", days);
    printf("%d\n", years);
}