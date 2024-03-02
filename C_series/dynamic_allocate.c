#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Dynamic Memory
void nhapMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void hienThi(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: %d\n", i, a[i]);
    }
}
void append(int **a, int *n, int x, int k)
{
    printf("nhap vi tri can chen: %d\n");
    scanf("%d", &k);
    printf("nhap gia tri can chen: %d\n");
    scanf("%d", &x);
    (*n)++;
    *a = (int *)realloc(*a, *n * sizeof(int));
    for (int i = *n - 1; i > k; i--)
    {
        (*a)[i] = (*a)[i - 1];
    }
    (*a)[k] = x;
    printf("ket qua sau khi chen: \n");
    hienThi(*a, *n);
}
void edit(int *a, int y, int k)
{
    printf("nhap vi tri can thay doi: ");
    scanf("%d", &k);
    printf("nhap so can thay doi: ");
    scanf("%d", &y);
    a[k] = y;
}
// 0 1 2 3 4
// 5 2 1 6 7
// 5 2 6 7
void Deleted(int **a, int *n)
{
    int k;
    printf("nhap vi tri can xoa: ");
    scanf("%d", &k);
    for (int i = k; i < *n - 1; i++)
    {
        (*a)[i] = (*a)[i + 1];
    }
    (*n)--;
    *a = (int *)realloc(*a, *n * sizeof(int));
    printf("ket qua sau khi xoa la: \n");
    hienThi(*a, *n);
}
int main()
{
    int *a, n, k, x, y;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    // Allocate memory
    a = (int *)calloc(n, sizeof(int));
    printf("nhap mang: \n");
    nhapMang(a, n);
    printf("hien thi mang: \n");
    hienThi(a, n);
    append(&a, &n, x, k);
    edit(a, y, k);
    printf("ket qua sau khi sua la: \n");
    hienThi(a, n);
    Deleted(&a, &n);
    // free memory
    free(a);
    return 0;
}
