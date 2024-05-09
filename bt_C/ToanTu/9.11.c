#include <stdio.h>

int add(int *ptr1, int *ptr2) {
    return (*ptr1 + *ptr2);
}

int main() {
    int num1 = 20, num2 = 30;
    int sum;

    sum = add(&num1, &num2);

    printf("Tong cua hai so la: %d\n", sum);

    return 0;
}