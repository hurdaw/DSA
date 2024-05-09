#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct hocSinh {
    char hoTen[50];
    int tuoi;
    char diaChi[100];
    float gpa;
};

int main() {
    struct hocSinh danhSachHocSinh[MAX_STUDENTS];
    int soLuongHocSinh = 0;
    int luaChon;

    // Vòng lặp chính
    while (1) {
        // Hiển thị menu lựa chọn
        printf("Hay lua chon:\n");
        printf("1. Nhap thong tin hoc sinh\n");
        printf("2. Tim kiem hoc sinh\n");
        printf("3. Thoat\n");

        // Nhập lựa chọn từ người dùng
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        printf("\n----------------------------\n");

        // Xử lý lựa chọn của người dùng
        switch (luaChon) {
            case 1: // Nhap thong tin hoc sinh
                printf("Nhap thong tin hoc sinh %d:\n", soLuongHocSinh + 1);
                printf("Ho ten: ");
                scanf("%s", danhSachHocSinh[soLuongHocSinh].hoTen);
                printf("Tuoi: ");
                scanf("%d", &danhSachHocSinh[soLuongHocSinh].tuoi);
                printf("Dia chi: ");
                scanf("%s", danhSachHocSinh[soLuongHocSinh].diaChi);
                printf("GPA: ");
                scanf("%f", &danhSachHocSinh[soLuongHocSinh].gpa);
                soLuongHocSinh++;
                break;
            case 2: // Tim kiem hoc sinh
                if (soLuongHocSinh == 0) {
                    printf("Danh sach hoc sinh hien tai trong.\n");
                    break;
                }
                char tenTimKiem[50];
                printf("Nhap ten hoc sinh can tim kiem: ");
                scanf("%s", tenTimKiem);
                for (int i = 0; i < soLuongHocSinh; i++) {
                    if (strcmp(danhSachHocSinh[i].hoTen, tenTimKiem) == 0) {
                        printf("Thong tin hoc sinh:\n");
                        printf("Ho ten: %s\n", danhSachHocSinh[i].hoTen);
                        printf("Tuoi: %d\n", danhSachHocSinh[i].tuoi);
                        printf("Dia chi: %s\n", danhSachHocSinh[i].diaChi);
                        printf("GPA: %.2f\n", danhSachHocSinh[i].gpa);
                        break;
                    }
                    if (i == soLuongHocSinh - 1) {
                        printf("Khong tim thay hoc sinh co ten la %s\n", tenTimKiem);
                    }
                }
                break;
            case 3: // Thoat
                printf("Ket thuc chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
        printf("\n----------------------------\n");
    }

    return 0;
}