// #include <iostream>
// #include <iomanip>
// #define MAX 100
// using namespace std;
// class Queue
// { // định nghĩa lớp queue
// public:
//     int node[MAX]; // các node của queue
//     int inp;       // dùng để đưa phần tử vào hàng đợi
//     int out;       // dùng để lấy phần tử ra khỏi hàng đợi
//     void Push()
//     {                       // đưa phần tử vào hàng đợi
//         int value;          // giá trị node
//         if (inp == MAX - 1) // nếu hàng đợi tràn
//             cout << "Tràn hàng đợi " << endl;
//         else
//         {                  // nếu hàng đợi chưa đầy
//             if (out == -1) // trường hợp hàng đợi rỗng
//                 out = 0;   // lấy vị trí out = 0
//             cout << "Giá trị node : ";
//             cin >> value;
//             inp = inp + 1;     // tăng con trỏ inp
//             node[inp] = value; // lưu trữ nội dung node
//         }
//     }
//     void Pop()
//     { // lấy phần tử ra khỏi hàng đợi
//         if (out == -1 || out > inp)
//         { // trường hợp hàng đợi rỗng
//             cout << "Queue rỗng" << endl;
//             return;
//         }
//         else
//         { // trường hợp hàng đợi không rỗng
//             cout << " Node được lấy ra : " << node[out] << endl;
//             out = out + 1;
//         }
//     }
//     void Display()
//     {                  // duyệt các node trong hàng đợi
//         if (out == -1) // trường hợp hàng đợi rỗng
//             cout << "Queue is empty " << endl;
//         else
//         {
//             cout << "Nội dung hàng đợi : ";
//             for (int i = out; i <= inp; i++)
//                 cout << node[i] << setw(3);
//             cout << endl;
//         }
//     }
//     Queue(void)
//     {             // constructor của lớp
//         inp = -1; // điểm vào thiết lập -1
//         out = -1; // điểm ra thiết lập -1
//     }
// };
// int main(void)
// {
//     int choice;
//     Queue X; // định nghĩa đối tượng X là queue
//     do
//     {
//         cout << "1. Đưa phần tử vào hàng đợi" << endl;
//         cout << "2. Lấy phần tử ra khỏi hàng đợi" << endl;
//         cout << "3. Duyệt các node của hàng đợi " << endl;
//         cout << "0. Thoát " << endl;
//         cout << "Đưa vào lựa chọn : ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             X.Push();
//             break;
//         case 2:
//             X.Pop();
//             break;
//         case 3:
//             X.Display();
//             break;
//         default:
//             cout << "Lựa chọn sai" << endl;
//             break;
//         }
//     } while (choice != 0);
// }
#include <iostream>
#include <iomanip>
using namespace std;
struct node
{                      // biểu diễn node của hàng đợi ưu tiên
    int priority;      // mức độ ưu tiên của node
    int data;          // thành phần thông tin của node
    struct node *next; // thành phần liên kết của node
};
class Priority_Queue
{ // định nghĩa lớp Priority_Queue
private:
    node *start; // start là danh sách liên kết đơn
public:
    Priority_Queue()
    {                 // Constructor của lớp
        start = NULL; // thiết lập lúc đầu là rỗng
    }
    void Push(int item, int priority); // thêm node vào hàng đợi ưu tiên
    void Pop(void);                    // loại node khỏi hàng đợi ưu tiên
    void Display();                    // duyệt các node
};
void Priority_Queue::Push(int item, int priority)
{ // thêm node với độ ưu tiên
    node *tmp, *q;
    tmp = new node;           // cấp phát miền nhớ cho node
    tmp->data = item;         // thiết lập thông tin của node
    tmp->priority = priority; // thiết lập chế độ ưu tiên của node
    if (start == NULL || priority < start->priority)
    {                      // trường hợp danh sách rỗng
        tmp->next = start; // tmp chỉ việc đặt ở đầu
        start = tmp;       // start bắt đầu từ đây
    }
    else
    {              // nếu start không rỗng
        q = start; // q trỏ đến node đầu tiên
        // tìm vị trí phù hợp với độ ưu tiên của tmp
        while (q->next != NULL && q->next->priority <= priority)
            q = q->next;
        tmp->next = q->next; // thiết lập liên kết cho tmp
        q->next = tmp;       // thiết lập liên kết cho q
    }
}
void Priority_Queue::Pop()
{
    node *tmp;
    if (start == NULL) // nếu hàng đợi rỗng
        cout << "Hàng đợi rỗng" << endl;
    else
    {
        tmp = start; // tmp trỏ đến starrt
        cout << "Node bị loại: " << tmp->data << endl;
        start = start->next; // di chuyển start lên một node
        free(tmp);           // giải phóng tmp
    }
}
void Priority_Queue::Display()
{ // Hien thi priority queue
    node *ptr;
    ptr = start; // ptr trỏ đến start
    if (start == NULL)
        cout << "Hàng đợi rỗng" << endl;
    else
    {
        cout << "Nội dung hàng đợi" << endl;
        cout << "Priority Item " << endl;
        while (ptr != NULL)
        {
            cout << ptr->priority << setw(10) << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}
int main()
{
    int choice, item, priority;
    Priority_Queue pq;
    do
    {
        cout << "1.Push\n";
        cout << "2.Delete\n";
        cout << "3.Display\n";
        cout << "0.Quit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Giá trị node : ";
            cin >> item;
            cout << "Mức độ ưu tiên : ";
            cin >> priority;
            pq.Push(item, priority);
            break;
        case 2:
            pq.Pop();
            break;
        case 3:
            pq.Display();
            break;
        default:
            cout << "Lựa chọn sai" << endl;
            break;
        }
    } while (choice != 0);
}