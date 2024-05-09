#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Queue
{
public:
    int inp;
    int out;
    int node[MAX];
    void push()
    {
        int value;
        if (inp == MAX - 1)
        {
            cout << "queue overflow";
            return;
        }
        else
        {
            if (out == -1) // queue rỗng
                out = 0;
            cout << "nhap value: ";
            cin >> value;
            inp++;
            node[inp] = value;
        }
    }
    void pop()
    {
        if (out > inp || out == -1)
        {
            cout << "queue empty";
            return;
        }
        else
        {
            cout << "queue duoc lay ra: " << node[out] << endl;
            out++;
        }
    }
    void display()
    {
        if (out == -1)
            cout <<"queue empty";
        else{
            for(int i=out;i<=inp;i++){
                cout<<node[i]<<" ";
            }
            cout<<endl;
        }
    }
    Queue(void){
        inp=-1;
        out=-1;
    }
};
int main()
{
    int choice;
    Queue q;
    cout << "CAC THAO TAC TREN QUEUE";
    do
    {
        cout << "\n------------------------\n";
        cout << "     1   --> PUSH       \n";
        cout << "     2   --> POP        \n";
        cout << "     3   --> DISPLAY    \n";
        cout << "     0   --> EXIT       \n";
        cout << " your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            q.push();
            break;
        case 2:
            q.pop();
            break;
        case 3:
            q.display();
            break;
        default:
            cout << " chon sai";
            break;
        }
    } while (choice != 0);
}