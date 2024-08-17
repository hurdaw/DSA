// #include <stdio.h>
// #include <string.h>
// #include <conio.h>
// void reverse(char str[], int index, int size)
// {
//     char temp = str[index];
//     str[index] = str[size - index];
//     str[size - index] = temp;
//     if (index == size / 2)
//         return;
//     reverse(str, index + 1, size);
// }
// int main()
// {
//     char X[] = "ABCDEF";
//     int size = strlen(X);
//     reverse(X, 0, size - 1);
//     printf("Ket qua is: %s\n", X);
//     getch();
//     return 0;
// }
// #include <stdio.h>
// #include <conio.h>
// int Tong(int A[], int n)
// {
//     if (n == 1)
//         return (A[0]);
//     else
//         return (A[n - 1] + Tong(A, n - 1));
// }
// int main(void)
// {
//     int A[] = {9, 7, 12, 8, 6, 5};
//     int n = sizeof(A) / sizeof(int);
//     int s = Tong(A, n);
//     printf("\n s = %d", s);
//     getch();
// }
#include <stdio.h>
#include <conio.h>
int convert(int X)
{
    if (X == 0)
        return 0;
    else
        return (X % 2 + 10 * convert(X / 2));
}
int main()
{
    int X, bin;
    printf("Nhap mot so: ");
    scanf("%d", &X);
    bin = convert(X);
    printf("Ket qua %d la %d.\n", X, bin);
    getch();
    return 0;
}