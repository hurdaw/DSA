#include <stdio.h>

int main() {
    int a = 25;
    int *ptr = &a;

    printf("Gia tri cua bien a truoc khi thay doi: %d\n", a);

    *ptr = 100;

    printf("Gia tri cua bien a sau khi thay doi: %d\n", a);

    return 0;
}