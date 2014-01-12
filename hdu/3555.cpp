#include<iostream>
#include<cstring>
typedef long long ll;
ll dp[25][3];
int bit[25];
//dp[i][0]表示长度为i,没有49
//dp[i][1]表示长度为i,没有49但前一位为4
//dp[i][2]表示长度为i,包括49的个数
using namespace std;
ll dfs(int pos,int s,bool limit){
    if(pos == -1)
        return s==2;
    if(limit==false && ~dp[pos][s])
        return dp[pos][s];
    int ed = limit?bit[pos]:9;
    ll ans = 0;
    for(int i=0;i<=ed;i++){
        int nows = s;
        if(s==0 && i==4)
            nows = 1;
        if(s==1 && i!=9)
            nows = 0;
        if(s==1 && i==4)
            nows = 1;
        if(s==1 && i==9)
            nows = 2;
        ans += dfs(pos-1,nows,limit&&i==ed);
    }
    if(!limit)
        dp[pos][s] = ans;
    return ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int t;
    ll x;
    cin>>t;
    while(t--){
        cin>>x;
        int len=0;
        ll tm = x;
        while(tm){
            bit[len++] = tm%10;
            tm/=10;
        }
        cout<<dfs(len-1,0,true)<<endl;
    }
}
