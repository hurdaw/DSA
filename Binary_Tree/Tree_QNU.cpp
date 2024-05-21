#include <iostream>
using namespace std;
typedef struct person
{
    string name;
    int yearOFBirth;
} PERSON;
typedef struct BFT
{
    PERSON data;
    BFT *pLeft, *pRight;
} BFT;
BFT *createNode(PERSON p, BFT *left, BFT *right)
{
    return new BFT{p, left, right};
}
BFT *createBFT()
{
    BFT *n1, *n2, *n3, *n4, *n5, *n6;
    n1 = createNode({"Nguyen D", 1960}, NULL, NULL);
    n2 = createNode({"Nguyen B", 1930}, NULL, n1);
    n3 = createNode({"Nguyen E", 1965}, NULL, NULL);
    n4 = createNode({"Nguyen F", 1970}, NULL, NULL);
    n5 = createNode({"Nguyen C", 1935}, n3, n4);
    n6 = createNode({"Nguyen A", 1900}, n2, n5);
    return n6;
}
void display_BFT(BFT *root)
{
    if (root)
    {
        cout << root->data.name << " " << root->data.yearOFBirth << endl;
        display_BFT(root->pLeft);
        display_BFT(root->pRight);
    }
}
int countMembers(BFT *root)
{
    if (!root)
        return 0;
    return 1 + countMembers(root->pLeft) + countMembers(root->pRight);
}
// đếm số thế hệ trong cây
int height(BFT *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->pLeft), height(root->pRight));
}
int countYear(BFT *root, int year)
{
    if (!root)
        return 0;
    else if (root->data.yearOFBirth < year)
    {
        return countYear(root->pLeft, year), countYear(root->pRight, year) + 1;
    }
    else
    {
        return 0;
    }
}
// tìm người theo họ tên
BFT *findMember(BFT *root, string name)
{
    if (!root)
        return NULL;
    if (root->data.name == name)
        return root;
    BFT *left = findMember(root->pLeft, name);
    if (left)
        return left;
    return findMember(root->pRight, name);
}
// Kiểm tra người tên cName có phải con người pName không?
bool isParent(BFT *root, string pName, string cName)
{
    BFT *parent;
    parent = findMember(root, cName);
    if (!parent)
        return false;
    else
        return (parent->pLeft && parent->pLeft->data.name == cName) || (parent->pRight && parent->pRight->data.name == cName);
}
void display_tree(BFT *t)
{
    if (t)
    {
        cout << t->data.name << endl;
        display_tree(t->pLeft);
        display_tree(t->pRight);
    }
}
int main()
{
    BFT *t = createBFT();
    cout << countMembers(t) << endl;
    cout << height(t) << endl;
    cout << countYear(t, 1950) << endl;
    string nameToFind = "Nguyen A";
    BFT *p = findMember(t, nameToFind);
}