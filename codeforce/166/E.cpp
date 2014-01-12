#include <iostream>
using namespace std;
typedef long  ll;
const ll mod = 1000000007;
ll dp[10000000][4];
int main(){
    int n;
    cin>>n;
    dp[1][0]=dp[1][1]=dp[1][2]=1;dp[1][3]=0;
    for(ll i=2;i<=n;i++){
        for(int j=0;j<4;j++){
            ll t=0;
            for(int k=0;k<4;k++){
                if(j==k)continue;
                t=(t+dp[i-1][k]%mod)%mod;
            }
            dp[i][j] = t;
        }
    }
    cout<<dp[n][3];
}
