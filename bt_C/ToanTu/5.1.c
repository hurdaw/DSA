#include <stdio.h>

int main(){
    float a, b;
    printf("nhap a: ");
    scanf("%f", &a);
    printf("nhap b: ");
    scanf("%f", &b);
    if(a!=(int)a||b!=(int)b){
        printf("so da nhap khong phai so nguyen");
    }else if(a==b){
        printf("so thu nhat bang so thu hai");
    }else if (a<b)
    {
        printf("so thu nhat nho hon so thu hai");
    }else{
        printf("so thu nhat nho hon so thu hai");
    }
    
}