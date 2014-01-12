#include<iostream>
using namespace std;
int main()
{
    long long t,n,x;
    long long ans;
    //int ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>x;
        ans = (n*(n-1))/2;
        cout<<ans<<endl;
    }
    return 0;
}
