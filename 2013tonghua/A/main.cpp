#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
int t;
using namespace std;
string x,xx,xxx;
int main()
{
    cin>>t;
    while(t--)
    {

        long long a,b,ans=0;
        for(int i=0;i<12;i++)
        {
            cin>>x;
            xx = x.substr(0,x.length()-3);
            xxx = x.substr(x.length()-2);
            stringstream oxx(xx),oxxx(xxx);
            oxx>>a;
            oxxx>>b;
            ans+=(a*100+b)*10;
        }
        ans/=12;
        if(ans%10>=5)
        {
            ans/=10;
            ans++;
        }
        else
        {
            ans/=10;
        }
        cout<<'$'<<ans/100;
        if(ans%100>0)
        {
            cout<<'.';
            cout<<(ans%100)/10;
            if(ans%10>0)
            {
                cout<<ans%10;
            }
        }
        cout<<endl;
    }
    return 0;
}
