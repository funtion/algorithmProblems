#include <iostream>
typedef long long T;
using namespace std;

int main()
{
    T a,b,c;
    cin>>a>>b>>c;
    if(a%c == 0)
        a/=c;
    else
        a=a/c+1;
    if(b%c == 0)
        b/=c;
    else
        b=b/c+1;
    cout<<a*b;
    return 0;
}
