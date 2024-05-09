#include <stdio.h>

int main()
{
    float a, b, c, d, tb;
    printf("nhap a: ");
    scanf("%f", &a);
    printf("nhap b: ");
    scanf("%f", &b);
    printf("nhap c: ");
    scanf("%f", &c);
    printf("nhap d: ");
    scanf("%f", &d);
    tb = (a + b + c + d) / 4;
    printf("%f", tb);
}