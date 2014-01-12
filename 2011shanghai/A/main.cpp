#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{

    ios::sync_with_stdio(false);
    long long t,n,s1,v1,s2,v2;
    cin>>t;
    for(int cs=1; cs<=t; cs++)
    {
        cin>>n>>s1>>v1>>s2>>v2;

        if(s1<s2)
        {
            swap(s1,s2);
            swap(v1,v2);
        }

        long long ans = 0;
        if(v1*s2>v2*s1)
        {
            for(long long i=0;i<=s1&&i<=n/s1;i++)
            {
                long long n1 = n/s1-i,n2 = (n-n1*s1)/s2;
                ans = max(ans,n1*v1+n2*v2);
            }
        }
        else
        {
            for(long long i=0;i<=s2&&i<=n/s2;i++)
            {
                long long n2 = n/s2-i,n1 = (n-n2*s2)/s1;
                ans = max(ans,n1*v1+n2*v2);
            }
        }
        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }
    return 0;
}
