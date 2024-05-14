#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
typedef struct date
{
    int day;
    int month;
    int year;
} DATE;
typedef struct staff
{
    char code[10];
    char fullName[30];
    DATE dateOfBirth;
    float salary;
    // 0 is female, 1 is male
    int gender;
} STAFF;
typedef struct node
{
    STAFF data;
    struct node *pNext;
} NODE;
typedef struct list
{
    NODE *pHead;
    NODE *pTail;
} LIST;
NODE *createNode(STAFF data);
void printDate(DATE date);
void printStaff(STAFF staff);
void nhapDate(DATE &date);
void nhapStaff(STAFF &staff);
void init(LIST &l);
void insert_begin(NODE *p, LIST &l);
void display(LIST l);
void destroyList(LIST &l);
void readStaffFromFile(const string &filename, vector<staff> &staffList);
void fillYearOfBirth(LIST l);
int countSalary(LIST l);
int deleteStaff(LIST &l);
void selectionSort(LIST &l);
int main()
{
    LIST l;
    init(l);
    vector<staff> staffList;
    readStaffFromFile("nhanVien.txt", staffList);
    for (auto &staff : staffList)
    {
        NODE *newNode = createNode(staff);
        if (newNode)
        {
            insert_begin(newNode, l);
        }
    }

    // const int n = 2; // Example size
    // STAFF staff;
    // for (int i = 0; i < n; i++)
    // {
    //     nhapStaff(staff);
    //     NODE *newNode = createNode(staff);
    //     if (newNode)
    //     {
    //         insert_begin(newNode, l);
    //     }
    // }

    cout << "Staff list:\n";
    display(l);
    fillYearOfBirth(l);
    cout << countSalary(l) << endl;
    cout<<"sap xep do tuoi tang dan theo nam sinh: "<<endl;
    selectionSort(l);
    display(l);
    // int res = deleteStaff(l);
    // if (res)
    // {
    //     cout << "list after remove: " << endl;
    //     display(l);
    // }
    // else
    // {
    //     cout << "NOT FOUND";
    // }
    destroyList(l);
}
NODE *createNode(STAFF data)
{
    NODE *p = new (NODE);
    if (p == NULL)
    {
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    return p;
}
void init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
void insert_begin(NODE *p, LIST &l)
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
void display(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        printStaff(p->data);
        p = p->pNext;
    }
}
void printDate(DATE date)
{
    cout << date.day << "\\";
    cout << date.month << "\\";
    cout << date.year;
}
void printStaff(STAFF staff)
{
    cout << staff.code << "\t";
    cout << staff.fullName << "\t";
    printDate(staff.dateOfBirth);
    cout << "\t";
    cout << staff.salary << "\t";
    cout << staff.gender << endl;
}
void nhapDate(DATE &date)
{
    cout << "nhap ngay: ";
    cin >> date.day;
    cout << "nhap thang: ";
    cin >> date.month;
    cout << "nhap nam: ";
    cin >> date.year;
}
void nhapStaff(STAFF &staff)
{
    cout << "nhap ma nhan vien: ";
    cin.ignore();
    cin.getline(staff.code, sizeof(staff.code));
    cout << "nhap ho ten: ";
    cin.getline(staff.fullName, sizeof(staff.fullName));
    cout << "nhap ngay sinh thang nam sinh: \n";
    nhapDate(staff.dateOfBirth);
    cout << "nhap luong: ";
    cin >> staff.salary;
    cout << "nhap gioi tinh: ";
    cin >> staff.gender;
}
void destroyList(LIST &l)
{
    NODE *p = l.pHead;
    while (l.pHead != NULL)
    {
        l.pHead = p->pNext;
        delete (p);
        p = l.pHead;
    }
}
void readStaffFromFile(const string &filename, vector<STAFF> &staffList)
{
    ifstream file(filename, ios_base::in); // Mở file để đọc

    if (!file.is_open())
    {
        cerr << "Không thể mở file: " << filename << endl;
        return;
    }

    STAFF s;
    while (file >> s.code >> s.fullName >> s.dateOfBirth.day >> s.dateOfBirth.month >> s.dateOfBirth.year >> s.salary >> s.gender)
    {
        staffList.push_back(s);
    }

    file.close(); // Đóng file sau khi đọc xong
}
void fillYearOfBirth(LIST l)
{
    cout << "Danh sach nhung nguoi co nam sinh duoi 1980 la: " << endl;
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (p->data.dateOfBirth.year <= 1980)
            cout << p->data.fullName << endl;
        p = p->pNext;
    }
}
int countSalary(LIST l)
{
    int count = 0;
    cout << "so nguoi co luong tren 60000 la: " << endl;
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (p->data.salary >= 60000)
            count++;
        p = p->pNext;
    }
    return count;
}
int deleteStaff(LIST &l)
{
    char code[10];
    cin >> code;
    NODE *p = l.pHead, *prev = NULL;
    while (p != NULL && strcmp(p->data.code, code) != 0)
    {
        prev = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0; // Staff with the code was not found.

    if (prev == NULL)
    {
        // The staff to delete is at the head of the list.
        l.pHead = p->pNext;
        if (l.pHead == NULL)
        { // If the list becomes empty, update pTail as well.
            l.pTail = NULL;
        }
    }
    else
    {
        // The staff to delete is not at the head.
        prev->pNext = p->pNext;
        if (p->pNext == NULL)
        { // If deleted node was the tail, update pTail.
            l.pTail = prev;
        }
    }
    delete p;
    return 1;
}
void selectionSort(LIST &l){
    NODE *p,  *q, *max;
    p=l.pHead;
    while (p!=l.pTail)
    {
        max=p;
        q=p->pNext;
        while (q!=NULL)
        {
            if(q->data.dateOfBirth.year>p->data.dateOfBirth.year)
                max=q;
            q=q->pNext;
        }
        swap(p->data,max->data);
        p=p->pNext;
    }
}