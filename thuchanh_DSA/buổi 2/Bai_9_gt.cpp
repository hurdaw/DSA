#include <iostream>
using namespace std;

// Hàm để tìm điểm xoay (pivot) trong mảng
int findPivot(int arr[], int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        return low;

    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid - 1;

    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;

    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, mid + 1, high, key);
    return binarySearch(arr, low, mid - 1, key);
}

// Hàm tìm kiếm trong mảng sắp xếp vòng
int search(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 1, n);

    // Nếu không có điểm xoay, dùng tìm kiếm nhị phân thông thường
    if (pivot == -1)
        return binarySearch(arr, 1, n, key);

    // Nếu tìm thấy điểm xoay, có hai trường hợp
    if (arr[pivot] == key)
        return pivot;

    if (arr[1] <= key)
        return binarySearch(arr, 1, pivot - 1, key);

    return binarySearch(arr, pivot + 1, n, key);
}

int main()
{
    int arr[] = {0, 4, 5, 6, 7, 0, 1, 2};     // Mảng bắt đầu từ 1 đến n, phần tử đầu tiên là 0 không dùng
    int n = sizeof(arr) / sizeof(arr[0]) - 1; // Giảm 1 để bỏ qua phần tử đầu tiên
    int key = 6;

    int index = search(arr, n, key);
    if (index != -1)
        cout << "Phan tu " << key << " duoc tim thay tai vi tri: " << index << endl;
    else
        cout << "Phan tu " << key << " khong co trong mang" << endl;

    return 0;
}
