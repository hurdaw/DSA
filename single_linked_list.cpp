#include <iostream>
using namespace std;
struct node
{
    int infor;
    struct node *next;
} *start;
class single_linked_list
{
public:
    node *create_node(int); // tạo node rời rạc có giá trị value
    void insert_begin();    // add node vào đầu single linked list
    void insert_pos();      // add node vào vị trí pos bất kỳ
    void insert_last();     // add node vào cuối SLL
    void delete_pos();      // remove node vào vị trí pos
    void sort();            // sắp xếp theo giá trị
    void search();          // tìm kiếm trong SLL
    void update();          // cập nhật thông tin cho node
    void reverse();         // đảo ngược các node trong SLL
    void display();         // duyệt DLL
    void input_linked_list(); // hàm nhập SLL
    single_linked_list()
    {
        start = NULL;
    }
};
node *single_linked_list::create_node(int value)
{
    struct node *temp;
    temp = new (struct node); // cấp phát không gian nhớ cho temp
    if (temp == NULL)
    { // nếu không đủ không gian nhớ để cấp phát
        cout << " Khong du bo nho " << endl;
        return 0;
    }
    else
    {
        temp->infor = value; // thiết lập thành phần thông tin
        temp->next = NULL;   // thiết lập thành phần liên kết
        return temp;         // trả lại con trỏ node
    }
}
void single_linked_list::insert_begin()
{
    int value;
    cout << "nhap gia tri node: ";
    cin >> value;
    struct node *temp, *p;
    temp = create_node(value); // tạo node rời rạc có giá trị value
    if (start == NULL)
    {                       // nếu SLL rỗng
        start = temp;       // start là temp
        start->next = NULL; // thiết lập thành phần liên kết cho start
    }
    else
    {
        p = start; // p trỏ đến node đầu của SLL
        start = temp;
        start->next = p;
    }
}
void single_linked_list::insert_last()
{
    int value;
    cout << " nhap gia tri cho node: ";
    cin >> value;
    struct node *temp, *s;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    s = start;              // s trỏ đến node đầu danh sách
    while (s->next != NULL) // di chuyển s đến node cuối
    {
        s = s->next;
    }
    temp->next = NULL; // temp không trỏ đi đâu nữa
    s->next = temp;    // thiết lập liên kết cho s
}
void single_linked_list::insert_pos()
{
    int value, pos, cnt = 0;
    cout << " nhap gia tri node: ";
    cin >> value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    cout << " nhap vi tri node can them: ";
    cin >> pos;
    int i;
    s = start;
    while (s != NULL) // đếm số node của SLL
    {
        s = s->next;
        cnt++;
    }
    if (cnt == 0)
    { // trường hợp SLL rỗng
        cout << " danh sach rong";
        return;
    }
    if (pos == 1)
    {                      // nếu pos là vị trí đầu tiên
        if (start == NULL) // trường hợp SLL rỗng
        {
            start = temp;
            start->next = NULL;
        }
        else
        { // thêm node temp vào đầu SLL
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1 && pos <= cnt)
    { // trường hợp pos hợp lệ
        s = start;
        for (int i = 1; i < pos; i++)
        { // di chuyển đến pos-1
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s; // thiết lập liên kết cho node
    }
    else
    {
        cout << " vuot qua gioi han SLL" << endl;
    }
}
void single_linked_list::delete_pos()
{
    int pos, i, cnt = 0;
    if (start == NULL)
    {
        cout << " khong thuc hien duoc" << endl;
        return;
    }
    cout << " nhap vi tri can xoa: ";
    cin >> pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
        s->next = NULL;
        free(s); // giải phóng s
    }
    else
    {
        while (s != NULL) // đếm số node
        {
            s = s->next;
            cnt++;
        }
        if (pos > 0 && pos <= cnt) // nếu vị trí pos hợp lệ
        {
            s = start;
            for (int i = 1; i < pos; i++)
            {
                ptr = s; // tới cuối vòng lặp thì s == pos
                s = s->next;
            }
            ptr->next = s->next; // thiết lập liên kết cho node
        }
        else
        {
            cout << " vi tri ngoai danh sach" << endl;
        }
        free(s);
        cout << " Node da duoc xoa" << endl;
    }
}
void single_linked_list::update()
{
    int value, pos, i;
    if (start == NULL)
    {
        cout << " khong thuc hien duoc" << endl;
    }
    cout << " nhap gia tri cua pos: ";
    cin >> pos;
    cout << " nhap gia tri moi cua pos: ";
    cin >> value;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->infor = value;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            if (s == NULL)
            { // nếu s là node cuối cùng
                cout << " vi tri: " << pos << " khong hop le" << endl;
                return;
            }
            s = s->next;
        }
        s->infor = value; // sửa thông tin node
    }
}
void single_linked_list::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout << " khong co gi ";
        return;
    }
    temp = start; // temp trỏ đến node đầu trong SLL
    cout << " noi dung SLL" << endl;
    while (temp != NULL)
    {
        cout << temp->infor << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void single_linked_list::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start = NULL)
    {
        cout << " Nothing to search";
        return;
    }
    cout << " noi dung can tim: ";
    cin >> value;
    struct node *s;
    s = start;
    while (s != NULL)
    {
        if (s->infor == value)
        {
            flag = true;
            cout << " tim thay" << value << " tai vi tri" << pos << endl;
        }
        s = s->next;
    }
    if (!flag)
    { // đến cuối vẫn không thấy
        cout << " gia tri" << value << " khong ton tai" << endl;
    }
}
void single_linked_list::sort()
{
    struct node *ptr, *s;
    int value; // giá trị trung gian
    if (start == NULL)
    {
        cout << " Nothing to sort" << endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next; s != NULL; s = s->next)
        {
            if (ptr->infor > s->infor)
            {
                value = ptr->infor; // tráo đổi nội dung hai node
                ptr->infor = s->infor;
                s->infor = value;
            }
        }
        ptr = ptr->next;
    }
}
void single_linked_list::reverse()
{
    struct node *ptr1, *ptr2, *ptr3; // sử dụng ba con trỏ node
    if (start == NULL)
    {
        cout << " Nothing to reverse";
        return;
    }
    if (start->next = NULL)
    { // nếu danh sách chỉ có 1 node
        cout << " chinh no" << endl;
        return;
    }
    ptr1 = start;
    ptr2 = ptr1->next; // ptr2 trỏ đến node kế tiếp của ptr1
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1; // node ptr2 bây giờ đứng trước node ptr1
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;       // ptr1 lại bắt đầu tại vị trí ptr2
        ptr2 = ptr3;       // ptr2 bắt đầu tại vị trí ptr3
        ptr3 = ptr3->next; // ptr3 trỏ đến node kế tiếp
        ptr2->next = ptr1; // thiết lập liên kết cho ptr2
    }
    start = ptr2; // node đầu tiên bây giờ là ptr2
}
void single_linked_list::input_linked_list()
{
    char choice;
    do
    {
        single_linked_list::insert_last();
         cout << "Ban co muon nhap them gia tri? (y/n): ";
            cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
int main()
{
    int choice;
    single_linked_list x;
    start = NULL;
    x.input_linked_list();
    while (1)
    {
        cout << endl
             << "--------------------------------" << endl;
        cout << endl
             << "CAC THAO TAC TREN SLL" << endl;
        cout << endl
             << "--------------------------------" << endl;
        cout << "1. Them node vao dau danh sach" << endl;
        cout << "2. Them node vao cuoi danh sach" << endl;
        cout << "3. Them node vao vi tri bat ky" << endl;
        cout << "4. Sap xep theo gia tri cua cac node" << endl;
        cout << "5. Xoa node bat ky" << endl;
        cout << "6. Cap nhat noi dung node" << endl;
        cout << "7. Tim kiem node theo gia tri" << endl;
        cout << "8. Duyet danh sach" << endl;
        cout << "9. Dao nguoc danh sach" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon chuc nang: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Them node vao dau danh sach" << endl;
            x.insert_begin();
            cout << endl;
            break;
        case 2:
            cout << "Them node vao cuoi danh sach" << endl;
            x.insert_last();
            cout << endl;
            break;
        case 3:
            cout << "Them node vao vi tri bat ky" << endl;
            x.insert_pos();
            cout << endl;
            break;
        case 4:
            cout << "4. Sap xep theo gia tri cua cac node" << endl;
            x.sort();
            cout << endl;
            break;
        case 5:
            cout << "Xoa node bat ky" << endl;
            x.delete_pos();
            cout << endl;
            break;
        case 6:
            cout << "Cap nhat noi dung node" << endl;
            x.update();
            cout << endl;
            break;
        case 7:
            cout << "Tim kiem node theo gia tri" << endl;
            x.search();
            cout << endl;
            break;
        case 8:
            cout << "Duyet danh sach" << endl;
            x.display();
            cout << endl;
            break;
        case 9:
            cout << "Dao nguoc danh sach" << endl;
            x.reverse();
            cout << endl;
            break;
        case 0:
            cout << "Thoat" << endl;
            exit(1);
            break;
        default:
            cout << "Lua chon sai";
            break;
        }
    }
}
