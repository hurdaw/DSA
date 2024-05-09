#include <stdio.h>

struct distance {
    int feet;
    float inch;
};

void addDistance(struct distance d1, struct distance d2) {
    int feetSum = d1.feet + d2.feet;
    float inchSum = d1.inch + d2.inch;

    if (inchSum >= 12.0) {
        inchSum -= 12.0;
        feetSum++;
    }

    printf("Tong hai khoang cach la: %d feet %.2f inch", feetSum, inchSum);
}

int main() {
    struct distance d1, d2;

    printf("Nhap khoang cach thu nhat (feet inch): ");
    scanf("%d %f", &d1.feet, &d1.inch);

    printf("Nhap khoang cach thu hai (feet inch): ");
    scanf("%d %f", &d2.feet, &d2.inch);

    addDistance(d1, d2);

    return 0;
}