#include <stdio.h>

int main()
{
    float temp;
    printf("nhap nhiet do: ");
    scanf("%f", &temp);
    if (temp < 0)
    {
        printf("thoi tiet lanh cong");
    }
    else if (temp >= 0 && temp < 10)
    {
        printf("thoi tiet rat lanh");
    }
    else if (temp >= 10 && temp < 20)
    {
        printf("thoi tiet lanh");
    }
    else if (temp >= 20 && temp < 30)
    {
        printf("thoi tiet tuyet voi");
    }
    else if (temp >= 30 && temp < 40)
    {
        printf("thoi tiet nong");
    }
    else
    {
        printf("thoi tiet rat nong");
    }
}