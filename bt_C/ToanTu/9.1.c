#include <stdio.h>

int main()
{
    int a = 5;
    float b = 2;
    char c = 3;
    int *p = &a;
    float *p2 = &b;
    char *p3 = &c;
    printf("dia chi cua bien a la: %d\n", p);
    printf("gia tri con tro p la: %d\n", p);
    printf("gia tri cua con tro p tro toi la: %d\n", *p);
    printf("dia chi con tro p la: %d\n", &p);
}