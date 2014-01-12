#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
int n,k;
long num[2003];
long dp[2003][2003];
int main()
{
    while(cin>>n>>k){
        num[0] = 0 ;
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }
        sort(num+1,num+n+1);
        for (int i=0;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
                dp[i][j] = LONG_MAX;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j*2<=i;j++){
                dp[i][j] = min(dp[i-1][j],dp[i-2][j-1]+(num[i]-num[i-1])*(num[i]-num[i-1]));
            }
        }
        cout<<dp[n][k]<<endl;
    }
    return 0;
}
