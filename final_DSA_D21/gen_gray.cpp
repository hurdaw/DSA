#include <bits/stdc++.h>
using namespace std;
int a[100], n, cnt=1;
bool OK=false;
void init_gray()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}
void result(){
    cout<<"xau gray thu"<<++cnt;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
void gen(){
    
}
int main()
{
}