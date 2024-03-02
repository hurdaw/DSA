#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// void pointer
// là con trỏ có thể trỏ đến bất kỳ kiểu dữ liệu nào miễn là trước khi thực hiện thao tác với con trỏ thì cần 
// ép kiểu cho con trỏ đó
void printBytes(void *a, int n)
{
    // int *ptr = (int *)a;
    for (int i = 0; i < n; i++)
    {
        printf("%08x ", *((int *)a+i));
    }
}
int main()
{
    int a[] = {16, 31, 32, 65};
    printBytes(a, 4);
}