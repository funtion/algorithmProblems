#include <iostream>
#include <cstring>

using namespace std;
int ma(int a,int b,int c)
{
    if(a>b)
    {
        if(a>c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b>c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}
int main()
{
    int t;
    int n[3],m[3];
    cin>>t>>n[0]>>n[1]>>n[2];
    int *p = new int[t+1];
    memset(p,0,t*sizeof(int));
    for(int i=1;i<=t;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(i - n[j] < 0)
                m[j] = 0;
            else if( i - n[j] == 0)
                m[j] = 1;
            else
            {
                if( p[i-n[j]]==0)
                    m[j] = 0;
                else
                    m[j] =  p[i-n[j]]+1;

            }
        }
        int mx = ma(m[0],m[1],m[2]);
        p[i] = mx;
    }
        cout<<p[t];
    return 0;
}
