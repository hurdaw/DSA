#include <stdio.h>

int main()
{
    enum congTy
    {
        Google = 15,
        Facebook = 20,
        Xerok = 5,
        Yahoo,
        Ebay,
        Microsoft
    };
    printf("The value of Google is: %d\n", Google);
}