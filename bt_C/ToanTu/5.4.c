#include <stdio.h>
#include <stdint.h>
#define salaryPerHour 12
#define OT 18
#define standardHour 40
#define grossTax300 0.15
#define grossTax450 0.2
#define grossTaxGreater450 0.25
int main()
{
    uint8_t hour, timeOT;
    float grossPay, netPay, taxes;
    printf("nhap gio lam viec: ");
    scanf("%d", &hour);
    if (hour <= 40)
    {
        grossPay = salaryPerHour * hour;
    }
    else
    {
        timeOT = hour - standardHour;
        grossPay = (salaryPerHour * standardHour) + (OT * timeOT);
    }
    if (grossPay <= 300)
    {
        taxes = grossPay * grossTax300;
    }
    else if (grossPay > 300 && grossPay <= 450)
    {
        taxes = 300 * grossTax300;
        taxes += (grossPay - 300) * grossTax450;
    }
    else
    {
        taxes = 300 * grossTax300;
        taxes += 150 * grossTax450;
        taxes += (grossPay - 450) * grossTaxGreater450;
    }
    netPay = grossPay - taxes;
    printf("Luong Gross: %.2f\n", grossPay);
    printf("Thue: %.2f\n", taxes);
    printf("luong Net: %.2f\n", netPay);
}