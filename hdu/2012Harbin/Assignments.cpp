#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int n,t;
    int a[1001],b[1001];
    while(cin>>n>>t){
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(a[i]+b[i]>t)
                ans+=a[i]+b[i]-t;
        }
        cout<<ans<<endl;
    }
}
