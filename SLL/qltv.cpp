#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
typedef struct book
{
    char code[10];
    char name[30];
    char author[30];
    int yearRelease;
} BOOK;
typedef struct node
{
    BOOK data;
    struct node *pNext;
} NODE;
typedef struct list
{
    NODE *pHead;
    NODE *pTail;
} LIST;
void init(LIST &l);
NODE *createNode(BOOK value);
void insert_begin(LIST &l, NODE *p);
void insert_last(LIST &l, NODE *p);
void insert_pos(LIST &l, NODE *p, NODE *q); // insert node p behide node  q
void nhapBook(BOOK &book);
void printBook(BOOK book);
void display(LIST l);
void readBookFromFile(const string &filename, vector<BOOK> &bookList);
int searchCode(LIST l, char code[]);
int delete_book(LIST &l);
int main()
{
    LIST l;
    init(l);
    vector<BOOK> booklist;
    readBookFromFile("library.txt", booklist);
    for (auto &book : booklist)
    {
        NODE *p = createNode(book);
        if (p)
        {
            insert_begin(l, p);
        }
    }
    // int n;
    // cin >> n;
    // BOOK book;

    // for (int i = 0; i < n; i++)
    // {
    //     nhapBook(book);
    //     NODE *p = createNode(book);
    //     if (p != NULL)
    //         insert_begin(l, p);
    // }
    cout << "list book: " << endl;
    display(l);
    char code[10];
    cout << "nhap ma can tim: ";
    cin.getline(code, sizeof(code));
    if (searchCode(l, code))
    {
        cout << "\nfound!" << endl;
    }
    else
    {
        cout << "not found";
    }
    if (delete_book(l))
    {
        cout << "list sau khi xoa: " << endl;
        display(l);
    }
    else
    {
        cout << "not found";
    }
}
void init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
NODE *createNode(BOOK value)
{
    NODE *p = new (NODE);
    if (p == NULL)
        return NULL;
    p->data = value;
    p->pNext = NULL;
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
        p->pNext = l.pHead;
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
void insert_pos(LIST &l, NODE *p, NODE *q)
{ // insert node p behide node  q
    NODE *i = l.pHead;
    if (q == NULL)
        return;
    while (i != NULL)
    {
        if (i == q) // tìm thấy q
        {
            p->pNext = i->pNext;
            i->pNext = p;
            if (i == l.pTail)
                l.pTail = p;
            break;
        }
        i = i->pNext;
    }
}
void printBook(BOOK book)
{
    cout << "ma sach: ";
    cout << book.code << "\t";
    cout << "ten sach: ";
    cout << book.name << "\t";
    cout << "tac gia: ";
    cout << book.author << "\t";
    cout << "nam xuat ban: ";
    cout << book.yearRelease << "\n";
}
void display(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        printBook(p->data);
        p = p->pNext;
    }
}
void nhapBook(BOOK &book)
{
    cout << "nhap ma sach: ";
    cin.ignore();
    cin.getline(book.code, sizeof(book.code));
    cout << "nhap ten sach: ";
    cin.getline(book.name, sizeof(book.name));
    cout << "tac gia: ";
    cin.getline(book.author, sizeof(book.author));
    cout << "ngay xuat ban: ";
    cin >> book.yearRelease;
}
void readBookFromFile(const string &filename, vector<BOOK> &bookList)
{
    ifstream FILE(filename, ios_base::in);
    if (!FILE.is_open())
    {
        cerr << "cannot open file" << endl;
        return;
    }
    BOOK book;
    while (FILE >> book.code >> book.name >> book.author >> book.yearRelease)
    {
        bookList.push_back(book);
    }
    FILE.close();
}
int searchCode(LIST l, char code[])
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (strcmp(p->data.code, code) == 0)
        {
            cout << p->data.name;
            return 1;
        }
        p = p->pNext;
    }
    return 0;
}
int delete_book(LIST &l)
{
    NODE *p = l.pHead, *prev = NULL;
    char code[10];
    cin.getline(code, sizeof(code));
    while (p != NULL && strcmp(p->data.code, code) != 0)
    {
        prev = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    if (prev == NULL) // xóa ngay node đầu
    {
        l.pHead = p->pNext;
        if (l.pHead == NULL)
        {
            l.pTail = NULL;
        }
    }
    else
    {
        prev->pNext = p->pNext;
        if (p->pNext == NULL)
        {
            l.pTail = prev;
        }
    }
    delete (p);
    return 1;
}