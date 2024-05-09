#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, d;
    printf("nhap a: ");
    scanf("%d", &a);
    printf("nhap b: ");
    scanf("%d", &b);
    printf("nhap c: ");
    scanf("%d", &c);
    printf("nhap d: ");
    scanf("%d", &d);
    printf("a^2=%.1f\n", pow(a, 2));
    printf("b^2=%.1f\n", pow(b, 2));
    printf("c^2=%.1f\n", pow(c, 2));
    printf("d^2=%.1f\n", pow(d, 2));
}