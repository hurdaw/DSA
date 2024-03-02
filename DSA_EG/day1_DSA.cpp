#include <bits/stdc++.h>
using namespace std;
void daoTu(string &s)
{
    int left = 0;
    int right = s.length() - 1;
    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    cout << s;
}
// đảo từ dùng stack
string Stack(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}
int main()
{
    string a;
    getline(cin, a);
    Stack(a);
}