#include <iostream>
using namespace std;
// khai báo SLL
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
struct list
{
    NODE *pHead;
    NODE *pTail; 
};
typedef struct list LIST;
// khởi tạo
void init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
NODE *create_node(int value)
{
    NODE *temp = new (NODE);
    if (temp == NULL)
        return NULL;
    temp->data = value;
    temp->pNext = NULL;
    return temp;
}
// thêm node p vào đầu danh sách
void insert_begin(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead; // p quăng dây tham gia vào danh sách
        l.pHead = p;
    }
}
void insert_last(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void input(list &l)
{
    int n;
    cout << "nhap so node: ";
    cin >> n;
    init(l);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << endl
             << "Gia tri cua node la: ";
        cin >> x;
        NODE *p = create_node(x);
        insert_last(l, p);
    }
}
void output(LIST l)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
}
int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int max(LIST l)
{
    // int max=a[0];
    int max = l.pHead->data;
    for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if (p->data > max)
            max = p->data;
    }
    return max;
}
int main()
{
    LIST l;
    input(l);
    output(l);
    cout << endl;
    cout << max(l);
}