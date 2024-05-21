#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
} NODE;
typedef NODE *TREE;
void init(TREE &t)
{
    t = NULL; // cây rỗng
}
void createNode(TREE &t, int x)
{
    if (t == NULL)
    {
        TREE p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        if (t->data > x)
            createNode(t->pLeft, x);
        else if (t->data < x)
            createNode(t->pRight, x);
    }
}
// hàm xuất dữ liệu theo kiểu NLR
void display_NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << " "; // xuất dữ liệu trong node
        display_NLR(t->pLeft);  // dịch qua trái
        display_NLR(t->pRight); // dịch qua phải
    }
}
// hàm xuất dữ liệu theo kiểu NLR
void display_NRL(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << " "; // xuất dữ liệu trong node
        display_NRL(t->pRight); // dịch qua trái
        display_NRL(t->pLeft);  // dịch qua phải
    }
}
// hàm xuất dữ liệu theo kiểu LNR
void display_LNR(TREE t)
{
    if (t != NULL)
    {
        display_LNR(t->pLeft);
        cout << t->data << " ";
        display_LNR(t->pRight);
    }
}
NODE *searchTree(TREE t, int x)
{
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        if (t->data > x)
            searchTree(t->pLeft, x);
        else if (t->data < x)
            searchTree(t->pRight, x);
        else
            return t;
    }
}
int max_tree(TREE t)
{
    // // chỉ có 1 node
    // if (t->pLeft == NULL && t->pRight == NULL)
    //     return t->data;
    // int max = t->data;
    // if (t->pLeft != NULL)
    // {
    //     int left = max_tree(t->pLeft);
    //     if (left > max)
    //         max = left;
    // }
    // if (t->pRight != NULL)
    // {
    //     int right = max_tree(t->pRight);
    //     if (right > max)
    //         max = right;
    // }
    // return max;
    // chỉ có 1 node
    if (t->pRight == NULL)
        return t->data;
    return max_tree(t->pRight);
}
// tìm node thế mạng
void find_node_replace(TREE &x, TREE &y) // y = t->pRight
{
    // duyệt sang bên trái nhất của node bên phải
    if (y->pLeft != NULL)
        find_node_replace(x, y->pLeft);
    else
    {
        x->data = y->data; // cập nhật data của node cần xóa thành data của node thế mạng
        x = y;             // x là node sẽ xóa
        y = y->pRight;  // trả về giá trị NULL cho node cuối bên trái
    }
}
void delete_tree(TREE &t, int value)
{
    if (t == NULL)
        return;
    else
    {
        if (t->data > value)
            delete_tree(t->pLeft, value);
        else if (t->data < value)
            delete_tree(t->pRight, value);
        else
        {
            TREE x = t;
            if (t->pLeft == NULL)
                t = t->pRight;
            if (t->pRight == NULL)
                t = t->pLeft;
            else
            {
                // cách 1: tìm node trái nhất của cây con phải
                TREE y = t->pRight; // y là node thế mạng
                find_node_replace(x, y);
            }
            delete x;
        }
    }
}
// hàm nhập dữ liệu
void menu(TREE &t)
{
    while (1)
    {
        cout << "\n\n\t=====================MENU=====================";
        cout << "\n1. Nhap du lieu: ";
        cout << "\n2. Xuat du lieu: ";
        cout << "\n3. Tim kiem phan tu trong cay: ";
        cout << "\n4. Max: ";
        cout << "\n5. delete: ";
        cout << "\n0. Ket thuc ";
        cout << "\n\n\t==============================================\n";
        int choice;
        cout << "Nhap lua chon: ";
        cin >> choice;
        if (choice < 0 || choice > 5)
        {
            cout << "Lua chon khong hop le: ";
        }
        else if (choice == 1)
        {
            int value;
            cout << "nhap value: ";
            cin >> value;
            createNode(t, value);
        }
        else if (choice == 2)
        {
            cout << "\n\txuat du lieu\n";
            display_NRL(t);
        }
        else if (choice == 3)
        {
            int x;
            cout << "nhap so can tim: ";
            cin >> x;
            TREE p = searchTree(t, x);
            if (p == NULL)
            {
                cout << "khong tim thay";
            }
            else
            {
                cout << "\nphan tu " << x << " co ton tai";
            }
        }
        else if (choice == 4)
        {
            cout << "max: " << max_tree(t) << endl;
        }
        else if (choice == 5)
        {
            int x;
            cout << "node can xoa: ";
            cin >> x;
            delete_tree(t, x);
            display_LNR(t);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    TREE t;
    init(t);
    menu(t);
}