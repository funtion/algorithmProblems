#include <iostream>
typedef int64_t T;
using namespace std;

int main()
{
    T a,b;
    cin>>a>>b;
    T i;
    for(i=0;i<b;i++)
    {
            cout<<a-i<<' ';
    }
    for(T j=1;j<a-b;j++)
    {
        cout<<j<<' ';
    }
    cout<<a-b;
    return 0;
}
