#include <iostream>
typedef int64_t   T;
using namespace std;
inline T sum(T a, T b)
{
    return (a+b)*(b-a+1)/2 ;
}
int main()
{
    T a,b;
    cin>>a>>b;
    T c=b;
    T l,h;
    if(b>=a)
    {
        if(a==1)
            cout<<0;
        else
            cout<<1;
        return 0;
    }
    else if(b+sum(0,b-2) < a)
    {
        cout<< -1;
        return 0;
    }
    else
    {
        a-=b;
        b-=2;
        l=0;
        h=b;
        T m = (l+h)/2;
        while(l<=h)
        {
            if(sum(m,b) <a)
            {
                h=m-1;
            }
            else if(sum(m,b) == a)
            {
                if(l==m)
                    cout<<c-h;
                else
                    cout<<c-m;
                return 0;
            }
            else
            {
                l = m+1;
            }
            m = (l+h)/2;
        }
    cout<< b-h+2;
    }
    return 0;
}
