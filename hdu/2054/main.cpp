#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;
string x,y;
long double a,b,esp = 1e-15;
long long aa,bb;
int as[1];
template<class T>  inline  T abs(T xx)
{
    return xx>0?xx:-xx;
}
bool ck()
{
    istringstream xx(x),yy(y);
    xx>>a;
    yy>>b;
    //assert(xx.eof());assert(yy.eof());
    return abs(a-b)<esp;
    //return a==b;
}
int main()
{
    while(cin>>x>>y)
    {
        cout<<(ck()?"YES":"NO")<<endl;
    }
    return 0;
}
