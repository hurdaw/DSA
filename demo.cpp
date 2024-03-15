#include <iostream>
using namespace std;

struct node {
    float soMu;
    float heSo;
    node *next;
};

class single_linked_list {
public:
    node *start;
    single_linked_list() {
        start = NULL;
    }
    node *create_node(float, float);
    void insert_begin();
    void insert_last();
    void display();
};

node *single_linked_list::create_node(float heSo, float soMu) {
    node *p = new node;
    if (p == nullptr) {
        cout << "Khong du bo nho cap phat" << endl;
        return nullptr;
    } else {
        p->heSo = heSo;
        p->soMu = soMu;
        p->next = NULL;
        return p;
    }
}

void single_linked_list::insert_begin() {
    float heSo, soMu;
    cout << "Nhap vao he so: ";
    cin >> heSo;
    cout << "Nhap vao so mu: ";
    cin >> soMu;
    node *temp = create_node(heSo, soMu);
    if (temp == nullptr) return; // Kiểm tra trường hợp cấp phát không thành công
    if (start == NULL) {
        start = temp;
    } else {
        temp->next = start;
        start = temp;
    }
}

void single_linked_list::insert_last() {
    float heSo, soMu;
    cout << "Nhap vao he so: ";
    cin >> heSo;
    cout << "Nhap vao so mu: ";
    cin >> soMu;
    node *temp = create_node(heSo, soMu);
    if (temp == nullptr) return; // Kiểm tra trường hợp cấp phát không thành công
    if (start == NULL) {
        start = temp;
    } else {
        node *p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void single_linked_list::display() {
    node *temp = start;
    while (temp != NULL) {
        cout << temp->heSo << "x^" << temp->soMu;
        if (temp->next != NULL) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    single_linked_list sll;

    // Ví dụ: thêm 5 nút
    for (int i = 0; i < 5; ++i) {
        sll.insert_last();
    }

    sll.display();
    return 0;
}
