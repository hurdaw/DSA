#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *ptr;

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    ptr = str + strlen(str) - 2; // -2 để bỏ qua kí tự newline và null terminator

    printf("Chuoi theo thu tu nguoc lai: ");
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;
    }
    printf("\n");

    return 0;
}