#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,d,m;
    int a[200];
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    sort(a,a+n);
    if(m<=n){
        int ans = 0;
        for(int i=0;i<m;i++)
            ans+=a[i];
        cout<<ans<<endl;
    }else{
        int ans = 0 ;
        for(int i=0;i<n;i++)
            ans+=a[i];
        ans -=d*(m-n);
        cout<<ans<<endl;
    }
    return 0;
}
