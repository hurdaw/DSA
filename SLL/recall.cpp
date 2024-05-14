#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
bool checkOp(char op[])
{
    return (strcmp(op, "+") == 0) || (strcmp(op, "-") == 0) || (strcmp(op, "*") == 0) || (strcmp(op, "/") == 0);
}
void tinhHauTo(char c[])
{
    stack<int> s;
    char *p = strtok(c, " ");
    int result;
    while (p != NULL)
    {
        if (checkOp(p))
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (strcmp(p, "+") == 0)
                result = a + b;
            if (strcmp(p, "-") == 0)
                result = a - b;
            if (strcmp(p, "*") == 0)
                result = a * b;
            if (strcmp(p, "/") == 0)
            {
                if (b == 0)
                {
                    cout << "ERROR";
                    return;
                }
                else
                {
                    result = a / b;
                }
            }
            s.push(result);
        }
        else
        {
            s.push(atoi(p));
        }
        p = strtok(NULL, " ");
    }
    cout << result << endl;
}
int main()
{
    char c[] = "41 10 + 2 * 3 /";
    tinhHauTo(c);
}
