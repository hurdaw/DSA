#include <iostream>
#include <iomanip>
using namespace std;
struct node
{                // định nghĩa cấu trúc node
    int data;    // thành phần dữ liệu
    node *left;  // thành phần liên kết với node con trái
    node *right; // thành phần liên kết với node con phải
} *T;            // cây nhị phân T
class Tree
{ // định nghĩa lớp các thao tác trên cây T
public:
    Tree(void)
    {             // constructor của lớp
        T = NULL; // cây ban đầu được khởi tạo là NULL
    }
    node *Make_Node(void);                    // tạo node rời rạc cho cây
    void Make_Root(void);                     // tạo node gốc cho cây
    void Insert_Left(node *root, int value);  // tạo node lá trái cho node
    void Insert_Right(node *root, int value); // tạo node lá phải cho node
    void Remove_Left(node *root, int value);  // loại node lá trái của node
    void Remove_Right(node *root, int value); // loại node lá phải của node
    void Clear_Tree(node *root);              // loại bỏ cả cây
    void NLR(node *root);                     // duyệt cây theo thứ tự trước
    void LNR(node *root);                     // duyệt cây theo thứ tự giữa
    void LRN(node *root);                     // duyệt cây theo thứ tự sau
    void Function(void);                      // hàm kiểm tra các thao tác trên cây
};
node *Tree::Make_Node(void)
{ // tạo node rời rạc có giá trị value
    node *tmp;
    int value;
    tmp = new node;
    cout << "Giá trị node:";
    cin >> value;
    tmp->data = value;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void Tree::Make_Root(void)
{ // tạo node gốc cho cây
    if (T == NULL)
    { // nếu cây rỗng
        node *tmp = Make_Node();
        T = tmp;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    else
    { // nếu cây không rỗng
        cout << "Cây đã có gốc" << endl;
    }
}
void Tree::Insert_Left(node *root, int value)
{ // thêm node lá trái cho node có gí trị value
    if (root != NULL)
    { // nếu cây không rỗng
        if (root->data == value)
        { // nếu tìm thấy node có giá trị value
            if (root->left != NULL)
            { // nếu node đã có node con trái
                cout << "Node " << value << " đã có node con trái" << endl;
                return;
            }
            else
            {                             // nếu node chưa có node con trái
                root->left = Make_Node(); // tạo node lá cho node
                return;
            }
        }
        Insert_Left(root->left, value);  // tìm node sang nhánh cây con trái
        Insert_Left(root->right, value); // tìm node sang nhánh cây con phải
    }
}
void Tree::Insert_Right(node *root, int value)
{ // thêm node lá trái cho node
    if (root != NULL)
    { // nếu cây không rỗng
        if (root->data == value)
        { // nếu tìm thấy node có giá trị value
            if (root->right != NULL)
            { // nếu node đã có node con phải
                cout << "Node " << value << " đã có node con phải" << endl;
                return;
            }
            else
            {                              // nếu node chưa có node conphải
                root->right = Make_Node(); // tạo node lá cho node
                return;
            }
        }
        Insert_Right(root->left, value);  // tìm node sang nhánh cây con trái
        Insert_Right(root->right, value); // tìm node sang nhánh cây con phải
    }
}
void Tree::Remove_Left(node *root, int value)
{ // loại bỏ node lá bên trái cho node
    if (root != NULL)
    { // nếu cây không rỗng
        if (root->data == value)
        { // nếu tìm thấy node có giá trị value
            if (root->left == NULL)
            { // nếu node không có node con trái
                cout << "Node " << value << " không có lá trái" << endl;
                return;
            }
            else if ((root->left)->left != NULL || (root->left)->right != NULL)
            {
                // nếu node có cây con trái
                cout << "Node " << value << " có cây con trái" << endl;
                return;
            }
            else if ((root->left)->left == NULL && (root->left)->right == NULL)
            {
                // nếu node có lá con trái
                node *rp = root->left; // rp nhận node lá trái
                root->left = NULL;     // ngắt liên kết trái của node
                delete (rp);           // giải phóng node
                return;
            }
        }
        Remove_Left(root->left, value);  // tìm node sang cây con trái
        Remove_Left(root->right, value); // tìm node sang cây con phải
    }
}
void Tree::Remove_Right(node *root, int value)
{ // loại bỏ node lá bên phải cho node
    if (root != NULL)
    { // nếu cây không rỗng
        if (root->data == value)
        { // nếu tìm thấy node có giá trị value
            if (root->right == NULL)
            { // nếu node không có node con phải
                cout << "Node trai cua " << value << " khong co la phai" << endl;
                return;
            }
            else if ((root->right)->left != NULL || (root->right)->right != NULL)
            {
                // nếu node có cây con phải
                cout << "Node " << value << " có cây con phải" << endl;
                return;
            }
            else if ((root->right)->left == NULL && (root->right)->right == NULL)
            {
                // nếu node có node lá phải
                node *rp = root->right; // rp nhận node lá bên phải
                root->right = NULL;     // ngắt liên kết phải cho node
                delete (rp);            // giải phóng node lá phải
                return;
            }
        }
        Remove_Right(root->left, value);  // tìm node sang cây con trái
        Remove_Right(root->right, value); // tìm node sang cây con phải
    }
}
void Tree::Clear_Tree(node *root)
{ // loại bỏ cả cây gốc root
    if (root != NULL)
    {                            // nếu cây rỗng
        Clear_Tree(root->left);  // loại loại cây con bên trái
        Clear_Tree(root->right); // loại loại cây con bên phải
        cout << "Node được giải phóng:" << root->data << endl;
        delete (root); // giải phóng node
    }
}
void Tree::NLR(node *root)
{ // duyệt cây theo thứ tự trước
    if (root != NULL)
    {                                  // nếu cây không rỗng
        cout << root->data << setw(3); // thăm node
        NLR(root->left);               // duyệt theo thứ tự trước cây con trái
        NLR(root->right);              // duyệt theo thứ tự trước cây con phải
    }
}
void Tree::LNR(node *root)
{ // duyệt cây theo thứ tự giữa
    if (root != NULL)
    {                                  // nếu cây không rỗng
        LNR(root->left);               // duyệt theo thứ tự giữa cây con trái
        cout << root->data << setw(3); // thăm node
        LNR(root->right);              // duyệt theo thứ tự giữa cây con phải
    }
}
void Tree::LRN(node *root)
{ // duyệt cây theo thứ tự sau
    if (root != NULL)
    {                                  // nếu cây không rỗng
        LRN(root->left);               // duyệt theo thứ tự sau cây con trái
        LNR(root->right);              // duyệt theo thứ tự sau cây con phải
        cout << root->data << setw(3); // thăm node
    }
}
void Tree::Function(void)
{
    int choice;
    int value;
    node *tmp, *root;
    do
    {
        cout << "\n CÁC THAO TÁC TRÊN CÂY" << endl;
        cout << "1. Tạo node gốc" << endl;
        cout << "2. Tạo node lá trái" << endl;
        cout << "3. Tạo node lá phải " << endl;
        cout << "4. Loại bỏ node lá trái " << endl;
        cout << "5. Loại bỏ node lá phải " << endl;
        cout << "6. Loại bỏ cả cây " << endl;
        cout << "7. Duyệt Node Left Right" << endl;
        cout << "8. Duyệt Left Node Right" << endl;
        cout << "9. Duyệt Left Right Node" << endl;
        cout << "0. Thoát " << endl;
        cout << "Đưa vào lựa chọn:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Make_Root();
            break;
        case 2:
            root = T;
            cout << "Giá trị node lá trái:";
            cin >> value;
            Insert_Left(root, value);
            break;
        case 3:
            root = T;
            cout << " Giá trị node lá phải:";
            cin >> value;
            Insert_Right(T, value);
            break;
        case 4:
            root = T;
            cout << " Giá trị node:";
            cin >> value;
            Remove_Left(root, value);
            break;
        case 5:
            root = T;
            cout << " Giá trị node:";
            cin >> value;
            Remove_Right(root, value);
            break;
        case 6:
            Clear_Tree(T);
            T = NULL;
            break;
        case 7:
            cout << "Duyệt NLR:";
            root = T;
            NLR(root);
            cout << endl;
            break;
        case 8:
            cout << "Duyệt LNR:";
            root = T;
            LNR(root);
            cout << endl;
            break;
        case 9:
            cout << "Duyệt LRN:";
            root = T;
            LRN(root);
            cout << endl;
            break;
        }
    } while (choice != 0);
}
int main(void)
{
    Tree X;
    X.Function();
}