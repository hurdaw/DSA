#include <stdio.h>

int main()
{
    enum congTy
    {
        GOOGLE = 10,
        FACEBOOK,
        XEROX = 22,
        YAHOO,
        EBAY,
        MICROSOFT
    };
    printf("The value of Google is: %d\n", GOOGLE);
    printf("The value of Facebook is: %d\n", FACEBOOK);
    printf("The value of Xerok is: %d\n", XEROX);
    printf("The value of Yahoo is: %d\n", YAHOO);
    printf("The value of Ebay is: %d\n", EBAY);
    printf("The value of Microsoft is: %d\n", MICROSOFT);
}