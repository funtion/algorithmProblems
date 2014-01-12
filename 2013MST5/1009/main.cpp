#include <iostream>
#include <cstdio>
#include <cstring>
#define mx 11111
int t;
typedef  int  ll;
ll  n;
ll  *dp[mx];
const ll  mol = 1000000007;

using namespace std;
ll split (ll n,ll m){
    if(dp[n][m]!=-1)
        return dp[n][m];
    ll ans;
    if(n < 1 || m < 1) ans= 0;
    else if(n == 1 || m == 1) ans= 1;
    else if(n < m) ans=split(n, n)%mol;
    else if(n == m) ans= (split(n, m - 1)%mol + 1)%mol;
    else if(n > m) ans= (split(n, m - 1)%mol + split((n - m), m)%mol)%mol;
    dp[n][m] = ans;
    return ans;
}
int main(){
    scanf("%d",&t);
    for(int i=0;i<mx;i++){
        dp[i] = new ll[i+1];
        memset(dp[i],-1,sizeof(ll)*(i+1));
    }
    while(t--){
        scanf("%d",&n);
        ll ans = split(n,n);
        printf("%d\n",ans);
    }
}
