#include <iostream>
#include <string>
#include <cstring>
#define max 1024
char s1[max],s2[max];
using namespace std;

int num, lev, pos, n1, n2;
char *ans ,*stack, *back;
inline int subnum()
{
    return 2;
}
bool down(int k)
{
    bool a=false;
    if (k==0)
    {
        if (n1<num)
        {
            ans[lev++]='i';
            stack[pos++]=s1[n1++];
            a=true;
        }
    }
    else if (pos>0 && (stack[pos-1]==s2[n2]))
    {
        back[lev]=stack[--pos];
        ans[lev++]='o';
        ++n2;
        a=true;
    }
    return a;
}
void up()
{
    char ch=ans[--lev];
    if (ch=='i')
    {
        --pos;
        --n1;
    }
    else
    {
        stack[pos++]=back[lev];
        --n2;
    }
}
void output()
{
    for (int i=0; i<2*num; ++i)
        cout<<ans[i]<<" ";
    cout<<endl;
}
void depthfirst()
{
    if (lev==2*num )
        output();
    else
    {
        int k=subnum();
        for (int i=0; i<k; ++i)
            if (down(i))
            {
                depthfirst();
                up();
            }
    }

}
int run()
{

    num = strlen(s1);
    ans = new char[2*num];
    back = new char[2*num];
    stack = new char[num];
    memset(ans,0,num);
    memset(back,0,num);
    memset(stack,0,num);
    depthfirst();
    return 0;
}
int main()
{
    while(cin>>s1>>s2)
    {
        cout<<'['<<endl;
        run();
        cout<<']'<<endl;

    }
}
