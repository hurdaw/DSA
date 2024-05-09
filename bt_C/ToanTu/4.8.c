#include <stdio.h>

int main(){
    unsigned int ID, soGioLam, tienLuongMoiGio, tienLuongCuaThang;
    printf("ID nhan vien: ");
    scanf("%d", ID);
    printf("Tong so gio lam viec: ");
    scanf("%d", soGioLam);
    printf("Tien luong moi gio: ");
    scanf("%d", tienLuongMoiGio);
    tienLuongCuaThang=soGioLam*tienLuongMoiGio;
    printf("nhan vien %d co tien luong moi thang la: %d", ID, tienLuongCuaThang);
}