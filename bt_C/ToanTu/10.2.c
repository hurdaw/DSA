#include <stdio.h>

struct ngaySinh {
    int ngay;
    int thang;
    int nam;
};

struct nhanVien {
    char ten[50];
    int ID;
    float luong;
    struct ngaySinh sinh;
};

int main() {
    struct nhanVien nv;

    printf("Nhap ten cua nhan vien: ");
    fgets(nv.ten,sizeof(nv.ten),stdin);

    printf("Nhap ID cua nhan vien: ");
    scanf("%d", &nv.ID);

    printf("Nhap ngay sinh (ngay thang nam cach nhau boi dau cach): ");
    scanf("%d %d %d", &nv.sinh.ngay, &nv.sinh.thang, &nv.sinh.nam);

    printf("Nhap luong cua nhan vien: ");
    scanf("%f", &nv.luong);

    printf("Thong tin cua nhan vien:\n");
    printf("Ten: %s\n", nv.ten);
    printf("ID: %d\n", nv.ID);
    printf("Ngay sinh: %d/%d/%d\n", nv.sinh.ngay, nv.sinh.thang, nv.sinh.nam);
    printf("Luong: %.2f\n", nv.luong);

    return 0;
}