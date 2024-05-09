#include <stdio.h>

int main()
{
    int a;
    printf("nhap a: ");
    scanf("%d", &a);
    if (a % 2 == 0)
    {
        printf("Day la so chan");
    }
    else
    {
        printf("Day la so le");
    }
}