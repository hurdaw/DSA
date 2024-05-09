#include <stdio.h>
#include <string.h>

struct nhanVien {
    char ten[50];
    int ID;
    float luong;
};

int main() {
    struct nhanVien nv;

    printf("Nhap ten cua nhan vien: ");
    fgets(nv.ten, sizeof(nv.ten), stdin);
    nv.ten[strcspn(nv.ten, "\n")] = '\0'; // Loại bỏ kí tự newline nếu có

    printf("Nhap ID cua nhan vien: ");
    scanf("%d", &nv.ID);

    printf("Nhap luong cua nhan vien: ");
    scanf("%f", &nv.luong);

    printf("Thong tin cua nhan vien:\n");
    printf("Ten: %s\n", nv.ten);
    printf("ID: %d\n", nv.ID);
    printf("Luong: %.2f\n", nv.luong);

    return 0;
}