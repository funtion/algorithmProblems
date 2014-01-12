#include <iostream>
#include <cstring>
using namespace std;
int n,t;
long long p1[30],p2[30],s1[30],s2[30];
long long dp[30][30][30][30],dp1[30][30],dp2[30][30];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>p1[i];
        for(int i=1;i<=n;i++)
            cin>>p2[i];
        s1[1]=p1[1];
        s2[1]=p2[1];
        for(int i=2;i<=n;i++){
            s1[i] = s1[i-1]+p1[i];
            s2[i] = s2[i-1]+p2[i];
        }
        memset(dp,0,sizeof(dp));
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=1;i<=n;i++){
            dp1[i][i] = p1[i];
            dp2[i][i] = p2[i];
        }
        for(int ii=1;ii<=n;ii++){
            for(int jj=1;ii+jj<=n;jj++){
                int i = jj;
                int j= i+ii;
                dp1[i][j] = max(p1[j]+(s1[j-1]-s1[i-1])-dp1[i][j-1],p1[i]+(s1[j]-s1[i])-dp1[i+1][j]);
                dp2[i][j] = max(p2[j]+(s2[j-1]-s2[i-1])-dp2[i][j-1],p2[i]+(s2[j]-s2[i])-dp2[i+1][j]);
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][i][j][j] = max(p1[i],p2[j]);
            }
        }

        for(int ii=1;ii<=n;ii++){
            for(int jj=1;jj+ii<=n;jj++){
                for(int k=1;k<=n;k++){
                    int i = jj;
                    int j = ii+jj;
                    dp[i][j][k][k] = max(p2[k]+(s1[j]-s1[i-1])-dp1[i][j],max(p1[i]+(s1[j]-s1[i]+p2[k])-dp[i+1][j][k][k],p1[j]+(s1[j-1]-s1[i-1]+p2[k])-dp[i][j-1][k][k]));
                    dp[k][k][i][j] = max(p1[k]+(s2[j]-s2[i-1])-dp2[i][j],max(p2[i]+(s2[j]-s2[i]+p1[k])-dp[k][k][i+1][j],p2[j]+(s2[j-1]-s2[i-1]+p1[k])-dp[k][k][i][j-1]));
                }
            }
        }

        for(int ii=1;ii<=n;ii++){
            for(int jj=1;jj+ii<=n;jj++){
                for(int kk=1;kk<=n;kk++){
                    for(int ll=1;ll+kk<=n;ll++){
                        int i,j,k,l;
                        i=jj;
                        j=ii+jj;
                        k=ll;
                        l=ll+kk;
                        long long x1,x2,x3,x4;
                        x1 = p1[i]+(s1[j]-s1[i]+s2[l]-s2[k-1])-dp[i+1][j][k][l];
                        x3 = p2[k]+(s2[l]-s2[k]+s1[j]-s1[i-1])-dp[i][j][k+1][l];

                        x2 = p1[j]+(s1[j-1]-s1[i-1]+s2[l]-s2[k-1])-dp[i][j-1][k][l];
                        x4 = p2[l]+(s2[l-1]-s2[k-1]+s1[j]-s1[i-1])-dp[i][j][k][l-1];

                        dp[i][j][k][l] = max(max(x1,x2),max(x3,x4));
                    }
                }
            }
        }
        cout<<dp[1][n][1][n]<<endl;
    }
    return 0;
}
