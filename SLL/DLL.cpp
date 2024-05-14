#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *previous;
    struct node *next;
} NODE;
typedef struct list
{
    NODE *pHead;
    NODE *pTail;
} LIST;
void init(LIST &l)
{
    l.pHead=l.pTail=NULL;
}
NODE *createdNode(int value)
{
    NODE *p;
    p = new (NODE);
    p->data = value;
    p->previous = NULL;
    p->next = NULL;
    return p;
}
void insert_begin(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->next = l.pHead;
        l.pHead->previous = p;
        l.pHead = p;
    }
}
void insert_last(LIST &l, NODE *p)
{
    NODE *s = l.pHead;
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->next = p;
        p->previous = l.pTail;
        l.pTail = p;
    }
}

void display(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void input(LIST &l)
{
    int n;
    cout << "nhap so node: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        NODE *p = createdNode(value);
        insert_last(l, p);
    }
}
int main()
{
    LIST l;
    init(l);
    input(l);
    display(l);
}