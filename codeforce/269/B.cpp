#include <iostream>
#include <algorithm>
using namespace std;
int a[6000],dp[6000],n,m;
const int inf = 10000;
double x[6000];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>x[i];
    }
    fill(dp+1,dp+6000,inf);
    for (int i=1;i<=n;i++){
        int *k = upper_bound(dp,dp+n+1,a[i]);//cout<<"find ins:"<<k-dp<<endl;
        if(a[i]< *k)
             *k=a[i];
    }
    int *cnt = lower_bound(dp,dp+6000,inf);
    int ans = cnt-dp;
    //for(int i=0;i<=n+5;i++)cout<<i<<":"<<dp[i]<<endl;
    cout<<n-ans+1;
}
