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
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
                swap(a[i], a[j]);
        }
    }
}
void sortSLL(LIST &l)
{
    for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        for (NODE *q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->data > q->data)
                swap(p->data, q->data);
        }
    }
}
void free(LIST &l)
{
    NODE *p;
    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete (p);
    }
}
// thêm node p vào sau node q
void insert_pos(LIST &l, NODE *p, NODE *q)
{
    for (NODE *g = l.pHead; g != NULL; g = g->pNext)
    {
        if (g->data == q->data)
        {
            NODE *k = g->pNext;
            g->pNext = p;
            p->pNext = k;
            return;
        }
    }
}
void delete_begin(LIST &l)
{
    NODE *p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete (p);
}
void delete_last(LIST &l)
{
    NODE *p = l.pHead;
    // duyệt đến node kề cuối
    while (p->pNext != l.pTail)
    {
        p = p->pNext;
    }
    p->pNext = NULL;
    l.pTail = p;
}
// xóa node p sau node q
void delete_pos(LIST &l, NODE *p, NODE *q)
{
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data = q->data)
        {
            NODE *g = k->pNext;
            
        }
    }
}
int main()
{
    LIST l;
    NODE *p, *q;
    input(l);
    delete_begin(l);
    delete_last(l);
    cout << endl;
    output(l);
}
