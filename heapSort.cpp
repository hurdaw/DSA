#include <bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i){
    int largest = i; // thiết lập node gốc
    int l=2*i+1;    // node con trái là 2*i + 1
    int r=2*i+2;    // node con phải là 2*i + 2
    if(l<n&&a[l]>a[largest]) // nếu node con trái lớn hơn gốc
        largest=l;
    if(r<n&&a[r]>a[largest]) // nếu node con phải lớn hơn gốc
        largest=r;         
    if(largest!=i){ // nếu node lơn nhất không phải là gốc
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n){
    for(int i=n/2-l;i>=0;i--){ // sắp đặt lại mảng thành heap
        heapify(a, n, i);
    }
    for(int i=n-l;i>=0;i--){ // trích rút từng phần tử
        swap(a[0], a[i]); // luôn đổi chỗ cho phần tử đầu tiên
        heapify(a, i, 0); // xây dựng heap đến phần tử cuối cùng 
    }
}
void printArray(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<setw(3);
    }
}
int main(){
    int a[]={12, 11, 13, 5, 6, 7};
    int n = sizeof(a)/sizeof(a[0]);
    heapSort(a, n);
    printArray(a, n);
}