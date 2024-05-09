#include <bits/stdc++.h>
using namespace std;
// khai báo SLL
struct node
{
    int data;
    NODE *pPrevious; 
    NODE *pNext;
};
typedef struct node NODE;

typedef struct list {
    NODE *pHead;
    NODE *pTail;
} LIST;
// khởi tạo
void init(LIST &l)
{
    
}
NODE *createNode(int value){
    NODE *temp = new(NODE);
    if(temp==NULL)  return NULL;
    temp->data=value;
    temp->pNext=NULL;
    temp->pPrevious=NULL;
    return temp;
}
void insert_begin(NODE *p, LIST &l){
    if()
}
int main()
{
}