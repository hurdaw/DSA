#include <stdio.h>

int main()
{
    int guessNumber = 20, n;
    do
    {
        printf("\nnhap n de bang so can doan: ");
        scanf("%d", &n);
        if (n == guessNumber)
            printf("xin chuc mung ban da doan dung");
        else    printf("so can doan la so dac biet doi voi toi");
    } while (n != 20);
}