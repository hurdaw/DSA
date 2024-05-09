#include <bits/stdc++.h>
using namespace std;
#define MAX 100
typedef struct stk
{
    int top; // index trong stack
    int node[MAX];
};
class STACK
{
public:
    stk s;
    void push(void)
    {
        int value;
        // kiểm tra stack có tràn không
        if (s.top == MAX - 1)
        {
            cout << "stack overflow";
            return;
        }
        else
        {
            cout << "nhap gia tri can push: ";
            cin >> value;
            s.top = s.top + 1;
            s.node[s.top] = value;
        }
    }
    int pop(void)
    {
        int value;
        // kiểm tra stack có rỗng không
        if (s.top == -1)
        {
            cout << "stack empty";
            return (INT_MIN);
        }
        else
        {
            value = s.node[s.top];
            s.top--;
        }
        return value;
    }
    void display(void)
    {
        // kiểm tra stack có rỗng không
        if (s.top == -1)
            cout << "empty stack";
        else
        {
            for (int i = s.top; i >= 0; i--)
                cout << s.node[i]<<" ";
        }
    }
    STACK(void)
    {
        s.top = -1;
    }
};
int main(void)
{
    STACK x;
    int choice;
    cout << "CAC THAO TAC TREN STACK";
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
            x.push();
            break;
        case 2:
            x.pop();
            break;
        case 3:
            x.display();
            break;
        default:
            cout << " chon sai";
            break;
        }
    } while (choice != 0);
}