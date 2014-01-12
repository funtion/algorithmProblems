#include <iostream>
#include <cstring>
using namespace std;
long long n,m,ni[3100],mi[13];

long long dp[3100];
long long dp2[3100][3100];
int main()
{
    while(cin>>n>>m){
        memset(ni,0,sizeof(ni));
        memset(mi,0,sizeof(mi));
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        for(int i=0;i<n;i++){
            cin>>ni[i];
        }
        for(int i=0;i<m;i++){
            cin>>mi[i];
        }
        /**/
        for(int i=0;i<n;i++){
            for(int j=(1<<m)-1;j>=0;j--){//mask
                for(int k=0;k<m;k++){
                    if( (j & (1<<k) )== 0){
                        dp[j|(1<<k)] = max(dp[j|(1<<k)],dp[j]+ni[i]*mi[k]+(i+1)*(k+1));
                    }
                }
            }
        }

        cout<<dp[(1<<m)-1 ]<<endl;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=(1<<m)-1;j++){
                for(int k=0;k<m;k++){
                    if( (j&(1<<k))){
                        dp2[i][j] = max(dp2[i-1][j],dp2[i-1][j&~(1<<k)]+ni[i-1]*mi[m-1-k]+(i)*(m-k));
                    }
                }
            }
        }
        cout<<dp2[n][(1<<m)-1]<<endl;
    }
    return 0;
}
