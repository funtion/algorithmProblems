#include <iostream>
bool isFind;
using namespace std;

bool find1(int x,int k)
{
    if(x==1)
        return true;
    else
    {
        for(int i=k; i>=2; i--)
        {
            if(x%i==0 && find1(x/i,i-1))
                return true;
        }
        return false;
    }
}
void find2(int x,int y,int n)
{
    if(x<=n && y<=n && (x==1 || y==1))
    {
        isFind =true;
        return;
    }
    else if(n>2)
    {
        for(int i=n;!isFind && i>=2; --i)
        {
            if(x%i==0)
                find2(x/i,y,i-1);
            if(!isFind&&y%i==0)
                find2(x,y/i,i-1);
        }
    }
}
int go(int a,int b)
{
    if(b>a)
        swap(a,b);
    if(!find1(b,100))
    {
        cout<<a<<endl;
    }
    else if(!find1(a,100))
    {
        cout<<b<<endl;
    }
    else
    {
        isFind =false;
        find2(a,b,100);
        if(isFind)
            cout<<a<<endl;
        else
            cout<<b<<endl;
    }
    return 0;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        go(a,b);
    }
    return 0;
}
