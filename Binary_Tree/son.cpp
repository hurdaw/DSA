#include <iostream>
#include <vector>
using namespace std;

// Cấu trúc 1 node
struct node
{
    int data;            // dữ liệu của node
    struct node *pLeft;  // node liên kết bên trái của cây <=> cây con trái
    struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef struct node NODE;
typedef NODE *TREE;

// Khởi tạo cây
void KhoiTaoCay(TREE &t)
{
    t = NULL; // cây rỗng
}

// Hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t, int x)
{
    // Nếu cây rỗng
    if (t == NULL)
    {
        NODE *p = new NODE; // khởi tạo 1 cái node để thêm vào cây
        p->data = x;        // thêm dữ liệu x vào data
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p; // node p chính là node gốc <=> x chính là node gốc
    }
    else
    { // cây có tồn tại phần tử
        // Nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái
        if (t->data > x)
        {
            ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
        }
        else if (t->data < x)
        {                                 // nếu phần tử thêm vào mà lớn hơn node gốc ==> thêm nó vào bên phải
            ThemNodeVaoCay(t->pRight, x); // duyệt qua phải để thêm phần tử x
        }
    }
}

// Hàm xuất cây nhị phân theo NLR
void Duyet_NLR(TREE t)
{
    // Nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        cout << t->data << " "; // xuất dữ liệu trong node
        Duyet_NLR(t->pLeft);    // duyệt qua trái
        Duyet_NLR(t->pRight);   // duyệt qua phải
    }
}

// Hàm xuất cây nhị phân theo NRL
void Duyet_NRL(TREE t)
{
    // Nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        cout << t->data << " "; // xuất dữ liệu trong node
        Duyet_NRL(t->pRight);   // duyệt qua phải
        Duyet_NRL(t->pLeft);    // duyệt qua trái
    }
}

// Hàm xuất cây nhị phân theo LNR <=> xuất ra các phần tử từ bé đến lớn
void Duyet_LNR(TREE t)
{
    // Nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_LNR(t->pLeft);     // duyệt qua trái
        cout << t->data << "  "; // xuất giá trị của node
        Duyet_LNR(t->pRight);    // duyệt qua phải
    }
}

// Hàm xuất cây nhị phân theo RNL <=> xuất ra các phần tử từ lớn đến bé
void Duyet_RNL(TREE t)
{
    // Nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_RNL(t->pRight);    // duyệt qua phải
        cout << t->data << "  "; // xuất giá trị của node
        Duyet_RNL(t->pLeft);     // duyệt qua phải
    }
}

// Hàm xuất cây nhị phân theo LRN
void Duyet_LRN(TREE t)
{
    // Nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_LRN(t->pLeft);     // duyệt qua trái
        Duyet_LRN(t->pRight);    // duyệt qua phải
        cout << t->data << "  "; // xuất giá trị của node
    }
}

// Hàm xuất cây nhị phân theo RLN
void Duyet_RLN(TREE t)
{
    // Nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_RLN(t->pRight);    // duyệt qua phải
        Duyet_RLN(t->pLeft);     // duyệt qua trái
        cout << t->data << "  "; // xuất giá trị của node
    }
}

// Hàm loại bỏ node lá bên trái có giá trị x
void XoaNodeLaBenTrai(TREE &t, int x)
{
    if (t != NULL)
    {
        if (t->pLeft != NULL && t->pLeft->data == x && t->pLeft->pLeft == NULL && t->pLeft->pRight == NULL)
        {
            delete t->pLeft;
            t->pLeft = NULL;
        }
        else
        {
            XoaNodeLaBenTrai(t->pLeft, x);
        }
        XoaNodeLaBenTrai(t->pRight, x);
    }
}

// Hàm loại bỏ node lá bên phải có giá trị x
void XoaNodeLaBenPhai(TREE &t, int x)
{
    if (t != NULL)
    {
        if (t->pRight != NULL && t->pRight->data == x && t->pRight->pLeft == NULL && t->pRight->pRight == NULL)
        {
            delete t->pRight;
            t->pRight = NULL;
        }
        else
        {
            XoaNodeLaBenPhai(t->pRight, x);
        }
        XoaNodeLaBenPhai(t->pLeft, x);
    }
}

// Hàm so sánh hai cây nhị phân có giống nhau hay không
bool KiemTraCayGiongNhau(TREE t1, TREE t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 != NULL && t2 != NULL)
    {
        return (t1->data == t2->data &&
                KiemTraCayGiongNhau(t1->pLeft, t2->pLeft) &&
                KiemTraCayGiongNhau(t1->pRight, t2->pRight));
    }
    return false;
}

// Hàm tìm độ cao của cây
int TimDoCaoCuaCay(TREE t)
{
    if (t == NULL)
        return 0;
    int leftHeight = TimDoCaoCuaCay(t->pLeft);
    int rightHeight = TimDoCaoCuaCay(t->pRight);
    return max(leftHeight, rightHeight) + 1;
}

// Hàm tìm tất cả các đường đi từ node gốc đến node lá
void TimDuongDi(TREE t, vector<int> &path)
{
    if (t == NULL)
        return;

    // Thêm node hiện tại vào đường đi
    path.push_back(t->data);

    // Nếu là node lá, in đường đi
    if (t->pLeft == NULL && t->pRight == NULL)
    {
        for (int i : path)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        // Nếu không phải, tiếp tục tìm đường đi cho cây con
        TimDuongDi(t->pLeft, path);
        TimDuongDi(t->pRight, path);
    }

    // Loại bỏ node hiện tại khỏi đường đi
    path.pop_back();
}

// Hàm đếm số lượng node lá trên cây
int DemNodeLa(TREE t)
{
    if (t == NULL)
        return 0;
    if (t->pLeft == NULL && t->pRight == NULL)
        return 1;
    return DemNodeLa(t->pLeft) + DemNodeLa(t->pRight);
}

// Hàm kiểm tra cây thỏa mãn điều kiện node trung gian bằng tổng hai node con
bool KiemTraDieuKien(TREE t)
{
    if (t == NULL)
        return true;
    if (t->pLeft == NULL && t->pRight == NULL)
        return true;

    int leftData = (t->pLeft != NULL) ? t->pLeft->data : 0;
    int rightData = (t->pRight != NULL) ? t->pRight->data : 0;

    return (t->data == leftData + rightData &&
            KiemTraDieuKien(t->pLeft) &&
            KiemTraDieuKien(t->pRight));
}

// Hàm nhập dữ liệu
void Menu(TREE &t)
{
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nhap du lieu";
        cout << "\n2. Duyet cay NLR";
        cout << "\n3. Duyet cay NRL";
        cout << "\n4. Duyet cay LNR";
        cout << "\n5. Duyet cay RNL";
        cout << "\n6. Duyet cay LRN";
        cout << "\n7. Duyet cay RLN";
        cout << "\n8. Xoa node la ben trai";
        cout << "\n9. Xoa node la ben phai";
        cout << "\n10. Kiem tra hai cay giong nhau";
        cout << "\n11. Tim do cao cua cay";
        cout << "\n12. Tim tat ca cac duong di tu node goc den node la";
        cout << "\n13. Dem so luong node la";
        cout << "\n14. Kiem tra dieu kien node trung gian bang tong hai node con";
        cout << "\n0. Ket thuc";
        cout << "\n\n\t\t ============================";

        int luachon;

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 14)
        {
            cout << "\nLua chon khong hop le";
            system("pause");
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\nNhap so nguyen x: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if (luachon == 2)
        {
            cout << "\n\t\t DUYET CAY THEO NLR\n";
            Duyet_NLR(t);
            system("pause");
        }
        else if (luachon == 3)
        {
            cout << "\n\t\t DUYET CAY THEO NRL\n";
            Duyet_NRL(t);
            system("pause");
        }
        else if (luachon == 4)
        {
            cout << "\n\t\t DUYET CAY THEO LNR\n";
            Duyet_LNR(t);
            system("pause");
        }
        else if (luachon == 5)
        {
            cout << "\n\t\t DUYET CAY THEO RNL\n";
            Duyet_RNL(t);
            system("pause");
        }
        else if (luachon == 6)
        {
            cout << "\n\t\t DUYET CAY THEO LRN\n";
            Duyet_LRN(t);
            system("pause");
        }
        else if (luachon == 7)
        {
            cout << "\n\t\t DUYET CAY THEO RLN\n";
            Duyet_RLN(t);
            system("pause");
        }
        else if (luachon == 8)
        {
            int x;
            cout << "\nNhap gia tri node can xoa: ";
            cin >> x;
            XoaNodeLaBenTrai(t, x);
            cout << "\nDa xoa node la ben trai co gia tri " << x << endl;
            system("pause");
        }
        else if (luachon == 9)
        {
            int x;
            cout << "\nNhap gia tri node can xoa: ";
            cin >> x;
            XoaNodeLaBenPhai(t, x);
            cout << "\nDa xoa node la ben phai co gia tri " << x << endl;
            system("pause");
        }
        else if (luachon == 10)
        {
            TREE t2;
            KhoiTaoCay(t2);
            cout << "\nNhap du lieu cho cay thu hai\n";
            Menu(t2);
            if (KiemTraCayGiongNhau(t, t2))
            {
                cout << "\nHai cay giong nhau\n";
            }
            else
            {
                cout << "\nHai cay khong giong nhau\n";
            }
            system("pause");
        }
        else if (luachon == 11)
        {
            cout << "\nDo cao cua cay la: " << TimDoCaoCuaCay(t) << endl;
            system("pause");
        }
        else if (luachon == 12)
        {
            vector<int> path;
            cout << "\nCac duong di tu node goc den node la:\n";
            TimDuongDi(t, path);
            system("pause");
        }
        else if (luachon == 13)
        {
            cout << "\nSo luong node la tren cay: " << DemNodeLa(t) << endl;
            system("pause");
        }
        else if (luachon == 14)
        {
            if (KiemTraDieuKien(t))
            {
                cout << "\nCay thoa man dieu kien\n";
            }
            else
            {
                cout << "\nCay khong thoa man dieu kien\n";
            }
            system("pause");
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
    KhoiTaoCay(t);
    Menu(t);

    system("pause");
    return 0;
}