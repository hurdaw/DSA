#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#define MAX 100
using namespace std;
void nhapMang(int *&a, int n)
{
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void checkNgoac(string s)
{
    stack<char> a;
    bool balanced = true; // flag to monitor if the string is balanced

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        // Check if the character is an opening bracket
        if (c == '(' || c == '[' || c == '{')
        {
            a.push(c);
        }
        else
        {
            // Ensure there is something to match with if a closing bracket is encountered
            if (a.empty())
            {
                balanced = false;
                break;
            }
            char top = a.top();
            if ((top == '(' && c == ')') ||
                (top == '[' && c == ']') ||
                (top == '{' && c == '}'))
            {
                a.pop();
            }
            else
            {
                balanced = false;
                break;
            }
        }
    }

    // Ensure there are no unmatched opening brackets left
    if (!a.empty())
        balanced = false;

    if (balanced)
        cout << "YES\n";
    else
        cout << "NO\n";
}
void daoTu(string s)
{
    stack<char> a;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            a.push(s[i]);
        }
        else
        {
            while (!a.empty())
            {
                cout << a.top();
                a.pop();
            }
            cout << " ";
        }
    }
    while (!a.empty())
    {
        cout << a.top();
        a.pop();
    }
}
void dec2bin(int n)
{
    stack<int> st;
    while (n != 0)
    {
        st.push(n % 2);
        n /= 2;
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}
void ktrSolonHonBenPhai(int a[], int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                x = a[j];
                break;
            }
        }
        cout << x << " ";
    }
}
void ktrStackMethod(int a[], int n)
{
    stack<int> s;
    int b[100];
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && a[s.top()] < a[i])
            {
                b[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        b[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}
bool checkOp(char op[])
{
    return (strcmp(op, "+") == 0) || (strcmp(op, "-") == 0) || (strcmp(op, "*") == 0) || (strcmp(op, "/") == 0);
}
void tinhHauTo(char c[])
{
    stack<int> s;
    int x = 0;
    char *p = strtok(c, " ");
    while (p != NULL)
    {
        if (checkOp(p))
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (strcmp(p, "+") == 0)
                x = a + b;
            else if (strcmp(p, "-") == 0)
                x = a - b;
            else if (strcmp(p, "*") == 0)
                x = a * b;
            else if (strcmp(p, "/") == 0)
            {
                if (b == 0)
                {
                    cout << "ERROR";
                    return;
                }
                x = a / b;
            }
            s.push(x);
        }
        else
        {
            s.push(atoi(p));
        }
        p = strtok(NULL, " ");
    }
    cout << x << endl;
}
// (a+b*c)-(a/b+c)
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
string infit2Postfit(string c)
{
    stack<char> s;   // lưu trữ phép toán
    string out = ""; // lưu trữ biểu thức hậu tố
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == '(')
            s.push(c[i]);
        else if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= '0' && c[i] <= '9'))
        {
            out += c[i];
        }
        else if (c[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                out += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(c[i]))
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c[i]))
            {
                out += s.top();
                s.pop();
            }
            s.push(c[i]);
        }
    }
    while (!s.empty())
    {
        if (s.top() != '(')
            out += s.top();
        s.pop();
    }
    return out;
}
int main()
{
    string s;
    int n, *a = nullptr;
    string c = "(a+b*c)-(a/b+c)";
    s = infit2Postfit(c);
    cout << s << " ";
    delete[] a;
    a = nullptr;
}
