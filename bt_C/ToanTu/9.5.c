#include <stdio.h>

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Truoc khi hoan doi: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("Sau khi hoan doi: a = %d, b = %d\n", a, b);

    return 0;
}           