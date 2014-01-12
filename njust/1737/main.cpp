#include <iostream>
#include <iomanip>
using namespace std;
int n,a[200],m,b[200];
int main()
{
    while(cin>>n)
    {
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        cin>>m;
        int t=0;
        for(int i=0; i<m; i++)
        {
            cin>>t;
            if(n-t==0)
            {
                cout<<"inf\n";
            }
            else
            {
                double r=(double)sum/n;
                r *=(n/(n-t));
                cout<<fixed<<setprecision(2)<<r<<endl;
            }
        }

    }
    return 0;
}
