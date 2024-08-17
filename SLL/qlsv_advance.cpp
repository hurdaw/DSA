#include <iostream>
#include <string>
#include <string.h>
#define MAX 10
using namespace std;
typedef struct subject
{
    string name;
    string code_sub;
    int stc;
} SUBJECT;
typedef struct list_subject
{
    SUBJECT list[MAX];
    int so_luong = 0;
} LIST_SUBJECT;
// danh sách sinh viên
typedef struct sv
{
    string name;
    string code_sv;
    float avg = 0;
} SV;
typedef struct node_sv
{
    SV data;
    node_sv *pNext;
} NODE_SV;
typedef struct list_sv
{
    NODE_SV *pHead = NULL;
    NODE_SV *pTail = NULL;
} LIST_SV;
// danh sách điểm
typedef struct score_tp
{
    float score;
    string code_sv;
    string code_sub;
} SCORE_TP;

typedef struct node_score_tp
{
    SCORE_TP data;
    node_score_tp *pNext;
    node_score_tp *pPrev;
} NODE_SCORE_TP;
typedef struct list_score
{
    NODE_SCORE_TP *pHead = NULL;
    NODE_SCORE_TP *pTail = NULL;
} LIST_SCORE;
void modify_subject(LIST_SUBJECT &lsb);
void displayListSub(LIST_SUBJECT lsb);
int check_codeSub_equal(LIST_SUBJECT lsb, string s);
bool check_score_equal(LIST_SCORE lsc, string s);
NODE_SV *createNode(SV a);
void insert_sv(LIST_SV &sv, SV a);
NODE_SCORE_TP *createNode(SCORE_TP a);
void insert_score(LIST_SCORE &score, SCORE_TP a);
void display_list_object(LIST_SV lsv, LIST_SCORE lsc, LIST_SUBJECT lsb);
void list_score_by_codeSV(LIST_SCORE lsc, LIST_SUBJECT lsb, string s);
int main()
{
    list_subject lsb;
    list_sv lsv;
    list_score lsc;
    int choice;
    modify_subject(lsb);
    bool kt_menu = true;
    while (kt_menu)
    {
        cout << "1. Nhap danh sach cho den khi nhap '$' vao ten doi tuong." << endl;
        cout << "2. Xuat danh sach mon hoc" << endl;
        cout << "3. Xuat danh sach doi tuong" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            while (1)
            {
                string s;
                cin.ignore();
                cout << "nhap ho ten sinh vien: ";
                getline(cin, s);
                if (s == "$")
                {
                    break;
                }
                else
                {
                    sv sv_tmp; // biến sv tạm
                    sv_tmp.name = s;
                    cout << "nhap ma sinh vien: ";
                    getline(cin, sv_tmp.code_sv);
                    score_tp score_tmp;
                    score_tmp.code_sv = sv_tmp.code_sv;
                    int check1;
                    bool check2;
                    // kiểm tra xem môn đó có hợp lệ với đã học chưa
                    do
                    {
                        cout << "nhap ma mon hoc: ";
                        getline(cin, score_tmp.code_sub);
                        check1 = check_codeSub_equal(lsb, score_tmp.code_sub), check2 = check_score_equal(lsc, score_tmp.code_sub);
                        if (check1 == -1)
                        {
                            cout << "ma mon hoc khong ton tai. Vui long nhap lai!" << endl;
                        }
                        else if (check2)
                        {
                            cout << "mon nay da hoc roi." << endl;
                        }
                    } while (check1==-1 || check2);
                    cout << "nhap diem: ";
                    cin >> score_tmp.score;
                    // thêm sinh viên tạm vào danh sách sinh viên
                    insert_sv(lsv, sv_tmp);
                    // thêm điểm tạm vào danh sách sinh viên
                    insert_score(lsc, score_tmp);
                }
            }

            break;
        case 2:
            displayListSub(lsb);
            break;
        case 3:

        default:
            break;
        }
    }
}
void nhapMon(LIST_SUBJECT &lsb)
{
    cout << "\t\tnhap thong tin mon hoc:" << endl;
    cout << "\t---- Nhap thong tin mon Toan ---- " << endl;
    lsb.list[0].name = "Toan";
    cout << "nhap ma mon Toan: ";
    getline(cin, lsb.list[0].code_sub);
    cout << "nhap so tin chi mon Toan: ";
    cin >> lsb.list[0].stc;

    cout << "\t---- Nhap thong tin mon Ly ---- " << endl;
    lsb.list[1].name = "Ly";
    cin.ignore();
    cout << "nhap ma mon Ly: ";
    getline(cin, lsb.list[1].code_sub);
    cout << "nhap so tin chi mon Ly: ";
    cin >> lsb.list[1].stc;

    cout << "\t---- Nhap thong tin mon tieng Anh ---- " << endl;
    lsb.list[2].name = "tieng Anh";
    cin.ignore();
    cout << "nhap ma mon tieng Anh: ";
    getline(cin, lsb.list[2].code_sub);
    cout << "nhap so tin chi mon tieng Anh: ";
    cin >> lsb.list[2].stc;

    cout << "\t---- Nhap thong tin mon DSA ---- " << endl;
    lsb.list[3].name = "DSA";
    cin.ignore();
    cout << "nhap ma mon DSA: ";
    getline(cin, lsb.list[3].code_sub);
    cout << "nhap so tin chi mon DSA: ";
    cin >> lsb.list[3].stc;
    lsb.so_luong = 4;
}
void modify_subject(LIST_SUBJECT &lsb)
{
    int choice_sub;
    // nhập môn học
    nhapMon(lsb);
    do
    {
        cout << "\t ---- Chinh sua thong tin mon hoc ---- " << endl;
        cout << "1. Sua thong tin mon Toan" << endl;
        cout << "2. Sua thong tin mon Ly" << endl;
        cout << "3. Sua thong tin mon tieng Anh" << endl;
        cout << "4. Sua thong tin mon DSA" << endl;
        cout << "0. Thoat khoi sua mon" << endl;
        cin >> choice_sub;
        switch (choice_sub)
        {
        case 1:
            cout << "\t---- Nhap thong tin mon Toan ---- " << endl;
            lsb.list[0].name = "Toan";
            cout << "nhap ma mon Toan: ";
            getline(cin, lsb.list[0].code_sub);
            cout << "nhap so tin chi mon Toan: ";
            cin >> lsb.list[0].stc;
            break;
        case 2:
            cout << "\t---- Nhap thong tin mon Ly ---- " << endl;
            lsb.list[1].name = "Ly";
            cin.ignore();
            cout << "nhap ma mon Ly: ";
            getline(cin, lsb.list[1].code_sub);
            cout << "nhap so tin chi mon Ly: ";
            cin >> lsb.list[1].stc;
            break;
        case 3:
            cout << "\t---- Nhap thong tin mon tieng Anh ---- " << endl;
            lsb.list[2].name = "tieng Anh";
            cin.ignore();
            cout << "nhap ma mon tieng Anh: ";
            getline(cin, lsb.list[2].code_sub);
            cout << "nhap so tin chi mon tieng Anh: ";
            cin >> lsb.list[2].stc;
            break;
        case 4:
            cout << "\t---- Nhap thong tin mon DSA ---- " << endl;
            lsb.list[3].name = "DSA";
            cin.ignore();
            cout << "nhap ma mon DSA: ";
            getline(cin, lsb.list[3].code_sub);
            cout << "nhap so tin chi mon DSA: ";
            cin >> lsb.list[3].stc;
            break;
        default:
            break;
        }
    } while (choice_sub != 0);
}
void displayListSub(LIST_SUBJECT lsb)
{
    for (int i = 0; i < lsb.so_luong; i++)
    {
        cout << "\t\t----mon hoc thu: " << i << " ----" << endl;
        cout << "ten mon: " << lsb.list[i].name << "\t";
        cout << "ma mon: " << lsb.list[i].code_sub << "\t";
        cout << "so tin chi: " << lsb.list[i].stc << endl;
    }
}
int check_codeSub_equal(LIST_SUBJECT lsb, string s)
{
    for (int i = 0; i < lsb.so_luong; i++)
    {
        if (stricmp(lsb.list[i].code_sub.c_str(), s.c_str()) == 0)
        {
            return i;
        }
    }
    return -1;
}
bool check_score_equal(LIST_SCORE lsc, string s)
{
    for (node_score_tp *k = lsc.pHead; k != NULL; k = k->pNext)
    {
        if (stricmp(k->data.code_sub.c_str(), s.c_str()) == 0)
        {
            return true;
        }
    }
    return false;
}
NODE_SV *createNode(SV a)
{
    NODE_SV *p = new NODE_SV;
    p->data = a;
    p->pNext = NULL;
    return p;
}
void insert_sv(LIST_SV &sv, SV a)
{
    NODE_SV *p = createNode(a);
    if (sv.pHead == NULL)
    {
        sv.pHead = sv.pTail = NULL;
    }
    else
    {
        sv.pTail->pNext = p;
        sv.pTail = p;
    }
}
NODE_SCORE_TP *createNode(SCORE_TP a)
{
    NODE_SCORE_TP *p = new NODE_SCORE_TP;
    p->data = a;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}
void insert_score(LIST_SCORE &score, SCORE_TP a)
{
    NODE_SCORE_TP *p = createNode(a);
    if (score.pHead == NULL)
    {
        score.pHead = score.pTail = NULL;
    }
    else
    {
        score.pTail->pNext = p;
        p->pPrev = score.pTail;
        score.pTail = p;
    }
}
// liệt kê điểm sv theo mã sv
void list_score_by_codeSV(LIST_SCORE lsc, LIST_SUBJECT lsb, string s)
{
    for (NODE_SCORE_TP *p = lsc.pHead; p != NULL; p = p->pNext)
    {
        int j = 1;
        if (stricmp(p->data.code_sv.c_str(), s.c_str()) == 0)
        {
            cout << "\t----- Diem thu " << j++ << " -----" << endl;
            cout << "ma mon hoc: " << p->data.code_sub << endl;
            int i = check_codeSub_equal(lsb, p->data.code_sub);
            cout << "ten mon: " << lsb.list[i].name << endl;
            cout << "so tin chi: " << lsb.list[i].stc << endl;
            cout << "diem: " << p->data.score << endl;
        }
    }
}
void display_list_object(LIST_SV lsv, LIST_SCORE lsc, LIST_SUBJECT lsb)
{
    int i = 1;
    cout << "\t\t===== Danh sach doi tuong =====" << endl;
    for (NODE_SV *k = lsv.pHead; k != NULL; k = k->pNext)
    {
        cout << "\t\t----- SV thu " << i << " ----" << endl;
        cout << "ma sv: " << k->data.code_sv << endl;
        cout << "ten sv: " << k->data.name << endl;
        cout << "diem tb: " << k->data.avg << endl;
        list_score_by_codeSV(lsc, lsb, k->data.code_sv);
    }
}