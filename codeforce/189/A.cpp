#include <iostream>
using namespace std;
int n,a,b,c,dp[4001];
int g(int i,int d){
    if(i-d<0)return 0;
    if(i-d==0)return 1;
    if(dp[i-d]==0)return 0;
    return dp[i-d]+1;
}
int main(){
    cin>>n>>a>>b>>c;
    //dp[a]=dp[b]=dp[c] = 1;
    for(int i=1;i<=n;i++){
        //if((i==a||i==b||i==c)&&i!=n)continue;
        //int aa = (i-a<0 || dp[i-a]==0)?0:dp[i-a]+1;
        //int bb = (i-b<0 || dp[i-b]==0)?0:dp[i-b]+1;
        //int cc = (i-c<0 || dp[i-c]==0)?0:dp[i-c]+1;
        int aa = g(i,a),bb=g(i,b),cc=g(i,c);
        dp[i] = max(aa,max(bb,cc));
    }
    cout<<dp[n];
}
