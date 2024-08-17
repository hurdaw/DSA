#include <iostream>
using namespace std;
// Biểu diễn danh sách liên kết kép:
struct node
{                      // biểu diễn node
    int info;          // thành phần thông tin của node
    struct node *next; // thành phần con trỏ đến node trước
    struct node *prev; // thành phần con trỏ đến node sau
} *start;              // đây là danh sách liên kết kép
// Lớp biểu diễn các thao tác trên danh sách liên kết kép:
class double_linked_list
{ // Bieu dien lop
public:
    node *create_node(int); // tạo node rời rạc có giá trị value
    void insert_begin();    // thêm node vào đầu DSLKK
    void insert_pos();      // thêm node vào vị trí pos trong DSLKK
    void insert_last();     // thêm node vào cuối DSLKK
    void delete_pos();      // loại node tại vị trí pos của DSLKK
    void sort();            // sắp xếp nội dung các node
    void search();          // tìm kiếm node có giá trị value
    void update();          // cập nhật thông tin cho node
    void right_travel();    // duyệt phải DSLKK từ node đầu tiên
    void left_travel();     // duyệt trái DSLKK từ node cuối cùng
    double_linked_list()
    { // Constructor của lớp
        start = NULL;
    }
};
// Thao tác tạo node rời rạc có giá trị value:
node *double_linked_list::create_node(int value)
{
    struct node *temp;        // khai báo con trỏ node temp
    temp = new (struct node); // cấp phát miền nhớ cho temp
    if (temp == NULL)
    { // nếu không đủ bộ nhớ
        cout << "Không đủ bộ nhớ để cấp phát" << endl;
        return 0;
    }
    else
    {                       // tạo node rời rạc có giá trị value
        temp->info = value; // thiết lập thành phần thông tin
        temp->next = NULL;  // thiết lập liên kết trước cho node
        temp->prev = NULL;  // thiết lập liên kết sau cho node
        return temp;        // trả lại con trỏ node
    }
}
// Thêm node vào đầu danh sách liên kết kép:
void double_linked_list::insert_begin()
{              // thêm node vào đầu DSLKK
    int value; // giá trị của node là value
    cout << "Nhap gia tri node:";
    cin >> value;
    struct node *temp, *p;
    temp = create_node(value); // tạo node rời rạc có giá trị value
    if (start == NULL)
    {                       // trường hợp danh sách rỗng
        start = temp;       // start chính làm temp
        start->next = NULL; // thiết lập liên kết trước
        start->prev = NULL; // thiết lập liên kết sau
    }
    else
    {                    // trường hợp danh sách không rỗng
        p = start;       // p trỏ đến node đầu tiên của danh sách
        start = temp;    // start trỏ đến temp
        start->next = p; // thiết lập liên kết trước cho start
        p->prev = start; // thiết lập liên kết sau cho start
    }
    cout << "Hoàn thành thêm node vào đầu" << endl;
}
// Thêm node vào cuối DSLKK
void double_linked_list::insert_last()
{              // thêm node vào cuối DSLKK
    int value; // giá trị node cần thêm
    cout << "Nhập giá trị cho node: ";
    cin >> value;
    struct node *temp, *s;     // sử dụng hai con trỏ node
    temp = create_node(value); // tạo node temp rời rạc có giá trị value
    s = start;                 // s trỏ đến start
    while (s->next != NULL)
    { // di chuyển đến node cuối cùng
        s = s->next;
    }
    temp->next = NULL; // thiết lập liên kết trước cho temp
    s->next = temp;    // thiết lập liên kết trước cho s
    temp->prev = s;    // thiết lập liên kết sau cho temp
    cout << "Hoàn thành việc thêm node vào cuối" << endl;
}
// Thêm node vào vị trí bất kỳ:
void double_linked_list::insert_pos()
{ // thêm node và vị trí bất kỳ
    int value, pos, counter = 0;
    cout << "Giá trị node cần thêm:";
    cin >> value;
    struct node *temp, *s, *ptr;
    temp = create_node(value); // tạo node rời rạc có giá trị value
    cout << "Vị trí node cần thêm: ";
    cin >> pos;
    int i;
    s = start; // s trỏ đến node đầu trong danh sách
    while (s != NULL)
    { // xác định counter là số node trong danh sách
        s = s->next;
        counter++;
    }
    if (pos == 1)
    { // nếu ta thêm vào node đầu tiên
        if (start == NULL)
        {                       // trường hợp danh sách rỗng
            start = temp;       // start lấy luôn là temp
            start->next = NULL; // thiết lập liên kết trước
            start->prev = NULL; // thiết lập liên kết sau
        }
        else
        {                      // trường hợp danh sách không rỗng
            ptr = start;       // ptr trỏ đến start
            start = temp;      // start lấy bằng temp
            start->next = ptr; // thiết lập liên kết trước cho start
            ptr->prev = start; // thiết lập liên kết sau cho ptr
        }
    }
    else if (pos > 1 && pos <= counter)
    {              // trường hợp vị trí pos hợp lệ
        s = start; // s trỏ đến node đầu tiên
        for (i = 1; i < pos; i++)
        { // di chuyển s đến vị trí pos
            ptr = s;
            s = s->next;
        }
        ptr->next = temp; // thiết lập liên kết trước cho ptr là temp
        temp->prev = ptr; // thiết lập liên kết sau cho temp là ptr
        temp->next = s;   // thiết lập liên kết trước cho temp là s
        s->prev = temp;   // thiết lập liên kết sau cho s là temp
    }
    else
    {
        cout << "Vị trí không hợp lệ" << endl;
    }
}
// Sắp xếp nội dung các node
void double_linked_list::sort()
{                         // sắp xếp nội dung các node
    struct node *ptr, *s; // sử dụng hai con trỏ node
    int value;
    if (start == NULL)
    { // trường hợp danh sách rỗng
        cout << "Không có gì để sắp xếp" << endl;
        return;
    }
    ptr = start; // ptr trỏ đến node đầu tiên
    while (ptr != NULL)
    { // lặp cho đến node cuối cùng
        for (s = ptr->next; s != NULL; s = s->next)
        { // duyệt từ node tiếp theo
            if (ptr->info > s->info)
            {                      // nếu xảy ra điều này
                value = ptr->info; // đổi nội dung hai node
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next; // duyệt đến node tiếp theo
    }
}
// Loại node ở vị trí pos:
void double_linked_list::delete_pos()
{ // loại node ở vị trí bất kỳ
    int pos, i, counter = 0;
    if (start == NULL)
    { // trường hợp danh sách rỗng
        cout << "Không có gì để loại bỏ" << endl;
        return;
    }
    cout << "Vị trí node cần loại:";
    cin >> pos;
    struct node *s, *ptr; // sử dụng hai con trỏ node
    s = start;            // s trỏ đến start
    if (pos == 1)
    {                    // nếu loại node đầu tiên
        start = s->next; // di chuyển start lên một node
        free(s);         // giải phóng s là xong
    }
    else
    { // nếu không phải là node đầu tiên
        while (s != NULL)
        { // xác định counter là số node trong DSLKK
            s = s->next;
            counter++;
        }
        if (pos > 0 && pos <= counter)
        {              // nếu vị trí hợp lệ
            s = start; // s trỏ đến node đầu tiên
            for (i = 1; i < pos; i++)
            { // di chuyển s đến vị trí pos
                ptr = s;
                s = s->next;
            }
            if (s->next == NULL)
            {                     // nếu s lại là node cuối cùng
                ptr->next = NULL; // thiết lập liên kết trước cho ptr
                s->prev = NULL;   // thiết lập liên kết sau cho s
                free(s);          // giải phóng s
            }
            else
            {
                ptr->next = s->next;   // thiết lập liên kết trước cho ptr
                (s->next)->prev = ptr; // thiết lập liên kết sau cho s-next
                free(s);               // giải phóng s
            }
        }
        else
        {
            cout << "Vị trí không hợp lệ" << endl;
        }
    }
}
// Sửa đổi thông tin cho node
void double_linked_list::update()
{ // sửa đổi thông tin cho node
    int value, pos, i;
    if (start == NULL)
    { // nếu danh sách rỗng
        cout << "Không có gì để sửa" << endl;
        return;
    }
    cout << "Vị trí node cần cập nhật:";
    cin >> pos;
    cout << "Giá trị mới của node:";
    cin >> value;
    struct node *s, *ptr; // sử dụng hai con trỏ node
    s = start;            // s trỏ đến start
    if (pos == 1)
    {                        // nếu cập nhật node đầu tiên
        start->info = value; // ta thực hiện được ngay
    }
    else
    { // trường hợp không phải node đầu tiên
        for (i = 0; i < pos - 1; i++)
        { // chuyển s đến vị trí pos
            if (s == NULL)
            { // nếu s là node rỗng
                cout << "Vị trí " << pos << " không hợp lệ";
                return;
            }
            s = s->next;
        }
        s
            ->info = value; // cập nhật lại thông tin cho s
    }
    cout << "Sửa đổi thành công" << endl;
}
// Tìm kiếm node
void double_linked_list::search()
{ // tìm kiếm node có giá trị value
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    { // trường hợp danh sách rỗng
        cout << "Không có gì để tìm" << endl;
        return;
    }
    cout << "Giá trị node cần tìm:";
    cin >> value;
    struct node *s;
    s = start; // s trỏ đến start
    while (s != NULL)
    {
        pos++;
        if (s->info == value)
        { // nếu tìm thấy node s
            flag = true;
            cout << "Giá trị " << value << " tại vị trí " << pos << endl;
        }
        s = s->next;
    }
    if (!flag)
        cout << "Giá trị " << value << " không tồn tại" << endl;
}
// Duyệt phải các node
void double_linked_list::right_travel()
{ // duyệt từ node đầu tiên
    struct node *temp;
    if (start == NULL)
    {
        cout << "Danh sách rỗng" << endl;
        return;
    }
    temp = start;
    cout << "Nội dung các node: " << endl;
    while (temp != NULL)
    {                               // lặp đến node cuối cùng
        cout << temp->info << "->"; // đưa ra nội dung node
        temp = temp->next;          // di chuyển đến node tiếp theo
    }
    cout << "NULL" << endl; // node cuối cùng là null
}
// Duyệt trái từ node cuối cùng
void double_linked_list::left_travel()
{ // duyệt từ node cuối cùng
    struct node *temp;
    if (start == NULL)
    {
        cout << "Danh sách rỗng" << endl;
        return;
    }
    temp = start;
    while (temp->next != NULL) // di chuyển đến node cuối cùng
        temp = temp->next;
    cout << "Nội dung các node: " << endl;
    while (temp != NULL)
    {                               // lặp cho đến node đầu tiên
        cout << temp->info << "->"; // nội dung node hiện tại
        temp = temp->prev;          // lùi lại node phía sau
    }
    cout << "NULL" << endl; // node cuối cùng là null
}
int main()
{ // chương trình chính
    int choice;
    double_linked_list X; // X là đối tượng double_linked_list
    start = NULL;         // start được khởi đầu là null
    while (1)
    {
        cout << endl
             << "---------------------------------" << endl;
        cout << endl
             << "THAO TÁC TRÊN DSLKK " << endl;
        cout << endl
             << "---------------------------------" << endl;
        cout << "1. Thêm node vào đầu danh sách" << endl;
        cout << "2. Thêm node vào cuối danh sách " << endl;
        cout << "3. Thêm node vào vị trí bất kỳ " << endl;
        cout << "4. Sắp xếp nội dung các node" << endl;
        cout << "5. Loại bỏ node bất kỳ" << endl;
        cout << "6. Cập nhật nội dung node" << endl;
        cout << "7. Tìm kiếm node theo giá trị" << endl;
        cout << "8. Duyệt từ trái qua phải" << endl;
        cout << "9. Duyệt từ phải qua trái " << endl;
        cout << "0. Thoát " << endl;
        cout << "Lựa chọn chức năng: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Thêm node vào đầu: " << endl;
            X.insert_begin();
            cout << endl;
            break;
        case 2:
            cout << "Thêm node vào cuối: " << endl;
            X.insert_last();
            cout << endl;
            break;
        case 3:
            cout << "Thêm node vào vị trí bất kỳ:" << endl;
            X.insert_pos();
            cout << endl;
            break;
        case 4:
            cout << "Sắp xếp nội dung các node: " << endl;
            X.sort();
            cout << endl;
            break;
        case 5:
            cout << "Loại bỏ node bất kỳ: " << endl;
            X.delete_pos();
            break;
        case 6:
            cout << "Cập nhật nội dung node:" << endl;
            X.update();
            cout << endl;
            break;
        case 7:
            cout << "Tìm node theo giá trị: " << endl;
            X.search();
            cout << endl;
            break;
        case 8:
            cout << "Duyệt từ node bên trái:" << endl;
            X.left_travel();
            cout << endl;
            break;
        case 9:
            cout << "Duyệt từ node bên phải:" << endl;
            X.right_travel();
            cout << endl;
            break;
        case 0:
            cout << "Thoat..." << endl;
            exit(1);
            break;
        default:
            cout << "Lua chon sai" << endl;
        }
    }
}