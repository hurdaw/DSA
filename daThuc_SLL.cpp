#include <iostream>
#include <fstream>
using namespace std;
struct node
{
    float heSo, soMu;
    struct node *pNext;
};
typedef struct node NODE;
struct list
{
    NODE *pHead, *pTail;
};
typedef struct list LIST;
// khởi tạo SLL
void init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
NODE *createNode(float heSo, float soMU)
{
    NODE *p = new (NODE);
    if (p == NULL)
    {
        return NULL;
    }
    p->heSo = heSo;
    p->soMu = soMU;
    p->pNext = NULL;
    return p;
}
void insert_last(LIST &l, NODE *p)
{
    // để biết được list đó có rỗng không thì ta cần biết đầu list có rỗng không
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
void insert_daThuc_last(LIST &l, float heSo, float soMu)
{
    NODE *newNode = createNode(heSo, soMu);
    newNode->heSo = heSo;
    newNode->soMu = soMu;
    newNode->pNext = NULL;
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = newNode;
    }
    else
    {
        l.pTail->pNext = newNode;
        l.pTail = newNode;
    }
}
void input(LIST &l, NODE *p)
{
    int n;
    cout << " Nhap so node: ";
    cin >> n;
    init(l);
    for (int i = 1; i <= n; i++)
    {
        int heSo, soMU;
        cout << " nhap he so: ";
        cin >> heSo;
        cout << " nhap so mu: ";
        cin >> soMU;
        p = createNode(heSo, soMU);
        insert_last(l, p);
    }
}
void inputFile(LIST &l, ifstream &FILEIN)
{
    int n, heSo, soMu;
    if (FILEIN >> n)
    {
        init(l);
        for (int i = 0; i < n; i++)
        {
            FILEIN >> heSo >> soMu;
            NODE *p = createNode(heSo, soMu);
            insert_daThuc_last(l, heSo, soMu);
        }
    }
}
void output(LIST l)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->heSo << "/" << p->soMu << "--->";
    }
    cout << "NULL";
}
LIST daThuc(LIST &p, LIST &q)
{
    LIST r;
    init(r);
    NODE *m = p.pHead, *n = q.pHead;
    while (m != NULL || n != NULL)
    {
        if (m == NULL)
        {
            insert_daThuc_last(r, n->heSo, n->soMu);
            m = m->pNext;
        }
        else if (n == NULL)
        {
            insert_daThuc_last(r, m->heSo, m->soMu);
            n = n->pNext;
        }
        else if (m->soMu > n->soMu)
        {
            // add số mũ và hệ số của list p vào r
            insert_daThuc_last(r, m->heSo, m->soMu);
            m = m->pNext;
        }
        else if (m->soMu < n->soMu)
        {
            insert_daThuc_last(r, n->heSo, n->soMu);
            n = n->pNext;
        }
        else
        {
            insert_daThuc_last(r, m->heSo + n->heSo, m->soMu);
            m = m->pNext;
            n = n->pNext;
        }
    }
    return r;
}
int main()
{
    ifstream FILEIN("daThuc.txt");
    if (!FILEIN.is_open())
    {
        cout << "cannot open the file!" << endl;
        return 1;
    }
    LIST p, q, r;
    inputFile(p, FILEIN);
    inputFile(q, FILEIN);
    r = daThuc(p, q);
    output(r);
    FILEIN.close();
}