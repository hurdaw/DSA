#include <iostream>
#include <climits>
using namespace std;

class MinHeap {
    int *harr;       // Mảng các node trong heap
    int capacity;    // Kích cỡ tối đa của heap
    int heap_size;   // Kích cỡ hiện tại của heap

public:
    // Constructor của lớp MinHeap
    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    // Hàm tạo heap con với khóa k
    void MinHeapify(int k) {
        int l = left(k);
        int r = right(k);
        int smallest = k;

        if (l < heap_size && harr[l] < harr[smallest])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != k) {
            swap(harr[k], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; } // Lấy vị trí node cha
    int left(int i) { return (2 * i + 1); }   // Lấy vị trí node con trái
    int right(int i) { return (2 * i + 2); }  // Lấy vị trí node con phải

    // Trích xuất phần tử nhỏ nhất (root) từ heap
    int extractMin() {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

    // Giảm giá trị của một key tại vị trí cụ thể
    void decreaseKey(int i, int new_val) {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    // Nhận giá trị nhỏ nhất (root) của heap
    int getMin() { return harr[0]; }

    // Xóa phần tử tại vị trí cụ thể
    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // Chèn một phần tử mới vào heap
    void insertKey(int k) {
        if (heap_size == capacity) {
            cout << "Overflow: Could not insertKey\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    // In ra heap
    void printHeap() {
        for (int i = 0; i < heap_size; i++) {
            cout << harr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout << "Min-Heap array: ";
    h.printHeap();

    cout << "Extracted min value: " << h.extractMin() << endl;

    cout << "Min-Heap array after extraction: ";
    h.printHeap();

    return 0;
}
